//
// Player.hpp for Player in /home/agaro/Epitech/cpp_indie_studio/src/include
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Mon May 15 16:24:13 2017 Agar-One
// Last update Tue Jun 13 14:13:53 2017 Agar-One
//

#ifndef			_PLAYER_HPP__
#define			_PLAYER_HPP__

#include		"ICharacter.hpp"

class			Player : public ICharacter
{
public:

  Player();
  Player(irr::scene::ISceneManager*, irr::IrrlichtDevice*, irr::video::IVideoDriver*, int);
  virtual		~Player(){};

  void			setScale(irr::core::vector3df);
  void			setNode(irr::scene::ISceneNode *);
  void			setFrame(int, int);
  void			setMesh(irr::scene::IAnimatedMesh *);
  void			setMeshSceneNode(irr::scene::IAnimatedMeshSceneNode *);
  void			setTexture(irr::video::ITexture *);
  void			setPos(irr::core::vector3df);
  void			setClass(int);
  void			setSelector(irr::scene::ITriangleSelector*);

  void			setSpeed(float);
  void			setAtk(float);
  void			setPv(float);

  void			goRight();
  void			goLeft();
  void			goForward();
  void			goBack();

  irr::scene::ISceneNode	*getNode();
  irr::scene::IAnimatedMesh	*getMesh();
  irr::scene::IAnimatedMeshSceneNode	*getMeshSceneNode();
  irr::video::ITexture	*getTexture();
  irr::core::vector3df	getPos();
  int			getClass();
  float			getSpeed();
  float			getAtk();
  float			getPv();

  void			setBonusTime(int);
  int			getBonusTime();
  void			setBonusType(int);
  int			getBonusType();
  void			setBonusActive(bool);
  bool			getBonusActive();

  void					setBallPos(irr::scene::ISceneNode*);
  irr::scene::ISceneNode		*getBallPos();
  void					setAnimPos(irr::scene::IParticleSystemSceneNode*);
  irr::scene::IParticleSystemSceneNode	*getAnimPos();
  void					setStatus(irr::scene::ISceneNodeAnimator*);
  irr::scene::ISceneNodeAnimator	*getStatus();
  void					setTime(size_t);
  size_t				getTime();
  void					setCredits(size_t);
  size_t				getCredits();
  std::wstring				widen(const std::string&);
  const wchar_t*			getStrCredits();
  void					setType(bool);
  bool					getType();

  irr::scene::ITriangleSelector		*_selector;
  
private:

  size_t		_time;
  size_t		_credits;
  bool			_type;
  int			_bonusTime;
  int			_bonusType;
  bool			_bonusActive;
  irr::scene::ISceneNode		*_ball;
  irr::scene::IParticleSystemSceneNode	*_anim;

};

#endif			/* ! _PLAYER_HPP__ */
