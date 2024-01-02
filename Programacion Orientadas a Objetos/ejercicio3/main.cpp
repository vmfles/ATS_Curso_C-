/*
Vídeo nº 134 y 135 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
POO - Ejercicio 3: Realice un programa en C++, de tal manera que se construya una solución para la jerarquía(herencia) de clases mostrada en la siguiente figura:

        Persona
        /    \
Empleado    Estudiante
                |
          Universitario

*/

#include <iostream>

using namespace std;

//Clase Persona es la clase padre
class Persona {
private:
    string m_nombre;
    int m_edad;
public:
    Persona(string,int);
    void mostrar_datos_persona();
};

//Clase Empleado es una clase hija que deriva de la clase Persona
class Empleado : public Persona {
private:
    float m_sueldo;
public:
    Empleado(string,int,float);
    void mostrar_datos_empleado();
};

class Estudiante : public Persona {
private:
    float m_nota_final;
public:
    Estudiante(string,int,float);
    void mostrar_datos_estudiante();
};

class Universitario : public Estudiante {
private:
    string m_carrera;
public:
    Universitario(string,int,float,string);
    void mostrar_datos_universitario();
};

//Constructor de la clase Persona
Persona::Persona(string nombre, int edad) :
    m_nombre(nombre), m_edad(edad)
{

}

void Persona::mostrar_datos_persona()
{
    cout << endl << "Nombre: " << m_nombre << endl << "Edad: " << m_edad <<  endl;
}

//Constructor de la clase Empleado
Empleado::Empleado(string nombre, int edad, float sueldo) :
    Persona(nombre,edad),
    m_sueldo(sueldo)
{
    //m_sueldo = sueldo;
}

void Empleado::mostrar_datos_empleado()
{
    mostrar_datos_persona();
    cout << "Sueldo: " << m_sueldo << endl;
}

//Constructor de la clase Estudiante
Estudiante::Estudiante(string nombre, int edad, float nota) :
    Persona(nombre,edad),
    m_nota_final(nota)
{

}

void Estudiante::mostrar_datos_estudiante()
{
    mostrar_datos_persona();
    cout << "Nota final: " << m_nota_final << endl;
}

Universitario::Universitario(string nombre, int edad, float nota, string carrera) :
    Estudiante(nombre,edad,nota),
    m_carrera(carrera)
{

}

void Universitario::mostrar_datos_universitario()
{
  mostrar_datos_estudiante();
  cout << "Carrera: " << m_carrera << endl;
}


int main()
{
    Empleado emp("Juan",25,1450.0f);
    cout << "--- EMPLEADO ---" << endl;
    emp.mostrar_datos_empleado();

    cout << endl << "--- UNIVERSITARIO ---" << endl;
    Universitario univer("Victor",19,9.8f,"Ing. Tec. Telecomunicaciones");
    univer.mostrar_datos_universitario();

    cout << endl << "--- ESTUDIANTE ---" << endl;
    Estudiante *est = new Estudiante("Paula",5,7.8f);
    est->mostrar_datos_estudiante();

    return 0;
}
