#ifndef HALL_H_INCLUDED
#define HALL_H_INCLUDED

int HallSensor[5][5] = {{33, 32, 31, 30, 34},
                        {29, 38, 37, 36, 35},
                        {43, 42, 41, 39, 40}, 
                        {48, 47, 46, 45, 44},
                        {53, 51, 52, 50, 49}};

int sensores[5][5];

void le_sensores();
void inicializa_pinos();

#endif // HALL_H_INCLUDED
                                    