/*
Nombre: Jaime Hernández González
Carrera: ITC
Matrícula: A00840312
Fecha: 20/05/2024
*/

#include "Serie.h"

        Serie::Serie() : Video() {
            cantidad = 0;
        }
        
        Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion)
        :Video(_iD, _titulo, _duracion, _genero, _calificacion){
            cantidad = 0;
        }

        void Serie::setEpisodio (int posicion, Episodio episodio){
            if (posicion >= 0 && posicion < cantidad) {
                episodios[posicion] = episodio;
            }
        }
        void Serie::setCantidad (int _cantidad){
            cantidad = _cantidad;
        }
        Episodio Serie::getEpisodio(int posicion){
            Episodio epi; 
            if(posicion >= 0 && posicion < cantidad){
                return episodios[posicion];
            }

            return epi;
        }
        // Retornar el valor de atributo 
        int Serie::getCantidad(){
            return cantidad;
        }

        // Otros métodos 
        double Serie::calculaPromedio(){
            double acum = 0;

            for (int idex = 0; idex < cantidad; idex++){
                acum = acum + episodios[idex].getCalificacion(); 
            }
        
            if (cantidad > 0){
                return acum / cantidad;
        }
            else {
                return 0;
        }
    }

        void Serie::calculaDuracion() {
            int duracionTotal = 0;

             for (int index = 0; index < cantidad; index++) {
                duracionTotal += episodios[index].getTemporada();
            }

            duracion = duracionTotal; 
        }
        string Serie::str (){
            string str = Video::str() + " " + to_string(cantidad) + "\n";
            for (int index = 0; index < cantidad; index++){
            str += episodios[index].str() + "\n";
        }
        return str;
    }
        void Serie::agregaEpisodio (Episodio episodio) {
            if (cantidad < 5) {
                episodios[cantidad++] = episodio;
            }
        }