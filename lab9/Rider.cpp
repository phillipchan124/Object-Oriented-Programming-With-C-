// Lab 9, Using vectors
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
const Rider& Rider::operator=(const Rider& r)
{
  if ( &r != this)
  {
    const_cast<int&>(idNum) = r.idNum;
    const_cast<const Floor*&>(dest) = r.dest;
  }
  return *this;
}