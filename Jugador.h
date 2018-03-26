#include "ficha.h"
#pragma once

class Jugador
{
	Ficha listaFichas[28];
	int contadorJugador;
	int numeroMayor;
	int dobleMayor;
	int posMayor;
	int posDob;

public:
	Jugador();
	void setFicha(Ficha nuevaFicha);
	void comprobarMayor();
	int getNumeroMayor();
	int getDobleMayor();
	int getPosMayor();
	int getPosDob();
	Ficha getFicha(int numero);
	void aumentarContador();
	void borrarFicha(int posicion);
	int getContador();
	~Jugador();
};