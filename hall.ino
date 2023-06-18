#include <Arduino.h>
#include "hall.h"
#include "maquina_estados.h"

Hall::Hall(){}

void Hall::le_sensores(){
/*
Função que lê todos os sensores do tabuleiro e armazena o valor de todas as leituras
*/

  for(int i = 0; i<=4; i++){
    for(int j=4;j>=0;j--){
      sensores[i][j] = digitalRead(HallSensor[i][j]);
    }
  }

}

void Hall::inicializa_pinos(){
/*
Função para inicializar os pinos dos sensores hall
*/

  for(int i=0; i<=4; i++){
    for(int j=4; j>=0; j--){
      pinMode(HallSensor[i][j], INPUT);
    }
  }

}


