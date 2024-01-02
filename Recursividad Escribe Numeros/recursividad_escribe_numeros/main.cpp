/*
Ejercicio propuesto en el vídeo nº 81 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Recursividad - escribeNumeros(int ini, int fin).

Escriba una función recursiva escribeNumeros(int ini, int fin) que devuelva en la salida estándar los números del ini al fin.
Escriba una versión que escriba los números en orden ascendente.

escribeNumeros(ini,fin) = cout << escribeNumeros(ini+1,fin)  si ini < fin
                x*potencia(x,y-1) si ini = fin
*/


#include <iostream>

using namespace std;

void escribeNumeros(int ini, int fin)
{
    cout << ini << endl;
    if(ini < fin)
    {

        escribeNumeros(ini+1,fin);
    }
}

int main()
{
    int ini = 0, fin = 0;

    cout << "Introduzca el primer numero: "; cin >> ini;
    cout << "\nIntroduzca el ultimo numero: "; cin >> fin;

    cout << "\nLa secuencia de numeros es la siguiente: " << endl;
    escribeNumeros(ini,fin);

    return 0;
}
