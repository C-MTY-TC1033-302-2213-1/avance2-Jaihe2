/*
Nombre: Jaime Hernández González
Carrera: ITC
Matrícula: A00840312
Fecha: 20/05/2024
*/
#include "Polimorfismo.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Video.h"
using namespace std;

Polimorfismo::Polimorfismo(){
    for(int index = 0;  index < MAX_VIDEOS; index++) {
        arrPtrVideos[index] = nullptr;
    }
    cantidad = 0;
}

    void Polimorfismo::setPtrVideo(int index, Video *video){
        if (index >=0 && index < cantidad){
            arrPtrVideos[index] = video;
        }
    }

    void Polimorfismo::setCantidad(int _cantidad){
        if (_cantidad >=0 && _cantidad <= MAX_VIDEOS) {
            cantidad = _cantidad;
        }
    }

    Video* Polimorfismo::getPtrVideo (int index){
        if (index >= 0 && index < cantidad) {
            return arrPtrVideos[index];
        }

        return nullptr;
    }

    int Polimorfismo::getCantidad(){
        return cantidad;
    }

    void Polimorfismo::reporteInventario(){
        int contPeliculas, contSeries;
        contPeliculas = 0;
        contSeries = 0; 

        for (int index = 0; index < cantidad; index++){
            cout << arrPtrVideos[index]->str() << endl;
            
            if (typeid (*arrPtrVideos[index]) == typeid(Pelicula)){
                contPeliculas++;
            }
            else if (typeid (*arrPtrVideos[index]) == typeid(Serie)){
                contSeries++;
            } 
        }
        cout<< "Peliculas = " << contPeliculas << endl;
        cout << "Series = " << contSeries << endl;
    }

    void Polimorfismo::reporteCalificacion(double _calificacion){
        int total;

        total = 0;

        for (int index = 0; index < cantidad; index++){
            if (arrPtrVideos[index]->getCalificacion() == _calificacion){
                cout << arrPtrVideos[index]->str() << endl;
                total++;
            }
        }
        cout << "Total = " <<  total << endl;
    }

    void Polimorfismo::reporteGenero(string _genero){
        int total = 0; 

        for (int index = 0; index < cantidad; index++) {
            if (arrPtrVideos[index]->getGenero() == _genero){
                cout << arrPtrVideos[index]->str() << endl;
                total++;
            }
        }
        cout << "Total = " <<  total << endl;
    }

    void Polimorfismo::reportePeliculas() {
        int totalPeliculas = 0; 

        for (int index = 0; index < cantidad; index++) {
            if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)) {
                cout << arrPtrVideos[index]->str() << endl;
                totalPeliculas++;
                }
        }
        if (totalPeliculas > 0) {
            cout << "Total Peliculas = " << totalPeliculas << endl;
            } else {
            cout << "No peliculas" << endl;
        }
    }

    void Polimorfismo::reporteSeries() {
        int totalSeries = 0; 

        for (int index = 0; index < cantidad; index++) {
            if (typeid(*arrPtrVideos[index]) == typeid(Serie)) {
                cout << arrPtrVideos[index]->str() << endl;
                totalSeries++;
            }
        }

        if (totalSeries > 0) {
            cout << "Total Series = " << totalSeries << endl;
            } else {
            cout << "No series" << endl;
        }
        cout << endl;
    }
    
    void Polimorfismo::leerArchivo (string nombre){
        Serie *arrPtrSeries[50];
        Pelicula *arrPtrPeliculas[50];
        Episodio episodio;
        fstream entrada;
        string row[7];
        string line, word;
        int cantidadPeliculas = 0;
        int cantidadSeries = 0;
        int iR = 0, index;
        double promedio;

        entrada.open (nombre, ios::in);

        if (!entrada.is_open()) {
            cerr << "Error al abrir el archivo!" << endl;
            return;
        }

        while(getline(entrada, line)) { 
            stringstream s(line);
            iR = 0;

            while (getline(s, word, ',')) {
                row[iR++] = word;
            } 

            if (row[0] == "P"){
                arrPtrPeliculas[cantidadPeliculas] = new Pelicula (row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
                cantidadPeliculas++; 
            }
            else if (row[0] == "S"){
                arrPtrSeries[cantidadSeries] = new Serie (row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
                cantidadSeries++;  
            }
            else if (row[0] == "E"){
                index = stoi(row[1]) - 500;
                arrPtrSeries[index]->agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
            }
        }

            entrada.close();

            for (int index  = 0; index < cantidadSeries; index++){
                promedio = arrPtrSeries[index]->calculaPromedio(); 
                arrPtrSeries[index]->setCalificacion(promedio);
                arrPtrSeries[index]->calculaDuracion();      
                arrPtrVideos[cantidad++] = arrPtrSeries[index];
            }

            for (int index = 0; index < cantidadPeliculas; index++){
                arrPtrVideos[cantidad++]= arrPtrPeliculas[index];
            }
        }