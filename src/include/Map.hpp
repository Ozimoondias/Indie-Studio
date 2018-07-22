//
// Map.hpp for Mapp in /home/agaro/Epitech/cpp_indie_studio/src/include
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Tue May 16 12:48:00 2017 Agar-One
// Last update Tue Jun 13 22:58:55 2017 Agar-One
//

#ifndef				_MAP_HPP__
#define				_MAP_HPP__

#include			<irrlicht.h>

#include			<vector>
#include			<thread>
#include			<fstream>
#include			<iostream>
#include			<string>
#include			<utility>
#include			<list>

#include			"Core.hpp"
#include			"Player.hpp"
#include			"Enemy.hpp"

class				Core;
class				Player;
class				Enemy;

class				Map
{
public:

  Map(Core &, Player &, std::string, std::string);
  Map(Core &, Player &, Player &, std::string, std::string);
  ~Map(){};

  int				atk = 0;
  int				lol = 0;
  int				boom = 1;

  irr::core::vector3df		boomPos;
  irr::scene::ISceneNode	*boomMesh;

  irr::scene::IMeshSceneNode	*getMap();
  void				setMap(irr::scene::IMeshSceneNode*);

  void				buildMap(Core &, char, Player&);
  void				checkBonus(Player &);
  void				checkSpawn(Player &,
					   irr::scene::ISceneManager*,
					   irr::IrrlichtDevice*,
					   irr::video::IVideoDriver*); 
  void				checkBonus(irr::core::vector3df,
					   irr::scene::ISceneManager*,
					   irr::IrrlichtDevice*,
					   irr::video::IVideoDriver*);

  void				checkFireball(Player &, Core &, std::list<std::pair<Enemy*,int>>::iterator &);
  void				checkEnemy(Player &, Core &);
  void				checkEnemy2(Player &, Player &, Core &);

  void				BuildDeco1(irr::scene::ISceneManager*,
					   irr::IrrlichtDevice*,
					   irr::video::IVideoDriver*,
					   std::string,int,int,int);
  void				BuildDeco2(irr::scene::ISceneManager*,
					   irr::IrrlichtDevice*,
					   irr::video::IVideoDriver*,
					   std::string,int,int,int);
  void				BuildDeco3(irr::scene::ISceneManager*,
					   irr::IrrlichtDevice*,
					   irr::video::IVideoDriver*,
					   std::string,int,int,int);
  void				BuildDeco4(irr::scene::ISceneManager*,
					   irr::IrrlichtDevice*,
					   irr::video::IVideoDriver*,
					   std::string,int,int,int);
  void				BuildDeco5(irr::scene::ISceneManager*,
					   irr::IrrlichtDevice*,
					   irr::video::IVideoDriver*,
					   std::string,int,int,int);
  void				BuildDeco(irr::scene::ISceneManager*,
					  irr::IrrlichtDevice*,
					  irr::video::IVideoDriver*);

  void				checkPlayerPos(Player&,Core&);

  void				playerAttack(Player &,
					     irr::scene::ISceneManager*,
                                             irr::IrrlichtDevice*,
                                             irr::video::IVideoDriver*);
  void				playerAttack2(Player &,
					      irr::scene::ISceneManager*,
					      irr::IrrlichtDevice*,
					      irr::video::IVideoDriver*);
  void				playerAttack3(Player &,
					      irr::scene::ISceneManager*,
					      irr::IrrlichtDevice*,
					      irr::video::IVideoDriver*);
  
  void				checkTarget(Player &,Core &,std::list<std::pair<Enemy*,int>>::iterator &);
  
  void 				setEnemyCollision(Core &);
  void				upMap();
  void				test(Player &, Core &);

  std::list<std::pair<Enemy*,int>>	_enemy;
  irr::scene::IMetaTriangleSelector	*_meta;
  float					fire = false;
  
private:

  std::list<std::pair<irr::scene::ISceneNode*,int>>	_blist;

  int					x = 0;
  int					y = 0;

  irr::scene::IMeshSceneNode		*_map;
  
};

void				BuildRandDungeon();

#endif				/* ! _MAP_HPP__ */
