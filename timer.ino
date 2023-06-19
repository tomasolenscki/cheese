#include <Arduino.h>
#include "timer.h"
#include "botao.h"
#include "jogo.h"

void taskAtualizaTempo(){
  if (timer.contando_tempo){
    timer.desconta_tempo();   
    min_MARROM = (int)(timer.tempo_MARROM/60000);
    seg_MARROM = (int)((timer.tempo_MARROM%60000) / 1000 );
    min_BRANCO = (int)(timer.tempo_BRANCO/60000);
    seg_BRANCO = (int)((timer.tempo_BRANCO%60000) / 1000 );
    lcd.setCursor(0,0);
    lcd.print("M: " + String(padZero(min_MARROM)) + ":" + String(padZero(seg_MARROM)));
    lcd.setCursor(0,1);
    lcd.print("B: " + String(padZero(min_BRANCO)) + ":" + String(padZero(seg_BRANCO)));
  }
}

Timer::Timer(){}

void Timer::inicializa_tempos(){
  if (jogo.game == CHEESE_5){
    tempo_MARROM = TEMPO_5;
    tempo_BRANCO = TEMPO_5;
    return;
  }
  if (jogo.game == CHEESE_10){
    tempo_MARROM = TEMPO_10;
    tempo_BRANCO = TEMPO_10;
    return;
  }
  if (jogo.game == CHEESE_15){
    tempo_MARROM = TEMPO_15;
    tempo_BRANCO = TEMPO_15;
    return;
  }
}

void Timer::desconta_tempo(){
/*

*/

  tempo_atual = millis();
  if (jogo.jogador_da_vez == MARROM){
    tempo_MARROM -= tempo_atual - comeco_intervalo;
  } else { // jogador_da_vez == BRANCO
    tempo_BRANCO -= tempo_atual - comeco_intervalo;
  }
  comeco_intervalo = tempo_atual; // atualiza novo comeco de intervalo
}

bool Timer::acaba_tempo(){
/*

*/

  if (tempo_MARROM <= 0){
    jogo.jogador_vencedor = BRANCO;
    contando_tempo = false;
    return true;
  } else if (tempo_BRANCO <= 0){
    jogo.jogador_vencedor = MARROM;
    contando_tempo = false;
    return true;
  }
  return false; // nao acabou o tempo
}