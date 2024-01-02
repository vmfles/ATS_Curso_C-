/*
 * Vídeo nº 53 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Búsqueda Secuencial:

Se utiliza cuando el vector no está ordenado o no puede ser ordenado previamente.
Consiste en buscar el elemento comparándolo secuencialmente (de ahí su nombre) con cada elemento del vector hasta encontrarlo,
o hasta que se llegue al final. La existencia se puede asegurar cuando el elemento es localizado, pero no podemos asegurar la
no existencia hasta no haber analizado todos los elementos del vector.
*/

#include <iostream>

#define N_ELEMENTOS 5

using namespace std;

int main()
{
    int lista_numeros[N_ELEMENTOS] = {1,4,5,3,2};
    int i = 0, dato = 3;
    bool bandera = false;

    while((!bandera) && (i < N_ELEMENTOS))
    {
        if(dato == lista_numeros[i])
            bandera = true;
        i++;
    }

    if(bandera)
         cout << "El numero ha sido encontrado en la lista en la posicion: "<<i<<endl;
    else cout << "El numero NO esta en la lista"<<endl;

    return 0;
}
