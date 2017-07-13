# ArdGenFu - The Arduino Function Generator
## Purpose
Generate square wave at high frequencies and allow switching of the frequency through use of a potentiometer.
Generates a square wave (duty cycle 50%).
## === Limitation - lowest frequency ===
This function uses, delayMicroseconds(), which is reportedly limited to a largest value 16383, which corresponds to about 30.5 Hz.  
If you want slower, you can just use the regular delay() function.

## === Setting a Frequency ===
This script can read a voltage from an analog pin and use this to set the output frequency.
Reading from analog pin gives you 1024 levels.
For my demo purpose I decided on a simple mapping from 32 Hz to 1055 Hz.

# Notes

## === Pin Addressing ===
Pin 12 is B010000. 13 is B100000. Both pin 12&13 on would be B110000
Both pins go off at B000000

## === Frequency outputs ===
f = 1/(2T), where T is the delay time in microseconds
Examples
T = 56, f = 9 kHz
T = 50,000 gives f=10 Hz, but largest working delay is 16383
T = 5,000 gives f=100 Hz
T = 16383 gives f = 30.5 Hz
