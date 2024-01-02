/*
Vídeo nº 127 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
POO - Clases

1.- Crear una clase: atributos y métodos
2.- Escribir en un archivo
3.- Lectura de un archivo
4.- Añadir texto al final de un archivo
*/

#include <iostream>

using namespace std;

class Persona
{
private:
    //Atributos o características
    int edad;
    string nombre;

public:
    //Métodos
    Persona(int,string); //Constructor de la clase
    void leer();
    void correr();
};

Persona::Persona(int _edad, string _nombre)
{
    edad = _edad;
    nombre = _nombre;
}

void Persona::leer()
{
    cout << endl << "Soy " << nombre << " y estoy leyendo un libro." << endl;
}

void Persona::correr()
{
    cout << endl << "Soy " << nombre << " y estoy corriendo una maraton." << endl;
}

int main()
{
    //Creamos el objeto persona1
    Persona *persona1 = new Persona(43,"Victor");
    persona1->leer();
    persona1->correr();

    //Creamos el objeto persona2
    Persona persona2(44,"Vanesa");
    persona2.leer();
    persona2.correr();
    return 0;
}
