#ifndef CINE_H
#define CINE_H
#include "pelicula.h"
#include "sala.h"
class Cine
{
private:
    float const PRECIO_BOLETO=3.15;
    Pelicula peliculas[5];
    Sala salas;
    int indice;
public:
    Cine();
    void mostrarCartelera();
    void mostrarSala();
    ~Cine();
};

#endif // CINE_H
