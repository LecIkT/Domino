#include "ficha.h"
#pragma once

class Jugador
{
	Ficha* listaFichas[28];
	int contadorJugador;
	int numeroMayor;
	int dobleMayor;
	int posMayor;
	int posDob;

public:
	Jugador();
	void setFicha(Ficha* nuevaFicha);
	Ficha* getFichaMayor();
	Ficha* getDobleMayor();
	int getPosMayor();
	int getPosDob();
	void soltarFicha(Ficha* ficha);
	void aumentarContador();
	void borrarFicha(int posicion);
	int getContador();
	void imprimir();
	~Jugador();
};