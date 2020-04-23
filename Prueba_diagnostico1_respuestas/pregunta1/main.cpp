#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void resultado(string texto)
{
    char letra;
    int contador = 0;
    for (int i = 0;i<=texto.length();i++)
    {
        if (i == 0)
        {
            letra = texto[i];
        }
        if (texto[i] == letra)
        {
            contador++;
        }
        else
        {
            cout << letra << contador;
            letra = texto[i];
            contador = 1;
        }
    }
    cout << endl;
}

int main()
{
    while(true)
    {
        int error = 0;
        string input;
        cout << "Ingrese una cadena de texto('exit' para salir): ";
        cin >> input;
        ///cout << "Ingreso: " << input << endl;
        if (input == "exit")
        {
            break;
        }
        for (int i = 0;i<input.length();i++)
        {
            if (!isalpha(input[i]))
            {
                cout << "carac.: " << input[i] << " ERRONEO..." << endl;
                cout << "Error de ingreso. Intente otra vez..." << endl;
                error = 1;
                break;
            }
            ///else
            ///{
            ///    cout << "carac.: " << input[i] << " CORRECTO..." << endl;
            ///}
        }
        if (error == 0)
        {
            cout << endl;
            resultado(input);
        }

    }
    return 0;
}


