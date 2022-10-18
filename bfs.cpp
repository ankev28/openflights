#include "bfs.h"


bfs::bfs(world &W, string s, string d)
{
  w = W;
  source =s;
  destination = d;
  totalstops = 0;
}

bfs::~bfs()
{
  
}

vector<string> bfs::BFSGraph()
{
  queue<int> q = {}; //will contain all neighboring airport IDs
  int start = w.getIdNumber(source);
  int end = w.getIdNumber(destination);
  q.push(start); //plan is to get to end, with everything mapped out directionwise for each
                //airport, then backtrack from destination to the source

  bool issolution = false;

  while(!q.empty())
  {
    int id = q.front();
    q.pop();

    if (id == end)
    {
      printf("Destination Found!\n");
      printf("Plotting . . . \n");
      //cout << ID << " " << endl;
      issolution = true;
      break;
    }

    vector<int> v = w.getConnections(id);
    for (int i = 0; i < (int)v.size(); i++)
    {
      if (w.getSource(v[i]) ==0)
      {
        q.push(v[i]);
        w.setSource(id, v[i]);
      }
    }
  }
  //map of all routes taken from start BFS is made by now
  if (issolution == false)
  {
    return {"No paths found!"};
  }

  vector<int> temppath = {};
  int temp = end;
  temppath.push_back(end);
  while(temp!=start)
  {
    temppath.push_back(w.getSource(temp));
    temp = w.getSource(temp);
  }

  reverse(temppath.begin(), temppath.end());

  vector<string> ret = {};

  for (int i = 0; i < (int)temppath.size(); i++)
  {
    ret.push_back(w.getAirportName(temppath[i]));
  }

  totalstops = ret.size() - 1;

  float TD = 0.0;
  for (int i = 0; i < (int)ret.size()-1; i++)
  {
    TD = TD + w.calculateDistance(w.getIdNumber(ret[i]),w.getIdNumber(ret[i+1]));
  }
  totalDistance = TD;

  return ret;

}

float bfs::getDistance()
{
  return totalDistance;
}


int bfs::getNumStops()
{
  return totalstops;
}
