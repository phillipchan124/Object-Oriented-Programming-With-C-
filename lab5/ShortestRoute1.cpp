// Lab 5b, Writing friend Functions
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Leg
{
private:
  const char * const start;
  const char * const end;
  int dist;
public:
  Leg ( const char * const start, const char * const end, int dist )
  : start(start), end(end), dist(dist) {}
  friend void outputLeg( ostream&, const Leg& );
};

void outputLeg( ostream&, const Leg& );

int main()
{
  // print my name and this assignment's title
  cout << "Lab 5b, Writing friend Functions \n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // create Leg objects
  Leg leg1("San Francisco", "Sacramento", 87 );
  Leg leg2("Sacramento", "Reno", 135 );
  Leg leg3("Reno", "Salt Lake City", 518 );
  Leg leg4("Salt Lake City", "Chicago", 1399 );
  Leg leg5("Chicago", "New York City", 759 );
  
  // output legs
  outputLeg( cout, leg1);
  outputLeg( cout, leg2);
  outputLeg( cout, leg3);
  outputLeg( cout, leg4);
  outputLeg( cout, leg5);
}

void outputLeg( ostream& out, const Leg& leg )
{
  out << leg.start << " to " << leg.end << ", " << leg.dist << " miles\n";
}

