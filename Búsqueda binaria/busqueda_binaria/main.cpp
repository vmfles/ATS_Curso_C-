/*
 * Vídeo nº 54 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Búsqueda Binaria en un arreglo:

Se utiliza cuando el vector en el que queremos determinar la existencia de un elemento está previamente ordenado.
Este algoritmo reduce el tiempo de búsqueda considerablemente, ya que disminuye exponencialmente el número de iteraciones necesarias.
*/


#include <iostream>

using namespace std;

#define N_ELEMENTOS 6

int main()
{
    int lista_numeros[N_ELEMENTOS] = {1,2,3,4,5,6};
    int i = 0, dato = 5;
    int i_ini = 0, i_fin = 0;
    bool bandera = false;

    i_ini = 0;
    i_fin = N_ELEMENTOS;

    while((!bandera) && (i_ini != i_fin))
    {
        i = (i_ini+i_fin)/2;
        if(lista_numeros[i] == dato)
        {
            bandera = true;
        }
        else if (lista_numeros[i] > dato)
        {
            i_fin = i;
        }
        else
        {
            i_ini = i;
        }
    }

    if(bandera)
         cout << "El numero ha sido encontrado en la lista en la posicion: "<<i+1<<endl;
    else cout << "El numero NO esta en la lista"<<endl;

    return 0;
}
