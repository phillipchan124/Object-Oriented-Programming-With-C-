// Lab 8, Using Inline Functions and Constants
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using std::ostream;
using std::endl;

#include "Floor.h"
#include "Elevator.h"

int Elevator::elevatorID = 0;
const int Elevator::IDLE = 0;
const int Elevator::UP = 1;
const int Elevator::DOWN = -1;

Elevator::Elevator(const int cap, const int v, const Floor& startFloor)
:ID(elevatorID), capacity(cap), speed(v), toFloor(0)
{
  location = startFloor.getLocation();
  direction = IDLE;
  doorOpen = true;
}

bool Elevator::isNearDestination() const
{
  double dist = (toFloor->getLocation() - location);
  if (dist < 0) dist *= -1;
  return (dist <= speed);
}

void Elevator::moveToDestinationFloor()
{
  if(hasADestination()) location = toFloor->getLocation();
}

ostream& operator<<(ostream& out, const Elevator& e)
{
  out << "Elevator is located at " << e.getLocation() << " inches from the ground level." << endl;
  
  if (e.isIdle()) out << "Elevator is idle." << endl;
  else if(e.isDirectionUp())  out << "Elevator is going up." << endl;
  else if(e.isDirectionDown()) out << "Elevator is going down." << endl;
  
  if (e.isDoorOpen()) out << "Door is open." << endl;
  else out << "Door is closed." << endl;
  return out;
}