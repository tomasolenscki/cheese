#include <Arduino.h>
#include "maquina_estados.h"
#include "hall.h"
#include "leds.h"
#include "lcd.h"

int obterAcao(int estado, int codigoEvento) {
  return acao_matrizTransicaoEstados[estado][codigoEvento];
}

int obterProximoEstado(int estado, int codigoEvento) {
  return proximo_estado_matrizTransicaoEstados[estado][codigoEvento];
}

/*************************************
SOMENTE PARA TESTES
vvvvvvvvvvvvvvvvvvv
*************************************/
char buf[10];
char* ihm_obterTeclas()
{
    int read_count = 0;
    
    // confere inputs
    if (Serial.available() > 0) {
      // le bytes de entrada
      read_count = Serial.readBytesUntil('\n', buf, sizeof(buf)/sizeof(buf[0]) - 1);
    }

    buf[read_count] = '\0';
    if(read_count > 0) {
      //Serial.println(buf);
    }
    return buf;
}

char* teclas;

int decodificarRIGHT(){
    if (teclas[0] == 'R' && teclas[1] == '\0')
        return true;
    return false;
}
int decodificarUP(){
    if (teclas[0] == 'U' && teclas[1] == '\0')
        return true;
    return false;
}
int decodificarDOWN(){
    if (teclas[0] == 'D' && teclas[1] == '\0')
        return true;
    return false;
}
int decodificarLEFT(){
    if (teclas[0] == 'L' && teclas[1] == '\0')
        return true;
    return false;
}
int decodificarPOSICIONAMENTO_DAS_PECAS(){
    if (teclas[0] == 'P' && teclas[1] == 'D' && teclas[2] == 'P')
        return true;
    return false;
}
int decodificarBOTAO_TIMER(){
    if (teclas[0] == 'B' && teclas[1] == 'T')
        return true;
    return false;
}
int decodificarLEVANTA_PECA(){
    if (teclas[0] == 'L' && teclas[1] == 'P' && teclas[2] == '\0')
        return true;
    return false;
}
int decodificarDEVOLVE_PECA(){
    if (teclas[0] == 'D' && teclas[1] == 'P')
        return true;
    return false;
}
int decodificarESCOLHE_CASA(){
    if (teclas[0] == 'E' && teclas[1] == 'C')
        return true;
    return false;
}
int decodificarESCOLHA_ILEGAL(){
    if (teclas[0] == 'E' && teclas[1] == 'I')
        return true;
    return false;
}
int decodificarLEVANTA_PECA_ILEGAL(){
    if (teclas[0] == 'L' && teclas[1] == 'P' && teclas[2] == 'I')
        return true;
    return false;
}
int decodificarVITORIA_DERROTA(){
    if (teclas[0] == 'V' && teclas[1] == 'D')
        return true;
    return false;
}
int decodificarLEGAL_nULTIMO(){
    if (teclas[0] == 'L' && teclas[1] == 'n' && teclas[2] == 'U')
        return true;
    return false;
}
int decodificarLEGAL_ULTIMO(){
    if (teclas[0] == 'L' && teclas[1] == 'U')
        return true;
    return false;
}
int decodificarACABA_TEMPO(){
    if (teclas[0] == 'A' && teclas[1] == 'T')
        return true;
    return false;
}
int decodificarLEFT_T(){
    if (teclas[0] == 'L' && teclas[1] == 'T')
        return true;
    return false;
}
int decodificarLEFT_J(){
    if (teclas[0] == 'L' && teclas[1] == 'J')
        return true;
    return false;
}
int decodificarLEFT_I(){
    if (teclas[0] == 'L' && teclas[1] == 'I')
        return true;
    return false;
}
int decodificarLEFT_V(){
    if (teclas[0] == 'L' && teclas[1] == 'V')
        return true;
    return false;
}
// int decodificarRIGHT_JOGAR_NOVAMENTE(){
//     if (teclas[0] == 'R' && teclas[1] == 'J' && teclas[2] == 'N')
//         return true;
//     return false;
// }
// int decodificarRIGHT_MENU_PRINCIPAL(){
//     if (teclas[0] == 'R' && teclas[1] == 'M' && teclas[2] == 'P')
//         return true;
//     return false;
// }


