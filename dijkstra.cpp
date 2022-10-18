#include "dijkstra.h"


dijkstra::dijkstra(world &W, string s, string d)
{
  w = W;
  source =s;
  destination = d;
  totaldistance = 0;
}

dijkstra::~dijkstra()
{
  
}


typedef pair<int, int> pi;

vector<string> dijkstra::DijkstraGraph()
{
  priority_queue<pi, vector<pi>, greater<pi>> q; //first number is dist, second is ID
  map<int, float> dmap = w.airportDistMap(source);
  int start = w.getIdNumber(source);
  int end = w.getIdNumber(destination);

  for (auto x : dmap)
  {
    vector<int> c = w.getConnections(x.first);
    for (int i = 0; i < (int)c.size(); i++)
    {
      duplicates[make_pair(x.first, c[i])] = false;
    }

  }

  q.push(make_pair(0, start));

  bool issolution = false;

  while(!q.empty())
  {
    pair<int, int> cat = q.top();
    q.pop();
    int ID = cat.second;

    if (ID == end)   //MAY NOT NECESSARILY BE TRUE FOR DIJKSTRAS TO FIND CORRECT ROUTE, WILL INCREASE RUNTIME A LOT IF COMMENTED OUT THOUGH
    {
      printf("Destination Found!\n");
      printf("Plotting . . . \n");
      //cout << ID << " " << endl;
      issolution = true;
      break;
    }

    vector<int> connections = w.getConnections(ID);
     for (int i = 0; i < (int)connections.size(); i++)
     {
       if (duplicates[make_pair(ID, connections[i])] == true)
       {
         continue;
       }
       duplicates[make_pair(ID, connections[i])] = true;


       //cout << connections[i] << " " << endl;
       if (dmap[connections[i]] > dmap[ID] + w.calculateDistance(ID, connections[i]))
       {
         dmap[connections[i]] = dmap[ID] + w.calculateDistance(ID, connections[i]);
         q.push(make_pair(dmap[connections[i]], connections[i]));
         w.setSource(ID, connections[i]);
         //cout << "Source: " << ID << " next: " << connections[i] << " distance: " << dmap[connections[i]] << endl;
       }
     }


  }
  if (issolution == false)
  {
      return {"No paths found!"};
  }

  vector<string> ret = {};

  int temp = w.getIdNumber(destination);
  ret.push_back(w.getAirportName(temp));
  while(temp!=start)
  {
    temp = w.getSource(temp);
    ret.push_back(w.getAirportName(temp));
  }

  totaldistance = dmap[end];

  reverse(ret.begin(), ret.end());

  totalstops = ret.size()-1;

  return ret;
}

float dijkstra::getDistance()
{
  return totaldistance;
}

int dijkstra::getNumStops()
{
  return totalstops;
}
