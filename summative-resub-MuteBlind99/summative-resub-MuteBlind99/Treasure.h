#pragma once
#include <SFML/Graphics.hpp>

#include "PirateShip.h"

class Treasure:public sf::Drawable, public sf::Transformable
{
public:
	Treasure();
	void ChestFound();
protected:
	std::vector<sf::Sprite> Sprite_Chest_Vector;
private:
	sf::Texture texture_;
	sf::Sprite sprite_;
	
	PirateShip ship_;
	int treasure_count_=0;
};

