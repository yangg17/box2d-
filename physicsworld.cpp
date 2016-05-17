#include "physicsworld.h"
#include "rigidbody.h"
#include <sys/time.h>
#include "Vec4.h"

///////////////////////////////////////
/// @brief Constructor for the world
//////////////////////////////////////
Physicsworld::Physicsworld()
{


}
//////////////////////////////////////
///@brief Deconstructor for the world
//////////////////////////////////////
Physicsworld::~Physicsworld()
{

}
/////////////////////////////////////////////////////////////////
/// @brief Enable with lighting and texture for behind the scene.
/////////////////////////////////////////////////////////////////
void Physicsworld::init()
{
  if (m_isInit) return;

  // Enable texturing
  glDisable(GL_TEXTURE_2D);

  // Enable counter clockwise face ordering
  glFrontFace(GL_CCW);

  //glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);
  glEnable( GL_POINT_SMOOTH );
  glEnable( GL_MULTISAMPLE_ARB);
  glEnable(GL_DEPTH_TEST);

  m_isInit = true;

  //initalise the obstacles
  addObstacles();


}

///////////////////////////////////////////////////////////////////
/// @brief Camera view and projection for the scene
/// @param w the width of t,m_startTime(0.0),m_elapsedTime(0.0)
/// @param h the height of the screen
////////////////////////////////////////////////////////////////////
void Physicsworld::resize(int w, int h)
{
  if (!m_isInit) return;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(float(w) / float(h)*-10.0,float(w) / float(h)*10.0,-10.0,10.0,0.1,10.0);
  //gluPerspective(60.0, float(w) / float(h), 0.1, 10.0);
  gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);

  glViewport(0,0,w,h);

  glMatrixMode(GL_MODELVIEW);
}
//////////////////////////////////////////////////////////////////////
/// @brief Add the circle and assign the position and radius with pink
/// @param pos
/// @param vel
//////////////////////////////////////////////////////////////////////
void Physicsworld::addPinkObject(Vec4 pos, Vec4 vel)
{
  Rigidbody r(pos, 0.6f,colour.pink().r,colour.pink().g,colour.pink().b);
  r.setVelocity(vel);
  Objectslist.push_back(r);
}
//////////////////////////////////////////////////////////////////////
/// @brief Add the circle and assign the position and radius with blue
/// @param pos
/// @param vel
//////////////////////////////////////////////////////////////////////
void Physicsworld::addBlueObject(Vec4 pos,Vec4 vel)
{
  Rigidbody rb(pos, 0.8f,colour.blue().r,colour.blue().g,colour.blue().b);
  rb.setVelocity(vel);
  Objectslist.push_back(rb);
}
//////////////////////////////////////////////////////////////////////
/// @brief Add the circle and assign the position and radius with yellow
/// @param pos
/// @param vel
//////////////////////////////////////////////////////////////////////
void Physicsworld::addYellowObject(Vec4 pos,Vec4 vel)
{
  Rigidbody ry(pos, 1.0f, colour.yellow().r,colour.yellow().g,colour.yellow().b);

  ry.setVelocity(vel);
  Objectslist.push_back(ry);
}
//////////////////////////////////////////////////////////////////////
/// @brief Add the circle and assign the position and radius with white
/// @param position
/// @param velocity
//////////////////////////////////////////////////////////////////////
void Physicsworld::addWhiteObject(Vec4 pos,Vec4 vel)
{
  Rigidbody rw(pos, 0.4f, colour.white().r,colour.white().g,colour.white().b);
  rw.setVelocity(vel);
  Objectslist.push_back(rw);
}
////////////////////////////
/// @brief Add the obstacles
////////////////////////////
void Physicsworld::addObstacles()
{
  Obstacles o;
  MapList.push_back(o);
}
////////////////////////////
/// @brief Draw function
////////////////////////////
void Physicsworld::draw()
{
  for(auto i:Objectslist)
  {
    i.draw();
  }
  for(auto i:MapList)
  {
    i.draw();
  }
}
////////////////////////////
/// @brief Update function
////////////////////////////
void Physicsworld::update()
{
  for(auto& i:Objectslist)
  {
    i.update();
  }
  for(auto i:MapList)
  {
    i.update();
  }
  collisionDetection();
  }
////////////////////////////////////////////////////////////////////////////////////
/// @brief Check whether the ball intersects with each other when dropping
////////////////////////////////////////////////////////////////////////////////////
bool Physicsworld::intersectCircle(Rigidbody &p1, Rigidbody &p2, float r1, float r2)
{

  //using the dot product will calculate the distance between two intersected circle
  if (p1.getPosition().dot(p2.getPosition())<r1+r2)
    return true;
  //when the circle does not intersect, return false
  else return false;
}
////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Check the collision between circles and circle, circle and line, circle and wall
/// @brief and apply the appropriate amount of force onto the object
/// @brief to enable the ball to bounce around the screen and go in the right direction
/////////////////////////////////////////////////////////////////////////////////////////////
void Physicsworld::collisionDetection()
{
  for(int i = 0; i<Objectslist.size(); ++i)
  {
    for(int j=i+1; j<Objectslist.size(); ++j)
    {
      //calculate the difference to see whether the circle intersect
      Vec4 rij = Objectslist[i].getPosition()-Objectslist[j].getPosition();
      if(rij.length()<2.5f)
      {
        //collided and add velocity to its opposite direction
        Objectslist[i].addVelocity(rij*0.01);
        Objectslist[j].addVelocity(-rij*0.01);

      }
    }

    // loop through all obstacles and check their rigid bodies to see if collided
    for(int j=0 ; j<MapList[m_mapSelect].m_obstaclesRigidbodies.size(); ++j)
    {
      Vec4 rij = Objectslist[i].getPosition()-MapList[m_mapSelect].m_obstaclesRigidbodies[j].getPosition();
      if(rij.length()<0.5f)
      {
        Objectslist[i].addVelocity(rij*0.05);
      }
    }
    //floor collision
    if(Objectslist[i].getPosition()[1]<-10.f)
    {
      Objectslist[i].addVelocity(Vec4(0.0f,-1.7*Objectslist[i].getVelocity()[1],0.0f));
    }
    //right side collision
    if(Objectslist[i].getPosition()[0]>12.0f)
    {
      Objectslist[i].addVelocity(Vec4(-1.7*Objectslist[i].getVelocity()[0],0.0f,0.0f));
    }
    //left side collision
    if(Objectslist[i].getPosition()[0]<-13.0f)
    {
      Objectslist[i].addVelocity(Vec4(-1.7*Objectslist[i].getVelocity()[0],0.0f,0.0f));
    }
  }

}



