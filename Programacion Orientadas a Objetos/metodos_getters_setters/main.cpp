/*
Vídeo nº 132 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Constructores y Modificadoresw (Getters y Setters)
*/

#include <iostream>

using namespace std;

class Punto{
private:
    //Atributos
    int m_x, m_y;
public:
    //Punto();
    Punto(int,int);
    void set_punto(int,int);
    int get_x_punto();
    int get_y_punto();
};

Punto::Punto(int x, int y) :
    m_x(x),
    m_y(y)
{

}

//Establecemos valores a los atributos
void Punto::set_punto(int x, int y)
{
    m_x = x;
    m_y = y;
}

int Punto::get_x_punto()
{
    return m_x;
}

int Punto::get_y_punto()
{
    return m_y;
}

int main()
{
    //cout << "Hello World!" << endl;
    Punto punto1(0,0);
    punto1.set_punto(15,10);

    cout << punto1.get_x_punto() << endl;
    cout << punto1.get_y_punto() << endl;
    cout << endl;
    return 0;
}
