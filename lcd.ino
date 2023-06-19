#include <Arduino.h>
#include "lcd.h"
#include "maquina_estados.h"
#include "timer.h"
#include "jogo.h"

LCD::LCD(){}

void LCD::menu_principal(){
/*
Função que exibe a mensagem do menu principal no LCD
*/

  lcd.clear();
  lcd.print("Menu principal");
  lcd.setCursor(0, 1);
  lcd.print("UP ou DOWN");
}

void LCD::menu_UP(){
/*
Função que cicla entre as opções dos menus para cima
*/

  if (estado == IDLE){
      if (contador_vertical_mdj == 0)
          contador_vertical_mdj = 3;
      else 
          contador_vertical_mdj -= 1;
      delay(200);
      lcd.clear();
      lcd.print(String("Modo: "));
      lcd.setCursor(0, 1);
      lcd.print(String(opcoes_menu_mdj[contador_vertical_mdj]));
  }
  if (estado == FIM){
      if (contador_vertical_fim == 0)
          contador_vertical_fim = 1;
      else 
          contador_vertical_fim -= 1;
      delay(200);
      lcd.clear();
      lcd.print(String("Escolha:"));
      lcd.setCursor(0, 1);
      lcd.print(String(opcoes_menu_fim[contador_vertical_fim]));
  }
}

void LCD::menu_DOWN(){
/*
Função que cicla entre as opções dos menus para baixo
*/

  if (estado == IDLE){
      if (contador_vertical_mdj == 3)
          contador_vertical_mdj = 0;
      else 
          contador_vertical_mdj += 1;
      delay(200);
      lcd.clear();
      lcd.print(String("Modo: "));
      lcd.setCursor(0, 1);
      lcd.print(String(opcoes_menu_mdj[contador_vertical_mdj]));
  }
  if (estado == FIM){
      if (contador_vertical_fim == 1)
          contador_vertical_fim = 0;
      else 
          contador_vertical_fim += 1;
      delay(300);
      lcd.clear();
      lcd.clear();
      lcd.print(String("Escolha:"));
      lcd.setCursor(0, 1);
      lcd.print(String(opcoes_menu_fim[contador_vertical_fim]));
  }
}

void LCD::menu_RIGHT_mdj(){
/*
Função que mostra o modo de jogo selecionado e confirma a seleção
*/

  modo_de_jogo = opcoes_menu_mdj[contador_vertical_mdj];
  switch (contador_vertical_mdj){
    case (0):
      jogo.game = CHEESE;
      timer.timer = false;
    break;
    case (1):
      jogo.game = CHEESE_5;
      timer.timer = true;
    break;
    case (2):
      jogo.game = CHEESE_10;
      timer.timer = true;
    break;
    case (3):
      jogo.game = CHEESE_15;
      timer.timer = true;
    break;
  }
  lcd.clear();
  lcd.print(String("Modo: ") + String(opcoes_menu_mdj[contador_vertical_mdj]));
  lcd.setCursor(0,1);
  lcd.print("Posic. as pecas:");
}

void LCD::menu_RIGHT_fim(){
/*
Função que mostra a opção de fim selecionada e confirma a seleção
*/

  if (contador_vertical_fim == 0) {
      lcd.clear();
      lcd.print(String(opcoes_menu_mdj[contador_vertical_mdj]));
      lcd.setCursor(0,1);
      lcd.print("Posic. as pecas:");

  }
  else {
      lcd.clear();
      lcd.print("Menu Principal:");
  }
}

void LCD::vitoria_derrota(){
/*
Função que mostra mensagem de vitória
*/

  lcd.clear();
  lcd.print("Fim de jogo");
  lcd.setCursor(0,1);
  if (jogo.jogador_vencedor == MARROM)
    lcd.print("MARROM VENCEU");
  else 
    lcd.print("BRANCO VENCEU");
}

void LCD::acaba_tempo(){
/*
função que mostra o fim do tempo e qual rato venceu
*/

  lcd.clear();
  lcd.print("Acabou o tempo");
  lcd.setCursor(0,1);
  if (jogo.jogador_vencedor == MARROM)
    lcd.print("MARROM VENCEU");
  else 
    lcd.print("BRANCO VENCEU");
}

void LCD::empate(){
/*
Função para declarar empate
*/

  lcd.clear();
  lcd.print("Empate?");
  lcd.setCursor(0, 1);
  lcd.print("nao     sim    ");

}

String padZero(int valor) {
/*
Função para manter numeros com 2 digitos independentemente do valor
*/

  if (valor < 10) {
    return "0" + String(valor);
  } else {
    return String(valor);
  }
}