#include "enemyManager.h"


/*-----------------------------------------------*/
enemyManager::enemyManager()
{
}
/*-----------------------------------------------*/
enemyManager::~enemyManager()
{
}
/*-----------------------------------------------*/
void enemyManager::init(std::unordered_map<std::string, Texture>* textures, std::unordered_map<int, std::vector<BattleSprite>>* enemies)
{
   // Initialize all enemies
   
   Texture* tex = &(*textures)["chicken_battle"];
   BattleSprite enemy = BattleSprite(&tex->texture, 0, 100, tex->cellWidth, tex->cellHeight, 0, 0, tex->uSize, tex->vSize);
   enemy.isAnimated = false; // TODO Remove once animations are setup
   enemy.name = "chicken";
   enemy.level = 1;

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
   Animation animation_idle = Animation("Idle", frames, numFrames);
   enemy.animations[animation_idle.name] = AnimationData(animation_idle, timeToNextFrame, false);

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
   Animation animation_attack = Animation("Attack", frames, numFrames);
   AnimationData animData = AnimationData(animation_attack, timeToNextFrame, false);
   //animData.eventFrame = 7; // This line breaks the engine???? // TODO Comprehend
   //animData.eventFrame = 6;
   //animData.eventFrame++;
   enemy.animations[animation_attack.name] = animData;

   // Damaged Animation
   numFrames = 12;
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
   Animation animation_damaged = Animation("Damaged", frames, numFrames);
   animData = AnimationData(animation_damaged, timeToNextFrame, true);
   enemy.animations[animation_damaged.name] = animData;

   enemy.setAnimation("Idle");
   (*enemies)[BATTLE_EASY].push_back(enemy);


   //Medium enemy
   tex = &(*textures)["guard_battle"];
   enemy = BattleSprite(&tex->texture, 500, 100, tex->width, tex->height, 0, 0, tex->uSize, tex->vSize);
   enemy.isAnimated = false; // TODO Remove once animations are setup
   enemy.name = "guard";
   enemy.level = 5;

   // Setup animations
   uSize = tex->uSize;
   vSize = tex->vSize;

   // Animations
   numFrames = 1;
   timeToNextFrame = 100;
   frames.clear();
   frames.assign(numFrames, AnimationFrame());

   // Idle Animation
   frames[0] = AnimationFrame(0 * uSize, 0 * vSize, 1 * uSize, 1 * vSize);
   animation_idle = Animation("Idle", frames, numFrames);
   enemy.animations[animation_idle.name] = AnimationData(animation_idle, timeToNextFrame, false);

   // Attack Animation
   numFrames = 20;
   frames.clear();
   frames.assign(numFrames, AnimationFrame());
   //frames[0] = AnimationFrame(0 * uSize, 19 * vSize, 1 * uSize, 1 * vSize);
   animation_attack = Animation("Attack", frames, numFrames);
   animData = AnimationData(animation_attack, timeToNextFrame, false);
   //animData.eventFrame = 13;
   enemy.animations[animation_attack.name] = animData;

   enemy.setAnimation("Idle");

   (*enemies)[BATTLE_MEDIUM].push_back(enemy);

   //Hard enemy
   tex = &(*textures)["knight_battle"];
   enemy = BattleSprite(&tex->texture, 500, 100, tex->width, tex->height, 0, 0, tex->uSize, tex->vSize);
   enemy.isAnimated = false; //TODO Remove once animations are setup
   enemy.name = "knight";
   enemy.level = 10;

   // Setup animations
   uSize = tex->uSize;
   vSize = tex->vSize;

   // Animations
   numFrames = 1;
   timeToNextFrame = 100;
   frames.clear();
   frames.assign(numFrames, AnimationFrame());

   //// Idle Animation
   //frames[0] = AnimationFrame(0 * uSize, 0 * vSize, 1 * uSize, 1 * vSize);
   animation_idle = Animation("Idle", frames, numFrames);
   enemy.animations[animation_idle.name] = AnimationData(animation_idle, timeToNextFrame, false);

   // Attack Animation
   numFrames = 20;
   frames.clear();
   frames.assign(numFrames, AnimationFrame());
   //frames[0] = AnimationFrame(0 * uSize, 19 * vSize, 1 * uSize, 1 * vSize);

   animation_attack = Animation("Attack", frames, numFrames);
   animData = AnimationData(animation_attack, timeToNextFrame, false);
   //animData.eventFrame = 13;
   enemy.animations[animation_attack.name] = animData;

   enemy.setAnimation("Idle");

   (*enemies)[BATTLE_HARD].push_back(enemy);
   
   //Boss enemy
   tex = &(*textures)["ganon_battle"];
   enemy = BattleSprite(&tex->texture, 500, 100, tex->width, tex->height, 0, 0, 1, 1);
   enemy.isAnimated = false; //TODO Remove once animations are setup
   enemy.name = "Ganon";
   enemy.level = 11;
   
   // Setup animations
   uSize = tex->uSize;
   vSize = tex->vSize;

   // Animations
   numFrames = 1;
   timeToNextFrame = 100;
   frames.clear();
   frames.assign(numFrames, AnimationFrame());

   //// Idle Animation
   //frames[0] = AnimationFrame(0 * uSize, 0 * vSize, 1 * uSize, 1 * vSize);
   animation_idle = Animation("Idle", frames, numFrames);
   enemy.animations[animation_idle.name] = AnimationData(animation_idle, timeToNextFrame, false);

   // Attack Animation
   numFrames = 20;
   frames.clear();
   frames.assign(numFrames, AnimationFrame());
   //frames[0] = AnimationFrame(0 * uSize, 19 * vSize, 1 * uSize, 1 * vSize);

   animation_attack = Animation("Attack", frames, numFrames);
   animData = AnimationData(animation_attack, timeToNextFrame, false);
   //animData.eventFrame = 13;
   enemy.animations[animation_attack.name] = animData;

   enemy.setAnimation("Idle");

   (*enemies)[BATTLE_HARD].push_back(enemy);
}
/*-----------------------------------------------*/
void enemyManager::updateEnemy(BattleSprite* enemy)
{
   // Enemy state changes go here
}
/*-----------------------------------------------*/