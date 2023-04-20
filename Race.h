// header file for Race
#include <string>
#include "Racer.h"
#include "StreetRacer.h"
#include "SteadyRacer.h"
#include "ToughRacer.h"
#include "RoadSegment.h"
#include "AsphaltSegment.h"
#include "CrumbledSegment.h"
#include "GravelSegment.h"
#include "DirtSegment.h"
#pragma once

using namespace std;

class Race { // class definition

  // protected fields
protected:
  int raceLength;
  Racer *racers[8];
  int segmentTracker[8];

  // public method definitions
public:
  Race();
  void runRace();
  void outputDivider(int);

};
