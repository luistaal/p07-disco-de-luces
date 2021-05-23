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

uint8_t buttonState = 0; // Estado del interruptor, LOW
uint8_t count = 0;

CRGB leds[NUM_LEDS];

enum Colors {
  PURPLE,
  GREEN,
  ROSE,
  BLUE
};

void setup()
{
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(PIN_BUTTON, INPUT);
  colorLeds(PURPLE);
}

void loop()
{
  buttonState = digitalRead(PIN_BUTTON);

  if (buttonState == HIGH)
  {
    count++;

    if (count > 3)
      count = 0;

    delay(DELAY_TIME);

    colorLeds(count);
  }
}

/*!
  @brief   Función para seleccionar el color según el parámetro seleccionado dentro de la lista de 'enum Colors'
  @param   color  Valor de 0 a 255
  @return  Llamada a la función 'displayColor()' con los valores para cada color (r, g, b)
*/ 
void colorLeds(uint8_t color) {
  switch (color) {
    case PURPLE:
      displayColor(0, 255, 0);
      break;
    case GREEN:
      displayColor(255, 0, 0);
      break;
    case ROSE:
      displayColor(51, 255, 153);
      break;
    case BLUE:
      displayColor(187, 153, 255);
      break;
  }
}

/*!
  @brief   Función que muestra los colores en la tira de led según los parámetros obtenidos
  @param   r  Valor de 0 a 255 para el color del led rojo
  @param   g  Valor de 0 a 255 para el color del led verde
  @param   b  Valor de 0 a 255 para el color del led azul
  @return  Llamada a la función 'setRGB()' con los valores obtenidos
*/ 
void displayColor(uint8_t r, uint8_t g, uint8_t b) {
  FastLED.clear();

  for (int dot = 0; dot < NUM_LEDS; dot++)
  {
    leds[dot].setRGB(r, g, b);
  }

  FastLED.show();
}
