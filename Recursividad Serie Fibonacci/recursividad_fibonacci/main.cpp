/*
Ejercicio propuesto al final del vídeo nº 80 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Recursividad - Imprimir la serie de Fibonacci:
0,1,1,2,3,5,8,13,21,34...
*/

#include <iostream>
//#include <conio.h>

using namespace std;

void serie_fibonacci(int n1, int n2, int n, int n_elementos)
{
    int n_fib = 0;

    if(n < n_elementos)
    {
        n++;

        if(n == 1)
        {                       
            cout << n_fib << endl;
            serie_fibonacci(0,1,n,n_elementos);
        }
        else if(n == 2)
        {
            n_fib = 1;
            cout << n_fib << endl;
            serie_fibonacci(1,1,n,n_elementos);
        }
        else
        {
            n_fib = n1+ n2;
            cout << n_fib << endl;
            serie_fibonacci(n2,n_fib,n,n_elementos);
        }                 
    }
}

int main()
{
    int n_elementos = 0;

    cout << "Introduzca el numero de elementos: ";
    cin >> n_elementos;

    cout << "\nLa serie de Fibonacci de " << n_elementos << " elementos es: " << endl;
    serie_fibonacci(0,1,0,n_elementos);

//    getch();
    return 0;
}
