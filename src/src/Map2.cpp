
//
// Map.cpp for Map.cpp in /home/agaro/Epitech/cpp_indie_studio/src/src
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Tue May 16 12:53:23 2017 Agar-One
// Last update Sun Jun 18 18:29:49 2017 Guillaume
//

#include			"Map.hpp"

#include			<iostream>

Map::Map(Core &core, Player &_player, Player &_player2, std::string _obj, std::string _texture)
{
  irr::scene::IAnimatedMesh		*wall_m;
  irr::scene::ITriangleSelector		*selector;
  irr::scene::IMeshSceneNode		*wall_am;
  irr::scene::IAnimatedMesh		*wall_ma;
  irr::scene::IAnimatedMeshSceneNode	*wall_ama;
  int					i = 0;

  this->BuildDeco(core.getSceneManager(),core.getDevice(),core.getDriver());
  this->BuildDeco(core.getSceneManager(),core.getDevice(),core.getDriver());
  this->BuildDeco(core.getSceneManager(),core.getDevice(),core.getDriver());
  wall_m = core.getSceneManager()->getMesh("../src/media/Map/map.obj");
  wall_am = core.getSceneManager()->addOctreeSceneNode(wall_m->getMesh(0),0,0);
  if (wall_am)
    {
      wall_am->setMaterialFlag(irr::video::EMF_LIGHTING,false);
      wall_am->setScale(irr::core::vector3df(300,200,300));
    }
  selector = core.getSceneManager()->createOctreeTriangleSelector(wall_m, wall_am, 128);
  _player.getMeshSceneNode()->setTriangleSelector(selector);
  _player2.getMeshSceneNode()->setTriangleSelector(selector);
  irr::scene::ISceneNodeAnimator *anim
    = core.getSceneManager()->createCollisionResponseAnimator(selector, _player.getMeshSceneNode(), irr::core::vector3df(15,1,15),irr::core::vector3df(0,0,0));
  _player.getMeshSceneNode()->addAnimator(anim);
  irr::scene::ISceneNodeAnimator *anim2
    = core.getSceneManager()->createCollisionResponseAnimator(selector, _player2.getMeshSceneNode(), irr::core::vector3df(15,1,15),irr::core::vector3df(0,0,0));
  _player2.getMeshSceneNode()->addAnimator(anim2);
  _player._selector = selector;
  _player2._selector = selector;
}

void					Map::checkBonus(irr::core::vector3df pos,
							irr::scene::ISceneManager *SceneManager,
							irr::IrrlichtDevice *Device,
							irr::video::IVideoDriver *Driver)
{
  int					i = 0;
  i = rand() % 10 + 1;
  if (i <= 2)
    {
      i = rand() % 3 + 1;
      i += 6;
      irr::scene::IAnimatedMesh			*wall_ma;
      irr::scene::IAnimatedMeshSceneNode	*wall_ama;
      wall_ma = SceneManager->getMesh("../src/media/Bonus/PowerUp/skharry_bottleMesh/skharry_bottleMesh.obj");
      wall_ama = SceneManager->addAnimatedMeshSceneNode(wall_ma);
      if (wall_ama)
	{
	  wall_ama->setMaterialTexture(0, Driver->getTexture("../src/media/Bonus/PowerUp/skharry_bottleMesh/skharry_bottleTex1.png"));
	  pos.Y += 10;
	  wall_ama->setPosition(pos);
	  wall_ama->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS,true);
	  wall_ama->setMaterialFlag(irr::video::EMF_LIGHTING,false);
	  wall_ama->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
	}
      wall_ama->setMaterialTexture(0, Driver->getTexture("../src/media/Bonus/PowerUp/skharry_bottleMesh/skharry_bottleTex1.png"));
      this->_blist.push_back(std::make_pair(wall_ama,i));
    }
  if (i >= 9)
    {
      irr::scene::IAnimatedMesh			*wall_ma;
      irr::scene::IAnimatedMeshSceneNode	*wall_ama;
      wall_ma = SceneManager->getMesh("../src/media/Décor/CacklingSkull/CacklingSkull.obj");
      wall_ama = SceneManager->addAnimatedMeshSceneNode(wall_ma);
      if (wall_ama)
	{
	  i = rand() % 300 + 1;
	  pos.X += rand() % 100 + 1;
	  pos.Z += rand() % 100 + 1;
	  wall_ama->setPosition(pos);
	  wall_ama->setRotation(irr::core::vector3df(0,i,0));
	  wall_ama->setScale(irr::core::vector3df(0.8,0.8,0.8));
	  wall_ama->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS,true);
	  wall_ama->setMaterialFlag(irr::video::EMF_LIGHTING,false);
	  wall_ama->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
	}
    }
}

