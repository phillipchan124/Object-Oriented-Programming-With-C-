// Lab 14, More STL vectors
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#ifndef Floor_h
#define Floor_h

#include "Rider.h"

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Floor
{
  const string NAME; // name of floor, for example: Mezzanine
  const int location; // inches above ground level
  vector<Rider> upRiders; // affected by addNewRider, removeUpRiders,...
  vector<Rider> downRiders; // ...and removeDownRiders functions
  
public:
  Floor(const int l, const char* const N = "unnamed") :NAME(N), location(l){}// name and location (inches above ground) of floor
  
  // inline functions
  int getLocation() const { return location; }
  bool hasRidersWaiting() const {if(upRiders.size()!=0 || downRiders.size()!=0) return true; else return false;}
  bool hasUpRiders() const { return upRiders.size()!=0; }
  bool hasDownRiders() const { return downRiders.size()!=0; }
  int getUpRiderCount() const { return upRiders.size(); }
  int getDownRiderCount() const{ return downRiders.size(); }
  string getName() const { return NAME; }
  
  // non-inline functions
  bool isPreferredDirectionUp() const; // based on Rider with smallest ID
  void addNewRider(const Rider&); // add to up- or down-vector
  vector<Rider> removeUpRiders(int); // int is max #of riders...
  vector<Rider> removeDownRiders(int); //...to move onto elevator
  
  // just in case you prefer to use "if (...== *toFloor)"
  //  in Elevator::removeRidersForDestinationFloor(), instead of "...== toFloor)"
  bool operator==(const Floor& floor) const {return NAME == floor.NAME;}
  
  friend ostream& operator<<(ostream&, const Floor&); // say name, location, #'s of up/down riders waiting
};

#endif
