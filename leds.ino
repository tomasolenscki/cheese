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

void acende_casas_ilegais(){

  int x = peca_levantada.x;
  int y = peca_levantada.y;
  switch (x){
    case (0):
      leds0[y] = CRGB(100, 0, 0);
    break;
    case (1):
      leds1[y] = CRGB(100, 0, 0);
    break;
    case (2):
      leds2[y] = CRGB(100, 0, 0);
    break;
    case (3):
      leds3[y] = CRGB(100, 0, 0);
    break;
    case (4):
      leds4[y] = CRGB(100, 0, 0);
    break;
  }

  x = casa_escolhida.x;
  y = casa_escolhida.y;
  switch (x){
    case (0):
      leds0[y] = CRGB(200, 0, 0);
    break;
    case (1):
      leds1[y] = CRGB(200, 0, 0);
    break;
    case (2):
      leds2[y] = CRGB(200, 0, 0);
    break;
    case (3):
      leds3[y] = CRGB(200, 0, 0);
    break;
    case (4):
      leds4[y] = CRGB(200, 0, 0);
    break;
  }

  FastLED.show();

}

void animacao_vez_do_jogador(){
  int x, y;
  // Serial.println("neutron?");
  // Serial.println(neutron);
  if (neutron) {
    x = pos_cheese.x;
    y = pos_cheese.y;
    // Serial.println("pos neutron");
    // Serial.println(x);
    // Serial.println(y); 
    if (jogador_da_vez == 1){
      apaga_todos_os_leds();
      switch (x){
        case (0):
          leds0[y] = CRGB(92,51,23);
        break;
        case (1):
          leds1[y] = CRGB(92,51,23);
        break;
        case (2):
          leds2[y] = CRGB(92,51,23);
        break;
        case (3):
          leds3[y] = CRGB(92,51,23);
        break;
        case (4):
          leds4[y] = CRGB(92,51,23);
        break;
      }
      FastLED.show();
      delay(1000);
      apaga_todos_os_leds();

    }
    else {
      switch (x){
        case (0):
          leds0[y] = CRGB(100, 100, 100);
        break;
        case (1):
          leds1[y] = CRGB(100, 100, 100);
        break;
        case (2):
          leds2[y] = CRGB(100, 100, 100);
        break;
        case (3):
          leds3[y] = CRGB(100, 100, 100);
        break;
        case (4):
          leds4[y] = CRGB(100, 100, 100);
        break;
      }
      FastLED.show();
      delay(1000);
      apaga_todos_os_leds();
    }
  }

  else{
    if (jogador_da_vez == 1){
      apaga_todos_os_leds();
      for(int i=0; i<=4; i++){
        x = pos_ratos_marrons[i].x;
        y = pos_ratos_marrons[i].y;
        switch (x){
          case (0):
            leds0[y] = CRGB(92,51,23);
          break;
          case (1):
            leds1[y] = CRGB(92,51,23);
          break;
          case (2):
            leds2[y] = CRGB(92,51,23);
          break;
          case (3):
            leds3[y] = CRGB(92,51,23);
          break;
          case (4):
            leds4[y] = CRGB(92,51,23);
          break;
        }
      }
      FastLED.show();
      delay(1000);
      apaga_todos_os_leds();
    }

    else {
      apaga_todos_os_leds();
      for(int i=0; i<=4; i++){
        x = pos_ratos_brancos[i].x;
        y = pos_ratos_brancos[i].y;
        switch (x){
          case (0):
            leds0[y] = CRGB(100,100,100);
          break;
          case (1):
            leds1[y] = CRGB(100,100,100);
          break;
          case (2):
            leds2[y] = CRGB(100,100,100);
          break;
          case (3):
            leds3[y] = CRGB(100,100,100);
          break;
          case (4):
            leds4[y] = CRGB(100,100,100);
          break;
        }
      }
      FastLED.show();
      delay(1000);
      apaga_todos_os_leds();
    }
  }
}

void animacao_inicio(){
  int x, y;
  leds2[2] = CRGB(0,100,100);
  FastLED.show();
  delay(700);
  for(int i=1; i<=3; i++){
    for(int j=1; j<=3; j++){
      switch (i){
        case (0):
          leds0[j] = CRGB(0,100,100);
        break;
        case (1):
          leds1[j] = CRGB(0,100,100);
        break;
        case (2):
          leds2[j] = CRGB(0,100,100);
        break;
        case (3):
          leds3[j] = CRGB(0,100,100);
        break;
        case (4):
          leds4[j] = CRGB(0,100,100);
        break;
      }      
    }
  }
  FastLED.show();
  delay(700);
  acende_todos_os_leds();
  delay(700);
  apaga_todos_os_leds();
  delay(300);
  acende_todos_os_leds();
  delay(300);
  apaga_todos_os_leds();
  delay(300);
  acende_todos_os_leds();
  delay(1000);
  apaga_todos_os_leds();
}

