#include "jugador.h"

Jugador::Jugador()
{
	contadorJugador = 0;
}

void Jugador::setFicha(Ficha* nuevaFicha)
{
	if (nuevaFicha == nullptr)
	{
		return;
	}
	
	listaFichas[contadorJugador] = nuevaFicha;
	contadorJugador++;
}

vector<Ficha*> Jugador::getFichas(int extremo1, int extremo2)
{
	//Devuelve las fichas que coinciden con los extremos
	vector<Ficha*> posibleJugada;

	for (int i = 0; i < contadorJugador; i++)
	{
		if (extremo1 == listaFichas[i]->obtenerValor1() || extremo1 == listaFichas[i]->obtenerValor2() || extremo2 == listaFichas[i]->obtenerValor1() || extremo2 == listaFichas[i]->obtenerValor2())
		{
			posibleJugada.push_back( listaFichas[i] );
		}

	}
	return posibleJugada;
	
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

int Jugador::fichasRestantes()
{
	return this->contadorJugador;
}

void Jugador::soltarFicha(Ficha* ficha)
{
	int encontrado = -1;
	for (int i = 0; i < contadorJugador; i++)
	{
		if (listaFichas[i] == ficha)
		{
			encontrado = i;
		}
	}
	if (encontrado != -1) {
		borrarFicha(encontrado);
	}
	else
		cout << "HOLA ";
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

Jugador* Jugador::clonarJugador()
{
	Jugador *J1 = new Jugador;

	J1->contadorJugador = this->contadorJugador;

	for (int i = 0; i < 28; i++)
	{
		J1->listaFichas[i] = this->listaFichas[i];
	}

	return J1;
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