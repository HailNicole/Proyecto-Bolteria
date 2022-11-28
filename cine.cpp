#include "cine.h"
#include "pelicula.h"
#include "boleto.h"
#include <cstring>
#include <iostream>
using namespace std;
Cine::Cine()
{
    this->indice=0;
    this->total=0;

    peliculas[0]=Pelicula(1, "[14:30]", "El Rey Leon", 117, 1);
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
    int id, contador;
    int sw;

    do{
        cout<<"INGRESE EL ID DE LA PELICULA: ";
        //cin>>id;
        scanf("%s", numero);
        fflush(stdin);
        sw=validar_num(numero);
        if(sw==1){
            cout<<"ERROR!!"<<endl;
            contador=0;
            continue;
        }
        else{
            id = atof(numero);
            if(id<1 or id>5){
                cout<<"ID INGRESADO NO EXISTE"<<endl;
                contador=0;
                cin.clear();
                cin.ignore(1000,'\n');
                continue;
            }
            else{
                contador=1;
            }
        }

    }while(contador==0);

    cout<<this->peliculas[id-1].mostrar()<<endl;
    salas[id-1]->mostrar_sala();
};

void Cine::comprarBoletos()
{
    int id, bol, columna, cont, cont3;
    char fila;
    int sw;
    bool x, y;

    do{
        cout<<"INGRESE EL ID DE LA PELICULA: ";
        //cin>>id;
        scanf("%s", numero);
        fflush(stdin);
        sw=validar_num(numero);
        if(sw==1){
            cout<<"ERROR!!"<<endl;
            cont=0;
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }
        else{
            id = atof(numero);
            if(id<1 or id>5){
                cout<<"ID INGRESADO NO EXISTE"<<endl;
                cont=0;
                cin.clear();
                cin.ignore(1000,'\n');
                continue;
            }
            else{
                cont=1;
            }
        }

    }while(cont==0);


    if(salas[id-1]->contador_de_asientos()==0){
        cout<<"NO EXISTE DISPONIBILIDAD EN LA SALA PARA ESA FUNCION"<<endl;
    }
    else{

        do{
            cout<<"INGRESE EL NUMERO DE BOLETOS: ";
            //cin>>bol;
            scanf("%s", numero);
            fflush(stdin);
            sw=validar_num(numero);
            if(sw==1){
                cout<<"ERROR!!"<<endl;
                cont=0;
                cin.clear();
                cin.ignore(1000,'\n');
                continue;
            }
            else{
                bol = atof(numero);
                if(bol>salas[id-1]->contador_de_asientos()){
                    cout<<"LA CANTIDAD DE BOLETOS SOBREPASA LA CANTIDAD DE ASIENTOS DISPONIBLES"<<endl;
                    //cout<<"NO EXISTE DISPONIBILIDAD EN LA SALA"<<endl;
                    cont=0;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    continue;
                }
                if(bol<0){
                    cout<<"NUMERO DE BOLETOS INCORRECTO"<<endl;
                    cont=0;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    continue;
                }
                else{
                    cont=1;
                }
            }

        }while(cont==0);


        if(bol==0){
            cout<<"NO SE HA REALIZADO NINGUNA COMPRA"<<endl;
        }
        else{

            Boleto *boletos[bol];
            cout<<"SELECCIONE LOS ASIENTOS \n";
            salas[id-1]->mostrar_sala();

            int i=0;
            while(i<bol){
                cout<<"Boleto #"<<i+1<<endl;
                do{
                    cout<<"INGRESE EL ASIENTO: "<<endl;
                    do{
                        cin>>fila;
                        scanf("%s", numero);
                        //cin>>columna;

                        if(isdigit(fila)!=0){
                            cout<<"ERROR!!"<<endl;
                            cout<<"VUELVA A ELEGIR EL ASIENTO"<<endl;
                            cont3=0;
                            cin.clear();
                            cin.ignore(1000,'\n');
                            continue;
                        }

                        else{

                            fflush(stdin);
                            sw=validar_num(numero);
                            if(sw==1){
                                cout<<"ERROR!!"<<endl;
                                cout<<"VUELVA A ELEGIR EL ASIENTO"<<endl;
                                cont3=0;
                                cin.clear();
                                cin.ignore(1000,'\n');
                                continue;
                            }
                            else{
                                columna = atof(numero);
                                x=validar_asiento_columna(columna);
                                if(x==false){
                                    cout<<"ERROR!!"<<endl;
                                    cout<<"VUELVA A ELEGIR EL ASIENTO"<<endl;
                                    cont3=0;
                                    cin.clear();
                                    cin.ignore(1000,'\n');
                                    continue;
                                }
                            }

                        }

                        y=validar_asiento_fila(fila);
                        if(y==false){
                            cout<<"ERROR!!"<<endl;
                            cout<<"VUELVA A ELEGIR EL ASIENTO"<<endl;
                            cont3=0;
                            cin.clear();
                            cin.ignore(1000,'\n');
                            continue;
                        }
                        else{
                            cont3=1;
                        }
                    }while(cont3==0);

                }while(salas[id-1]->reservar_asientos(fila, columna)==false);

                boletos[i] = new Boleto(id,fila, columna, peliculas[id-1]);
                i++;
            }

            cout<<"\n\nRESUMEN DE LA COMPRA\n\n";
            for(int i=0; i<bol; i++){
                cout<<"Boleto #"<<i+1<<endl;
                boletos[i]->mostrar_boleto();
            }

            this->total=this->PRECIO_BOLETO*bol;
            cout<<"\nTOTAL: "<<total;
        }
    };

}

int Cine::validar_num(char numero[])
{
    int i=0, sw=0, j;
    j=strlen(numero);
        while(i<j and sw==0){
            if(isdigit(numero[i])!=0){
                i++;
            }
            else{
                sw=1;
                break;
            }
        }
        return sw;
};

bool Cine::validar_asiento_fila(char fila)
{
    char mayusfil;
    bool val;
    mayusfil=toupper(fila);

        if(mayusfil< 'A' || mayusfil > 'E'){
            val=false;
        }
        else{
          val=true;
        }
        return val;
};

 bool Cine::validar_asiento_columna(int columna)
{
    bool res;

        if(columna < 1 || columna > 5){
            res=false;
        }
        else{
            res= true;
        }

    return res;
};

Cine::~Cine()
{

};
