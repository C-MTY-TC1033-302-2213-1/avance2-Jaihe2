/*
- Nombre: Jaime Hernandez Gonzalez
- Matricula: A00840312
- Carrera: ITC
- Fecha: 22/05/2024
- ¿Qué aprendí en el desarrollo de esta clase?
  Aprendí a implementar y manejar clases con polimorfismo en C++.
*/

#include "Polimorfismo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>

Polimorfismo::Polimorfismo() : cantidad(0), cantidadSeries(0), cantidadPeliculas(0) {
    for (int i = 0; i < MAX_VIDEOS; ++i) {
        arrPtrVideos[i] = nullptr;
    }
}

void Polimorfismo::setPtrVideo(int index, Video* video) {
    if (index >= 0 && index < MAX_VIDEOS) {
        arrPtrVideos[index] = video;
    }
}

void Polimorfismo::setCantidadVideos(int _cantidad) {
    if (_cantidad >= 0 && _cantidad <= MAX_VIDEOS) {
        cantidad = _cantidad;
    }
}

Video* Polimorfismo::getPtrVideo(int index) {
    if (index >= 0 && index < MAX_VIDEOS) {
        return arrPtrVideos[index];
    }
    return nullptr;
}

int Polimorfismo::getCantidad() {
    return cantidad;
}

void Polimorfismo::reporteInventario() {
    int contPeliculas = 0;
    int contSeries = 0;

    for (int i = 0; i < cantidad; ++i) {
        if (arrPtrVideos[i] != nullptr) {
            std::cout << arrPtrVideos[i]->str() << std::endl;
            if (dynamic_cast<Pelicula*>(arrPtrVideos[i])) {
                ++contPeliculas;
            } else if (dynamic_cast<Serie*>(arrPtrVideos[i])) {
                ++contSeries;
            }
        }
    }

    std::cout << "Peliculas = " << contPeliculas << std::endl;
    std::cout << "Series = " << contSeries << std::endl;
}

void Polimorfismo::reporteCalificacion(double _calificacion) {
    int total = 0;

    for (int i = 0; i < cantidad; ++i) {
        if (arrPtrVideos[i] != nullptr && arrPtrVideos[i]->getCalificacion() == _calificacion) {
            std::cout << arrPtrVideos[i]->str() << std::endl;
            ++total;
        }
    }

    std::cout << "Total = " << total << std::endl;
}

void Polimorfismo::reporteGenero(const std::string& _genero) {
    int total = 0;

    for (int i = 0; i < cantidad; ++i) {
        if (arrPtrVideos[i] != nullptr && arrPtrVideos[i]->getGenero() == _genero) {
            std::cout << arrPtrVideos[i]->str() << std::endl;
            ++total;
        }
    }

    std::cout << "Total = " << total << std::endl;
}

void Polimorfismo::reportePeliculas() {
    int contPeliculas = 0;

    for (int i = 0; i < cantidad; ++i) {
        if (arrPtrVideos[i] != nullptr && dynamic_cast<Pelicula*>(arrPtrVideos[i])) {
            std::cout << arrPtrVideos[i]->str() << std::endl;
            ++contPeliculas;
        }
    }

    if (contPeliculas > 0) {
        std::cout << "Total Peliculas = " << contPeliculas << std::endl;
    } else {
        std::cout << "No peliculas" << std::endl;
    }
}

void Polimorfismo::reporteSeries() {
    int contSeries = 0;

    for (int i = 0; i < cantidad; ++i) {
        if (arrPtrVideos[i] != nullptr && dynamic_cast<Serie*>(arrPtrVideos[i])) {
            std::cout << arrPtrVideos[i]->str() << std::endl;
            ++contSeries;
        }
    }

    if (contSeries > 0) {
        std::cout << "Total Series = " << contSeries << std::endl;
    } else {
        std::cout << "No series" << std::endl;
    }
}

void Polimorfismo::leerArchivo(const std::string& nombre) {
    Serie* arrPtrSeries[MAX_VIDEOS];
    Pelicula* arrPtrPeliculas[MAX_VIDEOS];
    std::fstream entrada;
    std::string row[7];
    std::string line, word;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, std::ios::in);

    if (!entrada.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombre << std::endl;
        return;
    }

    while (getline(entrada, line)) {
        std::stringstream s(line);
        iR = 0;

        while (getline(s, word, ',')) {
            row[iR++] = word;
        }

        if (row[0] == "P") {
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], std::stoi(row[3]), row[4], std::stod(row[5]), std::stoi(row[6]));
            std::cout << "Pelicula: " << arrPtrPeliculas[cantidadPeliculas]->str() << std::endl;
            cantidadPeliculas++;
        } else if (row[0] == "S") {
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], std::stoi(row[3]), row[4], std::stod(row[5]));
            std::cout << "Serie: " << arrPtrSeries[cantidadSeries]->str() << std::endl;
            cantidadSeries++;
        } else if (row[0] == "E") {
            index = std::stoi(row[1]) - 500;
            arrPtrSeries[index]->agregaEpisodio(Episodio(row[2], std::stoi(row[3]), std::stoi(row[4])));
            std::cout << "Episodio: " << arrPtrSeries[index]->str() << std::endl;
        }
    }

    for (int i = 0; i < cantidadSeries; ++i) {
        promedio = arrPtrSeries[i]->calculaPromedio();
        arrPtrSeries[i]->setCalificacion(promedio);
        arrPtrSeries[i]->calculaDuracion();
        arrPtrVideos[cantidad++] = arrPtrSeries[i];
    }

    for (int i = 0; i < cantidadPeliculas; ++i) {
        arrPtrVideos[cantidad++] = arrPtrPeliculas[i];
    }

    entrada.close();
}
