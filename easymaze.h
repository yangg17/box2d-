/// ------------------------------
/// @file Easymaze.h
/// @brief Easymaze class
/// @author Shannon Yang
/// @version 1.0
/// @date 2/5/16
/// -------------------------------
#ifndef EASYMAZE_H
#define EASYMAZE_H
#include "obstacles.h"

//easymaze class
class Easymaze : public Obstacles
{
public:
  //constructor
  Easymaze();
  //destructor
  ~Easymaze();
  //draw line
  void drawLine();

};

#endif // EASYMAZE_H
