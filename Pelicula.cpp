/*
- Nombre: Jaime Hernandez Gonzalez
- Matricula: A00840312
- Carrera: ITC
- Fecha: 22/05/2024
*/

#include "Pelicula.h"

// Constructores
Pelicula::Pelicula() : Video(), oscares(0) {}

Pelicula::Pelicula(std::string _id, std::string _titulo, int _duracion, std::string _genero, double _calificacion, int _oscares)
    : Video(_id, _titulo, _duracion, _genero, _calificacion), oscares(_oscares) {}

// Métodos modificadores
void Pelicula::setOscares(int _oscares) {
    oscares = _oscares;
}

// Métodos de acceso
int Pelicula::getOscares() {
    return oscares;
}

// Método adicional
std::string Pelicula::str() const {
    return Video::str() + " " + std::to_string(oscares);
}
