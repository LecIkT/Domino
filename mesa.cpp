#include "mesa.h"
#include "jugador.h"

Mesa::Mesa() {

	extremo1 = 0;
	extremo2 = 0;
	posicionMesa = 0;
	posicionPozo = 0;
	salida = 0;
	jugadorAnteriorHaPasado = 0;

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
	{
		cout << "Mesa:" << endl << "Sale jugador1:" << endl;
		jugador1->soltarFicha(salida);
		setQuienSale(1);
	}
		
	else
	{
		cout <<"Mesa:" << endl << "Sale jugador2:" << endl;
		jugador2->soltarFicha(salida);
		setQuienSale(2);
	}

	this->extremo1 = salida->obtenerValor1();
	this->extremo2 = salida->obtenerValor2();

	fichasMesa[posicionMesa] = salida;
	posicionMesa++;
	
}

void Mesa::setQuienSale(int salida)
{
	this->salida = salida;
}

int Mesa::getQuienSale()
{
	return this->salida;

}

vector<Ficha*> Mesa::getFichas1()
{
	return jugador1->getFichas(this->extremo1, this->extremo2);

}

vector<Ficha*> Mesa::getFichas2()
{
	return jugador2->getFichas(this->extremo1, this->extremo2);
}

void Mesa::inicializar()
{
	this->iniciarPozo();
	this->repartirFicha();
	this->primeraTirada();
}

void Mesa::ponerFicha(Ficha* ficha)
{
	if (ficha->obtenerValor1() == this->extremo1)
	{
		this->extremo1 = ficha->obtenerValor2();

	}

	else if (ficha->obtenerValor1() == this->extremo2)
	{
		this->extremo2 = ficha->obtenerValor2();

	}

	else if (ficha->obtenerValor2() == this->extremo1)
	{
		this->extremo1 = ficha->obtenerValor1();

	}

	else if (ficha->obtenerValor2() == this->extremo2)
	{
		this->extremo2 = ficha->obtenerValor1();

	}

	else
	{
		cout << "Poniendo ficha erronea";
		return;
	}
		
	if (this->getQuienSale() == 1)
	{
		jugador2->soltarFicha(ficha);
	}
	else
		jugador1->soltarFicha(ficha);

	fichasMesa[posicionMesa] = ficha;
	posicionMesa++;
}
int Mesa::fichasJ1()
{
	return jugador1->fichasRestantes();
}

int Mesa::fichasJ2()
{
	return jugador2->fichasRestantes();
}

int Mesa::obtenerExtremo1() {

	return this->extremo1;
}

int Mesa::obtenerExtremo2() {

	return this->extremo2;
}

void Mesa::cogerFichaJ1() {

	jugador1->setFicha(cogerFicha());
}

void Mesa::cogerFichaJ2() {

	jugador2->setFicha(cogerFicha());
}

int Mesa::getContaPozo()
{
	return this->posicionPozo;
}

void Mesa::clonarMesa(Mesa const &mesa) {

	for (int i = 0; i < 28; i++)
	{
		this->pozo[i] = mesa.pozo[i];
		this->fichasMesa[i] = mesa.fichasMesa[i];
	}

	this->jugador1 = mesa.jugador1->clonarJugador();
	this->jugador2 = mesa.jugador2->clonarJugador();
	this->extremo1 = mesa.extremo1;
	this->extremo2 = mesa.extremo2;
	this->posicionPozo = mesa.posicionPozo;
	this->posicionMesa = mesa.posicionMesa;
	this->salida = mesa.salida;
	this->jugadorAnteriorHaPasado = mesa.jugadorAnteriorHaPasado;
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
	for (int i = 0; i < posicionMesa; i++)
		fichasMesa[i]->imprimir();
		
	cout << "Jugador1: " << endl;
	jugador1->imprimir();

	cout << "Jugador2: " << endl;
	jugador2->imprimir();

}

