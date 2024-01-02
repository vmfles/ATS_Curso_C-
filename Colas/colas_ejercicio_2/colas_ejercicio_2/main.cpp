/*
Vídeo nº 102 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
COLAS - Ejercicio 2

Hacer un programa en C++ que guarde datos de clientes de un banco, los almacene en cola, y por ultimo muestre los clientes en el orden correcto.
*/

#include <iostream>
#include<conio.h>
#include <stdlib.h>

using namespace std;

#define NAME_SIZE   30
#define CLAVE_SIZE  10

typedef struct
{
    char name[NAME_SIZE];
    char clave[CLAVE_SIZE];
    int edad;
} Cliente_t;

struct Nodo_t
{
    Cliente_t   cliente;
    Nodo_t      *p_sig;
};

typedef struct
{
    Nodo_t *p_primero;
    Nodo_t *p_ultimo;
} Cola_t;

void pedir_datos_cliente(Cliente_t *p_cliente);
void imprimir_datos_cliente(Cliente_t *p_cliente);

bool cola_vacia(Cola_t *p_cola);
void agregar_cliente_cola(Cola_t *p_cola, Cliente_t *p_cliente);
void sacar_cliente_cola(Cola_t *p_cola, Cliente_t *p_cliente);

int main()
{
    Cola_t cola = {nullptr,nullptr};
    Cola_t *p_cola = &cola;
    Cliente_t cliente = {};
    Cliente_t *p_cliente = &cliente;
    char rpt = 0;

    do
    {
        pedir_datos_cliente(p_cliente);
        agregar_cliente_cola(p_cola,p_cliente);
        cout << "\n Desea agragar mas clientes? (s/n): "; cin >> rpt;
        cout << endl;

    } while ((rpt == 's') || (rpt == 'S'));

    if(!cola_vacia(p_cola))
    {
        cout << "\n*** MOSTRANDO DATOS DE CLIENTES ***" << endl;

        while(!cola_vacia(p_cola))
        {
            sacar_cliente_cola(p_cola,p_cliente);
            imprimir_datos_cliente(p_cliente);
        }
    }

    return 0;
}

void pedir_datos_cliente(Cliente_t *p_cliente)
{
    fflush(stdin);
    cout<<"\tIntroduzca los datos de un nuevo cliente"<<endl;
    cout<<"Nombre: "; cin.getline(p_cliente->name,NAME_SIZE,'\n');
    cout<<"Clave: "; cin.getline(p_cliente->clave,CLAVE_SIZE,'\n');
    cout<<"Edad: "; cin>>p_cliente->edad;
    cout<<"\n";
}

void imprimir_datos_cliente(Cliente_t *p_cliente)
{
    cout<<"Nombre: " << p_cliente->name << endl;
    cout<<"Clave: " << p_cliente->clave << endl;
    cout<<"Edad: " << p_cliente->edad << endl;
    cout << "\n";
}

void agregar_cliente_cola(Cola_t *p_cola, Cliente_t *p_cliente)
{
    Nodo_t *p_nuevo = new Nodo_t();
    p_nuevo->cliente = *p_cliente;
    p_nuevo->p_sig = nullptr;

    if(cola_vacia(p_cola))
    {
        p_cola->p_primero = p_nuevo;
    }
    else
    {
        p_cola->p_ultimo->p_sig = p_nuevo;
    }

    p_cola->p_ultimo = p_nuevo;
}

bool cola_vacia(Cola_t *p_cola)
{
    return ((p_cola->p_primero == nullptr) ? true : false);
}

void sacar_cliente_cola(Cola_t *p_cola, Cliente_t *p_cliente)
{
    Nodo_t *aux = p_cola->p_primero;
    *p_cliente = aux->cliente;

    if(p_cola->p_primero == p_cola->p_ultimo) //Sólo 1 cliente en cola
    {
        p_cola->p_primero = nullptr;
        p_cola->p_ultimo = nullptr;
    }
    else //Varios clientes en la cola
    {
        p_cola->p_primero = p_cola->p_primero->p_sig;
    }

    delete aux;
}



