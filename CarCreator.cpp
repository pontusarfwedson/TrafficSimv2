/*
 * VehicleGenerator.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstddef>
#include <stdio.h>
#include "CarCreator.h"

using namespace std;

/**
 * Hard coded probabilities for test purposes only.
 * The used probabilities will most certainly produce traffic jam.
 */

CarCreator::CarCreator(float prob1, float prob2, float prob3, float prob4) {
	// TODO Auto-generated constructor stub

	periods.push_back(30);         // Time step 0 - 29
	arrivalProbabilities.push_back(prob1);
	turningProbabilities.push_back(prob2);
	comments.push_back("First interval");

	periods.push_back(30 + 20);    // Time step 30 - 49
	arrivalProbabilities.push_back(prob3);
	turningProbabilities.push_back(prob4);
	comments.push_back("Second intervall");

  //TODO CHECK with Pontus if periods.get(periods.size()-1)
	// is meants to get the last element of ArrayList.
	totalCycle = periods.at(periods.size()-1);
	myTime = 0;
	period = 0;
}

CarCreator::CarCreator() {
	// TODO Auto-generated destructor stub
}

CarCreator::~CarCreator() {
	// TODO Auto-generated destructor stub
}

/**
 * Should generate a car OR truck OR null depending on probabilities.
 */
Car CarCreator::step(){

	myTime = myTime+1;
    if (myTime >= totalCycle) {
      myTime = 0;
      period = 0;
    }

    if (myTime>=periods.at(period)) {
      period++;
    }

    Car retur = Car(' ');
    double prob = arrivalProbabilities.at(period);

    if (((rand()%11)/10.0) < prob) {
      if (((rand()%11)/10.0) < turningProbabilities.at(period)) {
        retur = Car('S');
      } else {
        retur = Car('W');
      }
    }
    return retur;
}

/**
   * Returns the current state
   */
  string CarCreator::toString() {
	  	
	    return "";
		//return to_string(myTime) + ": <" + to_string(period) + ", " + to_string(arrivalProbabilities.at(period))
		//	+ ", " + to_string(turningProbabilities.at(period)) + ">";
  }

	/**
   * Prints the current setup of the generator
   */
  void CarCreator::print() {
    int nsteps = 0;
    for (int i= 0; i<periods.size(); i++) {
			cout << periods.at(i) - nsteps << ", "
				<< arrivalProbabilities.at(i) << ", "
				<< turningProbabilities.at(i) << ", "
				<< comments.at(i) << ", " << endl;
			nsteps = periods.at(i);
		}
  }

  // int main() {
	// 	srand(time(0)); //TODO This should be called only once
  //   VehicleGenerator vg = VehicleGenerator();
  //   cout << "VehicleGenerator setup:" << endl;
  //   vg.print();
  //   cout << "\nStepping the generator:" << endl;
  //   for (int i= 0; i<300; i++) {
  //     vg.print();
  //     Vehicle v = vg.step();
  //     if (v.getDestination() != ' ') {
  //       cout << "  Vehicle out: <" <<
  //     		v.getDestination() << ", " << v.getTime() << ">" << endl;
  //     }
	// 		else
	// 		{
	// 			cout << "  NO Vehicle out" << endl;
	// 		}
  //   }
  // }
