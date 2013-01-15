#include "stdafx.h"
#include "PersistPlayer.h"

using namespace std;

char * ConvertStringToCharArray(std::string s);

PersistPlayer::PersistPlayer(void)
{
}


PersistPlayer::~PersistPlayer(void)
{
}

void PersistPlayer::Persist(shared_ptr<Player> player)
{
	filebuf fb;
	fb.open ("player.dat",ios::out);
	ostream os(&fb);
	os << "Name: " << player->GetName() << "\n";
	os << "Level: " << player->GetLevel() << "\n";
	os << "Experience: " << player->GetExperience() << "\n";
	os << "AttackPower: " << player->GetAttackPower() << "\n";
	os << "DefensePower: " << player->GetDefensePower() << "\n";
	fb.close();
}
