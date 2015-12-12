// Lab 12, UI-independent Classes
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::cin;
using std::ostream;

#include <iomanip>
using std::setprecision;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstdlib>

#include <vector>
using std::vector;

#include "GeometryHomework.h"

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 12, UI-independent Classes \n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // create arrays for shape
  vector<const Shape*> shapes;
  
  // create a file-reading object
  ifstream fin;
  fin.open("geo.txt"); // open a file
  
  if (!fin.good()){
    cout << "geo.txt cannot be found. \n";
    return 1; // exit if file not found
  }
  // read each line of the file
  while (!fin.eof())
  {
    // read an entire line into memory
    char buf[MAX_CHARS_PER_LINE];
    fin.getline(buf, MAX_CHARS_PER_LINE);
    
    // parse the line into blank-delimited tokens
    int n = 0; // a for-loop indexß
    
    // array to store memory addresses of the tokens in buf
    const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0
    
    // parse the line
    token[0] = strtok(buf, DELIMITER); // first token
    if (token[0]) // zero if line is blank
    {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER); // subsequent tokens
        if (!token[n]) break; // no more tokens
      }
      // matching shape for tokens
      // calculate and output values for Square
      if(strcmp(token[0], "SQUARE") == 0){
        const Shape* const s = new Square(token);
        shapes.push_back(s);
      }
      else if(strcmp(token[0], "RECTANGLE") == 0){
        const Shape* const s = new Rectangle(token);
        shapes.push_back(s);
      }
      else if(strcmp(token[0],"CIRCLE") == 0){
        const Shape* const s = new Circle(token);
        shapes.push_back(s);
      }
      else if(strcmp(token[0], "CUBE") == 0){
        const Shape* const s = new Cube(token);
        shapes.push_back(s);
      }
      else if(strcmp(token[0], "PRISM") == 0){
        const Shape* const s = new Prism(token);
        shapes.push_back(s);
      }
      else if(strcmp(token[0], "CYLINDER") == 0){
        const Shape* const s = new Cylinder(token);
        shapes.push_back(s);
      }
      else{
        cout<< token[0] << " invalid object " << endl;
      }
    }
  }
  
  fin.close(); // close the file

  // output in console
  for (int i = 0; i < shapes.size(); i++ ) cout << shapes.at(i);
  
  // create a file-writing object with column names
  ofstream fout;
  fout.open("geo.xls"); // create a file to output result
  fout << "Shape \tside \tradius \tlength \twidth \theight \t"
  << "area \tperimeter \tsurface area \tvolumne \n";
  
  // outout in excel spreadsheet
  for (int i = 0; i < shapes.size(); i++ ) shapes.at(i) -> xls(fout);
  
  fout.close(); // close the excel spreadsheet
  
  // delete and free dynamic memory
  for (int i = 0; i < shapes.size(); i++ ) delete shapes.at(i);
}