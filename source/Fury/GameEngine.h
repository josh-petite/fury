#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include "Player.h"
#include "BattleEngine.h"
#include "PersistPlayer.h"

using namespace std;
using std::tr1::shared_ptr;

class GameEngine
{
public:
	GameEngine(void);
	~GameEngine(void);
	void Init(shared_ptr<Player> player);
	void Loop();	

private:
	void Cleanup();
	void EvaluateInput(std::string input);
	void EvaluatePlayerStatus();
	void EvaluateGameState();

	shared_ptr<Player> _player;
	shared_ptr<BattleEngine> _battleEngine;
	shared_ptr<PersistPlayer> _persistPlayer;
};

