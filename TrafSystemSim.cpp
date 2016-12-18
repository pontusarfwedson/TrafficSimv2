/*
 * TrafficSystem.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include <iostream>
#include <string>
//#include <time.h>
#include <unistd.h>
#include "TrafSystemSim.h"
#include "Car.h"
#include "CarCreator.h"
#include "TrafLane.h"
#include "TrafLight.h"
#include "InvalidInput.h"
using namespace std;

namespace trafficsystem {

TrafSystemSim::TrafSystemSim(int laneLength, int laneWSLength,
    int lightPeriod, int lightWestGreen, int lightSouthGreen,
    float probStraight1, float probWest1, float probStraight2, float probWest2) {
	  // TODO Auto-generated constructor stub

    try{

      this->laneLength      = laneLength;
      this->laneWSLength    = laneWSLength;
      this->lightPeriod     = lightPeriod;
      this->lightWestGreen  = lightWestGreen;
      this->lightSouthGreen = lightSouthGreen;

      generator     = CarCreator();
      lane          = TrafLane(laneLength);
      laneWest      = TrafLane(laneWSLength);
      laneExitWest  = TrafLane(3);             // Just for illustration
      laneSouth     = TrafLane(laneWSLength);
      laneExitSouth = TrafLane(3);             // Just for illustration
      lightWest     = TrafLight(lightPeriod, lightWestGreen);
      lightSouth    = TrafLight(lightPeriod, lightSouthGreen);

      if(laneLength < 0 || laneWSLength < 0 || lightPeriod < 0
          || lightWestGreen < 0 || lightSouthGreen < 0){
          throw InvalidInput<int>(laneLength);
      }
    }
    catch(InvalidInput<int>& e) {
      cout << "InvalidInput exception is caught" << endl;
      cout << e.what() << endl;
    }
}

/**
   * Advances the whole traffic system one timestep. Makes use
   * of components step methods
   */
  void TrafSystemSim::step() {
    Car v;

                                                // Vehicle leaving at West?
    v = laneExitWest.removeFirst();
    if (v.getDestination()!=' ') {
      //exitWest.push_back(Simulation.getTime() - v.getTime());
    }
    laneExitWest.step();

                                                // Vehicle leaving at South?
    v = laneExitSouth.removeFirst();
    if (v.getDestination()!=' ') {
      //exitSouth.push_back(Simulation.getTime() - v.getTime());
    }
    laneExitSouth.step();


                                                 // Take vehicles past the lights if possible
    if (lightWest.isGreen() ) {
      laneExitWest.putLast(laneWest.removeFirst());
    }
    if (lightSouth.isGreen()) {
      laneExitSouth.putLast(laneSouth.removeFirst());
    }

                                                 // Step lanes in front of the lights
    laneWest.step();
    laneSouth.step();

                                                 // Move from lane to laneWest or laneSouth
    v = lane.getFirst();
    if (v.getDestination()!=' ') {
      if (v.getDestination()=='W' )
        if (laneWest.lastFree() )
        laneWest.putLast(lane.removeFirst());
      else
        blocked++;
      else if (laneSouth.lastFree())
        laneSouth.putLast(lane.removeFirst());
      else
        blocked++;
    }

                                                 // Step first lane
    lane.step();

                                                 // Create vehicles
    v = generator.step();
    if (v.getDestination()!=' ') {
      queue.push_back(v);
    }
    if (!queue.empty() && lane.lastFree()) {
      lane.putLast(queue.front());
      queue.erase(queue.begin());
    }
    if (!queue.empty()) {
       queued++;
    }

                                                  // Step signals
    lightWest.step();
    lightSouth.step();
  }

  /**
   * Prints the current situation using toString-methods in
   * lights and lanes.
   * Example:
   * <pre>
   * (G) &lt;WWW W W  W&gt;&lt; W SW  W WS S&gt;   queue: [WWS]
   * (G) &lt S  SSS SS&gt;
   * </pre>
   */
  void TrafSystemSim::print() {
    cout << laneExitWest.stringify() << " " << lightWest.stringify() << " " << laneWest.stringify();
    cout << lane.stringify();
    //cout << ln("   queue: " + qtos() + "  vg: " + generator);
    cout << qtos() << "     " << generator.toString() << endl;
    cout << laneExitSouth.stringify() << " " << lightSouth.stringify() << " " << laneSouth.stringify() << endl;;
  }

  string TrafSystemSim::qtos() {
    string res = "";
    list<Car>::iterator it;
    for (it = queue.begin(); it != queue.end(); it++) {
      res += it->stringify();
    }
    return '[' + res + ']';
  }

  /**
   * Prints the simulation parameters and arrival probabilities used in this run
   */
  void TrafSystemSim::printSetup() {
    cout << "Simulation parameters:" << endl;
    cout << "\t laneLength     : " << laneLength << endl;
    cout << "\t laneWSLength   : " << laneWSLength << endl;
    cout << "\t lightPeriod    : " << lightPeriod << endl;
    cout << "\t lightSouthGreen: " << lightSouthGreen << endl;
    cout << "\t lightWestGreen : " << lightWestGreen << endl;
    cout << "\nTraffic periods and probabilities:" << endl;
    generator.print();
  }

TrafSystemSim::~TrafSystemSim() {
	// TODO Auto-generated destructor stub
}

} /* namespace query_namespace */

int main() {

  Properties prop;
  trafficsystem::TrafSystemSim tf = trafficsystem::TrafSystemSim(prop.laneLength,
		  prop.laneWSLength, prop.lightPeriod, prop.lightWestGreen, prop.lightSouthGreen,
		  prop.probStraight1, prop.probWest1, prop.probStraight2, prop.probWest2);
  //trafficsystem::TrafficSystem tf = trafficsystem::TrafficSystem(10, 8, 14, 6, 4);
  prop.print();
  usleep(5000000);

  //tf.printSetup();
  tf.print();
  for(int i = 0; i < 100; i++) {
    cout.flush();
    usleep(100000);
    //Sleep(10000); // for windows
    tf.print();
    tf.step();
  }
}
