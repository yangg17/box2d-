#include "easymaze.h"
#include <SDL2/SDL.h>
///--------------------
/// @brief Constructor
///--------------------
Easymaze::Easymaze()
{

}
///--------------------
/// @brief Constructor
///--------------------
Easymaze::~Easymaze()
{

}
///--------------------------
/// @brief Draw the Obstacles
///--------------------------
void Easymaze::drawLine()
{
  //glLineWidth(10.0);

  glBegin(GL_LINES);

  //the slope top right
  glColor3f(1.0,0.5,0.0);
  glVertex3f(12.0,6.0,0.0); //start point
  glVertex3f(3.0,3.0,0.0); //end point

  //slope buttom right
  glColor3f(0.5,1.0,0.0);
  glVertex3f(9.0,-4.0,0.0);
  glVertex3f(3.0,-6.0,0.0);


  //slope top left
  glColor3f(1.0,0.5,0.0);
  glVertex3f(-12.0,6.0,0.0);
  glVertex3f(-3.0,3.0,0.0);


  //slope buttom left
  glColor3f(0.5,1.0,0.0);
  glVertex3f(-9.0,-4.0,0.0);
  glVertex3f(-3.0,-6.0,0.0);

  //slope middle button
  glColor3f(1.0,0.5,0.0);
  glVertex3f(2.0,-3.0,0.0);
  glVertex3f(-2.0,-3.0,0.0);

  //slope middle top
  glColor3f(0.5,1.0,0.0);
  glVertex3f(3.0,1.0,0.0);
  glVertex3f(-3.0,1.0,0.0);

  glEnd();
  //glColor3b(1.0,0.5,0.0);
  glLineWidth(3.0);
}

