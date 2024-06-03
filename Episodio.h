#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>

class Episodio {
private:
    std::string titulo;
    int temporada;
    int calificacion;

public:
    Episodio(std::string _titulo, int _temporada, int _calificacion);
    std::string str() const;
};

#endif
