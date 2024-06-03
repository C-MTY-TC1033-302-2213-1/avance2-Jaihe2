/*
- Nombre: Jaime Hernandez Gonzalez
- Matricula: A00840312
- Carrera: ITC
- Fecha: 22/05/2024
- ¿Qué aprendí en el desarrollo de esta clase?
  Aprendí a usar la herencia para crear clases derivadas con atributos y métodos adicionales.
*/

#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
private:
    int oscares;

public:
    // Constructores
    Pelicula();
    Pelicula(std::string _id, std::string _titulo, int _duracion, std::string _genero, double _calificacion, int _oscares);

    // Métodos modificadores
    void setOscares(int _oscares);

    // Métodos de acceso
    int getOscares();

    // Método adicional
    std::string str() const override;
};

#endif
