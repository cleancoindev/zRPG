#pragma once
#include "AnimatedSprite.h"
#include "Texture.h"
#include "textureLoader.h"

class Chicken : public AnimatedSprite
{
private:
   void AI();
   float randomSpeed();

public:
   Chicken();
   ~Chicken();

   // Functions
   virtual void update(int ms) override;

};

