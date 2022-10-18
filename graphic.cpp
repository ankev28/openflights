
#include "graphic.h"


graphic::graphic(vector<string> input, world &world)
{
  path = input;
  w = world;
  base.readFromFile("map.png");
}

void graphic::drawBox(int x, int y)
{
  for (int i = -5; i < 5; i++)
  {
    for (int j = -5; j < 5; j++)
    {
      if (x + i >= 0 && x + i < 2058 && y + j >= 0 && y + j < 1036)
      {
        base.getPixel((unsigned)x+i,(unsigned)y+j).h = 50;
        base.getPixel((unsigned)x+i,(unsigned)y+j).l = .5;
        //cout << x + i << " " << y + j << endl;
      }
    }
  }
}

graphic::~graphic()
{
  
}


void graphic::drawLine(int x1, int y1, int x2, int y2)
{
    RTL(x1,y1,x2,y2);
    //cout << RTL(x1,y1,x2,y2) << endl;
    //cout << x1 << " " << y1<< " " << x2 << " "<< y2 <<endl;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1;
    int y = y1;

    x = x % 2058;
    int count = 0;

    if(dy > 0 && dx > 0) //draw right and down
    {
      if (dx > dy) // 0 < slope < 1
      {
        base.getPixel((unsigned)x,(unsigned)y).l = 0;
        int pk = (2 * abs(dy)) - abs(dx);

        for(int i = 0; i < abs(dx) ; i++)
        {
            x = (x + 1)%2058;
            if(pk < 0)
                pk = pk + (2 * abs(dy));
            else
            {
                y = y + 1;
                pk = pk + (2 * abs(dy)) - (2 * abs(dx));
            }
            base.getPixel((unsigned)x,(unsigned)y).l = 0;
            if (count%100 == 0)
            {
              animation.addFrame(base);
            }
            count++;
        }
      }
      else // slope > 1
      {
        base.getPixel((unsigned)x,(unsigned)y).l = 0;
        int pk = (2 * abs(dx)) - abs(dy);

        for(int i = 0; i < abs(dy) ; i++)
        {
            y = y + 1;
            if(pk < 0)
                pk = pk + (2 * abs(dx));
            else
            {
                x = (x + 1)%2058;
                pk = pk + (2 * abs(dx)) - (2 *abs(dy));
            }
            base.getPixel((unsigned)x,(unsigned)y).l = 0;
            if (count%100 == 0)
            {
              animation.addFrame(base);
            }
            count++;
        }
      }
    }
    else if (dy <= 0 && dx > 0) //right and up
    {
      if (dx > abs(dy)) // 0 < slope < 1
      {
        base.getPixel((unsigned)x,(unsigned)y).l = 0;
        int pk = (2 * abs(dy)) - abs(dx);

        for(int i = 0; i < abs(dx) ; i++)
        {
            x = (x + 1)%2058;
            if(pk < 0)
                pk = pk + (2 * abs(dy));
            else
            {
                y = y - 1;
                pk = pk + (2 * abs(dy)) - (2 * abs(dx));
            }
            base.getPixel((unsigned)x,(unsigned)y).l = 0;
            if (count%100 == 0)
            {
              animation.addFrame(base);
            }
            count++;
        }
      }
      else // slope > 1
      {
        base.getPixel((unsigned)x,(unsigned)y).l = 0;
        int pk = (2 * abs(dx)) - abs(dy);

        for(int i = 0; i > dy ; i--)
        {
            y = y - 1;
            if(pk < 0)
                pk = pk + (2 * abs(dx));
            else
            {
                x = (x + 1)%2058;
                pk = pk + (2 * abs(dx)) - (2 *abs(dy));
            }
            base.getPixel((unsigned)x,(unsigned)y).l = 0;
            if (count%100 == 0)
            {
              animation.addFrame(base);
            }
            count++;
        }
      }
    }
    else if (dy > 0 && dx <= 0) //draw left and down
    {
      if (abs(dx) > dy)
      {
        base.getPixel((unsigned)x,(unsigned)y).l = 0;
        int pk = (2 * abs(dy)) - abs(dx);

        for(int i = 0; i > dx ; i--)
        {
            x = (x - 1)%2058;
            if (x < 0)
            {
              x = x + 2058;
            }
            if(pk < 0)
                pk = pk + (2 * abs(dy));
            else
            {
                y = y + 1;
                pk = pk + (2 * abs(dy)) - (2 * abs(dx));
            }
            base.getPixel((unsigned)x,(unsigned)y).l = 0;
            if (count%100 == 0)
            {
              animation.addFrame(base);
            }
            count++;
        }
      }
      else
      {
        base.getPixel((unsigned)x,(unsigned)y).l = 0;
        int pk = (2 * abs(dx)) - abs(dy);

        for(int i = 0; i < dy; i++)
        {
            y = y + 1;
            if(pk < 0)
                pk = pk + (2 * abs(dx));
            else
            {
                x = (x - 1)%2058;
                if (x < 0)
                {
                  x = x + 2058;
                }
                pk = pk + (2 * abs(dx)) - (2 *abs(dy));
            }
            base.getPixel((unsigned)x,(unsigned)y).l = 0;
            if (count%100 == 0)
            {
              animation.addFrame(base);
            }
            count++;
        }
      }
    }
    else //left and up (dx <=0 && dy <= 0)
    {
      if (abs(dx) > abs(dy))
      {
        base.getPixel((unsigned)x,(unsigned)y).l = 0;
        int pk = (2 * abs(dy)) - abs(dx);

        for(int i = 0; i > dx ; i--)
        {
            x = (x - 1)%2058;
            if (x < 0)
            {
              x = x + 2058;
            }
            if(pk < 0)
                pk = pk + (2 * abs(dy));
            else
            {
                y = y - 1;
                pk = pk + (2 * abs(dy)) - (2 * abs(dx));
            }
            base.getPixel((unsigned)x,(unsigned)y).l = 0;
            if (count%100 == 0)
            {
              animation.addFrame(base);
            }
            count++;
        }
      }
      else
      {
        base.getPixel((unsigned)x,(unsigned)y).l = 0;
        int pk = (2 * abs(dx)) - abs(dy);

        for(int i = 0; i > dy; i--)
        {
            y = y - 1;
            if(pk < 0)
                pk = pk + (2 * abs(dx));
            else
            {
                x = (x - 1)%2058;
                if (x < 0)
                {
                  x = x + 2058;
                }
                pk = pk + (2 * abs(dx)) - (2 *abs(dy));
            }
            base.getPixel((unsigned)x,(unsigned)y).l = 0;
            if (count%100 == 0)
            {
              animation.addFrame(base);
            }
            count++;
        }
      }
    }
}

