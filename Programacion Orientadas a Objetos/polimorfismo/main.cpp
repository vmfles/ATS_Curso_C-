/*
Vídeo nº 136 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Polimorfismo
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
    virtual void mostrar(); //Polimorfismo
};

//Clase hija
class Alumno : public Persona {
private:
    float m_nota_final;
public:
    Alumno(string,int,float);
    void mostrar();
};

//Clase hija
class Profesor : public Persona {
private:
    string m_materia;
public:
    Profesor(string,int,string);
    void mostrar();
};

Persona::Persona(string nombre, int edad) :
    m_nombre(nombre),
    m_edad(edad)
{

}

void Persona::mostrar()
{
    cout << endl << "Nombre: " << m_nombre << endl << "Edad: " << m_edad <<  endl;
}

Alumno::Alumno(string nombre, int edad, float nota) :
    Persona(nombre,edad),
    m_nota_final(nota)

{

}

void Alumno::mostrar()
{
    Persona::mostrar();
    cout << "Nota final: " << m_nota_final << endl;
}

Profesor::Profesor(string nombre, int edad, string materia) :
    Persona(nombre,edad),
    m_materia(materia)
{

}

void Profesor::mostrar()
{
    Persona::mostrar();
    cout << "Materia: " << m_materia << endl;
}

int main()
{
    Persona *vector[3];
    vector[0] = new Alumno("Alejandro",20,18.9f);
    vector[1] = new Profesor("Vicente",54,"Calculo");
    vector[2] = new Persona("Emma",7);

    vector[0]->mostrar();
    vector[1]->mostrar();
    vector[2]->mostrar();

    return 0;
}
