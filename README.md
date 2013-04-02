﻿Squawk
======

Squawk is a **minimalistic 8-bit software synthesizer & playroutine** library for Arduino.

The approach to generating sound is very simple - much akin to 80's game consoles.  
It follows that Squawk sounds very much like an old-school 8-bit video game (http://youtu.be/sFPqoVnI8sY).

Why? Because _simple_ is also _fast_.

The library is designed to play music **in the background** - simply tell Squawk to start playing, then go about your business and do whatever else you want your sketch to do. The music will keep playing until you tell it to stop.

Depending on the sample rate (quality), Squawk will use between 10% and 40% of the average Arduino CPU time.  
That leaves you with plenty of room to run your other tasks.

Contributors:
* Philip Linde - _mod conversion, music_
* Davey Taylor - _the rest_

Thanks to:
* Fredrik Ericsson
* Linus Åkesson
* David Cuartielles

Making music for Squawk
-----------------------

Music is made using a _tracker_ that can handle _ProTracker_ files.  
* A _tracker_ is a type of music composing software.  
* _ProTracker_ is a tracker that was popular on the Amiga 500.

If you are unfamiliar with trackers, you will need to refer to the manual for the tracker you choose.

### Tracker suggestions

There are many modern trackers that are capable of composing music in this format.
These are a few:

* OpenMPT http://openmpt.org/
* MilkyTracker http://www.milkytracker.org/

### Tracking rules

When tracking your music, start with `template/template.mod`, and follow a few additional rules.

1. Do not modify the template instruments/samples
2. Only use instrument/sample 1 in channel 1, 2 in ch. 2, and so on
3. Only use even numbers for parameters on volume related commands
4. Don't use advanced looping (regular jumps/breaks are ok)
5. Don't change tempo (changing speed is ok)
6. Put no more than 64 patterns in your pattern list

Have a look at the music in `convert/music` for example well-formed ProTracker modules.

Getting your music onto your Arduino
------------------------------------

Squawk requires your ProTracker files to be converted into Squawk melodies.

Melodies come in two flavors:
* As data you put in your sketch to download with your code.  
  `sketches/Squawk_player`
* As a file on an SD card connected to your Arduino.  
  `sketches/SquawkSD_player`

Both formats can be generated by converter in the `convert/` directory.

If you have an SD card connected to your Arduino, you can also have the Arduino convert your files directly on the SD card.  
`sketches/SquawkSD_convert`

Building the hardware
---------------------

The simplest way of testing things out is to connect a piezo speaker between GND and the chosen output pin (default 3).  
The `sketches/Squawk_player` sketch is tuned to frequencies suitable for a small boxed piezo speaker.

It is also possible to connect output to a speaker system, but this requires a few additional components:

    PIN 3 ____/\/\/\________| |____ AUDIO OUT
               1kΩ     _|_  | | 1µF
                   20nF___
    GND   ______________|__________ AUDIO GND

This is a first order ~8kHz low-pass filter to "smooth out" the PWM carrier frequency.

### Using a resistor ladder

The maximum PWM frequency for 8-bit output on a 16MHz Arduino is 62.5kHz.  
This is relatively close to audible frequencies (0-20kHz) which makes it difficult to filter out.  
There is also some distortion due to interference between the sample rate and carrier frequency.

Both of these problems can be alleviated by using an R-2R resistor ladder.  
See http://en.wikipedia.org/wiki/Resistor_ladder for more information.

At this time, this is supported on ATmega168 & ATmega328 devices only.  

    AUDIO OUT __| |_________              2kΩ
                | |    1kΩ  |___________/\/\/\__ PIN 7
             2kΩ    _/\/\/\_|    1kΩ
    PIN 6 __/\/\/\_|___________/\/\/\_    2kΩ
                       1kΩ   _________|_/\/\/\__ PIN 5
             2kΩ    _/\/\/\_|    1kΩ
    PIN 4 __/\/\/\_|___________/\/\/\_    2kΩ
                       1kΩ   _________|_/\/\/\__ PIN 3
             2kΩ    _/\/\/\_|    1kΩ
    PIN 2 __/\/\/\_|___________/\/\/\_    2kΩ
                       1kΩ   _________|_/\/\/\__ PIN 1
             2kΩ    _/\/\/\_|    2kΩ
    PIN 0 __/\/\/\_|___________/\/\/\__ GND +AUDIO GND

This will give you a clean signal, with very crisp treble.

To configure your Squawk sketch for this set-up, use the line  
`SQUAWK_CONSTRUCT_ISR(SQUAWK_RLD_PORTD)`

Digital output from a microcontroller is usually not perfectly clean:
* Glitches - differences in switching time between pins
* Ringing - swings in output voltage following level transition

Therefore it is not a bad idea to add low-pass filtering even when using a resistor ladder.