/*
Vídeo nº 98 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Pilas - Ejercicio 1

Hacer un programa para agregar números enteros a una pila, hasta que el usuario
lo decida, después mostrar todos los números introducidos en la pila.
*/


#include <iostream>
#include <stdlib.h>

using namespace std;


typedef struct nodo
{
    int dato;
    nodo *p_sig;
} Nodo_t;

void agregar_nodo_pila(Nodo_t *&pp, int dato);
void sacar_nodo_pila(Nodo_t *&pp, int &dato);

int main()
{
    Nodo_t *pp = nullptr;
    int dato = 0;
    char rpt = 0;

    cout << "Introduzca elementos en la pila" << endl;

    do
    {
        cout << "\nIntroduzca un numero: "; cin >> dato;
        agregar_nodo_pila(pp,dato);

        cout << "\nDesea agregar otro elemento a la PILA? (s/n):"; cin >> rpt;
    } while(rpt == 'S' || rpt == 's');

    cout << "\n\nVamos a sacar todos los elementos de la PILA:" << endl;
    while (pp != nullptr)
    {
        sacar_nodo_pila(pp,dato);
        if(pp != nullptr)
        {
            cout << dato << ", ";
        }
        else
        {
            cout << dato << ".";
        }
    }

    return 0;
}

void agregar_nodo_pila(Nodo_t *&pp, int dato)
{
    Nodo_t *aux = new Nodo_t();
    aux->dato = dato;
    aux->p_sig = pp;
    pp = aux;

    cout << "\t Elemento " << dato << " agregado a la PILA correctamente.";
}

void sacar_nodo_pila(Nodo_t *&pp, int &dato)
{
    Nodo_t *aux = pp;
    dato = aux->dato;
    pp = aux->p_sig;
    delete aux;
}
