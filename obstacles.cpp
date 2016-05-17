#include "obstacles.h"
#include "physicsworld.h"
#include "easymaze.h"
#include "colours.h"

///-----------------------------
/// @brief Obstacles constructor
/// ----------------------------
Obstacles::Obstacles()
{

  drawRigidBodyLine(Vec4(12.0f,6.0f,0.0f),Vec4(3.0f,3.0f,0.0f));
  drawRigidBodyLine(Vec4(9.0f,-4.0f,0.0f),Vec4(3.0f,-6.0f,0.0f));
  drawRigidBodyLine(Vec4(-12.0f,6.0f,0.0f),Vec4(-3.0f,3.0f,0.0f));
  drawRigidBodyLine(Vec4(-9.0f,-4.0f,0.0f),Vec4(-3.0f,-6.0f,0.0f));
  drawRigidBodyLine(Vec4(2.0f,-3.0f,0.0f),Vec4(-2.0f,-3.0f,0.0f));
  drawRigidBodyLine(Vec4(3.0f,1.0f,0.0f),Vec4(-3.0f,1.0f,0.0f));

}
///-----------------------------
/// @brief Obstacles destructor
/// ----------------------------
Obstacles::~Obstacles()
{

}
///-------------------------------------------------------------------------
/// @brief Draw circles around the obstacles for collision detection.
/// @brief The circles are iterated 100 times with equally distanced radius
/// @param [in]_p1
/// @param [in]_p2
/// -------------------------------------------------------------------------
void Obstacles::drawRigidBodyLine(Vec4 _p1, Vec4 _p2)
{
  Vec4 direction = _p2-_p1;
  Vec4 currentpos = _p1;
  for(int i = 0; i<100 ; ++i)
  {
    currentpos=direction*((float)i/100.f) + _p1;
    m_obstaclesRigidbodies.push_back(Rigidbody(Vec4(currentpos[0],
                                               currentpos[1],
                                                0.0f),
                                                1.0f,
                                                colour.pink().r,
                                                colour.pink().g,
                                                colour.pink().b));
    glEnd();
  }
}

///----------------------------
/// @brief Draw obstacles line
/// ---------------------------
void Obstacles::drawLine()
{
  glPushMatrix();
  glLineWidth(10.0);

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

  glLineWidth(3.0);
  glPopMatrix();

}
///----------------------------
/// @brief Initalise Function
/// ----------------------------
void Obstacles::init()
{

}
///----------------------
/// @brief Draw Function
/// ---------------------
void Obstacles::draw()
{
  drawLine();
}
///----------------------
/// @brief Update Function
/// ---------------------
void Obstacles::update()
{

}
