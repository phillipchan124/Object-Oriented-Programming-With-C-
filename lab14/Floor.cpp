// Lab 9, Using vectors
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using std::endl;
using std::ostream;

#include "Floor.h"
#include "Rider.h"
#include "Elevator.h"

bool Floor::isPreferredDirectionUp() const// based on Rider with smallest ID
{
  if( !(hasDownRiders()) ) return true;
  if( !(hasUpRiders()) ) return false;
  if( upRiders[0] < downRiders[0] ) return true;
  return false;
}
void Floor::addNewRider(const Rider& r) // add to up- or down-vector
{
  if( r.getDestination().getLocation() > this->getLocation() ) upRiders.push_back(r);
  else downRiders.push_back(r);
}
vector<Rider> Floor::removeUpRiders(int capacity) // int is max #of riders...
{
  vector<Rider> leaving;
  if( hasUpRiders() )
  {
    vector<Rider> staying;
    for(int i=0 ; i < upRiders.size() ; i++)
    {
      if( leaving.size()!= capacity ) leaving.push_back(upRiders[i]);
      else staying.push_back(upRiders[i]);
    }
    upRiders = staying;
  }
  return leaving;
}
vector<Rider> Floor::removeDownRiders(int capacity) //...to move onto elevator
{
  vector<Rider> leaving;
  if( hasDownRiders() )
  {
    vector<Rider> staying;
    for(int i=0 ; i < downRiders.size() ; i++)
    {
      if( leaving.size()!= capacity ) leaving.push_back(downRiders[i]);
      else staying.push_back(downRiders[i]);
    }
    downRiders = staying;
  }
  return leaving;
}
ostream& operator<<(ostream& out, const Floor& f) // say name, location, #'s of up/down riders waiting
{
  out << f.NAME << ".";
  out << " Location of the floor is: " << f.getLocation() << ".";
  out << " Number of up riders waiting is: " << f.upRiders.size() << ".";
  out << " Number of down riders waiting is: " << f.downRiders.size() << ".";
  return out;
}