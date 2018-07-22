//
// Play.cpp for Play in /home/agaro/Epitech/cpp_indie_studio/cpp_indie_studio/src/src
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Mon May 22 10:50:44 2017 Agar-One
// Last update Mon Jun 19 18:53:55 2017 alex
//

#include		"Core.hpp"
#include		"Camera.hpp"
#include		"Player.hpp"
#include		"Map.hpp"
#include		"Keyboard.hpp"
#include		<thread>

int main(void);

enum
  {
    GUERRIER = 0,
    MAGE = 1
  };

static void
display_perso(Core& core, Player &player, int width)
{
  switch (width)
    {
    case 640:
	{
	  if (player.getClass() == GUERRIER)
	    core.setImPlayer(core.getDriver()->getTexture("../texture/In_Game/Character/Warrior/Warrior_640.png"));
	  else if (player.getClass() == MAGE)
	    core.setImPlayer(core.getDriver()->getTexture("../texture/In_Game/Character/Mage/Mage_640.png"));
	  break;
	}
    case 800:
	{
	  if (player.getClass() == GUERRIER)
	    core.setImPlayer(core.getDriver()->getTexture("../texture/In_Game/Character/Warrior/Warrior_800.png"));
	  else if (player.getClass() == MAGE)
	    core.setImPlayer(core.getDriver()->getTexture("../texture/In_Game/Character/Mage/Mage_800.png"));
	  break;
      }
    case 1024:
	{
	  if (player.getClass() == GUERRIER)
	    core.setImPlayer(core.getDriver()->getTexture("../texture/In_Game/Character/Warrior/Warrior_1024.png"));
	  else if (player.getClass() == MAGE)
	    core.setImPlayer(core.getDriver()->getTexture("../texture/In_Game/Character/Mage/Mage_1024.png"));
	  break;
	}
    case 1920:
	{
	  if (player.getClass() == GUERRIER)
	    core.setImPlayer(core.getDriver()->getTexture("../texture/In_Game/Character/Warrior/Warrior_1920.png"));
	  else if (player.getClass() == MAGE)
	    core.setImPlayer(core.getDriver()->getTexture("../texture/In_Game/Character/Mage/Mage_1920.png"));
	  break;
	}
    default: break;
    }
}

static void
test_vie_640(int pdv, Core& core)
{
  switch (pdv)
    {
    case 5: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/640/heart_5.png")); break;
    case 4: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/640/heart_4.png")); break;
    case 3: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/640/heart_3.png")); break;
    case 2: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/640/heart_2.png")); break;
    case 1: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/640/heart_1.png")); break;
    case 0: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/640/heart_0.png")); break;
    default: break;
    }
}

static void
test_vie_800(int pdv, Core& core)
{
  switch (pdv)
    {
    case 5: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/800/heart_5.png")); break;
    case 4: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/800/heart_4.png")); break;
    case 3: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/800/heart_3.png")); break;
    case 2: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/800/heart_2.png")); break;
    case 1: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/800/heart_1.png")); break;
    case 0: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/800/heart_0.png")); break;
    default: break;
    }
}

static void
test_vie_1024(int pdv, Core& core)
{
    switch (pdv)
    {
    case 5: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1024/heart_5.png")); break;
    case 4: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1024/heart_4.png")); break;
    case 3: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1024/heart_3.png")); break;
    case 2: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1024/heart_2.png")); break;
    case 1: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1024/heart_1.png")); break;
    case 0: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1024/heart_0.png")); break;
    default: break;
    }
}

static void
test_vie_1920(int pdv, Core& core)
{
  switch (pdv)
    {
    case 5: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1920/heart_5.png")); break;
    case 4: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1920/heart_4.png")); break;
    case 3: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1920/heart_3.png")); break;
    case 2: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1920/heart_2.png")); break;
    case 1: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1920/heart_1.png")); break;
    case 0: core.setImPvp(core.getDriver()->getTexture("../texture/In_Game/heart/1920/heart_0.png")); break;
    default: break;
    }
}

static void
display_vie(Core& core, Player &player, int width)
{
  int pdv = 0;
  if (player.getPv() > 4)
    pdv = 5;
  else if (player.getPv() > 3)
    pdv = 4;
  else if (player.getPv() > 2)
    pdv = 3;
  else if (player.getPv() > 1)
    pdv = 2;
  else if (player.getPv() > 0)
    pdv = 1;
  switch (width)
    {
    case 640: test_vie_640(pdv, core); break;
    case 800: test_vie_800(pdv, core); break;
    case 1024: test_vie_1024(pdv, core); break;
    case 1920: test_vie_1920(pdv, core); break;
    default: break;
    }
}

