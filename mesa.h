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
	int salida;
	int jugadorAnteriorHaPasado;

private:

	void iniciarPozo();
	void repartirFicha();
	void primeraTirada();
	Ficha* cogerFicha();
	

public:

	Mesa();
	int obtenerExtremo1();
	int obtenerExtremo2();
	void cogerFichaJ1();
	void cogerFichaJ2();
	int fichasJ1();
	int fichasJ2();
	void setQuienSale(int salida);
	int getQuienSale();
	void inicializar();
	int getContaPozo();
	void clonarMesa(Mesa const  &mesa);
	void ponerFicha(Ficha* ficha);
	Mesa * jugarPartida();
	vector<Ficha*> getFichas1();
	vector<Ficha*> getFichas2();
	void imprimirEstado();
	
};