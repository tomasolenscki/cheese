#ifndef LEDS_H_INCLUDED
#define LEDS_H_INCLUDED

#define LED_PIN_1    24        //pino do arduino conectado a fita de LEDS WS2812B
#define LED_PIN_2    25
#define LED_PIN_3    26
#define LED_PIN_4    27
#define LED_PIN_5    28

#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB     //Ordem das cores na fita de led WS2812B
#define NUM_LEDS    5      //numero de leds na fita

#define BRIGHTNESS          125   //brilho dos leds  0 a 255


void acende_todos_os_leds(void);
void apaga_todos_os_leds(void);
void acende_casa(int sensores[5][5]);
void inicial_cheese();
void acende_possiveis_jogadas();
void acende_casas_ilegais();
void animacao_vez_do_jogador();
void animacao_inicio();

CRGB leds0[NUM_LEDS];
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];

CRGB rgb_marrom = CRGB(92,51,23);


#endif // LEDS_H_INCLUDED