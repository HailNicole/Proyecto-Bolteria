#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cine.h"
#include "sala.h"
using namespace std;


int main(){

    cout << "\n- - M I  C I N E - - " << endl;
    Cine c1;
    int opcion(0);

    do{

        cout << "\n+ + MENÚ PRINCIPAL + +" << endl;
        cout << "1. Mostrar cartelera" << endl;
        cout << "2. Mostrar sala" << endl;
        cout << "3. Comprar boletos" << endl;
        cout << "4. Salir" << endl;

        cout << "Ingrese su opcion: ";
        cin >> opcion;

        if (cin.fail()==true){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "\nIngresa un número!" << endl;
            system("pause");
            continue;
         }

        switch(opcion){
           case 1:
                c1.mostrarCartelera();
               break;

           case 2:
                c1.mostrarSala();
               break;

           case 3:

               break;

           case 4:
               cout << "\nAdios!" << endl;
               break;

           default:
               cout << "\nOpción inválida!" << endl;
        }
    }while(opcion != '4');

    return 0;
}
