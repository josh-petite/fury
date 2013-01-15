#include "stdafx.h"
#include "Entity.h"

using namespace std;

Entity::Entity(void)
{
}


Entity::~Entity(void)
{
}

int Entity::GetCurrentHp()
{
	return _currentHitPoints;
}

int Entity::GetTotalHp()
{
	return _totalHitPoints;
}

int Entity::GetLevel()
{
	return _level;
}

std::string Entity::GetName()
{
	return _name;
}

void Entity::DecreaseHp(int amount)
{
	_currentHitPoints -= amount;
}

bool Entity::IsDead()
{
	return _currentHitPoints <= 0;
}

int Entity::CalculateDamage()
{
	return (rand() % 10) + _level * _attackPower;
}