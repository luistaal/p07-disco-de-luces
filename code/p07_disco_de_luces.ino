#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 2
#define PIN_BUTTON_1 3
#define DELAY_TIME 1000

int buttonState = 0;
int count = -1;

CRGB leds[NUM_LEDS];

enum colores {
  morado = "0, 255, 0",
  verde = "255, 0, 0",
  rosa = "51, 255, 153",
  azul = "187, 153, 255"
}

void setup()
{
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  pinMode(PIN_BUTTON_1, INPUT);

  FastLED.setBrightness(100);
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

    // Color morado
    if (count == 0)
    {
      FastLED.clear();

      for (int dot = 0; dot < NUM_LEDS; dot++)
      {
        if (dot % 2 == 0)
        {
          leds[dot].setRGB(0, 255, 0);
        }
        else
        {
          leds[dot].setRGB(0, 0, 255);
        }
      }

      FastLED.show();
    }

    // Color verde suave
    if (count == 1)
    {
      FastLED.clear();

      for (int dot = 0; dot < NUM_LEDS; dot++)
      {
        leds[dot].setRGB(colores.verde);
      }

      FastLED.show();
    }

    // Rosa
    if (count == 2)
    {
      FastLED.clear();

      for (int dot = 0; dot < NUM_LEDS; dot++)
      {
        leds[dot].setRGB(51, 255, 153);
      }

      FastLED.show();
    }

    // Azul suave
    if (count == 3)
    {
      FastLED.clear();

      for (int dot = 0; dot < NUM_LEDS; dot++)
      {
        leds[dot].setRGB(187, 153, 255);
      }

      FastLED.show();
    }
  }
}
