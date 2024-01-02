/*
Vídeo nº 91 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Punteros - Matrices dinámicas

Ejercicio: Rellenar una matrix de NxM y mostrar su contenido.

**puntero_matriz -> *puntero_fila -> [int] [int] [int]
                    *puntero_fila -> [int] [int] [int]
                    *puntero_fila -> [int] [int] [int]

NOTA: Recuerda que debes utilizar punteros

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

//Prototipos de funciones
void pedir_dimension_matriz();
void pedir_datos_matriz(int **p_matriz, int n_filas, int n_columnas);
void mostrar_datos_matriz(int **p_matriz, int n_filas, int n_columnas);

static int n_filas = 0, n_columnas = 0;
static int **p_matriz = nullptr;

int main()
{    
    pedir_dimension_matriz();
    pedir_datos_matriz(p_matriz,n_filas,n_columnas);
    mostrar_datos_matriz(p_matriz,n_filas,n_columnas);

    //LIBERAMOS LA MEMORIA ASIGNADA DE FORMA DINAMICA
    for(int i = 0; i < n_filas; i++)
        delete[] p_matriz[i]; //Liberamos la memoria para las columnas

    delete[] p_matriz; //Liberamos la memoria para las filas

    return 0;
}

void pedir_dimension_matriz()
{
    cout << "Introduzca el numero de filas: "; cin >> n_filas;
    cout << "Introduzca el numero de columnas: "; cin >> n_columnas;

    p_matriz = new int*[n_filas]; //Reservando memoria para las filas

    for(int i = 0; i < n_filas; i++)
        p_matriz[i] = new int[n_columnas]; //Reservando memoria para las columnas

}

void pedir_datos_matriz(int **p_matriz, int n_filas, int n_columnas)
{
    for(int i = 0; i < n_filas; i++)
    {
        for(int j = 0; j < n_columnas; j++)
        {
            //cout << "Introduzca un numero [" << i << "][" << j << "]: "; cin >> p_matriz[i][j];
            cout << "Introduzca un numero [" << i << "][" << j << "]: "; cin >> *(*(p_matriz+i)+j);
        }
    }
}

void mostrar_datos_matriz(int **p_matriz, int n_filas, int n_columnas)
{
    cout << "\n\nImprimiendo la matriz:\n";

    for(int i = 0; i < n_filas; i++)
    {
        for(int j = 0; j < n_columnas; j++)
        {
            //cout << "Introduzca un numero [" << i << "][" << j << "]: "; cin >> p_matriz[i][j];
            //cout << "Dato [" << i << "][" << j << "]: " << *(*(p_matriz+i)+j) << " ";
            cout << *(*(p_matriz+i)+j) << " ";
        }

        cout << endl;
    }
}
