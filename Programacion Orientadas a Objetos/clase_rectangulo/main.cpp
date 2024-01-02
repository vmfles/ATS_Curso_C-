/*
Vídeo nº 128 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
POO - Crear una clase rectángulo que tenga los siguientes atributos:
1.- largo
2.- ancho

Y los siguientes métodos:
1.- perímetro
2.- área
*/

#include <iostream>

using namespace std;

class Rectangulo
{
private:
    float m_largo;
    float m_ancho;

public:
    Rectangulo(float,float);
    float perimetro();
    float area();
};

Rectangulo::Rectangulo(float largo, float ancho)
{
    m_largo = largo;
    m_ancho = ancho;
}

float Rectangulo::perimetro()
{
    return (2*m_largo+2*m_ancho);
}

float Rectangulo::area()
{
    return (m_largo*m_ancho);
}

int main()
{
    //cout << "Hello World!" << endl;
    Rectangulo rect1 = Rectangulo(11,7);

    cout << endl << "El perimetro es: " << rect1.perimetro() << "m" << endl;
    cout << endl << "El area es: " << rect1.area() << "m2" << endl;
    cout << endl;
    return 0;
}
