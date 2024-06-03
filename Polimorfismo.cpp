#include "Polimorfismo.h"
#include <fstream>
#include <sstream>
#include <iostream>

Polimorfismo::Polimorfismo() : cantidad(0) {}

Polimorfismo::~Polimorfismo() {
    for (auto ptr : arrPtrVideos) {
        delete ptr;
    }
}

void Polimorfismo::leerArchivo(const std::string& nombre) {
    std::ifstream entrada(nombre);
    std::string row[7];
    std::string line, word;
    int iR = 0, index;
    double promedio;

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
            arrPtrVideos.push_back(new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6])));
        } else if (row[0] == "S") {
            arrPtrVideos.push_back(new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5])));
        } else if (row[0] == "E") {
            index = stoi(row[1]) - 500;
            static_cast<Serie*>(arrPtrVideos[index])->agregaEpisodio(Episodio(row[2], stoi(row[3]), stoi(row[4])));
        }
    }

    entrada.close();
}

void Polimorfismo::reporteCalificacion(double calificacion) {
    int count = 0;
    for (const auto& ptr : arrPtrVideos) {
        if (ptr->getCalificacion() == calificacion) {
            std::cout << ptr->str() << std::endl;
            count++;
        }
    }
    std::cout << "Total = " << count << std::endl;
}

void Polimorfismo::reporteGenero(const std::string& genero) {
    int count = 0;
    for (const auto& ptr : arrPtrVideos) {
        if (ptr->getGenero() == genero) {
            std::cout << ptr->str() << std::endl;
            count++;
        }
    }
    std::cout << "Total = " << count << std::endl;
}

void Polimorfismo::reporteInventario() {
    int peliculas = 0, series = 0;
    for (const auto& ptr : arrPtrVideos) {
        std::cout << ptr->str() << std::endl;
        if (dynamic_cast<Pelicula*>(ptr)) {
            peliculas++;
        } else if (dynamic_cast<Serie*>(ptr)) {
            series++;
        }
    }
    std::cout << "Peliculas = " << peliculas << std::endl;
    std::cout << "Series = " << series << std::endl;
}

void Polimorfismo::reportePeliculas() {
    int count = 0;
    for (const auto& ptr : arrPtrVideos) {
        if (dynamic_cast<Pelicula*>(ptr)) {
            std::cout << ptr->str() << std::endl;
            count++;
        }
    }
    if (count == 0) {
        std::cout << "No series" << std::endl;
    } else {
        std::cout << "Total Peliculas = " << count << std::endl;
    }
}

void Polimorfismo::reporteSeries() {
    int count = 0;
    for (const auto& ptr : arrPtrVideos) {
        if (dynamic_cast<Serie*>(ptr)) {
            std::cout << ptr->str() << std::endl;
            count++;
        }
    }
    if (count == 0) {
        std::cout << "No series" << std::endl;
    } else {
        std::cout << "Total Series = " << count << std::endl;
    }
}
