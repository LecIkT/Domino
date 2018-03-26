#include "iostream"
#include "ficha.h"
#include <ctime>
#include <cstdlib>
#include "mesa.h"
#include "Jugador.h"
#define NUMEROMAX 7
using namespace std;

int main()
{
	srand((unsigned)time(NULL)); // inicializar la semilla con el tiempo 
	int contador = 0, A = 0, B = 27;//Variables para el srand

	int contaValor1, contaValor2;
	Ficha *misFichas[28];//Primer array para crear mis fichas
	Ficha *pozo[28];

	//Con este bucle creo todas mis fichas y las introduzco en el array misFichas
	for (contaValor1 = 0; contaValor1 < NUMEROMAX; contaValor1++)
	{
		for (contaValor2 = contaValor1; contaValor2 < NUMEROMAX; contaValor2++)
		{
			misFichas[contador] = new Ficha(contaValor1, contaValor2);
			//misFichas[contador]->imprimir();
			contador++;
		}
	}

	//Bucle para rellenar mi array de pozo
	for (int contaPozo = 0; contaPozo < 28; contaPozo++)
	{
		int indice = 0;

		do
		{
			indice = A + (rand() % (B + 1 - A));

		} while (misFichas[indice] == NULL);

		pozo[contaPozo] = misFichas[indice];
		misFichas[indice] = NULL;

		//pozo[contaPozo]->imprimir();
	}

	Mesa mesa;
	Jugador jugador1, jugador2;
	int turno = 1; //Jugador 1 = 1, jugador 2 = -1
	int posFicha = 0;

	//Repartir fichas
	int numeroFichasARepartir = rand() % 14 + 1;

	for (int i = 0; i < numeroFichasARepartir; i++)
	{
		Ficha nuevaFicha = mesa.cogerFicha();
		jugador1.setFicha(nuevaFicha);
		nuevaFicha = mesa.cogerFicha();
		jugador2.setFicha(nuevaFicha);
	}

	//Comprobamos quien empieza
	jugador1.comprobarMayor();
	jugador2.comprobarMayor();

	int numDob1 = jugador1.getDobleMayor();
	int numDob2 = jugador2.getDobleMayor();

	if (numDob1 > numDob2)
	{
		turno = 1;
		posFicha = jugador1.getPosDob();
	}
	else if (numDob1 == numDob2) //No hay dobles
	{
		int numMay1 = jugador1.getNumeroMayor();
		int numMay2 = jugador2.getNumeroMayor();
		if (numMay1 > numMay2)
		{
			turno = 1;
			posFicha = jugador1.getPosMayor();
		}
		else
		{
			turno = -1;
			posFicha = jugador2.getPosMayor();
		}
	}
	else
	{
		turno = -1;
		posFicha = jugador2.getPosDob();
	}
	
	//Empieza el juego
	if (turno == 1)
	{
		mesa.ponerFicha(jugador1.getFicha(posFicha));
	}
	else
	{
		mesa.ponerFicha(jugador2.getFicha(posFicha));
	}
	int contadorTurnos = 0;
	while (jugador1.getContador() != 0 && jugador2.getContador() != 0 && contadorTurnos < 100) //Lo de los turnos no sigue una logica
	{
		Ficha aux(-1,-1);
		int pos = 0;
		if (turno == 1) //Le toca al jugador 1
		{
			pos = mesa.comprobarFicha(jugador1);
			if(pos != -1)
				aux = jugador1.getFicha(pos);
		}
		else //Le toca al jugador 2
		{
			pos = mesa.comprobarFicha(jugador2);
			if(pos != -1)
				aux = jugador2.getFicha(pos);
		}
		if (aux.obtenerValor1() != -1)
			mesa.ponerFicha(aux);
		turno *= (-1);
		contadorTurnos++;
	}

	turno *= (-1);
	if (contadorTurnos == 100)
		cout << "Empate" << endl;
	else if (turno == 1)
		cout << "Gana el jugador 1" << endl;
	else
		cout << "Gana el jugador 2" << endl;
}