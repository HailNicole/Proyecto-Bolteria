#ifndef BOLETO_H
#define BOLETO_H
#include "pelicula.h"
#include "sala.h"
class Boleto
{
private:
    int sala;
    Pelicula _peliculas;
    Sala salas;
    char fila;
    int columna;
public:
    Boleto();
    Boleto(int, char, int, Pelicula);
    char getFila() const;
    int getColumna() const;
    void mostrar_boleto();
    ~Boleto();
};

#endif // BOLETO_H
