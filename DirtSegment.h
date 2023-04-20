// header file for DirtSegment
#include "RoadSegment.h"
#include <string>
#pragma once

using namespace std;

class DirtSegment : public RoadSegment { // inherited class

  // public methods
public:

  DirtSegment();
  RoadSegment* generateNeighbor();
  string toString();

};
