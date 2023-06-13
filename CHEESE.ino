#include <FastLED.h>
#include <LiquidCrystal.h>
#include "maquina_estados.h"
#include "leds.h"
#include "hall.h"
#include "lcd.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int codigoEvento = NENHUM_EVENTO;
int codigoAcao;
int estado = IDLE;
int eventoInterno = NENHUM_EVENTO;  

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  Serial.println("Maquina de Estados iniciada");
  // make the pushbutton's pin an input:

/******************************************************************
DESCOMENTAR
*******************************************************************
  inicializa_pinos();

  FastLED.addLeds<WS2812B, LED_PIN_1, COLOR_ORDER>(leds0, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_2, COLOR_ORDER>(leds1, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_3, COLOR_ORDER>(leds2, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_4, COLOR_ORDER>(leds3, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_5, COLOR_ORDER>(leds4, NUM_LEDS).setCorrection(TypicalLEDStrip);

    // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
*/

}


void loop() {

  
  if (eventoInterno == NENHUM_EVENTO) {
    codigoEvento = obterEvento();
  }
  else {
    codigoEvento = eventoInterno;
  }

  if (codigoEvento != NENHUM_EVENTO)
  {
    codigoAcao = obterAcao(estado, codigoEvento);
    eventoInterno = executarAcao(codigoAcao);
    estado = obterProximoEstado(estado, codigoEvento);
    Serial.print("Estado: ");
    Serial.print(estado);
    Serial.print(" Evento: ");
    Serial.print(codigoEvento);
    Serial.print(" Acao: ");
    Serial.println(codigoAcao);
  }
}