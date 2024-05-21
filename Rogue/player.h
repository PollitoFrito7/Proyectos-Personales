#ifndef player_h
#define player_h
#include <string>

const int MaxHealth1 = 20, BagDim = 10;
const char playerDisplay = '@';

enum damageType {slashing, blunt, piercing};

struct t_Weapon {
	std::string name;
	int damage;
	damageType type;
};

enum objects {
	healthPotion, stone, 
};
typedef objects t_Bag[BagDim];

struct t_Player {
	int health = MaxHealth1;
	int maxHealth = MaxHealth1;
	int level = 1;
	int exp = 0;
	int money = 0;
	int room = -1;
	int xPlayer;
	int yPlayer;
};

void levelUp(t_Player player1);

#endif 

