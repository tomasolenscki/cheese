#ifndef HALL_H_INCLUDED
#define HALL_H_INCLUDED
/******************************************************************
DESCOMENTAR
*******************************************************************
typedef struct {
    int x;
    int y;
} Move;

void le_sensores();
void inicializa_pinos();
bool peca_pronta(int game);
bool peca_levantou(Move peca_levantada);
int possible_moves(int board[5][5], Move peca_levantada, Move* moves);

int HallSensor[5][5] = {{29, 30, 31, 32, 33},
                        {34, 35, 36, 37, 38},
                        {39, 40, 41, 42, 43}, 
                        {44, 45, 46, 47, 48},
                        {49, 50, 51, 52, 53}};

int sensores[5][5];

int tabuleiro_inicial_cheese[5][5] = {{0, 0, 0, 0, 0},
                                      {1, 1, 1, 1, 1},
                                      {1, 1, 0, 1, 1}, 
                                      {1, 1, 1, 1, 1},
                                      {0, 0, 0, 0, 0}};

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

Move moves[8];

Move peca_levantada = {.x = 0, .y = 0};

Move casa_escolhida = {.x = 0, .y = 0};
 *********************************************************/
#endif // HALL_H_INCLUDED
                                    