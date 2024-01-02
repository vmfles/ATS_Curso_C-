/*
Vídeo nº 104, 105, 106, 107 y 108 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Listas
Tenemos 4 tipos de listas:
1.- Listas simplemente enlazadas
2.- Listas doblemente enlazadas
3.- Listas circulares simplemente enlazadas
4.- Listas circulares doblemente enlazadas

Vamos a implementar 4 funciones para una lista ordenada de forma creciente:
a) Insertar elemento en la lista
b) Mostrar todos los elementos de la lista
c) Buscar un elemento en la lista
d) Eliminar un elemento de la lista
e) Eliminar toda la lista
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo_t
{
    int dato;
    Nodo_t *p_sig;
};

typedef struct
{
    Nodo_t *p_primero;
    int n_elementos;
} Lista_t;

void menu(Lista_t *p_lista);
void insertar_elemento_lista(Lista_t *p_lista, int dato);
void mostrar_elementos_lista(Lista_t *p_lista);
void buscar_elemento_lista(Lista_t *p_lista, int n);
void eliminar_elemento_lista(Lista_t *p_lista, int n);
void eliminar_todos_elementos_lista(Lista_t *p_lista);

int main()
{
    //Nodo_t *lista = nullptr;
    Lista_t lista = {nullptr,0};
    //Lista_t *p_lista = &lista;

    menu(&lista);

    cout << endl << "BYE BYE ..." << endl;

    return 0;
}

void menu(Lista_t *p_lista)
{
    int opc = 0, dato = 0;

    do
    {
        system("cls");
        cout << "\t *** MENU *** \n";
        cout << "1.- Insertar elementos a la lista" << endl;
        cout << "2.- Mostrar elementos de la lista" << endl;
        cout << "3.- Buscar en la lista" << endl;
        cout << "4.- Borrar elemento de la lista" << endl;
        cout << "5.- Eliminar todos los elementos de la lista" << endl;
        cout << "6.- Salir" << endl;
        cout << "Opcion: "; cin >> opc;

        switch (opc)
        {
            case 1:
                cout << "Inserte un numero: "; cin >> dato;
                insertar_elemento_lista(p_lista,dato);
            break;

            case 2:
                cout << "\n\nVAMOS A MOSTRAR LOS ELEMENTOS DE LA LISTA" << endl;
                mostrar_elementos_lista(p_lista);
                system("pause");
            break;

            case 3:
                cout << "Indique el elemento que quiere buscar en la lista: "; cin >> dato;
                buscar_elemento_lista(p_lista,dato);
                system("pause");
            break;

            case 4:
                cout << "Indique el elemento que quiere borrar de la lista: "; cin >> dato;
                eliminar_elemento_lista(p_lista,dato);
                system("pause");
            break;

            case 5:
                eliminar_todos_elementos_lista(p_lista);
                cout << endl << "SE HA BORRADO TODOS LOS ELEMENTOS DE LA LISTA" << endl;
                system("pause");
            break;
        }

        cout << endl;

    } while (opc != 6);
}

void insertar_elemento_lista(Lista_t *p_lista, int dato)
{
    Nodo_t *nuevo_nodo = new Nodo_t();
    Nodo_t *aux1 = p_lista->p_primero, *aux2 = nullptr;

    nuevo_nodo->dato = dato;

    while((aux1 != nullptr) && (aux1->dato < dato))
    {
        aux2 = aux1;
        aux1 = aux1->p_sig;
    }

    if(p_lista->p_primero == aux1)
    {
        //Se inserta al principio de la lista
        p_lista->p_primero = nuevo_nodo;
    }
    else //Se inserta en medio o final de la lista
    {
        aux2->p_sig = nuevo_nodo;
    }

    nuevo_nodo->p_sig = aux1;
    p_lista->n_elementos++;

    cout << "\tElmento " << dato << " insertado en la lista (" << p_lista->n_elementos << ")" << endl;
}


void mostrar_elementos_lista(Lista_t *p_lista)
{
    Nodo_t *aux = p_lista->p_primero;

    while(aux != nullptr)
    {
        //cout << "\nElemento: " << aux->dato;
        cout << aux->dato;
        aux = aux->p_sig;
        if(aux != nullptr)
             cout << " -> ";
    }

    cout << endl;
}

void buscar_elemento_lista(Lista_t *p_lista, int n)
{
    bool found = false;
    Nodo_t *aux = p_lista->p_primero;
//    Nodo_t *aux = new Nodo_t();
//    aux = p_lista->p_primero;

    while((!found) && (aux != nullptr) && (aux->dato <= n))
    {
        if(aux->dato == n)
             found = true;
        else aux = aux->p_sig;
    }

    cout << endl << "El numero " << n;

    if(found)
         cout << " SI ";
    else cout << " NO ";

    cout << "ha sido encontrado en la lista" << endl;

//    aux = nullptr;
//    delete aux;
}

void eliminar_elemento_lista(Lista_t *p_lista, int n)
{
    Nodo_t *aux_borrar = nullptr, *ant = nullptr;
    bool found = false;

    if(!p_lista->n_elementos)
        return;

    ant = aux_borrar = p_lista->p_primero;

    while (!found && (aux_borrar != nullptr) && (aux_borrar->dato <= n))
    {
        if(aux_borrar->dato == n)
        {
            found = true;
        }
        else
        {
            ant = aux_borrar;
            aux_borrar = aux_borrar->p_sig;
        }
    }

    if(!found)
    {
        cout << "\nNO SE HA EN ENCONTRADO EN LA LISTA EL ELEMENTO " << aux_borrar->dato << endl;
    }
    else
    {
        ant->p_sig = aux_borrar->p_sig;
        if(p_lista->p_primero == aux_borrar)
            p_lista->p_primero = aux_borrar->p_sig;

        cout << "\nSE ELIMINA EL ELEMENTO " << aux_borrar->dato << endl;
        p_lista->n_elementos--;
        delete  aux_borrar;
    }

    mostrar_elementos_lista(p_lista);
}

void eliminar_todos_elementos_lista(Lista_t *p_lista)
{
    Nodo_t *aux_borrar = p_lista->p_primero;

    while (p_lista->p_primero != nullptr)
    {
        aux_borrar = p_lista->p_primero;
        p_lista->p_primero = p_lista->p_primero->p_sig;
        cout << "\nSE ELIMINA EL ELEMENTO " << aux_borrar->dato << endl;
        p_lista->n_elementos--;
        delete  aux_borrar;
    }
}
































