#include <cstddef>

struct EnemySpaceShip
{
	int x_coord;
	int y_coord;
	int weaponPower;
	EnemySpaceShip* p_nextEnemy;
};

EnemySpaceShip* p_enemies = NULL;

EnemySpaceShip* getEnemy(void)
{
	EnemySpaceShip *p_ship = new EnemySpaceShip;
	p_ship->x_coord = 0.0;
	p_ship->y_coord = 0.0;
	p_ship->weaponPower = 20;
	p_ship->p_nextEnemy = p_enemies;
	p_enemies = p_ship;
	return p_ship;
}

void upgradeWeapons(EnemySpaceShip* p_ship)
{
	p_ship->weaponPower += 10;
}

int main()
{
	EnemySpaceShip* ship = getEnemy();
	upgradeWeapons(ship);
}