/*
 * Lane.h
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#ifndef LANE_H_
#define LANE_H_

#include "Car.h"
#include <vector>
#include <string>

class TrafLane {
private:
std::vector<Car> theLane;

public:
	TrafLane();
	TrafLane(int length);
	std::string stringify();
	void step();
	Car removeFirst();
	Car getFirst();
	bool lastFree();
	void putLast(Car v);
	virtual ~TrafLane();
};
#endif /* LANE_H_ */
