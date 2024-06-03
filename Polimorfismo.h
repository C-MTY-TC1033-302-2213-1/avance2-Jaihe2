#ifndef POLIMORFISMO_H
#define POLIMORFISMO_H

#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include <vector>
#include <string>

class Polimorfismo {
private:
    std::vector<Video*> arrPtrVideos;
    int cantidad;

public:
    Polimorfismo();
    ~Polimorfismo();
    void leerArchivo(const std::string& nombre);
    void reporteCalificacion(double calificacion);
    void reporteGenero(const std::string& genero);
    void reporteInventario();
    void reportePeliculas();
    void reporteSeries();
};

#endif
