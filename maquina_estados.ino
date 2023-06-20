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
    int botao_evento = botao.Botao();
    
    if (botao_evento == 1 && (estado == IDLE)) {
        codigoEvento = RIGHT_ESCOLHE_MODO;
    }

    else if (botao_evento == 1 && (estado == EMPATE)) {
      codigoEvento = RIGHT_ESCOLHE_MODO;
    }

    else if (botao_evento == 2) {
        codigoEvento = UP;
    }
    else if (botao_evento == 3) {
        codigoEvento = DOWN; 
    }
    else if ((botao_evento == 4 && ((estado == MODOS_DE_JOGO) || (estado == TURNO) || (estado == JOGADA) || (estado == VERIFICACAO) || (estado == ILEGAL) ))) {
        codigoEvento = LEFT; 
    }
    else if ((estado == MODOS_DE_JOGO) && jogo.peca_pronta()) {
        codigoEvento = POSICIONAMENTO_DAS_PECAS; 
    }
    else if ((botao_evento == 5) || ((estado == PRONTO) && (!timer.timer))) {
        codigoEvento = BOTAO_TIMER; 
    }

    else if ((estado == TURNO) && jogo.peca_levantou()) {
        codigoEvento = LEVANTA_PECA; 
    }

    else if ((estado == JOGADA) && jogo.peca_abaixou()) {
        codigoEvento = ESCOLHE_CASA; 
    }

    else if ((estado == ILEGAL) && jogo.trata_peca_ilegal() ) {
        codigoEvento = LEVANTA_PECA_ILEGAL; 
    }

    else if ((estado != FIM ) && timer.acaba_tempo()) {
        codigoEvento = ACABA_TEMPO; 
    }
    else if ((estadoSalvo == TURNO) && (botao_evento == 4 )) {
        codigoEvento = LEFT_T; 
    }
    else if ((estadoSalvo == JOGADA) && (botao_evento == 4 )) {
        codigoEvento = LEFT_J; 
    }
    else if ((estadoSalvo == ILEGAL) && (botao_evento == 4 )) {
        codigoEvento = LEFT_I; 
    }
    else if ((estadoSalvo == VERIFICACAO) && (botao_evento == 4 )) {
        codigoEvento = LEFT_V; 
    }
    else if ((botao_evento == 1 && tela.contador_vertical_fim == 0 && estado == FIM)) {
        codigoEvento = RIGHT_JOGAR_NOVAMENTE; 
    }
    else if ((botao_evento == 1 && tela.contador_vertical_fim == 1 && estado == FIM)) {
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
      tela.menu_UP();
      break;
    case A02:
      Serial.println("A02");
      tela.menu_DOWN();
      break;
    case A03:
      Serial.println("A03");
      tela.menu_RIGHT_mdj();
      jogo.reinicia_tabuleiro_cheese();
      leds.inicial_cheese();
      break;
    case A04:
      Serial.println("A04");
      leds.acende_todos_os_leds(rgb_apagado);
      tela.menu_principal();
      break;
    case A05:
      lcd.clear();
      leds.acende_todos_os_leds(rgb_apagado);
      leds.animacao_inicio();
      leds.acende_todos_os_leds(rgb_apagado);
      lcd.print("Boa partida");
      lcd.setCursor(0,1);
      jogo.jogador_da_vez == 1 ? lcd.print(String("comeca ") + String("marrom")) : lcd.print(String("comeca ") + String("branco"));
      if (timer.timer) timer.inicializa_tempos();
      Serial.println("A05");
      break;
    case A06:
      Serial.println("A06");
      lcd.clear();
      jogo.jogador_da_vez = (int) random(1,2);
      jogo.acha_ratos_marrons();
      jogo.acha_ratos_brancos();
      leds.animacao_vez_do_jogador();
      estadoSalvo = estado;
      if (timer.timer){
        timer.comeco_intervalo = millis();
        timer.contando_tempo = true;
      }
      break;
    case A07:
      Serial.println("A07");
      estadoSalvo = estado;
      leds.acende_possiveis_jogadas();
      break;
    case A08:
      Serial.println("A08");
      estadoSalvo = estado;
      break;
    case A09:
      Serial.println("A09");
      estadoSalvo = estado;
      leds.acende_todos_os_leds(rgb_apagado);
      delay(100);
      return jogo.verifica_jogada();
      break;
    case A10:
      Serial.println("A10");
      estadoSalvo = estado;
      jogo.trata_peca_ilegal();
      break;
    case A11:
      Serial.println("A11");
      estadoSalvo = estado;
      break;
    case A12:
      jogo.preenche_cor(jogo.jogador_vencedor);
      tela.vitoria_derrota();
      leds.animacao_vencedor();
      if (timer.timer){
        timer.contando_tempo = false;
        timer.inicializa_tempos();
      } 
      tela.menu_UP();
      Serial.println("A12");
      break;
    case A13:
      Serial.println("A13");
      estadoSalvo = estado;
      leds.animacao_vez_do_jogador();
      break;
    case A14:
      Serial.println("A14");
      estadoSalvo = estado;
      leds.animacao_vez_do_jogador();
      break;
    case A15:
      tela.acaba_tempo();
      jogo.preenche_cor(jogo.jogador_vencedor);
      leds.animacao_vencedor();
      timer.inicializa_tempos();
      tela.menu_UP();
      Serial.println("A15");
      break;
    case A16:
      timer.contando_tempo = false;
      tela.empate();
      Serial.println("A16");
      break;
    case A17:
      Serial.println("A17");
      jogo.preenche_cor(3);
      leds.animacao_empate();
      tela.contador_vertical_fim = 0;
      tela.menu_RIGHT_fim();
      jogo.reinicia_tabuleiro_cheese();
      tela.menu_principal();
      break;
    case A18:
      Serial.println("A18");
      lcd.clear();
      if (timer.timer) {
        timer.contando_tempo = true;
        timer.comeco_intervalo = millis(); 
      }
      break;
    case A19:
      Serial.println("A19");
      tela.menu_RIGHT_fim();
      jogo.reinicia_tabuleiro_cheese();
      leds.inicial_cheese();
      break;
    case A20:
      Serial.println("A20");
      tela.contador_vertical_fim = 0;
      tela.menu_RIGHT_fim();
      jogo.reinicia_tabuleiro_cheese();
      tela.menu_principal();
      break;
    }

    return NENHUM_EVENTO;
}