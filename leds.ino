#include <Arduino.h>
#include "leds.h"


void acende_todos_os_leds(void){

for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      switch (i){
        case (0):
          leds0[j] = CRGB(0, 100, 100);
        break;
        case (1):
          leds1[j] = CRGB(0, 100, 100);
        break;
        case (2):
          leds2[j] = CRGB(0, 100, 100);
        break;
        case (3):
          leds3[j] = CRGB(0, 100, 100);
        break;
        case (4):
          leds4[j] = CRGB(0, 100, 100);
        break;
      } 
    } 
  }

FastLED.show();
delay(50);

}

void apaga_todos_os_leds(void){

for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      switch (i){
        case (0):
          leds0[j] = CRGB(0, 0, 0);
        break;
        case (1):
          leds1[j] = CRGB(0, 0, 0);
        break;
        case (2):
          leds2[j] = CRGB(0, 0, 0);
        break;
        case (3):
          leds3[j] = CRGB(0, 0, 0);
        break;
        case (4):
          leds4[j] = CRGB(0, 0, 0);
        break;
      } 
    } 
  }

FastLED.show();
delay(50);

}

void acende_casa(int sensores[5][5]){

  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      if(sensores[i][j] == 0){
        switch (i){
          case (0):
            leds0[4-j] = CRGB(0, 0, 0);
          break;
          case (1):
            leds1[4-j] = CRGB(0, 0, 0);
          break;
          case (2):
            leds2[4-j] = CRGB(0, 0, 0);
          break;
          case (3):
            leds3[4-j] = CRGB(0, 0, 0);
          break;
          case (4):
            leds4[4-j] = CRGB(0, 0, 0);
          break;
        }
      }
      else{
        switch (i){
          case (0):
            leds0[4-j] = CRGB(0, 100, 100);
          break;
          case (1):
            leds1[4-j] = CRGB(0, 100, 100);
          break;
          case (2):
            leds2[4-j] = CRGB(0, 100, 100);
          break;
          case (3):
            leds3[4-j] = CRGB(0, 100, 100);
          break;
          case (4):
            leds4[4-j] = CRGB(0, 100, 100);
          break;
        }
      }
    }
  }
}

void inicial_cheese(){
  for(int i=0; i<=4; i++){
    leds0[i] = CRGB(100, 0, 0);
    leds4[i] = CRGB(100, 0, 0);
  }

  leds2[2] = CRGB(100, 0, 0);

  FastLED.show();
}

void acende_possiveis_jogadas(){
  int x = peca_levantada.x;
  int y = peca_levantada.y;
  int numero_de_movimentos = 0;
 
  switch (x){
    case (0):
      leds0[y] = CRGB(100, 100, 0);
    break;
    case (1):
      leds1[y] = CRGB(100, 100, 0);
    break;
    case (2):
      leds2[y] = CRGB(100, 100, 0);
    break;
    case (3):
      leds3[y] = CRGB(100, 100, 0);
    break;
    case (4):
      leds4[y] = CRGB(100, 100, 0);
    break;
  }

  numero_de_movimentos = possible_moves();
  for (int i = 0; i<numero_de_movimentos; i++){
    x = moves[i].x;
    y = moves[i].y;
    switch (x){
      case (0):
        leds0[y] = CRGB(0, 100, 0);
      break;
      case (1):
        leds1[y] = CRGB(0, 100, 0);
      break;
      case (2):
        leds2[y] = CRGB(0, 100, 0);
      break;
      case (3):
        leds3[y] = CRGB(0, 100, 0);
      break;
      case (4):
        leds4[y] = CRGB(0, 100, 0);
      break;
    }
  }

  FastLED.show();

}
