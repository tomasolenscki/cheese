Button::Button(){}

int Button::getButton(){
/*
Função que separa o botão analógico nas diferentes faixas de valor
*/

  int button;
  int i, z, sum;

  sum = 0;
  for (i=0; i < 4; i++)
  {
     sum += analogRead(0);
  }
  z = sum / 4;

  if (z < 60 ) button = 1;                     
  else if (z < 200 ) button = 2;                
  else if (z < 400 ) button = 3;                
  else if (z < 600 ) button = 4;             
  else if (z < 800 ) button = 5; 
  else button = 0;

  return button;
}

int Button::Botao(){
/*
Debounce do botao
*/

  int button, button2, pressed_button;

  button = getButton();
  if (button != old_button)
  {
      delay(200);        // debounce
      button2 = getButton();

      if (button == button2)
      {
         old_button = button;
         pressed_button = button;
      }
  }

  return pressed_button;
}



