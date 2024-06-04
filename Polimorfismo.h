/*
Nombre: Jaime Hernández González
Carrera: ITC
Matrícula: A00840312
Fecha: 20/05/2024
*/

#ifndef POLIMORFISMO_H
#define POLIMORFISMO_H

#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Polimorfismo {
private:
    static const int MAX_VIDEOS = 100;
    Video* arrPtrVideos[MAX_VIDEOS];
    int cantidad;
    int cantidadPeliculas;
    int cantidadSeries;

public:
    Polimorfismo();
    void setPtrVideo(int index, Video* video);
    void setCantidad(int _cantidad);
    Video* getPtrVideo(int index);
    int getCantidad();
    void leerArchivo(string nombre);
    void reporteInventario();
    void reporteCalificacion(double calificacion);
    void reporteGenero(string genero);
    void reportePeliculas();
    void reporteSeries();
};

#endif