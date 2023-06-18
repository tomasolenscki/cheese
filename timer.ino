#include <Arduino.h>
#include "timer.h"
#include "botao.h"
#include "jogo.h"

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

  if (tempo_MARROM == 0 || tempo_MARROM >= 6000000){
    jogador_vencedor = BRANCO;
    contando_tempo = false;
    return true;
  } else if (tempo_BRANCO == 0 || tempo_BRANCO >= 6000000){
    jogador_vencedor = MARROM;
    contando_tempo = false;
    return true;
  }
  return false; // nao acabou o tempo
}