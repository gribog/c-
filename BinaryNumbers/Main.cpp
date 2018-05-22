#include <iostream>
#include <string>

using namespace std;


enum class monsterType
{
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME,
};

void printMonsterType(monsterType type)
{
	if (type == monsterType::OGRE) 
		cout << "Ogre";
	if (type == monsterType::DRAGON)
		cout << "Dragon";
	if (type == monsterType::GIANT_SPIDER)
		cout << "Giant Spider";
	if (type == monsterType::SLIME)
		cout << "Slime";
}


struct Monster
{
	monsterType type;
	string name;
	int health;
};

void printMonster(Monster monster)
{
	cout << "This "; 
	printMonsterType(monster.type);
	cout << " is named " << monster.name << " and has " << monster.health << " health." << '\n';
}

int main()
{
	Monster Buba{ monsterType::OGRE,"Torg",145 };
	Monster Zeld{ monsterType::SLIME,"Blurp",145 };

	printMonster(Buba);
	printMonster(Zeld);

	return 0;
}