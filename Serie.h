/*
Nombre: Pedro Valdez Flores
Carrera: IDM
Matricula: A00838331
Fecha: 20/05/2024
*/
#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"
#include <vector>
using namespace std;

class Serie : public Video {
private:
    Episodio episodios[5];
    int cantidad;
public:
    Serie();
    Serie(string _id, string _nombre, int _duracion, string _genero, double _calificacion);
    void agregaEpisodio(Episodio ep);
    void setEpisodio(int _cantidad, Episodio);
    void setCantidad(int _cantidad);
    Episodio getEpisodio(int _posicion);
    int getCantidad();
    string str();
    double calculaPromedio();
    void calculaDuracion();
};

#endif