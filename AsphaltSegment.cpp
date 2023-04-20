// Implementation file for AsphaltSegment
#include "AsphaltSegment.h"
#include "CrumbledSegment.h"
#include "GravelSegment.h"
#include "DirtSegment.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>

using namespace std;

AsphaltSegment::AsphaltSegment() { // default constructor
  modifier = 1.0;
}

RoadSegment* AsphaltSegment::generateNeighbor() { // overridden method to generate the next segment

  int random;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> generate(1,100);
  random = generate(gen);

  if (random >= 1 && random <= 60) {
    RoadSegment* segment = new AsphaltSegment();
    return segment;
  } else if (random > 60 && random <= 85) {
    RoadSegment* segment = new CrumbledSegment();
    return segment;
  } else if (random > 85 && random <= 95) {
    RoadSegment* segment = new GravelSegment();
    return segment;
  } else if (random > 95 && random <= 100) {
    RoadSegment* segment = new DirtSegment();
    return segment;
  }

  RoadSegment* segment = new AsphaltSegment();
  return segment;

}

string AsphaltSegment::toString() { // overridden method
  string str = "Asphalt - " + to_string(length) + " units ";
  return str;
}