bool graphic::RTL(int &x1, int &y1, int &x2, int &y2) //will determine which way line will go in. false = need to wrap around, true = stay on map
{
  float stay = pow(pow((y2-y1),2) + pow(x2-x1,2), .5);
  float left = pow(pow((y2-y1),2) + pow(x2- (x1 + 2058),2), .5);
  float right = pow(pow((y2-y1),2) + pow(x2 + 2058- x1, 2), .5);

  if (stay < left && stay < right)
  {
    return true;
  }
  else if (stay >= left)
  {
    x1 = x1 +2058;
    return false;
  }
  else if (stay >= right)
  {
    x2 = x2 + 2058;
    return false;
  }
  else
  {
    return true;
  }
}




void graphic::generate()
{
    //base.readFromFile("map.png");
    //animation.addFrame(base);
    int mapWidth    = 2058;
    int mapHeight   = 1036;


    for (int i = 0; i < (int)path.size()-1; i++)
    {

      string current = path[i];
      float latitude = w.getCoordinates(current).first; // (φ)
      float longitude= w.getCoordinates(current).second;   // (λ)

      float x = mapWidth * (180 + longitude) / 360;
      float y = mapHeight * (90-latitude) / 180;

      //cout << (int)x << " " << (int)y << endl;
      drawBox((int)x, (int)y);

      animation.addFrame(base);

      string next = path[i+1];
      float latitude1 = w.getCoordinates(next).first; // (φ)
      float longitude1= w.getCoordinates(next).second;   // (λ)

      float x1 = mapWidth * (180 + longitude1) / 360;
      float y1 = mapHeight * (90-latitude1) / 180;

      drawLine((int)x, (int)y,(int)x1, (int)y1);


    }
    float latitude = w.getCoordinates(path.back()).first; // (φ)
    float longitude= w.getCoordinates(path.back()).second;   // (λ)

    float x = mapWidth * (180 + longitude) / 360;
    float y = mapHeight * (90-latitude) / 180;

    drawBox(x,y);

    animation.addFrame(base);

    animation.write("ROUTE_PATH.gif");
}
