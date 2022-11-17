#ifndef SALA_H
#define SALA_H

#include<iostream>
#include <string>
#include<iomanip>

using namespace std;

class Sala
{
private:
    int numero;
    int const numfilas=5;
    int const numcolumnas=5;
    bool asientos[5][5];
    char filas[5]={'A', 'B', 'C', 'D', 'E'};
    int columnas[5];
    char asientos_str[5][5];
    char asientostr();
public:
    Sala();
    void crear_sala();
    void mostrar_sala();
    bool reservar_asientos(char, int);
    ~Sala();
};

#endif // SALA_H
