// Lab 2b, Writing Templates And Overloading Operators
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using namespace std;

#include <cassert>

#include "SalesPerson.h" 
#include "SalesPerson.h" 

int main()
{
  cout << "OK";
  SalesPerson salesperson;
  salesperson.getSalesFromUser();
  salesperson.printAnnualSales();
  
  salesperson.setSales(1, 10);
  salesperson.setSales(2, 10);
  salesperson.printAnnualSales();
  
  
}