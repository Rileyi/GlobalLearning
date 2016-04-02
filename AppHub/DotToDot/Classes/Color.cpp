#include "Color.h"

Color::Color(char r, char v, char b, float a) : Color4F((float)r/255, (float)v/255, (float)b/255, a)
{
}


Color::~Color()
{
}
