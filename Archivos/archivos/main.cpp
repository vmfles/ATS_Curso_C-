/*
Vídeo nº 123, 124 y 125 del curso de YOUTUBE "Programación en C++ (Programación ATS)"
Archivos

1.- Crear un archivo
2.- Escribir en un archivo
3.- Lectura de un archivo
4.- Añadir texto al final de un archivo
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void escribir_en_archivo();
void lectura_archivo();
void agregar_texto_final_archivo();

int main()
{
    //escribir_en_archivo();
    //lectura_archivo();
    agregar_texto_final_archivo();

    return 0;
}


void escribir_en_archivo()
{
    ofstream archivo;
    string nombre_archivo, frase;

    //archivo.open("prueba.txt",ios::out); //Abrimos el archivo (si no existe entonces lo crea, si existe lo sobreescribe)
    //archivo.open("C:\\Users\\Vanessa\\Documents\\Proyectos_Qt\\CURSO C++ ATS\\Archivos\\ejemplo.txt",ios::out);
    cout << "Indique el nombre del archivo: ";
    getline(cin,nombre_archivo);
    archivo.open(nombre_archivo.c_str(),ios::out);
    if(archivo.fail()) //Comprueba si hay algún error al abrir/crear archivo
    {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

//    archivo << "Hola que tal? Mi nombre es Victor." << endl;
//    archivo << "Vamos a agregar mas texto." << endl;
    cout << "\nIndique el texto del archivo: ";
    getline(cin,frase);
    archivo << frase;
    archivo.close();
}

void lectura_archivo()
{
    ifstream archivo;
    string texto;

    //archivo.open("programacion.txt",ios::in); //Abrimos el archivo en modo lectura
    archivo.open("C:\\Users\\Vanessa\\Documents\\Proyectos_Qt\\CURSO C++ ATS\\Archivos\\ejemplo.txt",ios::in);

    if(archivo.fail())
    {
        cout << "\nNo se pudo abrir el archivo";
        exit(1);
    }

    while (!archivo.eof()) //Mientras no sea el final del archivo
    {
        getline(archivo,texto);
        cout << texto << endl;
    }

    archivo.close();
}

void agregar_texto_final_archivo()
{
    ofstream archivo;
    string nombre_archivo, frase;

    archivo.open("prueba.txt",ios::app); //Abrimos el archivo en modo añadir texto al final

    if(archivo.fail()) //Comprueba si hay algún error al abrir/crear archivo
    {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    //archivo << ". \nHemos agregado esta nueva linea." << endl;
    cout << "\nIndique el texto que quiere agregar al archivo: ";
    getline(cin,frase);
    archivo << frase;
    archivo.close();
}
