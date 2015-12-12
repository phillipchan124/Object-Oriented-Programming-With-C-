// Lab 5a
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using std::cout;
using std::endl;

#include "Date.h" // include Date class definition

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date( int mn, int dy, int yr )
{
  if ( mn > 0 && mn <= monthsPerYear ) // validate the month
    month = mn;
  else
  {
    month = 1; // invalid month set to 1
    cout << "Invalid month (" << mn << ") set to 1.\n";
  } // end else
  
  year = yr; // could validate yr
  day = checkDay( dy ); // validate the day
  
  // output Date object to show when its constructor is called
  cout << "Date object constructor for date ";
  print();
  cout << endl;
} // end Date constructor

// print Date object in form month/day/year
void Date::print() const
{
  cout << month << '/' << day << '/' << year;
} // end function print

// utility function to confirm proper pay value based on
// month and year; handles leap years, too
int Date::checkDay( int testDay ) const
{
  static const int daysPerMonth[ monthsPerYear + 1 ] =
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  
  // determine whether testDay is valid for specified month
  if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
    return testDay;
  
  // February 29 check for leap year
  if ( month == 2 && testDay == 29 && ( year % 400 == 0 ||
     ( year % 4 == 0 && year % 100 != 0 ) ) )
    return testDay;
  
  cout << "Invalid day (" << testDay << ") set to 1.\n";
  return 1; // leave object in consistent state if bad value
} // end function checkDay