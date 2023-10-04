#include <Adafruit_NeoPixel.h>

// Define the number of LEDs and the data pin for the WS2812 strip
#define LED_COUNT 30
#define LED_PIN 4

// Create an instance of the Adafruit NeoPixel library
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  // Initialize the NeoPixel library
  strip.begin();
  strip.show();
}

void loop() {
  // Night Rider animation
  for (int i = 0; i < LED_COUNT; i++) {
    // Turn on the current LED
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
    // Turn off the previous LED
    if (i > 0) {
      strip.setPixelColor(i-2, 0, 0, 0);
    }
    // Delay between LEDs
    delay(100);
  }

  // Repeat the animation in the reverse direction
  for (int i = LED_COUNT-1; i >= 0; i--) {
    // Turn on the current LED
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
    // Turn off the previous LED
    if (i < LED_COUNT-1) {
      strip.setPixelColor(i+2, 0, 0, 0);
    }
    // Delay between LEDs
    delay(100);
  }
}