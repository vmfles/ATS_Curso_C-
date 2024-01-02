/*
Vídeo nº 137 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
POO - Ejercicio 4: Realice un programa en C++ que tenga la siguiente jerarquía de clases:
Animal (clase padre) -> Humano (clase hija)
        Animal
        /    \
    Humano  Perro

Y hacer polimorfismo con el método comer

*/

#include <iostream>

using namespace std;

class Animal {
private:
    int m_edad;
public:
    Animal(int);
    virtual void comer();
};

class Humano : public Animal {
private:
    string m_nombre;
public:
    Humano(int,string);
    void comer();
};

class Perro : public Animal {
private:
    string m_nombre;
    string m_raza;
public:
    Perro(int,string,string);
    void comer();
};

Animal::Animal(int edad) :
    m_edad(edad)
{

}

void Animal::comer()
{
    cout << "Yo como ";
}

Humano::Humano(int edad, string nombre) :
    Animal(edad),
    m_nombre(nombre)
{

}

void Humano::comer()
{
    Animal::comer();
    cout << "en una mesa, sentado en mi silla" << endl;
}

Perro::Perro(int edad, string nombre, string raza) :
    Animal(edad),
    m_nombre(nombre),
    m_raza(raza)
{

}

void Perro::comer()
{
    Animal::comer();
    cout << "en el suelo, en mi plato" << endl;
}

int main()
{
    //cout << "Hello World!" << endl;
    Animal *animales[2];

    animales[0] = new Perro(5,"Boby","Pastor Aleman");
    animales[0]->comer();

    animales[1] = new Humano(18,"Juan");
    animales[1]->comer();

    return 0;
}
