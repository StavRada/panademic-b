#pragma once
#include <map>
using namespace std;

enum Color { Blue,Yellow,Black,Red };
static map<Color,string> cast_color =
{
  {Color::Blue,"Blue"},
  {Color::Yellow,"Yellow"},
  {Color::Black,"Black"},
  {Color::Red,"Red"},
};