Mesa * Mesa::jugarPartida()
{
	Mesa * siguienteMesa = new Mesa;
	Mesa * mesaGanadora = nullptr;

	//Si gana jugador1 se devuelve la mesa actual porque es la ganadora
	if (this->fichasJ1() == 0)
	{
		cout << "Jugador 1 gana" << endl;
		this->imprimirEstado();
		return this;
	}

	//Si gana jugador dos , devuelvo un nullptr porque no es valida y vuelvo al estado anterior
	if (this->fichasJ2() == 0)
	{
		return nullptr;
	}

	//Si es tablas , devuelvo un nullptr porque no es valida y vuelvo al estado anterior
	if (this->jugadorAnteriorHaPasado == 2)
	{
		return nullptr;
	}

	//Si la mesa actual el ultimo en poner ficha ha sido jugador 1, continua el jugador2
	if (this->getQuienSale() == 1)
	{
		vector<Ficha*> posiblejugada = (this->getFichas2());
		cout << "Juega el jugador2:" << endl << "Hay " << posiblejugada.size() << " jugadas posibles:" << endl;

		for (int cont = 0; cont < posiblejugada.size(); cont++) {

			Ficha f = *posiblejugada.at(cont);
			f.imprimir();
		}

		if (posiblejugada.size() == 0)
		{
			//Copiamos nuestra mesa en una mesa nueva, para no hacer modificaciones en la mesa actual (this)
			siguienteMesa->clonarMesa(*this);

			if (siguienteMesa->getContaPozo() >= 28)
			{
				siguienteMesa->jugadorAnteriorHaPasado++;
			}
			else
				//En la mesa nueva si se puede robo del pozo
				siguienteMesa->cogerFichaJ2();

			cout << "Jug2 coge una del pozo" << endl;

			//En la mesa nueva actualizo quien ha tirado el ultimo
			siguienteMesa->setQuienSale(2);
			//Y sobre la mesa con los cambios realizados ejecutas una nueva iteracion
			mesaGanadora = siguienteMesa->jugarPartida();
			//Si he robado y gano devuelvo la mesa ganadora 
			return mesaGanadora;

		}
		else
		{
			for (int cont = 0; cont < posiblejugada.size(); cont++) {

				//Copia mesa para no hacer cambios
				siguienteMesa->clonarMesa(*this);
				siguienteMesa->jugadorAnteriorHaPasado = 0;

				cout << "Juga2 pone ficha: ";
				posiblejugada.at(cont)->imprimir();
				//Pongo la ficha en mi mesa nueva
				siguienteMesa->ponerFicha(posiblejugada.at(cont));
				//Actualizo el ultimo jugador que ha puesto ficha
				siguienteMesa->setQuienSale(2);
				//Creo otra iteracion 
				mesaGanadora = siguienteMesa->jugarPartida();

				//Si la mesa es buena devuelvo esta mesa como ganadora y sino es bueno me quedo dentro del bucle
				// y pruebo la siguiente posibilidad
				if (mesaGanadora)
				{
					return mesaGanadora;
				}
			}
		}
	}

	else
	{
		vector<Ficha*> posiblejugada = (this->getFichas1());
		cout << "Juega el jugador1" << endl << "Hay " << posiblejugada.size() << " jugadas posibles:" << endl;
		
		for (int cont = 0; cont < posiblejugada.size(); cont++) {

			Ficha f = *posiblejugada.at(cont);
			f.imprimir();
		}

		if (posiblejugada.size() == 0)
		{
			siguienteMesa->clonarMesa(*this);

			if (siguienteMesa->getContaPozo() >= 28)
			{
				siguienteMesa->jugadorAnteriorHaPasado++;
			}
			else
				siguienteMesa->cogerFichaJ1();

			cout << "Jug1 coge una del pozo" << endl;
			siguienteMesa->setQuienSale(1);
			mesaGanadora = siguienteMesa->jugarPartida();
			return mesaGanadora;

		}
		else
		{
			for (int cont = 0; cont < posiblejugada.size(); cont++) {

				siguienteMesa->clonarMesa(*this);
				siguienteMesa->jugadorAnteriorHaPasado = 0;

				cout << "Juga1 pone ficha: ";
				posiblejugada.at(cont)->imprimir();
				siguienteMesa->ponerFicha(posiblejugada.at(cont));
				siguienteMesa->setQuienSale(1);

				mesaGanadora = siguienteMesa->jugarPartida();

				if (mesaGanadora)
				{
					return mesaGanadora;
				}
			}
		}
	}

	return nullptr;
}
