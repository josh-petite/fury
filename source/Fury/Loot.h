#pragma once
class Loot
{
public:
	Loot(void);
	Loot(int exp, int money) : _experienceReward(exp), _monetaryReward(money) {}
	~Loot(void);

	int GetExpReward();
	int GetMonetaryReward();

private:
	int _experienceReward;
	int _monetaryReward;
};

