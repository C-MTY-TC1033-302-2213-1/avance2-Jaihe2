#include "Serie.h"
#include <sstream>

Serie::Serie(std::string _id, std::string _nombre, int _duracion, std::string _genero, double _calificacion)
    : Video(_id, _nombre, _duracion, _genero, _calificacion) {}

void Serie::agregaEpisodio(const Episodio& episodio) {
    episodios.push_back(episodio);
}

double Serie::calculaPromedio() {
    double suma = 0;
    for (const auto& episodio : episodios) {
        suma += episodio.getCalificacion();
    }
    return episodios.empty() ? 0 : suma / episodios.size();
}

void Serie::calculaDuracion() {
    int duracionTotal = 0;
    for (const auto& episodio : episodios) {
        duracionTotal += episodio.getDuracion();
    }
    duracion = duracionTotal;
}

std::string Serie::str() const {
    std::ostringstream oss;
    oss << Video::str() << " " << episodios.size() << "\n";
    for (const auto& episodio : episodios) {
        oss << episodio.str() << "\n";
    }
    return oss.str();
}
