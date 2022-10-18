#include <vector>
#include <string>
#include <cmath>
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include "Animation.h"
#include "world.h"
#include <iostream>
#pragma once

using namespace cs225;
using namespace std;

class graphic
{
public:
  ~graphic();
  graphic(vector<string> input, world &world);
  Animation animation;
  void generate();
  void drawBox(int x, int y);
  void drawLine(int x1, int y1, int x2, int y2);
  bool RTL(int &x1, int &y1, int &x2, int &y2);

private:
  PNG base;
  vector<string> path;
  world w;
};
