#include <Arduino.h>
#include "bt.h"

void taskImprimeMatriz(){
/*
Função que envia a matriz do jogo via bluetooth
*/

  bt.print("<"); // inicio do array
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      manda = String(tabuleiro_cheese[i][j]);
      bt.print(manda);
      bt.print(",");
    }
    bt.print(" ");
  }
  bt.println(">"); // fim do array
  delay(25);
}