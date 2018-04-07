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
	Mesa * mesa = new Mesa;
	
	mesa->inicializar();
	mesa->imprimirEstado();
	
	Mesa * mesaGanadora = mesa->jugarPartida();

	
	
		
}
		