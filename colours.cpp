#include "colours.h"
///---------------------------
/// @brief Pink colour palette
///---------------------------
Colour Colour::pink()
{
  Colour pink;
  pink.r = 0.945f;
  pink.g = 0.368f;
  pink.b = 0.458f;
  return pink;
}
///---------------------------
/// @brief Blue colour palette
///---------------------------
Colour Colour::blue()
{
  Colour blue;
  blue.r=0.454f;
  blue.g=1.000f;
  blue.b=0.961f;
  return blue;
}
///---------------------------
/// @brief Yellow colour palette
///---------------------------
Colour Colour::yellow()
{
  Colour yellow;
  yellow.r=1.000f;
  yellow.g=0.957f;
  yellow.b=0.455f;
  return yellow;
}
///---------------------------
/// @brief White colour palette
///---------------------------
Colour Colour::white()
{
  Colour white;
  white.r=1.000f;
  white.g=1.000f;
  white.b=1.000f;
  return white;
}

