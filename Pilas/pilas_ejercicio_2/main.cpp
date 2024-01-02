/*
Vídeo nº 98 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Pilas - Ejercicio 2

Hacer un programa en C++, utilizando Pilas que contenga el siguiente menú:
1.- Insertar un carácter a la pila
2.- Mostrar todos los elementos de la pila
3.- Salir
*/


#include <iostream>
#include <stdlib.h>

using namespace std;


typedef struct nodo
{
    char dato;
    nodo *p_sig;
} Nodo_t;

void agregar_nodo_pila(Nodo_t *&pp, char dato);
void sacar_nodo_pila(Nodo_t *&pp, char &dato);

int main()
{
    Nodo_t *pp = nullptr;    
    int opc = 0;
    char dato = 0;

    do
    {
        cout << "\nSeleccione una opcion: " << endl << endl;
        cout << "1.- Introduza un caracter a la PILA" << endl;
        cout << "2.- Mostrar todos los elementos de la PILA" << endl;
        cout << "3.- Salir" << endl;
        cin >> opc;

        switch (opc)
        {
            case 1:
                cout << "\nIntroduzca un caracter: "; cin >> dato;
                agregar_nodo_pila(pp,dato);
            break;

            case 2:
                cout << "\nMostrar todos los elementos de la PILA: ";
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

void agregar_nodo_pila(Nodo_t *&pp, char dato)
{
    Nodo_t *aux = new Nodo_t();
    aux->dato = dato;
    aux->p_sig = pp;
    pp = aux;

    cout << "\t Elemento " << dato << " agregado a la PILA correctamente.";
}

void sacar_nodo_pila(Nodo_t *&pp, char &dato)
{
    Nodo_t *aux = pp;
    dato = aux->dato;
    pp = aux->p_sig;
    delete aux;
}
