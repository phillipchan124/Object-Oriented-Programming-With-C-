// Lab 3b, Writing With Classes
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

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159;

// class for shapes
class Square
{
  double side;
public:
  Square( const char* [] );
  void output(ostream&) const;
  void xls(ostream&) const;
};
class Rectangle
{
  double length;
  double width;
public:
  Rectangle( const char* [] );
  void output(ostream&) const;
  void xls(ostream&) const;
};
class Circle
{
  double radius;
public:
  Circle( const char* [] );
  void output(ostream&) const;
  void xls(ostream&) const;
};
class Cube
{
  double side;
public:
  Cube( const char* [] );
  void output(ostream&) const;
  void xls(ostream&) const;
};
class Prism
{
  double length;
  double width;
  double height;
public:
  Prism( const char* [] );
  void output(ostream&) const;
  void xls(ostream&) const;
};
class Cylinder {
  double radius;
  double height;
public:
  Cylinder( const char* [] );
  void output(ostream&) const;
  void xls(ostream&) const;
};

int main()
{
  // print my name and this assignment's title
  cout << "Lab 3b, Writing With Classes \n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // create arrays for shape
  void *shape[100];
  int shapeId[100];
  int shapeIndex = 0;
  
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
        Square* s = new Square(token);
        shape[shapeIndex] = s;
        shapeId[shapeIndex] = 1;
      }
      else if(strcmp(token[0], "RECTANGLE") == 0){
        Rectangle* r = new Rectangle(token);
        shape[shapeIndex] = r;
        shapeId[shapeIndex] = 2;
      }
      else if(strcmp(token[0],"CIRCLE") == 0){
        Circle* c = new Circle(token);
        shape[shapeIndex] = c;
        shapeId[shapeIndex] = 3;
      }
      else if(strcmp(token[0], "CUBE") == 0){
        Cube* c = new Cube(token);
        shape[shapeIndex] = c;
        shapeId[shapeIndex] = 4;
      }
      else if(strcmp(token[0], "PRISM") == 0){
        Prism* p = new Prism(token);
        shape[shapeIndex] = p;
        shapeId[shapeIndex] = 5;
      }
      else if(strcmp(token[0], "CYLINDER") == 0){
        Cylinder* c = new Cylinder(token);
        shape[shapeIndex] = c;
        shapeId[shapeIndex] = 6;
      }
      else{
        cout<< token[0] << " invalid object " << endl;
        shapeIndex--;
      }
      shapeIndex++;
    }
  }
  
  fin.close(); // close the file

  // output in console
  for (int i = 0; i < shapeIndex; i++ )
  {
    if ( shapeId[i] == 1 ) ((Square*)shape[i]) -> output(cout);
    else if ( shapeId[i] == 2 ) ((Rectangle*)shape[i]) -> output(cout);
    else if ( shapeId[i] == 3 ) ((Circle*)shape[i]) -> output(cout);
    else if ( shapeId[i] == 4 ) ((Cube*)shape[i]) -> output(cout);
    else if ( shapeId[i] == 5 ) ((Prism*)shape[i]) -> output(cout);
    else if ( shapeId[i] == 6 ) ((Cylinder*)shape[i]) -> output(cout);
  }
  
  // create a file-writing object with column names
  ofstream fout;
  fout.open("geo.xls"); // create a file to output result
  fout << "Shape \tside \tradius \tlength \twidth \theight \t"
  << "area \tperimeter \tsurface area \tvolumne \n";
  
  // outout in excel spreadsheet
  for (int i = 0; i < shapeIndex; i++ )
  {
    if ( shapeId[i] == 1)  ((Square*)shape[i]) -> xls(fout);
    else if ( shapeId[i] == 2 ) ((Rectangle*)shape[i]) -> xls(fout);
    else if ( shapeId[i] == 3 ) ((Circle*)shape[i]) -> xls(fout);
    else if ( shapeId[i] == 4 ) ((Cube*)shape[i]) -> xls(fout);
    else if ( shapeId[i] == 5 ) ((Prism*)shape[i]) -> xls(fout);
    else if ( shapeId[i] == 6 ) ((Cylinder*)shape[i]) -> xls(fout);
  }
  
  fout.close(); // close the excel spreadsheet
  
  // delete and free dynamic memory
  for (int i = 0; i < shapeIndex; i++ )
  {
    if ( shapeId[i] == 1 ) delete (Square*)shape[i];
    else if ( shapeId[i] == 2 )  delete (Rectangle*)shape[i];
    else if ( shapeId[i] == 3 ) delete (Circle*)shape[i];
    else if ( shapeId[i] == 4 ) delete (Cube*)shape[i];
    else if ( shapeId[i] == 5 ) delete (Prism*)shape[i];
    else if ( shapeId[i] == 6 ) delete (Cylinder*)shape[i];
  }
}
// constructors
Square::Square(const char* token[4])
{
  side = 0==token[1]? 0.0:atof(token[1]);
}
Rectangle::Rectangle(const char*  token[4])
{
  length = 0==token[1]? 0.0:atof(token[1]);
  width = 0==token[2]? 0.0:atof(token[2]);
}
Circle::Circle(const char* token[4])
{
  radius = 0==token[1]? 0.0:atof(token[1]);
}
Cube::Cube(const char* token[4])
{
  side = 0==token[1]? 0.0:atof(token[1]);
}
Prism::Prism(const char* token[4])
{
  length = 0==token[1]? 0.0:atof(token[1]);
  width = 0==token[2]? 0.0:atof(token[2]);
  height = 0==token[3]? 0.0:atof(token[3]);
}
Cylinder::Cylinder(const char* token[4])
{
  radius = 0==token[1]? 0.0:atof(token[1]);
  height = 0==token[2]? 0.0:atof(token[2]);
}
// output in console
void Square::output(ostream& out) const
{
  out << "SQUARE";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << " side="<< side;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " area=" << side * side
  << " perimeter=" << side * 4 << endl;
}
void Rectangle::output(ostream& out) const
{
  out << "RECTANGLE";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << " length="<< length << " ";
  out << "width="<< width << " ";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << "area=" << length * width
  << " perimeter=" << (length + width) * 2 << endl;
}
void Circle::output(ostream& out) const
{
  out << "CIRCLE";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << " radius=" << radius << " ";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << "area=" << PI * radius * radius
  << " perimeter=" << PI * 2 * radius << endl;
}
void Cube::output(ostream& out) const
{
  out << "CUBE";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << " side=" << side;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " surface area=" << side * side *6
  << " volume=" << side * side * side << endl;
}
void Prism::output(ostream& out) const
{
  out << "PRISM";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << " length=" << length << " width=" << width << " height=" << height;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " surface area=" << ((length * width) + (width * height) + (length * height)) * 2
  << " volume= " << length * width * height << endl;
}
void Cylinder::output(ostream& out) const
{
  out << "CYLINDER";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << " radius=" << radius << " height=" << height;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " surface area=" << PI * (radius * radius) * 2 + PI * (radius * height) * 2
  << " volume=" << PI * (radius * radius) * height << endl;
}
// output to xls
void Square::xls(ostream& out) const
{
  out << "SQUARE" << "\t";
  cout.unsetf(ios::fixed|ios::showpoint);
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << side << "\t\t\t\t\t";;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << side * side << "\t"
  << side * 4 << "\n";
}
void Rectangle::xls(ostream& out) const
{
  out << "RECTANGLE "  << "\t\t\t";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << length << "\t" << width << "\t\t";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << length * width << "\t" << (length + width) * 2 << "\n";
}
void Circle::xls(ostream& out) const
{
  out << "CIRCLE" << "\t\t";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << radius << "\t\t\t\t";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << PI * radius * radius << "\t"
  << PI * 2 * radius << "\n";
}
void Cube::xls(ostream& out) const
{
  out << "CUBE" << "\t";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << side << "\t\t\t\t\t\t\t";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << side * side * 6 << "\t"
  << side * side * side << "\n";
}
void Prism::xls(ostream& out) const
{
  out << "PRISM" << "\t\t\t";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << length << "\t" << width << "\t" << height << "\t\t\t";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << ((length * width) + (width * height) + (length * height)) * 2 << "\t"
  << length * width * height << "\n";
}
void Cylinder::xls(ostream& out) const
{
  out << "CYLINDER" << "\t\t";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << radius << "\t\t\t" << height << "\t\t\t";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << PI * (radius * radius) * 2 + PI * (radius * height) * 2 << "\t"
  << PI * (radius * radius) * height << "\n";
}