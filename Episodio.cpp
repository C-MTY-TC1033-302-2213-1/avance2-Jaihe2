/*
- Nombre: Jaime Hernandez Gonzalez
- Matricula: A00840312
- Carrera: ITC
- Fecha: 22/05/2024
*/

#include "Episodio.h"

// Constructores
Episodio::Episodio() : titulo(""), duracion(0), calificacion(0) {}

Episodio::Episodio(std::string _titulo, int _duracion, int _calificacion)
    : titulo(_titulo), duracion(_duracion), calificacion(_calificacion) {}

// Métodos modificadores
void Episodio::setTitulo(std::string _titulo) {
    titulo = _titulo;
}

void Episodio::setDuracion(int _duracion) {
    duracion = _duracion;
}

void Episodio::setCalificacion(int _calificacion) {
    calificacion = _calificacion;
}

// Métodos de acceso
std::string Episodio::getTitulo() const {
    return titulo;
}

int Episodio::getDuracion() const {
    return duracion;
}

int Episodio::getCalificacion() const {
    return calificacion;
}

// Método adicional
std::string Episodio::str() const {
    return titulo + " " + std::to_string(duracion) + " " + std::to_string(calificacion);
}
