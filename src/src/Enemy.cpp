//
// Player.cpp for Player in /home/agaro/Epitech/cpp_indie_studio/src/src
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Tue May  9 18:22:22 2017 Agar-One
// Last update Tue Jun 13 18:26:10 2017 Agar-One
// Last update Mon May 22 00:32:22 2017 Alex.commeau
//

#include		"Enemy.hpp"
#include		"Light.hpp"
#include <iostream>

Enemy::Enemy()
{
  this->_speed = rand() % 5 + 2;
  this->_atk = 100;
  this->_pv = 100;
}

Enemy::Enemy(irr::scene::ISceneManager *SceneManager, irr::IrrlichtDevice *Device, irr::video::IVideoDriver *Driver, irr::core::vector3df pos)
{
  enum
  {
    ID_IsNotPickable = 0,
    IDFlag_IsPickable = 1 << 0,
    IDFlag_IsHighlightable = 1 << 1
  };

  int	i = rand() % 3 + 1;
  this->_atk = 100;
  this->_pv = 100;

  i += 1;
  pos.X += rand() % 100;
  pos.Z += rand() % 100;
  this->_speed = i;
  if (i == 2)
    this->_mesh = SceneManager->getMesh("../src/media/Koala/koala.b3d");
  else
    this->_mesh = SceneManager->getMesh("../src/media/Astek/ASTEK_FINAL.b3d");
  if (_mesh)
    {
      this->_meshnode = SceneManager->addAnimatedMeshSceneNode(this->_mesh);
      if (this->_meshnode)
	{
	  this->_meshnode->setMaterialFlag(irr::video::EMF_LIGHTING,false);
	  this->_meshnode->setScale(irr::core::vector3df(10, 10, 10));
	  this->_meshnode->setFrameLoop(1, 33);
	  this->_meshnode->setLoopMode(true);
	  this->setPos(pos);
	  if (i == 2)
	    {
	      this->_meshnode->setMaterialTexture(0, Driver->getTexture("../src/media/Koala/TEXTURE.png"));
	      this->_type = false;
	    }
	  else
	    {
	      this->_meshnode->setMaterialTexture(0, Driver->getTexture("../src/media/Astek/Texture_ASTEK_FINALv2.png"));
	      this->_type = true;
	    }
	}
    }
}

void	Enemy::setType(bool type)
{
  this->_type = type;
}

bool	Enemy::getType()
{
  return (this->_type);
}

void	Enemy::setNode(irr::scene::ISceneNode *node)
{
  this->_node = node;
  this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

void	Enemy::setScale(irr::core::vector3df vec)
{
  this->_meshnode->setScale(vec);
}

void	Enemy::setFrame(int a, int b)
{
  int	i = 0;

  this->_meshnode->setFrameLoop(a, b);
  this->_meshnode->setLoopMode(false);
}

void	Enemy::setMesh(irr::scene::IAnimatedMesh *mesh)
{
  this->_mesh = mesh;
}

void	Enemy::setMeshSceneNode(irr::scene::IAnimatedMeshSceneNode *meshnode)
{
  this->_meshnode = meshnode;
}

void	Enemy::setTexture(irr::video::ITexture *texture)
{
  this->_node->setMaterialTexture(0, texture);
}

void	Enemy::setPos(irr::core::vector3df playerPos)
{
  this->_playerPosition = playerPos;
  this->_meshnode->setPosition(this->_playerPosition);
}

void	Enemy::setClass(int clas)
{
  this->_class = clas;
}

void	Enemy::setAnim(irr::scene::ISceneNodeAnimator *anim)
{
  this->_anim = anim;
}

void	Enemy::setSpeed(float speed)
{
  this->_speed = speed;
}

void	Enemy::setAtk(float atk)
{
  this->_atk = atk;
}

void	Enemy::setPv(float pv)
{
  this->_pv = pv;
}

void    Enemy::setSelector(irr::scene::ITriangleSelector *selec)
{
  this->selector = selec;
}

void	Enemy::enemyOrient(Player &player)
{
  irr::core::vector3df	vec = player.getMeshSceneNode()->getPosition() - this->_meshnode->getPosition();
  irr::core::vector3df	rot = this->_meshnode->getRotation();

  rot.Y = (atan(vec.Z/vec.X) * (180.0f / irr::core::PI) + 90);
  if ((player.getMeshSceneNode()->getPosition().X - this->_meshnode->getPosition().X) >= 0)
    rot.Y = 90 - rot.Y;
  else if ((player.getMeshSceneNode()->getPosition().X - this->_meshnode->getPosition().X) <= 0)
    rot.Y = -90 - rot.Y;
  rot.Y -= 90;
  this->_meshnode->setRotation(rot);
}

irr::scene::ISceneNode		*Enemy::getNode()
{
  return (this->_node);
}

irr::scene::IAnimatedMesh	*Enemy::getMesh()
{
  return (this->_mesh);
}

irr::scene::IAnimatedMeshSceneNode	*Enemy::getMeshSceneNode()
{
  return (this->_meshnode);
}

irr::video::ITexture			*Enemy::getTexture()
{
  return (this->_texture);
}

irr::core::vector3df			Enemy::getPos()
{
  return (this->_playerPosition);
}

int					Enemy::getClass()
{
  return (this->_class);
}

irr::scene::ISceneNodeAnimator		*Enemy::getAnim()
{
  return (this->_anim);
}

float				Enemy::getSpeed()
{
  return (this->_speed);
}

float				Enemy::getAtk()
{
  return (this->_atk);
}

float				Enemy::getPv()
{
  return (this->_pv);
}

void				Enemy::goRight()
{
  irr::core::vector3df		vec = this->getMeshSceneNode()->getPosition();

  vec.X += this->getSpeed();
  this->setPos(vec);
  this->_meshnode->setPosition(vec);
  this->_meshnode->setRotation(irr::core::vector3df(0,270,0));
}

void				Enemy::goLeft()
{
  irr::core::vector3df		vec = this->getMeshSceneNode()->getPosition();

  vec.X -= this->getSpeed();
  this->setPos(vec);
  this->_meshnode->setPosition(vec);
  this->_meshnode->setRotation(irr::core::vector3df(0,90,0));
}

void				Enemy::goBack()
{
  irr::core::vector3df		vec = this->getMeshSceneNode()->getPosition();

  vec.Z -= this->getSpeed();
  this->setPos(vec);
  this->_meshnode->setPosition(vec);
  this->_meshnode->setRotation(irr::core::vector3df(0,0,0));
}

void				Enemy::goForward()
{
  irr::core::vector3df		vec = this->getMeshSceneNode()->getPosition();

  vec.Z += this->getSpeed();
  this->setPos(vec);
  this->_meshnode->setPosition(vec);
  this->_meshnode->setRotation(irr::core::vector3df(0,180,0));
}
