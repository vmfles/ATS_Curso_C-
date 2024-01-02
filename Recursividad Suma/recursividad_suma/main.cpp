/*
Vídeo nº 79 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Recursividad - Sumar n números enteros de forma recursiva:
*/

#include <iostream>

using namespace std;

int suma(int n)
{
    if (n == 1)
    {
        n = 1;
    }
    else
    {
        n = n+suma(n-1);
    }
    return n;
}

int main()
{
    int n = 0;

    cout << "Introduzca un numero: ";
    cin >> n;
    cout << "\nLa suma total de 1 hasta " << n << " es: " << suma(n) << endl;
    return 0;
}
