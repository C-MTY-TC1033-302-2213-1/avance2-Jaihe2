/*
Nombre: Jaime Hernández González
Carrera: ITC
Matrícula: A00840312
Fecha: 20/05/2024
*/
#ifndef Episodio_h
#define Episodio_h
#include <string>
using namespace std;

class Episodio {
private:
    string titulo;
    int temporada;
    double calificacion;
public:
//constructores
    Episodio();
    Episodio(string _titulo, int _temporada, double _calificacion);
//getters
    string getTitulo();
    int getTemporada();
    double getCalificacion();
//setters
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(double _calificacion);
//otros metodods
    string str();
};


#endif