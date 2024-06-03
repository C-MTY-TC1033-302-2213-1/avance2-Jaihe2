#include "Episodio.h"
#include <sstream>

Episodio::Episodio(std::string _titulo, int _temporada, int _calificacion)
    : titulo(_titulo), temporada(_temporada), calificacion(_calificacion) {}

std::string Episodio::str() const {
    std::ostringstream oss;
    oss << titulo << " " << temporada << " " << calificacion;
    return oss.str();
}
