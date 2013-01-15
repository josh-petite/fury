#include "stdafx.h"
#include "Encounter.h"
#include "Enemy.h"
#include "Player.h"

Encounter::Encounter(void)
{
	srand(time(NULL));
}

Encounter::~Encounter(void)
{
}

void Encounter::Generate(int level)
{
	int encounterSize = (rand() % level) + 1;

	for(int i = 0; i < encounterSize; i++)
	{
		_enemies.push_back(CreateEnemy());
	}
}

void Encounter::Attack(shared_ptr<Player> player)
{
	for(auto i = _enemies.begin(); i != _enemies.end(); i++)
	{
		auto enemy = *i;
		enemy->Attack(player);
	}
}

shared_ptr<Enemy> Encounter::CreateEnemy()
{
	auto pivot = rand() % 5;
	shared_ptr<Enemy> enemy;

	switch(pivot)
	{
		case 0:
			{
				enemy = make_shared<Enemy>("Goblin", 3, 1, 1, 1);
				break;
			}
		case 1:
			{
				enemy = make_shared<Enemy>("Wood Elf", 7, 1, 1, 1);
				break;
			}
		case 2:
			{
				enemy = make_shared<Enemy>("Peasant", 5, 1, 1, 1);
				break;
			}
		case 3:
			{
				enemy = make_shared<Enemy>("Groveling Imp", 10, 1, 1, 1);
				break;
			}
		case 4:
			{
				enemy = make_shared<Enemy>("Giant Rat", 10, 1, 1, 1);
				break;
			}
	}
	
	enemy->SetLoot(10, 10);

	return enemy;
}

bool Encounter::IsDead()
{
	for(auto i = _enemies.begin(); i != _enemies.end(); i++)
	{
		auto enemy = *i;
		if (!enemy->IsDead())
			return false;
	}

	return true;
}

void Encounter::ApplyReward(shared_ptr<Player> player)
{
	for(auto i = _enemies.begin(); i != _enemies.end(); i++)
	{
		auto enemy = *i;
		enemy->ApplyReward(player);
	}
}

void Encounter::DisplayBattleStatus()
{
	std::map<std::string, int> encounterGrouping;

	cout << "****************************************" << endl;
	
	for(auto i = _enemies.begin(); i != _enemies.end(); i++)
	{
		auto enemy = *i;
		auto enemyType = encounterGrouping.find(enemy->GetName());
		
		/*if (enemyType == )
			encounterGrouping.insert(*/
	}

	cout << "****************************************" << endl;
}

shared_ptr<Enemy> Encounter::GetRandomEnemy()
{
	return _enemies[rand() % _enemies.size() - 1];
}