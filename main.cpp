//
// main.cpp
// Tarea3 y Actividad Presencial 23/05/24
//
// Created by Ma. Guadalupe Roque Díaz de León on 23/05/24.
//
// Clases Base - Video - con método virtual str() para Polimorfismo
// Clases Derivadas - Pelicula, Serie
// Clase usada para composición - Episodio
// Arreglo de apuntadores
/*
Nombre:
Matricula:
Carrera:
Fecha:
- ¿Qué aprendí en el desarrollo de la clase Polimorfismo?
*/

#include <iostream>
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Polimorfismo.h"
#include <string>

using namespace std;

void polimorfismo(Polimorfismo inventario) {
    // Declaración de variables locales
    int opcion;
    double calificacion;
    string genero;

    cin >> opcion;

    switch (opcion) {
        case 1:
            cin >> calificacion;
            inventario.reporteCalificacion(calificacion);
            break;
        case 2:
            cin >> genero;
            inventario.reporteGenero(genero);
            break;
        case 3:
            inventario.reporteInventario();
            break;
        case 4:
            inventario.reportePeliculas();
            break;
        case 5:
            inventario.reporteSeries();
            break;
        default:
            cout << "Error\n";
            break;
    }
}

int main() {
    // Declaracion de objetos
    Polimorfismo neflix;
    int opcion;

    // leer la opcion
    cin >> opcion;

    switch (opcion) {
        case 1:
            neflix.leerArchivo("Inventario1.csv");
            polimorfismo(neflix);
            break;
        case 2:
            neflix.leerArchivo("Inventario2.csv");
            polimorfismo(neflix);
            break;
        default:
            cout << "incorrecta" << endl;
    }

    return 0;
}
