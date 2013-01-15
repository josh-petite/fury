#pragma once

#include "Entity.h"

class Enemy;
class Experience;
class Encounter;

using std::tr1::shared_ptr;

class Player : public Entity
{
public:
	Player();
	Player(std::string name, int hp, int level, int atk, int def) : Entity(name, hp, level, atk, def) { _money = 0; }
	
	void Init();
	void GetStatus() override;
	void Attack(shared_ptr<Encounter> encounter);
	void IncrementExp(int amount);
	void IncrementMoney(int amount);
	void CalculateLevel();
	
	// Accessors
	int GetExperience();
	int GetAttackPower();
	int GetDefensePower();
	
	void SetExperience(int amount);
	void SetLevel(int level);

	std::string CalculateColumnTwoSpacing(int columnOneFieldLength);
	std::string ConstructStatusRow1();
	std::string ConstructStatusRow2();
	std::string ConstructStatusRow3();
	std::string ConstructStatusRow4();

private:
	int _experience;
	int _money;

	shared_ptr<Experience> _experienceTable;
};