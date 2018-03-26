#pragma once
#include "iostream"
#include "ficha.h"
#include <ctime>
#include <cstdlib>
#include "Jugador.h"
#define NUMEROMAX 7
using namespace std;

class Mesa
{
	//Atributos privados por defecto
	Ficha* pozo[28];
	int extremo1;
	int extremo2;
	int posicion;

public:

	Mesa();
	int obtenerExtremo1();
	int obtenerExtremo2();
	Ficha cogerFicha();
	int comprobarFicha(Jugador jugador);
	void ponerFicha(Ficha ficha);
};