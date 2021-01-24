# SoundViz
Sound visualizer using an Arduino, microphone and LEDs. Provides a great way to visualize your favorite songs as light shows.

## Required Components
* Arduino Uno/Mega or equivalent
* KY-038 sound sensor module
* LEDs (at least 8)
* Resistors (min 150 ohm, same count as LEDs)
* Jumper wires

## Circuit Setup
![soundviz circuit](img/soundviz.jpg)

1. Connect the positive power pin of the sound sensor module to an Arduino 5V power pin.
2. Connect the ground pin of the sound sensor module to an Arduino ground pin.
3. Connect the analog output pin of the sound sensor module to an analog input pin on the Arduino.
   * Make a note of the analog input pin you use, you will need it for the code.
   * If you use analog input pin `A0` you will not need to update the code.
4. For each LED, run wire from a digital output pin on the Arduino to a resistor, then into the positive side of the LED, then out the negative side of the LED back to ground on the Arduino.
   * Make a note of the pin numbers of each digital output pin you use and put order them based on in which order you want them to turn on. For example, if you use digital output pins 1-4 and you want pin 4 to correspond to the lowest volume sound, then 3 the next lowest, and eventually 1 corresponding to the highest sound, the order would be: 4, 3, 2, 1.

## Code Setup
1. Update the `SOUND_PIN` define on [line 1](soundviz.ino#L1) to the analog input pin to which you attached the sound module analog output in step 3 of [circuit setup](#circuit-setup).
2. Update the `NUM_LEDS` define on [line 2](soundviz.ino#L2) to the number of LEDs you used as part of your circuit.
3. Update the `ledPins` array on [line 7](soundviz.ino#L7) using the order of LEDs you determined in step 4 of [circuit setup](#circuit-setup).
4. Optionally update the `MIN_LEDS_TO_LIGHT` define on [line 3](soundviz.ino#L3) which determines how many LEDs will be lit regardless of the current sound volume.
   * For example, if you wanted 1 LED to be lit all the time to indicate that the device was powered on you could change the define from 0 to 1.
5. Optionally update the `NUM_SOUND_VALS` and `MAX_AMPLITUDE` defines on [lines 4 and 5](soundviz.ino#L4-L5). These parameters affect how the LEDs are lit up depending on the sound level. I found the current values through trial and error with the circuit shown in the picture above. Depending on the number of LEDs you use you may need to adjust these values slightly to achieve nice visual output.
