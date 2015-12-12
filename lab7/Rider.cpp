// Lab 7, Using Operator Overloading
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#include "Rider.h"

int Rider:: n = 0;

bool Rider::operator==( const Rider& r ) const
{
  bool result = true;
  
  if (idNum != r.idNum) result = false;
  
  return result;
}

bool Rider::operator<(const Rider& r) const
{
  bool result = false;
  
  if (idNum < r.idNum) result = true;
  
  return result;
}