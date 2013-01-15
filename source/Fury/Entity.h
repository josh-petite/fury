#pragma once

#include <string>
#include <iostream>
#include <time.h>
#include <memory>

using std::tr1::shared_ptr;

class Entity
{
public:
	Entity(void);
	Entity(std::string name, int hp, int level, int atk, int def) : _name(name), _currentHitPoints(hp), _totalHitPoints(hp), _level(level), _attackPower(atk), _defensePower(def) { srand(time(NULL)); }
	~Entity(void);
	int GetCurrentHp();
	int GetTotalHp();
	int GetLevel();
	std::string GetName();
	virtual void GetStatus() = 0;
	void DecreaseHp(int amount);
	bool IsDead();
	int CalculateDamage();

protected:
	std::string _name;
	int _currentHitPoints;
	int _totalHitPoints;
	int _level;
	int _attackPower;
	int _defensePower;
};

