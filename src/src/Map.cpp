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

Map::Map(Core &core, Player &_player, std::string _obj, std::string _texture)
{
  irr::scene::IAnimatedMesh		*wall_m;
  irr::scene::IMeshSceneNode		*wall_am;
  irr::scene::ITriangleSelector		*selector;
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
  irr::scene::ISceneNodeAnimator *anim
    = core.getSceneManager()->createCollisionResponseAnimator(selector, _player.getMeshSceneNode(), irr::core::vector3df(15,1,15),irr::core::vector3df(0,0,0));
  _player.getMeshSceneNode()->addAnimator(anim);
  _player._selector = selector;
}

void				Map::checkSpawn(Player &player,
						irr::scene::ISceneManager *SceneManager,
						irr::IrrlichtDevice *Device,
						irr::video::IVideoDriver *Driver)
{
  irr::core::vector3df		pos = irr::core::vector3df(10,1,10);
  int				i = rand() % 10;

  
  if (player.getCredits() >= 0 && player.getCredits() < 60)
    if (i <= 4)
      pos = irr::core::vector3df(816,1,-697);
    else if (i <= 6)
      pos = irr::core::vector3df(-617,1,592);
    else
      pos = irr::core::vector3df(-653,1,-702);
  else if (player.getCredits() > 59 && player.getCredits() < 120)
    if (i <= 4)
      pos = irr::core::vector3df(-776,1,1921);
    else if (i <= 7)
      pos = irr::core::vector3df(-521,1,2846);
    else
      pos = irr::core::vector3df(238,1,2688);
  else if (player.getCredits() > 119 && player.getCredits() < 180)
    if (i <= 4)
      pos = irr::core::vector3df(-470,1,4499);
    else if (i <= 7)
      pos = irr::core::vector3df(-296,1,4179);
    else
      pos = irr::core::vector3df(-750,1,4747);
  Enemy			*enemy
    = new Enemy(SceneManager, Device, Driver, pos);
  this->_enemy.push_back(std::make_pair(enemy, 0));
  irr::scene::ISceneNodeAnimator	*anim2
    = SceneManager->createCollisionResponseAnimator(player._selector, enemy->getMeshSceneNode(), irr::core::vector3df(15,1,15), irr::core::vector3df(0,0,0));
  enemy->getMeshSceneNode()->addAnimator(anim2);
}

void				Map::checkPlayerPos(Player &player, Core &core)
{
  irr::core::vector3df		pos
    = player.getMeshSceneNode()->getPosition();

  if (player.getCredits() < 60 && pos.Z >= 1300)
    {
      pos.Z -= 500;
      player.setPos(pos);
    }
  if (player.getCredits() < 120 && pos.Z >= 3500)
    {
      pos.Z -= 500;
      player.setPos(pos);
    }
  if (player.getCredits() < 180 && pos.Z >= 5350)
    {
      pos.Z -= 500;
      player.setPos(pos);
    }
}

void				Map::checkEnemy(Player &player, Core &core)
{
  irr::core::vector3df		diff;
  irr::core::vector3df		newPos;
  std::list<std::pair<Enemy*,int>>::iterator
    lit(this->_enemy.begin()),
    lend(this->_enemy.end());

  this->atk += 1;
  this->checkPlayerPos(player, core);
  if (this->lol%2)
    {
      for (; lit!=lend; ++lit)
	{
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
	    player.setPv(player.getPv()-0.2);
	  (*lit).first->enemyOrient(player);
	  if (player.getBallPos() && player.getAnimPos())
	    if (player.getBallPos()->getAbsolutePosition().getDistanceFrom((*lit).first->getMeshSceneNode()->getAbsolutePosition()) <= 50)
	      {
		this->checkBonus((*lit).first->getMeshSceneNode()->getPosition(), core.getSceneManager(), core.getDevice(), core.getDriver());
		this->checkSpawn(player, core.getSceneManager(), core.getDevice(), core.getDriver());
		(*lit).first->getMeshSceneNode()->remove();
		lit = this->_enemy.erase(lit);
		_meta->removeAllTriangleSelectors();
		player.setCredits(player.getCredits()+rand()%2);
		player.getBallPos()->remove();
		player.getAnimPos()->remove();
		player.setBallPos(NULL);
		player.setAnimPos(NULL);
	      }
	}
      this->lol -= 2;
    }
  if (player.getBallPos() && player.getAnimPos() && player.getTime() <= 15)
    {
      player.getBallPos()->remove();
      player.getAnimPos()->remove();
      player.setBallPos(NULL);
      player.setAnimPos(NULL);
    }
  if (player.getTime() > 0)
    player.setTime(player.getTime()-1);
  this->lol += 1;
}

void                    Map::setEnemyCollision(Core &core)
{
  std::list<std::pair<Enemy*,int>>::iterator
      lit(this->_enemy.begin()),
      lend(this->_enemy.end());
    _meta = core.getSceneManager()->createMetaTriangleSelector();
    for (; lit != lend; ++lit)
      {
        std::list<std::pair<Enemy*,int>>::iterator
	  enemy_it(this->_enemy.begin()),
	  enemy_end(this->_enemy.end());
        for (; enemy_it != enemy_end; ++enemy_it)
	  if (enemy_it != lit)
            {
	      irr::scene::ITriangleSelector *selector_enemy =
		core.getSceneManager()->createOctreeTriangleSelector(
								     (*enemy_it).first->getMesh(), (*enemy_it).first->getMeshSceneNode());
	      (*lit).first->getMeshSceneNode()->setTriangleSelector(selector_enemy);
	      _meta->addTriangleSelector((*lit).first->getMeshSceneNode()->getTriangleSelector());
	      irr::scene::ISceneNodeAnimator *anim3
		= core.getSceneManager()->createCollisionResponseAnimator(_meta,
									  (*lit).first->getMeshSceneNode(),
									  irr::core::vector3df(20, 1, 20),
									  irr::core::vector3df(0, 0, 0));
	      (*lit).first->getMeshSceneNode()->addAnimator(anim3);
            }
    }
}

void				Map::checkBonus(Player &player)
{
  std::list<std::pair<irr::scene::ISceneNode*,int>>::iterator
    lit(this->_blist.begin()),
    lend(this->_blist.end());
  for (; lit!=lend; ++lit)
    if (player.getMeshSceneNode()->getAbsolutePosition().getDistanceFrom((*lit).first->getAbsolutePosition()) < 35)
      if (player.getBonusActive() == false)
	{
	  if ((*lit).second == 9)
	    {
	      player.setSpeed(15);
	      player.setBonusTime(200);
	      player.setBonusType(1);
	      player.setBonusActive(true);
	    }
	  if ((*lit).second == 8)
	    {
	      player.getMeshSceneNode()->setScale(irr::core::vector3df(20, 20, 20));
	      player.setBonusTime(200);
	      player.setBonusType(2);
	      player.setBonusActive(true);
	    }
	  if ((*lit).second == 7)
	    {
	      player.getMeshSceneNode()->setScale(irr::core::vector3df(5, 5, 5));
	      player.setBonusTime(200);
	      player.setBonusType(2);
	      player.setBonusActive(true);
	    }
	  (*lit).first->remove();
	  lit = this->_blist.erase(lit);
	}
}
