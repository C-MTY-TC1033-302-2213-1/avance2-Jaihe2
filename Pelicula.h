/*
Nombre: Jaime Hernández González
Carrera: ITC
Matrícula: A00840312
Fecha: 20/05/2024
*/

#ifndef Pelicula_h
#define Pelicula_h
#include "Video.h"
#include <string>
using namespace std;

//clase pelicula es derivada de video
class Pelicula : public Video{
private:
    int oscares;
public:
//constructores
    Pelicula();
    Pelicula(string _iD, string _titulo
    ,int _duracion, string _genero
    ,double _calificacion, int _oscares);
//getter
    int getOscares();
//setter
    void setOscares(int _oscares);
//otros metodos
    string str();
};
#endif