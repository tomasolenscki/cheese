#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#define TEMPO_5 300000 // 5 min para cada jogador
#define TEMPO_10 600000 // 10 min para cada jogador
#define TEMPO_15 900000 // 15 min para cada jogador

class Timer{
  public:
  Timer();
  bool timer = false;
  bool contando_tempo = false;
  long tempo_MARROM = 2311;
  long tempo_BRANCO = 2211;
  unsigned long comeco_intervalo;
  void inicializa_tempos();
  bool acaba_tempo();
    void desconta_tempo();

  private:
  unsigned long tempo_atual;

};

int min_MARROM;
int seg_MARROM;
int min_BRANCO;
int seg_BRANCO;


void taskAtualizaTempo();


#endif // TIMER_H_INCLUDED