#ifndef GAME_H
#define  GAME_H
#include <array>

#include "PirateShip.h"
#include "SFML/Graphics.hpp"

class Game
{
public:
	Game();
	void GameLoop();
	bool GameEnd();
	void DrawMap();
	void DrawPlayer();
	void DrawChest();
	void Event();
	void CheckMove();

private:
	std::array<int, 64>field_array_ = { 0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0 };

	sf::RenderWindow window_;
	sf::Texture texture_map;
	sf::Sprite sprite_map;
	sf::Texture texture_player_;
	sf::Sprite sprite_player_;
	sf::Texture texture_chest_;
	sf::Sprite sprite_chest_;
	sf::Event event_;

	PirateShip ship_;

	std::vector<sf::Sprite> Sprite_Chest_Vector;

	sf::Clock clock_;
	float dt_ = 0.f;
	float colldown_click_ = 0.f;
};
#endif //GAME_H
