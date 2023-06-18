#include <Arduino.h>
#include "leds.h"

void acende_todos_os_leds(CRGB cor){

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

void inicial_cheese(){
  for(int i=0; i<=4; i++){
    leds0[i] = rgb_vermelho_claro;
    leds4[i] = rgb_vermelho_claro;
  }

  leds2[2] = rgb_vermelho_claro;

  FastLED.show();
}

void acende_possiveis_jogadas(){
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

  numero_de_movimentos = possible_moves();
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

void acende_casas_ilegais(){

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

void animacao_vez_do_jogador(){
  int x, y;
  if (cheese) {
    x = pos_cheese.x;
    y = pos_cheese.y;
    if (jogador_da_vez ==  MARROM){
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
    if (jogador_da_vez == MARROM){
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

void animacao_inicio(){
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



void animacao_vencedor(){
  if (jogador_vencedor == BRANCO){
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


  if (jogador_vencedor == MARROM){
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


bool verificarPosicaoEncontradaBranco(int x, int y) {
  for (int i = 0; i < 5; i++) {
    if (pos_ratos_brancos[i].x == x && pos_ratos_brancos[i].y == y) {
      return true;
    }
  }
  return false;
}

bool verificarPosicaoEncontradaMarrom(int x, int y) {
  for (int i = 0; i < 5; i++) {
    if (pos_ratos_marrons[i].x == x && pos_ratos_marrons[i].y == y) {
      return true;
    }
  }
  return false;
}

