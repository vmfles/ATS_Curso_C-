/*
Vídeo nº 81 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Recursividad - Elevación de un número con recursividad.

Escriba una función recursiva que calcule un número elevado a una potencia entera mayor o igual que cero: x^y

potencia(x,y) = x si y = 1
                x*potencia(x,y-1) si y > 1
*/

#include <iostream>

using namespace std;

int potencia(int x, int y)
{
    int pot = 1;

    if(y == 1)
    {
        pot = x;
    }
    else if (y > 1)
    {
        pot = x*potencia(x,y-1);
    }

    return pot;
}

int main()
{
    int base = 0, exponente = 0;

    //Pedir datos al usuario
    cout << "Introduzca la base: "; cin >> base;

    do {
        cout << "\nIntroduzca el exponente (mayor o igual que 0): "; cin >> exponente;
    }
    while (exponente < 0);

    //Calculamos la potencia y la mostramos
    cout << "\nLa potencia de " << base << " elevado a " << exponente << " es: " << potencia(base,exponente) << endl;

    return 0;
}
