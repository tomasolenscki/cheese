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

#define BRIGHTNESS          200   //brilho dos leds  0 a 255

const CRGB rgb_marrom = CRGB(139, 69, 19);
const CRGB rgb_branco = CRGB(100, 100, 100);
const CRGB rgb_verde = CRGB(0, 100, 0);
const CRGB rgb_vermelho_claro = CRGB(100, 0, 0);
const CRGB rgb_vermelho_escuro = CRGB(200, 0, 0);
const CRGB rgb_azul = CRGB(0, 100, 100);
const CRGB rgb_amarelo = CRGB(100, 100, 0);
const CRGB rgb_apagado = CRGB(0, 0, 0);

class Leds {

  public:
  Leds();
  void setup();
  void acende_todos_os_leds(CRGB cor);
  void inicial_cheese();
  void acende_possiveis_jogadas();
  void acende_casas_ilegais();
  void animacao_vez_do_jogador();
  void animacao_inicio();
  void animacao_vencedor();
  void animacao_empate();

  CRGB leds0[NUM_LEDS];
  CRGB leds1[NUM_LEDS];
  CRGB leds2[NUM_LEDS];
  CRGB leds3[NUM_LEDS];
  CRGB leds4[NUM_LEDS];

  private:
  bool verificarPosicaoEncontradaBranco(int x, int y);
  bool verificarPosicaoEncontradaMarrom(int x, int y);

};



#endif // LEDS_H_INCLUDED