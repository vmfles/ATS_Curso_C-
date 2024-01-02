/*
Vídeo nº 129 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
POO - Sobrecarga de constructores
*/

#include <iostream>

using namespace std;

class Fecha{
private:
    int m_dia, m_mes, m_anho;
public:
    Fecha(int,int,int); //Constructor 1
    Fecha(long); //Constructor 2
    void mostrar_fecha();
};

Fecha::Fecha(int dia, int mes, int anho)
{
    m_dia = dia;
    m_mes = mes;
    m_anho = anho;
}

Fecha::Fecha(long fecha)
{
    m_anho = int(fecha/10000);
    m_mes = int((fecha-m_anho*10000)/100);
    m_dia = int(fecha-m_anho*10000-m_mes*100);
}

void Fecha::mostrar_fecha()
{
    cout << endl << "La fecha es: " << m_dia << "/" << m_mes << "/" << m_anho << endl;
}

int main()
{
    //cout << "Hello World!" << endl;
    Fecha hoy(16,12,2023);
    hoy.mostrar_fecha();

    Fecha ayer(20231225);
    ayer.mostrar_fecha();

    cout << endl;

    return 0;
}