int obterEvento() {
    teclas = ihm_obterTeclas();

    if ((decodificarRIGHT() && estado == IDLE) || (analogRead(0) < 60 && estado == IDLE)) {
        return RIGHT_ESCOLHE_MODO; 
    }
    else if (decodificarUP()) {
        return UP; 
    }
    else if (decodificarDOWN()) {
        return DOWN; 
    }
    else if (decodificarLEFT()) {
        return LEFT; 
    }
    else if (decodificarPOSICIONAMENTO_DAS_PECAS()) {
        return POSICIONAMENTO_DAS_PECAS; 
    }
    else if (decodificarBOTAO_TIMER()) {
        return BOTAO_TIMER; 
    }
    else if (decodificarLEVANTA_PECA()) {
        return LEVANTA_PECA; 
    }
    else if (decodificarDEVOLVE_PECA()) {
        return DEVOLVE_PECA; 
    }
    else if (decodificarESCOLHE_CASA()) {
        return ESCOLHE_CASA; 
    }
    else if (decodificarESCOLHA_ILEGAL()) {
        return ESCOLHA_ILEGAL; 
    }
    else if (decodificarLEVANTA_PECA_ILEGAL()) {
        return LEVANTA_PECA_ILEGAL; 
    }
    else if (decodificarVITORIA_DERROTA()) {
        return VITORIA_DERROTA; 
    }
    else if (decodificarLEGAL_nULTIMO()) {
        return LEGAL_nULTIMO; 
    }
    else if (decodificarLEGAL_ULTIMO()) {
        return LEGAL_ULTIMO; 
    }
    else if (decodificarACABA_TEMPO()) {
        return ACABA_TEMPO; 
    }
    else if (decodificarLEFT_T()) {
        return LEFT_T; 
    }
    else if (decodificarLEFT_J()) {
        return LEFT_J; 
    }
    else if (decodificarLEFT_I()) {
        return LEFT_I; 
    }
    else if (decodificarLEFT_V()) {
        return LEFT_V; 
    }
    else if ((decodificarRIGHT() && (contador_vertical_fim == 0) && estado == FIM) || (analogRead(0) < 60 && contador_vertical_fim == 0 && estado == FIM)) {
        return RIGHT_JOGAR_NOVAMENTE; 
    }
    else if ((decodificarRIGHT() && (contador_vertical_fim == 1) && estado == FIM) || (analogRead(0) < 60 && contador_vertical_fim == 1 && estado == FIM)) {
        return RIGHT_MENU_PRINCIPAL; 
    }
    else {
        return NENHUM_EVENTO;
    }
}

/*************************************
^^^^^^^^^^^^^^^^^^^
SOMENTE PARA TESTES
*************************************/

/*********************************
int obterEvento() {
    if (analogRead(0) < 60) {
        return RIGHT; 
    }
    else if (analogRead(0) < 200) {
        return UP; 
    }
    else if (analogRead(0) < 400) {
        return DOWN; 
    }
    else if (analogRead(0) < 600) {
        return LEFT; 
    }
    else if (peca_pronta(game)) {
        return POSICIONAMENTO_DAS_PECAS; 
    }
    else if (analogRead(0) < 800) {
        return BOTAO_TIMER; 
    }
    else if (peca_levantou(peca_levantada)) {
        return LEVANTA_PECA; 
    }
    else if (1 == 0) {
        return DEVOLVE_PECA; 
    }
    else if (1 == 0) {
        return ESCOLHE_CASA; 
    }
    else if (1 == 0) {
        return ESCOLHA_ILEGAL; 
    }
    else if (1 == 0) {
        return LEVANTA_PECA_ILEGAL; 
    }
    else if (1 == 0) {
        return VITORIA_DERROTA; 
    }
    else if (1 == 0) {
        return LEGAL_nULTIMO; 
    }
    else if (1 == 0) {
        return LEGAL_ULTIMO; 
    }
    else if (1 == 0) {
        return ACABA_TEMPO; 
    }
    else if (1 == 0) {
        return LEFT_T; 
    }
    else if (1 == 0) {
        return LEFT_J; 
    }
    else if (1 == 0) {
        return LEFT_I; 
    }
    else if (1 == 0) {
        return LEFT_V; 
    }
    else if (1 == 0) {
        return RIGHT_JOGAR_NOVAMENTE; 
    }
    else if (1 == 0) {
        return RIGHT_MENU_PRINCIPAL; 
    }
    else {
        return NENHUM_EVENTO;
    }
}
**********************************/



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
        break;
    case A04:
        Serial.println("A04");
        lcd_menu_principal();
        break;
    case A05:
        Serial.println("A05");
        break;
    case A06:
        Serial.println("A06");
        break;
    case A07:
        Serial.println("A07");
        break;
    case A08:
        Serial.println("A08");
        break;
    case A09:
        Serial.println("A09");
        break;
    case A10:
        Serial.println("A10");
        break;
    case A11:
        Serial.println("A11");
        break;
    case A12:
        Serial.println("A12");
        break;
    case A13:
        Serial.println("A13");
        break;
    case A14:
        Serial.println("A14");
        break;
    case A15:
        Serial.println("A15");
        break;
    case A16:
        Serial.println("A16");
        break;
    case A17:
        Serial.println("A17");
        break;
    case A18:
        Serial.println("A18");
        break;
    case A19:
        Serial.println("A19");
        lcd_menu_RIGHT_fim();
        break;
    case A20:
        Serial.println("A20");
        lcd_menu_RIGHT_fim();
        break;
    }

    return NENHUM_EVENTO;
}