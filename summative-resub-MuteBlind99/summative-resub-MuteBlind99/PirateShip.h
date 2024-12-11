#pragma once
#include <SFML/Graphics.hpp>

class PirateShip:public sf::Drawable,public sf::Transformable
{
public:

	PirateShip();
	
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void ShipRotate();
private:

	sf::Texture texture_ship_;
	sf::Sprite sprite_;
	float colldown_click_ = 0.f;
};

