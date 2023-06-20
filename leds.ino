#include <Arduino.h>
#include "leds.h"

Leds::Leds(){}

void Leds::setup(){

  FastLED.addLeds<WS2812B, LED_PIN_1, COLOR_ORDER>(leds0, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_2, COLOR_ORDER>(leds1, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_3, COLOR_ORDER>(leds2, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_4, COLOR_ORDER>(leds3, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_PIN_5, COLOR_ORDER>(leds4, NUM_LEDS).setCorrection(TypicalLEDStrip);

    // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  leds.acende_todos_os_leds(rgb_apagado);

}

void Leds::acende_todos_os_leds(CRGB cor){
/*
Função que acende todos os leds com a cor especificada.
Pode também apagar todos os leds caso a cor seja (0, 0, 0)
*/

  for(int i=0; i<=4; i++){
      for(int j=0; j<=4; j++){
        switch (i){
          case (0):
            leds0[j] = cor;
          break;
          case (1):
            leds1[j] = cor;
          break;
          case (2):
            leds2[j] = cor;
          break;
          case (3):
            leds3[j] = cor;
          break;
          case (4):
            leds4[j] = cor;
          break;
        } 
      } 
    }

  FastLED.show();
  delay(50);

}

void Leds::inicial_cheese(){
/*
Função que acende as casas iniciasi do jogo cheese
*/

  for(int i=0; i<=4; i++){
    leds0[i] = rgb_vermelho_claro;
    leds4[i] = rgb_vermelho_claro;
  }

  leds2[2] = rgb_vermelho_claro;

  FastLED.show();
}

void Leds::acende_possiveis_jogadas(){
/*
Função que acende as possíveis jogadas de um rato
As possíveis jogadas são acessas em verde e a casa atual em amarelo
*/

  int x = peca_levantada.x;
  int y = peca_levantada.y;
  int numero_de_movimentos = 0;
 
  switch (x){
    case (0):
      leds0[y] = rgb_amarelo;
    break;
    case (1):
      leds1[y] = rgb_amarelo;
    break;
    case (2):
      leds2[y] = rgb_amarelo;
    break;
    case (3):
      leds3[y] = rgb_amarelo;
    break;
    case (4):
      leds4[y] = rgb_amarelo;
    break;
  }

  numero_de_movimentos = jogo.possible_moves();
  for (int i = 0; i<numero_de_movimentos; i++){
    x = moves[i].x;
    y = moves[i].y;
    switch (x){
      case (0):
        leds0[y] = rgb_verde;
      break;
      case (1):
        leds1[y] = rgb_verde;
      break;
      case (2):
        leds2[y] = rgb_verde;
      break;
      case (3):
        leds3[y] = rgb_verde;
      break;
      case (4):
        leds4[y] = rgb_verde;
      break;
    }
  }

  FastLED.show();

}

void Leds::acende_casas_ilegais(){
/*
Função que acende as casas quando um movimento ilegal é realizado
A casa posta incorreta é acessa em vermelho escuro 
A casa original do rato é acessa em vermelho claro
*/

  int x = peca_levantada.x;
  int y = peca_levantada.y;
  switch (x){
    case (0):
      leds0[y] = rgb_vermelho_claro;
    break;
    case (1):
      leds1[y] = rgb_vermelho_claro;
    break;
    case (2):
      leds2[y] = rgb_vermelho_claro;
    break;
    case (3):
      leds3[y] = rgb_vermelho_claro;
    break;
    case (4):
      leds4[y] = rgb_vermelho_claro;
    break;
  }

  x = casa_escolhida.x;
  y = casa_escolhida.y;
  switch (x){
    case (0):
      leds0[y] = rgb_vermelho_escuro;
    break;
    case (1):
      leds1[y] = rgb_vermelho_escuro;
    break;
    case (2):
      leds2[y] = rgb_vermelho_escuro;
    break;
    case (3):
      leds3[y] = rgb_vermelho_escuro;
    break;
    case (4):
      leds4[y] = rgb_vermelho_escuro;
    break;
  }

  FastLED.show();

}

void Leds::animacao_vez_do_jogador(){
/*
Animação com os LEDs que indica a vez de um dos jogadores
*/

  int x, y;
  if (jogo.cheese) {
    x = pos_cheese.x;
    y = pos_cheese.y;
    if (jogo.jogador_da_vez ==  MARROM){
      acende_todos_os_leds(rgb_apagado);
      switch (x){
        case (0):
          leds0[y] = rgb_marrom;
        break;
        case (1):
          leds1[y] = rgb_marrom;
        break;
        case (2):
          leds2[y] = rgb_marrom;
        break;
        case (3):
          leds3[y] = rgb_marrom;
        break;
        case (4):
          leds4[y] = rgb_marrom;
        break;
      }
      FastLED.show();
      delay(1000);
      acende_todos_os_leds(rgb_apagado);

    }
    else {
      switch (x){
        case (0):
          leds0[y] = rgb_branco;
        break;
        case (1):
          leds1[y] = rgb_branco;
        break;
        case (2):
          leds2[y] = rgb_branco;
        break;
        case (3):
          leds3[y] = rgb_branco;
        break;
        case (4):
          leds4[y] = rgb_branco;
        break;
      }
      FastLED.show();
      delay(1000);
      acende_todos_os_leds(rgb_apagado);
    }
  }

  else{
    if (jogo.jogador_da_vez == MARROM){
      acende_todos_os_leds(rgb_apagado);
      for(int i=0; i<=4; i++){
        x = pos_ratos_marrons[i].x;
        y = pos_ratos_marrons[i].y;
        switch (x){
          case (0):
            leds0[y] = rgb_marrom;
          break;
          case (1):
            leds1[y] = rgb_marrom;
          break;
          case (2):
            leds2[y] = rgb_marrom;
          break;
          case (3):
            leds3[y] = rgb_marrom;
          break;
          case (4):
            leds4[y] = rgb_marrom;
          break;
        }
      }
      FastLED.show();
      delay(1000);
      acende_todos_os_leds(rgb_apagado);
    }

    else {
      acende_todos_os_leds(rgb_apagado);
      for(int i=0; i<=4; i++){
        x = pos_ratos_brancos[i].x;
        y = pos_ratos_brancos[i].y;
        switch (x){
          case (0):
            leds0[y] = rgb_branco;
          break;
          case (1):
            leds1[y] = rgb_branco;
          break;
          case (2):
            leds2[y] = rgb_branco;
          break;
          case (3):
            leds3[y] = rgb_branco;
          break;
          case (4):
            leds4[y] = rgb_branco;
          break;
        }
      }
      FastLED.show();
      delay(1000);
      acende_todos_os_leds(rgb_apagado);
    }
  }
}

void Leds::animacao_inicio(){
/*
Animação do início do jogo
*/

  int x, y;
  leds2[2] = rgb_azul;
  FastLED.show();
  delay(500);
  for(int i=1; i<=3; i++){
    for(int j=1; j<=3; j++){
      switch (i){
        case (0):
          leds0[j] = rgb_azul;
        break;
        case (1):
          leds1[j] = rgb_azul;
        break;
        case (2):
          leds2[j] = rgb_azul;
        break;
        case (3):
          leds3[j] = rgb_azul;
        break;
        case (4):
          leds4[j] = rgb_azul;
        break;
      }      
    }
  }
  FastLED.show();
  delay(700);
  acende_todos_os_leds(rgb_azul);
  delay(700);
  acende_todos_os_leds(rgb_apagado);
  delay(300);
  acende_todos_os_leds(rgb_azul);
  delay(300);
  acende_todos_os_leds(rgb_apagado);
  delay(300);
  acende_todos_os_leds(rgb_azul);
  delay(1000);
  acende_todos_os_leds(rgb_apagado);
}



void Leds::animacao_vencedor(){
/*
Animação do vencedor do jogo
*/

  if (jogo.jogador_vencedor == BRANCO){
    for (int x = 0; x <= 4; x++) {
      for (int y = 0; y <= 4 ; y++) {
        switch (x){
          case (0):
            leds0[y] = rgb_azul;
          break;
          case (1):
            leds1[y] = rgb_azul;
          break;
          case (2):
            leds2[y] = rgb_azul;
          break;
          case (3):
            leds3[y] = rgb_azul;
          break;
          case (4):
            leds4[y] = rgb_azul;
          break;
        } 
        if (verificarPosicaoEncontradaBranco(x, y)) {
          switch (x){
            case (0):
              leds0[y] = rgb_branco;
            break;
            case (1):
              leds1[y] = rgb_branco;
            break;
            case (2):
              leds2[y] = rgb_branco;
            break;
            case (3):
              leds3[y] = rgb_branco;
            break;
            case (4):
              leds4[y] = rgb_branco;
            break;
          } 
        }  
      }
        FastLED.show();
        delay(200);
        for (int y = 0; y <= 4 ; y++) {
          switch (x){
            case (0):
              leds0[y] = rgb_apagado;
            break;
            case (1):
              leds1[y] = rgb_apagado;
            break;
            case (2):
              leds2[y] = rgb_apagado;
            break;
            case (3):
              leds3[y] = rgb_apagado;
            break;
            case (4):
              leds4[y] = rgb_apagado;
            break;
          } 
          if (verificarPosicaoEncontradaBranco(x, y)) {
            switch (x){
              case (0):
                leds0[y] = rgb_branco;
              break;
              case (1):
                leds1[y] = rgb_branco;
              break;
              case (2):
                leds2[y] = rgb_branco;
              break;
              case (3):
                leds3[y] = rgb_branco;
              break;
              case (4):
                leds4[y] = rgb_branco;
              break;
            } 
          }
        }
        FastLED.show();
        delay(60);    
    }
  acende_todos_os_leds(rgb_branco);
  delay(700);
  acende_todos_os_leds(rgb_apagado);
  delay(300);
  acende_todos_os_leds(rgb_branco);
  delay(300);
  acende_todos_os_leds(rgb_apagado);
  delay(300);
  acende_todos_os_leds(rgb_branco);
  delay(1000);
  acende_todos_os_leds(rgb_apagado);
  }


  if (jogo.jogador_vencedor == MARROM){
    for (int x = 0; x <= 4; x++) {
      for (int y = 0; y <= 4 ; y++) {
        switch (x){
          case (0):
            leds0[y] = rgb_azul;
          break;
          case (1):
            leds1[y] = rgb_azul;
          break;
          case (2):
            leds2[y] = rgb_azul;
          break;
          case (3):
            leds3[y] = rgb_azul;
          break;
          case (4):
            leds4[y] = rgb_azul;
          break;
        } 
        if (verificarPosicaoEncontradaMarrom(x, y)) {
          switch (x){
            case (0):
              leds0[y] = rgb_marrom;
            break;
            case (1):
              leds1[y] = rgb_marrom;
            break;
            case (2):
              leds2[y] = rgb_marrom;
            break;
            case (3):
              leds3[y] = rgb_marrom;
            break;
            case (4):
              leds4[y] = rgb_marrom;
            break;
          } 
        }  
      }
        FastLED.show();
        delay(200);
        for (int y = 0; y <= 4 ; y++) {
          switch (x){
            case (0):
              leds0[y] = rgb_apagado;
            break;
            case (1):
              leds1[y] = rgb_apagado;
            break;
            case (2):
              leds2[y] = rgb_apagado;
            break;
            case (3):
              leds3[y] = rgb_apagado;
            break;
            case (4):
              leds4[y] = rgb_apagado;
            break;
          } 
          if (verificarPosicaoEncontradaMarrom(x, y)) {
            switch (x){
              case (0):
                leds0[y] = rgb_marrom;
              break;
              case (1):
                leds1[y] = rgb_marrom;
              break;
              case (2):
                leds2[y] = rgb_marrom;
              break;
              case (3):
                leds3[y] = rgb_marrom;
              break;
              case (4):
                leds4[y] = rgb_marrom;
              break;
            } 
          }
        }
        FastLED.show();
        delay(60);    
    }
  acende_todos_os_leds(rgb_marrom);
  delay(700);
  acende_todos_os_leds(rgb_apagado);
  delay(300);
  acende_todos_os_leds(rgb_marrom);
  delay(300);
  acende_todos_os_leds(rgb_apagado);
  delay(300);
  acende_todos_os_leds(rgb_marrom);
  delay(1000);
  acende_todos_os_leds(rgb_apagado);
  }
}

void Leds::animacao_empate(){

  acende_todos_os_leds(rgb_amarelo);
  delay(700);
  acende_todos_os_leds(rgb_apagado);
  delay(700);
  acende_todos_os_leds(rgb_amarelo);
  delay(700);
  acende_todos_os_leds(rgb_apagado);

}


bool Leds::verificarPosicaoEncontradaBranco(int x, int y) {
/*
Função que verifica se algum rato branco esta em uma posição do tabuleiro
*/

  for (int i = 0; i < 5; i++) {
    if (pos_ratos_brancos[i].x == x && pos_ratos_brancos[i].y == y) {
      return true;
    }
  }
  return false;
}

bool Leds::verificarPosicaoEncontradaMarrom(int x, int y) {
/*
Função que verifica se algum rato marrom esta em uma posição do tabuleiro
*/

  for (int i = 0; i < 5; i++) {
    if (pos_ratos_marrons[i].x == x && pos_ratos_marrons[i].y == y) {
      return true;
    }
  }
  return false;
}

