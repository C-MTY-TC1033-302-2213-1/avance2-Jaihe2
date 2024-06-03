/*
- Nombre: Jaime Hernandez Gonzalez
- Matricula: A00840312
- Carrera: ITC
- Fecha: 22/05/2024
*/

#include "Video.h"

// Constructores
Video::Video() : id("0000"), titulo(""), duracion(0), genero(""), calificacion(0.0) {}

Video::Video(std::string _id, std::string _titulo, int _duracion, std::string _genero, double _calificacion)
    : id(_id), titulo(_titulo), duracion(_duracion), genero(_genero), calificacion(_calificacion) {}

// Métodos modificadores
void Video::setID(std::string _id) {
    id = _id;
}

void Video::setTitulo(std::string _titulo) {
    titulo = _titulo;
}

void Video::setDuracion(int _duracion) {
    duracion = _duracion;
}

void Video::setGenero(std::string _genero) {
    genero = _genero;
}

void Video::setCalificacion(double _calificacion) {
    calificacion = _calificacion;
}

// Métodos de acceso
std::string Video::getID() {
    return id;
}

std::string Video::getTitulo() {
    return titulo;
}

int Video::getDuracion() {
    return duracion;
}

std::string Video::getGenero() {
    return genero;
}

double Video::getCalificacion() {
    return calificacion;
}

// Método adicional
std::string Video::str() const {
    return id + " " + titulo + " " + std::to_string(duracion) + " " + genero + " " + std::to_string(calificacion);
}
