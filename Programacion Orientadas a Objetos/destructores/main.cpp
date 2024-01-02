/*
Vídeo nº 131 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Destructores de objetos
*/

#include <iostream>

using namespace std;

class Perro{
private:
    string m_nombre;
    string m_raza;
public:
    Perro(string,string); //Constructor
    ~Perro(); //Destructor
    void mostrar_datos();
    void jugar();
};

Perro::Perro(string nombre, string raza)
{
    m_nombre = nombre;
    m_raza = raza;
}

Perro::~Perro()
{

}

void Perro::mostrar_datos()
{
    cout << endl << "El nombre del perro es " << m_nombre << " y su raza es " << m_raza << endl;
}

void Perro::jugar()
{
    cout << endl << "El perro " << m_nombre << " esta jugando" << endl;
}

int main()
{
    Perro perro1("Fido","Doberman");
    perro1.mostrar_datos();
    perro1.jugar();
    perro1.~Perro();

    cout << endl;

    return 0;
}
