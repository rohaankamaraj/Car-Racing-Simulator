#include <iostream>
#include <stdlib.h>
#include <string>
#include "RoadSegment.h"
#include "AsphaltSegment.h"
#include "CrumbledSegment.h"
#include "GravelSegment.h"
#include "DirtSegment.h"
#include "Racer.h"
#include "StreetRacer.h"
#include "SteadyRacer.h"
#include "ToughRacer.h"
#include "Race.h"

// the only thing main is used for is to create a Race object and call the runRace() method

using namespace std;

int main() {

  Race* race = new Race();
  race->runRace();

  return 0;
}
