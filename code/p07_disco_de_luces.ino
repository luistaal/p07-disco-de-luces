/*
  Proyecto nº 07. Disco de luces para iluminar detrás de cualquier pantalla.
  @author luistaal, 2021/03
  @version 1.0
  @see https://github.com/FastLED/FastLED

  Distribuida bajo licencia GNU General Public License V3
*/
#include <FastLED.h>

const uint8_t NUM_LEDS = 30;      // Número de pixeles o LEDs
const uint8_t DATA_PIN = 2;       // Pin de la tira NeoPixel, D2
const uint8_t PIN_BUTTON = 3;     // Pin al interruptor, D3
const uint16_t DELAY_TIME = 1000; // Tiempo de pausa
const uint8_t BRIGHTNESS = 100;   // Nivel de brillo, entre 0 y 255
const uint8_t NUM_COLORS = 4;     // Número de colores definidos

typedef struct Color
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

const Color PURPLE = Color{0, 255, 0};
const Color GREEN = Color{255, 0, 0};
const Color ROSE = Color{51, 255, 153};
const Color BLUE = Color{187, 153, 255};

uint8_t buttonState = 0;  // Estado del interruptor, LOW
uint8_t colorOrder = 0;   // Estado de inicio del orden de color

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(PIN_BUTTON, INPUT);
  displayColor(PURPLE);
}

void loop()
{
  buttonState = digitalRead(PIN_BUTTON);

  if (buttonState == HIGH)
  {
    colorOrder++;

    if (colorOrder > (NUM_COLORS - 1))
      colorOrder = 0;

    delay(DELAY_TIME);

    colorLeds(colorOrder);
  }
}

/*!
  @brief   Función para seleccionar el color según el valor de la variable 'colorOrder'
  @param   color  Valor de 0 a 255
  @return  Llamada a la función 'displayColor()' con los valores para cada color (r, g, b)
*/
void colorLeds(uint8_t color) {
  switch (color) {
    case 0:
      displayColor(PURPLE);
      break;
    case 1:
      displayColor(GREEN);
      break;
    case 2:
      displayColor(ROSE);
      break;
    case 3:
      displayColor(BLUE);
      break;
  }
}

/*!
  @brief   Función que muestra los colores en la tira de led según los parámetros obtenidos
  @param   color  Valores de 0 a 255 de RGB del color en su variable definida
  @return  Llamada a la función 'setRGB()' con los valores obtenidos
*/
void displayColor(Color color)
{
  FastLED.clear();

  for (int dot = 0; dot < NUM_LEDS; dot++)
  {
    leds[dot].setRGB(color.r, color.g, color.b);
  }

  FastLED.show();
};
