/*
   Motion detecting LED Bar Light–just turns on if motion is detected.

   Sketch written by Neil Janwani, 01/29/22. www.github.com/njanwani
*/

#include <Adafruit_NeoPixel.h>

const int LED_PIN =         2;      // Arduino digital pin for LED
const int INTERRUPT_PIN =   7;      // Arduino motion detector interrupt pin

const int LED_COUNT =       91;     // Number of LEDS
const int BRIGHTNESS =      150;    // LED brightness
const int ON_TIME =         15000;  // How long LEDs should stay on if no motion is detected

unsigned long timer =       0;      // just counts milliseconds
double color =              0;      // color incrementor, see color()
boolean bar_on =            false;  // true if light's on, false otherwise
volatile boolean state =    false;  // used to start-up LED
volatile boolean reset =    false;  // used to reset timer

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);   // instantiate LED object

// Interrupt method, runs when motions is detectted
void motion() {
  state = true;
  reset = true;
}

// First method that is run
void setup() {
  // Setup motion detection
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), motion, RISING);
   
  // Setup strip
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS);
   
  // Initialize timer
  timer = millis();

}

void loop() {
  // Resetting timer...
  if (reset) {
    timer = millis(); // everytime motion is detected, reset the timer
    reset = false;
  } else if (millis() - timer >= ON_TIME) {
    state = false;  // to avoid race conditions by putting this later in the code,
                    // we only want to count when we KNOW no motion has been detected
  }
   
  // Decides when to turn on LED
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

// Animates turning on the LED strip
void animate_on() {
  for (int i = 0; i < LED_COUNT / 2 && !bar_on; i++) {
    strip.setPixelColor(i + LED_COUNT / 2, trig(color), trig(color + 2 * PI / 3), trig(color + 4 * PI / 3));
    strip.setPixelColor(-1 * i + LED_COUNT / 2, trig(color), trig(color + 2 * PI / 3), trig(color + 4 * PI / 3));
    strip.show();
    delay(0.2 * (LED_COUNT - i));
  }
  bar_on = true;
}

// Animates turning off the LED strip
void animate_off() {
  bar_on = false;
  for (int i = 0; i <= LED_COUNT / 2 + 1; i++) {
    strip.setPixelColor(LED_COUNT - i, 0, 0, 0);
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
    delay(0.2 * (LED_COUNT - i));
  }
}

// Handles color modulation
int trig(double color) {
  return 127 * sin(color) + 127;
}

// Simply increments color
void increment_color() {
  color += 0.001;
  if (color >= 2 * PI) {
    color = 0;
  }
}
