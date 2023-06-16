#include <FastLED.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include "maquina_estados.h"
#include "leds.h"
#include "hall.h"
#include "lcd.h"
#include "botao.h"
#include "jogo.h"
#include "timer.h"
// #include "bt.h"

/*
  CHEESE
  GUILHERME RODRIGUES MONTEIRO - 10706103
  JOAO RODRIGO WINDISCH OLENSCKI - 10773224
  LUCA RODRIGUES MIGUEL - 10705655
  LUI DAMIANCI FERREIRA - 10770579
*/

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
// SoftwareSerial bt(18, 19); //Rx Tx

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // bt.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  Serial.println("Maquina de Estados iniciada");
  lcd.print("Escolha o modo: ");
  // make the pushbutton's pin an input:


  inicializa_pinos();

  FastLED.addLeds<WS2812B, LED_PIN_1, COLOR_ORDER>(leds0, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_2, COLOR_ORDER>(leds1, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_3, COLOR_ORDER>(leds2, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_4, COLOR_ORDER>(leds3, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_5, COLOR_ORDER>(leds4, NUM_LEDS).setCorrection(TypicalLEDStrip);

    // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  apaga_todos_os_leds();


}


void loop() {
  
  if (eventoInterno == NENHUM_EVENTO) {
    codigoEvento = obterEvento();
  }
  else {
    Serial.println("evento interno:");
    Serial.println(eventoInterno);
    codigoEvento = eventoInterno;
    eventoInterno = NENHUM_EVENTO; 
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

  if (contando_tempo){
    desconta_tempo();
    Serial.print("tempo_BRANCO");
    Serial.println(tempo_BRANCO);
    Serial.print("tempo_MARROM");
    Serial.println(tempo_MARROM);    
    min_MARROM = (int)(tempo_MARROM/60000);
    seg_MARROM = (int)((tempo_MARROM%60000) / 1000 );
    min_BRANCO = (int)(tempo_BRANCO/60000);
    seg_BRANCO = (int)((tempo_BRANCO%60000) / 1000 );
    lcd.setCursor(0,0);
    lcd.print("M: " + String(padZero(min_MARROM)) + ":" + String(padZero(seg_MARROM)));
    lcd.setCursor(0,1);
    lcd.print("B: " + String(padZero(min_BRANCO)) + ":" + String(padZero(seg_BRANCO)));
  }

  delay(100);
}