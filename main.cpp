/*
Nombre: Jaime Hernández González
Carrera: ITC
Matrícula: A00840312
Fecha: 20/05/2024
*/

#include <iostream>
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"

using namespace std;

int main(){
    Video video("01", "Mavericks", 90, "Deportes", 100);
    Pelicula pelicula1("Batman", "The Dark Knight", 81, "Accion", 180, 2);
    Pelicula peli("Simios", "Ceasear", 190, "Accion", 100, 6);

    Serie serie1;
    Episodio episodio1("1.Uno", 53, 100);
    Episodio episodio2("2.Dos", 78, 100);

    cout << pelicula1.str() <<endl;
    cout << peli.str() << endl;

    serie1.setID("11234");
    serie1.setTitulo("Invencible");
    serie1.setDuracion(214);
    serie1.setGenero("superheroes");
    serie1.setCalificacion(90);
    serie1.agregaEpisodio(episodio1);
    serie1.agregaEpisodio(episodio2);
    serie1.setCalificacion(serie1.calculaPromedio());
    
return 0;    
}