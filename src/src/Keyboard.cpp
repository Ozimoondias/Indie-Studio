//
// MyEventReceiver.cpp for MyEventReceiver in /home/agaro/Epitech/cpp_indie_studio/src/src
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Tue May 16 15:57:57 2017 Agar-One
// Last update Mon Jun 19 00:03:41 2017 Guillaume
//

#include			"Keyboard.hpp"

#include			<iostream>

Keyboard::Keyboard()
{
  for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
    KeyIsDown[i] = false;
}

const irr::SEvent::SJoystickEvent & Keyboard::GetJoystickState(void) const
{
  return JoystickState;
}

bool				Keyboard::OnEvent(const irr::SEvent &e)
{
  if (e.EventType == irr::EET_KEY_INPUT_EVENT)
    KeyIsDown[e.KeyInput.Key] = e.KeyInput.PressedDown;
  if (e.EventType == irr::EET_JOYSTICK_INPUT_EVENT)
    //&& e.JoystickEvent.Joystick == 1)
    JoystickState = e.JoystickEvent;
  return (false);
}

bool				Keyboard::IsKeyDown(irr::EKEY_CODE keyCode) const
{
  return (KeyIsDown[keyCode]);
}

bool				Keyboard::getInput(Player &player, Camera &camera, Map &map,
						   irr::scene::ISceneManager *SceneManager, irr::IrrlichtDevice *Device, irr::video::IVideoDriver *Driver)
{
  // CHECK QUIT
  if (this->IsKeyDown(irr::KEY_ESCAPE))
    return (true);

  // CHECK ANIM PLAYER
  if (player.getType() && player.getMeshSceneNode()->getFrameNr() >= 75)
    {
      player.setFrame(1,33);
      player.getMeshSceneNode()->setAnimationSpeed(15);
      player.getMeshSceneNode()->setLoopMode(true);
    }
  else if (!player.getType() && player.getMeshSceneNode()->getFrameNr() >= 45)
    {
      player.setFrame(1,33);
      player.getMeshSceneNode()->setAnimationSpeed(15);
      player.getMeshSceneNode()->setLoopMode(true);
    }
  
  // ATTACK PLAYER 1
  if (this->IsKeyDown(irr::KEY_RETURN))// || this->JoystickState.ButtonStates == 4)
    {
      irrklang::ISoundEngine*       engine = irrklang::createIrrKlangDevice();
      if (map.atk >= 60 && player.getType())
	{
	  engine->play2D("../Media/lancement_sort_female.ogg", false);
	  player.setFrame(37, 56);
	  map.playerAttack2(player, SceneManager, Device, Driver);
	}	  
      if (map.atk >= 40 && !player.getType())
	{
	  engine->play2D("../Media/sword.ogg", false);
	  player.setFrame(35, 50);
	  player.getMeshSceneNode()->setAnimationSpeed(100);
	  map.playerAttack(player, SceneManager, Device, Driver);
	}
    }
  if (this->IsKeyDown(irr::KEY_KEY_M))// || this->JoystickState.ButtonStates == 8)
    if (map.atk >= 120)
      if (player.getType())
	{
	  player.setFrame(60, 84);
	  player.getMeshSceneNode()->setAnimationSpeed(50);
	  map.playerAttack3(player, SceneManager, Device, Driver);
	}
      else
	{
	  player.setFrame(35, 50);
	  player.getMeshSceneNode()->setAnimationSpeed(100);
	  map.playerAttack(player, SceneManager, Device, Driver);
	}

  // CHECK BONUS PLAYER
  if (this->IsKeyDown(irr::KEY_KEY_E))// || this->JoystickState.ButtonStates == 1)
    map.checkBonus(player);
  if (player.getBonusActive() == true && player.getBonusTime() <= 0 && player.getBonusType() == 1)
    {
      player.setSpeed(5);
      player.setBonusActive(false);
    }
  if (player.getBonusActive() == true && player.getBonusTime() <= 0 && player.getBonusType() == 2)
    {
      player.getMeshSceneNode()->setScale(irr::core::vector3df(10,10,10));
      player.setBonusActive(false);
    }
  if (player.getBonusActive() == true && player.getBonusTime() <= 0 && player.getBonusType() == 3)
    {
      player.getMeshSceneNode()->setScale(irr::core::vector3df(10,10,10));
      player.setBonusActive(false);
    }
  if (player.getBonusActive() == true && player.getBonusTime() > 0)
    player.setBonusTime(player.getBonusTime()-1);

  // MOVE PLAYER
  if (this->IsKeyDown(irr::KEY_KEY_Z))// || this->JoystickState.Axis[1] < -20000)
    player.goForward();
  if (this->IsKeyDown(irr::KEY_KEY_S))// || this->JoystickState.Axis[1] > 20000)
    player.goBack();
  if (this->IsKeyDown(irr::KEY_KEY_Q) || this->JoystickState.Axis[0] < -20000)
    player.goLeft();
  if (this->IsKeyDown(irr::KEY_KEY_D) || this->JoystickState.Axis[0] > 20000)
    player.goRight();

  // MOVE PLAYER
  if (this->IsKeyDown(irr::KEY_KEY_Z) && this->IsKeyDown(irr::KEY_KEY_D))
    player.getMeshSceneNode()->setRotation(irr::core::vector3df(0,225,0));
  if (this->IsKeyDown(irr::KEY_KEY_Z) && this->IsKeyDown(irr::KEY_KEY_Q))
    player.getMeshSceneNode()->setRotation(irr::core::vector3df(0,135,0));
  if (this->IsKeyDown(irr::KEY_KEY_S) && this->IsKeyDown(irr::KEY_KEY_D))
    player.getMeshSceneNode()->setRotation(irr::core::vector3df(0,315,0));
  if (this->IsKeyDown(irr::KEY_KEY_S) && this->IsKeyDown(irr::KEY_KEY_Q))
    player.getMeshSceneNode()->setRotation(irr::core::vector3df(0,45,0));

  // UPDATE PLAYER POS
  camera.updatePos(player);

  return (false);
}

