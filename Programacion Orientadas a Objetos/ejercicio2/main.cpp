/*
Vídeo nº 130 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
POO - Ejercicio 2: Construya una clase Tiempo que contenga los siguientes atributos enteros: horas, minutos y segundos.
Haga que la clase contenga 2 constructores, el primero debe tener 3 parámetros Tiempo(int,int,int) y el segundo
sólo tendrá un campo que serán los segundos y desensamble el número entero largo en horas, minutos y segundos.
*/

#include <iostream>

using namespace std;

class Tiempo{
private:
    int m_segundos, m_minutos, m_horas;
public:
    Tiempo(int,int,int);
    Tiempo(int);
    void mostrar_tiempo();
};

Tiempo::Tiempo(int horas, int minutos, int segundos)
{
    m_segundos = segundos;
    m_minutos = minutos;
    m_horas = horas;
}

Tiempo::Tiempo(int tiempo_sg)
{
    m_horas = tiempo_sg/3600; //Extraemos las horas
    tiempo_sg %= 3600;
    m_minutos = tiempo_sg/60; //Extraemos los minutos
    m_segundos = tiempo_sg%60; //Extraemos los segundos
}

void Tiempo::mostrar_tiempo()
{
    cout << endl << "La hora es: " << m_horas << ":" << m_minutos << ":" << m_segundos << endl;
}

int main()
{
    Tiempo hora_actual(12,48,50);
    hora_actual.mostrar_tiempo();

    Tiempo hora_anterior(125);
    hora_anterior.mostrar_tiempo();
    return 0;
}
