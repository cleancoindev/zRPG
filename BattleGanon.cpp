#include "BattleGanon.h"


/*-----------------------------------------------*/
BattleGanon::BattleGanon()
{
   Texture* tex = textureLoader::getTexture("ganon_battle");
   BattleSprite enemy = BattleSprite(&tex->texture, 0, 100, tex->cellWidth, tex->cellHeight, 0, 0, tex->uSize, tex->vSize);
   *this = BattleGanon((BattleGanon&)enemy);
   isAnimated = false; //TODO Remove once animations are setup
   name = "Ganon";
   level = 11;
   maxSpeed = 0;
   healFactor = 0.20;

   // Setup animations
   float uSize = tex->uSize;
   float vSize = tex->vSize;
   std::vector<AnimationFrame> frames;

   // Animations
   int numFrames = 1;
   int timeToNextFrame = 100;
   frames.clear();
   frames.assign(numFrames, AnimationFrame());

   //// Idle Animation
   //frames[0] = AnimationFrame(0 * uSize, 0 * vSize, 1 * uSize, 1 * vSize);
   Animation animation = Animation("Idle", frames, numFrames);
   animations[animation.name] = AnimationData(animation, timeToNextFrame, false);

   // Attack Animation
   numFrames = 20;
   frames.clear();
   frames.assign(numFrames, AnimationFrame());
   //frames[0] = AnimationFrame(0 * uSize, 19 * vSize, 1 * uSize, 1 * vSize);

   animation = Animation("Attack", frames, numFrames);
   AnimationData animData = AnimationData(animation, timeToNextFrame, false);
   //animData.eventFrame = 13;
   animations[animation.name] = animData;

   // Flee Animation
   numFrames = 5;
   timeToNextFrame = 1000;
   frames.clear();
   frames.assign(numFrames, AnimationFrame());

   frames[0] = AnimationFrame(0 * uSize, 0 * vSize, 1 * uSize, 1 * vSize);
   animation = Animation("Flee", frames, numFrames);
   animData = AnimationData(animation, timeToNextFrame, false);
   animations[animation.name] = animData;

   //setAnimation("Idle");
}
/*-----------------------------------------------*/
BattleGanon::~BattleGanon()
{
}
/*-----------------------------------------------*/
void BattleGanon::AI()
{
  
}
/*-----------------------------------------------*/
void BattleGanon::update(int ms)
{
   BattleSprite::update(ms);
}
/*-----------------------------------------------*/
BattleGanon* BattleGanon::clone() const
{
   return new BattleGanon(*this);
}
/*-----------------------------------------------*/