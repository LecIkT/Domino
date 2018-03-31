#include "ficha.h"
#pragma once

class Jugador
{
	Ficha* listaFichas[28];
	int contadorJugador;

public:
	Jugador();
	void setFicha(Ficha* nuevaFicha);
	Ficha* getFichaMayor();
	Ficha* getDobleMayor();
	void soltarFicha(Ficha* ficha);
	void borrarFicha(int posicion);
	void imprimir();
	~Jugador();
};