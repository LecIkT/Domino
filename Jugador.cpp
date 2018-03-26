#include "Jugador.h"

Jugador::Jugador()
{
	Ficha nuevaFicha;
	for (int i = 0; i < 28; i++)
		listaFichas[i] = nuevaFicha;
	contadorJugador = 0;
	numeroMayor = -1; //No existe doble
	dobleMayor = -1; //No existe doble 
	posMayor = 0;
}

void Jugador::setFicha(Ficha nuevaFicha)
{
	listaFichas[contadorJugador] = nuevaFicha;
	contadorJugador++;
}

void Jugador::comprobarMayor()
{
	for (int i = 0; i < contadorJugador; i++)
	{
		if (listaFichas[i].obtenerValor1() == listaFichas[i].obtenerValor2())
		{
			if (dobleMayor < listaFichas[i].obtenerValor1())
			{
				posDob = i;
				dobleMayor = listaFichas[i].obtenerValor1();
			}
		}
		int numMayor = listaFichas[i].obtenerValor1() + listaFichas[i].obtenerValor2();
		if (numeroMayor < numMayor)
		{
			posMayor = i;
			numeroMayor = numMayor;
		}
	}
}

int Jugador::getNumeroMayor()
{
	return numeroMayor;
}

int Jugador::getDobleMayor()
{
	return dobleMayor;
}

int Jugador::getPosMayor()
{
	return posMayor;
}

int Jugador::getPosDob()
{
	return posDob;
}


Ficha Jugador::getFicha(int numero)
{
	Ficha temp = listaFichas[numero];
	borrarFicha(numero);
	return temp;
}

void Jugador::aumentarContador()
{
	contadorJugador++;
}

void Jugador::borrarFicha(int posicion)
{
	for (int i = posicion; i < contadorJugador-1; i++)
	{
		Ficha aux = listaFichas[i];
		listaFichas[i] = listaFichas[i + 1];
		listaFichas[i + 1] = aux;
	}
	contadorJugador--;
}

int Jugador::getContador()
{
	return contadorJugador;
}

Jugador::~Jugador()
{
}
