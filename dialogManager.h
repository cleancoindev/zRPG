#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <SDL.h>
#include "DialogBox.h"
#include "Font.h"
#include "EventQueue.h"
#include "EventListener.h"
#include "BattleSprite.h"

class DialogManager : public EventListener
{
protected:

private:
   // Functions
   void loadDialogQueue(std::vector<DialogBox> dialogSequence);
   void center(int* x, int* y, int rows, int cols);
   void centerX(int* x, int rows, int cols);
   void centerY(int* y, int rows, int cols);
   void sizeDialogBox(int* rows, int* cols, int linesOfText, std::string maxRowOfText);

public:
   DialogManager();
   ~DialogManager();

   // Enum
   enum CONTROLS { CONTROL_NULL, CONTROL_UP, CONTROL_DOWN, CONTROL_SELECT, CONTROL_CANCEL };

   // Functions
   void initDialogs();
   void dialogKeyboard(const unsigned char* kbState, unsigned char* kbPrevState);
   virtual void notify(Event* event) override;
   void registerListeners(EventQueue* eventQueue);
   void initBattleDialog(std::vector<BattleSprite>* battleSprites);
   void updateBattleDialog(int input);
   void battleRewards(std::vector<std::string> loot);

   // Variables
   static int* screenWidth;
   static int* screenHeight;
   static std::vector<DialogBox>* dialogQueue;
   std::unordered_map<std::string, std::vector<DialogBox>> dialogs; 
   BattleSprite* battlePlayer;
   std::vector<BattleSprite*> enemies;
   std::unordered_map<std::string, std::string> playerStrings;
   std::unordered_map<std::string, std::string> actionStrings;
   std::vector<std::string> enemyStrings;
   std::string* playerText;
   std::string* actionText;
   std::string* enemyText;
   std::unordered_map<std::string, DialogBox> battleBoxes;
};

