#ifndef PELICULA_H
#define PELICULA_H

#include <string>
using namespace std;

class Pelicula
{
private:
    int id;
    string titulo;
    float duracion;
    bool estreno;
    string hora;
    string estrenostr();
public:
    Pelicula();
    Pelicula(int, string, string, float, bool);
    string mostrar();
    ~Pelicula();
    const string &getTitulo() const;
    float getDuracion() const;
    bool getEstreno() const;
    const string &getHora() const;
    int getId() const;
};

#endif // PELICULA_H
