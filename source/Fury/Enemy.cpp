#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Loot.h"

using namespace std;

Enemy::Enemy(void)
{
}

Enemy::~Enemy(void)
{
}

void Enemy::GetStatus()
{
	cout << _name << " -> HP: " << _currentHitPoints << "/" << _totalHitPoints << " Level: " << _level << endl;
}

void Enemy::SetLoot(int exp, int money)
{
	_loot = make_shared<Loot>(rand() % exp + (exp / 2), rand() % money);	
}

void Enemy::Attack(shared_ptr<Player> player)
{
	if (IsDead())
		return;

	int damage = CalculateDamage();
	player->DecreaseHp(damage);
	cout << _name << " deals " << player->GetName() << " [" << damage << "] damage!" << endl;
}

void Enemy::ApplyReward(shared_ptr<Player> player)
{
	int money = _loot->GetMonetaryReward();
	int exp = _loot->GetExpReward();

	cout << "Loot found: " << money << " gold! " << endl;
	cout << exp << " exp gained!" << endl;

	player->IncrementExp(exp);
	player->IncrementMoney(money);
	player->CalculateLevel();
}
