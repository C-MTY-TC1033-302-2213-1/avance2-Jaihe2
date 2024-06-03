#include "Pelicula.h"
#include <sstream>

Pelicula::Pelicula(std::string _id, std::string _nombre, int _duracion, std::string _genero, double _calificacion, int _oscares)
    : Video(_id, _nombre, _duracion, _genero, _calificacion), oscares(_oscares) {}

std::string Pelicula::str() const {
    std::ostringstream oss;
    oss << Video::str() << " " << oscares;
    return oss.str();
}
