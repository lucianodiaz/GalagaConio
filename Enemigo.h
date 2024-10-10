#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <iostream>
#include <conio2.h>


using namespace std;
//Vamos a definir que el enemigo por ahora se mueva aleatoriamente 1 pixel en x e y (puede ser negativo o positivo)
class Enemigo {
public:
	Enemigo();
	
	void update();
	void render();
	
	void setInitialPosition(int x, int y);
	
protected:
	//Metodos protegidos de la clase enemigo
	void move();
	
	int randomDirection();
	
	int timer=0;
private:
	
	//Metodos privados
	void borrar();
	
	//pos del enemigo en pantalla
	int _lastX;//Guardamos los valores de x antes de actualizarlos por los nuevos
	int _lastY;//Guardamos los valores de x antes de actualizarlos por los nuevos
	//Esto lo hacemos para borrar caracteres en pantalla
	
	int _x;//estos valores son los valores actuales de posicion
	int _y;
	
	int _life = 2;
	
};

#endif

