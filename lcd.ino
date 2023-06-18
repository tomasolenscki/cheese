#include <Arduino.h>
#include "lcd.h"
#include "maquina_estados.h"
#include "timer.h"
#include "jogo.h"

void lcd_menu_principal(){
  lcd.clear();
  lcd.print("Menu principal");
}

void lcd_menu_UP(){
    if (estado == IDLE){
        if (contador_vertical_mdj == 0)
            contador_vertical_mdj = 3;
        else 
            contador_vertical_mdj -= 1;
        delay(200);
        lcd.clear();
        lcd.print(String("Modo: ") + String(opcoes_menu_mdj[contador_vertical_mdj]));
    }
    if (estado == FIM){
        if (contador_vertical_fim == 0)
            contador_vertical_fim = 1;
        else 
            contador_vertical_fim -= 1;
        delay(200);
        lcd.clear();
        lcd.print(String("Escolha: ") + String(opcoes_menu_fim[contador_vertical_fim]));
    }
}

void lcd_menu_DOWN(){
    if (estado == IDLE){
        if (contador_vertical_mdj == 3)
            contador_vertical_mdj = 0;
        else 
            contador_vertical_mdj += 1;
        delay(300);
        lcd.clear();
        lcd.print(String("Modo: ") + String(opcoes_menu_mdj[contador_vertical_mdj]));
    }
    if (estado == FIM){
        if (contador_vertical_fim == 1)
            contador_vertical_fim = 0;
        else 
            contador_vertical_fim += 1;
        delay(300);
        lcd.clear();
        lcd.print(String("Escolha: ") + String(opcoes_menu_fim[contador_vertical_fim]));
    }
}

void lcd_menu_RIGHT_mdj(){
    modo_de_jogo = opcoes_menu_mdj[contador_vertical_mdj];
    switch (contador_vertical_mdj){
      case (0):
        game = CHEESE;
        timer = false;
      break;
      case (1):
        game = CHEESE_5;
        timer = true;
      break;
      case (2):
        game = CHEESE_10;
        timer = false;
      break;
      case (3):
        game = CHEESE_15;
        timer = true;
      break;
    }
    lcd.clear();
    lcd.print(String("Modo: ") + String(opcoes_menu_mdj[contador_vertical_mdj]));
    lcd.setCursor(0,1);
    lcd.print("Posicione:");
}

void lcd_menu_RIGHT_fim(){
    if (contador_vertical_fim == 0) {
        lcd.clear();
        lcd.print(String("Escolhido: ") + String(opcoes_menu_mdj[contador_vertical_mdj]));
        lcd.setCursor(0,1);
        lcd.print("Posicione as pecas:");

    }
    else {
        lcd.clear();
        lcd.print("Menu Principal:");
    }
    
}

void lcd_vitoria_derrota(){
  lcd.clear();
  lcd.print("Fim de jogo");
  lcd.setCursor(0,1);
  if (jogador_vencedor == MARROM)
    lcd.print("MARROM VENCEU");
  else 
    lcd.print("BRANCO VENCEU");
}

void lcd_acaba_tempo(){
  lcd.clear();
  lcd.print("Acabou o tempo");
  lcd.setCursor(0,1);
  if (jogador_vencedor == MARROM)
    lcd.print("MARROM VENCEU");
  else 
    lcd.print("BRANCO VENCEU");
}

void lcd_empate(){
  lcd.clear();
  lcd.print("Empate?");

}

String padZero(int valor) {
  if (valor < 10) {
    return "0" + String(valor);
  } else {
    return String(valor);
  }
}