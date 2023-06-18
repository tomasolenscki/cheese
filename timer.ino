#include <Arduino.h>
#include "timer.h"
#include "botao.h"
#include "jogo.h"

void taskAtualizaTempo(){
  if (contando_tempo){
    desconta_tempo();   
    min_MARROM = (int)(tempo_MARROM/60000);
    seg_MARROM = (int)((tempo_MARROM%60000) / 1000 );
    min_BRANCO = (int)(tempo_BRANCO/60000);
    seg_BRANCO = (int)((tempo_BRANCO%60000) / 1000 );
    lcd.setCursor(0,0);
    lcd.print("M: " + String(tela.padZero(min_MARROM)) + ":" + String(tela.padZero(seg_MARROM)));
    lcd.setCursor(0,1);
    lcd.print("B: " + String(tela.padZero(min_BRANCO)) + ":" + String(tela.padZero(seg_BRANCO)));
  }
}

void inicializa_tempos(){
  if (game == CHEESE_5){
    tempo_MARROM = TEMPO_5;
    tempo_BRANCO = TEMPO_5;
    return;
  }
  if (game == CHEESE_10){
    tempo_MARROM = TEMPO_10;
    tempo_BRANCO = TEMPO_10;
    return;
  }
  if (game == CHEESE_15){
    tempo_MARROM = TEMPO_15;
    tempo_BRANCO = TEMPO_15;
    return;
  }
}

void desconta_tempo(){
/*

*/

  tempo_atual = millis();
  if (jogador_da_vez == MARROM){
    tempo_MARROM -= tempo_atual - comeco_intervalo;
  } else { // jogador_da_vez == BRANCO
    tempo_BRANCO -= tempo_atual - comeco_intervalo;
  }
  comeco_intervalo = tempo_atual; // atualiza novo comeco de intervalo
}

bool acaba_tempo(){
/*

*/

  if (tempo_MARROM <= 0){
    jogador_vencedor = BRANCO;
    contando_tempo = false;
    return true;
  } else if (tempo_BRANCO <= 0){
    jogador_vencedor = MARROM;
    contando_tempo = false;
    return true;
  }
  return false; // nao acabou o tempo
}