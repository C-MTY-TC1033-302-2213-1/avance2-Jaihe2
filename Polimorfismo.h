
/*
- Nombre: Jaime Hernandez Gonzalez
- Matricula: A00840312
- Carrera: ITC
- Fecha: 22/05/2024
- ¿Qué aprendí en el desarrollo de esta clase?
  Aprendí a implementar y manejar clases con polimorfismo en C++.
*/

#ifndef POLIMORFISMO_H
#define POLIMORFISMO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

const int MAX_VIDEOS = 100;

class Polimorfismo {
private:
    Video* arrPtrVideos[MAX_VIDEOS];
    int cantidad;
    Serie* arrPtrSeries[MAX_VIDEOS];
    Pelicula* arrPtrPeliculas[MAX_VIDEOS];
    int cantidadSeries;
    int cantidadPeliculas;

public:
    Polimorfismo();
    void leerArchivo(const std::string& _nombre);

    void setPtrVideo(int index, Video* video);
    void setCantidadVideos(int _cantidad);

    Video* getPtrVideo(int index);
    int getCantidad();

    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(const std::string& _genero);
    void reportePeliculas();
    void reporteSeries();
};

#endif /* POLIMORFISMO_H */
