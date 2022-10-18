#include "world.h"
#include <sstream>
#include <iterator>
#include <algorithm>
#include <set>
world::world()
{
  ifstream wordsFile("IATA_clean.txt");
  string word;
  if (wordsFile.is_open()) {
    while (getline(wordsFile, word)) {
        vector<string> dog = {};
        string word1;
        stringstream iss(word);

        while(iss >> word1)
        {
          dog.push_back(word1);
        }
        int id = stoi(dog[0]);
        float lat = stof(dog[1]);
        float lon = stof(dog[2]);
        for (int i = 3; i < (int)dog.size(); i++)
        {
          //cout << dog[i] << " ";
          airportid[dog[i]] = make_tuple(id, lat, lon);
        }
        vector<int> emptyvector = {};
        airports[id] = make_pair(0, emptyvector); //initializes source airport as "not seen"
    }
      //cout << airports.size() << endl;
  }
  ifstream connectionFile("ROUTES_clean.txt");
  if (connectionFile.is_open()) {
    while (getline(connectionFile, word)) {
      vector<string> dog = {};
      string word1;
      stringstream iss(word);

      while(iss >> word1)
      {
        dog.push_back(word1);
      } //only 2 numbers (as strings), first is source, second is destination

      airports[stoi(dog[0])].second.push_back(stoi(dog[1]));
    }
  }
  for(auto &x : airports) //removing duplicates by dumping every vector
                          //into a set and back into the vector
  {
    sort(x.second.second.begin(), x.second.second.end());
    set<int> s(x.second.second.begin(), x.second.second.end());
    x.second.second.assign(s.begin(), s.end());
  }
}

world::~world()
{
  
}


map<int, float> world::airportDistMap(string s) //will return distance map and priority queue for dijkstras
{
  int id = getIdNumber(s);
  map<int, float> ret1;
  for (auto x : airports)
  {
    ret1[x.first] = INT_MAX;
  }
  ret1[id] = 0.0; //distance from source = 0 of course
  return ret1;
}

bool world::airportExists(string check)
{
  if (airportid.find(check)!=airportid.end())
  {
    return true;
  }
  else
  {
    return false;
  }
}



vector<int> world::getConnections(string input)
{
  int id = get<0>(airportid[input]);

  //vector<int> &x = airports[id];

  // for (int i = 0; i < (int)x.size(); i++)
  // {
  //   cout << i << " " << x[i] << endl;
  // }

  return airports[id].second;
}

vector<int> world::getConnections(int input)
{
  return airports[input].second;
}


string world::getAirportName(int input)
{
  for (auto dog: airportid)
  {
    if (get<0>(dog.second) == input)
    {
      return dog.first;
    }
  }
  return "";
}

pair<float, float> world::getCoordinates(int input)
{
  //cout << airportid[input].second.first << " " << airportid[input].second.second << endl;
  string dog = getAirportName(input);

  float lat = get<1>(airportid[dog]);
  float lon = get<2>(airportid[dog]);

  return pair<float, float>(lat, lon);;
}

// void world::setVisited(int idNumber)
// {
//   airports[idNumber].first = true;
// }
//
// bool world::getVisited(int idNumber)
// {
//   return airports[idNumber].first;
// }


pair<float, float> world::getCoordinates(string input)
{
  //cout << airportid[input].second.first << " " << airportid[input].second.second << endl;
  float lat = get<1>(airportid[input]);
  float lon = get<2>(airportid[input]);

  return pair<float, float>(lat, lon);;
}

int world::getIdNumber(string id)
{
  return get<0>(airportid[id]);
}

float world::calculateDistance(int airportid1, int airportid2) //"great circle approach" = shortest of 2 lat/long coordinates?
{
  float pi = 3.14159;
  pair<float, float> coordinate1 = getCoordinates(airportid1);
  float lat1 = coordinate1.first*pi/180;
  float lon1 = coordinate1.second*pi/180;
  pair<float, float> coordinate2 = getCoordinates(airportid2);
  float lat2 = coordinate2.first*pi/180;
  float lon2 = coordinate2.second*pi/180;

  float d = 3963.0 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1));
  return d;


}

void world::clearWorld()
{
  for (auto &x : airports)
  {
    x.second.first = 0;
  }
}

void world::setSource(int s, int n)
{
  airports[n].first = s;
}

int world::getSource(int id)
{
  return airports[id].first;
}
