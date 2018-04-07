#include "ficha.h"

Ficha::Ficha() {

	this->valor1 = 0;
	this->valor2 = 0;
}
Ficha::Ficha(int valor1, int valor2) {//Constructor por valores

	this->valor1 = valor1;
	this->valor2 = valor2;
}

int Ficha::obtenerValor1() {

	return this->valor1;
}

int Ficha::obtenerValor2() {

	return this->valor2;
}

void Ficha::imprimir() {

	cout << this->valor1 << "/" << this->valor2 << endl;
}

bool Ficha::esDoble()
{
	return valor1 == valor2;
}

int Ficha::puntuacion()
{
	return valor1 + valor2;
}

Ficha::~Ficha() {

}