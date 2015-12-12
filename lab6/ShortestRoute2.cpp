// Lab 6, Using Dynamic Memory Allocation
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Route;
class Leg
{
private:
  const char * const start;
  const char * const end;
  double dist;
public:
  Leg ( const char * const start, const char * const end, double dist )
  : start(start), end(end), dist(dist) {}
  friend class Route;
  friend void outputLeg( ostream&, const Leg& );
  friend void outputRoute( ostream&, const Route& );
};
class Route
{
private:
  const Leg** const legs;
  const int size;
  const double sumDist;
public:
  Route( const Leg & );
  Route( const Route &, const Leg&);
  Route( const Route&);
  friend void outputRoute( ostream&, const Route& );
  ~Route(){ delete[] legs;}
};

void outputLeg( ostream&, const Leg& );
void outputRoute( ostream&, const Route& );

int main()
{
  // print my name and this assignment's title
  cout << "Lab 6, Using Dynamic Memory Allocation \n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // create all of the Legs
  Leg leg1("San Francisco", "Sacramento", 87.3 );
  Leg leg2("Sacramento", "Reno", 135.2 );
  Leg leg3("Reno", "Salt Lake City", 518.5 );
  Leg leg4("Salt Lake City", "Chicago", 1399.2 );
  Leg leg5("Chicago", "New York City", 759.1 );
  
  // output all of the Legs
  cout << "\noutput all of the Legs\n";
  outputLeg( cout, leg1);
  outputLeg( cout, leg2);
  outputLeg( cout, leg3);
  outputLeg( cout, leg4);
  outputLeg( cout, leg5);
  
  // create all of the Routes
  Route route1( leg1 );
  Route route2 ( route1, leg2 );
  Route route3 ( route2, leg3 );
  Route route4 ( route3, leg4 );
  Route route5 ( route4, leg5 );
  
  // output all of the Routes
  cout << "\noutput all of the Routes\n";
  outputRoute( cout, route1 );
  outputRoute( cout, route2 );
  outputRoute( cout, route3 );
  outputRoute( cout, route4 );
  outputRoute( cout, route5 );
  
  // test copy constructor
  {
    cout << "\ntest copy constructor\n";
    const Route rCopy = route1;
    outputRoute( cout, rCopy );
  }
}
void outputLeg( ostream& out, const Leg& leg )
{
  out << leg.start << " to " << leg.end << ", " << leg.dist << " miles\n";
}
void outputRoute( ostream& out, const Route& route)
{
  for ( int i=0 ; i < route.size ; i++ )
    out << (route.legs[i])->start << " to ";
  out << (route.legs[route.size-1])->end << ", " << route.sumDist << " miles" << endl;
}
Route::Route( const Leg & leg)
: legs( new const Leg*[1]), size(1), sumDist(leg.dist)
{
  legs[0] = &leg;
}
Route::Route( const Route & route, const Leg& leg)
: legs( new const Leg*[ route.size+1] ), size( route.size+1 ), sumDist(route.sumDist+leg.dist)
{
  for ( int i=0 ; i < route.size ; i++ )
    legs[i] = route.legs[i];
  legs[route.size] = &leg;
}
Route::Route( const Route& route)
: legs( new const Leg*[ route.size] ), size( route.size ), sumDist( route.sumDist )
{
  for ( int i=0 ; i < route.size ; i++ )
    legs[i] = route.legs[i];
}
