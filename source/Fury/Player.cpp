#include "Player.h"
#include "Enemy.h"
#include "Experience.h"
#include "Encounter.h"
#include <boost\lexical_cast.hpp>

using namespace std;

static int StatusRowLength = 40;

Player::Player()
{
	_name = "Player";
	_level = 1;
	_currentHitPoints = _totalHitPoints = 10;
	_attackPower = 1;
	_defensePower = 1;
}

void Player::Init()
{
	SetExperience(0);
	_experienceTable = make_shared<Experience>(); 
	_experienceTable->Init();
}

void Player::GetStatus()
{
	cout << "****************************************" << endl;
	cout << ConstructStatusRow1() << endl;
	cout << ConstructStatusRow2() << endl;
	cout << ConstructStatusRow3() << endl;
	cout << ConstructStatusRow4() << endl;
	cout << "****************************************" << endl;
}

std::string Player::CalculateColumnTwoSpacing(int columnOneFieldLength)
{
	std::string result;
	for(int i = 0; i < (10 - columnOneFieldLength); i++) { result += " "; }

	return result;
}

std::string Player::ConstructStatusRow1()
{	
	auto row = "* Name:  " + _name + CalculateColumnTwoSpacing(_name.length()) +
			   "HP:  " + boost::lexical_cast<std::string>(_currentHitPoints) + "/" + boost::lexical_cast<std::string>(_totalHitPoints);		

	int remainder = StatusRowLength - row.length() - 1;
	for(int i = 0; i < remainder; i++) { row += " "; }
	row += "*";

	return row;
}

std::string Player::ConstructStatusRow2()
{
	std::string levelString = boost::lexical_cast<std::string>(_level);
	auto row = "* Level: " + levelString + CalculateColumnTwoSpacing(levelString.length()) + "Atk: " + boost::lexical_cast<std::string>(_attackPower);
	int remainder = StatusRowLength - row.length() - 1;
	for(int i = 0; i < remainder; i++) { row += " "; }
	row += "*";

	return row;
}

std::string Player::ConstructStatusRow3()
{
	std::string expString = boost::lexical_cast<std::string>(_experience);
	auto row = "* Exp:   " + expString + CalculateColumnTwoSpacing(expString.length()) + "Def: " + boost::lexical_cast<std::string>(_defensePower);
	int remainder = StatusRowLength - row.length() - 1;
	for(int i = 0; i < remainder; i++) { row += " "; }
	row += "*";

	return row;
}

std::string Player::ConstructStatusRow4()
{
	auto row = "* Gold:  " + boost::lexical_cast<std::string>(_money);
	int remainder = StatusRowLength - row.length() - 1;
	for(int i = 0; i < remainder; i++) { row += " "; }
	row += "*";

	return row;
}

void Player::Attack(shared_ptr<Encounter> encounter)
{
	if (IsDead())
		return;

	int damage = CalculateDamage();
	auto enemy = encounter->GetRandomEnemy();
	enemy->DecreaseHp(damage);
	cout << _name << " attacks the <" << enemy->GetName() << "> for [" << damage << "] damage!" << endl;
}

void Player::CalculateLevel()
{
	int currentExp = GetExperience();
	int newLevel = 0;
	auto expTable = _experienceTable->GetTable();

	for(int i = 1; i < expTable.size() + 1; i++)
	{
		if (currentExp <= expTable[i])
			break;

		newLevel++;
	}

	SetLevel(newLevel);
}

void Player::IncrementExp(int amount)
{
	_experience += amount;
}

void Player::IncrementMoney(int amount)
{
	_money += amount;
}

int Player::GetExperience()
{
	return _experience;
}
void Player::SetExperience(int amount) 
{
	_experience = amount;
}

void Player::SetLevel(int level)
{
	if (level > _level)
		cout << "LEVEL UP!!" << endl;

	_level = level;
}

int Player::GetAttackPower()
{
	return _attackPower;
}

int Player::GetDefensePower()
{
	return _defensePower;
}