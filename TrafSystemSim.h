/*
 * TrafficSystem.h
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#ifndef TRAFFICSYSTEM_H_
#define TRAFFICSYSTEM_H_

#include<list>
#include<string>
#include"Car.h"
#include"CarCreator.h"
#include"TrafLane.h"
#include"TrafLight.h"

#include "Properties.cpp"

using namespace std;

namespace trafficsystem {

class TrafSystemSim {
private:
	int laneLength;
	int laneWSLength;
	int lightPeriod;
	int lightWestGreen;
	int lightSouthGreen;

  CarCreator generator;
  list<Car> queue;
  TrafLane   lane;
  TrafLane   laneWest;
  TrafLane   laneExitWest;
  TrafLane   laneSouth;
  TrafLane   laneExitSouth;
  TrafLight  lightWest;
  TrafLight  lightSouth;

  int blocked;	  // Number of time step blocking has occured
  int queued; 		// Number of time steps with queued vehicles

public:
	TrafSystemSim(int, int, int, int, int, float, float, float, float);
	void step();
	void print();
	string qtos();
	void printSetup();
	virtual ~TrafSystemSim();
};

} /* namespace query_namespace */
#endif /* TRAFFICSYSTEM_H_ */
