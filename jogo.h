#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#define MARROM 1
#define BRANCO 2
#define NEUTRON 3

// MODO DE JOGO
#define CHEESE 1
#define CHEESE_5 2
#define CHEESE_10 3
#define CHEESE_15 4

typedef struct {
    int x;
    int y;
} Move;

Move moves[8];
Move pos_ratos_marrons[5];
Move pos_ratos_brancos[5];
Move peca_levantada = {.x = 0, .y = 0};
Move casa_escolhida = {.x = 0, .y = 0};
Move pos_cheese = {.x = 0, .y = 0};

int numero_movimentos;

class Jogo{
  public:
  Jogo();
  int jogador_da_vez = 2;
  int jogador_vencedor = 2;
  int game = CHEESE;
  bool cheese = false;

  int tabuleiro_cheese[5][5] = {{1, 1, 1, 1, 1},
                                {0, 0, 0, 0, 0},
                                {0, 0, 3, 0, 0}, 
                                {0, 0, 0, 0, 0},
                                {2, 2, 2, 2, 2}};

  bool peca_pronta();
  bool peca_levantou();
  bool peca_abaixou();
  void reinicia_tabuleiro_cheese();
  void acha_cheese();
  int acha_ratos_marrons();
  int acha_ratos_brancos();
  int possible_moves();
  int verifica_jogada();
  int trata_peca_ilegal();
  void preenche_cor(int jogador);


  private:
  const int tabuleiro_inicial_cheese[5][5] = {{0, 0, 0, 0, 0},
                                              {1, 1, 1, 1, 1},
                                              {1, 1, 0, 1, 1}, 
                                              {1, 1, 1, 1, 1},
                                              {0, 0, 0, 0, 0}};

  const int tabuleiro_cheese_inicial[5][5] = {{1, 1, 1, 1, 1},
                                              {0, 0, 0, 0, 0},
                                              {0, 0, 3, 0, 0}, 
                                              {0, 0, 0, 0, 0},
                                              {2, 2, 2, 2, 2}}; 

  const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

  bool cheese_preso();
  bool verifica_jogador_cheese();
  bool verifica_casa_escolhida(int x_fim, int y_fim);


};

                                
#endif // JOGO_H_INCLUDED


