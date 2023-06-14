#ifndef HALL_H_INCLUDED
#define HALL_H_INCLUDED

void le_sensores();
void inicializa_pinos();

int HallSensor[5][5] = {{33, 32, 31, 30, 29},
                        {38, 37, 36, 35, 34},
                        {43, 42, 41, 40, 39}, 
                        {48, 47, 46, 45, 44},
                        {53, 52, 51, 50, 49}};

int sensores[5][5];

#endif // HALL_H_INCLUDED
                                    