#include <iostream>
#include <fstream>

using namespace std;

bool abrirArchivoEntrada(ifstream &archivoEntrada, const string &nombreArchivo);
bool abrirArchivoSalida(ofstream &archivoSalida, const string &nombreArchivo);
int obtenerLongitudArchivo(ifstream &archivoEntrada);
void leerArchivo(ifstream &archivoEntrada, char *buffer, int longitud);
void encontrarBloquesHoras(char *horasCurso, int longitud, ofstream &archivoSalida, char *chunk);

int main() {
    // Abrir el archivo de entrada
    ifstream archivoEntrada;
    if (!abrirArchivoEntrada(archivoEntrada, "archivo.txt")) {
        return 1;
    }

    // Abrir el archivo de salida
    ofstream archivoSalida;
    if (!abrirArchivoSalida(archivoSalida, "salida.txt")) {
        return 1;
    }

    // Obtener la longitud del archivo de entrada
    int longitud = obtenerLongitudArchivo(archivoEntrada);

    // Leer el archivo de entrada en un arreglo de char
    char *horasCurso = new char[longitud];
    leerArchivo(archivoEntrada, horasCurso, longitud);

    //ENCONTRAR BLOQUES DE HORAS
    char *chunk = new char[2];
    encontrarBloquesHoras(horasCurso, longitud, archivoSalida, chunk);

    for (int p=0; p<3;p++){
        cout<<"pruebita "<<chunk[p]<<endl;
    }

    // Liberar la memoria asignada
    delete[] horasCurso;
    delete[] chunk;

    return 0;
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

