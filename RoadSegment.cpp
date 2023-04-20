// implementation class for abstract base class
#include "RoadSegment.h"
#include <iostream>
#include <stdlib.h>
#include <random>

using namespace std;

RoadSegment::RoadSegment() { // default constructor
  random_device random;
  mt19937 gen(random());
  uniform_int_distribution<> generate(10, 50);
  length = generate(gen);
  modifier = 0.0;
}

int RoadSegment::getLength() { // getter
  return length;
}


double RoadSegment::getModifier() { // getter
  return modifier;
}



