#pragma once

#include <map>

class Experience
{
public:
	Experience(void);
	~Experience(void);

	void Init();
	std::map<int, int> GetTable();

private:
	std::map<int, int> _experienceTable;
};

