#include <Arduino.h>
#include "hall.h"
#include "maquina_estados.h"


void le_sensores(){

  for(int i = 0; i<=4; i++){
    for(int j=4;j>=0;j--){
      sensores[i][j] = digitalRead(HallSensor[i][j]);
    }
  }

}

void inicializa_pinos(){

  for(int i=0; i<=4; i++){
    for(int j=4; j>=0; j--){
      pinMode(HallSensor[i][j], INPUT);
    }
  }

}


