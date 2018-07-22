//
// Player.cpp for Player in /home/agaro/Epitech/cpp_indie_studio/src/src
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Tue May  9 18:22:22 2017 Agar-One
// Last update Tue Jun 13 18:47:57 2017 Agar-One
// Last update Mon May 22 00:32:22 2017 Alex.commeau
//

#include		"Player.hpp"
#include		"Light.hpp"
#include		<sstream>

Player::Player()
{
  this->_speed = 5;
  this->_atk = 100;
  this->_pv = 100;
}

Player::Player(irr::scene::ISceneManager *SceneManager, irr::IrrlichtDevice *Device, irr::video::IVideoDriver *Driver, int play)
{
  Light	light(SceneManager);

  this->_speed = 5;
  this->_atk = 5;
  this->_pv = 5;
  this->_credits = 1;
  this->_ball = 0;
  this->_bonusTime = 0;
  this->_bonusType = 0;
  this->_bonusActive = false;
  this->_time = 0;
  enum
  {
    ID_IsNotPickable = 0,
    IDFlag_IsPickable = 1 << 0,
    IDFlag_IsHighlightable = 1 << 1
  };

  if (play == 0)
    {
      this->_mesh = SceneManager->getMesh("../src/media/Warrior/WARIOR_FINAL.b3d");
      this->_type = false;
    }
  if (play == 1)
    {
      this->_mesh = SceneManager->getMesh("../src/media/Angel/angel.b3d");
      this->_type = true;
    }
  this->_meshnode = SceneManager->addAnimatedMeshSceneNode(this->_mesh);
  if (this->_meshnode)
    {
      this->_meshnode->setMaterialFlag(irr::video::EMF_LIGHTING,false);
      this->_meshnode->setScale(irr::core::vector3df(10,10,10));
      this->setPos(irr::core::vector3df(10,1,10));
      this->_meshnode->setFrameLoop(1,33);
      this->_meshnode->setLoopMode(true);
      if (play == 0)
	this->_meshnode->setMaterialTexture(0, Driver->getTexture("../src/media/Warrior/WARIOR_Vok_TEXTURE.png"));
      if (play == 1)
	this->_meshnode->setMaterialTexture(0, Driver->getTexture("../src/media/Angel/Yang.png"));
    }
  light.getLight()->setParent(this->getMeshSceneNode());
}

void	Player::setType(bool type)
{
  this->_type = type;
}

bool	Player::getType()
{
  return (this->_type);
}

void	Player::setNode(irr::scene::ISceneNode *node)
{
  this->_node = node;
  this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

void	Player::setScale(irr::core::vector3df vec)
{
  this->_meshnode->setScale(vec);
}

void	Player::setFrame(int a, int b)
{
  int	i = 0;

  this->_meshnode->setFrameLoop(a, b);
  this->_meshnode->setLoopMode(false);
}

void	Player::setMesh(irr::scene::IAnimatedMesh *mesh)
{
  this->_mesh = mesh;
}

void	Player::setMeshSceneNode(irr::scene::IAnimatedMeshSceneNode *meshnode)
{
  this->_meshnode = meshnode;
}

void	Player::setTexture(irr::video::ITexture *texture)
{
  this->_node->setMaterialTexture(0, texture);
}

void	Player::setPos(irr::core::vector3df playerPos)
{
  this->_playerPosition = playerPos;
  this->_meshnode->setPosition(this->_playerPosition);
}

void	Player::setClass(int clas)
{
  this->_class = clas;
}

void	Player::setSpeed(float speed)
{
  this->_speed = speed;
}

void	Player::setAtk(float atk)
{
  this->_atk = atk;
}

void	Player::setPv(float pv)
{
  this->_pv = pv;
}

void    Player::setSelector(irr::scene::ITriangleSelector *selec)
{
  this->selector = selec;
}

void	Player::setBonusTime(int time)
{
  this->_bonusTime = time;
}

int	Player::getBonusTime()
{
  return (this->_bonusTime);
}

void	Player::setBonusType(int type)
{
  this->_bonusType = type;
}

int	Player::getBonusType()
{
  return (this->_bonusType);
}

void	Player::setBonusActive(bool act)
{
  this->_bonusActive = act;
}

bool	Player::getBonusActive()
{
  return (this->_bonusActive);
}

void				Player::setTime(float ti)
{
  this->_time = ti;
}

float				Player::getTime()
{
  return (this->_time);
}

void				Player::setCredits(size_t ti)
{
  this->_credits = ti;
}

size_t				Player::getCredits()
{
  return (this->_credits);
}

irr::scene::ISceneNode		*Player::getBallPos()
{
  return (this->_ball);
}

void				Player::setBallPos(irr::scene::ISceneNode *pos)
{
  this->_ball = pos;
}

irr::scene::IParticleSystemSceneNode	*Player::getAnimPos()
{
  return (this->_anim);
}

void					Player::setAnimPos(irr::scene::IParticleSystemSceneNode *anim)
{
  this->_anim = anim;
}

const wchar_t				*Player::getStrCredits()
{
  std::string				s
    = std::to_string(this->_credits);
  const	char				*cstr
    = s.c_str();
  const wchar_t				*wcstr
    = this->widen(cstr).c_str();
  return (wcstr);
}

std::wstring				Player::widen(const std::string& str)
{
  std::wostringstream			wstm ;
  const std::ctype<wchar_t>			&ctfacet
    = std::use_facet<std::ctype<wchar_t> >( wstm.getloc() ) ;
  
  for(size_t i=0; i<str.size(); ++i)
    wstm << ctfacet.widen( str[i] ) ;
  return wstm.str() ;
}

irr::scene::ISceneNode		*Player::getNode()
{
  return (this->_node);
}

irr::scene::IAnimatedMesh	*Player::getMesh()
{
  return (this->_mesh);
}

irr::scene::IAnimatedMeshSceneNode	*Player::getMeshSceneNode()
{
  return (this->_meshnode);
}

irr::video::ITexture			*Player::getTexture()
{
  return (this->_texture);
}

irr::core::vector3df			Player::getPos()
{
  return (this->_playerPosition);
}

int				Player::getClass()
{
  return (this->_class);
}

float				Player::getSpeed()
{
  return (this->_speed);
}

float				Player::getAtk()
{
  return (this->_atk);
}

float				Player::getPv()
{
  return (this->_pv);
}

void				Player::goRight()
{
  irr::core::vector3df		vec = this->getMeshSceneNode()->getPosition();

  vec.X += this->getSpeed();
  this->setPos(vec);
  this->_meshnode->setPosition(vec);
  this->_meshnode->setRotation(irr::core::vector3df(0,270,0));
}

void				Player::goLeft()
{
  irr::core::vector3df		vec = this->getMeshSceneNode()->getPosition();

  vec.X -= this->getSpeed();
  this->setPos(vec);
  this->_meshnode->setPosition(vec);
  this->_meshnode->setRotation(irr::core::vector3df(0,90,0));
}

void				Player::goBack()
{
  irr::core::vector3df		vec = this->getMeshSceneNode()->getPosition();

  vec.Z -= this->getSpeed();
  this->setPos(vec);
  this->_meshnode->setPosition(vec);
  this->_meshnode->setRotation(irr::core::vector3df(0,0,0));
}

void				Player::goForward()
{
  irr::core::vector3df		vec = this->getMeshSceneNode()->getPosition();

  vec.Z += this->getSpeed();
  this->setPos(vec);
  this->_meshnode->setPosition(vec);
  this->_meshnode->setRotation(irr::core::vector3df(0,180,0));
}
