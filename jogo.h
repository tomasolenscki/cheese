#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#define MARROM 1
#define BRANCO 2
#define NEUTRON 3

// MODO DE JOGO
#define CHEESE 1
#define QUEENS 2

typedef struct {
    int x;
    int y;
} Move;

int tabuleiro_inicial_cheese[5][5] = {{0, 0, 0, 0, 0},
                                      {1, 1, 1, 1, 1},
                                      {1, 1, 0, 1, 1}, 
                                      {1, 1, 1, 1, 1},
                                      {0, 0, 0, 0, 0}};

int tabuleiro_inicial_queens[5][5] = {{0, 0, 0, 0, 0},
                                      {1, 1, 1, 1, 1},
                                      {0, 1, 1, 1, 0}, 
                                      {1, 1, 1, 1, 1},
                                      {0, 0, 0, 0, 0}};

int tabuleiro_cheese[5][5] = {{1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0},
                              {0, 0, 3, 0, 0}, 
                              {0, 0, 0, 0, 0},
                              {2, 2, 2, 2, 2}};

int tabuleiro_cheese_inicial[5][5] = {{1, 1, 1, 1, 1},
                                      {0, 0, 0, 0, 0},
                                      {0, 0, 3, 0, 0}, 
                                      {0, 0, 0, 0, 0},
                                      {2, 2, 2, 2, 2}};                                    

int jogador_da_vez = 2;
int jogador_vencedor = 2;
int game = CHEESE;
bool neutron = false;


int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int numero_movimentos;

Move moves[8];

Move pos_ratos_marrons[5];

Move pos_ratos_brancos[5];

Move peca_levantada = {.x = 0, .y = 0};

Move casa_escolhida = {.x = 0, .y = 0};

Move pos_cheese = {.x = 0, .y = 0};

bool peca_pronta(int game);
bool peca_levantou();
bool peca_abaixou();
int possible_moves();
bool verifica_jogador_cheese();
bool verifica_casa_escolhida(int x_fim, int y_fim);
int verifica_jogada();
int trata_peca_ilegal();
void acha_neutron();
bool neutron_preso();
int acha_ratos_marrons();
int acha_ratos_brancos();
void preenche_cor(int jogador);

#endif // JOGO_H_INCLUDED


