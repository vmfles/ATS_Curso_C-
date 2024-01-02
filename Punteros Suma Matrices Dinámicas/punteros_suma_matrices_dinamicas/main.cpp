/*
Vídeo nº 92 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Punteros - Suma de matrices dinámicas

Ejercicio: Realice un programa que calcule la suma de dos matrices dinámicas

**puntero_matriz -> *puntero_fila -> [int] [int] [int]
                    *puntero_fila -> [int] [int] [int]
                    *puntero_fila -> [int] [int] [int]

NOTA: Recuerda que debes utilizar punteros

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

//Prototipos de funciones
void pedir_datos_matrices(int *p_n_filas, int *p_n_columnas);
void pedir_datos_matriz(int **p_matriz, int n_filas, int n_columnas);
void sumar_matrices(int **p_matriz1, int **p_matriz2, int n_filas, int n_columnas);
void mostrar_datos_matriz(int **p_matriz, int n_filas, int n_columnas);

static int **p_matriz1 = nullptr, **p_matriz2 = nullptr, **p_matriz_suma = nullptr;

int main()
{
    int i = 0, n_filas = 0, n_columnas = 0;

    pedir_datos_matrices(&n_filas, &n_columnas);

    cout << "\n\nDatos de la matriz 1:" << endl;
    mostrar_datos_matriz(p_matriz1,n_filas,n_columnas);

    cout << "\n\nDatos de la matriz 2:" << endl;
    mostrar_datos_matriz(p_matriz2,n_filas,n_columnas);

    cout << "\n\nLa matriz suma es:" << endl;
    sumar_matrices(p_matriz1,p_matriz2,n_filas,n_columnas);
    mostrar_datos_matriz(p_matriz_suma,n_filas,n_columnas);

    //LIBERAMOS TODA LA MEMORIA ASIGNADA DE FORMA DINÁMICA
    for(i = 0; i < n_filas; i++)
        delete[] p_matriz_suma[i]; //Liberamos la memoria de las columnas de la matriz suma

    delete[] p_matriz_suma; //Liberamos la memoria de las filas de la matriz suma

    for(i = 0; i < n_filas; i++)
        delete[] p_matriz2[i]; //Liberamos la memoria de las columnas de la matriz 2

    delete[] p_matriz2; //Liberamos la memoria de las filas de la matriz 2

    for(i = 0; i < n_filas; i++)
        delete[] p_matriz1[i]; //Liberamos la memoria de las columnas de la matriz 1

    delete[] p_matriz1; //Liberamos la memoria de las filas de la matriz 1

    return 0;
}

void pedir_datos_matrices(int *p_n_filas, int *p_n_columnas)
{
    cout << "Indique el numero de filas de las matrices: "; cin >> *p_n_filas;
    cout << "\nIndique el numero de columnas de las matrices: "; cin >> *p_n_columnas;

    p_matriz1 = new int*[*p_n_filas];
    for(int i = 0; i < *p_n_filas; i++)
        p_matriz1[i] = new int[*p_n_columnas];

    pedir_datos_matriz(p_matriz1,*p_n_filas,*p_n_columnas);

    p_matriz2 = new int*[*p_n_filas];
    for(int i = 0; i < *p_n_filas; i++)
        p_matriz2[i] = new int[*p_n_columnas];

    pedir_datos_matriz(p_matriz2,*p_n_filas,*p_n_columnas);

}

void pedir_datos_matriz(int **p_matriz, int n_filas, int n_columnas)
{
    cout << "\n\nIntroduzca los datos de la matriz" << endl;

    for(int i = 0; i < n_filas; i++)
    {
        for(int j = 0; j < n_columnas; j++)
        {
            cout << "[" << i << "][" << j << "]: ";
            cin >> *(*(p_matriz+i)+j);
        }
    }
}

void sumar_matrices(int **p_matriz1, int **p_matriz2, int n_filas, int n_columnas)
{
    p_matriz_suma = new int*[n_filas];

    for(int i = 0; i < n_filas; i++)
    {
        p_matriz_suma[i] = new int[n_columnas];
        for(int j = 0; j < n_columnas; j++)
        {
            *(*(p_matriz_suma+i)+j) = *(*(p_matriz1+i)+j) + *(*(p_matriz2+i)+j);
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


////Prototipos de funciones
//void pedir_datos_matrices(int **p_matriz1, int **p_matriz2, int *p_n_filas, int *p_n_columnas);
//void pedir_datos_matriz(int **p_matriz, int n_filas, int n_columnas);
//void sumar_matrices(int **p_matriz1, int **p_matriz2, int **p_matriz_suma, int n_filas, int n_columnas);
//void mostrar_datos_matriz(int **p_matriz, int n_filas, int n_columnas);

////static int **p_matriz1 = nullptr, **p_matriz2 = nullptr, **p_matriz_suma = nullptr;

//int main()
//{
//    int i = 0, n_filas = 0, n_columnas = 0;
//    int **p_matriz1 = nullptr, **p_matriz2 = nullptr, **p_matriz_suma = nullptr;

//    cout << "Indique el numero de filas de las matrices: "; cin >> n_filas;
//    cout << "\nIndique el numero de columnas de las matrices: "; cin >> n_columnas;

//    p_matriz1 = new int*[n_filas];
//    for(i = 0; i < n_filas; i++)
//        p_matriz1[i] = new int[n_columnas];

//    pedir_datos_matriz(p_matriz1,n_filas,n_columnas);

//    p_matriz2 = new int*[n_filas];
//    for(i = 0; i < n_filas; i++)
//        p_matriz2[i] = new int[n_columnas];

//    pedir_datos_matriz(p_matriz2,n_filas,n_columnas);

//    p_matriz_suma = new int*[n_filas];

//    for(i = 0; i < n_filas; i++)
//        p_matriz_suma[i] = new int[n_columnas];

//    cout << "\n\nDatos de la matriz 1:" << endl;
//    mostrar_datos_matriz(p_matriz1,n_filas,n_columnas);

//    cout << "\n\nDatos de la matriz 2:" << endl;
//    mostrar_datos_matriz(p_matriz2,n_filas,n_columnas);

//    cout << "\n\nLa matriz suma es:" << endl;
//    sumar_matrices(p_matriz1,p_matriz2,p_matriz_suma,n_filas,n_columnas);
//    mostrar_datos_matriz(p_matriz_suma,n_filas,n_columnas);

//    //LIBERAMOS TODA LA MEMORIA ASIGNADA DE FORMA DINÁMICA
//    for(i = 0; i < n_filas; i++)
//        delete[] p_matriz_suma[i]; //Liberamos la memoria de las columnas de la matriz suma

//    delete[] p_matriz_suma; //Liberamos la memoria de las filas de la matriz suma

//    for(i = 0; i < n_filas; i++)
//        delete[] p_matriz2[i]; //Liberamos la memoria de las columnas de la matriz 2

//    delete[] p_matriz2; //Liberamos la memoria de las filas de la matriz 2

//    for(i = 0; i < n_filas; i++)
//        delete[] p_matriz1[i]; //Liberamos la memoria de las columnas de la matriz 1

//    delete[] p_matriz1; //Liberamos la memoria de las filas de la matriz 1

//    return 0;
//}

//void pedir_datos_matrices(int **p_matriz1, int **p_matriz2, int *p_n_filas, int *p_n_columnas)
//{
//    cout << "Indique el numero de filas de las matrices: "; cin >> *p_n_filas;
//    cout << "\nIndique el numero de columnas de las matrices: "; cin >> *p_n_columnas;

//    p_matriz1 = new int*[*p_n_filas];
//    for(int i = 0; i < *p_n_filas; i++)
//        p_matriz1[i] = new int[*p_n_columnas];

//    pedir_datos_matriz(p_matriz1,*p_n_filas,*p_n_columnas);

//    p_matriz2 = new int*[*p_n_filas];
//    for(int i = 0; i < *p_n_filas; i++)
//        p_matriz2[i] = new int[*p_n_columnas];

//    pedir_datos_matriz(p_matriz2,*p_n_filas,*p_n_columnas);

//}

//void pedir_datos_matriz(int **p_matriz, int n_filas, int n_columnas)
//{
//    cout << "\n\nIntroduzca los datos de la matriz" << endl;

//    for(int i = 0; i < n_filas; i++)
//    {
//        for(int j = 0; j < n_columnas; j++)
//        {
//            cout << "[" << i << "][" << j << "]: ";
//            cin >> *(*(p_matriz+i)+j);
//        }
//    }
//}

//void sumar_matrices(int **p_matriz1, int **p_matriz2, int **p_matriz_suma, int n_filas, int n_columnas)
//{
//    for(int i = 0; i < n_filas; i++)
//    {
//        for(int j = 0; j < n_columnas; j++)
//        {
//            *(*(p_matriz_suma+i)+j) = *(*(p_matriz1+i)+j) + *(*(p_matriz2+i)+j);
//        }
//    }
//}

//void mostrar_datos_matriz(int **p_matriz, int n_filas, int n_columnas)
//{
//    for(int i = 0; i < n_filas; i++)
//    {
//        for(int j = 0; j < n_columnas; j++)
//        {
//            cout << *(*(p_matriz+i)+j) << " ";
//        }

//        cout << endl;
//    }
//}
