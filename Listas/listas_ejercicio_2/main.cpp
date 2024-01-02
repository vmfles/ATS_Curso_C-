/*
Vídeo nº 109 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Listas
Escribir un programa en C++ que permita realizar las siguientes funciones:
a) Insertar un elemento tipo real en la lista (se insertarán en el orden en que se ingresan)
b) Mostrar todos los elementos de la lista
c) Calcular la suma y el promedio de todos los elementos en la lista

El parámetro formal para la lista se va a pasar en las funciones por referencia.
*/

#include <iostream>
#include <stdlib.h>

struct Nodo_t
{
    float dato;
    Nodo_t *p_sig;
};

using namespace std;

//void menu(Lista_t *p_lista);
void insertar_elemento_lista(Nodo_t *&lista, float n);
void mostrar_lista(Nodo_t *lista);
void calcular_suma_y_promedio(Nodo_t *lista);

int main()
{
    Nodo_t *lista = nullptr;
    float dato = 0;
    char rpt = 0;

    do
    {
        cout << "Indique un numero: "; cin >> dato;
        insertar_elemento_lista(lista,dato);
        cout << endl << "Desea ingresar otro elemento (s/n)?: "; cin >> rpt;
    } while ((rpt == 's') || (rpt == 'S'));

    mostrar_lista(lista);
    calcular_suma_y_promedio(lista);

    return 0;
}

//Agrega elemeno al final de la lista
void insertar_elemento_lista(Nodo_t *&lista, float n)
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

//Escribe la suma y el promedio de todos los elementos de la lista
void calcular_suma_y_promedio(Nodo_t *lista)
{
    float suma = 0, promedio = 0;
    int n = 0;

    while(lista != nullptr)
    {
        suma += lista->dato;
        n++;
        lista = lista->p_sig;
    }

    if(n)
        promedio = suma / n;

    cout << endl << "Suma: " << suma << endl;
    cout << endl << "Promedio: " << promedio << endl;
}
















