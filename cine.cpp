#include "cine.h"
#include "pelicula.h"
#include <iostream>
using namespace std;
Cine::Cine()
{
    this->indice=0;
    this->total=0;

    peliculas[0]=Pelicula(1, "[14:30]", "El Rey León", 117, 1);
    peliculas[1]=Pelicula(2, "[16:00]", "Spiderman: Lejos de Casa", 130, 1);
    peliculas[2]=Pelicula(3, "[18:20]", "Annabelle 3: Vuelve a Casa", 106, 0);
    peliculas[3]=Pelicula(4, "[16:15]", "Avengers: End Game", 188, 0);
    peliculas[4]=Pelicula(5, "[11:30]", "Toy Story 4", 100, 0);

    for(int i = 0; i < 5; i++){
        salas[i] = new Sala;
    }

};

void Cine::mostrarCartelera()
{
    cout<<" - -CARTELERA- - \n";

    cout<<peliculas[0].mostrar()<<endl;
    cout<<peliculas[1].mostrar()<<endl;
    cout<<peliculas[2].mostrar()<<endl;
    cout<<peliculas[3].mostrar()<<endl;
    cout<<peliculas[4].mostrar()<<endl;
};

void Cine::mostrarSala()
{
    int id;
    cout<<"INGRESE EL ID DE LA PELICULA: ";
    cin>>id;

    salas[id-1]->mostrar_sala();
}

Cine::~Cine()
{

};
