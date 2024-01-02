/*
En el ordenamiento por inserción requiere n^2 operaciones para ordenar una lista de n elementos.
*/

#include <iostream>

using namespace std;

void subordenacion_numeros(int *p, int pos)
{
    int i = 0, aux = 0;

    for(i = pos; i > 0; i--)
    {
        if(p[i] < p[i-1])
        {
            aux = p[i];
            p[i] = p[i-1];
            p[i-1] = aux;
        }
    }
}

int main()
{
    #define N_ELEMENTOS 5
    int lista_numeros[N_ELEMENTOS] = {2,4,5,3,1};
    int i = 0;

    for(i = 0; i < N_ELEMENTOS; i++)
    {
        subordenacion_numeros(lista_numeros,i);
    }

    cout << "Orden ascendente: ";
    for(i = 0; i < N_ELEMENTOS; i++)
        cout<<lista_numeros[i]<<" ";

    cout << endl;

    return 0;
}
