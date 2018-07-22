//
// Light.hpp for Light in /home/agaro/Epitech/cpp_indie_studio/cpp_indie_studio
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Mon May 22 08:57:29 2017 Agar-One
// Last update Sun Jun 11 02:32:08 2017 Agar-One
//

#ifndef				_LIGHT_HPP__
#define				_LIGHT_HPP__

#include			<irrlicht.h>

class				Light
{
public:

  Light(irr::scene::ISceneManager*);
  virtual			~Light(){};

  irr::scene::ILightSceneNode	*getLight();

private:

  irr::scene::ILightSceneNode	*_light;
  irr::scene::ILightSceneNode	*_light2;

};

#endif				/* ! _LIGHT_HPP__ */
