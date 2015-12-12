// Lab 1b, Geometry Homework 1
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::cin;

#include <iomanip>
using std::setprecision;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstdlib>

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 1b, Geometry Homework 1 \n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // create a file-reading object
  ifstream fin;
  fin.open("geo.txt"); // open a file
  
  // create a file-writing object with column names
  ofstream fout;
  fout.open("geo.xls"); // create a file to output result
  fout << "Shape \tside \tradius \tlength \twidth \theight \t"
       << "area \tperimeter \tsurface area \tvolumne \n";
  
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
    int n = 0; // a for-loop index
    
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
      double nums[MAX_TOKENS_PER_LINE-1];
      for(int i = 1; i < MAX_TOKENS_PER_LINE; i++){
        if(token[i] != NULL)
          nums[i-1] = atof(token[i]);
        else
          nums[i-1] = 0;
      }
      // matching shape for tokens
      // calculate and output values for Square
      if(strcmp(token[0], "SQUARE") == 0){
        cout << token[0]; fout << token[0] << "\t";
        double square_side = nums[0];
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        cout << " side="<< square_side;
        fout.unsetf(ios::fixed|ios::showpoint);
        fout << setprecision(6);
        fout << square_side << "\t\t\t\t\t";
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);
        cout << " area=" << square_side * square_side
             << " perimeter=" << square_side * 4 << endl;
        fout.setf(ios::fixed|ios::showpoint);
        fout << setprecision(2);
        fout << square_side * square_side << "\t"
             << square_side * 4 << "\n";
      }
      // calculate and output values for Rectangle
      else if(strcmp(token[0], "RECTANGLE") == 0){
        cout << token[0]; fout << token[0] << "\t\t\t";
        double rectangle_length = nums[0];
        double rectangle_width = nums[1];
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        cout << " length=" << rectangle_length << " width=" << rectangle_width;
        fout.unsetf(ios::fixed|ios::showpoint);
        fout << setprecision(6);
        fout << rectangle_length << "\t" << rectangle_width << "\t\t";
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);
        cout << " area=" << rectangle_length * rectangle_width << " perimeter="
             << (2 * rectangle_length) + (2 * rectangle_width) << endl;
        fout.setf(ios::fixed|ios::showpoint);
        fout << setprecision(2);
        fout << rectangle_length * rectangle_width << "\t"
             << (2 * rectangle_length) + (2 * rectangle_width) << "\n";
      }
      // calculate and output values for Circle
      else if(strcmp(token[0],"CIRCLE") == 0){
        cout << token[0]; fout << token[0] << "\t\t";
        double circle_radius = nums[0];
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        cout << " radius=" << circle_radius;
        fout.unsetf(ios::fixed|ios::showpoint);
        fout << setprecision(6);
        fout << circle_radius << "\t\t\t\t" ;
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);
        cout << " area=" << PI * ((circle_radius) * (circle_radius))
             << " perimeter=" << PI * 2 * circle_radius << endl;
        fout.setf(ios::fixed|ios::showpoint);
        fout << setprecision(2);
        fout << PI * ((circle_radius) * (circle_radius)) << "\t"
             << PI * 2 * circle_radius << "\n";
      }
      // calculate and output values for Cube
      else if(strcmp(token[0], "CUBE") == 0){
        cout << token[0]; fout << token[0] << "\t";
        double cube_side = nums[0];
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        cout << " side=" << cube_side;
        fout.unsetf(ios::fixed|ios::showpoint);
        fout << setprecision(6);
        fout << cube_side << "\t\t\t\t\t\t\t";
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);
        cout << " surface area=" << 6 * (cube_side * cube_side)
             << " volume=" << cube_side * cube_side * cube_side << endl;
        fout.setf(ios::fixed|ios::showpoint);
        fout << setprecision(2);
        fout << 6 * (cube_side * cube_side) << "\t"
             << cube_side * cube_side * cube_side << "\n";
      }
      // calculate and output values for Prism
      else if(strcmp(token[0], "PRISM") == 0){
        cout << token[0]; fout << token[0] << "\t\t\t";
        double prism_length = nums[0];
        double prism_width = nums[1];
        double prism_height = nums[2];
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        cout << " length="<< prism_length << " width=" << prism_width << " height=" << prism_height;
        fout.unsetf(ios::fixed|ios::showpoint);
        fout << setprecision(6);
        fout << prism_length << "\t" << prism_width << "\t" << prism_height << "\t\t\t";
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);
        cout << " surface area=" << ((prism_length * prism_width) + (prism_width * prism_height) + (prism_length * prism_height)) * 2
             << " volume= " << prism_length * prism_width * prism_height << endl;
        fout.setf(ios::fixed|ios::showpoint);
        fout << setprecision(2);
        fout << ((prism_length * prism_width) + (prism_width * prism_height) + (prism_length * prism_height)) * 2 << "\t"
             << prism_length * prism_width * prism_height << "\n";
      }
      // calculate and output values for Cylinder
      else if(strcmp(token[0], "CYLINDER") == 0){
        cout << token[0]; fout << token[0] << "\t\t";
        double cylinder_radius = nums[0];
        double cylinder_height = nums[1];
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        cout << " radius=" << cylinder_radius << " height=" << cylinder_height;
        fout.unsetf(ios::fixed|ios::showpoint);
        fout << setprecision(6);
        fout << cylinder_radius << "\t\t\t" << cylinder_height << "\t\t\t";
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);
        cout << " surface area=" << PI * (cylinder_radius * cylinder_radius) * 2 + PI * (cylinder_radius * cylinder_height) * 2
             << " volume=" << PI * (cylinder_radius * cylinder_radius) * cylinder_height << endl;
        fout.setf(ios::fixed|ios::showpoint);
        fout << setprecision(2);
        fout << PI * (cylinder_radius * cylinder_radius) * 2 + PI * (cylinder_radius * cylinder_height) * 2 << "\t"
             << PI * (cylinder_radius * cylinder_radius) * cylinder_height << "\n";
      }
      else
        cout<< token[0] << " invalid object " << endl;
    }
  }
}