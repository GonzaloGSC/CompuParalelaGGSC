#include <iostream>
#include<fstream>
#include <cctype>
#include <sstream>

using namespace std;

void integrantes()
{
    cout <<"\nIntegrantes:\n\nGonzalo Salinas\nCamila Carrasco\nIgnacio Valdes\n" << endl;
}

int main()
{
    integrantes();
    cout << "Leyendo archivo de resultados...\n\n" << endl;
    ifstream lectura;
    lectura.open("resultados.csv",ios::in);

    std::ofstream archivoSalida("promedios.csv");
    archivoSalida << "rut;promedio"<< std::endl;

    string linea;
    string dato;
    string rut;
    float suma;
    while (getline(lectura,linea))
    {
        std::stringstream registro(linea);
        string dato;
        suma = 0;
        for (int columna = 0; getline(registro, dato, ';'); ++columna)
        {
            if (isdigit(dato[0]))
            {
                if (columna == 0)
                {
                    rut=dato;
                }
                else
                {
                    suma=suma+stof(dato);
                }
            }
        }
        if (suma)
        {
            archivoSalida << rut << ";" << suma/6 << std::endl;
        }
        ///if (isdigit(linea[0]))
        ///{
        ///    cout <<"rut"<<";"<<"Promedio"<< endl;
        ///}
        ///else
        ///{
        ///    cout <<rut<<";"<<suma/6<< endl;
        ///}

    }
    lectura.close();
    archivoSalida.close();
    return EXIT_SUCCESS;
}
