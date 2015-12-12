// Lab 7, Using Operator Overloading
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#ifndef Rider_h
#define Rider_h

class Floor;

class Rider
{
private:
  const int idNum;
  const Floor* const dest;
  static int n;
public:
  Rider ( const Floor& f): idNum ( n ), dest( &f ) { n++; }
  bool operator== ( const Rider& ) const;
  bool operator< ( const Rider& ) const;
  const Floor& getDestination() const { return *dest; };
};

#endif