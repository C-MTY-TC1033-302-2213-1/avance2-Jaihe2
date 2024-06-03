#ifndef VIDEO_H
#define VIDEO_H

#include <string>

class Video {
protected:
    std::string id;
    std::string nombre;
    int duracion;
    std::string genero;
    double calificacion;

public:
    Video(std::string _id, std::string _nombre, int _duracion, std::string _genero, double _calificacion);
    virtual std::string str() const;
    double getCalificacion() const;
    std::string getGenero() const;
    virtual ~Video() = default;
};

#endif
