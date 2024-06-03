/*
- Nombre: Jaime Hernandez Gonzalez
- Matricula: A00840312
- Carrera: ITC
- Fecha: 22/05/2024
- ¿Qué aprendí en el desarrollo de esta clase?
  Aprendí a crear clases específicas con sus propios atributos y métodos.
*/

#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>

class Episodio {
private:
    std::string titulo;
    int duracion;
    int calificacion;

public:
    // Constructores
    Episodio();
    Episodio(std::string _titulo, int _duracion, int _calificacion);

    // Métodos modificadores
    void setTitulo(std::string _titulo);
    void setDuracion(int _duracion);
    void setCalificacion(int _calificacion);

    // Métodos de acceso
    std::string getTitulo() const;
    int getDuracion() const;
    int getCalificacion() const;

    // Método adicional
    std::string str() const;
};

#endif
