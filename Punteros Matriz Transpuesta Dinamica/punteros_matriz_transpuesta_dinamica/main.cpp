/*
Vídeo nº 92 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Punteros - Obtener la matriz transpuesta de una matriz dinámica NxM

Ejercicio: Realice un programa que obtenga la matriz transpuesta de una matriz dinámica.

**puntero_matriz -> *puntero_fila -> [int] [int] [int]
                    *puntero_fila -> [int] [int] [int]
                    *puntero_fila -> [int] [int] [int]

NOTA: Recuerda que debes utilizar punteros

*/

#include <iostream>
#include <stdlib.h>

//Prototipos de funciones
void pedir_datos_matriz(int *p_n_filas, int *p_n_columnas);
void obtener_matriz_transpuesta(int **p_matriz, int n_filas, int n_columnas);
void mostrar_datos_matriz(int **p_matriz, int n_filas, int n_columnas);

using namespace std;

static int **p_matriz = nullptr, **p_matriz_transp = nullptr;

int main()
{
    int i = 0, n_filas = 0, n_columnas = 0;

    pedir_datos_matriz(&n_filas, &n_columnas);
    cout << "\n\nLa matriz original es:" << endl;
    mostrar_datos_matriz(p_matriz,n_filas,n_columnas);

    cout << "\n\nLa matriz transpuesta es:" << endl;
    obtener_matriz_transpuesta(p_matriz,n_filas,n_columnas);
    mostrar_datos_matriz(p_matriz_transp,n_filas,n_columnas);

    for(i = 0; i < n_filas; i++)
        delete[] p_matriz[i]; //Liberamos la memoria de las columnas de la matriz

    delete[] p_matriz; //Liberamos la memoria de las filas de la matriz

    for(i = 0; i < n_filas; i++)
        delete[] p_matriz_transp[i]; //Liberamos la memoria de las columnas de la matriz transpuesta

    delete[] p_matriz_transp; //Liberamos la memoria de las filas de la matriz transpuesta

    return 0;
}

void pedir_datos_matriz(int *p_n_filas, int *p_n_columnas)
{
    cout << "Indique el numero de filas de las matrices: "; cin >> *p_n_filas;
    cout << "\nIndique el numero de columnas de las matrices: "; cin >> *p_n_columnas;

    p_matriz = new int*[*p_n_filas];
    for(int i = 0; i < *p_n_filas; i++)
        p_matriz[i] = new int[*p_n_columnas];

    cout << "\n\nIntroduzca los datos de la matriz" << endl;

    for(int i = 0; i < *p_n_filas; i++)
    {
        for(int j = 0; j < *p_n_columnas; j++)
        {
            cout << "[" << i << "][" << j << "]: ";
            cin >> *(*(p_matriz+i)+j);
        }
    }
}

void obtener_matriz_transpuesta(int **p_matriz, int n_filas, int n_columnas)
{
    p_matriz_transp = new int*[n_filas];

    for(int i = 0; i < n_filas; i++)
    {
        p_matriz_transp[i] = new int[n_columnas];
        for(int j = 0; j < n_columnas; j++)
        {
            p_matriz_transp[i][j] = p_matriz[j][i];
        }
    }
}

void mostrar_datos_matriz(int **p_matriz, int n_filas, int n_columnas)
{
    for(int i = 0; i < n_filas; i++)
    {
        for(int j = 0; j < n_columnas; j++)
        {
            cout << *(*(p_matriz+i)+j) << " ";
        }

        cout << endl;
    }
}
