#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#define TEMPO_5 300000 // 5 min para cada jogador
#define TEMPO_10 600000 // 10 min para cada jogador
#define TEMPO_15 900000 // 15 min para cada jogador


long tempo_MARROM = 2311;
int min_MARROM;
int seg_MARROM;
long tempo_BRANCO = 2211;
int min_BRANCO;
int seg_BRANCO;
unsigned long comeco_intervalo;
unsigned long tempo_atual;
bool timer = false;
bool contando_tempo = false;

void taskAtualizaTempo();
void inicializa_tempos();
void desconta_tempo();
bool acaba_tempo();

#endif // TIMER_H_INCLUDED