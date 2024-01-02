#include <iostream>

using namespace std;

#define NAME_SIZE   30

typedef struct{
    char nombre[30];
    int edad;
} Persona_t;

//static Persona_t persona;
//static Persona_t *pp = &persona;

void pedir_datos(Persona_t *pp);
void mostrar_datos(Persona_t *pp);

int main()
{
    Persona_t persona;
    Persona_t *pp = &persona;

    pedir_datos(pp);
    mostrar_datos(pp);

    return 0;
}

void pedir_datos(Persona_t *pp)
{
    cout << "Indique su nombre: ";
    cin.getline(pp->nombre,NAME_SIZE,'\n');
    cout << "\nIndique su edad: ";
    cin >> pp->edad;
}

void mostrar_datos(Persona_t *pp)
{
    cout << "\n\nNombre: " << pp->nombre << endl;
    cout << "Edad: " << pp->edad << endl;
}
