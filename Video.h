/*
Nombre: Jaime Hernández González
Carrera: ITC
Matrícula: A00840312
Fecha: 20/05/2024
*/
#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>
using namespace std;

class Video {
protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;
public:
//constructores
    Video();
    Video(string _iD, string _titulo
    ,int _duracion, string _genero
    ,double _calificacion);
//getters
    string getID();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();
//setters
    void setID(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);
//otros metodos
    virtual string str();
};


#endif