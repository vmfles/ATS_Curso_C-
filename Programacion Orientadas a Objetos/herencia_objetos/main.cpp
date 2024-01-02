/*
Vídeo nº 133 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Herencia en POO
*/

#include <iostream>

using namespace std;

//Clase padre
class Persona{
private:
    string m_nombre;
    int m_edad;
public:
    Persona(string,int);
    void mostrar_datos_persona();
};

//Clase hija de Persona que puede acceder a todos los atributos y métodos públicos de la clase Persona
class Alumno : public Persona
{
private:
    string m_codigo_alumno;
    float m_nota_final;
public:
    Alumno(string,int,string,float);
    void mostrar_datos_alumno();
};

Persona::Persona(string nombre, int edad) :
    m_nombre(nombre),
    m_edad(edad)
{

}

void Persona::mostrar_datos_persona()
{
    cout << endl << "Nombre: " << m_nombre << endl << "Edad: " << m_edad <<  endl;
}

Alumno::Alumno(string nombre, int edad, string codigo, float nota) : Persona(nombre,edad)
{
    m_codigo_alumno = codigo;
    m_nota_final = nota;
}

void Alumno::mostrar_datos_alumno()
{
    mostrar_datos_persona();
    cout << endl << "Código alumno: " << m_codigo_alumno<< endl << "Nota final: " << m_nota_final <<  endl;
}

int main()
{
    Alumno alumno1("Victor",43,"1547895",15.6f);
    alumno1.mostrar_datos_alumno();
    return 0;
}
