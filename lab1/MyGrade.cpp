// Lab 1a, My Grade
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


int main()
{
  // print my name and this assignment's title
  cout << "Lab 1a, My Grade\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  int total; // sum of grades entered by user
  int gradeCounter; // number of the grade to be entered next
  int grade;
  int average;
  char buf[100];
    
  // initialization phase
  total = 0; // initialize total
  gradeCounter = 1; // initialize loop counter
    
  // processing phase
  while ( gradeCounter <= 10)
  {
    cout << "Enter grade: "; // prompt for input
    cin >> buf; grade = atof(buf);
    cin.ignore(1000, 10);
    total = total + grade; // add grade to total
    gradeCounter = gradeCounter + 1; // increment counter by 1
  } // end while
    
  // termination phase
  average = total / 10; // integer division yields integer result
    
  // display total and average of grades
  cout << "\nTotal of all 10 grades is " << total << endl;
  cout << "Class average is " << average << endl;
} // end main