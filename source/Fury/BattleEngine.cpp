#include "stdafx.h"
#include "BattleEngine.h"
#include "Player.h"
#include "Enemy.h"
#include "Encounter.h"

using namespace std;
using std::tr1::shared_ptr;

void ClearConsole();

static enum Inputs
{
	Run = 1,
	Attack = 2
};

// Map to associate the strings with the enum values
static std::map<std::string, Inputs> inputMap;

BattleEngine::BattleEngine(void) {}
BattleEngine::~BattleEngine(void) {}

BattleEngine::BattleEngine(shared_ptr<Player> player)
{
	_player = player;
}

void BattleEngine::Init()
{
	GenerateInputMap();
}

void BattleEngine::GenerateInputMap()
{
	inputMap["R"] = Run;
	inputMap["r"] = Run;
	inputMap["A"] = Attack;
	inputMap["a"] = Attack;
}

void BattleEngine::StartFight()
{
	_battleIsOver = false;
	auto encounter = GenerateEncounter();
	BattleLoop(encounter);	
}

void BattleEngine::BattleLoop(shared_ptr<Encounter> encounter)
{
	static char szInput[_MAX_PATH];

	while(!_battleIsOver)
	{
		try 
		{
			ClearConsole();
			encounter->DisplayBattleStatus();
			cout << "[A]ttack, [R]un: ";
			cout.flush();
			cin.getline(szInput, _MAX_PATH);
			EvaluateInput(szInput, encounter);
			EvaluateBattleConditions(encounter);
		}
		catch(std::exception ex)
		{
			cout << "Exception Caught: " << ex.what();
		}
	}
}

void BattleEngine::EvaluateBattleConditions(shared_ptr<Encounter> encounter)
{
	if (encounter->IsDead())
	{
		_battleIsOver = true;
		cout << "The battle is over! " << endl;
		encounter->ApplyReward(_player);
	}

	if (_player->IsDead())
	{
		_battleIsOver = true;
	}
}

void BattleEngine::EvaluateInput(char input[], shared_ptr<Encounter> encounter)
{
	switch(inputMap[input])
	{
		case Run:
			{
				_battleIsOver = true;
				break;
			}
		case Attack:
			{
				_player->Attack(encounter);
				encounter->Attack(_player);
				break;
			}
	}
}

shared_ptr<Encounter> BattleEngine::GenerateEncounter()
{
	auto encounter = make_shared<Encounter>();
	encounter->Generate(_player->GetLevel());

	return encounter;
}

void ClearConsole()
{
    system("cls");
}