#include "iostream"
#include "ficha.h"
#include "mesa.h"
#include "jugador.h"
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	Mesa* mesa[27];
	bool tablas = false;
	int jugadorAnteriorHaPasado = 0;

	mesa[0] = new Mesa;
	mesa[1] = new Mesa;
	mesa[1]->clonarMesa(*mesa[0]);
	mesa[0]->inicializar();
	mesa[0]->imprimirEstado();
	int i = 0;

	while (mesa[i]->fichasJ1() != 0 && mesa[i]->fichasJ2() != 0 && !tablas)
	{
		if (mesa[i]->getQuienSale() == 1)
		{
			vector<Ficha*> posiblejugada = (mesa[i]->getFichas2());
			cout << "Juega el jugador2" << endl << "Hay " << posiblejugada.size() << " jugadas posibles";
			//mesa[i]->imprimirEstado();
			for (int cont = 0; cont < posiblejugada.size(); cont++) {
				Ficha f = *posiblejugada.at(cont);
				f.imprimir();
			}

			if (posiblejugada.size() == 0)
			{
				if (mesa[i]->getContaPozo() >= 28)
				{
					jugadorAnteriorHaPasado++;
				}

				mesa[i]->cogerFichaJ2();
				cout << "Jug2 coge una del pozo";
			}
			else
			{
				jugadorAnteriorHaPasado = 0;
				cout << "Juga2 pone ficha: ";
				posiblejugada.at(0)->imprimir();
				mesa[i]->ponerFicha(posiblejugada.at(0));
			}

			mesa[i]->setQuienSale(2);
		}

		else
		{
			vector<Ficha*> posiblejugada = (mesa[i]->getFichas1());
			cout << "Juega el jugador1" << endl << "Hay " << posiblejugada.size() << " jugadas posibles";
			//mesa[i]->imprimirEstado();
			for (int cont = 0; cont < posiblejugada.size(); cont++) {
				Ficha f = *posiblejugada.at(cont);
				f.imprimir();
			}
			if (posiblejugada.size() == 0)
			{
				if (mesa[i]->getContaPozo() >= 28)
				{
					jugadorAnteriorHaPasado++;
				}

				mesa[i]->cogerFichaJ1();
				cout << "Jug1 coge una del pozo";
			}
			else
			{
				jugadorAnteriorHaPasado = 0;
				cout << "Juga1 pone ficha: ";
				posiblejugada.at(0)->imprimir();
				mesa[i]->ponerFicha(posiblejugada.at(0));
			}
			mesa[i]->setQuienSale(1);

		}
		if (jugadorAnteriorHaPasado == 2)
		{
			tablas = true;
		}
		mesa[i]->imprimirEstado();
	}

	if (mesa[i]->fichasJ1() == 0)
	{
		cout << "Gana jugador 1";

	}
	else if (mesa[i]->fichasJ2() == 0)
	{
		cout << "Gana jugador 2";
	}

	else if (tablas = true)
	{
		cout << "Tablas";
	}
		
}
		