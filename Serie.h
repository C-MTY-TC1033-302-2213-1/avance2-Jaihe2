#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"
#include <vector>

class Serie : public Video {
private:
    std::vector<Episodio> episodios;

public:
    Serie(std::string _id, std::string _nombre, int _duracion, std::string _genero, double _calificacion);
    void agregaEpisodio(const Episodio& episodio);
    double calculaPromedio();
    void calculaDuracion();
    std::string str() const override;
};

#endif
