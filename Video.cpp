/*
Nombre: Jaime Hernández González
Carrera: ITC
Matrícula: A00840312
Fecha: 20/05/2024
*/

#include "Video.h"
Video::Video(){
    iD = "A00838331";
    titulo = "Pedro";
    duracion = 18;
    genero = "Masculino";
    calificacion = 98.00;
}

Video::Video(string _iD, string _titulo
    ,int _duracion, string _genero
    ,double _calificacion){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}

//getters
string Video::getID(){
    return iD;
}

string Video::getTitulo(){
    return titulo;
}

string Video::getGenero(){
    return genero;
}

double Video::getCalificacion(){
    return calificacion;
}

int Video::getDuracion(){
    return duracion;
}
//setters
void Video::setID(string _iD){
    iD = _iD;
}

void Video::setTitulo(string _titulo){
    titulo = _titulo;
}

void Video::setDuracion(int _duracion){
    duracion = _duracion;
}

void Video::setGenero(string _genero){
    genero = _genero;
}

void Video::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}

string Video::str(){
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' +
    genero + ' ' + to_string(calificacion);
}