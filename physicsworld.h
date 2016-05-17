/// ------------------------------
/// @file Physicsworld.h
/// @brief Physicsworld class
/// @author Shannon Yang
/// @version 1.0
/// @date 2/5/16
/// -------------------------------
#ifndef PHYSICSWORLD_H
#define PHYSICSWORLD_H
#include<sys/time.h>
#include <GLFunctions.h>
#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include "rigidbody.h"
#include "stdlib.h"
#include "easymaze.h"
#include"obstacles.h"
#include <vector>

//physicsworld class
class Physicsworld
{

public:
  //constructor
  Physicsworld();
  //destructor, virtual function will call the destructor from derived class
 ~Physicsworld();
  //struct to hold the intersection elements
  struct Intersection{float x; //x
                      float y; //y
                      float dist; //distance
                     };
  // initialise the scene
  void init();
  //resize the window
  void resize(int w, int h );
  //add pink object
  void addPinkObject(Vec4 pos, Vec4 vel);
  //add blue object
  void addBlueObject(Vec4 pos, Vec4 vel);
  //add yellow object
  void addYellowObject(Vec4 pos,Vec4 vel);
  //add white object
  void addWhiteObject(Vec4 pos,Vec4 vel);
  //add obstacles
  void addObstacles();
  //redraw the scene
  void draw();
  //update the scene
  void update();
  //check the intersection between obstacles and circle
  bool intersectObstacles();
  //chekc the intersection between cirlces
  bool intersectCircle(Rigidbody &p1, Rigidbody &p2, float r1, float r2);
  //final collision detection between everything that is drawn in the scene
  void collisionDetection();
  //holds the colour
  Colour colour;

private:
  //boolean value
  bool m_isInit;
  //manage list of object
  std::vector<Rigidbody> Objectslist;
  //manage the list for the map
  std::vector<Obstacles> MapList;
  //int
  int m_mapSelect;


};

#endif // PHYSICSWORLD_H
