/*
- Nombre: Jaime Hernandez Gonzalez
- Matricula: A00840312
- Carrera: ITC
- Fecha: 22/05/2024
- ¿Qué aprendí en el desarrollo de esta clase?
  Aprendí a utilizar la composición y cómo una clase puede contener objetos de otra clase.
*/

#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"

class Serie : public Video {
private:
    Episodio episodios[5];
    int cantidad;

public:
    // Constructor
    Serie();
    Serie(std::string _ID, std::string _titulo, int _duracion, std::string _genero, double _calificacionPromedio);

    // Métodos modificadores
    void setEpisodio(int index, Episodio episodio);
    void setCantidad(int _cantidad);

    // Métodos de acceso
    Episodio getEpisodio(int index) const;
    int getCantidad() const;

    // Métodos adicionales
    double calculaPromedio() const;
    void calculaDuracion();
    std::string str() const;
    void agregaEpisodio(Episodio episodio);
};

#endif
