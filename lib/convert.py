#
# Converts the can_data.txt files into C++ headers for this project!
#
# This program takes 2 arguments:
# 1. Input can_data.txt file
# 2. Output directory for header files
# 3. Optional - Global #ifdef guard for file

import os
import sys


input_file=open(sys.argv[1], 'r')
output_dir=sys.argv[2]

output_guard = False
global_guard=""
if len(sys.argv) > 3:
    global_guard=sys.argv[3]
    output_guard = True

def clear_bit(mask, bit):
    return mask & ~(1<<bit)

def remove_useless_from_line(l: str) -> str:
    return l.replace("\t", "").replace("\n", "")

class EnumEntry:
    def __init__(self, name: str, raw: int, desc: str):
        self.name = name
        self.raw = raw
        self.desc = desc

class Signal:
    def __init__(self, name: str, desc: str, length: int, offset: int, unit: str):
        self.name = name
        self.desc = desc
        self.length = length
        self.offset = offset
        self.is_iso_tp = False
        self.is_number = False
        self.is_bool = False
        self.is_char = False
        self.number_data = (0.0, 0.0) # Multiplier, offset
        self.is_enum = True
        self.unit = unit
        self.enum_table = []

    def get_return_data_type(self, frame_name: str) -> str:
        if self.is_number:
            if self.length <= 8: # 8 bit wide data
                return "uint8_t"
            elif self.length <= 16: # 16 bit wide data
                return "uint16_t"
            elif self.length <= 32: # 32 bit wide data
                return "uint32_t"
            else:
                return "uint64_t" # 64 bit wide data
        elif self.is_bool: # Boolean data type
            return "bool"
        elif self.is_enum: # Enum data type
            return "{}_{}".format(frame_name, self.name)
        elif self.is_char:
            return "char"
        else:
            return"" # ??

    def get_setter_and_getter(self, frame_name: str) -> str:
        mask = 0xFFFFFFFFFFFFFFFF

        start_mask = 63-self.offset
        for bit in range(0,self.length):
            mask = clear_bit(mask, start_mask-bit)

        f_mask = 0x0
        for bit in range(0,self.length):
            f_mask = (f_mask | 0x01 << bit)

        conv_to = ""
        conv_from=""
        unit_str=""
        if self.unit:
            unit_str=" (Unit: {})".format(self.unit)
        if self.is_number:

            conv_to = ". Conversion formula (To raw from real): y=(x{1:+})/{0:.2f}".format(self.number_data[0], self.number_data[1]*-1)
            conv_from = ". Conversion formula (To real from raw): y=({0:.2f}x){1:+}".format(self.number_data[0], self.number_data[1])

        return """
    /** Sets {0}{6}{8} */
    void set_{1}({2} value){{ raw = (raw & 0x{5:{fill}16x}) | ((uint64_t)value & 0x{4:x}) << {3}; }}

    /** Gets {0}{7}{8} */
    {2} get_{1}() const {{ return ({2})(raw >> {3} & 0x{4:x}); }}
        """.format(self.desc, self.name, self.get_return_data_type(frame_name), 64-self.length-self.offset, f_mask, mask, conv_to, conv_from, unit_str, fill='0')

    def add_enum(self, e: EnumEntry):
        self.enum_table.append(e)

    def add_data_str(self, dt: str):
        self.is_bool = False
        self.is_enum = False
        self.is_iso_tp = False
        self.is_number = False

        if dt.strip() == "ISO_TP":
            self.is_iso_tp = True
        elif dt.strip() == "CHAR":
            self.is_char = True
        elif dt.strip() == "BOOL":
            self.is_bool = True
        elif "ENUM" in dt:
            self.is_enum = True
        elif "NUMBER" in dt:
            self.is_number = True
            multiplier = float(dt.split("_MULTIPLIER_: ")[1].split(",")[0])
            offset = float(dt.split("_OFFSET_: ")[1].split(")")[0])
            self.number_data = (multiplier, offset)
        else:
            print(dt)

class Frame:
    def __init__(self, name: str, id: int):
        self.name = name
        self.can_id = id
        self.signals=[]
    
    def add_signal(self, s: Signal):
        self.signals.append(s)