static void
Pos_Curseur_vie(Core& core, int width)
{
  switch (width)
    {
    case 640: core.setPosCur(irr::core::position2d<irr::s32>(76, 10)); break;
    case 800: core.setPosCur(irr::core::position2d<irr::s32>(91, 17)); break;
    case 1024: core.setPosCur(irr::core::position2d<irr::s32>(116, 36)); break;
    case 1920: core.setPosCur(irr::core::position2d<irr::s32>(227, 59)); break;
    default: break;
    }
}

static void
Pos_Curseur_Character(Core& core, int width)
{
   switch (width)
    {
    case 640: core.setPosChar(irr::core::position2d<irr::s32>(5, 4)); break;
    case 800: core.setPosChar(irr::core::position2d<irr::s32>(6, 10)); break;
    case 1024: core.setPosChar(irr::core::position2d<irr::s32>(11, 22)); break;
    case 1920: core.setPosChar(irr::core::position2d<irr::s32>(17, 19)); break;
    default: break;
    }
}

static void
Pause_Menu(Core& core, int width, int choix)
{
  irr::video::SColor            blanc;
  irr::video::ITexture*         Play_Test;

  blanc.set(255, 255, 255, 255);
  switch (width)
    {
    case 640:
      {
	if (choix == 0)
	  Play_Test = core.getDriver()->getTexture("../texture/In_Game/Pause/Pause_640_0.png");
	else if (choix == 1)
	  Play_Test = core.getDriver()->getTexture("../texture/In_Game/Pause/Pause_640_1.png");
	break;
      }
    case 800:
      {
	if (choix == 0)
	  Play_Test = core.getDriver()->getTexture("../texture/In_Game/Pause/Pause_800_0.png");
	else if (choix == 1)
	  Play_Test = core.getDriver()->getTexture("../texture/In_Game/Pause/Pause_800_1.png");
	break;
      }
    case 1024:
      {
	if (choix == 0)
	  Play_Test = core.getDriver()->getTexture("../texture/In_Game/Pause/Pause_1024_0.png");
	else if (choix == 1)
	  Play_Test = core.getDriver()->getTexture("../texture/In_Game/Pause/Pause_1024_1.png");
	break;
      }
    case 1920:
      {
	if (choix == 0)
	  Play_Test = core.getDriver()->getTexture("../texture/In_Game/Pause/Pause_1920_0.png");
	else if (choix == 1)
	  Play_Test = core.getDriver()->getTexture("../texture/In_Game/Pause/Pause_1920_1.png");
	break;
      }
    default: break;
    }
  core.getDriver()->draw2DImage(Play_Test, irr::core::position2d<irr::s32> (0, 0),
				irr::core::rect<irr::s32> (0, 0, 1920, 1080),
				0, blanc, true);
}

static void
display_Bonus(Core& core, int id, int time)
{
  if (time >= 160)
    {
      if (id == 1)
	core.setImPopo(core.getDriver()->getTexture("../texture/In_Game/Potion/Speed/speed_5.png"));
      else if (id == 2)
	core.setImPopo(core.getDriver()->getTexture("../texture/In_Game/Potion/Resis/resis_5.png"));
    }
  else if (time >= 120 && time < 160)
    {
      if (id == 1)
	core.setImPopo(core.getDriver()->getTexture("../texture/In_Game/Potion/Speed/speed_4.png"));
      else if (id == 2)
	core.setImPopo(core.getDriver()->getTexture("../texture/In_Game/Potion/Resis/resis_4.png"));
    }
  else if (time >= 80 && time < 120)
    {
      if (id == 1)
	core.setImPopo(core.getDriver()->getTexture("../texture/In_Game/Potion/Speed/speed_3.png"));
      else if (id == 2)
	core.setImPopo(core.getDriver()->getTexture("../texture/In_Game/Potion/Resis/resis_3.png"));
    }
  else if (time >= 40 && time < 80)
    {
      if (id == 1)
	core.setImPopo(core.getDriver()->getTexture("../texture/In_Game/Potion/Speed/speed_2.png"));
      else if (id == 2)
	core.setImPopo(core.getDriver()->getTexture("../texture/In_Game/Potion/Resis/resis_2.png"));
    }
  else if (time >= 0  && time < 40)
    {
      if (id == 1)
	core.setImPopo(core.getDriver()->getTexture("../texture/In_Game/Potion/Speed/speed_1.png"));
      else if (id == 2)
	core.setImPopo(core.getDriver()->getTexture("../texture/In_Game/Potion/Resis/resis_1.png"));
    }
}

static void
Pos_Curseur_Bonus(Core& core, int width)
{
  switch (width)
    {
    case 640: core.setPosPopo(irr::core::position2d<irr::s32>(10, 600)); break;
    case 800: core.setPosPopo(irr::core::position2d<irr::s32>(10, 100)); break;
    case 1024: core.setPosPopo(irr::core::position2d<irr::s32>(10, 976)); break;
    case 1920: core.setPosPopo(irr::core::position2d<irr::s32>(10, 250)); break;
    default: break;
    }
}

