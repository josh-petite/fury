#include "stdafx.h"
#include "Loot.h"


Loot::Loot(void)
{
}


Loot::~Loot(void)
{
}

int Loot::GetExpReward()
{
	return _experienceReward;
}

int Loot::GetMonetaryReward()
{
	return _monetaryReward;
}
