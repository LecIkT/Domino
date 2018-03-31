#include "iostream"
#include "ficha.h"
#include "mesa.h"
#include "jugador.h"
#include <ctime>
#include <cstdlib>
#define NUMEROMAX 7
using namespace std;

int main()
{
	Mesa* mesa[27];

	mesa[0] = new Mesa;
	mesa[0]->inicializar();
	mesa[0]->imprimirEstado();
}