class ECU:
    def __init__(self, name: str):
        self.name = name
        self.frames=[]

    def add_frame(self, f: Frame):
        self.frames.append(f)

    def filter_frames(self):
        cloned = self.frames.copy()
        self.frames.clear()
        for x in cloned:
            if len(x.signals) > 1:
                self.frames.append(x)

    def make_output_str(self) -> str:
        self.filter_frames()
        # Create output header string

        guard = ""
        if output_guard:
            guard = "#ifdef {0}".format(global_guard)
        tmp = """
/**
* AUTOGENERATED BY convert.py
* DO NOT EDIT THIS FILE!
*
* IF MODIFICATIONS NEED TO BE MADE, MODIFY can_data.txt!
*
* CAN Defintiion for ECU '{0}'
*/

{1}

#ifndef __ECU_{0}_H_
#define __ECU_{0}_H_

#include <stdint.h>
    """.format(self.name, guard)

        for f in self.frames:
            tmp += "\n#define {}_CAN_ID 0x{:04X}".format(f.name.strip().removesuffix("h"), f.can_id)

        tmp += "\n\n"
        # Now iterate over all enums of the ECU
        for x in self.frames:
            for s in x.signals:
                if s.is_enum:
                    tmp += "/** {} */".format(s.desc)
                    tmp += "\nenum class {}_{} {{".format(x.name, s.name)
                    for e in s.enum_table:
                        tmp += "\n\t{} = {}, // {}".format(e.name, e.raw, e.desc)
                    tmp += "\n};\n\n"

        # Now create our type unions for CAN Frames!
        for x in self.frames:
            struct_name = x.name.strip().removesuffix("h")
            tmp += "\n\ntypedef union {" # Struct name
            tmp += "\n\tuint64_t raw;" # Store raw value
            tmp += "\n\tuint8_t bytes[8];"
            tmp += "\n\n\t/** Gets CAN ID of {} */".format(struct_name)
            tmp += "\n\tuint32_t get_canid(){{ return {}_CAN_ID; }}".format(struct_name)
            
            # Setters and getters!
            for s in x.signals:
                tmp += s.get_setter_and_getter(x.name)
            
            tmp += "\n}} {};\n\n".format(struct_name)


        # Now magic to create the class ;)

        num_frames = len(self.frames)

        tmp += "\n\nclass ECU_{} {{".format(self.name)
        tmp += "\n\tpublic:"
        # Setter function to import supported frames to the ECU
        tmp += """
        /**
         * @brief Imports the CAN frame given the CAN ID, CAN Contents, and current timestamp
         *
         * Returns true if the frame was imported successfully, and false if import failed (Due to non-matching CAN ID).
         *
         * NOTE: The endianness of the value cannot be guaranteed. It is up to the caller to correct the byte order!
         */
        bool import_frames(uint64_t value, uint32_t can_id, uint64_t timestamp_now) {
            switch(can_id) {"""
        for idx, frame in enumerate(self.frames):
            tmp += """
                case {0}_CAN_ID:
                    LAST_FRAME_TIMES[{1}] = timestamp_now;
                    FRAME_DATA[{1}] = value;
                    return true;""".format(frame.name.strip().removesuffix("h"), idx)
        tmp += """
                default:
                    return false;
            }
        }
        """
        # Now do getters!
        for idx, frame in enumerate(self.frames):
            tmp += """
        /** Sets data in pointer to {0}
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_{0}(uint64_t now, uint64_t max_expire_time, {0}* dest) const {{
            if (LAST_FRAME_TIMES[{1}] == 0 || dest == nullptr) {{ // CAN Frame has not been seen on bus yet / NULL pointer
                return false;
            }} else if (now - LAST_FRAME_TIMES[{1}] > max_expire_time) {{ // CAN Frame has not refreshed in valid interval
                return false;
            }} else {{ // CAN Frame is valid! return it
                dest->raw = FRAME_DATA[{1}];
                return true;
            }}
        }}
            """.format(frame.name.strip().removesuffix("h"), idx)
        tmp += "\n\tprivate:"
        tmp += "\n\t\tuint64_t FRAME_DATA[{0}];".format(num_frames)
        tmp += "\n\t\tuint64_t LAST_FRAME_TIMES[{0}];".format(num_frames)
        tmp += "\n};"

        # Lastly append endif guard
        tmp += "\n#endif // __ECU_{}_H_".format(self.name)
        if output_guard:
            tmp += "\n\n#endif // {}".format(global_guard)
        return tmp


current_ecu: ECU = None
current_frame: Frame = None
current_signal: Signal = None


for line in input_file:
    l = remove_useless_from_line(line)
    if not l.startswith("#"): # Ignore comments
        if l.startswith("ECU "):
            ecu = l.split("ECU ")[1].strip()
            if getattr(current_ecu, 'name', 'nan') != ecu and current_ecu != None:
                # Check if frame / signal is none
                if current_signal and current_frame:
                    if len(current_frame.signals) > 1: # Ignore ISO-TP endpoints
                        current_frame.add_signal(current_signal)
                    current_signal = None
                if current_frame and current_ecu:
                    current_ecu.add_frame(current_frame)
                    current_frame = None
                open("{}/{}.h".format(output_dir, current_ecu.name), 'w').write(current_ecu.make_output_str()) # Write tmp output str to file
            current_ecu = ECU(ecu)
        elif l.startswith("FRAME"):
            frame_name = l.split("FRAME ")[1].split("(")[0].strip()
            frame_id = int(l.split("(")[1].split(")")[0], 0)
            if current_signal and current_frame:
                current_frame.add_signal(current_signal)
            if current_frame:
                if len(current_frame.signals) > 1: # Ignore ISO-TP endpoints
                    # Its a new frame
                    current_ecu.add_frame(current_frame)
            current_frame = Frame(frame_name, frame_id)
            current_signal = None
        elif l.startswith("SIGNAL"):
            if current_signal:
                current_frame.add_signal(current_signal)
            signal_name = l.split("SIGNAL ")[1].split(", ")[0].strip()
            signal_offset = int(l.split("OFFSET: ")[1].split(",")[0], 10)
            signal_length = int(l.split("LEN: ")[1].split(",")[0], 10)
            signal_desc = l.split("DESC: ")[1].split(", DATA TYPE")[0].strip()
            signal_dt = l.split(", DATA TYPE ")[1]
            unit=""
            if "UNIT: " in l:
                unit = l.split("UNIT: ")[1]
            current_signal = Signal(signal_name, signal_desc, signal_length, signal_offset, unit)
            current_signal.add_data_str(signal_dt)
        elif l.startswith("ENUM"):
            if current_signal:
                enum_name = l.split("ENUM ")[1].split(", ")[0].strip()
                enum_raw = int(l.split("RAW: ")[1].split(", ")[0])
                enum_desc = l.split("DESC: ")[1].strip()
                current_signal.add_enum(EnumEntry(enum_name, enum_raw, enum_desc))


if current_signal and current_frame:
    current_frame.add_signal(current_signal)
    current_signal = None
if current_frame and current_ecu:
    current_ecu.add_frame(current_frame)
    current_frame = None
# Write last ECU in DB
open("{}/{}.h".format(output_dir, current_ecu.name), 'w').write(current_ecu.make_output_str()) # Write tmp output str to file