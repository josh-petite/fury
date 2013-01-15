#include "stdafx.h"
#include "Experience.h"

Experience::Experience(void)
{
}


Experience::~Experience(void)
{
}

void Experience::Init()
{
	_experienceTable[1] = 0;
	_experienceTable[2] = 10;
	_experienceTable[3] = 100;
	_experienceTable[4] = 1000;
	_experienceTable[5] = 2000;
	_experienceTable[6] = 4000;
	_experienceTable[7] = 16000;
	_experienceTable[8] = 32000;
	_experienceTable[9] = 64000;
}

std::map<int, int> Experience::GetTable()
{
	return _experienceTable;
}
