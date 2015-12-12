// Lab 5a
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Employee.h" // Employee class definition
#include "Date.h" // Date class definition

// constructor uses member initializer list to pass initializer
// values to constructor of member objects
Employee::Employee( const string & first, const string & last,
                   const Date & dateOfBirth, const Date & dateOfHire)
: firstName( first ), // initialize firstName
  lastName( last ), // initialize lastName
  birthDate( dateOfBirth ), // initialize birthDate
  hireDate( dateOfHire ) // initialize hireDate
{
  // output Employee object to show when constructor is called
  cout << "Employee object constructor: "
  << firstName << ' ' << lastName << endl;
} // end Employee constructor

// print Employee object
void Employee::print() const
{
  cout << lastName << ", " << firstName << " Hired: ";
  hireDate.print();
  cout << " Birthday: ";
  birthDate.print();
  cout << endl;
} // end function print

// output Employee object to show when its destructor is called
Employee::~Employee()
{
  cout << "Employee object destructor: "
  << lastName << ", " << firstName << endl;
} // end ~Employee destructor