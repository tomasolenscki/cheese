#ifndef LCD_H_INCLUDED
#define LCD_H_INCLUDED

class LCD{

  public:
  LCD();
  void menu_principal();
  void menu_UP();
  void menu_DOWN();
  void menu_RIGHT_mdj();
  void menu_RIGHT_fim();
  void vitoria_derrota();
  void acaba_tempo();
  void empate();
  String padZero(int value);
  int contador_vertical_fim = 0;
  int contador_vertical_mdj = 0;

  private:
  String modo_de_jogo;
  String opcoes_menu_mdj[4] = {{"cheese"},{"cheese_5"},{"cheese_10"},{"cheese_15"}};
  String selecao_fim;
  String opcoes_menu_fim[2] = {{"Jogar de novo"},{"Menu principal"}};


};


#endif // LCD_H_INCLUDED
