/// ------------------------------
/// @file Obstacles.h
/// @brief obstacles class
/// @author Shannon Yang
/// @version 1.0
/// @date 2/5/16
/// -------------------------------
#ifndef OBSTACLES_H
#define OBSTACLES_H
#include <vector>
#include "rigidbody.h"

//obstacles class
class Obstacles
{
public:
  //constructor
  Obstacles();
  //destructor
  ~Obstacles();
  //draw the onstacles
  void drawLine();
  //initalise the scene, before drawing and updating
  void init();
  //draw the scene
  void draw();
  //update the scene
  void update();
  //draw circles around lines
  void drawRigidBodyLine(Vec4 _p1, Vec4 _p2);
  //vector list to hold the obstacles
  std::vector<Rigidbody> m_obstaclesRigidbodies;

private:
  //colour
  Colour colour;

};

#endif // OBSTACLES_H
