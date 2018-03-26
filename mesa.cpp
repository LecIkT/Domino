#include "mesa.h"

Mesa::Mesa() {
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
	this->posicion = 0;

}

int Mesa::obtenerExtremo1() {

	return this->extremo1;
}

int Mesa::obtenerExtremo2() {

	return this->extremo2;
}

Ficha Mesa::cogerFicha() {
	if (posicion != 28)
	{
		Ficha aux = *this->pozo[this->posicion];
		this->posicion++;
		return aux;
	}
	else
	{
		Ficha nada(-1, -1);
		return nada;
	}
}

int Mesa::comprobarFicha(Jugador jugador)
{
	//Comprobamos las fichas del jugador 
	for (int i = 0; i < jugador.getContador(); i++)
	{
		int valor1 = jugador.getFicha(i).obtenerValor1();
		int valor2 = jugador.getFicha(i).obtenerValor2();

		if (valor1 == obtenerExtremo1())
		{
			return (i);
		}
		else if (valor1 == obtenerExtremo2())
		{
			return (i);
		}
		else if (valor2 == obtenerExtremo1())
		{
			return (i);
		}
		else if (valor2 == obtenerExtremo2())
		{
			return (i);
		}
	}
	//Si sale del bucle es que no ha encontrado coincidencias
	jugador.setFicha(cogerFicha());
	return -1;
}

void Mesa::ponerFicha(Ficha ficha)
{
	if (obtenerExtremo1() > 6 || obtenerExtremo1() < 0) //No hay ninguna ficha en la mesa
	{
		extremo1 = ficha.obtenerValor1();
		extremo2 = ficha.obtenerValor2();
	}
}