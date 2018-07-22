//
// MyEventReceiver.hpp for EventReceiver in /home/agaro/Epitech/cpp_indie_studio/src/include
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Tue May 16 15:53:39 2017 Agar-One
// Last update Tue Jun 13 15:53:58 2017 Guillaume
//

#ifndef				_KEYBOARD_HPP__
#define				_KEYBOARD_HPP__

#include			<irrlicht.h>

#include			"Camera.hpp"
#include			"Map.hpp"
#include			"Player.hpp"

class				Player;
class				Camera;
class				Map;

class				Keyboard : public irr::IEventReceiver
{
public:

  Keyboard();
  virtual			~Keyboard(){};

  virtual	bool		OnEvent(const irr::SEvent &);

  virtual	bool		IsKeyDown(irr::EKEY_CODE) const;

  virtual	bool		getInput(Player &, Camera &, Map &,
					 irr::scene::ISceneManager*,
					 irr::IrrlichtDevice*,
					 irr::video::IVideoDriver*);
  virtual	bool		getInput(Player &, Player&, Camera &,
					 Camera &, Map &,
					 irr::scene::ISceneManager*,
					 irr::IrrlichtDevice*,
					 irr::video::IVideoDriver*);
  const irr::SEvent::SJoystickEvent & GetJoystickState(void) const;
    

private:

  bool				KeyIsDown[irr::KEY_KEY_CODES_COUNT];
  irr::SEvent::SJoystickEvent	JoystickState;
};

#endif				/* ! _KEYBOARD_HPP__ */
