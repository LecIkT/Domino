#include "mesa.h"
#include "jugador.h"

Mesa::Mesa() {

	extremo1 = 0;
	extremo2 = 0;
	posicionMesa = 0;
	posicionPozo = 0;

	jugador1 = new Jugador;
	jugador2 = new Jugador;
}

void Mesa::iniciarPozo()
{
	srand((unsigned)time(NULL)); // inicializar la semilla con el tiempo 
	int contador = 0, A = 0, B = 27;//Variables para el srand

	int contaValor1, contaValor2;
	Ficha *misFichas[28];//Primer array para crear mis fichas

						 //Con este bucle creo todas mis fichas y las introduzco en el array misFichas
	for (contaValor1 = 0; contaValor1 < NUMEROMAX; contaValor1++)
	{
		for (contaValor2 = contaValor1; contaValor2 < NUMEROMAX; contaValor2++)
		{
			misFichas[contador] = new Ficha(contaValor1, contaValor2);
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

		this->pozo[contaPozo] = misFichas[indice];
		misFichas[indice] = NULL;
	}
	this->posicionPozo = 0;
}

void Mesa::repartirFicha() {

	for (int contador = 0; contador < FICHAS_INICIALES; contador++)
	{
		jugador1->setFicha(cogerFicha());
		jugador2->setFicha(cogerFicha());
	}
		
}

void Mesa::primeraTirada() {
	
	int jugadorQueSale = 0;
	Ficha* salida = nullptr;

	Ficha* doble1 = jugador1->getDobleMayor();
	Ficha* doble2 = jugador2->getDobleMayor();

	if (doble1 && doble2)
	{
		if (doble1->puntuacion() > doble2->puntuacion())
		{
			jugadorQueSale = 1;
			salida = doble1;
		}
			
		else
		{
			jugadorQueSale = 2;
			salida = doble2;
		}
			
	}
	else if (doble1)
	{
		jugadorQueSale = 1;
		salida = doble1;
	}
		

	else if (doble2)
	{
		jugadorQueSale = 2;
		salida = doble2;
	}
		

	else
	{
		doble1 = jugador1->getFichaMayor();
		doble2 = jugador2->getFichaMayor();

		if (doble1->puntuacion() > doble2->puntuacion())
		{
			jugadorQueSale = 1;
			salida = doble1;
		}
			
		else
		{
			jugadorQueSale = 2;
			salida = doble2;
		}
			
	}
		
	if (jugadorQueSale == 1)
		jugador1->soltarFicha(salida);
	else
		jugador2->soltarFicha(salida);

	this->extremo1 = salida->obtenerValor1();
	this->extremo2 = salida->obtenerValor2();

	fichasMesa[0] = salida;
	posicionMesa++;
}

void Mesa::inicializar()
{
	this->iniciarPozo();
	this->repartirFicha();
	this->primeraTirada();
}

void Mesa::ponerFicha(Ficha* ficha)
{
	
}

int Mesa::obtenerExtremo1() {

	return this->extremo1;
}

int Mesa::obtenerExtremo2() {

	return this->extremo2;
}

Ficha* Mesa::cogerFicha() {
	if (posicionPozo > 27)
		return nullptr;

	Ficha* aux = this->pozo[this->posicionPozo];
	this->posicionPozo++;
	return aux;
}

void Mesa::imprimirEstado()
{
	cout << "Mesa: " << endl;
	for (int i = 0; i < posicionMesa; i++)
		fichasMesa[i]->imprimir();
		
	cout << "Jugador1: " << endl;
	jugador1->imprimir();

	cout << "Jugador2: " << endl;
	jugador2->imprimir();

}
