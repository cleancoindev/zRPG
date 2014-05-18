#include "Chest.h"

Chest::Chest()
{
	Texture* tex = textureLoader::getTexture("friendly_npcs");
	AnimatedSprite sprite = AnimatedSprite(&tex->texture, 0, 0, tex->width, tex->height, 0, 0, 0.5, 1);
	*this = Chest((Chest&)sprite);
	type = 1;
	name = "chest";


}