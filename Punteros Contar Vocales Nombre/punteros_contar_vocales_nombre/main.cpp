/*
Vídeo nº 90 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Punteros - Contar vocales de un nombre con punteros

Ejercicio: Pedir al usuario su nombre y devolver el número de vocales que tiene.
NOTA: Recuerda que debes utilizar punteros

*/

#include <iostream>
#include <string.h>

using namespace std;

#define NAME_SIZE   30

void pedir_nombre(char *p_nombre);
int contar_vocales_nombre(char *p_nombre);

int main()
{    
    char nombre[NAME_SIZE];
    int n_vocales = 0;

    pedir_nombre(nombre);
    n_vocales = contar_vocales_nombre(nombre);

    cout << "\nEl nombre " << nombre << " tiene " << n_vocales << " vocales" << endl;

    return 0;
}

void pedir_nombre(char *p_nombre)
{
    cout << "Introduzca su nombre: ";
    cin.getline(p_nombre,NAME_SIZE,'\n');
    strupr(p_nombre);
}

int contar_vocales_nombre(char *p_nombre)
{
    int cont = 0;

    while(*p_nombre)
    {
        switch (*p_nombre)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                cont++;
            break;
        }

        p_nombre++;
    }

    return cont;
}
