#include <Arduino.h>
#include "jogo.h"
#include "maquina_estados.h"
#include "timer.h"

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

void reinicia_tabuleiro_cheese(){

  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      tabuleiro_cheese[i][j] = tabuleiro_cheese_inicial[i][j];
    }
  }

  neutron = false;
  jogador_da_vez = 2;

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

bool neutron_preso() {
  acha_neutron();
  int num_moves = 0;
  int x = pos_cheese.x;
  int y = pos_cheese.y;

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
        num_moves++;
    }
  }

  Serial.println("neutron preso:");
  Serial.println(num_moves);

  delay(50);

  return num_moves !=0 ? false : true;
  
}

bool verifica_jogador_cheese(){
  // Serial.println("verificou_jogador");
  int x_inicio = peca_levantada.x;
  int y_inicio = peca_levantada.y;
  // Serial.println(x_inicio);
  // Serial.println(y_inicio);
  // Serial.println(tabuleiro_cheese[x_inicio][y_inicio]);
  // Serial.println(jogador_da_vez); 
  if (((tabuleiro_cheese[x_inicio][y_inicio] == jogador_da_vez) && (neutron == false)) || ((tabuleiro_cheese[x_inicio][y_inicio] == NEUTRON) && (neutron == true))){
    return true;
  }
  return false;
}

void acha_neutron(){

  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      if (tabuleiro_cheese[i][j] == 3) {
        pos_cheese.x = i;
        pos_cheese.y = j;
        break;
      }
    }
  }
}

int acha_ratos_brancos(){
  int cont = 0;
  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      if (tabuleiro_cheese[i][j] == 2) {
        pos_ratos_brancos[cont].x = i;
        pos_ratos_brancos[cont].y = j;
        cont++;
        if (cont == 5){
          return 0;
        }
      }
    }
  }
  return 0;
}

int acha_ratos_marrons(){
  int cont = 0;
  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      if (tabuleiro_cheese[i][j] == 1) {
        pos_ratos_marrons[cont].x = i;
        pos_ratos_marrons[cont].y = j;
        cont++;
        if (cont == 5){
          return 0;
        }
      }
    }
  }
  return 0;
}

bool verifica_casa_escolhida(int x_fim, int y_fim){
  // Serial.println("verificou_casa");

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

    if (neutron && ((x_fim == 0 ) || (x_fim==4))) {
      contando_tempo = false;
      jogador_vencedor = (x_fim == 0 ) ? MARROM : BRANCO;
      return VITORIA_DERROTA;
    }

    tabuleiro_cheese[x_inicio][y_inicio] = 0;
    tabuleiro_cheese[x_fim][y_fim] = neutron ? NEUTRON : jogador_da_vez;

    if (neutron_preso()){
      contando_tempo = false;
      jogador_vencedor = jogador_da_vez;
      return VITORIA_DERROTA;
    }

    if (jogador_da_vez == BRANCO) {
      jogador_da_vez = neutron ? BRANCO : MARROM;
    }
    else if (jogador_da_vez == MARROM){
      jogador_da_vez = neutron ? MARROM : BRANCO;
    }

    // Serial.println("Jogador_atual");
    // Serial.println(jogador_da_vez);
  
    neutron = !neutron;
    // Serial.println("neutron");
    // Serial.println(neutron);

    acha_neutron();
    acha_ratos_marrons();
    acha_ratos_brancos();

    // if (neutron && !timer){
    //   return LEGAL_ULTIMO;
    // } else if (neutron && timer){
    //   return VERIFICACAO; // ainda tem que esperar o botao timer
    // } else if (!neutron){
    //   return LEGAL_nULTIMO;
    // }

  return neutron ? LEGAL_ULTIMO : LEGAL_nULTIMO ;

  }

  else if (game  == QUEENS){
    return -1;
  }

}


int trata_peca_ilegal(){

  acende_casas_ilegais();

  le_sensores();

  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      if (tabuleiro_cheese[i][j] == 0){
        if (sensores[i][j] != tabuleiro_cheese[i][j]){
          return NENHUM_EVENTO;
        }
      }
    }
  }

  return LEVANTA_PECA_ILEGAL;


}

