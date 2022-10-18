#include <iostream>
#include <string>
#include "world.h"
#include "bfs.h"
#include "dijkstra.h"
#include "graphic.h"

using namespace std;

int main()
{
  world* w = new world();
  string source, destination;
  cout << "Please enter in an IATA or ICAO source airport code: ";
  cin >> source;
  while (!w->airportExists(source))
  {
    cout << "\n\nPlease enter a valid IATA or ICAO code! ";
    cin >> source;
  }

  cout << "\nPlease enter in an IATA or ICAO destination airport code: ";
  cin >> destination;
  while (!w->airportExists(destination))
  {
    cout << "\n\nPlease enter a valid IATA or ICAO code! ";
    cin >> destination;
  }

  while(source==destination)
  {
    cout << "\n\nPlease enter a different IATA or ICAO code from your source! ";
    cin >> destination;
  }


  cout << "\nInput route: " << source << " --> " << destination << " ✈" << endl;

  cout << "\nPlease select desired algorithm: 1 for BFS (fewest stops), 2 for Dijkstra's (shortest overall distance): ";
  string bfsordijkstras;
  cin >> bfsordijkstras;


  while (stoi(bfsordijkstras)!=1 && stoi(bfsordijkstras)!=2)
  {
    cout << "\n\nPlease select a valid algorithm! ";
    cin >> bfsordijkstras;
  }


  bool check = true;
  vector<string> soln = {};
  if (stoi(bfsordijkstras) == 1)
  {
    bfs *b = new bfs(*w, source, destination);
    soln = b->BFSGraph();
    printf("Route: ");
    for (int i = 0; i < (int)soln.size(); i++)
    {
      cout << soln[i]<< " ";
      if(i < (int)soln.size() -1){
        printf("-> ");
      }
    }

    cout<<"| Total Stops: " << b->getNumStops();
    cout <<" | Total Distance in Miles: " << b->getDistance() << endl;

    if (b->getNumStops() == 0)
    {
      check = false;
      printf("No map generated!\n");
    }
    else
    {
      printf("Generating map of route . . .\n");
    }

    delete b;
  }
  else if (stoi(bfsordijkstras) == 2)
  {
    dijkstra *d = new dijkstra(*w, source, destination);
    soln = d->DijkstraGraph();
    for (int i = 0; i < (int)soln.size(); i++)
    {
      cout << soln[i]<< " ";
      if(i < (int)soln.size() -1){
        printf("-> ");
      }
    }
    cout << "| Total Stops: " << d->getNumStops();
    cout <<" | Total Distance in Miles: " << d->getDistance() << endl;
    if (d->getNumStops() == 0)
    {
      check = false;
      printf("No map generated!\n");
    }
    else
    {
      printf("Generating map of route . . .\n");
    }

    delete d;
  }

  if  (check==true)
  {
    graphic *map = new graphic(soln, *w);
    map->generate();
    printf("Map has been generated! Saved to ROUTE_PATH.gif\n");
    delete map;
  }

  else
    ;

  delete w;

}
