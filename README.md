# SoundViz
Sound visualizer using an Arduino, microphone and LEDs

### Required Components
* Arduino Uno/Mega or equivalent
* KY-038 sound sensor module
* LEDs (at least 8)
* Resistors (min 150 ohm, same count as LEDs)
* Jumper wires

## Circuit Setup
1. Connect the positive power pin of the sound sensor module to an Arduino 5V power pin
2. Connect the ground pin of the sound sensor module to an Arduino ground pin
3. Connect the analog output pin of the sound sensor module to an analog input pin on the Arduino
   * Make a note of the analog input pin you use, you will need it for the code
   * If you use analog input pin `A0` you will not need to update the code
4. For each LED, run wire from a digital output pin on the Arduino to a resistor, then into the positive side of the LED, then out the negative side of the LED back to ground on the Arduino.
   * Make a note of the pin numbers of each digital output pin you use and put order them based on in which order you want them to turn on. For example, if you use digital output pins 1-4 and you want pin 4 to correspond to the lowest volume sound, then 3 the next lowest, and eventually 1 corresponding to the highest sound, the order would be: 4, 3, 2, 1.
