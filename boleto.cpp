#include "boleto.h"
#include <iostream>
#include <stdio.h>
using namespace std;

char Boleto::getFila() const
{
    return fila;
};

int Boleto::getColumna() const
{
    return columna;
};

Boleto::Boleto()
{
    this->sala=0;
    this->fila=0;
    this->columna=0;
};

Boleto::Boleto(int sala, char fila, int columna, Pelicula _peliculas)
{
    this->sala=sala;
    this->fila=toupper(fila);
    this->columna=columna;
    this->_peliculas=_peliculas;
};


void Boleto::mostrar_boleto()
{
    int espacios=_peliculas.getTitulo().length();
    int a=44;

    for(int i=0; i<=56; i++){
        printf("%c", 205);
    }
      cout<<"\n";

      printf("%c", 186); cout<<" ";
      cout<<" Sala: "<<this->sala;
      cout<<"\t\t\t\t\t\t"; printf("%c", 186); cout<<endl;

      printf("%c", 186); cout<<" ";
      cout<<" Hora: "<<this->_peliculas.getHora();
      cout<<"\t\t\t\t\t"; printf("%c", 186); cout<<endl;

      printf("%c", 186); cout<<" ";
      cout<<" Asiento: "<<this->fila<<this->columna;
      cout<<"\t\t\t\t\t\t"; printf("%c", 186); cout<<endl;

      printf("%c", 186); cout<<" ";
      cout<<" Pelicula: "<<this->_peliculas.getTitulo();

      for(int i=1; i<a-espacios; i++){
          cout<<"\u0020";
      }

      printf("%c", 186); cout<<endl;

      for(int i=0; i<=56; i++){
          printf("%c", 205);
      }
     cout<<"\n";

};

Boleto::~Boleto()
{

};
