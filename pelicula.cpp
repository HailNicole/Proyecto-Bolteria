#include "pelicula.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 0)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
};

const string &Pelicula::getTitulo() const
{
    return titulo;
};

float Pelicula::getDuracion() const
{
    return duracion;
};

bool Pelicula::getEstreno() const
{
    return estreno;
};

const string &Pelicula::getHora() const
{
    return hora;
};

int Pelicula::getId() const
{
    return id;
};

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
};

string Pelicula::mostrar()
{
    return to_string(this->id) + " - " + this->hora + " " + this->titulo + " ("  + to_string_with_precision(this->duracion) + ") " + " " + estrenostr() ;
};

Pelicula::~Pelicula()
{

};
