#define SOUND_PIN A0
#define NUM_LEDS 16
#define MIN_LEDS_TO_LIGHT 0
#define NUM_SOUND_VALS 10
#define MAX_AMPLITUDE 6

unsigned short ledPins[NUM_LEDS] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 40, 38, 36, 34};

int soundVals[NUM_SOUND_VALS];
int soundVal;
long sum;
int centerAmplitude;
unsigned int amplitude;
unsigned short ledsToLight;
unsigned int i;

void setup() {
  // Initialize LED pins for output
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Read sound value from microphone analog input
  soundVal = analogRead(SOUND_PIN);

  // Calculate center amplitude by taking the average of the soundVals
  sum = 0;
  for (i = 0; i < NUM_SOUND_VALS - 1; i++) {
    soundVals[i] = soundVals[i+1];
    sum += soundVals[i];
  }
  soundVals[NUM_SOUND_VALS-1] = soundVal;
  sum += soundVal;
  centerAmplitude = sum / NUM_SOUND_VALS;

  // Convert soundVal to absolute amplitude relative to center amplitude
  amplitude = abs(soundVal - centerAmplitude);
  if (amplitude > MAX_AMPLITUDE) {
    amplitude = MAX_AMPLITUDE;
  }

  // Determine number of LEDs to light based on amplitude
  ledsToLight = map(amplitude, 0, MAX_AMPLITUDE, MIN_LEDS_TO_LIGHT, NUM_LEDS);

  // Update LEDs
  for (i = 0; i < ledsToLight; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  for (i = ledsToLight; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
