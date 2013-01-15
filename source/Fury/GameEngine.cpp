#include "stdafx.h"
#include "GameEngine.h"

using namespace std;

void GenerateInputMap();
void DisplayGameOver();

static enum Inputs
{
	Fight = 1,
	Status = 2,
	Quit = 3	
};

// Map to associate the strings with the enum values
static std::map<std::string, Inputs> inputMap;

GameEngine::GameEngine(void)
{
}


GameEngine::~GameEngine(void)
{
}

void GameEngine::Init(shared_ptr<Player> player)
{
	_player = player;
	_battleEngine = make_shared<BattleEngine>(_player);
	_battleEngine->Init();

	GenerateInputMap();
}

void GenerateInputMap()
{
	inputMap["F"] = Fight;
	inputMap["f"] = Fight;
	inputMap["S"] = Status;
	inputMap["s"] = Status;
	inputMap["Q"] = Quit;
	inputMap["q"] = Quit;	
}

void GameEngine::Loop()
{
	static char szInput[_MAX_PATH];

	while(true)
	{
		try 
		{
			EvaluateGameState();
			cout << endl <<  "L: " << _player->GetLevel() << " HP: " << _player->GetCurrentHp() << "/" << _player->GetTotalHp() << endl << "[F]ight, [S]tatus, [Q]uit: ";
			cout.flush();
			cin.getline(szInput, _MAX_PATH);
			EvaluateInput(szInput);
		}
		catch (std::exception ex)
		{
			cout << "Exception Caught: " << ex.what();
			break;
		}
	}

	Cleanup();
}

void GameEngine::EvaluateGameState()
{
	if (_player->IsDead())
	{
		DisplayGameOver();
		exit(0);
	}
}

void GameEngine::EvaluateInput(std::string input)
{
	switch(inputMap[input])
	{
		case Quit:
			{
				_persistPlayer->Persist(_player);
				exit(0);
				break;
			}
		case Status:
			{
				_player->GetStatus();
				break;
			}
		case Fight:
			{
				_battleEngine->StartFight();
				break;
			}
		default:
			{
				break;
			}
	}
}

void GameEngine::Cleanup()
{
}

void DisplayGameOver()
{
	cout << "********************" << endl;
	cout << "*     YOU DIED     *" << endl;
	cout << "*    ==========    *" << endl;
	cout << "*    GAME  OVER    *" << endl;
	cout << "********************" << endl;
	cout << endl;

	system("PAUSE");
}
