#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#define TEMPO_POR_JOGADOR 300000 // 5 min para cada jogador


unsigned long tempo_MARROM = TEMPO_POR_JOGADOR;
int min_MARROM;
int seg_MARROM;
unsigned long tempo_BRANCO = TEMPO_POR_JOGADOR;
int min_BRANCO;
int seg_BRANCO;
unsigned long comeco_intervalo;
unsigned long tempo_atual;
bool timer = false;
bool contando_tempo = false;

void desconta_tempo();
bool acaba_tempo();

#endif // TIMER_H_INCLUDED