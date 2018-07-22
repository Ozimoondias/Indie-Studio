//
// Map.cpp for Map.cpp in /home/agaro/Epitech/cpp_indie_studio/src/src
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Tue May 16 12:53:23 2017 Agar-One
// Last update Wed Jun  7 12:41:46 2017 Agar-One
//

#include			"Map.hpp"

#include			<iostream>

class				Dungeon;

void				Map::buildEnemy(Core &core, char key, Player &player)
{
  switch (key)
    {
    case '+':
      {
	int			ra = rand() % 10 + 1;
	if (ra <= 7 && ra >= 3)
	  {
	    irr::scene::IAnimatedMesh		*wall_m;
	    irr::scene::IAnimatedMeshSceneNode	*wall_am;
	    switch (ra)
	      {
	      case 6:
		{
		  wall_m = core.getSceneManager()->getMesh("../src/media/Mario/skharry_bottleMesh.obj");
		  wall_am = core.getSceneManager()->addAnimatedMeshSceneNode(wall_m);
		  if (wall_am)
		    {
		      wall_am->setMaterialTexture(0, core.getDriver()->getTexture("../src/media/Mario/9HGKqwP.jpeg"));
		      wall_am->setPosition(irr::core::vector3df(x, 10, y));
		      wall_am->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS,true);
		      wall_am->setMaterialFlag(irr::video::EMF_LIGHTING,false);
		      wall_am->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
		    }
		  this->_blist.push_back(std::make_pair(wall_am, 9));
		  break;
		}
	      case 4:
		{
		  wall_m = core.getSceneManager()->getMesh("../src/media/Mario/skharry_bottleMesh.obj");
		  wall_am = core.getSceneManager()->addAnimatedMeshSceneNode(wall_m);
		  if (wall_am)
		    {
		      wall_am->setMaterialTexture(0, core.getDriver()->getTexture("../src/media/Mario/skharry_bottleTex0.png"));
		      wall_am->setPosition(irr::core::vector3df(x, 10, y));
		      wall_am->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS,true);
		      wall_am->setMaterialFlag(irr::video::EMF_LIGHTING,false);
		      wall_am->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
		    }
		  this->_blist.push_back(std::make_pair(wall_am, 8));
		  break;
		}
	      case 2:
		{
		  wall_m = core.getSceneManager()->getMesh("../src/media/Mario/skharry_bottleMesh.obj");
		  wall_am = core.getSceneManager()->addAnimatedMeshSceneNode(wall_m);
		  if (wall_am)
		    {
		      wall_am->setMaterialTexture(0, core.getDriver()->getTexture("../src/media/Mario/3umMoI1.jpeg"));
		      wall_am->setPosition(irr::core::vector3df(x, 10, y));
		      wall_am->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS,true);
		      wall_am->setMaterialFlag(irr::video::EMF_LIGHTING,false);
		      wall_am->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
		    }
		  this->_blist.push_back(std::make_pair(wall_am, 7));
		  break;
		}
	      default:
		break;
	      }
	  }
	x += 40;
	break;
      }
    default:
      {
	x += 40;
	break;
      }
    }
}

void				Map::testMap(Core &core, std::string map, Player &player)
{
  int				i = 0;

  while (map[i])
    {
      this->buildEnemy(core, map[i], player);
      i += 1;
    }
  this->y += 40;
  this->x = 0;
}

