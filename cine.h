#ifndef CINE_H
#define CINE_H
#include "pelicula.h"
#include "sala.h"
class Cine
{
private:
    float const PRECIO_BOLETO=3.15;
    Pelicula peliculas[5];
    Sala *salas[5];
    int indice;
    float total;
public:
    Cine();
    void mostrarCartelera();
    void mostrarSala();
    void comprarBoletos();
    bool validar_asiento_fila(char fila);
    ~Cine();
};

#endif // CINE_H
