#include <Arduino.h>
#include "lcd.h"
#include "maquina_estados.h"

void lcd_menu_principal(){
    Serial.println("LCD: Menu principal");
}

void lcd_menu_UP(){
    if (estado == IDLE){
        if (contador_vertical_mdj == 0)
            contador_vertical_mdj = 3;
        else 
            contador_vertical_mdj -= 1;
        Serial.print("LCD: modo pre-selecionado: ");
        Serial.println(opcoes_menu_mdj[contador_vertical_mdj]);
    }
    if (estado == FIM){
        if (contador_vertical_fim == 0)
            contador_vertical_fim = 1;
        else 
            contador_vertical_fim -= 1;
        Serial.print("LCD: pre-selecao no fim: ");
        Serial.println(opcoes_menu_fim[contador_vertical_fim]);
    }
}

void lcd_menu_DOWN(){
    if (estado == IDLE){
        if (contador_vertical_mdj == 3)
            contador_vertical_mdj = 0;
        else 
            contador_vertical_mdj += 1;
        Serial.print("LCD: modo pre-selecionado: ");
        Serial.println(opcoes_menu_mdj[contador_vertical_mdj]);
    }
    if (estado == FIM){
        if (contador_vertical_fim == 1)
            contador_vertical_fim = 0;
        else 
            contador_vertical_fim += 1;
        Serial.print("LCD: pre-selecao no fim: ");
        Serial.println(opcoes_menu_fim[contador_vertical_fim]);
    }
}

void lcd_menu_RIGHT_mdj(){
    modo_de_jogo = opcoes_menu_mdj[contador_vertical_mdj];
    Serial.print("LCD: Opc escolhida: ");
    Serial.println(opcoes_menu_mdj[contador_vertical_mdj]);
    Serial.println("LCD: Posicione as pecas");
}

void lcd_menu_RIGHT_fim(){
    if (contador_vertical_fim == 0) {
        Serial.print("LCD: Opc escolhida: ");
        Serial.println(opcoes_menu_mdj[contador_vertical_mdj]);
        Serial.println("LCD: Posicione as pecas");
    }
    else {
        Serial.println("LCD: Menu Principal");
    }
    
}