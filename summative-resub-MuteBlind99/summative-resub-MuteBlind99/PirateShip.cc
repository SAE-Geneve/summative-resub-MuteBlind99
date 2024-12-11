#include "PirateShip.h"

PirateShip::PirateShip()
{
	texture_ship_.loadFromFile("Assets//Ships//ship (1).png");

	sprite_.setTexture(texture_ship_);
	//sprite_.setPosition(16, 16);
	sprite_.setScale(1, 1);
}

void PirateShip::ShipRotate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sprite_.getRotation()* (3.14159265358979323846f / 180.0f);
		
		// Forward direction (local +x direction in global space)
		float angleRad = sprite_.getRotation() * (3.14159265358979323846f / 180.0f);
		sf::Vector2f forward(std::cos(angleRad), std::sin(angleRad));
		colldown_click_ = 0;
	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sprite_.getRotation()* (3.14159265358979323846f / 180.0f);
		
		// Forward direction (local +x direction in global space)
		float angleRad = sprite_.getRotation() * (3.14159265358979323846f / 180.0f);
		sf::Vector2f forward(std::cos(angleRad), std::sin(angleRad));
		colldown_click_ = 0;
	}
}


void PirateShip::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}
