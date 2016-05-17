#include "rigidbody.h"
#include "obstacles.h"
#include "colours.h"

///-------------------------------
/// @brief Rigid body constructor.
/// @param pos
/// @param r    //radius
/// @param _r   //red
/// @param _g
/// @param _b
/// @param mass
/// -----------------------------
Rigidbody::Rigidbody(Vec4 pos, float r, GLfloat _r,GLfloat _g,GLfloat _b):mass(1.0f)
{
  m_position=pos;
  radius=r;
  colour.r = _r;
  colour.g = _g;
  colour.b = _b;
  // GRAVITY
  acceleration = Vec4(0,-0.00098);
  m_velocity = Vec4 (0.0,-0.000005); // initial velocity
}
///------------------------------
/// @brief Rigid body destructor
/// -----------------------------
Rigidbody::~Rigidbody()
{

}
///-------------------------------------
/// @brief Set the position of the ball
/// @param _position
/// ------------------------------------
void Rigidbody::setPosition(Vec4 _position)
{
  m_position=_position;
}
///---------------------------------------------------------------------
/// @brief Get the position of the ball and returns to the next position
/// --------------------------------------------------------------------
Vec4 Rigidbody::getPosition()
{
  return m_position;
}
///------------------------------------------------------------
/// @brief Draw the circle with a radius and its centre point
/// @param r
/// @param k  //centre of circle
/// @param h  //centre of circle
///-----------------------------------------------------------
void Rigidbody::drawCircle(float r,float k, float h)
{

  Circle circle;

  glPushMatrix();
  glLineWidth(8.5f);
  glColor3f(colour.r, colour.g, colour.b);
  glBegin(GL_LINES);

  //create half circles(180 degrees) and connecting them together with a loop
  for (int i = 0; i < 180; i++)
    {
    // drawing in position
    circle.x = r * cos(i);// - h;
    circle.y = r * sin(i);// + k;
    glVertex3f(circle.x + k,circle.y + h,0);

    circle.x = r * cos(i + 0.1);// - h;
    circle.y = r * sin(i + 0.1);// + k;
    glVertex3f(circle.x + k,circle.y + h,0);

    }
    glEnd();

  glPopMatrix();

}

///-----------------------------------------
/// @brief Apply any given force to the body
/// @param force
///----------------------------------------
void Rigidbody::applyForce(Vec4 force)
{
  m_force += force;

}
///-------------------------
/// @brief Set the velocity
/// @param _velocity
///------------------------
void Rigidbody::setVelocity(Vec4 _velocity)
{
  m_velocity=_velocity;
}
///-------------------------
/// @brief Add the velocity
/// @param _addvelocity
///------------------------
void Rigidbody::addVelocity(Vec4 _addvelocity)
{
  m_velocity+=_addvelocity;
}
///-------------------------
/// @brief Get the velocity
/// @param _getvelocity
/// @return m_velocity
///------------------------
Vec4 Rigidbody::getVelocity()
{
  return m_velocity;
}

///----------------------
/// @brief Draw function
///----------------------
void Rigidbody::draw()
{
  glColor3f(colour.r, colour.g, colour.b);
  glPushMatrix();
  //translate for the circle to move around
  glTranslatef(m_position.m_x,m_position.m_y,m_position.m_z);
  drawCircle(radius, 1.0f, 1.0f);
  glPopMatrix();
}
///-----------------------
/// @brief Update function
///-----------------------
void Rigidbody::update()
{
  m_velocity+=acceleration;
  //the new position is the velocity change after each time-step
  m_position+=m_velocity;

}