void                    Map::setEnemyCollision(Core &core)
{
  std::list<std::pair<Enemy*,int>>::iterator
    lit(this->_enemy.begin()),
    lend(this->_enemy.end());
  for (; lit != lend; ++lit)
    {
      //(*lit).first->getMeshSceneNode()->removeAnimators(); //clear la liste d'animators
      std::list<std::pair<Enemy*,int>>::iterator
	enemy_it(this->_enemy.begin()),
	enemy_end(this->_enemy.end());
      for (; enemy_it != enemy_end; ++enemy_it)
	if (enemy_it != lit)
	  {
	    irr::scene::ITriangleSelector *selector_enemy =
	      core.getSceneManager()->createOctreeTriangleSelector(
								   (*enemy_it).first->getMesh(), (*enemy_it).first->getMeshSceneNode());
	    (*lit).first->setSelector(selector_enemy);
	    (*lit).first->getMeshSceneNode()->setTriangleSelector(selector_enemy);

	    irr::scene::ISceneNodeAnimator *anim3
	      = core.getSceneManager()->createCollisionResponseAnimator(selector_enemy,
									(*lit).first->getMeshSceneNode(),
									irr::core::vector3df(20, 20, 20),
									irr::core::vector3df(0, 0, 0));
	    (*lit).first->getMeshSceneNode()->addAnimator(anim3);
          //(*lit).first->getMeshSceneNode()->removeAnimators();
	  }
    }
}

void					Map::buildMap(Core &core, char key, Player &player)
{
  irr::scene::ISceneNode		*wall;
  irr::scene::IAnimatedMesh		*wall_m;
  irr::scene::IAnimatedMeshSceneNode	*wall_am;
  irr::scene::ITriangleSelector         *selector = 0;

  switch (key)
    {
    case 'H':
      {
	player.setPos(irr::core::vector3df(x, 10, y));
	this->x += 40;
	break;
      }
    case '#':
      {
	int				ra = rand() % 21 + 1;
	wall_m = core.getSceneManager()->getMesh("../src/media/wall.b3d");
	wall_am = core.getSceneManager()->addAnimatedMeshSceneNode(wall_m);
	if (wall_am)
	  {
	    if (ra <= 11)
	      if (ra % 2 != 0)
		wall_am->setMaterialTexture(0, core.getDriver()->getTexture("../src/media/texture_wall.png"));
	      else
		wall_am->setMaterialTexture(0, core.getDriver()->getTexture("../src/media/texture_wall2.png"));
	    else
	      if (ra % 2 != 0)
		wall_am->setMaterialTexture(0, core.getDriver()->getTexture("../src/media/texture_wall2.png"));
	      else
		wall_am->setMaterialTexture(0, core.getDriver()->getTexture("../src/media/texture_wall.png"));
	    wall_am->setPosition(irr::core::vector3df(x, 50, y));
	    wall_am->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS,true);
	    wall_am->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
	    wall_am->setMaterialFlag(irr::video::EMF_LIGHTING,true);
	    wall_am->setScale(irr::core::vector3df(20, ra+50, 20));
	    selector = core.getSceneManager()->createOctreeTriangleSelector(wall_m, wall_am);
	    std::list<std::pair<Enemy*,int>>::iterator
	      lit(this->_enemy.begin()),
	      lend(this->_enemy.end());
	    for (; lit!=lend; ++lit)
	      {
		    (*lit).first->setSelector(selector);
		    (*lit).first->getMeshSceneNode()->setTriangleSelector(selector);
	      }
	    player.setSelector(selector);
	    player.getMeshSceneNode()->setTriangleSelector(selector);
	  }
	this->x += 40;
	break;
      }
    default:
      {
	int			ra = rand() % 50 + 1;
	if (ra == 25)
	  {
	    Enemy		*enemy
	      = new Enemy(core.getSceneManager(), core.getDevice(), core.getDriver(), irr::core::vector3df(x, 10, y));
	    this->_enemy.push_back(std::make_pair(enemy, 0));
	    enemy->setPos(irr::core::vector3df(x, 10, y));
	  }
	this->x += 40;
	break;
      }
    }
  if (selector)
    {
      irr::scene::ISceneNodeAnimator *anim
	= core.getSceneManager()->createCollisionResponseAnimator(selector, player.getMeshSceneNode(), irr::core::vector3df(20, 20, 20),irr::core::vector3df(0, 0, 0));
      player.getMeshSceneNode()->addAnimator(anim);
      std::list<std::pair<Enemy*,int>>::iterator
	lit(this->_enemy.begin()),
	lend(this->_enemy.end());
      for (; lit != lend; ++lit)
        {
	  irr::scene::ISceneNodeAnimator* anim2
	    = core.getSceneManager()->createCollisionResponseAnimator(selector, (*lit).first->getMeshSceneNode(), irr::core::vector3df(20,20,20), irr::core::vector3df(0,0,0));
	  (*lit).first->getMeshSceneNode()->addAnimator(anim2);
	}
    }
}

