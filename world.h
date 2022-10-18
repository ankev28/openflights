#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <utility>
#include <tuple>
#include <cmath>
#include <queue>
#pragma once

using namespace std;

class world
{
public: //after starting with id strings to id ints, everything will be done using the id ints inside the code
  world();
  ~world();
  int getIdNumber(string airportid);
  vector<int> getConnections(string airportid);
  pair<float, float> getCoordinates(string airportid);
  string getAirportName(int idNumber);

  vector<int> getConnections(int idNumber); //to be used by bfs and dijkstra
  pair<float, float> getCoordinates(int airportid); //to be used by dijkstra and animation

  //bool getVisited(int idNumber); can be replaced by getsource probably
  void setSource(int source, int next);
  int getSource(int id);

  bool airportExists(string check);

  void clearWorld(); //resets all the "is seen" bools to false;

  map<int, float> airportDistMap(string s);

  float calculateDistance(int airportid1, int airportid2); //given 2 airport unique IDs, calculates distance in kilometers to find weight for Dijkstra's
private:
                                                 //THIS MEMBER CHANGES INTERNALLY
  map<int, pair<int, vector<int>>> airports;    //int = openflights id, int = parent or 0 if not seeen, vector = id of places its connected to.

                                                 //THIS MEMBER IS ONLY FOR SETUP AND NEVER CHANGED AFTER
  map<string, tuple<int,float,float>> airportid; //maps identical airports to same id, and its coordinates


};
