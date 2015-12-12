// Lab 10, Using Inheritance
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

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159;

// class for shapes
class Shape {};
// Square
class Square : public Shape
{
protected:
  const double side;
public:
  Square( const char* const token[] ): Shape(), side( 0==token[1] ? 0.0 : atof(token[1]) ){}
  void output(ostream&) const;
  void xls(ostream&) const;
};
class Cube : public Square
{
public:
  Cube( const char* const token[] )
  : Square( token ){}
  void output(ostream&) const;
  void xls(ostream&) const;
};
// Rectangle
class Rectangle : public Shape
{
protected:
  const double length;
  const double width;
public:
  Rectangle( const char* const token[] )
  : length ( 0==token[1]? 0.0:atof(token[1]) ), width ( 0==token[2]? 0.0:atof(token[2]) ){}
  void output(ostream&) const;
  void xls(ostream&) const;
};
class Prism : public Rectangle
{
public:
  const double height;
  Prism( const char* const token[] )
  : Rectangle( token ) , height ( 0==token[3]? 0.0:atof(token[3]) ){}
  void output(ostream&) const;
  void xls(ostream&) const;
};
// Circle
class Circle : public Shape
{
protected:
  const double radius;
public:
  Circle( const char* const token[] )
  : radius ( 0==token[1]? 0.0:atof(token[1]) ) {}
  void output(ostream&) const;
  void xls(ostream&) const;
};
class Cylinder : public Circle
{
public:
  const double height;
  Cylinder( const char* const token[] )
  : Circle( token ), height ( 0==token[2]? 0.0:atof(token[2]) ){}
  void output(ostream&) const;
  void xls(ostream&) const;
};
// standalone output stream manipulators
ostream& reset(ostream& out) // requires iostream, using ostream
{
  out.unsetf(ios::fixed|ios::showpoint); // requires iostream, using ios
  out << setprecision(6); // requires iostream and iomanip, using setprecision
  return out;
}
ostream& set(ostream& out) // requires iostream, using ostream
{
  out.setf(ios::fixed|ios::showpoint); // requires iostream, using ios
  out << setprecision(2); // requires iostream and iomanip, using setprecision
  return out;
}

