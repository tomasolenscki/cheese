#ifndef LCD_H_INCLUDED
#define LCD_H_INCLUDED

void lcd_menu_principal();

String modo_de_jogo;
String opcoes_menu_mdj[] = {{"cheese"},{"cheese_5"},{"cheese_10"},{"cheese_15"}};
int contador_vertical_mdj = 0;

String selecao_fim;
String opcoes_menu_fim[] = {{"Jogar de novo"},{"Menu principal"}};
int contador_vertical_fim = 0;

void lcd_menu_UP();
void lcd_menu_DOWN();
void lcd_menu_RIGHT_mdj();
void lcd_menu_RIGHT_fim();
void lcd_acaba_tempo();
void lcd_vitoria_derrota();

#endif // LCD_H_INCLUDED
