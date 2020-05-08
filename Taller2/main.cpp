#include <iostream>
#include <fstream>
#include <cstdlib>
#include<stdlib.h>
#include<time.h>


using namespace std;

/**
 * Función que muestra los participantes del grupo
 */
void participante();

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {

    std::ofstream archivoSalida("resultados.csv");
    archivoSalida << "rut;nem;rank;mat;leng;ciencia;historia"<< std::endl;
    int rut = 14916641;
    srand((unsigned int)time(NULL));
    while(rut<=19932391)
    {
        rut++;

        int nem = 475+rand()%(751-475);
        int ranking = 475+rand()%(751-475);
        int mat = 475+rand()%(751-475);
        int leng = 475+rand()%(751-475);
        int ciencia = 475+rand()%(751-475);
        int historia = 475+rand()%(751-475);

        archivoSalida << rut << ";" << nem << ";" << ranking << ";" << mat << ";" << leng << ";" << ciencia << ";" << historia << std::endl;

    }
    archivoSalida.close();
    participante();
    return EXIT_SUCCESS;
}

void participante() {
    std::cout << std::endl << "=== Tarea ===" << std::endl;
    std::cout << std::endl << "Gonzalo Salinas Campos" << std::endl; // Reemplazar por su nombre
}
