
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo_t
{
    int dato;
    Nodo_t *p_izq;
    Nodo_t *p_dch;
    Nodo_t *p_padre;
};

void menu(Nodo_t *&arbol);
Nodo_t* crear_nodo(int n, Nodo_t *p_padre);
void insertar_nodo(Nodo_t *&arbol, int n, Nodo_t *p_padre);
void mostrar_arbol(Nodo_t *arbol, int contador);
bool buscar_nodo(Nodo_t *arbol, int n);
void recorrer_preorden_arbol(Nodo_t *arbol); //Recorrido en pre-orden
void recorrer_inorden_arbol(Nodo_t *arbol); //Recorrido en in-orden
void recorrer_postorden_arbol(Nodo_t *arbol); //Recorrido en post-orden
void eliminiar_nodo_arbol(Nodo_t *arbol, int n); //Eliminar un nodo del árbol

int main()
{
    Nodo_t *arbol = nullptr;

    insertar_nodo(arbol,10,nullptr);
    insertar_nodo(arbol,5,nullptr);
    insertar_nodo(arbol,15,nullptr);
    insertar_nodo(arbol,3,nullptr);
    insertar_nodo(arbol,8,nullptr);
    insertar_nodo(arbol,12,nullptr);
    insertar_nodo(arbol,20,nullptr);
    insertar_nodo(arbol,6,nullptr);
    insertar_nodo(arbol,9,nullptr);
    insertar_nodo(arbol,30,nullptr);
    insertar_nodo(arbol,7,nullptr);
    menu(arbol);

    return 0;
}

void menu(Nodo_t *&arbol)
{
    int dato = 0, opc = 0;

    do
    {
        cout << "*** MENU ***" << endl;
        cout << "1.- Insertar un nuevo nodo" << endl;
        cout << "2.- Mostrar arbol" << endl;
        cout << "3.- Buscar un nodo" << endl;
        cout << "4.- Recorrer el arbol en pre-orden" << endl;
        cout << "5.- Recorrer el arbol en in-orden" << endl;
        cout << "6.- Recorrer el arbol en post-orden" << endl;
        cout << "7.- Borrar un nodo" << endl;
        cout << "8.- Salir" << endl;
        cout << "Opcion: "; cin >> opc;

        switch (opc)
        {
            case 1:
                cout << endl << "Indique un numero: "; cin >> dato;
                insertar_nodo(arbol,dato,nullptr);
                cout << endl;
                system("pause");
            break;

            case 2:
                cout << endl << "Mostrando el arbol completo: " << endl << endl;
                mostrar_arbol(arbol,0);
                cout << endl;
                system("pause");
            break;

            case 3:
                cout << endl << "Indique el numero que quiere buscar: "; cin >> dato;
                cout << endl << "El numero " << dato;
                if(buscar_nodo(arbol,dato))
                     cout << " SI";
                else cout << " NO";
                cout << " ha sido encontrado";
                cout << endl;
                system("pause");
            break;

            case 4:
                cout << endl << "Mostrando el arbol en pre-orden: " << endl << endl;
                recorrer_preorden_arbol(arbol);
                cout << endl;
                system("pause");
            break;

            case 5:
                cout << endl << "Mostrando el arbol en in-orden: " << endl << endl;
                recorrer_inorden_arbol(arbol);
                cout << endl;
                system("pause");
            break;

            case 6:
                cout << endl << "Mostrando el arbol en post-orden: " << endl << endl;
                recorrer_postorden_arbol(arbol);
                cout << endl;
                system("pause");
            break;

            case 7:
                cout << endl << "Indique el nodo que quiere eliminar: "; cin >> dato;
                eliminiar_nodo_arbol(arbol,dato);
                cout << endl;
                system("pause");
            break;
        }

        system("cls");
    } while (opc != 8);
}

Nodo_t* crear_nodo(int n, Nodo_t *p_padre)
{
    Nodo_t *nuevo_nodo = new Nodo_t();
    nuevo_nodo->dato = n;
    nuevo_nodo->p_dch = nullptr;
    nuevo_nodo->p_izq = nullptr;
    nuevo_nodo->p_padre = p_padre;
    return nuevo_nodo;
}

void insertar_nodo(Nodo_t *&arbol, int n, Nodo_t *p_padre)
{
    Nodo_t *nuevo_nodo = nullptr;
    int valor_raiz = 0;

    if(arbol == nullptr)
    {
        //Árbol vacío
        nuevo_nodo = crear_nodo(n,p_padre);
        arbol = nuevo_nodo;
    }
    else
    {
        //El árbol contiene algún nodo
        valor_raiz = arbol->dato;
        if(n < valor_raiz)
        {
            //Si el elemento es menor que el valor de raíz, insertamos en el lado izquierdo
            insertar_nodo(arbol->p_izq,n,arbol);
        }
        else
        {
            //Si el elemento es menor que el valor de raíz, insertamos en el lado derecho
            insertar_nodo(arbol->p_dch,n,arbol);
        }
    }
}

void mostrar_arbol(Nodo_t *arbol, int contador)
{
    if(arbol == nullptr)
        return;

    //Imprimimos la parte derecha del árbol
    mostrar_arbol(arbol->p_dch,contador+1);
    for(int i = 0; i < contador; i++)
        cout << "   ";
    cout << arbol->dato << endl;

    //Imprimimos la parte izquierda del árbol
    mostrar_arbol(arbol->p_izq,contador+1);
}

