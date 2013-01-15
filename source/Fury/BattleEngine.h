#pragma once

#include <memory>
#include <iostream>
#include <map>

using std::tr1::shared_ptr;

class Enemy;
class Player;
class Encounter;

class BattleEngine
{
public:
	BattleEngine(void);
	BattleEngine(shared_ptr<Player> player);
	~BattleEngine(void);
	void StartFight();
	void Init();
	
private:
	void BattleLoop(shared_ptr<Encounter> encounter);
	void EvaluateInput(char input[], shared_ptr<Encounter> encounter);
	void EvaluateBattleConditions(shared_ptr<Encounter> encounter);
	void GenerateInputMap();
	shared_ptr<Encounter> GenerateEncounter();
	
	bool _battleIsOver;
	shared_ptr<Player> _player;
};

