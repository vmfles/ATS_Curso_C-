/*
Vídeo nº 90 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Punteros - Contar vocales de una cadena con punteros

Ejercicio: Pedir al usuario una cadena e indicar cuantas veces aparece la vocal a, e, i, o, u en la cadena.
NOTA: Recuerda que debes utilizar punteros

*/

#include <iostream>
#include <string.h>

using namespace std;

#define STRING_SIZE   100

void pedir_cadena(char *p_cadena);
int contar_vocal_a_cadena(const char *p_cadena);
int contar_vocal_e_cadena(const char *p_cadena);
int contar_vocal_i_cadena(const char *p_cadena);
int contar_vocal_o_cadena(const char *p_cadena);
int contar_vocal_u_cadena(const char *p_cadena);

using namespace std;

int main()
{    
    char cadena[STRING_SIZE];

    pedir_cadena(cadena);

    cout << "La vocal \'A\' aparece " << contar_vocal_a_cadena(cadena) << " veces" << endl;
    cout << "La vocal \'E\' aparece " << contar_vocal_e_cadena(cadena) << " veces" << endl;
    cout << "La vocal \'I\' aparece " << contar_vocal_i_cadena(cadena) << " veces" << endl;
    cout << "La vocal \'O\' aparece " << contar_vocal_o_cadena(cadena) << " veces" << endl;
    cout << "La vocal \'U\' aparece " << contar_vocal_u_cadena(cadena) << " veces" << endl;

    return 0;
}

void pedir_cadena(char *p_cadena)
{
    cout << "Introduzca una cadena: ";
    cin.getline(p_cadena,STRING_SIZE,'\n');
    strupr(p_cadena);
}

int contar_vocal_a_cadena(const char *p_cadena)
{
    int cont = 0;

    while(*p_cadena)
    {
        if (*p_cadena == 'A')
        {
            cont++;
        }

        p_cadena++;
    }

    return cont;
}

int contar_vocal_e_cadena(const char *p_cadena)
{
    int cont = 0;

    while(*p_cadena)
    {
        if (*p_cadena == 'E')
        {
            cont++;
        }

        p_cadena++;
    }

    return cont;
}

int contar_vocal_i_cadena(const char *p_cadena)
{
    int cont = 0;

    while(*p_cadena)
    {
        if (*p_cadena == 'I')
        {
            cont++;
        }

        p_cadena++;
    }

    return cont;
}

int contar_vocal_o_cadena(const char *p_cadena)
{
    int cont = 0;

    while(*p_cadena)
    {
        if (*p_cadena == 'O')
        {
            cont++;
        }

        p_cadena++;
    }

    return cont;
}

int contar_vocal_u_cadena(const char *p_cadena)
{
    int cont = 0;

    while(*p_cadena)
    {
        if (*p_cadena == 'U')
        {
            cont++;
        }

        p_cadena++;
    }

    return cont;
}
