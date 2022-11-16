#include "sala.h"
#include <iostream>
#include <iomanip>
using namespace std;
Sala::Sala()
{
    this->numero=0;
};

Sala::Sala(int numero)
{
    this->numero=numero;
};

void Sala::sala(int id)
{
    if(id==1){
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
                salas[i][j]='O';
                cout<<salas[i][j]<<setw(4);
            }
            cout<<"\n";
        }
    }

};

Sala::~Sala()
{

};
