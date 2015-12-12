// Lab 7, Using Operator Overloading
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#ifndef Floor_h
#define Floor_h

class Floor
{
private:
  const int location;
public:
  Floor (const int l): location( l ){}
  int getLocation() const { return location; }
};

#endif