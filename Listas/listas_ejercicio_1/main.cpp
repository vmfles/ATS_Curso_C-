/*
Vídeo nº 109 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Listas
Escribir un programa en C++ que permita realizar las siguientes funciones:
a) Insertar un elemento entero en la lista (se insertarán en el orden en que se ingresan)
b) Mostrar todos los elementos de la lista
c) Calcular el menor y el mentor de todos los elementos en la lista

El parámetro formal para la lista se va a pasar en las funciones por referencia.
*/

#include <iostream>
#include <stdlib.h>

struct Nodo_t
{
    int dato;
    Nodo_t *p_sig;
};

using namespace std;

//void menu(Lista_t *p_lista);
void insertar_elemento_lista(Nodo_t *&lista, int n);
void mostrar_lista(Nodo_t *lista);
void calcular_mayor_y_menor(Nodo_t *lista);

int main()
{    
    Nodo_t *lista = nullptr;
    int dato = 0;
    char rpt = 0;

    do
    {
        cout << "Indique un numero: "; cin >> dato;
        insertar_elemento_lista(lista,dato);
        cout << endl << "Desea ingresar otro elemento (s/n)?: "; cin >> rpt;
    } while ((rpt == 's') || (rpt == 'S'));

    mostrar_lista(lista);
    calcular_mayor_y_menor(lista);

    return 0;
}

//Agrega elemeno al final de la lista
void insertar_elemento_lista(Nodo_t *&lista, int n)
{
    Nodo_t *nuevo_nodo = new Nodo_t();
    Nodo_t *aux = lista;
    nuevo_nodo->dato = n;
    nuevo_nodo->p_sig = nullptr;

    if(lista != nullptr)
    {
        //Hay elementos en la lista
        while (aux->p_sig != nullptr)
        {
            aux = aux->p_sig;
        }
        aux->p_sig = nuevo_nodo;
    }
    else
    {
        //Lista vacía
        lista = nuevo_nodo;
    }

    cout << endl << "Elmento " << n << " insertado en la lista" << endl;
}

//Mostramos todos los elementos de la lista
void mostrar_lista(Nodo_t *lista)
{
    cout << endl << "ELEMENTOS DE LA LISTA: ";
    while(lista != nullptr)
    {
        cout << lista->dato;
        lista = lista->p_sig;
        cout << " -> ";
    }

    cout << "NULL" << endl;
}

//Escribe el mayor y el menor de la lista
void calcular_mayor_y_menor(Nodo_t *lista)
{
    int mayor = 0, menor = 0;

    if(lista != nullptr)
    {
        menor = mayor = lista->dato;
    }
    else
    {
        cout << endl << "LISTA VACIA";
        return;
    }

    while(lista != nullptr)
    {
        if(lista->dato < menor)
            menor = lista->dato;

        if(lista->dato > mayor)
            mayor = lista->dato;

        lista = lista->p_sig;
    }

    cout << endl << "Menor: " << menor << endl;
    cout << endl << "Mayor: " << mayor << endl;
}
















