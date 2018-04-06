#pragma once
#include "iostream"
using namespace std;
class Ficha
{
	//Atributos privados por defecto. Esta clase sirve para crear ambos valores de las fichas
	int valor1;//Valor de arriba de la ficha
	int valor2;//Valor de abajo de la ficha
	bool usada;
public:

	Ficha();//Contructor por defecto;
	Ficha(int valor1, int valor2);//Constructor por valores
	int obtenerValor1();
	int obtenerValor2();
	bool esDoble();
	int puntuacion();
	void marcarUsada();
	void noUsada();
	void imprimir();
	~Ficha();//Destructor
};