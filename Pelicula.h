#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
private:
    int oscares;

public:
    Pelicula(std::string _id, std::string _nombre, int _duracion, std::string _genero, double _calificacion, int _oscares);
    std::string str() const override;
};

#endif
