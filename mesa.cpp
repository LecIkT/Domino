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
	Ficha aux = *this->pozo[this->posicion];
	this->posicion++;
	return aux;
}
