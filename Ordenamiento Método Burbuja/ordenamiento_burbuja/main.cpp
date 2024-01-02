/*
El método burbuja es un método de ordenamiento donde se va revisando cada elemento de la lista
que se va a ordenar con el siguiente intercambiándose la posición si están en el orden equivocado.
Es necesario revisar varias veces toda la list hasta que no se necesiten más intercambios, lo
cual significa que la lista ya está ordenada.
*/
#include <iostream>
//#include <conio.h>

using namespace std;

int main()
{
    #define N_ELEMENTOS 5
    int lista_numeros[N_ELEMENTOS] = {4,1,2,3,5};
    int i = 0, j = 0, aux = 0;

    for(i = 0; i < N_ELEMENTOS; i++)
    {
        for(j = 0; j < (N_ELEMENTOS-1); j++)
        {
            if(lista_numeros[j]>lista_numeros[j+1])
            {
                aux = lista_numeros[j+1];
                lista_numeros[j+1] = lista_numeros[j];
                lista_numeros[j] = aux;
            }
        }
    }

    cout << "Orden ascendente: ";
    for(i = 0; i < N_ELEMENTOS; i++)
        cout<<lista_numeros[i]<<" ";

    cout << "\nOrden descendente: ";
    for(i = N_ELEMENTOS-1; i >=0 ; i--)
        cout<<lista_numeros[i]<<" ";

    cout << endl;

//    getch();
    return 0;
}
