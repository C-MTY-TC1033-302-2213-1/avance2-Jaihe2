// Episodio.h
// Nombre: [Tu Nombre]
// Matricula: [Tu Matrícula]
// Carrera: [Tu Carrera]
// Fecha: [Fecha]
// Reflexión:
// - ¿Qué aprendí en el desarrollo de esta clase?

#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>
using namespace std;

class Episodio {
private:
    string titulo;
    int temporada;

public:
    Episodio(string titulo, int temporada)
        : titulo(titulo), temporada(temporada) {}

    string str() const {
        return titulo + " " + to_string(temporada);
    }
};

#endif
