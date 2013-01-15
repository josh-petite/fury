#pragma once

#include "Entity.h"

using std::tr1::shared_ptr;

class Player;
class Loot;

class Enemy : public Entity
{
public:
	Enemy(void);
	Enemy(std::string name, int hp, int level, int atk, int def) : Entity(name, hp, level, atk, def) { }
	~Enemy(void);

	void GetStatus() override;
	
	void SetLoot(int exp, int money);
	void Attack(shared_ptr<Player> player);
	void ApplyReward(shared_ptr<Player> player);
private:
	shared_ptr<Loot> _loot;
};

