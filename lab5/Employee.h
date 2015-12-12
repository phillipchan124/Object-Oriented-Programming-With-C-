// Lab 5a
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#ifndef Employee_H
#define Employee_H

#include <string>
using std::string;

#include "Date.h" // include Date class definition

class Employee
{
public:
  Employee( const string &, const string &,
           const Date &, const Date &);
  void print () const;
  ~Employee(); // provided to confirm destruction order
private:
  string firstName; // composition: member object
  string lastName; // composition: member object
  const Date birthDate; // composition: member object
  const Date hireDate; // composition: member object
}; // end class Employee

#endif