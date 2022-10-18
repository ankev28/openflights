#include "../cs225/catch/catch.hpp"
#include "../bfs.h"
#include "../dijkstra.h"
#include "../world.h"
#include "../graphic.h"

#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <string>
#include <utility>
#include <fstream>


using namespace std;


TEST_CASE("graph_construction", "[weight=1]")
{
 world* dog = new world();
 //cout << dog->getIdNumber("CUM") << endl; //should be the same airport number when tested
 //cout << dog->getIdNumber("SVCU") << endl; //and both are at id = 2835
 cout << dog->getIdNumber("LHW") << endl;
 cout << dog->getCoordinates("LHW").first << " " << dog->getCoordinates("LHW").second << endl;
 cout << endl;
 cout << dog->getIdNumber("ZLLL") << endl;
 cout << dog->getCoordinates("ZLLL").first << " " << dog->getCoordinates("ZLLL").second << endl;
 cout << endl;
 cout << dog->getAirportName(3378) << endl; //probably KORD, just picks the closest to the front of the map
 cout << dog->getCoordinates(3378).first << " " << dog->getCoordinates(3378).second << endl;

 vector<int> connections = dog->getConnections("LHW");
 for (int i = 0; i < (int)connections.size(); i++)
 {
   cout << i << " "<<connections[i] << endl;
 }
 vector<int> c = dog->getConnections(3378);
 for (int i = 0; i < (int)c.size(); i++)
 {
   cout << i << " "<<c[i] << endl;
 }

 cout << dog->calculateDistance(3378, 3375) << " miles distance" <<endl;

}


TEST_CASE("read_sources", "[weight=1]")
{
  world *dog = new world();

  cout << dog->getSource(3830) << endl;

  dog->setSource(3378, 3830);

  cout << dog->getSource(3830) << endl;

  dog->clearWorld();

  cout << dog->getSource(3830) << endl;

}

TEST_CASE("memory_leak_check", "[weight=1]")
{
  world *dog = new world();
  bfs *b = new bfs(*dog, "ORD", "ORD");
  dijkstra *d = new dijkstra(*dog, "ORD", "ORD");
  graphic *g = new graphic({"ORD"}, *dog);

  delete dog;
  delete b;
  delete d;
  delete g;


}


TEST_CASE("BFS", "[weight=1]")
{
  world *dog = new world();

  bfs *cat = new bfs(*dog, "CMI", "IBB"); //change airport IATA/ICAO's here

  vector<string> soln = cat->BFSGraph();

  for (int i = 0; i < (int)soln.size(); i++)
  {
    cout << soln[i] << " ";
  }

  cout << cat->getNumStops() << endl;


}

TEST_CASE("gif", "[weight=1]")
{
  world *w = new world();
  vector<string> cat = {"PEK", "CYVR"};//,"CMI","PEK","FNJ"};

  graphic *dog = new graphic(cat, *w);

  dog->generate();


}

TEST_CASE("dijkstra_pt1", "[weight=1]")
{
  world *dog = new world();

  dijkstra *cat = new dijkstra(*dog, "CMI", "IBB"); //change airport IATA/ICAO's here

  vector<string> soln = cat->DijkstraGraph();

  for (int i = 0; i < (int)soln.size(); i++)
  {
    cout << soln[i] << " ";
  }

}
