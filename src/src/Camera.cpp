//
// Camera.cpp for Camera in /home/agaro/Epitech/cpp_indie_studio/src/src
//
// Made by Agar-One
// Login   <agaro@epitech.net>
//
// Started on  Tue May 16 12:39:27 2017 Agar-One
// Last update Tue Jun 13 13:48:29 2017 Agar-One
//

#include			"Camera.hpp"

Camera::Camera(irr::scene::ISceneManager *SceneManager)
{
  this->setCamera(SceneManager->addCameraSceneNode());
}

Camera::Camera(irr::scene::ISceneManager *SceneManager, int ratio)
{
  this->setCamera(SceneManager->addCameraSceneNode());
  this->_camera->setAspectRatio(ratio);
}

irr::scene::ICameraSceneNode	*Camera::getCamera()
{
  return (this->_camera);
}

void				Camera::setCamera(irr::scene::ICameraSceneNode *camera)
{
  this->_camera = camera;
}

void				Camera::updatePos(Player &player)
{
  irr::core::vector3df		vec = player.getPos();

  vec.Y += 300;
  vec.Z -= 80;
  this->getCamera()->setPosition(vec);
  this->getCamera()->setTarget(player.getPos());
}
