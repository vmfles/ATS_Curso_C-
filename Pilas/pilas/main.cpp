/*
Vídeo nº 96 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Pilas - Insertar elementos a una pila

Vídeo nº 97 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Pilas - Quitar elementos a una pila
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo_t
{
    int dato;
    Nodo_t *p_sig;
};

void agregar_elemento_pila(Nodo_t *&pila, int dato);
void sacar_elemento_pila(Nodo_t *&pila, int &dato);
bool pila_vacia(Nodo_t *pila);

int main()
{
    Nodo_t *pila = nullptr;
    int dato;

    cout << "Inserte un numero: ";
    cin >> dato;

    agregar_elemento_pila(pila,dato);

    cout << "\nInserte otro numero: ";
    cin >> dato;

    agregar_elemento_pila(pila,dato);

    cout << "\nSacando los elementos de la pila: ";
    //while(pila != nullptr) //Mientras no sea el final de la pila
    while(!pila_vacia(pila)) //Mientras no sea el final de la pila
    {
        sacar_elemento_pila(pila,dato);
        //if(pila != nullptr)
        if(!pila_vacia(pila))
        {
            cout << dato << ", ";
        }
        else
        {
            cout << dato << ".";
        }
    }

    cout << endl;

    return 0;
}

void agregar_elemento_pila(Nodo_t *&pila, int dato)
{
    Nodo_t *nuevo_nodo = new Nodo_t;
    nuevo_nodo->dato = dato;
    nuevo_nodo->p_sig = pila;
    pila = nuevo_nodo;

    cout << "\nElemento " << dato << " agregado a PILA correctamente" << endl;
}

void sacar_elemento_pila(Nodo_t *& pila, int &dato)
{
    Nodo_t *aux = pila;
    dato = aux->dato;
    pila = aux->p_sig;
    delete aux;
}

bool pila_vacia(Nodo_t *pila)
{
    return ((pila == nullptr) ? true : false);
}
