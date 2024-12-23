#include "Game.h"

#include <iostream>

Game::Game()
{
	texture_map.loadFromFile("Assets\\Tiles\\tile_73.png");

	sprite_map.setTexture(texture_map);
	sprite_map.setScale(1, 1);

	texture_chest_.loadFromFile("Assets\\Tiles\\tile_71.png");
	sprite_chest_.setTexture(texture_chest_);
	//sprite_chest_2.setTexture(texture_chest_);

	sprite_chest_.setScale(1, 1);
	//sprite_chest2_.setScale(2, 2);

	window_.create(sf::VideoMode(texture_map.getSize().x * sprite_map.getScale().x * 8,texture_map.getSize().y * sprite_map.getScale().x * 8), "Pirate Chest Adventure");
	std::cout << window_.getSize().x << "(x) " << window_.getSize().y << "(y)" << '\n';
	sprite_chest_.setPosition(64 * 4, 64* 0);
	sprite_chest_2.setPosition(64 * 2, 64 * 3);
	sprite_chest_3.setPosition(64 * 4, 64 * 6);

	sprite_chest_4.setPosition(64 * 7, 64 * 4);


	Sprite_Chest_Vector.emplace_back(sprite_chest_);
	Sprite_Chest_Vector.emplace_back(sprite_chest_2);
	Sprite_Chest_Vector.emplace_back(sprite_chest_3);
	Sprite_Chest_Vector.emplace_back(sprite_chest_4);
}

//void Game::CheckRotate()
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//	{
//		ship_.setRotation(3.14159265358979323846f / 180.0f);
//	
//		// Forward direction (local +x direction in global space)
//		float angleRad = ship_.getRotation() * (3.14159265358979323846f / 180.0f);
//		sf::Vector2f forward(std::cos(angleRad), std::sin(angleRad));
//		colldown_click_ = 0;
//	}
//
//
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//	{
//		ship_.setRotation(3.14159265358979323846f / 180.0f);
//		
//		// Forward direction (local +x direction in global space)
//		float angleRad = ship_.getRotation() * (3.14159265358979323846f / 180.0f);
//		sf::Vector2f forward(std::cos(angleRad), std::sin(angleRad));
//		colldown_click_ = 0;
//	}
//}

void Game::GameLoop()
{
	while (window_.isOpen())
	{
		window_.clear();

		DrawMap();
		DrawPlayer();
		//Boucle simple Sprite_Coin_Vector
		for (auto i : Sprite_Chest_Vector)
		{
			window_.draw(i);
		}

		//window_.draw(item_);
		//DrawCoin();

		Event();
		//CheckRotate();
		CheckMove();



		//GameEnd();


		colldown_click_ += dt_;
		dt_ = clock_.restart().asSeconds();
		//std::cout << sprite_coin.getPosition().x << " / " << sprite_coin.getPosition().y << std::endl;
		window_.display();
	}
}

bool Game::GameEnd()
{
	if (Sprite_Chest_Vector.empty())
	{
		std::cout << "End" << std::endl;
	}

	while (window_.pollEvent(event_))
	{
		if (event_.type == sf::Event::Closed)
		{
			window_.close();
		}
	}
	return NULL;
}

void Game::DrawMap()
{
	for (int row_size = 0; row_size < 8; row_size++)//Y
	{
		for (int col_size = 0; col_size < 8; col_size++)//X
		{

			switch (field_array_[8 * row_size + col_size])
			{
			case 0:

				texture_map.loadFromFile("Assets//Tiles//tile_73.png");
				sprite_map.setPosition(col_size * sprite_map.getScale().x * 64, row_size * sprite_map.getScale().y * 64);


				window_.draw(sprite_map);

				break;

			case 2:
				texture_player_.loadFromFile("Assets//Ships//ship (1).png");
				sprite_player_.setTexture(texture_player_);

				ship_.setPosition(col_size * sprite_map.getScale().x * 64, row_size * sprite_map.getScale().y * 64);
				//sprite_player_.setScale(2, 2);

				window_.draw(ship_);
				break;

			case 1:
				texture_chest_.loadFromFile("Assets\\Tiles\\tile_71.png");
				sprite_chest_.setTexture(texture_chest_);

				sprite_chest_.setPosition(col_size * sprite_map.getScale().x * 64, row_size * sprite_map.getScale().y * 64);
				//sprite_coin.setScale(2, 2);

				window_.draw(sprite_chest_);
					window_.draw(sprite_chest_2);
				window_.draw(sprite_chest_3);
				window_.draw(sprite_chest_4);
				break;
			}

		}

	}
}

void Game::DrawPlayer()
{
	window_.draw(ship_);
}

void Game::DrawChest()
{

}

void Game::Event()
{
	while (window_.pollEvent(event_))
	{
		if (event_.type == sf::Event::Closed)
		{
			window_.close();
		}
	}
}

void Game::CheckMove()
{
	if (colldown_click_ >= 0.5f)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			ship_.setPosition(ship_.getPosition().x, ship_.getPosition().y - (sprite_map.getScale().y * 64));
			colldown_click_ = 0;
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{

			ship_.setPosition(ship_.getPosition().x, ship_.getPosition().y + (sprite_map.getScale().y * 64));
			colldown_click_ = 0;
		}



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			ship_.setRotation(3.14159265358979323846f / 180.0f);
			ship_.setPosition(ship_.getPosition().x - (sprite_map.getScale().x * 64), ship_.getPosition().y);
			// Forward direction (local +x direction in global space)
			float angleRad = ship_.getRotation() * (3.14159265358979323846f / 180.0f);
			sf::Vector2f forward(std::cos(angleRad), std::sin(angleRad));
			colldown_click_ = 0;
		}



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			ship_.setRotation(3.14159265358979323846f / 180.0f);
			ship_.setPosition(ship_.getPosition().x + (sprite_map.getScale().x * 64), ship_.getPosition().y);
			// Forward direction (local +x direction in global space)
			float angleRad = ship_.getRotation() * (3.14159265358979323846f / 180.0f);
			sf::Vector2f forward(std::cos(angleRad), std::sin(angleRad));
			colldown_click_ = 0;
		}


	}

	for (int idx = 0; idx < Sprite_Chest_Vector.size(); ++idx)
	{
		if (ship_.getPosition() == Sprite_Chest_Vector[idx].getPosition())
		{
			Sprite_Chest_Vector.erase(Sprite_Chest_Vector.begin() + idx);
			//treasur count
			treasure_count_++;
			std::cout <<"CHEST:" << treasure_count_<<'\n';
		}
	}


	if (Sprite_Chest_Vector.empty())
	{
		std::cout << "End" << std::endl;
	}
}

