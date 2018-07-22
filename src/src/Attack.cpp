/*
**
**
**
**
*/

#include			"Map.hpp"

void				Map::playerAttack3(Player &player,
						   irr::scene::ISceneManager *SceneManager,
						   irr::IrrlichtDevice *Device,
						   irr::video::IVideoDriver *Driver)
{
  irr::core::vector3df		pos = player.getMeshSceneNode()->getPosition();
  irr::core::vector3df		pos2 = player.getMeshSceneNode()->getPosition();
  int				orie = player.getMeshSceneNode()->getRotation().Y;
  irr::scene::ISceneNodeAnimator	*anim2 = 0;

  this->atk = 0;
  switch (orie)
    {
    case 0:pos.Z -= 60;pos2.Z -= 200;break;
    case 90:pos.X -= 60;pos2.X -= 200;break;
    case 180:pos.Z += 60;pos2.Z += 200;break;
    case 270:pos.X += 60;pos2.X += 200;break;
    case 45:pos.Z -= 50;pos.X -= 50;pos2.Z -= 150;pos2.X -= 150;break;
    case 135:pos.X -= 50;pos.Z += 50;pos2.X -= 150;pos2.Z += 150;break;
    case 225:pos.Z += 50;pos.X += 50;pos2.Z += 150;pos2.X += 150;break;
    case 315:pos.Z -= 50;pos.X += 50;pos2.Z -= 150;pos2.X += 150;break;
    default:break;
    }
  irr::scene::IVolumeLightSceneNode	*n
    = SceneManager->addVolumeLightSceneNode(0,-1,32,32,
					    irr::video::SColor(0, 255, 255, 255),
					    irr::video::SColor(0, 0, 0, 0));
  if (n)
    {
      n->setScale(irr::core::vector3df(200,130,200));
      n->setPosition(pos2);
      irr::core::array<irr::video::ITexture*> textures;
      for (irr::s32 g=7; g > 0; --g)
	{
	  irr::core::stringc tmp;
	  tmp = "../src/media/Fire/portal";
	  tmp += g;
	  tmp += ".bmp";
	  irr::video::ITexture* t = Driver->getTexture( tmp.c_str() );
	  textures.push_back(t);
	}
      irr::scene::ISceneNodeAnimator* glow = SceneManager->createTextureAnimator(textures, 150);
      n->addAnimator(glow);
      glow->drop();
      anim2 = SceneManager->createDeleteAnimator(600);
      n->addAnimator(anim2);
      anim2->drop();
    }
  if (n)
    {
      std::list<std::pair<Enemy*,int>>::iterator
	lit(this->_enemy.begin()),
	lend(this->_enemy.end());
      for (; lit != lend; ++lit)
	{
	  if ((*lit).first->getMeshSceneNode()->getAbsolutePosition().getDistanceFrom(n->getPosition()) <= 100)
	    {
	      this->checkSpawn(player, SceneManager, Device, Driver);
	      this->checkBonus((*lit).first->getMeshSceneNode()->getPosition(), SceneManager, Device, Driver);
	      (*lit).first->getMeshSceneNode()->remove();
	      lit = this->_enemy.erase(lit);
	      _meta->removeAllTriangleSelectors();		    
	      player.setCredits(player.getCredits()+rand()%2);
	    }
	}
    }
}

