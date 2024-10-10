#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <conio2.h>
#include <windows.h>
#include "Player.h"
#include "Enemigo.h"
using namespace std;

class Game 
{

public:
	Game();
	
	void run();
private:
	
	void drawBorder();
	
	void processEvent();
	
	void update();
	
	void render();
	void clean();
	
	bool _isWindowOpen=true;
	
	Player _player;
	
	Enemigo _enemigo;
};

#endif