void				Map::parseMap(Core &core, std::string map, Player &player)
{
  int				i = 0;

  while (map[i])
    {
      this->buildMap(core, map[i], player);
      i += 1;
    }
  this->y += 40;
  this->x = 0;
}

void				Map::loadMap(Core &core, std::string path, Player &player)
{
  srand (time(NULL));
  std::vector<std::string>	map;
  std::string			line;
  std::ifstream			myfile;

  BuildRandDungeon();
  myfile.open(path);
  if (myfile)
    while (getline(myfile, line))
      map.push_back(line);
  for (std::vector<std::string>::iterator	i = map.begin(); i != map.end(); ++i)
    this->testMap(core, *i, player);
  this->x = 0;
  this->y = 0;
  for (std::vector<std::string>::iterator	i = map.begin(); i != map.end(); ++i)
    this->parseMap(core, *i, player);
  irr::scene::ITerrainSceneNode	*terrain
    = core.getSceneManager()->addTerrainSceneNode("../src/media/index.png",0,-1,
						  irr::core::vector3df(5.f,0.f,5.f),
						  irr::core::vector3df(0.f,0.f,0.f),
						  irr::core::vector3df(5, 0.f, 5));
  terrain->setMaterialFlag(irr::video::EMF_LIGHTING, true);
  terrain->setMaterialTexture(0, core.getDriver()->getTexture("../src/media/groond.jpg"));
  myfile.close();
}

void				Map::checkEnemy(Player &player, Core &core)
{
  irr::core::vector3df		diff;
  irr::core::vector3df		newPos;
  std::list<std::pair<Enemy*,int>>::iterator
    lit(this->_enemy.begin()),
    lend(this->_enemy.end());

  if (this->lol%2)
    {
      for (; lit!=lend; ++lit)
	{
	  if (player.getMeshSceneNode()->getAbsolutePosition().getDistanceFrom((*lit).first->getMeshSceneNode()->getAbsolutePosition()) <= 70)
	    {
	      if ((*lit).second == 0
		  || (*lit).second == 1)
		{
		  (*lit).first->setFrame(36, 56);
		  (*lit).first->getMeshSceneNode()->setLoopMode(true);
		  (*lit).second = 2;
		}
	    }
	  else if (player.getMeshSceneNode()->getAbsolutePosition().getDistanceFrom((*lit).first->getMeshSceneNode()->getAbsolutePosition()) <= 2000)
	    {
	      diff = player.getMeshSceneNode()->getPosition() - (*lit).first->getMeshSceneNode()->getPosition();
	      newPos = (*lit).first->getMeshSceneNode()->getPosition();
	      newPos.Y = 0;
	      if ((*lit).first->getMeshSceneNode()->getPosition().X <= player.getMeshSceneNode()->getPosition().X)
		newPos.X += (*lit).first->getSpeed();
	      if ((*lit).first->getMeshSceneNode()->getPosition().X >= player.getMeshSceneNode()->getPosition().X)
		newPos.X -= (*lit).first->getSpeed();
	      if ((*lit).first->getMeshSceneNode()->getPosition().Z <= player.getMeshSceneNode()->getPosition().Z)
		newPos.Z += (*lit).first->getSpeed();
	      if ((*lit).first->getMeshSceneNode()->getPosition().Z >= player.getMeshSceneNode()->getPosition().Z)
		newPos.Z -= (*lit).first->getSpeed();
	      if ((*lit).second == 0
		  || (*lit).second == 2)
		{
		  (*lit).first->setFrame(1, 33);
		  (*lit).first->getMeshSceneNode()->setLoopMode(true);
		  (*lit).second = 1;
		}
	      (*lit).first->getMeshSceneNode()->setPosition(newPos);
	    }
	  (*lit).first->enemyOrient(player);
	}
      this->lol -= 2;
    }
  this->lol += 1;
}