bool				Keyboard::getInput(Player &player, Player &player2, Camera &camera, Camera &camera2, Map &map,
						   irr::scene::ISceneManager *SceneManager, irr::IrrlichtDevice *Device, irr::video::IVideoDriver *Driver)
{
  // CHECK QUIT
  if (this->IsKeyDown(irr::KEY_ESCAPE))
    return (true);

  // CHECK ANIM PLAYER
  if (player.getType() && player.getMeshSceneNode()->getFrameNr() >= 75)
    {
      player.setFrame(1,33);
      player.getMeshSceneNode()->setAnimationSpeed(15);
      player.getMeshSceneNode()->setLoopMode(true);
    }
  else if (!player.getType() && player.getMeshSceneNode()->getFrameNr() >= 45)
    {
      player.setFrame(1,33);
      player.getMeshSceneNode()->setAnimationSpeed(15);
      player.getMeshSceneNode()->setLoopMode(true);
    }
  if (player2.getType() && player2.getMeshSceneNode()->getFrameNr() >= 75)
    {
      player2.setFrame(1,33);
      player2.getMeshSceneNode()->setAnimationSpeed(15);
      player2.getMeshSceneNode()->setLoopMode(true);
    }
  else if (!player2.getType() && player2.getMeshSceneNode()->getFrameNr() >= 45)
    {
      player2.setFrame(1,33);
      player2.getMeshSceneNode()->setAnimationSpeed(15);
      player2.getMeshSceneNode()->setLoopMode(true);
    }
  
  // ATTACK PLAYER 1
  if (this->IsKeyDown(irr::KEY_KEY_V))
    {
      irrklang::ISoundEngine*       engine = irrklang::createIrrKlangDevice();
      if (map.atk >= 60 && player.getType())
	{
	  engine->play2D("../Media/lancement_sort_female.ogg", false);
	  player.setFrame(37, 56);
	  map.playerAttack2(player, SceneManager, Device, Driver);
	}	  
      if (map.atk >= 40 && !player.getType())
	{
	  engine->play2D("../Media/sword.ogg", false);
	  player.setFrame(35, 50);
	  player.getMeshSceneNode()->setAnimationSpeed(100);
	  map.playerAttack(player, SceneManager, Device, Driver);
	}
    }
  if (this->IsKeyDown(irr::KEY_KEY_B))
    if (map.atk >= 120)
      if (player.getType())
	{
	  player.setFrame(60, 84);
	  player.getMeshSceneNode()->setAnimationSpeed(50);
	  map.playerAttack3(player, SceneManager, Device, Driver);
	}
      else
	{
	  player.setFrame(35, 50);
	  player.getMeshSceneNode()->setAnimationSpeed(100);
	  map.playerAttack(player, SceneManager, Device, Driver);
	}

  // ATTACK PLAYER 2
  if (this->IsKeyDown(irr::KEY_KEY_L))
    {
      irrklang::ISoundEngine*       engine = irrklang::createIrrKlangDevice();
      if (map.atk >= 60 && player2.getType())
	{
	  engine->play2D("../Media/lancement_sort_female.ogg", false);
	  player2.setFrame(37, 56);
	  map.playerAttack2(player2, SceneManager, Device, Driver);
	}	  
      if (map.atk >= 40 && !player2.getType())
	{
	  engine->play2D("../Media/sword.ogg", false);
	  player2.setFrame(35, 50);
	  player2.getMeshSceneNode()->setAnimationSpeed(100);
	  map.playerAttack(player2, SceneManager, Device, Driver);
	}
    }
  if (this->IsKeyDown(irr::KEY_KEY_K))
    if (map.atk >= 120)
      if (player2.getType())
	{
	  player2.setFrame(60, 84);
	  player2.getMeshSceneNode()->setAnimationSpeed(50);
	  map.playerAttack3(player2, SceneManager, Device, Driver);
	}
      else
	{
	  player2.setFrame(35, 50);
	  player2.getMeshSceneNode()->setAnimationSpeed(100);
	  map.playerAttack(player2, SceneManager, Device, Driver);
	}

  // CHECK BONUS PLAYER
  if (this->IsKeyDown(irr::KEY_KEY_N))
    map.checkBonus(player);
  if (player.getBonusActive() == true && player.getBonusTime() <= 0 && player.getBonusType() == 1)
    {
      player.setSpeed(5);
      player.setBonusActive(false);
    }
  if (player.getBonusActive() == true && player.getBonusTime() <= 0 && player.getBonusType() == 2)
    {
      player.getMeshSceneNode()->setScale(irr::core::vector3df(10,10,10));
      player.setBonusActive(false);
    }
  if (player.getBonusActive() == true && player.getBonusTime() > 0)
    player.setBonusTime(player.getBonusTime()-1);

  if (this->IsKeyDown(irr::KEY_KEY_J))
    map.checkBonus(player2);
  if (player2.getBonusActive() == true && player2.getBonusTime() <= 0 && player2.getBonusType() == 1)
    {
      player2.setSpeed(5);
      player2.setBonusActive(false);
    }
  if (player2.getBonusActive() == true && player2.getBonusTime() <= 0 && player2.getBonusType() == 2)
    {
      player2.getMeshSceneNode()->setScale(irr::core::vector3df(10,10,10));
      player2.setBonusActive(false);
    }
  if (player2.getBonusActive() == true && player2.getBonusTime() > 0)
    player2.setBonusTime(player2.getBonusTime()-1);

  // MOVE PLAYER 1
  if (this->IsKeyDown(irr::KEY_KEY_Z))
    player.goForward();
  if (this->IsKeyDown(irr::KEY_KEY_S))
    player.goBack();
  if (this->IsKeyDown(irr::KEY_KEY_Q))
    player.goLeft();
  if (this->IsKeyDown(irr::KEY_KEY_D))
    player.goRight();

  // MOVE PLAYER 2
  if (this->IsKeyDown(irr::KEY_UP))
    player2.goForward();
  if (this->IsKeyDown(irr::KEY_DOWN))
    player2.goBack();
  if (this->IsKeyDown(irr::KEY_LEFT))
    player2.goLeft();
  if (this->IsKeyDown(irr::KEY_RIGHT))
    player2.goRight();

  // MOVE PLAYER 1
  if (this->IsKeyDown(irr::KEY_KEY_Z) && this->IsKeyDown(irr::KEY_KEY_D))
    player.getMeshSceneNode()->setRotation(irr::core::vector3df(0,225,0));
  if (this->IsKeyDown(irr::KEY_KEY_Z) && this->IsKeyDown(irr::KEY_KEY_Q))
    player.getMeshSceneNode()->setRotation(irr::core::vector3df(0,135,0));
  if (this->IsKeyDown(irr::KEY_KEY_S) && this->IsKeyDown(irr::KEY_KEY_D))
    player.getMeshSceneNode()->setRotation(irr::core::vector3df(0,315,0));
  if (this->IsKeyDown(irr::KEY_KEY_S) && this->IsKeyDown(irr::KEY_KEY_Q))
    player.getMeshSceneNode()->setRotation(irr::core::vector3df(0,45,0));

  // MOVE PLAYER 2
  if (this->IsKeyDown(irr::KEY_UP) && this->IsKeyDown(irr::KEY_RIGHT))
    player2.getMeshSceneNode()->setRotation(irr::core::vector3df(0,225,0));
  if (this->IsKeyDown(irr::KEY_LEFT) && this->IsKeyDown(irr::KEY_UP))
    player2.getMeshSceneNode()->setRotation(irr::core::vector3df(0,135,0));
  if (this->IsKeyDown(irr::KEY_DOWN) && this->IsKeyDown(irr::KEY_RIGHT))
    player2.getMeshSceneNode()->setRotation(irr::core::vector3df(0,315,0));
  if (this->IsKeyDown(irr::KEY_DOWN) && this->IsKeyDown(irr::KEY_LEFT))
    player2.getMeshSceneNode()->setRotation(irr::core::vector3df(0,45,0));

  // UPDATE PLAYER POS
  camera.updatePos(player);
  camera2.updatePos(player2);

  return (false);
}
