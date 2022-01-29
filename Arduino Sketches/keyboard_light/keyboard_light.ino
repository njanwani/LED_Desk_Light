/*
 * Simple LED Bar Light–just turns on when connected to power.
 * 
 * Sketch written by Neil Janwani, 01/29/22. www.github.com/njanwani
 */

#include <Adafruit_NeoPixel.h>

#define LED_PIN     2

#define LED_COUNT 91

#define BRIGHTNESS 100

double color = 0;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS);
  animate_on();
}

void loop() {
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, trig(color), trig(color + 2 * PI / 3), trig(color + 4 * PI / 3));
  }
  strip.show();
  //delay(10);
  color += 0.004;
  if (color >= 2 * PI) {
    color = 0;
  }
}

void animate_on() {
  for (int i = 0; i < LED_COUNT / 2; i++) {
    strip.setPixelColor(i + LED_COUNT / 2, trig(color), trig(color + 2 * PI / 3), trig(color + 4 * PI / 3));
    strip.setPixelColor(-1 * i + LED_COUNT / 2, trig(color), trig(color + 2 * PI / 3), trig(color + 4 * PI / 3));
    strip.show();
    delay(1 * (LED_COUNT - i));
  }
}

int trig(double color) {
  return 127 * sin(color) + 127;
}
