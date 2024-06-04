/*
Nombre: Jaime Hernández González
Carrera: ITC
Matrícula: A00840312
Fecha: 20/05/2024
*/

#include "Pelicula.h"

Pelicula::Pelicula():Video(){
    oscares = 3;
}
Pelicula::Pelicula(string _iD, string _titulo
    ,int _duracion, string _genero
    ,double _calificacion, int _oscares){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
    oscares = _oscares;
}
//getter
int Pelicula::getOscares(){
    return oscares;
}
//setter
void Pelicula::setOscares(int _oscares){
    oscares = _oscares;
}
//otros metodos
string Pelicula::str(){
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' +
    genero + ' ' + to_string(calificacion) + ' ' + to_string(oscares);
}