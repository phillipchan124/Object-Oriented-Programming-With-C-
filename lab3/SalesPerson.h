// SalesPerson.h, by Kwun Hang Chan (1509834)
//
// Lab 3a
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#ifndef SalesPerson_h
#define SalesPerson_h

class SalesPerson
{
public:
  static const int monthsPerYear = 12; // months in one year
  SalesPerson();
  void getSalesFromUser(); // input sales from keyboard()
  void setSales( int, double ); // set sales for a specific month
  void printAnnualSales(); // summarize and print sales
private:
  double totalAnnualSales(); // prototype for utility function
  double sales[ monthsPerYear ]; // 12 monthly sales figures
}; // end class SalesPerson

#endif
