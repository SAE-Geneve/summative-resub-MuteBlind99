#include "Treasure.h"

Treasure::Treasure()
{
	texture_.loadFromFile("Assets\\Tiles\\tile_71.png");
	sprite_.setTexture(texture_);
	//sprite_chest_2.setTexture(texture_chest_);

	sprite_.setScale(1, 1);
	//sprite_chest2_.setScale(2, 2);
	sprite_.setPosition(126 , 126);
	//sprite_chest_2.setPosition(32 * 2, 32 * 1);

	Sprite_Chest_Vector.emplace_back(sprite_);
	/*Sprite_Chest_Vector.emplace_back(sprite_chest_2);*/
}

void Treasure::ChestFound()
{
	for (int idx = 0; idx < Sprite_Chest_Vector.size(); ++idx)
	{
		if (ship_.getPosition() == Sprite_Chest_Vector[idx].getPosition())
		{
			Sprite_Chest_Vector.erase(Sprite_Chest_Vector.begin() + idx);
			//treasur count
			treasure_count_++;
		}
	}
}
