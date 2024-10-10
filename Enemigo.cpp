#include "Enemigo.h"
#include "utils.h"

Enemigo::Enemigo() {
	srand(time(0));
	_x = 30;
	_y = 10;
	move();
}

void Enemigo::setInitialPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Enemigo::update()
{
	//Guardamos posiciones antes de actualizar a las nuevas posiciones

	if(timer >= 30)
	{
		_lastX = _x;
		_lastY = _y;
		move();
		timer = 0;
	}
	
	timer++;
	//gotoxy(limitX+2,minY+3);
	//cout<<"X: "<<"   "<<" Y: "<<"   ";
	
	//gotoxy(limitX+2,minY+3);
	//cout<<"X: "<<_x<<" Y: "<<_y;
}

void Enemigo::render()
{
	borrar();
	gotoxy(_x,_y);
	cout<<char(157);
}

void Enemigo::borrar()
{
	gotoxy(_lastX,_lastY);
	cout<<" ";
}

int Enemigo::randomDirection()
{
	return (rand() % 3) - 1; // Genera -1, 0 o 1
}

void Enemigo::move()
{
	int newValueX = randomDirection();
	int newValueY = randomDirection();
	
	//gotoxy(limitX+2,minY+4);
	//cout<<"RX: "<<"  "<<" RY: "<<"  ";
	//gotoxy(limitX+2,minY+4);
	//cout<<"RX: "<<newValueX<<" RY: "<<newValueY;

	_x += newValueX;

	_y += newValueY;
	
	if(_x >= limitX)
	{
		_x = limitX-2;
	}
	else if(_x <= minX)
	{
		_x = minX +1;
	}
	
	if(_y <= minY)
	{
		_y = minY+1;
	}
	else if(_y >= limitY)
	{
		_y = limitY-2;
	}

}

