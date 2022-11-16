#ifndef SALA_H
#define SALA_H


class Sala
{
private:
    int numero;
    int const numfilas=5;
    int const numcolumnas=5;
    bool asientos[5][5];
    char filas[5]={'A', 'B', 'C', 'D', 'E'};
    int columnas[5];
    char salas[5][5];
public:
    Sala();
    Sala(int);
    void sala(int id);
    ~Sala();
};

#endif // SALA_H
