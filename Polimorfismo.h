// Polimorfismo.h
// Nombre: Jaime Hernandez Gonzalez
// Matricula: A00840312
// Carrera: ITC
// Fecha: 22/05/2024
// Reflexión: Aprendí a implementar y manejar polimorfismo en C++, así como a gestionar un inventario utilizando un arreglo de punteros a objetos de distintas clases derivadas.

#ifndef POLIMORFISMO_H
#define POLIMORFISMO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"

using namespace std;

const int MAX_VIDEOS = 100;
const int MAX_SERIES = 50;
const int MAX_PELICULAS = 50;

class Polimorfismo {
private:
    Video* arrPtrVideos[MAX_VIDEOS];
    Serie* arrPtrSeries[MAX_SERIES];
    Pelicula* arrPtrPeliculas[MAX_PELICULAS];
    int cantidad;
    int cantidadSeries;
    int cantidadPeliculas;

public:
    Polimorfismo();
    void leerArchivo(const std::string& nombre);

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
