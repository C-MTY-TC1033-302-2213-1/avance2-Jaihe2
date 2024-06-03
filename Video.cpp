#include "Video.h"
#include <sstream>

Video::Video(std::string _id, std::string _nombre, int _duracion, std::string _genero, double _calificacion)
    : id(_id), nombre(_nombre), duracion(_duracion), genero(_genero), calificacion(_calificacion) {}

std::string Video::str() const {
    std::ostringstream oss;
    oss << id << " " << nombre << " " << duracion << " " << genero << " " << calificacion;
    return oss.str();
}

double Video::getCalificacion() const {
    return calificacion;
}

std::string Video::getGenero() const {
    return genero;
}
