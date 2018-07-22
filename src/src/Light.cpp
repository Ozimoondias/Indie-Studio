//
// Light.cpp for Light in /home/agaro/Epitech/cpp_indie_studio/cpp_indie_studio
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Mon May 22 09:02:49 2017 Agar-One
// Last update Tue Jun 13 18:45:07 2017 Agar-One
//

#include		"Light.hpp"

Light::Light(irr::scene::ISceneManager *SceneManager)
{
  this->_light = SceneManager->addLightSceneNode(0,
						 irr::core::vector3df(0,2,10),
						 irr::video::SColorf(255,127,0),500,1);
  this->_light->setRotation(irr::core::vector3df(180,0,0));
  irr::video::SLight	&_data
    = this->_light->getLightData();
  _data.Type = irr::video::ELT_SPOT;
}

irr::scene::ILightSceneNode	*Light::getLight()
{
  return (this->_light);
}
