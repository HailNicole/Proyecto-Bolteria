#include "sala.h"
#include "pelicula.h"
#include <iostream>
#include <iomanip>
using namespace std;

Sala::Sala()
{
    this->crear_sala();
};

void Sala::crear_sala()
{
        for(int i=0; i<this->numfilas;i++){
            for(int j=0; j<this->numcolumnas; j++){
                asientos[i][j]=0;
            }
        }
};

void Sala::mostrar_sala()
{
    for (int i = 0; i <this->numfilas ; i++) {
        for(int j=0; j<this->numcolumnas; j++){
            if (asientos[i][j]) {
                asientos_str[i][j] = 'X';
            }
            else {
                asientos_str[i][j] = 'O';
            }
    }
    }
    cout<<"- - A S I E N T O S - -"<<endl;
    cout<<"  ";
    for(int b=0; b<this->numcolumnas;b++){
        columnas[b]=b+1;
        cout<<columnas[b]<<setw(4);
    }
    cout<<"\n";

    for(int i=0; i<this->numfilas;i++){
        cout<<filas[i]<<" ";
        for(int j=0; j<this->numcolumnas; j++){
            cout<<asientos_str[i][j]<<setw(4);
        }
        cout<<"\n";
    }
};

bool Sala::reservar_asientos(char fila, int columnas)
{
    char filastr;
    filastr=toupper(fila);
    int aux;
    switch (filastr){
        case 'A':
            aux=0;
        break;
        case 'B':
            aux=1;
            break;
        case 'C':
            aux=2;
            break;
        case 'D':
            aux=3;
            break;
        case 'E':
            aux=4;
            break;
    }

    if(asientos[aux][columnas-1]==0){
        asientos[aux][columnas-1]=1;
        asientos_str[aux][columnas-1]='X';
        return true;
    }
    else{
        cout<<"ASIENTO OCUPADO"<<endl;
        return false;
    };

};

int Sala::contador_de_asientos()
{
    int cont=0;
    for(int i=0; i<this->numfilas;i++){
        for(int j=0; j<this->numcolumnas; j++){
            if(asientos[i][j]==0){
               cont++;
            }
        }
    }
    return cont;
};

Sala::~Sala()
{

};

