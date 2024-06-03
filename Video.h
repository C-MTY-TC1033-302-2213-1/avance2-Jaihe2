/*
- Nombre: Jaime Hernandez Gonzalez
- Matricula: A00840312
- Carrera: ITC
- Fecha: 22/05/2024
- ¿Qué aprendí en el desarrollo de esta clase?
  Aprendí a manejar herencia y la creación de clases derivadas.
*/

#ifndef VIDEO_H
#define VIDEO_H

#include <string>

class Video {
protected:
    std::string id;
    std::string titulo;
    int duracion;
    std::string genero;
    double calificacion;

public:
    // Constructores
    Video();
    Video(std::string _id, std::string _titulo, int _duracion, std::string _genero, double _calificacion);

    // Métodos modificadores
    void setID(std::string _id);
    void setTitulo(std::string _titulo);
    void setDuracion(int _duracion);
    void setGenero(std::string _genero);
    void setCalificacion(double _calificacion);

    // Métodos de acceso
    std::string getID();
    std::string getTitulo();
    int getDuracion();
    std::string getGenero();
    double getCalificacion();

    // Método adicional
    virtual std::string str() const = 0;
};

#endif