void
Character_interface(Player &player, Core& core, int width, bool perso, bool vie, bool tour)
{
  static float pdv;

  if (tour == true)
    pdv = player.getPv();
  if (perso == true)
    {
      display_perso(core, player, width);
      Pos_Curseur_Character(core, width);
      core.getGui()->addImage(core.getImPlayer(), core.getPosChar());
    }
  if (vie == true)
    {
      display_vie(core, player, width);
      Pos_Curseur_vie(core, width);
      core.getGui()->addImage(core.getImPvp(), core.getPosCur());
    }
  if (pdv > player.getPv())
    {
      if (player.getClass() == 0)
	core.sound->play2D("../Media/Knight_Hited_01_WAV.ogg", false);
      else
	core.sound->play2D("../Media/Douleur.ogg", false);
      pdv = player.getPv();
      display_vie(core, player, width);
      Pos_Curseur_vie(core, width);
      core.getGui()->addImage(core.getImPvp(), core.getPosCur());
    }
  if (player.getBonusActive())
    {
      if (player.getBonusType() == 1 || player.getBonusType() == 2)
	if (player.getBonusTime() == 199)
	  core.sound->play2D("../Media/Drinkin_Potion02_WAV-1.ogg", false);
      display_Bonus(core, player.getBonusType(), player.getBonusTime());
      Pos_Curseur_Bonus(core, width);
      core.getGui()->addImage(core.getImPopo(), core.getPosPopo());
      if (player.getBonusTime() <= 0)
	{
	  if (player.getBonusType() == 1)
	    player.setSpeed(5);
	  else if (player.getBonusType() == 2)
	    player.getMeshSceneNode()->setScale(irr::core::vector3df(10,10,10));
	  player.setBonusActive(false);
	  core.getGui()->clear();
	  Character_interface(player, core, width, true, true, false);
	}
    }
}

void			One_Player(int width, int Height, bool screen, int chara)
{
  Keyboard		keyboard;
  Core			core(keyboard, width, Height, screen);
  Player		player(core.getSceneManager(), core.getDevice(), core.getDriver(), chara);
  Camera                camera1(core.getSceneManager());
  Map                   map(core, player, "lol", "lol");
  int			choix = 0;
  int			i = 0;

  player.setClass(chara);
  map.setEnemyCollision(core);
  while (i++ < 10)
    map.checkSpawn(player,core.getSceneManager(),core.getDevice(),core.getDriver());
  irr::gui::IGUIFont* font2 = core.getDevice()->getGUIEnvironment()->getFont("../texture/big.png");
  core.sound = irrklang::createIrrKlangDevice();
  core.sound->play2D("../Media/In.ogg", true);
  core.setHeight(Height);
  core.setWidth(width);
  player.setClass(chara);
  player.setPv(5);
  core.getSceneManager()->setAmbientLight(irr::video::SColorf(0.11,0.11,0.11,0));
  Character_interface(player, core, Height, true, true, true);
  core.getSceneManager()->addTextSceneNode(font2,
					   L"Credits",
					   irr::video::SColor(255, 255, 255, 255),
					   camera1.getCamera(),
					   irr::core::vector3df(14, -10, 11));
  while (i++ < 20)
    map.checkSpawn(player,core.getSceneManager(),core.getDevice(),core.getDriver());
  
  irr::core::array<irr::SJoystickInfo> joystickInfo;
  if(core.getDevice()->activateJoysticks(joystickInfo))
    {
        for(irr::u32 joystick = 0; joystick < joystickInfo.size(); ++joystick)
        {
            std::cout << "Joystick " << joystick << ":" << std::endl;
            std::cout << "\tName: '" << joystickInfo[joystick].Name.c_str() << "'" << std::endl;
            std::cout << "\tAxes: " << joystickInfo[joystick].Axes << std::endl;
            std::cout << "\tButtons: " << joystickInfo[joystick].Buttons << std::endl;

            std::cout << "\tHat is: ";

            switch(joystickInfo[joystick].PovHat)
            {
            case irr::SJoystickInfo::POV_HAT_PRESENT:
                std::cout << "present" << std::endl;
                break;

            case irr::SJoystickInfo::POV_HAT_ABSENT:
                std::cout << "absent" << std::endl;
                break;

            case irr::SJoystickInfo::POV_HAT_UNKNOWN:
            default:
                std::cout << "unknown" << std::endl;
                break;
            }
        }
    }
    else
    {
        std::cout << "Joystick support is not enabled." << std::endl;
    }

  
  while (core.getDevice()->run() && (player.getPv() > 0))
    {
      irr::scene::ITextSceneNode *MyTextNode =
	core.getSceneManager()->addTextSceneNode(font2,
						 player.getStrCredits(),
						 irr::video::SColor(255, 255, 255, 255),
						 camera1.getCamera(),
						 irr::core::vector3df(12, -10, 11));
      Character_interface(player, core, Height, false, false, false);
      core.getDriver()->beginScene(true, true, 0);
      if (keyboard.getInput(player, camera1, map, core.getSceneManager(),
      			    core.getDevice(), core.getDriver()))
      	{
      	  core.getDevice()->sleep(130);
      	  while (core.getDevice()->run())
      	    {
      	      core.getDevice()->sleep(130);
      	      Pause_Menu(core, Height, choix);
      	      if (keyboard.IsKeyDown(irr::KEY_KEY_S))
      		choix++;
      	      if (keyboard.IsKeyDown(irr::KEY_KEY_Z))
      		choix--;
      	      if (keyboard.IsKeyDown(irr::KEY_ESCAPE))
      		break;
      	      if (keyboard.IsKeyDown(irr::KEY_RETURN) && choix == 1)
      		return ;
      	      if (keyboard.IsKeyDown(irr::KEY_RETURN) && choix == 0)
      		break;
      	      if (core.getDevice()->isWindowActive())
      		core.getDriver()->endScene();
      	      if (choix > 1)
      		choix = 0;
      	      else if (choix < 0)
      		choix = 1;
      	    }
      	}
      if (keyboard.IsKeyDown(irr::KEY_MENU))
	return ;
      map.checkEnemy(player, core);
      core.Draw();
      MyTextNode->remove();
    }
  core.sound->drop();
}