void				Map::checkTarget(Player &player, Core &core, std::list<std::pair<Enemy*,int>>::iterator &lit)
{
  irr::core::vector3df		diff;
  irr::core::vector3df		newPos;

  if ((*lit).first->getType() == true && player.getMeshSceneNode()->getAbsolutePosition().getDistanceFrom((*lit).first->getMeshSceneNode()->getAbsolutePosition()) <= 70)
    {
      if ((*lit).second == 0
	  || (*lit).second == 1)
	{
	  (*lit).first->setFrame(36, 56);
	  (*lit).first->getMeshSceneNode()->setLoopMode(true);
	  (*lit).second = 2;
	}
    }
  if ((*lit).first->getType() == true && player.getMeshSceneNode()->getAbsolutePosition().getDistanceFrom((*lit).first->getMeshSceneNode()->getAbsolutePosition()) > 70)
    {
      diff = player.getMeshSceneNode()->getPosition() - (*lit).first->getMeshSceneNode()->getPosition();
      newPos = (*lit).first->getMeshSceneNode()->getPosition();
      newPos.Y = 0;
      if ((*lit).first->getMeshSceneNode()->getPosition().X <= player.getMeshSceneNode()->getPosition().X)
	{
	  newPos.X += (*lit).first->getSpeed();
	  (*lit).first->getMeshSceneNode()->setPosition(newPos);
	}
      if ((*lit).first->getMeshSceneNode()->getPosition().X >= player.getMeshSceneNode()->getPosition().X)
	{
	  newPos.X -= (*lit).first->getSpeed();
	  (*lit).first->getMeshSceneNode()->setPosition(newPos);
	}
      if ((*lit).first->getMeshSceneNode()->getPosition().Z <= player.getMeshSceneNode()->getPosition().Z)
	{
	  newPos.Z += (*lit).first->getSpeed();
	  (*lit).first->getMeshSceneNode()->setPosition(newPos);
	}
      if ((*lit).first->getMeshSceneNode()->getPosition().Z >= player.getMeshSceneNode()->getPosition().Z)
	{
	  newPos.Z -= (*lit).first->getSpeed();
	  (*lit).first->getMeshSceneNode()->setPosition(newPos);
	}
      if ((*lit).second == 0
	  || (*lit).second == 2)
	{
	  (*lit).first->setFrame(1, 33);
	  (*lit).first->getMeshSceneNode()->setLoopMode(true);
	  (*lit).second = 1;
	}
    }
  int		i = rand() % 1000 + 1;i += 1000;
  if ((*lit).first->getType() == false && player.getMeshSceneNode()->getAbsolutePosition().getDistanceFrom((*lit).first->getMeshSceneNode()->getAbsolutePosition()) <= 50)
    {
      (*lit).first->_anim =
	core.getSceneManager()->createFlyStraightAnimator((*lit).first->getMeshSceneNode()->getPosition(),
							  (*lit).first->getMeshSceneNode()->getPosition(),i,true);
      (*lit).first->getMeshSceneNode()->addAnimator((*lit).first->_anim);
      (*lit).first->_anim->drop();
      if ((*lit).second == 0
	  || (*lit).second == 1)
	{
	  (*lit).first->setFrame(36, 56);
	  (*lit).first->getMeshSceneNode()->setLoopMode(true);
	  (*lit).second = 2;
	}
    }
  if ((*lit).first->getType() == false && player.getMeshSceneNode()->getAbsolutePosition().getDistanceFrom((*lit).first->getMeshSceneNode()->getAbsolutePosition()) > 70)
    {
      (*lit).first->_anim =
	core.getSceneManager()->createFlyStraightAnimator((*lit).first->getMeshSceneNode()->getPosition(),
							  player.getMeshSceneNode()->getPosition(),i,true);
      (*lit).first->getMeshSceneNode()->addAnimator((*lit).first->_anim);
      (*lit).first->_anim->drop();
      if ((*lit).second == 0
	  || (*lit).second == 2)
	{
	  (*lit).first->setFrame(1, 33);
	  (*lit).first->getMeshSceneNode()->setLoopMode(true);
	  (*lit).second = 1;
	}
    }
  if ((*lit).first->getMeshSceneNode()->getFrameNr() >= 53)
    ;//player.setPv(player.getPv()-0.2);
  (*lit).first->enemyOrient(player);
}

void				Map::checkFireball(Player &player, Core &core, std::list<std::pair<Enemy*,int>>::iterator &lit)
{
  if (player.getBallPos() && player.getAnimPos())
    if (player.getBallPos()->getAbsolutePosition().getDistanceFrom((*lit).first->getMeshSceneNode()->getAbsolutePosition()) <= 50)
      {
	this->checkSpawn(player, core.getSceneManager(), core.getDevice(), core.getDriver());
	(*lit).first->getMeshSceneNode()->remove();
	lit = this->_enemy.erase(lit);
	_meta->removeAllTriangleSelectors();
	player.getBallPos()->remove();
	player.getAnimPos()->remove();
	player.setBallPos(NULL);
	player.setAnimPos(NULL);
      }
  if (player.getBallPos() && player.getAnimPos() && player.getTime() <= 5)
    {
      player.getBallPos()->remove();
      player.getAnimPos()->remove();
      player.setBallPos(NULL);
      player.setAnimPos(NULL);
    }
  if (player.getTime() > 0)
    player.setTime(player.getTime()-0.1);
}

void				Map::checkEnemy2(Player &player, Player &player2, Core &core)
{
  std::list<std::pair<Enemy*,int>>::iterator
    lit(this->_enemy.begin()),
    lend(this->_enemy.end());

  this->atk += 1;
  for (; lit!=lend; ++lit)
    {
      if (player.getMeshSceneNode()->getAbsolutePosition().getDistanceFrom((*lit).first->getMeshSceneNode()->getAbsolutePosition())
	  < player2.getMeshSceneNode()->getAbsolutePosition().getDistanceFrom((*lit).first->getMeshSceneNode()->getAbsolutePosition()))
	this->checkTarget(player,core,lit);
      else
	this->checkTarget(player2,core,lit);
      this->checkFireball(player,core,lit);
      this->checkFireball(player2,core,lit);
    }
  this->lol -= 2;
}
