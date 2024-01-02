/*
Vídeo nº 99, 100 y 101 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Colas
*/

//LAS SIGUIENTES LÍNEAS DE CÓDIGOS IMPLEMENTAN UNA COLA UTILIZANDO SÓLO PUNTEROS

//#include <iostream>
//#include <stdlib.h>

//using namespace std;

//struct Nodo_t
//{
//    int dato;
//    Nodo_t *p_sig;
//};

//typedef struct
//{
//    Nodo_t *p_frente;
//    Nodo_t *p_fin;
//} Cola_t;

//void agregar_elemento_cola(Nodo_t **p_primero, Nodo_t **p_ultimo, int dato);
//void sacar_elemento_cola(Nodo_t **p_primero, Nodo_t **p_ultimo, int *dato);
//bool cola_vacia(Nodo_t *p_primero);

//int main()
//{
//    Nodo_t *p_primero = nullptr, *p_ultimo = nullptr;
//    int dato = 0;

//    cout << "\nIntroduza un numero: "; cin >> dato;
//    agregar_elemento_cola(&p_primero,&p_ultimo,dato);

//    cout << "\nIntroduza un numero: "; cin >> dato;
//    agregar_elemento_cola(&p_primero,&p_ultimo,dato);

//    cout << "\nIntroduza un numero: "; cin >> dato;
//    agregar_elemento_cola(&p_primero,&p_ultimo,dato);

//    cout << "\nSacamos los elementos de la COLA" << endl;
//    while(!cola_vacia(p_primero))
//    {
//        sacar_elemento_cola(&p_primero,&p_ultimo,&dato);
//        if(!cola_vacia(p_primero))
//        {
//            cout << dato << ", ";
//        }
//        else
//        {
//            cout << dato << ".";
//        }
//    }

//    cout << endl;

//    return 0;
//}

//void agregar_elemento_cola(Nodo_t **p_primero, Nodo_t **p_ultimo, int dato)
//{
//    Nodo_t *nuevo_nodo = new Nodo_t();
//    nuevo_nodo->dato = dato;
//    nuevo_nodo->p_sig = nullptr;

//    if(cola_vacia(*p_primero))
//    {
//        *p_primero = nuevo_nodo;
//    }
//    else
//    {
//        (*p_ultimo)->p_sig = nuevo_nodo;
//    }

//    *p_ultimo = nuevo_nodo;

//    cout << "\tElemento " << dato << " agregado a la COLA correctamente" << endl;
//}

//void sacar_elemento_cola(Nodo_t **p_primero, Nodo_t **p_ultimo, int *dato)
//{
//    Nodo_t *aux = *p_primero;
//    *dato = (*p_primero)->dato;

//    //if(p_primero->p_sig == nullptr) //Es el único elemento en la cola
//    if(*p_primero == *p_ultimo)
//    {
//        *p_ultimo = nullptr;
//        *p_primero = nullptr;
//    }
//    else //Hay más elementos en la cola
//    {
//        *p_primero = (*p_primero)->p_sig;
//    }

//    delete aux;
//}

//bool cola_vacia(Nodo_t *p_primero)
//{
////    bool si_vacia = false;

////    if(out_cola == nullptr)
////        si_vacia = true;

////    return si_vacia;
//    return (p_primero == nullptr)? true : false;
//}


//LAS SIGUIENTES LÍNEAS DE CÓDIGOS IMPLEMENTAN UNA COLA UTILIZANDO UNA ESTRUCTURA Cola_t

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
    Nodo_t *p_ultimo;
    int n_elementos;
} Cola_t;


void agregar_elemento_cola(Cola_t *cola, int dato);
void sacar_elemento_cola(Cola_t *p_cola, int *dato);
bool cola_vacia(Cola_t *cola);

int main()
{
    //Nodo_t *p_primero = nullptr, *p_ultimo = nullptr;
    Cola_t cola = {nullptr,nullptr,0};
    Cola_t *p_cola = &cola;

    int dato = 0;

    cout << "\nIntroduza un numero: "; cin >> dato;
    agregar_elemento_cola(p_cola,dato);

    cout << "\nIntroduza un numero: "; cin >> dato;
    agregar_elemento_cola(p_cola,dato);

    cout << "\nIntroduza un numero: "; cin >> dato;
    agregar_elemento_cola(p_cola,dato);

    cout << "\nSacamos los elementos de la COLA" << endl;
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

    return 0;
}

void agregar_elemento_cola(Cola_t *p_cola, int dato)
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

void sacar_elemento_cola(Cola_t *p_cola, int *dato)
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