void			Two_Player(int width, int Height, bool screen, int chara, int chara2)
{
  Keyboard		keyboard;
  Core			core(keyboard, width, Height, screen);
  Player		player(core.getSceneManager(), core.getDevice(), core.getDriver(), chara);
  Player		player2(core.getSceneManager(), core.getDevice(), core.getDriver(), chara2);
  Camera                camera1(core.getSceneManager(), 1);
  Camera                camera2(core.getSceneManager(), 1);
  Map                   map(core, player, player2, "lol", "lol");
  int			choix = 0;
  int			i = 0;

  player.setClass(chara);
  player2.setClass(chara2);
  map.setEnemyCollision(core);
  while (i++ < 10)
    map.checkSpawn(player,core.getSceneManager(),core.getDevice(),core.getDriver());
  irr::gui::IGUIFont* font2 = core.getDevice()->getGUIEnvironment()->getFont("../texture/big.png");
  core.sound = irrklang::createIrrKlangDevice();
  core.sound->play2D("../Media/In.ogg", true);
  core.setHeight(Height);
  core.setWidth(width);
  core.getSceneManager()->setAmbientLight(irr::video::SColorf(0.11,0.11,0.11,0));
  while (i++ < 20)
    map.checkSpawn(player,core.getSceneManager(),core.getDevice(),core.getDriver());
  while (core.getDevice()->run() && (player.getPv() > 0))
    {
      core.getDriver()->setViewPort(irr::core::rect<irr::s32>(0,0,Height,width));
      core.getDriver()->beginScene(true,true,irr::video::SColor(0,0,0,0));
      core.getSceneManager()->setActiveCamera(camera1.getCamera());
      core.getDriver()->setViewPort(irr::core::rect<irr::s32>(0,0,(Height/2)-3,width));
      core.getSceneManager()->drawAll();
      core.getSceneManager()->setActiveCamera(camera2.getCamera());
      core.getDriver()->setViewPort(irr::core::rect<irr::s32>((Height/2)+3,0,Height,width));
      core.getSceneManager()->drawAll();
      if (keyboard.getInput(player, player2, camera1, camera2, map, core.getSceneManager(),
      			    core.getDevice(), core.getDriver()))
      	{
      	  core.getDevice()->sleep(130);
      	  while (core.getDevice()->run())
      	    {
      	      core.getDevice()->sleep(130);
      	      Pause_Menu(core, Height, choix);
      	      if (keyboard.IsKeyDown(irr::KEY_KEY_S))
      		choix++;
      	      if (keyboard.IsKeyDown(irr::KEY_KEY_Z))
      		choix--;
      	      if (keyboard.IsKeyDown(irr::KEY_ESCAPE))
      		break;
      	      if (keyboard.IsKeyDown(irr::KEY_RETURN) && choix == 1)
      		return ;
      	      if (keyboard.IsKeyDown(irr::KEY_RETURN) && choix == 0)
      		break;
      	      if (core.getDevice()->isWindowActive())
      		core.getDriver()->endScene();
      	      if (choix > 1)
      		choix = 0;
      	      else if (choix < 0)
      		choix = 1;
      	    }
	}
      if (keyboard.IsKeyDown(irr::KEY_MENU))
	return ;
      map.checkEnemy2(player, player2,core);
      core.getDriver()->endScene();
    }
  core.sound->drop();
}
