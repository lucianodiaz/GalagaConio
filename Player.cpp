#include "Player.h"
#include "utils.h"

Player::Player(int x,int y) {

}

Player::Player()
{
	_x = 5;
	_y = 3;
}


void Player::update()
{

	string lifeText = _life > 0 ? ("vidas: "+ to_string(_life)) : "Se murio"; //Comparacion ternaria
	//Es lo mmismo que hacer un if
	gotoxy(limitX+2,minY);
	cout<<lifeText;

	gotoxy(_x,_y);
	cout<<" ";
}

void Player::render()
{
	textcolor(LIGHTGREEN);
	gotoxy(_x,_y);
	cout<<char(169);
}


void Player::processEvent()
{
	if(kbhit())//detectamos que se ha tocado una tecla
	{
		//borrar
		gotoxy(_x,_y);
		cout<<" ";
		//clean
		int tecla = getch(); // guardamos la tecla (valor numerico)
		switch(tecla)
		{
		case 72:
		case 119://arriba
			//_isWindowOpen = false;
			if(_y-2 > minY-1)
			{
				_y -=1;
			}
			break;
		case 80:
		case 115://anajo
			if(_y < limitY-1)
			{
				_y +=1;
			}
			_life -=1;
			break;
		case 77:
		case 100:// derecha
			if(_x < limitX-1)
			{
			  _x += 1;
			}
			break;
		case 75:
		case 97://izquierda
			if(_x-2 > minX-1)
			{
				_x -=1;
			}
			break;
		}

	}
}
