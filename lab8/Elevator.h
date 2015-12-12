// Lab 8, Using Inline Functions and Constants
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#ifndef Elevator_h
#define Elevator_h

#include <iostream>
using std::ostream;

class Floor;
class Elevator
{
  // class-defined constants
  static int elevatorID; // initialize to zero; use to assign unique ID to each elevator
  static const int IDLE; // a unique numeric code
  static const int UP; // another unique numeric code
  static const int DOWN; // yet another unique numeric code
  
  // private member variables
  const int ID; // a unique identifier
  const int capacity; // max number of riders, set in constructor
  const int speed; // inches per second, up or down, set in constructor
  const Floor* toFloor; // destination floor, initialized in constructor to zero
  int location; // inches above ground level, initialized in constructor based on starting floor
  int direction; // equal to IDLE, UP, DOWN, initialized to IDLE in constructor
  bool doorOpen; // initialized to true in constructor
  
public:
  Elevator(const int, const int, const Floor& ); // capacity, speed, and starting floor
  
  // inline functions
  bool isDoorOpen() const { return doorOpen; }
  bool isIdle() const { return direction==IDLE; }
  bool isDirectionUp() const { return direction==UP; }
  bool isDirectionDown() const { return direction==DOWN; }
  void closeDoor() { doorOpen=false; }
  void openDoor() { doorOpen=true; }
  void setIdle() { direction=IDLE; }
  void setDirectionUp() { direction=UP; }
  void setDirectionDown() { direction=DOWN; }
  void moveUp() { location+=speed; }
  void moveDown() { location-=speed; }
  void setDestination(const Floor* floor) { toFloor=floor; }
  const Floor& getDestination() const { return *toFloor; }
  int getLocation() const { return location; }
  bool hasADestination() const { return toFloor!=0; }
  
  // non-inline functions
  bool isNearDestination() const; // true if distance to destination is less than OR EQUAL TO the speed
  void moveToDestinationFloor(); // set location to that of destination floor (if there is one)
  
  // friend function
  friend ostream& operator<<(ostream&, const Elevator&);
};

#endif