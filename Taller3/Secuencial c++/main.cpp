#include <iostream>
#include<fstream>
#include <cctype>
#include <sstream>
#include <cmath>

using namespace std;

void integrantes()
{
    cout <<"\nIntegrantes:\n\nGonzalo Salinas\nCamila Carrasco\nIgnacio Valdes\n" << endl;
}

void resultados(long double snem,long double srank,long double smat,long double cont,int moda1[1][2],int moda2[1][2],int moda3[1][2],long double sdesv1,long double sdesv2,long double sdesv3,int mediana1,int mediana2,int mediana3)
{
    cout <<"=== Nem ===" << endl;
    cout <<"Promedio: " << snem/cont << endl;
    cout <<"Desviacion estandar: " << sdesv1/cont << endl;
    cout <<"Moda: " << moda1[0][0] << endl;
    cout <<"Mediana: " << mediana1 << endl;
    cout <<"=== Ranking ===" << endl;
    cout <<"Promedio: " << srank/cont << endl;
    cout <<"Desviacion estandar: " << sdesv2/cont << endl;
    cout <<"Moda: " << moda2[0][0] << endl;
    cout <<"Mediana: " << mediana2 << endl;
    cout <<"=== Matematica ===" << endl;
    cout <<"Promedio: " << smat/cont << endl;
    cout <<"Desviacion estandar: " << sdesv3/cont << endl;
    cout <<"Moda: " << moda3[0][0] << endl;
    cout <<"Mediana: " << mediana3 << endl;
}

void resultadoscontinuacion(long double sleng,long double scien,long double shist,long double cont,int moda4[1][2],int moda5[1][2],int moda6[1][2],long double sdesv4,long double sdesv5,long double sdesv6,int mediana4,int mediana5,int mediana6)
{
    cout <<"=== Lenguaje ===" << endl;
    cout <<"Promedio: " << sleng/cont << endl;
    cout <<"Desviacion estandar: " << sdesv4/cont << endl;
    cout <<"Moda: " << moda4[0][0] << endl;
    cout <<"Mediana: " << mediana4 << endl;
    cout <<"=== Ciencias ===" << endl;
    cout <<"Promedio: " << scien/cont << endl;
    cout <<"Desviacion estandar: " << sdesv5/cont << endl;
    cout <<"Moda: " << moda5[0][0] << endl;
    cout <<"Mediana: " << mediana5 << endl;
    cout <<"=== Historia ===" << endl;
    cout <<"Promedio: " << shist/cont << endl;
    cout <<"Desviacion estandar: " << sdesv6/cont << endl;
    cout <<"Moda: " << moda6[0][0] << endl;
    cout <<"Mediana: " << mediana6 << endl;
}

void revisararreglo2d(int arreglo[276][2])
{
    cout <<"Arreglo: \n"<< endl;
    for(int i=0;i<276;i++)
    {
        cout <<"[" << arreglo[i][0] << "]" << "[" << arreglo[i][1] << "]" << endl;
    }
}

