#include "cine.h"
#include <iostream>
using namespace std;
Cine::Cine()
{
    this->indice=0;
};

void Cine::mostrarCartelera()
{
    cout<<"--CARTELERA-- \n";
    /*cout<<"1 - [14:30] El Rey León (117) * ESTRENO * \n";
    cout<<"2 - [16:00] Spiderman: Lejos de Casa (130) * ESTRENO * \n";
    cout<<"3 - [18:20] Annabelle 3: Vuelve a Casa (106) \n";
    cout<<"4 - [16:15] Avengers: End Game (188) \n";
    cout<<"5 - [11:30] Toy Story 4 (100) \n";
    */

    peliculas[0]=Pelicula(1, "[14:30]", "El Rey León", 117, 1);
    peliculas[1]=Pelicula(2, "[16:00]", "Spiderman: Lejos de Casa", 130, 1);
    peliculas[2]=Pelicula(2, "[18:20]", "Annabelle 3: Vuelve a Casa", 106, 0);
    peliculas[3]=Pelicula(3, "[16:15]", "Avengers: End Game", 188, 0);
    peliculas[4]=Pelicula(4, "[11:30]", "Toy Story 4", 100, 0);

    cout<<peliculas[0].mostrar()<<endl;
    cout<<peliculas[1].mostrar()<<endl;
    cout<<peliculas[2].mostrar()<<endl;
    cout<<peliculas[3].mostrar()<<endl;
    cout<<peliculas[4].mostrar()<<endl;
}

void Cine::mostrarSala()
{
    int id;
    cout<<"INGRESE EL ID DE LA PELICULA: ";
    cin>>id;

    salas.sala(id);
}

Cine::~Cine()
{

};
