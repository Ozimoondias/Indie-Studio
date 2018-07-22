//
// Player.hpp for Player in /home/agaro/Epitech/cpp_indie_studio/src/include
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Mon May 15 16:24:13 2017 Agar-One
// Last update Fri Jun  2 17:13:00 2017 Agar-One
//

#ifndef			_ENEMY_HPP__
#define			_ENEMY_HPP__

#include		"ICharacter.hpp"
#include		"Player.hpp"

#ifdef	_IRR_WINDOWS_
#pragma	comment(lib, "irrlicht.lib")
#pragma	comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
# endif

class			Player;

class			Enemy : public ICharacter
{
public:

  Enemy();
  Enemy(irr::scene::ISceneManager*, irr::IrrlichtDevice*, irr::video::IVideoDriver*, irr::core::vector3df);
  virtual		~Enemy(){};

  void			setScale(irr::core::vector3df);
  void			setNode(irr::scene::ISceneNode *);
  void			setFrame(int, int);
  void			setMesh(irr::scene::IAnimatedMesh *);
  void			setMeshSceneNode(irr::scene::IAnimatedMeshSceneNode *);
  void			setTexture(irr::video::ITexture *);
  void			setPos(irr::core::vector3df);
  void			setClass(int);
  void			setSelector(irr::scene::ITriangleSelector*);
  void			setAnim(irr::scene::ISceneNodeAnimator *);
  void			setType(bool);
  void			enemyOrient(Player &);

  void			setSpeed(float);
  void			setAtk(float);
  void			setPv(float);

  void			goRight();
  void			goLeft();
  void			goForward();
  void			goBack();

  irr::scene::ISceneNode		*getNode();
  irr::scene::IAnimatedMesh		*getMesh();
  irr::scene::IAnimatedMeshSceneNode	*getMeshSceneNode();
  irr::video::ITexture			*getTexture();
  irr::core::vector3df			getPos();
  irr::scene::ISceneNodeAnimator	*getAnim();
  int			getClass();
  float			getSpeed();
  float			getAtk();
  float			getPv();
  bool			getType();
  
  irr::scene::ISceneNodeAnimator	*_anim;

private:

  bool				_type;
};

#endif			/* ! _ENEMY_HPP__ */
