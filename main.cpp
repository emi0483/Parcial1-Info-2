#include <iostream>

using namespace std;

int main()
{
    bool turn = false;

    while(turn == false){

        int selection = 0;

        cout << "Ingrese el numero correspondiente a la opcion.\n1. Ingresar datos.\n2. Gestionar horario.\n3. Borrar datos.\n4. Cerrar el programa.\n";
        cin >> selection;

        if(selection == 1){
            cout << "Ingresar datos.";
        }

        else if(selection == 2){
            cout << "Gestionar.";
        }

        else if(selection == 3){
            cout << "Borrando...";
        }

        else if(selection == 4){
            cout << "Adios.";
            turn = true;
        }

        else{
            cout << "Ingreso un caracter que no corresponde a una opcion.";
        }
    }
}
