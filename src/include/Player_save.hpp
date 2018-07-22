//
// Player.hpp for Player in /home/agaro/Epitech/cpp_indie_studio/src/include
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Mon May 15 16:24:13 2017 Agar-One
// Last update Mon May 29 23:13:28 2017 Agar-One
//

#ifndef			_PLAYER_HPP__
#define			_PLAYER_HPP__

#include		"ICharacter.hpp"

class			Player : public ICharacter
{
public:

  Player();
  Player(irr::scene::ISceneManager*, irr::IrrlichtDevice*, irr::video::IVideoDriver*);
  virtual		~Player(){};

  void			setScale(irr::core::vector3df);
  void			setNode(irr::scene::ISceneNode *);
  void			setFrame(int, int);
  void			setMesh(irr::scene::IAnimatedMesh *);
  void			setMeshSceneNode(irr::scene::IAnimatedMeshSceneNode *);
  void			setTexture(irr::video::ITexture *);
  void			setPos(irr::core::vector3df);
  void			setSelector(irr::scene::ITriangleSelector*);
  void          setPreviousAnim(irr::scene::ISceneNodeAnimator *);

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

  float			getSpeed();
  float			getAtk();
  float			getPv();
    irr::scene::ISceneNodeAnimator *getPreviousAnim();
};

#endif			/* ! _PLAYER_HPP__ */