bool buscar_nodo(Nodo_t *arbol, int n)
{
    if (arbol == nullptr)
        return false;

    if(arbol->dato == n)
        return true;

    if(n < arbol->dato)
         return buscar_nodo(arbol->p_izq,n);
    else return buscar_nodo(arbol->p_dch,n);
}

//Recorrer en preorden el árbol: raíz, izquierdo y derecho
//Visite la raíz, atraviese el sub-árbol izquierdo y atraviese el sub-árbol derecho
void recorrer_preorden_arbol(Nodo_t *arbol) //Recorrido en preorden
{
    if(arbol != nullptr)
    {
        cout << arbol->dato << " - ";
        recorrer_preorden_arbol(arbol->p_izq);
        recorrer_preorden_arbol(arbol->p_dch);
    }
}

//Recorrer en preorden el árbol: izquierdo, raíz y derecho
//Atraviese el sub-árbol izquierdo, visite la raíz y atraviese el sub-árbol derecho
void recorrer_inorden_arbol(Nodo_t *arbol)
{
    if(arbol != nullptr)
    {
        recorrer_inorden_arbol(arbol->p_izq);
        cout << arbol->dato << " - ";
        recorrer_inorden_arbol(arbol->p_dch);
    }
}

//Recorrer en post-orden el árbol: izquierdo, derecho y raíz
//Atraviese el sub-árbol izquierdo, atraviese el sub-árbol derecho y visite la raíz
void recorrer_postorden_arbol(Nodo_t *arbol)
{
    if(arbol != nullptr)
    {
        recorrer_postorden_arbol(arbol->p_izq);
        recorrer_postorden_arbol(arbol->p_dch);
        cout << arbol->dato << " - ";
    }
}

    //Devuelve el nodo más a la izquierda posible (el menor de los hijos)
    Nodo_t* nodo_minimo(Nodo_t *arbol)
    {
        if(arbol != nullptr)
        {
            if(arbol->p_izq)
            {
                //Si tiene hijo izquierdo, buscamos la parte más izquierda posible
                nodo_minimo(arbol->p_izq);
            }
            else
            {
                return arbol;
            }
        }

        //return nullptr;
    }

    void reemplazar_nodos(Nodo_t *arbol, Nodo_t *nuevo_nodo)
    {
        if((arbol->p_padre == nullptr) || (nuevo_nodo == nullptr))
            return;

        //arbol->padre hay que asignarle a su nuevo hijo
        if(arbol->dato == arbol->p_padre->p_izq->dato)
        {
            //Hijo izquierdo
            arbol->p_padre->p_izq = nuevo_nodo;
        }
        else if(arbol->dato == arbol->p_padre->p_dch->dato)
        {
            //Hijo derecho
            arbol->p_padre->p_dch = nuevo_nodo;
        }

        nuevo_nodo->p_padre = arbol->p_padre;
    }

    void destruir_nodo(Nodo_t *&nodo)
    {
        if(nodo != nullptr)
        {
            nodo->p_izq = nullptr;
            nodo->p_dch = nullptr;
            nodo->p_padre = nullptr;
            nodo->dato = 0;

            delete nodo;
        }
    }

    void borrar_nodo(Nodo_t *nodo_eliminiar)
    {
        //EL BORRADO DE UN NODO DEPENDE DE LOS HIJOS QUE TIENE EL NODO:
        //1.- Nodo hoja: no tiene hijos
        //2.- Tiene sólo un hijo izquierdo
        //3.- Tiene sólo un hijo derecho
        //4.- Tiene 2 hijos (un hijo izquierdo y un hijo derecho)

        //2 hijos
        if(nodo_eliminiar->p_izq && nodo_eliminiar->p_dch)
        {
            //El nodo que queremos eliminar tiene 2 hijos
            Nodo_t *menor = nodo_minimo(nodo_eliminiar->p_dch);
            nodo_eliminiar->dato = menor->dato;
            borrar_nodo(menor);
        }
        else if (nodo_eliminiar->p_izq)
        {
            //El nodo que queremos eliminar sólo tiene un hijo (izquierdo)
            reemplazar_nodos(nodo_eliminiar,nodo_eliminiar->p_izq);
            destruir_nodo(nodo_eliminiar);
        }
        else if (nodo_eliminiar->p_dch)
        {
            //El nodo que queremos eliminar sólo tiene un hijo (derecho)
            reemplazar_nodos(nodo_eliminiar,nodo_eliminiar->p_dch);
            destruir_nodo(nodo_eliminiar);
        }
        else //No tiene ningún hijo, el nodo es una hoja
        {
            reemplazar_nodos(nodo_eliminiar,nullptr);
            destruir_nodo(nodo_eliminiar);
        }
    }

void eliminiar_nodo_arbol(Nodo_t *arbol, int n)
{
    if(arbol != nullptr)
    {
        if(n < arbol->dato)
        {
            //Si el valor es menor, busca por la izquierda
            eliminiar_nodo_arbol(arbol->p_izq,n);
        }
        else if (n > arbol->dato)
        {
            //Si el valor es mayor, busca por la derecha
            eliminiar_nodo_arbol(arbol->p_dch,n);
        }
        else
        {
            //Es el nodo que estamos buscando, borramos el nodo
            borrar_nodo(arbol);
        }
    }
}
