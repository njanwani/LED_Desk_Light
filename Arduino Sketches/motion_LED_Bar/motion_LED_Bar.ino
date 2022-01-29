/*
   Motion detecting LED Bar Light–just turns on if motion is detected.

   Sketch written by Neil Janwani, 01/29/22. www.github.com/njanwani
*/

#include <Adafruit_NeoPixel.h>

const int LED_PIN =         2;
const int INTERRUPT_PIN =    7;

const int LED_COUNT =       91;
const int BRIGHTNESS =      150;
const int ON_TIME =         15000;

unsigned long timer =       0;
double color =              0;
boolean bar_on =            false;
volatile boolean state =    false;
volatile boolean reset =    false;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void motion() {
  state = true;
  reset = true;
}

void setup() {
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), motion, RISING);
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS);
  timer = millis();

}

void loop() {
  if (reset) {
    timer = millis(); // everytime motion is detected, reset the timer
    reset = false;
  } else if (millis() - timer >= ON_TIME) {
    state = false;  // to avoid race conditions by putting this later in the code,
                    // we only want to count when we KNOW no motion has been detected
  }
  if (state) {
    animate_on();
    for (int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, trig(color), trig(color + 2 * PI / 3), trig(color + 4 * PI / 3));
    }
    strip.show();
    increment_color();
  } else {
    animate_off();
  }
}

void animate_on() {
  for (int i = 0; i < LED_COUNT / 2 && !bar_on; i++) {
    strip.setPixelColor(i + LED_COUNT / 2, trig(color), trig(color + 2 * PI / 3), trig(color + 4 * PI / 3));
    strip.setPixelColor(-1 * i + LED_COUNT / 2, trig(color), trig(color + 2 * PI / 3), trig(color + 4 * PI / 3));
    strip.show();
    delay(0.2 * (LED_COUNT - i));
  }
  bar_on = true;
}

void animate_off() {
  bar_on = false;
  for (int i = 0; i <= LED_COUNT / 2 + 1; i++) {
    strip.setPixelColor(LED_COUNT - i, 0, 0, 0);
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
    delay(0.2 * (LED_COUNT - i));
  }
}

int trig(double color) {
  return 127 * sin(color) + 127;
}

void increment_color() {
  color += 0.001;
  if (color >= 2 * PI) {
    color = 0;
  }
}
