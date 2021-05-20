#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 2
#define PIN_BUTTON_1 3
#define DELAY_TIME 1000

int buttonState = 0;
int count = -1;

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
  pinMode(PIN_BUTTON_1, INPUT);

  FastLED.setBrightness(2);
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

    if (count == 0)
    {
      colorLeds(MORADO);
    }

    if (count == 1)
    {
      colorLeds(VERDE);
    }

    if (count == 2)
    {
      colorLeds(ROSA);
    }

    if (count == 3)
    {
      colorLeds(AZUL);
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
