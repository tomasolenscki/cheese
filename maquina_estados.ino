#include <Arduino.h>
#include "maquina_estados.h"
#include "hall.h"
#include "leds.h"
#include "lcd.h"
#include "timer.h"

int obterAcao(int estado, int codigoEvento) {
  return acao_matrizTransicaoEstados[estado][codigoEvento];
}

int obterProximoEstado(int estado, int codigoEvento) {
  return proximo_estado_matrizTransicaoEstados[estado][codigoEvento];
}

void taskMaqEstados() {
  if (eventoInterno != NENHUM_EVENTO) {
      codigoEvento = eventoInterno;
  }
  if (codigoEvento != NENHUM_EVENTO)
  {
      codigoAcao = obterAcao(estado, codigoEvento);
      estado = obterProximoEstado(estado, codigoEvento);
      eventoInterno = executarAcao(codigoAcao);
      Serial.print("Estado: ");
      Serial.print(estado);
      Serial.print(" Evento: ");
      Serial.print(codigoEvento);
      Serial.print(" Acao: ");
      Serial.println(codigoAcao);
  }
}

void taskObterEvento() {

    if (botao.Botao() == 1 && (estado == IDLE)) {
        codigoEvento = RIGHT_ESCOLHE_MODO;
    }

    else if (botao.Botao() == 1 && (estado == EMPATE)) {
      codigoEvento = RIGHT_ESCOLHE_MODO;
    }

    else if (botao.Botao() == 2) {
        codigoEvento = UP;
    }
    else if (botao.Botao() == 3) {
        codigoEvento = DOWN; 
    }
    else if ((botao.Botao() == 4 && ((estado == MODOS_DE_JOGO) || (estado == TURNO) || (estado == JOGADA) || (estado == VERIFICACAO) || (estado == ILEGAL) ))) {
        codigoEvento = LEFT; 
    }
    else if ((estado == MODOS_DE_JOGO) && peca_pronta()) {
        codigoEvento = POSICIONAMENTO_DAS_PECAS; 
    }
    else if ((botao.Botao() == 5) || ((estado == PRONTO) && (!timer))) {
        codigoEvento = BOTAO_TIMER; 
    }

    else if ((estado == TURNO) && peca_levantou()) {
        codigoEvento = LEVANTA_PECA; 
    }

    else if ((estado == JOGADA) && peca_abaixou()) {
        codigoEvento = ESCOLHE_CASA; 
    }

    else if ((estado == ILEGAL) && trata_peca_ilegal() ) {
        codigoEvento = LEVANTA_PECA_ILEGAL; 
    }

    else if ((estado != FIM ) && acaba_tempo()) {
        codigoEvento = ACABA_TEMPO; 
    }
    else if ((estadoSalvo == TURNO) && (botao.Botao() == 4 )) {
        codigoEvento = LEFT_T; 
    }
    else if ((estadoSalvo == JOGADA) && (botao.Botao() == 4 )) {
        codigoEvento = LEFT_J; 
    }
    else if ((estadoSalvo == ILEGAL) && (botao.Botao() == 4 )) {
        codigoEvento = LEFT_I; 
    }
    else if ((estadoSalvo == VERIFICACAO) && (botao.Botao() == 4 )) {
        codigoEvento = LEFT_V; 
    }
    else if ((botao.Botao() == 1 && contador_vertical_fim == 0 && estado == FIM)) {
        codigoEvento = RIGHT_JOGAR_NOVAMENTE; 
    }
    else if ((botao.Botao() == 1 && contador_vertical_fim == 1 && estado == FIM)) {
        codigoEvento = RIGHT_MENU_PRINCIPAL; 
    }
    else {
        codigoEvento = NENHUM_EVENTO;
    }
}


int executarAcao(int codigoAcao) {
    if (codigoAcao == NENHUMA_ACAO)
        return NENHUM_EVENTO;

    switch(codigoAcao)
    {
    case A01:
      Serial.println("A01");
      lcd_menu_UP();
      break;
    case A02:
      Serial.println("A02");
      lcd_menu_DOWN();
      break;
    case A03:
      Serial.println("A03");
      lcd_menu_RIGHT_mdj();
      reinicia_tabuleiro_cheese();
      inicial_cheese();
      break;
    case A04:
      Serial.println("A04");
      acende_todos_os_leds(rgb_apagado);
      lcd_menu_principal();
      break;
    case A05:
      lcd.clear();
      acende_todos_os_leds(rgb_apagado);
      animacao_inicio();
      acende_todos_os_leds(rgb_apagado);
      lcd.print("Boa partida");
      lcd.setCursor(0,1);
      jogador_da_vez == 1 ? lcd.print(String("comeca ") + String("marrom")) : lcd.print(String("comeca ") + String("branco"));
      if (timer) inicializa_tempos();
      Serial.println("A05");
      break;
    case A06:
      Serial.println("A06");
      lcd.clear();
      jogador_da_vez = (int) random(1,2);
      acha_ratos_marrons();
      acha_ratos_brancos();
      animacao_vez_do_jogador();
      estadoSalvo = estado;
      if (timer){
        comeco_intervalo = millis();
        contando_tempo = true;
      }
      break;
    case A07:
      Serial.println("A07");
      estadoSalvo = estado;
      acende_possiveis_jogadas();
      break;
    case A08:
      Serial.println("A08");
      estadoSalvo = estado;
      break;
    case A09:
      Serial.println("A09");
      estadoSalvo = estado;
      acende_todos_os_leds(rgb_apagado);
      delay(100);
      return verifica_jogada();
      break;
    case A10:
      Serial.println("A10");
      estadoSalvo = estado;
      trata_peca_ilegal();
      break;
    case A11:
      Serial.println("A11");
      estadoSalvo = estado;
      break;
    case A12:
      preenche_cor(jogador_vencedor);
      lcd_vitoria_derrota();
      animacao_vencedor();
      if (timer){
        contando_tempo = false;
        inicializa_tempos();
      } 
      lcd_menu_UP();
      Serial.println("A12");
      break;
    case A13:
      Serial.println("A13");
      estadoSalvo = estado;
      animacao_vez_do_jogador();
      break;
    case A14:
      Serial.println("A14");
      estadoSalvo = estado;
      animacao_vez_do_jogador();
      break;
    case A15:
      lcd_acaba_tempo();
      preenche_cor(jogador_vencedor);
      animacao_vencedor();
      inicializa_tempos();
      lcd_menu_UP();
      Serial.println("A15");
      break;
    case A16:
      contando_tempo = false;
      lcd_empate();
      Serial.println("A16");
      break;
    case A17:
      Serial.println("A17");
      preenche_cor(3);
      contador_vertical_fim = 0;
      lcd_menu_RIGHT_fim();
      reinicia_tabuleiro_cheese();
      lcd_menu_principal();
      break;
    case A18:
      Serial.println("A18");
      lcd.clear();
      if (timer) {
        contando_tempo = true;
        comeco_intervalo = millis(); 
      }
      break;
    case A19:
      Serial.println("A19");
      lcd_menu_RIGHT_fim();
      reinicia_tabuleiro_cheese();
      inicial_cheese();
      break;
    case A20:
      Serial.println("A20");
      contador_vertical_fim = 0;
      lcd_menu_RIGHT_fim();
      reinicia_tabuleiro_cheese();
      lcd_menu_principal();
      break;
    }

    return NENHUM_EVENTO;
}