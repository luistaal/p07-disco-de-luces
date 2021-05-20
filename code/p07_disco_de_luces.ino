#include <FastLED.h>

const uint8_t NUM_LEDS = 30;
const uint8_t DATA_PIN = 2;
const uint8_t PIN_BUTTON_1 = 3;
const uint16_t DELAY_TIME = 1000;
const uint8_t BRIGHTNESS = 100;

uint8_t buttonState = 0;
int8_t count = -1;

CRGB leds[NUM_LEDS];

enum {
  MORADO,
  VERDE,
  ROSA,
  AZUL
};

void setup()
{
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(PIN_BUTTON_1, INPUT);
}

void loop()
{
  buttonState = digitalRead(PIN_BUTTON_1);

  if (buttonState == HIGH)
  {
    count++;

    if (count > 3)
      count = 0;

    delay(DELAY_TIME);

    switch (count) {
      case 0:
        colorLeds(MORADO);
        break;
      case 1:
        colorLeds(VERDE);
        break;
      case 2:
        colorLeds(ROSA);
        break;
      case 3:
        colorLeds(AZUL);
        break;
    }
  }
}

void colorLeds(int color) {
  switch (color) {
    case MORADO:
      displayColor(0, 255, 0);
      break;
    case VERDE:
      displayColor(255, 0, 0);
      break;
    case ROSA:
      displayColor(51, 255, 153);
      break;
    case AZUL:
      displayColor(187, 153, 255);
      break;
  }
}

void displayColor(int r, int g, int b) {
  FastLED.clear();

  for (int dot = 0; dot < NUM_LEDS; dot++)
  {
    leds[dot].setRGB(r, g, b);
  }

  FastLED.show();
}
