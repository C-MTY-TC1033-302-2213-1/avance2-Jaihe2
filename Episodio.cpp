/*
Nombre: Jaime Hernández González
Carrera: ITC
Matrícula: A00840312
Fecha: 02/06/2024
*/
#include "Episodio.h"

//constructores
Episodio::Episodio(){
    titulo = "The Dark Knight";
    temporada = 2;
    calificacion = 10.00;
}
Episodio::Episodio(string _titulo, int _temporada, double _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}
//getters
string Episodio::getTitulo(){
    return titulo;
}
int Episodio::getTemporada(){
    return temporada;
}
double Episodio::getCalificacion(){
    return calificacion;
}
//setters
void Episodio::setTitulo(string _titulo){
    titulo = _titulo;
}
void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}
void Episodio::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}
//otros metodods
string Episodio::str(){
    return titulo + ' ' + to_string(temporada) + ' ' +
    to_string(calificacion);
}