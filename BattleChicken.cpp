#include "BattleChicken.h"


/*-----------------------------------------------*/
BattleChicken::BattleChicken()
{
   Texture* tex = textureLoader::getTexture("chicken_battle");
   BattleSprite enemy = BattleSprite(&tex->texture, 0, 100, tex->cellWidth, tex->cellHeight, 0, 0, tex->uSize, tex->vSize);
   *this = BattleChicken((BattleChicken&)enemy);
   isAnimated = true; // TODO Remove once animations are setup
   name = "chicken";
   level = 1;

   // Setup animations
   float uSize = tex->uSize;
   float vSize = tex->vSize;

   // Animations
   int numFrames = 1;
   int timeToNextFrame = 100;

   // Idle Animation
   std::vector<AnimationFrame> frames;
   frames.assign(numFrames, AnimationFrame());

   frames[0] = AnimationFrame(0 * uSize, 0 * vSize, 1 * uSize, 1 * vSize);
   Animation animation = Animation("Idle", frames, numFrames);
   animations[animation.name] = AnimationData(animation, timeToNextFrame, false);

   // Attack Animation
   numFrames = 12;
   frames.clear();
   frames.assign(numFrames, AnimationFrame());
   frames[0] = AnimationFrame(0 * uSize, 11 * vSize, 1 * uSize, 1 * vSize);
   frames[1] = AnimationFrame(0 * uSize, 10 * vSize, 1 * uSize, 1 * vSize);
   frames[2] = AnimationFrame(0 * uSize, 9 * vSize, 1 * uSize, 1 * vSize);
   frames[3] = AnimationFrame(0 * uSize, 8 * vSize, 1 * uSize, 1 * vSize);
   frames[4] = AnimationFrame(0 * uSize, 7 * vSize, 1 * uSize, 1 * vSize);
   frames[5] = AnimationFrame(0 * uSize, 6 * vSize, 1 * uSize, 1 * vSize);
   frames[6] = AnimationFrame(0 * uSize, 5 * vSize, 1 * uSize, 1 * vSize);
   frames[7] = AnimationFrame(0 * uSize, 4 * vSize, 1 * uSize, 1 * vSize);
   frames[8] = AnimationFrame(0 * uSize, 3 * vSize, 1 * uSize, 1 * vSize);
   frames[9] = AnimationFrame(0 * uSize, 2 * vSize, 1 * uSize, 1 * vSize);
   frames[10] = AnimationFrame(0 * uSize, 1 * vSize, 1 * uSize, 1 * vSize);
   frames[11] = AnimationFrame(0 * uSize, 0 * vSize, 1 * uSize, 1 * vSize);
   animation = Animation("Attack", frames, numFrames);
   AnimationData animData = AnimationData(animation, timeToNextFrame, false);
   animData.eventFrame = 7;
   animations[animation.name] = animData;

   // Damaged Animation
   numFrames = 13;
   timeToNextFrame = 100;
   frames.clear();
   frames.assign(numFrames, AnimationFrame());

   frames[0] = AnimationFrame(0 * uSize, 11 * vSize, 1 * uSize, 1 * vSize);
   frames[1] = AnimationFrame(0 * uSize, 12 * vSize, 1 * uSize, 1 * vSize);
   frames[2] = AnimationFrame(0 * uSize, 13 * vSize, 1 * uSize, 1 * vSize);
   frames[3] = frames[0];
   frames[4] = frames[1];
   frames[5] = frames[2];
   frames[6] = frames[0];
   frames[7] = frames[1];
   frames[8] = frames[2];
   frames[9] = frames[0];
   frames[10] = frames[1];
   frames[11] = frames[2];
   frames[12] = frames[0];
   animation = Animation("Damaged", frames, numFrames);
   animData = AnimationData(animation, timeToNextFrame, false);
   animations[animation.name] = animData;

   setAnimation("Idle");
}
/*-----------------------------------------------*/
BattleChicken::~BattleChicken()
{
}
/*-----------------------------------------------*/
void BattleChicken::AI()
{

}
/*-----------------------------------------------*/
void BattleChicken::update(int ms)
{
   BattleSprite::update(ms);
   AI();
}
/*-----------------------------------------------*/
void BattleChicken::notify(Event* event)
{
   // TODO
}
/*-----------------------------------------------*/