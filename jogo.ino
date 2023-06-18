#include <Arduino.h>
#include "jogo.h"
#include "maquina_estados.h"
#include "hall.h"

void preenche_cor(int jogador){
/*
Função que preenche o tabuleiro com a cor de um jogador
Funciona como animação de vitória para o bluetooth
*/
  
  if (jogador == MARROM){
   for(int i=0; i<=4; i++){
      for(int j=0; j<=4; j++){
        tabuleiro_cheese[i][j] = MARROM;
      }
    }
  }

  if (jogador == BRANCO){
   for(int i=0; i<=4; i++){
      for(int j=0; j<=4; j++){
        tabuleiro_cheese[i][j] = BRANCO;
      }
    }
  }
}

bool peca_pronta(){
/*
Indica que todas as peças estão posicionadas na posição inicial
*/

  hall.le_sensores();

  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      if (hall.sensores[i][j] != tabuleiro_inicial_cheese[i][j]) return false;
    }
  }
  return true;

}

bool peca_levantou(){
/*
Indica que uma peça foi levantada
*/

  int tabuleiro_antigo[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      tabuleiro_antigo[i][j] = hall.sensores[i][j];
    }
  }

  hall.le_sensores();

  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      if (hall.sensores[i][j] != tabuleiro_antigo[i][j]){
        peca_levantada.x = i;
        peca_levantada.y = j;
        return true;
      }
    }
  }

  return false;
}

bool peca_abaixou(){
/*
Indica que uma peça foi posta no tabuleiro
*/

  int tabuleiro_antigo[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      tabuleiro_antigo[i][j] = hall.sensores[i][j];
    }
  }

  hall.le_sensores();

  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      if (hall.sensores[i][j] != tabuleiro_antigo[i][j]){
        casa_escolhida.x = i;
        casa_escolhida.y = j;
        return true;
      }
    }
  }

  return false;
}

void reinicia_tabuleiro_cheese(){
/*
Volta a matriz de tabuleiro à função original
*/

  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      tabuleiro_cheese[i][j] = tabuleiro_cheese_inicial[i][j];
    }
  }

  cheese = false;
  jogador_da_vez = (int) random(1,2);

}

int possible_moves() {
/*
Função que calcula os movimentos possíveis para uma peça no tabuleiro
*/

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

bool cheese_preso() {
/*
Função que verifica se o cheese não pode mais se mexer
*/

  acha_cheese();
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

  delay(50);

  return num_moves !=0 ? false : true;
  
}

bool verifica_jogador_cheese(){
/*
Função que verifica se a peça levantada foi do jogador da vez
*/

  int x_inicio = peca_levantada.x;
  int y_inicio = peca_levantada.y;

  if (((tabuleiro_cheese[x_inicio][y_inicio] == jogador_da_vez) && (cheese == false)) || ((tabuleiro_cheese[x_inicio][y_inicio] == NEUTRON) && (cheese == true))){
    return true;
  }
  return false;
}

void acha_cheese(){
/*
Função para encontrar as coordenadas x e y do cheese
*/

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
/*
Função para achar as coordenadas dos 5 ratos brancos
*/

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
/*
Função para achar as coordenadas dos 5 ratos marrons
*/

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
/*
Função que verifica se a casa escolhida para uma jogada é ou não legal
*/

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
/*
Função que verifica se uma jogada é legal ou não
Ela separa as diferentes possibilidades de jogada nos seus respectivos eventos internos
Também atualiza a matriz do jogo caso a jogada seja legal
*/

  int x_inicio = peca_levantada.x;
  int y_inicio = peca_levantada.y;
  int x_fim = casa_escolhida.x;
  int y_fim = casa_escolhida.y;



  if ((x_fim == x_inicio ) && (y_fim == y_inicio)){
    return DEVOLVE_PECA;
  }

  if (!verifica_jogador_cheese()){
    return ESCOLHA_ILEGAL;
  }

  if (!verifica_casa_escolhida(x_fim, y_fim)){
    return ESCOLHA_ILEGAL;
  }

  if (cheese && ((x_fim == 0 ) || (x_fim==4))) {
    contando_tempo = false;
    jogador_vencedor = (x_fim == 0 ) ? MARROM : BRANCO;
    return VITORIA_DERROTA;
  }

  tabuleiro_cheese[x_inicio][y_inicio] = 0;
  tabuleiro_cheese[x_fim][y_fim] = cheese ? NEUTRON : jogador_da_vez;

  if (cheese_preso()){
    contando_tempo = false;
    jogador_vencedor = jogador_da_vez;
    return VITORIA_DERROTA;
  }

  if (jogador_da_vez == BRANCO) {
    jogador_da_vez = cheese ? BRANCO : MARROM;
  }
  else if (jogador_da_vez == MARROM){
    jogador_da_vez = cheese ? MARROM : BRANCO;
  }

  cheese = !cheese;

  acha_cheese();
  acha_ratos_marrons();
  acha_ratos_brancos();

  return cheese ? LEGAL_ULTIMO : LEGAL_nULTIMO ;

}


int trata_peca_ilegal(){
/*
Função que percebe se uma jogada ilegal foi refeita as condições originais
*/

  acende_casas_ilegais();
  hall.le_sensores();

  for(int i=0; i<=4; i++){
    for(int j=0; j<=4; j++){
      if (tabuleiro_cheese[i][j] == 0){
        if (hall.sensores[i][j] != tabuleiro_cheese[i][j]){
          return NENHUM_EVENTO;
        }
      }
    }
  }

  return LEVANTA_PECA_ILEGAL;


}

