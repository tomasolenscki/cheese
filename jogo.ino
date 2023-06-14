#include <Arduino.h>
#include "maquina_estados.h"

bool peca_pronta(int game){

  le_sensores();

  if(game == CHEESE) {
    for(int i=0; i<=4; i++){
      for(int j=0; j<=4; j++){
        if (sensores[i][j] != tabuleiro_inicial_cheese[i][j]) return false;
      }
    }
    return true;
  }

  else if(game == QUEENS) {
    return true;
  }
}

bool peca_levantou(){

  int tabuleiro_antigo[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      tabuleiro_antigo[i][j] = sensores[i][j];
    }
  }

  le_sensores();

  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      if (sensores[i][j] != tabuleiro_antigo[i][j]){
        peca_levantada.x = i;
        peca_levantada.y = j;
        return true;
      }
    }
  }

  return false;
}

bool peca_abaixou(){

  int tabuleiro_antigo[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      tabuleiro_antigo[i][j] = sensores[i][j];
    }
  }

  le_sensores();

  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      if (sensores[i][j] != tabuleiro_antigo[i][j]){
        casa_escolhida.x = i;
        casa_escolhida.y = j;
        return true;
      }
    }
  }

  return false;
}

int possible_moves() {

  int num_moves = 0;
  int x = peca_levantada.x;
  int y = peca_levantada.y;

  for (int direction = 0; direction < 8; direction++) {
    int new_x = x + dx[direction];
    int new_y = y + dy[direction];

    while (new_x >= 0 && new_x < 5 && new_y >= 0 && new_y < 5 && tabuleiro_cheese[new_x][new_y] == 0) {
      new_x += dx[direction];
      new_y += dy[direction];
    }

    // Revertendo a última iteração quando a peça atinge um obstáculo ou o limite do tabuleiro
    new_x -= dx[direction];
    new_y -= dy[direction];
    
    // Verificando se a nova posição é diferente da posição original
    if (new_x != x || new_y != y) {
        moves[num_moves].x = new_x;
        moves[num_moves].y = new_y;
        num_moves++;
    }
  }

  numero_movimentos = num_moves;

  return num_moves;
}

bool verifica_jogador_cheese(){
  Serial.println("verificou_jogador");
  int x_inicio = peca_levantada.x;
  int y_inicio = peca_levantada.y;
  Serial.println(x_inicio);
  Serial.println(y_inicio);
  Serial.println(tabuleiro_cheese[x_inicio][y_inicio]);
  Serial.println(jogador_da_vez); 
  if (((tabuleiro_cheese[x_inicio][y_inicio] == jogador_da_vez) && (neutron == false)) || ((tabuleiro_cheese[x_inicio][y_inicio] == NEUTRON) && (neutron == true))){
    return true;
  }
  return false;
}

bool verifica_casa_escolhida(int x_fim, int y_fim){
  Serial.println("verificou_casa");

  bool esta_na_lista = false;
  int x, y;

  for (int i = 0; i<numero_movimentos; i++){
    x = moves[i].x;
    y = moves[i].y;

    if ((x == x_fim) && (y == y_fim)) esta_na_lista = true;

  }

  return esta_na_lista;

}  

int verifica_jogada(){

  int x_inicio = peca_levantada.x;
  int y_inicio = peca_levantada.y;
  int x_fim = casa_escolhida.x;
  int y_fim = casa_escolhida.y;

  if (game == CHEESE){

    if ((x_fim == x_inicio ) && (y_fim == y_inicio)){
      return DEVOLVE_PECA;
    }

    if (!verifica_jogador_cheese()){
      return ESCOLHA_ILEGAL;
    }

    if (!verifica_casa_escolhida(x_fim, y_fim)){
      return ESCOLHA_ILEGAL;
    }

    if (neutron && ((x_fim == 0 )|| (x_fim==4))) {
      return VITORIA_DERROTA;
    }

    tabuleiro_cheese[x_inicio][y_inicio] = 0;
    tabuleiro_cheese[x_fim][y_fim] = neutron ? NEUTRON : jogador_da_vez;

    if (jogador_da_vez == BLUE) {
      jogador_da_vez = neutron ? GREEN : BLUE;
    }
    else if (jogador_da_vez == GREEN){
      jogador_da_vez = neutron ? BLUE : GREEN;
    }

    Serial.println("Jogador_atual");
    Serial.println(jogador_da_vez);
  
    neutron = !neutron;
    Serial.println("neutron");
    Serial.println(neutron);

    return neutron ? LEGAL_ULTIMO : LEGAL_nULTIMO ;

  }

  else if (game  == QUEENS){
    return -1;
  }

}