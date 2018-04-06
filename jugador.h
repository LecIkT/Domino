#include "ficha.h"
#include <vector>
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
	vector<Ficha*> getFichas(int extremo1, int extremo2);
	int fichasRestantes();
	void soltarFicha(Ficha* ficha);
	void borrarFicha(int posicion);
	Jugador * clonarJugador();
	void imprimir();
	~Jugador();
};