 #include <iostream>
 #include <fstream>

using namespace std;

bool abrirArchivoEntrada(ifstream &archivoEntrada, const string &nombreArchivo);
bool abrirArchivoSalida(ofstream &archivoSalida, const string &nombreArchivo);
int obtenerLongitudArchivo(ifstream &archivoEntrada);
void leerArchivo(ifstream &archivoEntrada, char *buffer, int longitud);
void encontrarBloquesHoras(char *horasCurso, int longitud, ofstream &archivoSalida, char *chunk);
bool menu ();

int main()
{
    ifstream inFile;
    ofstream outFile;
    
    bool estudiante = false;
    
    while(estudiante != true){
        int respuesta;
        cout << "Ingrese el numero correspondiente a la opcion a la que desea acceder.\n1. Crear un estudiante nuevo.\n2. Gestionar horario de estudiante anterior .\n3.Cerrar el programa.\n";
        cin >> respuesta;
        
         if(respuesta == 1){
            const string nombreArchivo;
            cout << "Estas creando un estudiante nuevo";
            cout << "Ingresa el nombre y apellido del estudiante sin espacios";
            cin>> nombreArchivo;
            bool abrirArchivoSalida(ofstream &archivoSalida, const string &nombreArchivo)
            
            int dosmenu;
            cout << "Desea gestionar el horario \n1.Si \n2.No";
            cin>> dosmenu;
            
            if (dosmenu == 1){
                menu ()
            }
            else if (dosmenu == 2){
                cout<< "Volviendo al menu de crear estudiante;
                estudiante = true;
            }
        
         }
        else if (respuesta == 2){
            
            cout << "Acontinuaciòn se listan los estudiantes disponibles";
            try{
                inFile.open(nombreArchivo);
                if(!inFile.is_open()) throw 1;
                menu() 
                
            } 
            catch(int err){
                cout<< "Error # "<<err<<" :"<<endl;
                if(err == 1) cout << "El archivo de entrada no pudo abrise.";
                if(err == 2) cout << "El archivo de salida no pudo abrise."
            }
            
         }
        else if (respuesta == 3){
            cout << "Fin del programa \n Adios.";
            estudiante = true;
        }
    }
    
}

bool menu() {
    bool exitMenu = false;

    while (!exitMenu) {
        int selectedOption = 0;

        cout << "Ingrese el numero correspondiente a la opcion.\n1. Ingresar materias.\n2. Gestionar horario.\n3. Volver al menu anterior\n";
        cin >> selectedOption;

        if (selectedOption == 1) {
            cout << "Ingresar materia.";
            
            abrirArchivoSalida(nombreArchivo, )
        }
        else if (selectedOption == 2) {
            cout << "Gestionar el horario.";
            cout << "Tienes" << creditos<<""
        }
        else if (selectedOption == 3) {
            cout << "De regreso al menu inicial";
            exitMenu = true;
        }
    }

    return exitMenu;
}
    
bool abrirArchivoEntrada(ifstream &archivoEntrada, const string &nombreArchivo) {
    archivoEntrada.open(nombreArchivo);
    if (!archivoEntrada.is_open()) {
        cout << "No se pudo abrir el archivo de entrada" << endl;
        return false;
    }
    return true;
}

bool abrirArchivoSalida(ofstream &archivoSalida, const string &nombreArchivo) {
    archivoSalida.open(nombreArchivo, fstream::out);
    if (!archivoSalida.is_open()) {
        cout << "No se pudo crear el archivo de salida" << endl;
        return false;
    }
    return true;
}

int obtenerLongitudArchivo(ifstream &archivoEntrada) {
    archivoEntrada.seekg(0, ios::end);
    int longitud = archivoEntrada.tellg();
    archivoEntrada.seekg(0, ios::beg);
    return longitud;
}

void leerArchivo(ifstream &archivoEntrada, char *buffer, int longitud) {
    archivoEntrada.read(buffer, longitud);
}

void encontrarBloquesHoras(char *horasCurso, int longitud, ofstream &archivoSalida, char *chunk) {
    int posAntes = 0;
    for (int i = 0; i < longitud; i++) {
        if (horasCurso[i] == ':') {
            posAntes = i + 1;
            break;
        }
    }
    int posAfter = posAntes+3;
    int k = 0;
    for (int j=posAntes; j<posAfter;j++){
        chunk[k] = horasCurso[j];
        k++;
    }
}
