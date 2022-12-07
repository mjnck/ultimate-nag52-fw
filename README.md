# Firmware for Ultimate NAG52 (Open source 722.6 TCM with CANBUS support)

EARLY WIP. See the [main repository](https://github.com/rnd-ash/ultimate_nag52) for details about the project and the [wiki](https://github.com/rnd-ash/ultimate_nag52/wiki)

For context on this project, checkout my [video playlist](https://youtube.com/playlist?list=PLxrw-4Vt7xtu9d8lCkMCG0_K7oHcsSMtF) showing the TCM in action and progress on it!

## DISCLAIMER

I am in no way responsible if your gearbox or car dies as a result of using this firmware!
Although this firmware is being tested actively, there are loads of unknowns which may occur rarely during operation that
are not tested yet.

## IMPORTANT

If you have just built your board, or are updating to firmware after 30/11/22, please look at [this guide](https://youtu.be/ov3pYcKIA70)!
Your TCU will be bricked until you follow it!

## Generating the code documentation

1. Install [doxygen](https://www.doxygen.nl/manual/install.html)
2. Clone doxygen-awesome-css submodule with `git submodule update --init --recursive`
3. Run `doxygen`
4. View code documentation in the generated `html` folder
