#include <vector>
#include <map>
#include <string>
#include <queue>
#pragma once
#include "world.h"

using namespace std;

class dijkstra
{
public:
  ~dijkstra();
  dijkstra(world &W, string source, string dest);
  vector<string> DijkstraGraph();
  float getDistance();
  int getNumStops();

private:
  map<pair<int, int>, bool> duplicates; //pair = source, destination, bool = edge seen
  float totaldistance;
  int totalstops;
  world w;
  string source;
  string destination;
};
