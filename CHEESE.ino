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
Timer timer;


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
  hall.setup();
  leds.setup();

  delay(2000);
  Serial.println("Maquina de Estados iniciada");

  randomSeed(analogRead(8));

}


void loop() {
  
  TaskController.runCurrentTask();

}