#include "jugador.h"

Jugador::Jugador()
{
	contadorJugador = 0;
}

void Jugador::setFicha(Ficha* nuevaFicha)
{
	listaFichas[contadorJugador] = nuevaFicha;
	contadorJugador++;
}


Ficha* Jugador::getFichaMayor()
{
	Ficha* mayor = listaFichas[0];

	for (int i = 1; i < contadorJugador; i++)
	{
		Ficha* ficha = listaFichas[i];

		if (ficha->puntuacion() > mayor->puntuacion())
		{
			mayor = ficha;
		}
	}

	return mayor;
}

Ficha* Jugador::getDobleMayor()
{
	Ficha* mayor = nullptr;

	for (int i = 0; i < contadorJugador; i++)
	{
		Ficha* ficha = listaFichas[i];

		if (ficha->esDoble())
		{
			if (!mayor) 
				mayor = ficha;
			else
			{
				if (mayor->puntuacion() < ficha->puntuacion())
					mayor = ficha;
			}
		}
	}

	return mayor;
}

int Jugador::getPosMayor()
{
	return posMayor;
}

int Jugador::getPosDob()
{
	return posDob;
}


void Jugador::soltarFicha(Ficha* ficha)
{
	for (int i = 0; i < contadorJugador; i++)
	{
		if (listaFichas[i] == ficha)
		{
			borrarFicha(i);
		}
	}
}

void Jugador::aumentarContador()
{
	contadorJugador++;
}

void Jugador::borrarFicha(int posicion)
{
	contadorJugador--;

	for (int i = posicion; i < contadorJugador; i++)
	{
		Ficha* aux = listaFichas[i];
		listaFichas[i] = listaFichas[i + 1];
		listaFichas[i + 1] = aux;
	}
	
}

int Jugador::getContador()
{
	return contadorJugador;
}

void Jugador::imprimir()
{
	for (int i = 0; i < contadorJugador; i++)
	{
		listaFichas[i]->imprimir();
	}
}

Jugador::~Jugador()
{
}