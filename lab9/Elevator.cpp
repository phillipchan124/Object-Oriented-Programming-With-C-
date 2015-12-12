// Lab 9, Using vectors
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using std::ostream;
using std::endl;

#include <vector>
using std::vector;

#include "Floor.h"
#include "Elevator.h"

int Elevator::elevatorID = 0;
const int Elevator::IDLE = 0;
const int Elevator::UP = 1;
const int Elevator::DOWN = -1;

Elevator::Elevator(const int cap, const int v, const Floor& startFloor)
:ID(Elevator::elevatorID), capacity(cap), speed(v), toFloor(0)
{
  elevatorID++;
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
  out << "Elevator is located at " << e.getLocation() << " inches from the ground level.";
  out << "Elevator ID: " << ID << ". ";
  
  if (e.isIdle()) out << " Elevator is idle.";
  else if(e.isDirectionUp())  out << " Elevator is going up.";
  else if(e.isDirectionDown()) out << " Elevator is going down.";
  
  if (e.isDoorOpen()) out << " Door is open.";
  else out << " Door is closed.";
  
  int rSize = e.riders.size();
  if (rSize == 0) out << " No riders.";
  else if (rSize == 1) out << " 1 rider.";
  else out << " " << rSize << " riders.";
    
  return out;
}

vector<Rider> Elevator::removeRidersForDestinationFloor()
{
  vector<Rider> leaving;
  
  if(riders.size()!=0)
  {
    vector<Rider> remaining;
    
    for(int i=0 ; i<riders.size() ; i++)
    {
      if( toFloor == &riders[i].getDestination() )
        leaving.push_back(riders[i]);
      else
        remaining.push_back(riders[i]);
    }
    riders = remaining;
  }
  return leaving;
}

void Elevator::addRiders(const vector<Rider>& r)
{
  int rSize = r.size();
  for(int i=0 ; i<rSize ; i++)
  {
    if ( getAvailableSpace()>0 ) riders.push_back( r[i] );
    else break;
  }
}

void Elevator::setDestinationBasedOnRiders()
{
  if( !hasRiders() )
    return;
  
  toFloor = &riders[0].getDestination();
  
  for( int i=1 ; i<riders.size() ; i++)
  {
    int eDist = getLocation() - getDestination().getLocation();
    int rDest = getLocation() - riders[i].getDestination().getLocation();
    int absDist = abs (eDist-rDest);
    if ( absDist <= eDist ) toFloor = &riders[i].getDestination();
  }
}