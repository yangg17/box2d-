/// ------------------------------
/// @file Rigidbody.h
/// @brief rigidbody class
/// @author Shannon Yang
/// @version 1.0
/// @date 2/5/16
/// -------------------------------
#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "math.h"
#include<sys/time.h>
#include <GLFunctions.h>
#include <iostream>
#include "Vec4.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <vector>
#include "colours.h"


class Rigidbody
{
public:
  //A rigidbody constructor
  Rigidbody(Vec4 pos, float r, GLfloat _r, GLfloat _g, GLfloat _b);
  //A rigidbody destructor
  ~Rigidbody();
  //A struct to hold circle
  struct Circle
  {
    float x; //x
    float y; //y
  };
  //Set the position
  void setPosition(Vec4 _position);
  //Get position using Vec4
  Vec4 getPosition();
  //Draw circle
  void drawCircle(float r, float k, float h);
  //Apply force
  void applyForce(Vec4 force);
  //Set velocity
  void setVelocity(Vec4 _velocity);
  //Add velocity
  void addVelocity(Vec4 _addvelocity);
  //Get velocity
  Vec4 getVelocity();

  // Draw function
  void draw();
  //Update function
  void update();
  //store the colour
  Colour colour;

private:
  // float
  float radius;
  //Vec4
  Vec4 acceleration;
  //Float
  float mass;
  //Vec4
  Vec4 m_position;
  //Vec4
  Vec4 m_velocity;
  //Vec4
  Vec4 m_force;
  //Vec4
  Vec4 gravity;


};

#endif // RIGIDBODY_H
