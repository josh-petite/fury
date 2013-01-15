#pragma once

#include <memory>
#include <fstream>
#include <stdio.h>
#include "Player.h"

using std::tr1::shared_ptr;

class PersistPlayer
{
public:
	PersistPlayer(void);
	~PersistPlayer(void);
	void Persist(shared_ptr<Player> player);

private:
};

