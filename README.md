# OpenFlights Airport Search Visualizaiton

Implementation of 2 popular graph search algorithms to search for the least number of stops from the source (BFS) and to search for the shortest travelled mileage distance from the source (Dijkstra's Algorithm), and at the end of the route processing the program  will return the path discovered (if it exists), as well as a .gif visual of the path taken from the source to the destination.

Yeah, this was for the CS225 final project.

## 1. Introduction to the Code

The first step to running the program is to downloading all the code and datasets used! This can be done using the command line below:

`git clone https://github.com/ankev28/openflights.git`

What's important:
  * IATA_clean.txt and ROUTES_clean.txt: cleaned datasets to be parsed by the program.
  * main.cpp: responsible for object instantiation, user input/interface, and  final route output.
  * world.h/world.cpp: the graph class which processes the datasets, representing each airport as a vertex and the route destinations an airport can reach as a directed edge.
  * dijkstra.h/dijkstra.cpp: the Dijkstra search algorithm class, implementing a priority queue to run in **O(|E| + |V|log(|V|))** time complexity.
  * bfs.h/bfs.cpp: the BFS algorithm class, running in **O(|E| + |V|)** time.
  * cs225 namespace classes (HSLAPixel, PNG, etc.): used for graphic deliverable.
  * animation.h/animation.cpp: the provided animation class, used for the graphic deliverable.
  * graphic.h/graphic.cpp: the graphic class, which creates a visual of the path traversal taken upon completion of the route discovery by the program. The gif output will be saved to **ROUTE_PATH.gif** in the same directory as the project is located in.
  * Makefile: used to compile the program (usage explained later)
  * map.png: base image of map the program uses to draw the graphic on (called an Equidistant Cylindrical Projection)
  * tests: testcases used throughout production of the project itself

## 2. Build and Run

The next step to running the project code is to compile the code using the line below:

`make`

This will create the project executable, which you can run using the line below:

`./project`

Upon successful compilation and running of ./project, the user will be able to input a source and destination airport using the 3 digit IATA or 4 digit ICAO (if either exists). Invalid codes will result in the user having to re-enter in a valid code, as prompted to by the program. Some such codes that are valid include *KORD*, *CMI*, *PEK*, *FNJ*, *HFN*, and more (you can use the IATA_clean.txt for reference to find any of the 7000+ aiport IATA/ICAOs!).

The next step is for the user to enter either **1** - representing BFS, or **2** - representing Dijkstra's. Either implementation will either return the optimal path taken with each search algorithm, or it will notify the user that there is no path from the source to the destination if there is no path found.

Last, upon successful completion of the program, the user will find a gif called **ROUTE_PATH.gif**. This will be a visual representation of the path that was listed from the airport traversal discovered by the program. If the program is run multiple times, the gif will be overridden by the program so as to not produce excess clutter, so the user will need to manually store the generated gif elsewhere if they wish to view it later.

## 3. Full Test Suite

To compile the test cases, please use the line below:

`make test`

This will create the test executable, which the user can then run either the sample test cases (ie. "gif", "BFS", etc.), or simply run `./test` to run all the sample testcases. 

*Note that none of the testcases accept user input (ie. for the search algorithms the user would manually need to modify the hardcoded source and destination IATA/ICAO inside the tests.cpp file). Essentially all of the testcases are only meant to produce some kind of output that verifies the object and/or function to be tested performs to standard, usually done by printing out the results to the console.

