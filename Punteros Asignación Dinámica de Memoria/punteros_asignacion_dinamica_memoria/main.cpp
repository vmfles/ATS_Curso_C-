/*
Vídeo nº 86 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Punteros - Asignación dinámica de arreglos

new: reserva el número de bytes solicitados por la declaración
delete: libera un bloque de memoria de bytes reservado con anterioridad

Ejemplo: pedir al usuario n calificaciones y almacenarlas en un array dinámico

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

static int n_calif = 0, *p_calif = nullptr;

//Prototipos de funciones
void pedir_notas();
void mostar_notas();

int main()
{
    pedir_notas();
    mostar_notas();

    delete[] p_calif;
    return 0;
}

void pedir_notas()
{
    cout << "Introduce la cantidad de calificaciones: "; cin >> n_calif;

    p_calif = new int[n_calif];

    for(int i = 0; i < n_calif; i++)
    {
        cout << "Ingrese una nota: ";
        cin >> *(p_calif+i);
        //cin >> p_calif[i];
    }
}

void mostar_notas()
{
    cout << "\n\nMostrando notas del usuario:\n";
    for(int i = 0; i < n_calif; i++)
    {
        //cout << "Calificacion " << i+1 << ": " << p_calif[i] << endl;
       cout << "Calificacion " << i+1 << ": " << *(p_calif+i) << endl;
    }
}