int main() /// CREAR ARCHIVO "puntajes.csv" con script en carpeta "tarea en clase rut psu", luego, colocarlo en el directorio de esta tarea.
{

    cout << "Leyendo archivo de resultados...\n\n" << endl;
    ifstream lectura;
    lectura.open("puntajes.csv",ios::in);
    string linea;
    string dato;
    int primeralineatexto = 0;


    long double sumanem = 0; ///Suma simple de cada tipo de puntaje por separado
    long double sumarank = 0;
    long double sumamat = 0;
    long double sumaleng = 0;
    long double sumacien = 0;
    long double sumahist = 0;

    int arreglomodanem [276][2]; ///Arreglo de cada dato UNICO, y sus repeticiones, necesario para calcular la moda
    int arreglomodarank [276][2];
    int arreglomodamat [276][2];
    int arreglomodaleng [276][2];
    int arreglomodacien [276][2];
    int arreglomodahist [276][2];

    for(int i=0;i<276;i++)///Relleno inicial de los arreglos... rutina...
    {
        arreglomodanem [i][0] = 475+i;
        arreglomodarank [i][0] = 475+i;
        arreglomodamat [i][0] = 475+i;
        arreglomodaleng [i][0] = 475+i;
        arreglomodacien [i][0] = 475+i;
        arreglomodahist [i][0] = 475+i;

        arreglomodanem [i][1] = 0;
        arreglomodarank [i][1] = 0;
        arreglomodamat [i][1] = 0;
        arreglomodaleng [i][1] = 0;
        arreglomodacien [i][1] = 0;
        arreglomodahist [i][1] = 0;
    }

    long double contador = 0;

    while (getline(lectura,linea))
    {
        contador = contador+1;
        std::stringstream registro(linea);
        string dato;
        for (int columna = 0; getline(registro, dato, ';'); ++columna)
        {
            if (isdigit(dato[0]))
            {
                if (columna == 1)/// si corresponde a puntaje nem
                {
                    sumanem=sumanem+stof(dato);
                    arreglomodanem[stoi(dato)-475][1]++;
                }
                if (columna == 2)/// si corresponde a puntaje ranking
                {
                    sumarank=sumarank+stof(dato);
                    arreglomodarank[stoi(dato)-475][1]++;
                }
                if (columna == 3)/// si corresponde a puntaje mat
                {
                    sumamat=sumamat+stof(dato);
                    arreglomodamat[stoi(dato)-475][1]++;
                }
                if (columna == 4)/// si corresponde a puntaje lenguaje
                {
                    sumaleng=sumaleng+stof(dato);
                    arreglomodaleng[stoi(dato)-475][1]++;
                }
                if (columna == 5)/// si corresponde a puntaje ciencia
                {
                    sumacien=sumacien+stof(dato);
                    arreglomodacien[stoi(dato)-475][1]++;
                }
                if (columna == 6)/// si corresponde a puntaje historia
                {
                    sumahist=sumahist+stof(dato);
                    arreglomodahist[stoi(dato)-475][1]++;
                }
            }
            else
            {
                primeralineatexto = 1;
            }
        }
    }

    if (primeralineatexto == 1)///Si existe una linea con texto, pasa de ella (se ignora dentro del while anterior) y resta la linea al contador ya que no corresponde a un dato (esto se hace aqui)
    {
        contador = contador-1;
    }
    int m1[1][2];///Aqui se guarda la moda de cada tipo de puntaje
    int m2[1][2];
    int m3[1][2];
    int m4[1][2];
    int m5[1][2];
    int m6[1][2];
    for (int i=0;i<276;i++)///Se selecciona la moda de los arreglos
    {
        if (arreglomodanem[i][1] > m1[0][1])
        {
            m1[0][0] = arreglomodanem [i][0];
            m1[0][1] = arreglomodanem [i][1];
        }
        if (arreglomodarank[i][1] > m2[0][1])
        {
            m2[0][0] = arreglomodarank [i][0];
            m2[0][1] = arreglomodarank [i][1];
        }
        if (arreglomodamat[i][1] > m3[0][1])
        {
            m3[0][0] = arreglomodamat [i][0];
            m3[0][1] = arreglomodamat [i][1];
        }
        if (arreglomodaleng[i][1] > m4[0][1])
        {
            m4[0][0] = arreglomodaleng [i][0];
            m4[0][1] = arreglomodaleng [i][1];
        }
        if (arreglomodacien[i][1] > m5[0][1])
        {
            m5[0][0] = arreglomodacien [i][0];
            m5[0][1] = arreglomodacien [i][1];
        }
        if (arreglomodahist[i][1] > m6[0][1])
        {
            m6[0][0] = arreglomodahist [i][0];
            m6[0][1] = arreglomodahist [i][1];
        }
    }

    long double sumanemdesv = 0; ///Suma del valor absoluto del dato menos el promediod e los datos (x - x prom.) por tipo de puntaje, necesario apra calcular la desviacion estandar
    long double sumarankdesv = 0;
    long double sumamatdesv = 0;
    long double sumalengdesv = 0;
    long double sumaciendesv = 0;
    long double sumahistdesv = 0;

    int mediananem;
    int medianarank;
    int medianamat;
    int medianaleng;
    int medianacien;
    int medianahist;

    long double contador2 = 0;

    lectura.close();
    ifstream lectura2;
    lectura2.open("puntajes.csv",ios::in);
    while (getline(lectura2,linea))
    {
        contador2 = contador2+1.0;
        std::stringstream registro(linea);
        string dato;
        for (int columna = 0; getline(registro, dato, ';'); ++columna)
        {
            if (isdigit(dato[0]))
            {
                if (columna == 1)
                {
                    sumanemdesv=sumanemdesv+abs(stof(dato)-(sumanem/contador));
                    if ((long int)contador%2==0)
                    {
                        if (contador/2.0 == contador2-1)
                        {
                            mediananem = stoi(dato);
                        }
                    }
                    else
                    {
                        if ((contador+1)/2 == contador2-1)
                        {
                            mediananem = stoi(dato);
                        }
                    }
                }
                if (columna == 2)
                {
                    sumarankdesv=sumarankdesv+abs(stof(dato)-(sumarank/contador));
                    if ((long int)contador%2==0)
                    {
                        if (contador/2 == contador2-1)
                        {
                            medianarank = stoi(dato);
                        }
                    }
                    else
                    {
                        if ((contador-1)/2 == contador2-1)
                        {
                            medianarank = stoi(dato);
                        }
                    }
                }
                if (columna == 3)
                {
                    sumamatdesv=sumamatdesv+abs(stof(dato)-(sumamat/contador));
                    if ((long int)contador%2==0)
                    {
                        if (contador/2 == contador2-1)
                        {
                            medianamat = stoi(dato);
                        }
                    }
                    else
                    {
                        if ((contador-1)/2 == contador2-1)
                        {
                            medianamat = stoi(dato);
                        }
                    }
                }
                if (columna == 4)
                {
                    sumalengdesv=sumalengdesv+abs(stof(dato)-(sumaleng/contador));
                    if ((long int)contador%2==0)
                    {
                        if (contador/2 == contador2-1)
                        {
                            medianaleng = stoi(dato);
                        }
                    }
                    else
                    {
                        if ((contador-1)/2 == contador2-1)
                        {
                            medianaleng = stoi(dato);
                        }
                    }
                }
                if (columna == 5)
                {
                    sumaciendesv=sumaciendesv+abs(stof(dato)-(sumacien/contador));
                    if ((long int)contador%2==0)
                    {
                        if (contador/2 == contador2-1)
                        {
                            medianacien = stoi(dato);
                        }
                    }
                    else
                    {
                        if ((contador-1)/2 == contador2-1)
                        {
                            medianacien = stoi(dato);
                        }
                    }
                }
                if (columna == 6)
                {
                    sumahistdesv=sumahistdesv+abs(stof(dato)-(sumahist/contador));
                    if ((long int)contador%2==0)
                    {
                        if (contador/2 == contador2-1)
                        {
                            medianahist = stoi(dato);
                        }
                    }
                    else
                    {
                        if ((contador-1)/2 == contador2-1)
                        {
                            medianahist = stoi(dato);
                        }
                    }
                }
            }
        }
    }

    resultados(sumanem,sumarank,sumamat,contador,m1,m2,m3,sumanemdesv,sumarankdesv,sumamatdesv,mediananem,medianarank,medianamat);
    resultadoscontinuacion(sumaleng,sumacien,sumahist,contador,m4,m5,m6,sumalengdesv,sumaciendesv,sumahistdesv,medianaleng,medianacien,medianahist);
    integrantes();
//    revisararreglo2d(arreglomodanem);
//    revisararreglo2d(arreglomodarank);
//    revisararreglo2d(arreglomodamat);
//    revisararreglo2d(arreglomodaleng);
//    revisararreglo2d(arreglomodacien);
//    revisararreglo2d(arreglomodahist);
    lectura2.close();

    return EXIT_SUCCESS;
}
