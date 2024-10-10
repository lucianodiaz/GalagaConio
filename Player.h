#ifndef PLAYER_H
#define PLAYER_H

#include <conio2.h>
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

class Player {
public:
	
	Player();
	Player(int x, int y);
	
	void update();
	void processEvent();
	void render();
	
private:
	//pos del jugador en pantalla
	int _x;
	int _y;
	
	int _life = 3;
};

#endif

