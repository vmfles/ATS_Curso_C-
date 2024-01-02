/*
Vídeo nº 79 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Recursividad - Calcular el factorial de un número de forma recursiva:
*/

#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n == 1)
    {
        n = 1;
    }
    else
    {
        n = n*factorial(n-1);
    }
    return n;
}

int main()
{
    int n = 0;

    cout << "Introduzca un numero: ";
    cin >> n;
    cout << "\nEl factorial de " << n << " es: " << factorial(n) << endl;
    return 0;
}
