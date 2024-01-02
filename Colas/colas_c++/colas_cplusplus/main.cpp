#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo_t
{
    int dato;
    Nodo_t *p_sig;
};


bool cola_vacia(Nodo_t *p_frente);
void insertar_elemento_cola(Nodo_t *&p_frente, Nodo_t *&p_fin, int dato);
int sacar_elemento_cola(Nodo_t *&p_frente, Nodo_t *&p_fin);

int main()
{
    Nodo_t *p_frente = nullptr, *p_fin = nullptr;
    //int dato = 0;

    //cout << "\nIntroduza un numero: "; cin >> dato;
    insertar_elemento_cola(p_frente,p_fin,5);
    insertar_elemento_cola(p_frente,p_fin,10);
    insertar_elemento_cola(p_frente,p_fin,15);
    insertar_elemento_cola(p_frente,p_fin,20);
    insertar_elemento_cola(p_frente,p_fin,25);

    cout << "\nELEMENTOS DE LA COLA\n";

    while(!cola_vacia(p_frente))
    {
        cout << sacar_elemento_cola(p_frente,p_fin);
        if(!cola_vacia(p_frente))
            cout << " - ";
    }

    cout << endl;

    return 0;
}

bool cola_vacia(Nodo_t *p_frente)
{
    return (p_frente == nullptr) ? true : false;
}

void insertar_elemento_cola(Nodo_t *&p_frente, Nodo_t *&p_fin, int dato)
{
    Nodo_t *nuevo_nodo = new Nodo_t();
    nuevo_nodo->dato = dato;
    nuevo_nodo->p_sig = nullptr;

    if(cola_vacia(p_frente))
    {
        p_frente = nuevo_nodo;
    }
    else
    {
        p_fin->p_sig = nuevo_nodo;
    }

    p_fin = nuevo_nodo;
}

int sacar_elemento_cola(Nodo_t *&p_frente, Nodo_t *&p_fin)
{
    int dato = 0;
    Nodo_t *aux = p_frente;

    dato = p_frente->dato;

    if(p_frente == p_fin)
    {
        p_fin = nullptr;
    }

    p_frente = p_frente->p_sig;

    delete aux;
    return dato;
}


