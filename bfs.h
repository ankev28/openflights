#include <vector>
#include <map>
#include <string>
#include <queue>
#pragma once
#include "world.h"

using namespace std;

class bfs
{
public:
  ~bfs();
  bfs(world &W, string source, string dest);
  vector<string> BFSGraph();
  int getNumStops();
  float getDistance();
private:
  float totalDistance;
  int totalstops;
  world w;
  string source;
  string destination;

};
