# Development Log

###### 11/22 - 11/28

- Data has been parsed using a Python script as promised. There are now two new and polished files, "ROUTES_clean.txt" and "IATA_clean.txt". We take these and use them in our world constructor where we have two maps.
  - The first assigns any airport name to a unique identifier number from OpenFlights (ie. ORD and KORD both map to 3830).
  - The second assigns unique identifier number to a vector of unique identifier numbers. Duplicates have also been dealt with to avoid confusion and to free memory during traversal.

- Files added and now works:
  - ROUTES_clean.txt
  - IATA_clean.txt
  - airports.dat
  - routes.dat
  - world.h
  - world.cpp
  - bfs.h
  - bfs.cpp
  - tests stuff

- Files added but needs work:
  - dijkstra.h
  - dijkstra.cpp
  - main.cpp


######  11/29 - 12/5

- Dijkstra has been finished although we are looking for ways to shorten the runtime. Work for the animation is underway. We have a good understanding on how to do it from past MPs so finishing this shouldn't be too bad.

- Files added and now works:
  - dijkstra.h
  - dijkstra.cpp

- Files added but needs work:
  - Animation.cpp
  - Animation.h
