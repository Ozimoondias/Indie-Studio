//
// ICharacter.hpp for ICharacter.hpp in /home/agaro/Epitech/cpp_indie_studio/src/include
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Mon May 15 16:19:06 2017 Agar-One
// Last update Fri Jun  2 17:10:03 2017 Agar-One
//

#ifndef				_ICHARACTER_HPP__
#define				_ICHARACTER_HPP__

#include			<irrlicht.h>
#include			<iostream>

class					ICharacter
{
public:

  virtual				~ICharacter(){};

  virtual	void			setNode(irr::scene::ISceneNode *) = 0;
  virtual	void			setScale(irr::core::vector3df) = 0;
  virtual	void			setFrame(int, int) = 0;
  virtual	void			setMesh(irr::scene::IAnimatedMesh *) = 0;
  virtual	void			setMeshSceneNode(irr::scene::IAnimatedMeshSceneNode *) = 0;
  virtual	void			setTexture(irr::video::ITexture *) = 0;
  virtual	void			setPos(irr::core::vector3df) = 0;
  virtual	void			setClass(int) = 0;
  virtual	void			setSpeed(float) = 0;
  virtual	void			setAtk(float) = 0;
  virtual	void			setPv(float) = 0;

  virtual	void			goRight() = 0;
  virtual	void			goLeft() = 0;
  virtual	void			goForward() = 0;
  virtual	void			goBack() = 0;

  virtual	irr::scene::ISceneNode	*getNode() = 0;
  virtual	irr::scene::IAnimatedMesh	*getMesh() = 0;
  virtual	irr::scene::IAnimatedMeshSceneNode	*getMeshSceneNode() = 0;
  virtual	irr::video::ITexture	*getTexture() = 0;
  virtual	irr::core::vector3df	getPos() = 0;
  virtual	int			getClass() = 0;
  virtual	float			getSpeed() = 0;
  virtual	float			getAtk() = 0;
  virtual	float			getPv() = 0;

protected:

  irr::video::ITexture			*_texture;
  irr::scene::ISceneNode		*_node;
  irr::scene::IAnimatedMesh		*_mesh;
  irr::scene::IAnimatedMeshSceneNode	*_meshnode;

  irr::core::vector3df			_playerPosition;

  float					_speed;
  float					_atk;
  float					_pv;

  int					_class;

  irr::scene::ITriangleSelector*	selector = 0;
  
  
};

#endif			/* ! _ICHARACTER_HPP__ */
