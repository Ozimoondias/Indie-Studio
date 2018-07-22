//
// Core.cpp for Core.cpp in /home/agaro/Epitech/cpp_indie_studio/src/src
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Mon May 15 15:34:59 2017 Agar-One
// Last update Fri Jun  9 01:40:08 2017 Agar-One
//

#include			"Core.hpp"
#include			"driverChoice.h"

Core::Core()
{
  this->_device = irr::createDevice(irr::video::EDT_OPENGL,
				    irr::core::dimension2d<irr::u32>(1920,1080),
				    16,true,false,false,0);
  this->_driver = this->_device->getVideoDriver();
  this->_scenemanager = this->_device->getSceneManager();
  this->_device->getCursorControl()->setVisible(false);
}

Core::Core(Keyboard &receiver)
{
  this->_device = irr::createDevice(irr::video::EDT_OPENGL,
				    irr::core::dimension2d<irr::u32>(1920,1080),
				    16,true,false,false,&receiver);
  this->_driver = this->_device->getVideoDriver();
  this->_scenemanager = this->_device->getSceneManager();
  this->_device->getCursorControl()->setVisible(false);
}

Core::Core(Keyboard &receiver, int height, int width, bool screen)
{
  this->_device = irr::createDevice(irr::video::EDT_OPENGL,
				    irr::core::dimension2d<irr::u32>(width, height),
				    16,screen,false,false,&receiver);
  this->_driver = this->_device->getVideoDriver();
  this->_scenemanager = this->_device->getSceneManager();
  this->_device->getCursorControl()->setVisible(false);
  this->Gui = this->_device->getGUIEnvironment();
}

irr::gui::IGUIEnvironment       *Core::getGui()
{
  return (this->Gui);
}

irr::IrrlichtDevice		*Core::getDevice()
{
  return (this->_device);
}

irr::video::IVideoDriver	*Core::getDriver()
{
  return (this->_driver);
}

irr::scene::ISceneManager	*Core::getSceneManager()
{
  return (this->_scenemanager);
}

irr::video::ITexture		*Core::getImPlayer()
{
  return (this->Image_Player);
}

irr::video::ITexture		*Core::getImPvp()
{
  return (this->Image_Pvp);
}

irr::video::ITexture		*Core::getImPopo()
{
  return (this->Image_Potion);
}

irr::core::position2d<irr::s32>	Core::getPosPopo()
{
  return (this->pos_curseur_potion);
}

irr::core::position2d<irr::s32>	Core::getPosCur()
{
  return (this->pos_curseur_vie);
}

irr::core::position2d<irr::s32>	Core::getPosChar()
{
  return (this->pos_curseur_character);
}

void				Core::setImPlayer(irr::video::ITexture *text)
{
  this->Image_Player = text;
}

void				Core::setImPvp(irr::video::ITexture *text)
{
  this->Image_Pvp = text;
}

void				Core::setImPopo(irr::video::ITexture *text)
{
  this->Image_Potion = text;
}

void				Core::setPosCur(irr::core::position2d<irr::s32> text)
{
  this->pos_curseur_vie = text;
}

void				Core::setPosPopo(irr::core::position2d<irr::s32> text)
{
  this->pos_curseur_potion = text;
}

void				Core::setPosChar(irr::core::position2d<irr::s32> text)
{
  this->pos_curseur_character = text;
}

void				Core::setDevice(irr::IrrlichtDevice *device)
{
  this->_device = device;
}

void				Core::setDriver(irr::video::IVideoDriver *driver)
{
  this->_driver = driver;
}

void				Core::setSceneManager(irr::scene::ISceneManager *scenemanager)
{
  this->_scenemanager = scenemanager;
}

void				Core::Draw()
{
  this->_driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
  this->_scenemanager->drawAll();
  this->Gui->drawAll();
  this->_driver->endScene();
}

int                             Core::getWidth()
{
  return (this->Width);
}

int                             Core::getHeight()
{
  return (this->Height);
}

void                            Core::setWidth(int i)
{
  this->Width = i;
}

void                            Core::setHeight(int i)
{
  this->Height = i;
}
