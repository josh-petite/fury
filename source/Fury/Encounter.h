#pragma once

#include <memory>
#include <vector>
#include <time.h>
#include <map>

class Enemy;
class Player;

using namespace std;

class Encounter
{
public:
	Encounter(void);
	~Encounter(void);

	void Generate(int level);
	void DisplayBattleStatus();
	shared_ptr<Enemy> GetRandomEnemy();
	void Attack(shared_ptr<Player> player);
	void ApplyReward(shared_ptr<Player> player);
	bool IsDead();

private:
	shared_ptr<Enemy> CreateEnemy();

	vector<shared_ptr<Enemy>> _enemies;
};

