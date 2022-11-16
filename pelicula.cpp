#include "pelicula.h"
#include <iostream>
using namespace std;

string Pelicula::estrenostr()
{
    switch (estreno) {
    case 1:
        return "* ESTRENO *";
        break;
    case 0:
        return " ";
        break;
    default:
        return "";
        break;
    }
};

Pelicula::Pelicula()
{
    this->id=0;
    this->duracion=0;
    this->estreno=0;
    this->titulo="S/N";
    this->hora="";
};

Pelicula::Pelicula(int id, string hora, string titulo , float duracion, bool estreno)
{
    this->id=id;
    this->hora=hora;
    this->titulo=titulo;
    this->duracion=duracion;
    this->estreno=estreno;

}

string Pelicula::mostrar()
{
    return to_string(this->id) + " - " + this->hora + " " + this->titulo + " (" + to_string(this->duracion) + ") " + " " + to_string(this->estreno) + " \n";
}

Pelicula::~Pelicula()
{

};