int main()
{
  // print my name and this assignment's title
  cout << "Lab 10, Using Inheritance \n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // create arrays for shape
  vector<const Shape*> shapes;
  vector<int> shapeId;
  
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
        const Square* const s = new Square(token);
        shapes.push_back(s);
        shapeId.push_back(1);
      }
      else if(strcmp(token[0], "RECTANGLE") == 0){
        const Rectangle* const s = new Rectangle(token);
        shapes.push_back(s);
        shapeId.push_back(2);
      }
      else if(strcmp(token[0],"CIRCLE") == 0){
        const Circle* const s = new Circle(token);
        shapes.push_back(s);
        shapeId.push_back(3);
      }
      else if(strcmp(token[0], "CUBE") == 0){
        const Cube* const s = new Cube(token);
        shapes.push_back(s);
        shapeId.push_back(4);
      }
      else if(strcmp(token[0], "PRISM") == 0){
        const Prism* const s = new Prism(token);
        shapes.push_back(s);
        shapeId.push_back(5);
      }
      else if(strcmp(token[0], "CYLINDER") == 0){
        const Cylinder* const s = new Cylinder(token);
        shapes.push_back(s);
        shapeId.push_back(6);
      }
      else{
        cout<< token[0] << " invalid object " << endl;
      }
    }
  }
  
  fin.close(); // close the file

  // output in console
  for (int i = 0; i < shapeId.size(); i++ )
  {
    if ( shapeId.at(i) == 1 ) ((Square*)shapes.at(i)) -> output(cout);//((Square*)shape[i]) -> output(cout);
    else if ( shapeId.at(i) == 2 ) ((Rectangle*)shapes.at(i)) -> output(cout);
    else if ( shapeId.at(i) == 3 ) ((Circle*)shapes.at(i)) -> output(cout);
    else if ( shapeId.at(i) == 4 ) ((Cube*)shapes.at(i)) -> output(cout);
    else if ( shapeId.at(i) == 5 ) ((Prism*)shapes.at(i)) -> output(cout);
    else if ( shapeId.at(i) == 6 ) ((Cylinder*)shapes.at(i)) -> output(cout);
  }
  
  // create a file-writing object with column names
  ofstream fout;
  fout.open("geo.xls"); // create a file to output result
  fout << "Shape \tside \tradius \tlength \twidth \theight \t"
  << "area \tperimeter \tsurface area \tvolumne \n";
  
  // outout in excel spreadsheet
  for (int i = 0; i < shapeId.size(); i++ )
  {
    if ( shapeId.at(i) == 1) ((Square*)shapes.at(i)) -> xls(fout);
    else if ( shapeId.at(i) == 2 ) ((Rectangle*)shapes.at(i)) -> xls(fout);
    else if ( shapeId.at(i) == 3 ) ((Circle*)shapes.at(i)) -> xls(fout);
    else if ( shapeId.at(i) == 4 ) ((Cube*)shapes.at(i)) -> xls(fout);
    else if ( shapeId.at(i) == 5 ) ((Prism*)shapes.at(i)) -> xls(fout);
    else if ( shapeId.at(i) == 6 ) ((Cylinder*)shapes.at(i)) -> xls(fout);
  }
  
  fout.close(); // close the excel spreadsheet
  
  // delete and free dynamic memory
  for (int i = 0; i < shapeId.size(); i++ )
  {
    if ( shapeId.at(i) == 1 ) delete (Square*)shapes.at(i);
    else if ( shapeId.at(i) == 2 ) delete (Rectangle*)shapes.at(i);
    else if ( shapeId.at(i) == 3 ) delete (Circle*)shapes.at(i);
    else if ( shapeId.at(i) == 4 ) delete (Cube*)shapes.at(i);
    else if ( shapeId.at(i) == 5 ) delete (Prism*)shapes.at(i);
    else if ( shapeId.at(i) == 6 ) delete (Cylinder*)shapes.at(i);
  }
}
// output in console
void Square::output(ostream& out) const
{
  out << "SQUARE";
  out << reset;
  out << " side="<< side;
  out << set;
  out << " area=" << side * side
  << " perimeter=" << side * 4 << endl;
}
void Rectangle::output(ostream& out) const
{
  out << "RECTANGLE";
  out << reset;
  out << " length="<< length << " ";
  out << "width="<< width << " ";
  out << set;
  out << "area=" << length * width
  << " perimeter=" << (length + width) * 2 << endl;
}
void Circle::output(ostream& out) const
{
  out << "CIRCLE";
  out << reset;
  out << " radius=" << radius << " ";
  out << set;
  out << "area=" << PI * radius * radius
  << " perimeter=" << PI * 2 * radius << endl;
}
void Cube::output(ostream& out) const
{
  out << "CUBE";
  out << reset;
  out << " side=" << side;
  out << set;
  out << " surface area=" << side * side *6
  << " volume=" << side * side * side << endl;
}
void Prism::output(ostream& out) const
{
  out << "PRISM";
  out << reset;
  out << " length=" << length << " width=" << width << " height=" << height;
  out << set;
  out << " surface area=" << ((length * width) + (width * height) + (length * height)) * 2
  << " volume= " << length * width * height << endl;
}
void Cylinder::output(ostream& out) const
{
  out << "CYLINDER";
  out << reset;
  out << " radius=" << radius << " height=" << height;
  out << set;
  out << " surface area=" << PI * (radius * radius) * 2 + PI * (radius * height) * 2
  << " volume=" << PI * (radius * radius) * height << endl;
}
// output to xls
void Square::xls(ostream& out) const
{
  out << "SQUARE" << "\t";
  out << reset;
  out << side << "\t\t\t\t\t";;
  out << set;
  out << side * side << "\t"
  << side * 4 << "\n";
}
void Rectangle::xls(ostream& out) const
{
  out << "RECTANGLE "  << "\t\t\t";
  out << reset;
  out << length << "\t" << width << "\t\t";
  out << set;
  out << length * width << "\t" << (length + width) * 2 << "\n";
}
void Circle::xls(ostream& out) const
{
  out << "CIRCLE" << "\t\t";
  out << reset;
  out << radius << "\t\t\t\t";
  out << set;
  out << PI * radius * radius << "\t"
  << PI * 2 * radius << "\n";
}
void Cube::xls(ostream& out) const
{
  out << "CUBE" << "\t";
  out << reset;
  out << side << "\t\t\t\t\t\t\t";
  out << set;
  out << side * side * 6 << "\t"
  << side * side * side << "\n";
}
void Prism::xls(ostream& out) const
{
  out << "PRISM" << "\t\t\t";
  out << reset;
  out << length << "\t" << width << "\t" << height << "\t\t\t";
  out << set;
  out << ((length * width) + (width * height) + (length * height)) * 2 << "\t"
  << length * width * height << "\n";
}
void Cylinder::xls(ostream& out) const
{
  out << "CYLINDER" << "\t\t";
  out << reset;
  out << radius << "\t\t\t" << height << "\t\t\t";
  out << set;
  out << PI * (radius * radius) * 2 + PI * (radius * height) * 2 << "\t"
  << PI * (radius * radius) * height << "\n";
}