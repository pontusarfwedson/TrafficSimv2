/*
 * VehicleGenerator.h
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#ifndef VEHICLEGENERATOR_H_
#define VEHICLEGENERATOR_H_

#include <vector>
#include <string>
#include <cstddef>
#include "Car.h"

using namespace std;

class CarCreator {

private:
	vector<int> periods;
	vector<double> arrivalProbabilities;
	vector<double> turningProbabilities;
	vector<string> comments;

	int myTime;       // internal clock
  int period;     // current period
  int totalCycle; // total time period

public:
	CarCreator(float, float, float, float);
	CarCreator(string);
	CarCreator();
	virtual ~CarCreator();
	Car step();
	string toString();
	void print();
};

#endif /* VEHICLEGENERATOR_H_ */
