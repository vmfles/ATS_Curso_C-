/*
Vídeo nº 96 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Pilas - Insertar elementos a una pila
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo_t
{
    int dato;
    Nodo_t *p_siguiente;
};

//void func1_alterar_numero(int n);
//void func2_alterar_numero(int *n);
//void func3_alterar_numero(int &n);
//void func4_alterar_numero(int *&n);
void agregar_elemento_pila(Nodo_t *&, int);

int main()
{
    Nodo_t *pila = nullptr;
    int n1, n2;

    cout << "Inserte un numero: ";
    cin >> n1;
//    func1_alterar_numero(n1);
//    func2_alterar_numero(&n1);
//    func3_alterar_numero(n1);
//    int *p_n1 = &n1;
//    func4_alterar_numero(p_n1);

    agregar_elemento_pila(pila,n1);

    cout << "\nInserte otro numero: ";
    cin >> n2;

    agregar_elemento_pila(pila,n2);

    return 0;
}

void func1_alterar_numero(int n)
{
    n++;
    cout << "El numero introducido + 1 es: " << n << endl;
}

void func2_alterar_numero(int *n)
{
    //*n = *n+2;
    *n += 2;
    cout << "El numero introducido + 2 es: " << *n << endl;
}

void func3_alterar_numero(int &n)
{
    n = n+3;
    cout << "El numero introducido + 3 es: " << n << endl;
}

void func4_alterar_numero(int *&n)
{
    *n += 4;
    cout << "El numero introducido + 4 es: " << n << endl;
}

void agregar_elemento_pila(Nodo_t *&pila, int dato)
{
    Nodo_t *nuevo_nodo = new Nodo_t();
    nuevo_nodo->dato = dato;
    nuevo_nodo->p_siguiente = pila;
    pila = nuevo_nodo;

    cout << "\nElemento " << dato << " agregado a PILA correctamente" << endl;
}
