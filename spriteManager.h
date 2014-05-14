#pragma once
#include <vector>
#include <unordered_map>
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "Texture.h"
#include "textureLoader.h"
#include "Chicken.h"
#include "bucketManager.h"

class spriteManager
{
protected:
   spriteManager();

private:


public:
   ~spriteManager();
   static void init(std::vector<std::vector<Sprite*>>* spriteBuckets, std::unordered_map<std::string, Texture>* textures, int* maxScreenWidth, int* maxScreenHeight);
   static void loadLevelSprites(std::string levelName);
   static void initChickens();

   // Variables
  static std::unordered_map<std::string, std::vector<Sprite*>> levelSprites;
  static std::vector<std::vector<Sprite*>>* spriteBuckets;
  static std::unordered_map<std::string, Texture>* textures;
  static int *maxScreenWidth, *maxScreenHeight;
};
