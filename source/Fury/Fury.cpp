// Fury.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameEngine.h"
#include "Player.h"
#include <windows.h>

void DisplaySplashMessage();

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DisplaySplashMessage();

	auto player = make_shared<Player>("Josh", 10, 1, 1, 1);
	player->Init();

	auto gameEngine = make_shared<GameEngine>();
	gameEngine->Init(player);
	gameEngine->Loop();

	return 0;
}

void DisplaySplashMessage()
{
	cout << "********************" << endl;
	cout << "*       FURY       *" << endl;
	cout << "*       v1.0       *" << endl;
	cout << "********************" << endl;
	cout << endl;
}

