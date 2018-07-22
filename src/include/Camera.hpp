//
// Camera.hpp for Camera.hpp in /home/agaro/Epitech/cpp_indie_studio/src/include
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Tue May 16 12:32:25 2017 Agar-One
// Last update Thu May 25 15:07:50 2017 Agar-One
//

#ifndef				_CAMERA_HPP__
#define				_CAMERA_HPP__

#include			<irrlicht.h>

#include			"Player.hpp"

class				Camera
{
public:

  Camera(irr::scene::ISceneManager*);
  Camera(irr::scene::ISceneManager*, int);
  ~Camera(){};

  irr::scene::ICameraSceneNode	*getCamera();
  void				setCamera(irr::scene::ICameraSceneNode *);

  void				updatePos(Player &);

private:

  irr::scene::ICameraSceneNode	*_camera;

};

#endif				/* ! _CAMERA_HPP__ */
