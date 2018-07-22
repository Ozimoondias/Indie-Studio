/*
**
**
**
**
**
*/

#include			"Map.hpp"

#include			<iostream>

void				Map::BuildDeco1(irr::scene::ISceneManager *SceneManager,
					       irr::IrrlichtDevice *Device,
					       irr::video::IVideoDriver *Driver,
					       std::string deco,int x,int y,int z)
{
  irr::scene::IAnimatedMesh		*wall_ma;
  irr::scene::IAnimatedMeshSceneNode	*wall_ama;
  
  wall_ma = SceneManager->getMesh(deco.c_str());
  wall_ama = SceneManager->addAnimatedMeshSceneNode(wall_ma);
  if (wall_ama)
    {
      wall_ama->setPosition(irr::core::vector3df(x,5,z));
      wall_ama->setRotation(irr::core::vector3df(0,y,0));
      wall_ama->setScale(irr::core::vector3df(50,50,50));
      wall_ama->setMaterialFlag(irr::video::EMF_LIGHTING,false);
    }
}

void				Map::BuildDeco(irr::scene::ISceneManager *SceneManager,
					       irr::IrrlichtDevice *Device,
					       irr::video::IVideoDriver *Driver)
{
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/WoodenTiki/tiki_wooden_bind.obj",965,225,-545);
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/WoodenTiki/tiki_wooden_bind.obj",-950,135,-540);
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/WoodenTiki/tiki_wooden_bind.obj",-950,135,820);

  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/ShhhhTiki/tiki_shhhh_bind.obj",-531,180,2844);
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/ShhhhTiki/tiki_shhhh_bind.obj",655,180,3042);
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/ShhhhTiki/tiki_shhhh_bind.obj",-950,90,1900);
  
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/StoneTiki/tiki_stone_bind.obj",204,225,4606);
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/StoneTiki/tiki_stone_bind.obj",-880,135,4606);
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/StoneTiki/tiki_stone_bind.obj",-450,90,4180);
  
  /*BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/FloatingTiki/tiki_lovey_dovey_bind.obj",965,225,-545);
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/BetaThunderTiki/tiki_thunder_bind.obj",-950,135,-540);
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/ShhhhTiki/tiki_shhhh_bind.obj",-950,135,820);
  
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/FloatingTiki/tiki_lovey_dovey_bind.obj",965,225,-545);
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/BetaThunderTiki/tiki_thunder_bind.obj",-950,135,-540);
  BuildDeco1(SceneManager,Device,Driver,"../src/media/Décor/Tikis/ShhhhTiki/tiki_shhhh_bind.obj",-950,135,820);*/
}