void				Map::playerAttack2(Player &player,
						   irr::scene::ISceneManager *SceneManager,
						   irr::IrrlichtDevice *Device,
						   irr::video::IVideoDriver *Driver)
{
  irr::scene::ISceneNode	*node = 0;
  irr::core::vector3df		pos = player.getMeshSceneNode()->getPosition();
  irr::core::vector3df		pos2 = player.getMeshSceneNode()->getPosition();
  int				orie = player.getMeshSceneNode()->getRotation().Y;
  irr::scene::ISceneNodeAnimator
    *anim = 0;

  if (this->atk >= 50)
    {
      this->atk = 0;
      switch (orie)
	{
	case 0:pos.Z -= 55;pos.Y += 10;pos2.Z -= 400;pos2.Y += 10;break;
	case 90:pos.X -= 55;pos.Y += 10;pos2.X -= 400;pos2.Y += 10;break;
	case 180:pos.Z += 55;pos.Y += 10;pos2.Z += 400;pos2.Y += 10;break;
	case 270:pos.X += 55;pos.Y += 10;pos2.X += 400;pos2.Y += 10;break;
	case 45:pos.Z -= 55;pos.X -= 55;pos.Y += 10;pos2.Z -= 400;pos2.X -= 400;pos2.Y += 10;break;
	case 135:pos.X -= 55;pos.Z += 55;pos.Y += 10;pos2.X -= 400;pos2.Z += 400;pos2.Y += 10;break;
	case 225:pos.Z += 55;pos.X += 55;pos.Y += 10;pos2.Z += 400;pos2.X += 400;pos2.Y += 10;break;
	case 315:pos.X += 55;pos.Z -= 55;pos.Y += 10;pos2.X += 400;pos2.Z -= 400;pos2.Y += 10;break;
	default:break;
	}
      node = SceneManager->addBillboardSceneNode(0,irr::core::dimension2d<irr::f32>(50,50),pos);
      if (node)
	{
	  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  node->setMaterialTexture(0, Device->getVideoDriver()->getTexture("../src/media/Fire/fireball.bmp"));
	  node->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	}
      irr::f32			speed = 0.6f;
      irr::f32			length = (irr::f32)(pos2-pos).getLength();
      irr::u32			time = (irr::u32)(length/speed);
      anim = SceneManager->createFlyStraightAnimator(pos,pos2,time);

      irr::scene::IParticleSystemSceneNode* ps = 
	SceneManager->addParticleSystemSceneNode(false);

      if (ps)
	{
	  irr::scene::IParticleEmitter* em = ps->createBoxEmitter(irr::core::aabbox3d<irr::f32>(-7,0,-7,7,7,7),irr::core::vector3df(0,0,0),
								  80,170,irr::video::SColor(0,255,255,255),irr::video::SColor(0,255,255,255),
								  800,2000,0,irr::core::dimension2df(10,10),irr::core::dimension2df(12.f,12.f));
	  ps->setEmitter(em);
	  em->drop();
	  irr::scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();
	  ps->addAffector(paf);
	  paf->drop();
	  ps->setPosition(pos);
	  ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	  ps->setMaterialTexture(0, Driver->getTexture("../src/media/Fire/fire.bmp"));
	}
      node->addAnimator(anim);
      ps->addAnimator(anim);
      anim->drop();
      player.setBallPos(node);
      player.setAnimPos(ps);
      player.setTime(40);
    }
}

void				Map::playerAttack(Player &player,
						  irr::scene::ISceneManager *SceneManager,
						  irr::IrrlichtDevice *Device,
						  irr::video::IVideoDriver *Driver)
{
  irr::scene::IMeshSceneNode	*wall_am = NULL;
  irr::core::vector3df		pos = player.getMeshSceneNode()->getPosition();
  int				orie = player.getMeshSceneNode()->getRotation().Y;

  this->atk = 0;
  wall_am = SceneManager->addCubeSceneNode(0);
  switch (orie)
    {
    case 0:pos.Z -= 30;break;
    case 90:pos.X -= 30;break;
    case 180:pos.Z += 30;break;
    case 270:pos.X += 30;break;
    default:break;
    }
  wall_am->setPosition(pos);
  wall_am->setMaterialFlag(irr::video::EMF_LIGHTING,false);
  if (wall_am)
    {
      std::list<std::pair<Enemy*,int>>::iterator
	lit(this->_enemy.begin()),
	lend(this->_enemy.end());
      for (; lit!=lend; ++lit)
	if ((*lit).first->getMeshSceneNode()->getAbsolutePosition().getDistanceFrom(wall_am->getPosition()) <= 40)
	  {
	    this->checkBonus((*lit).first->getMeshSceneNode()->getPosition(), SceneManager, Device, Driver);
	    this->checkSpawn(player, SceneManager, Device, Driver);
	    (*lit).first->getMeshSceneNode()->remove();
	    lit = this->_enemy.erase(lit);
	    player.setCredits(player.getCredits()+rand()%2);
	  }
      _meta->removeAllTriangleSelectors();
      wall_am->remove();
    }
}
