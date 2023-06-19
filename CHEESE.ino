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
#include "task_switcher.h"
#include "bt.h"

/*
  CHEESE - Grupo A
  Eric Toshio Mizukami (11804272)
  Marco Antonio Jabes Galvão Filho (11369711)
  Renan Hideo Watanabe (4777842)
  Tomás Windisch Olenscki (11803490)
*/

#define TASK_INTERVAL1 100
#define TASK_INTERVAL2 100
#define TASK_INTERVAL3 10
#define TASK_INTERVAL4 10

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
SoftwareSerial bt(tx, rx); //Rx Tx

Hall hall;
Button botao;
LCD tela;
Leds leds;
Jogo jogo;


void setup() {

  TaskController.createTask(&taskMaqEstados, TASK_INTERVAL1);
  TaskController.createTask(&taskObterEvento, TASK_INTERVAL2);
  TaskController.createTask(&taskImprimeMatriz, TASK_INTERVAL3);
  TaskController.createTask(&taskAtualizaTempo, TASK_INTERVAL4);

  TaskController.begin(1000);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  bt.begin(9600);
  lcd.begin(16,2);
  tela.menu_principal();
  delay(2000);
  Serial.println("Maquina de Estados iniciada");
  // make the pushbutton's pin an input:


  hall.inicializa_pinos();

  FastLED.addLeds<WS2812B, LED_PIN_1, COLOR_ORDER>(leds0, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_2, COLOR_ORDER>(leds1, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_3, COLOR_ORDER>(leds2, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_4, COLOR_ORDER>(leds3, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_5, COLOR_ORDER>(leds4, NUM_LEDS).setCorrection(TypicalLEDStrip);

    // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  leds.acende_todos_os_leds(rgb_apagado);

  randomSeed(analogRead(8));

}


void loop() {
  
  TaskController.runCurrentTask();

}