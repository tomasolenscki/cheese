#include <Arduino.h>
#include "hall.h"
#include "maquina_estados.h"

/******************************************************************
DESCOMENTAR
*******************************************************************

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

bool peca_levantou(Move peca_levantada){

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

int possible_moves(int board[5][5], Move peca_levantada, Move* moves) {
    int num_moves = 0;
    int x = peca_levantada.x;
    int y = peca_levantada.y;

    for (int direction = 0; direction < 8; direction++) {
        int new_x = x + dx[direction];
        int new_y = y + dy[direction];

        while (new_x >= 0 && new_x < 5 && new_y >= 0 && new_y < 5 && board[new_x][new_y] == 1) {
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

    return num_moves;
}
*******************************************************************/
