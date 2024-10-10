#include "Game.h"
#include "utils.h"

Game::Game() {
	
}

void Game::drawBorder()
{

	for(int i=minX; i<=limitX;i++)
	{
		for(int j=minY;j<=limitY;j++)
		{
			if( (i == minX) || (i == limitX) || //Magic number // bad practice
			   (j == limitY) || (j==minY))
			{
				
				gotoxy(i,j);
				textcolor(BLUE );
				cout<<char(254);
			}
		}
	}
}

void Game::run()
{
	
	 
	drawBorder();
	while(_isWindowOpen)
	{
		processEvent();
		update();
		clean();
		render();
		Sleep(1);
	}
}

void Game::update()
{
	//update entidades
	//cout<<"update"<<endl;
	_player.update();
	_enemigo.update();
}

void Game::processEvent()
{
	if(kbhit())//detectamos que se ha tocado una tecla
	{
		int tecla = getch(); // guardamos la tecla (valor numerico)
		switch(tecla)
		{
		case 27://ESC
			_isWindowOpen = false;
			break;
		}
		gotoxy(110,27);
		cout<<"   ";
		textcolor(LIGHTRED);
		gotoxy(110,27);
		cout<<tecla;
		//cout<<"se toco una tecla"<<endl;
	}
	//procesar evento de teclados, mouse etc
	_player.processEvent();

	
	//cout<<"processEvent"<<endl;
}

void Game::render()
{
	//dibujar en pantalla
	_player.render();
	_enemigo.render();
	//cout<<"render"<<endl;
}

void Game::clean()
{
	// limpiar}
	//cout<<"clean"<<endl;
}
