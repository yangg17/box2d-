/// ------------------------------
/// @file Colours.h
/// @brief Colour class
/// @author Shannon Yang
/// @version 1.0
/// @date 2/5/16
/// -------------------------------
#ifndef COLOURS
#define COLOURS
#include <GL/gl.h>

  ///Struct to hold colour
  typedef struct Colour
{
//public
public:

    GLfloat r; /*!<member red*/

    GLfloat g; /*!<member green*/

    GLfloat b; /*!<member blue*/


    //colour pink
    Colour pink();
    //colour blue
    Colour blue();
    //colour yellow
    Colour yellow();
    //colour white
    Colour white();

//class clase
  }Colour;





#endif // COLOURS

