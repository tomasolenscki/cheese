#include <Arduino.h>
#include "leds.h"

/******************************************************************
DESCOMENTAR
*******************************************************************
void acende_todos_os_leds(void){

for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      switch (i){
        case (0):
          leds0[j] = CRGB(0, 100, 100);
          Serial.println('i:');
          Serial.println(i);
          Serial.println('j:');
          Serial.println(j);
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
******************************************************/