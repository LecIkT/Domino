#pragma once
#include "iostream"
#include "ficha.h"
#include "jugador.h"
#include <ctime>
#include <cstdlib>
#define NUMEROMAX 7
#define FICHAS_INICIALES 7
using namespace std;

class Mesa
{
	//Atributos privados por defecto
	Ficha* pozo[28];
	Ficha* fichasMesa[28];
	Jugador* jugador1;
	Jugador* jugador2;
	int extremo1;
	int extremo2;
	int posicionPozo;
	int posicionMesa;

private:

	void iniciarPozo();
	void repartirFicha();
	void primeraTirada();

public:

	Mesa();
	int obtenerExtremo1();
	int obtenerExtremo2();
	void inicializar();
	void imprimirEstado();
	Ficha* cogerFicha();
	void ponerFicha(Ficha* ficha);
};