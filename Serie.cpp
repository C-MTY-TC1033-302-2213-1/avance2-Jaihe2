/*
- Nombre: Jaime Hernandez Gonzalez
- Matricula: A00840312
- Carrera: ITC
- Fecha: 22/05/2024
*/

#include "Serie.h"

// Constructor
Serie::Serie() : Video(), cantidad(0) {}

Serie::Serie(std::string _ID, std::string _titulo, int _duracion, std::string _genero, double _calificacionPromedio)
    : Video(_ID, _titulo, _duracion, _genero, _calificacionPromedio), cantidad(0) {}

// Métodos modificadores
void Serie::setEpisodio(int index, Episodio episodio) {
    if (index >= 0 && index < 5) {
        episodios[index] = episodio;
    }
}

void Serie::setCantidad(int _cantidad) {
    if (_cantidad >= 0 && _cantidad <= 5) {
        cantidad = _cantidad;
    }
}

// Métodos de acceso
Episodio Serie::getEpisodio(int index) const {
    if (index >= 0 && index < cantidad) {
        return episodios[index];
    }
    return Episodio(); // Devuelve un episodio vacío si el índice no es válido
}

int Serie::getCantidad() const {
    return cantidad;
}

// Métodos adicionales
double Serie::calculaPromedio() const {
    double suma = 0.0;
    for (int i = 0; i < cantidad; ++i) {
        suma += episodios[i].getCalificacion();
    }
    return (cantidad > 0) ? (suma / cantidad) : 0.0;
}

void Serie::calculaDuracion() {
    int duracionTotal = 0;
    for (int i = 0; i < cantidad; ++i) {
        duracionTotal += episodios[i].getDuracion();
    }
    setDuracion(duracionTotal);
}

std::string Serie::str() const {
    std::string result = Video::str() + " " + std::to_string(cantidad) + "\n";
    for (int i = 0; i < cantidad; ++i) {
        result += episodios[i].str() + "\n";
    }
    return result;
}

void Serie::agregaEpisodio(Episodio episodio) {
    if (cantidad < 5) {
        episodios[cantidad++] = episodio;
    }
}
