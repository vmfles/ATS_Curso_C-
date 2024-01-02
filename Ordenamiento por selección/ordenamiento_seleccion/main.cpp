/*
 * Vídeo nº 52 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
En el ordenamiento por inserción requiere n^2 operaciones para ordenar una lista de n elementos.
Su funcionamiento es el siguiente:

Buscar el mínimo elemento de la lista.
Intercambiar con el primer elemento.
Buscar el mínimo del resto de la lista.
Intercambiar con el segundo.
Y así sucesivamente.
*/

#include <iostream>

using namespace std;

#define N_ELEMENTOS 5

void subordenacion_elemento_minimo(int *p, int pos)
{
    int i = 0, n_min = 0, pos_min = 0;

    n_min = p[pos];
    for(i = pos+1; i < N_ELEMENTOS; i++)
    {
        if(p[i]<n_min)
        {
            n_min = p[i];
            pos_min = i;
        }
    }

    if(pos_min > pos)
    {
        //Intercambio
        p[pos_min] = p[pos];
        p[pos] = n_min;
    }
}

int main()
{    
    int lista_numeros[N_ELEMENTOS] = {1,4,5,3,2};
    int i = 0;

    for(i = 0; i < N_ELEMENTOS-1; i++)
    {
        subordenacion_elemento_minimo(lista_numeros,i);
    }

    cout << "Orden ascendente: ";
    for(i = 0; i < N_ELEMENTOS; i++)
        cout<<lista_numeros[i]<<" ";

    cout << endl;

    return 0;
}
