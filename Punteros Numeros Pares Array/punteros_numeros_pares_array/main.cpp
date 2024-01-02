/*
Vídeo nº 85 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Punteros - Números pares de un array con ponteros:
Rellenar un array de 10 números, posteriormente utilizando punteros indicar cuales son
números pares y su posición en memoria.
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
//    int num = 20, *dir_num = nullptr;

//    dir_num = &num;
//    //cout << "Numero: " << num << endl;
//    //cout << "Direccion de memoria: " << &num << endl;
//    cout << "Numero: " << *dir_num << endl;
//    cout << "Direccion de memoria: " << dir_num << endl;

//    int numero = 0, *dir_numero = nullptr;

//    cout << "Indique un numero: "; cin >> numero;

//    dir_numero = &numero;

//    if(*dir_numero % 2 == 0)
//    {
//        cout << "El numero" << numero << " es par" << endl;

//    }
//    else cout << "El numero" << numero << " es impar" << endl;
//    cout << "Posicion de memoria: " << dir_numero << endl;

//    #define N_MAX   5
//    int numeros[N_MAX] = {1,2,3,4,5}, *p_numeros = nullptr;

//    p_numeros = numeros;
//    for (int i = 0; i < N_MAX; i++)
//    {
//        cout << "Elemento del vector ["<<i<<"]: " << numeros[i] << endl;
////        cout << "Elemento del vector ["<<i<<"]: " << *(numeros+i) << endl;
////        cout << "Elemento del vector ["<<i<<"]: " << *p_numeros++ << endl;
////        cout << "Elemento del vector ["<<i<<"]: " << *(p_numeros+i) << endl;
////        cout << "Direccion memoria ["<<i<<"]: " << p_numeros++ << endl;
////        cout << "Direccion memoria ["<<i<<"]: " << p_numeros+i << endl;
////        cout << "Direccion memoria ["<<i<<"]: " << &numeros[i] << endl;
//    }

    #define N_MAX   10
    int numeros[N_MAX] = {0}, *p_numeros = nullptr;

    p_numeros = numeros;
    for (int i = 0; i < N_MAX; i++)
    {
        cout << "Introduzca el numero de la posicion ["<<i<<"]: "; cin >> *p_numeros++;
        cout << endl;
    }

//    for (int i = 0; i < N_MAX; i++)
//        cout << numeros[i] << endl;

    p_numeros = numeros;
    for (int i = 0; i < N_MAX; i++)
    {
        if(*p_numeros%2 == 0)
        {
            cout << "El numero " << *p_numeros << " es par" << endl;
            cout << "Posicion de memoria " << p_numeros << endl;
        }
        p_numeros++;
    }


    //getchar();
    return 0;
}
