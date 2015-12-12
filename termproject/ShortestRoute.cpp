// Term Project
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include <set>
using std::set;

#include <algorithm>
using std::min_element;

class Route;
class ShortestRoute;
class Leg
{
private:
  const char * const start;
  const char * const end;
  double dist;
  static const Leg legs[];
public:
  Leg ( const char * const start, const char * const end, double dist )
  : start(start), end(end), dist(dist) {}
  friend class Route;
  friend class ShortestRoute;
  friend ostream& operator<<( ostream&, const Leg& );
  friend ostream& operator<<( ostream&, const Route& );
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
  friend ostream& operator<<( ostream&, const Route& );
  ~Route(){ delete[] legs;}
  bool operator<(const Route& r) const { return sumDist < r.sumDist; }
  friend class ShortestRoute;
};
class ShortestRoute
{
private:
  static const Leg legs[];
  static const int arrayLen;
public:
  static Route getAnyRoute(const string, const string);
  static Route getShortestRoute(const string, const string);
};
const int ShortestRoute::arrayLen = 41;
const Leg ShortestRoute::legs[] =
{
  Leg ("San Francisco", "Sacramento", 87),
  Leg ("San Francisco", "Reno", 218),
  Leg ("Albuquerque", "Wichita", 592),
  Leg ("Albuquerque", "Oklahoma City", 541),
  Leg ("Oklahoma City", "Tulsa", 107),
  Leg ("Wichita", "Tulsa", 176),
  Leg ("Wichita", "Jefferson City", 328),
  Leg ("Tulsa", "Jefferson City", 316),
  Leg ("Tulsa", "Memphis", 402),
  Leg ("Jefferson City", "Columbus", 542),
  Leg ("Jefferson City", "Charleston", 987),
  Leg ("Jefferson City", "Memphis", 335),
  Leg ("Chicago", "Columbus", 359),
  Leg ("Columbus", "New York City", 535),
  Leg ("Memphis", "Columbus", 587),
  Leg ("Memphis", "Charleston", 598),
  Leg ("Charleston", "New York City", 532),
  Leg ("San Francisco", "Carson City", 215),
  Leg ("San Francisco", "Las Vegas", 569),
  Leg ("San Francisco", "Los Angeles", 382),
  Leg ("Sacramento", "Reno", 135),
  Leg ("Los Angeles", "Albuquerque", 789),
  Leg ("Los Angeles", "Phoenix", 374),
  Leg ("Las Vegas", "Phoenix", 298),
  Leg ("Las Vegas", "Albuquerque", 574),
  Leg ("Las Vegas", "Aurora", 762),
  Leg ("Reno", "Salt Lake City", 5185),
  Leg ("Salt Lake City", "Chicago", 1399),
  Leg ("Chicago", "New York City", 759),
  Leg ("Columbus", "Charleston", 162),
  Leg ("Albuquerque", "Aurora", 447),
  Leg ("Aurora", "Chicago", 1005),
  Leg ("Aurora", "Columbus", 1251),
  Leg ("Aurora", "Jefferson City", 750),
  Leg ("Aurora", "Wichita", 511),
  Leg ("Aurora", "Tulsa", 684),
  Leg ("Aurora", "Oklahoma City", 670),
  Leg ("San Francisco", "New York City", 21000),
  Leg ("Carson City", "Salt Lake City", 535),
  Leg ("Salt Lake City", "Aurora", 541),
  Leg ("Phoenix", "Albuquerque", 422),
  Leg ("San Francisco", "New York City", 21000)
};
int main()
{
  try
  {
    cout << "Any route from San Francisco to New York:" << endl;
    cout << ShortestRoute::getAnyRoute("San Francisco", "New York City");
    cout << "Shortest route from San Francisco to New York:" << endl;
    cout << ShortestRoute::getShortestRoute("San Francisco", "New York City");
  }
  catch(int n)
  {
    cout << "There is no route." << endl;
  }
}
ostream& operator<<(ostream& out, const Leg& leg)
{
  out << leg.start << " to " << leg.end << ", " << leg.dist << " miles\n";
  return out;
}
ostream& operator<<(ostream& out, const Route& route)
{
  for ( int i=0 ; i < route.size ; i++ )
    out << (route.legs[i])->start << " to ";
  out << (route.legs[route.size-1])->end << ", " << route.sumDist << " miles" << endl;
  return out;
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
Route ShortestRoute::getAnyRoute(const string fromCity, const string toCity)
{
  for(int i =0 ; i < arrayLen ; i ++)
  {
    if(strcmp(legs[i].end, toCity.c_str()) == 0)
    {
      if(strcmp(legs[i].start, fromCity.c_str()) == 0) return Route(legs[i]);
      else return Route(getAnyRoute(fromCity, legs[i].start), legs[i]);
    }
  }
  throw 0;
}
Route ShortestRoute::getShortestRoute(const string fromCity, const string toCity)
{
  set<Route> routes;
  for(int i =0 ; i < arrayLen ; i ++)
  {
    if(strcmp(legs[i].end, toCity.c_str()) == 0)
    {
      if(strcmp(legs[i].end, toCity.c_str()) == 0)
      {
        if(strcmp(legs[i].start, fromCity.c_str()) == 0) routes.insert(Route(legs[i]));
        else routes.insert(Route(getAnyRoute(fromCity, legs[i].start), legs[i]));
      }
    }
  }
  if ( routes.size() != 0 )
  {
    set<Route>::iterator it = routes.begin();
    set<Route>::iterator eit = routes.end();
    it = min_element(it, eit);
    return *it;
  }
  throw 0;
}