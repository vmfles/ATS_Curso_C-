/*
Vídeo nº 102 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
COLAS - Ejercicio 1

Hacer un programa en C++, utilizando COLAS que contenga el siguiente menú:
1.- Insertar un carácter a la COLA
2.- Mostrar todos los elementos de la COLA
3.- Salir
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo_t
{
    char dato;
    Nodo_t *p_sig;
};

typedef struct
{
    Nodo_t *p_primero;
    Nodo_t *p_ultimo;
    int n_elementos;
} Cola_t;


void agregar_elemento_cola(Cola_t *p_cola, char dato);
void sacar_elemento_cola(Cola_t *p_cola, char *dato);
bool cola_vacia(Cola_t *cola);

int main()
{
    //Nodo_t *p_primero = nullptr, *p_ultimo = nullptr;
    Cola_t cola = {nullptr,nullptr,0};
    Cola_t *p_cola = &cola;

    int opc = 0;
    char dato = 0;

    do
    {
        cout << "\nSeleccione una opcion: " << endl << endl;
        cout << "1.- Introduza un caracter a la COLA" << endl;
        cout << "2.- Mostrar todos los elementos de la COLA" << endl;
        cout << "3.- Salir" << endl;
        cin >> opc;

        switch (opc)
        {
            case 1:
                cout << "\nIntroduzca un caracter: "; cin >> dato;
                agregar_elemento_cola(p_cola,dato);
            break;

            case 2:
                cout << "\nMostrar todos los elementos de la COLA: ";
                while(!cola_vacia(p_cola))
                {
                    sacar_elemento_cola(p_cola,&dato);
                    if(!cola_vacia(p_cola))
                    {
                        cout << dato << ", ";
                    }
                    else
                    {
                        cout << dato << ".";
                    }
                }
                cout << endl;
                system("pause");
            break;

            case 3:
                //No se hace nada
            break;
        }

        system("cls"); //Limpiamos la pantalla

    } while((opc != 3));

    return 0;
}

void agregar_elemento_cola(Cola_t *p_cola, char dato)
{
    Nodo_t *nuevo_nodo = new Nodo_t();
    nuevo_nodo->dato = dato;
    nuevo_nodo->p_sig = nullptr;

    if(cola_vacia(p_cola))
    {
        p_cola->p_primero = nuevo_nodo;
    }
    else
    {
        p_cola->p_ultimo->p_sig = nuevo_nodo;
    }

    p_cola->p_ultimo = nuevo_nodo;

    cout << "\tElemento " << dato << " agregado a la COLA correctamente" << endl;
}

void sacar_elemento_cola(Cola_t *p_cola, char *dato)
{
    Nodo_t *aux = p_cola->p_primero;
    *dato = p_cola->p_primero->dato;

    //if(p_primero->p_sig == nullptr) //Es el único elemento en la cola
    if(p_cola->p_primero == p_cola->p_ultimo)
    {
        p_cola->p_ultimo = nullptr;
        p_cola->p_primero = nullptr;
    }
    else //Hay más elementos en la cola
    {
        p_cola->p_primero = p_cola->p_primero->p_sig;
    }

    delete aux;
}

bool cola_vacia(Cola_t *cola)
{
    return (cola->p_primero == nullptr)? true : false;
}

