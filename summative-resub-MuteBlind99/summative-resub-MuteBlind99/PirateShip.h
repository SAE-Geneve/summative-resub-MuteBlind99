#pragma once
#include <SFML/Graphics.hpp>

class PirateShip:public sf::Drawable,public sf::Transformable
{
public:

	PirateShip();
	void PlayerMove(sf::Vector2f direction, float dt);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:

	sf::Texture texture_ship_;
	sf::Sprite sprite_;
	bool is_running;
	float speed_running = 0.30f;
	float speed_walking = 0.15;
	const  float speed_ = 50.5f;
};

