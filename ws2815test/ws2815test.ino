#include <FastLED.h>

#define LED_PIN     4
#define NUM_LEDS    30
#define BRIGHTNESS  16

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // Example light show pattern
  rainbow();
  delay(1000);
  theaterChaseRainbow();
  delay(1000);
  colorWipe(CRGB::Red, 30);
  delay(500);
  colorWipe(CRGB::Green, 30);
  delay(500);
  colorWipe(CRGB::Blue, 30);
  delay(500);
  colorWipe(CRGB::Black, 30);
  delay(500);
}

void rainbow() {
  // Fill the dots one after the other with a color
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(i * 256 / NUM_LEDS, 255, 255);
    FastLED.show();
    delay(30);
  }
}

void theaterChaseRainbow() {
  // Rainbow movie theater marquee chase effect
  for (int j = 0; j < 256; j++) {
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < NUM_LEDS; i = i + 3) {
        leds[i + q] = CHSV((i + j) % 255, 255, 255);
      }
      FastLED.show();
      delay(1);
      for (int i = 0; i < NUM_LEDS; i = i + 3) {
        leds[i + q] = CRGB::Black;
      }
    }
  }
}

void colorWipe(CRGB color, int wait) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
    FastLED.show();
    delay(wait);
  }
}