void				Map::playerAttack(Player &player, irr::scene::ISceneManager *SceneManager, irr::IrrlichtDevice *Device, irr::video::IVideoDriver *Driver)
{
  irr::scene::IMeshSceneNode	*wall_am = NULL;
  irr::core::vector3df		pos = player.getMeshSceneNode()->getPosition();
  int				orie = player.getMeshSceneNode()->getRotation().Y;

  switch (orie)
    {
    case 0:
      {
	wall_am = SceneManager->addCubeSceneNode(0);
	if (wall_am)
	  {
	    pos.Z -= 55;
	    wall_am->setPosition(pos);
	    wall_am->setMaterialFlag(irr::video::EMF_LIGHTING,false);
	  }
	break;
      }
    case 90:
      {
	wall_am = SceneManager->addCubeSceneNode(0);
	if (wall_am)
	  {
	    pos.X -= 55;
	    wall_am->setPosition(pos);
	    wall_am->setMaterialFlag(irr::video::EMF_LIGHTING,false);
	  }
	break;
      }
    case 180:
      {
	wall_am = SceneManager->addCubeSceneNode(0);
	if (wall_am)
	  {
	    pos.Z += 55;
	    wall_am->setPosition(pos);
	    wall_am->setMaterialFlag(irr::video::EMF_LIGHTING,false);
	  }
	break;
      }
    case 270:
      {
	wall_am = SceneManager->addCubeSceneNode(0);
	if (wall_am)
	  {
	    pos.X += 55;
	    wall_am->setPosition(pos);
	    wall_am->setMaterialFlag(irr::video::EMF_LIGHTING,false);
	  }
	break;
      }
    default:
      break;
    }
  if (wall_am)
    {
      std::list<std::pair<Enemy*,int>>::iterator
	lit(this->_enemy.begin()),
	lend(this->_enemy.end());
      for (; lit!=lend; ++lit)
	if ((*lit).first->getMeshSceneNode()->getAbsolutePosition().getDistanceFrom(wall_am->getPosition()) <= 20)
	  {
		  //il faut rm le selector de scene manager
		  /*core.getSceneManager()->createOctreeTriangleSelector(
				  (*enemy_it).first->getMesh(), (*enemy_it).first->getMeshSceneNode());*/
		  //SceneManager->
          (*lit).first->getMeshSceneNode()->removeAnimators(); //clear la liste d'animators
		  (*lit).first->getMeshSceneNode()->remove();
		  lit = this->_enemy.erase(lit);
	  }
		wall_am->removeAnimators();
		wall_am->remove();
	}
}

void				Map::checkBonus(Player &player)
{
  std::list<std::pair<irr::scene::ISceneNode*,int>>::const_iterator
    lit(this->_blist.begin()), lend(this->_blist.end());
  for (; lit!=lend; ++lit)
    if (player.getMeshSceneNode()->getAbsolutePosition().getDistanceFrom((*lit).first->getAbsolutePosition()) < 35)
      {
	if ((*lit).second == 9)
	  player.setSpeed(15);
	if ((*lit).second == 8)
	  player.getMeshSceneNode()->setScale(irr::core::vector3df(20, 20, 20));
	if ((*lit).second == 7)
	  player.getMeshSceneNode()->setScale(irr::core::vector3df(5, 5, 5));
	(*lit).first->remove();
	lit = this->_blist.erase(lit);
      }
}
