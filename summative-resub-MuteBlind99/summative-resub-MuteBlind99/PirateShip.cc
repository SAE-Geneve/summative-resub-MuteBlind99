#include "PirateShip.h"

PirateShip::PirateShip()
{
	texture_ship_.loadFromFile("Assets//Ships//ship (1).png");

	sprite_.setTexture(texture_ship_);
	//sprite_.setPosition(16, 16);
	sprite_.setScale(2, 2);
}



void PirateShip::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}
