#include <Arduino.h>
#include "lcd.h"
#include "maquina_estados.h"

void lcd_menu_principal(){
  lcd.clear();
  Serial.println("LCD: Menu principal");
  lcd.print("Menu principal");
}

void lcd_menu_UP(){
    if (estado == IDLE){
        if (contador_vertical_mdj == 0)
            contador_vertical_mdj = 3;
        else 
            contador_vertical_mdj -= 1;
        delay(300);
        Serial.print("LCD: modo pre-selecionado: ");
        Serial.println(opcoes_menu_mdj[contador_vertical_mdj]);
        lcd.clear();
        lcd.print(String("Modo: ") + String(opcoes_menu_mdj[contador_vertical_mdj]));
    }
    if (estado == FIM){
        if (contador_vertical_fim == 0)
            contador_vertical_fim = 1;
        else 
            contador_vertical_fim -= 1;
        delay(300);
        Serial.print("LCD: pre-selecao no fim: ");
        Serial.println(opcoes_menu_fim[contador_vertical_fim]);
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
        Serial.print("LCD: modo pre-selecionado: ");
        Serial.println(opcoes_menu_mdj[contador_vertical_mdj]);
        lcd.clear();
        lcd.print(String("Modo: ") + String(opcoes_menu_mdj[contador_vertical_mdj]));
    }
    if (estado == FIM){
        if (contador_vertical_fim == 1)
            contador_vertical_fim = 0;
        else 
            contador_vertical_fim += 1;
        delay(300);
        Serial.print("LCD: pre-selecao no fim: ");
        Serial.println(opcoes_menu_fim[contador_vertical_fim]);
        lcd.clear();
        lcd.print(String("Escolha: ") + String(opcoes_menu_fim[contador_vertical_fim]));
    }
}

void lcd_menu_RIGHT_mdj(){
    modo_de_jogo = opcoes_menu_mdj[contador_vertical_mdj];
    switch (contador_vertical_mdj){
      case (0):
        game = CHEESE;
      break;
      case (2):
        game = QUEENS;
      break;
    }
    Serial.print("LCD: Opc escolhida: ");
    Serial.println(opcoes_menu_mdj[contador_vertical_mdj]);
    Serial.println("LCD: Posicione as pecas");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(String("Modo: ") + String(opcoes_menu_mdj[contador_vertical_mdj]));
    lcd.setCursor(0,1);
    lcd.print("Posicione:");
}

void lcd_menu_RIGHT_fim(){
    if (contador_vertical_fim == 0) {
        Serial.print("LCD: Opc escolhida: ");
        Serial.println(opcoes_menu_mdj[contador_vertical_mdj]);
        Serial.println("LCD: Posicione as pecas");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(String("Escolhido: ") + String(opcoes_menu_mdj[contador_vertical_mdj]));
        lcd.setCursor(0,1);
        lcd.print("Posicione as pecas:");

    }
    else {
        Serial.println("LCD: Menu Principal");
        lcd.clear();
        lcd.print("Menu Principal:");
    }
    
}