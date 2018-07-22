//
// Core.hpp for Core.hpp in /home/agaro/Epitech/cpp_indie_studio/src/include
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Mon May 15 15:30:27 2017 Agar-One
// Last update Wed Jun  7 15:07:25 2017 Agar-One
//

#ifndef				_CORE_HPP__
#define				_CORE_HPP__

#include			<irrlicht.h>

#include			<string>
#include			<iostream>

#include			"Keyboard.hpp"

class				Keyboard;

#include <irrKlang.h>
using namespace irrklang;
#pragma comment(lib, "irrKlang.lib")

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif

class				Core
{
public:

  irrklang::ISoundEngine*       sound;
  
  Core();
  Core(Keyboard &);
  Core(Keyboard &, int, int, bool);
  ~Core(){};

  irr::IrrlichtDevice		*getDevice();
  irr::video::IVideoDriver	*getDriver();
  irr::scene::ISceneManager	*getSceneManager();
  irr::video::ITexture		*getImPlayer();
  irr::video::ITexture		*getImPvp();
  irr::video::ITexture		*getImPopo();
  irr::gui::IGUIEnvironment	*getGui();
  irr::core::position2d<irr::s32>	getPosPopo();
  irr::core::position2d<irr::s32>	getPosCur();
  irr::core::position2d<irr::s32>	getPosChar();

  void				setGui(irr::gui::IGUIEnvironment *);
  void				setDevice(irr::IrrlichtDevice *);
  void				setDriver(irr::video::IVideoDriver *);
  void				setSceneManager(irr::scene::ISceneManager *);
  void				setImPlayer(irr::video::ITexture*);
  void				setImPvp(irr::video::ITexture*);
  void				setImPopo(irr::video::ITexture*);
  void				setPosPopo(irr::core::position2d<irr::s32>);
  void				setPosCur(irr::core::position2d<irr::s32>);
  void				setPosChar(irr::core::position2d<irr::s32>);

  int                           getWidth();
  int                           getHeight();
  void                          setWidth(int);
  void                          setHeight(int);

  void				Draw();

private:

  irr::IrrlichtDevice		*_device;
  irr::video::IVideoDriver	*_driver;
  irr::scene::ISceneManager	*_scenemanager;
  irr::video::ITexture		*Image_Player;
  irr::video::ITexture		*Image_Pvp;
  irr::video::ITexture		*Image_Potion;

  irr::core::position2d<irr::s32>	pos_curseur_potion;
  irr::core::position2d<irr::s32>	pos_curseur_vie;
  irr::core::position2d<irr::s32>	pos_curseur_character;
  irr::gui::IGUIEnvironment		*Gui;

  int                                   Height;
  int                                   Width;

};

#endif				/* ! _CORE_HPP__ */
