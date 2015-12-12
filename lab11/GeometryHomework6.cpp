// Lab 11, Using Polymorphism
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
class Shape
{
protected:
  const double dim1;
  const double dim2;
  const double dim3;
public:
  Shape ( const char* const token[] )
  : dim1( 0==token[1] ? 0.0 : atof(token[1]) ), dim2( 0==token[2] ? 0.0 : atof(token[2]) ),
  dim3( 0==token[3] ? 0.0 : atof(token[3]) ) {}
  virtual void output(ostream&) const = 0;
  virtual void xls(ostream&) const = 0;
  virtual ~Shape(){}
};
// Square
struct Square : public Shape
{
  Square( const char* const token[] ) : Shape ( token ) {}
  void output(ostream&) const;
  void xls(ostream&) const;
};
struct Cube : public Square
{
  Cube( const char* const token[] ) : Square ( token ) {}
  void output(ostream&) const;
  void xls(ostream&) const;
};
// Rectangle
struct Rectangle : public Shape
{
  Rectangle( const char* const token[] ) : Shape ( token ) {}
  void output(ostream&) const;
  void xls(ostream&) const;
};
struct Prism : public Rectangle
{
  Prism( const char* const token[] ) : Rectangle ( token ) {}
  void output(ostream&) const;
  void xls(ostream&) const;
};
// Circle
struct Circle : public Shape
{
  Circle( const char* const token[] ) : Shape ( token ) {}
  void output(ostream&) const;
  void xls(ostream&) const;
};
struct Cylinder : public Circle
{
  Cylinder( const char* const token[] ) : Circle ( token ) {}
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
  cout << "Lab 11, Using Polymorphism \n";
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
  for (int i = 0; i < shapes.size(); i++ ) shapes.at(i) -> output(cout);
  
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
// output in console
void Square::output(ostream& out) const
{
  out << "SQUARE";
  out << reset;
  out << " side="<< dim1;
  out << set;
  out << " area=" << dim1 * dim1
  << " perimeter=" << dim1 * 4 << endl;
}
void Rectangle::output(ostream& out) const
{
  out << "RECTANGLE";
  out << reset;
  out << " length="<< dim1 << " ";
  out << "width="<< dim2 << " ";
  out << set;
  out << "area=" << dim1 * dim2
  << " perimeter=" << (dim1 + dim2) * 2 << endl;
}
void Circle::output(ostream& out) const
{
  out << "CIRCLE";
  out << reset;
  out << " radius=" << dim1 << " ";
  out << set;
  out << "area=" << PI * dim1 * dim1
  << " perimeter=" << PI * 2 * dim1 << endl;
}
void Cube::output(ostream& out) const
{
  out << "CUBE";
  out << reset;
  out << " side=" << dim1;
  out << set;
  out << " surface area=" << dim1 * dim1 *6
  << " volume=" << dim1 * dim1 * dim1 << endl;
}
void Prism::output(ostream& out) const
{
  out << "PRISM";
  out << reset;
  out << " length=" << dim1 << " width=" << dim2 << " height=" << dim3;
  out << set;
  out << " surface area=" << ((dim1 * dim2) + (dim1 * dim3) + (dim2 * dim3)) * 2
  << " volume= " << dim1 * dim2 * dim3 << endl;
}
void Cylinder::output(ostream& out) const
{
  out << "CYLINDER";
  out << reset;
  out << " radius=" << dim1 << " height=" << dim2;
  out << set;
  out << " surface area=" << PI * (dim1 * dim1) * 2 + PI * (dim1 * dim2) * 2
  << " volume=" << PI * (dim1 * dim1) * dim2 << endl;
}
// output to xls
void Square::xls(ostream& out) const
{
  out << "SQUARE" << "\t";
  out << reset;
  out << dim1 << "\t\t\t\t\t";;
  out << set;
  out << dim1 * dim1 << "\t"
  << dim1 * 4 << "\n";
}
void Rectangle::xls(ostream& out) const
{
  out << "RECTANGLE "  << "\t\t\t";
  out << reset;
  out << dim1 << "\t" << dim2 << "\t\t";
  out << set;
  out << dim1 * dim2 << "\t" << (dim1 + dim2) * 2 << "\n";
}
void Circle::xls(ostream& out) const
{
  out << "CIRCLE" << "\t\t";
  out << reset;
  out << dim1 << "\t\t\t\t";
  out << set;
  out << PI * dim1 * dim1 << "\t"
  << PI * 2 * dim1 << "\n";
}
void Cube::xls(ostream& out) const
{
  out << "CUBE" << "\t";
  out << reset;
  out << dim1 << "\t\t\t\t\t\t\t";
  out << set;
  out << dim1 * dim1 * 6 << "\t"
  << dim1 * dim1 * dim1 << "\n";
}
void Prism::xls(ostream& out) const
{
  out << "PRISM" << "\t\t\t";
  out << reset;
  out << dim1 << "\t" << dim2 << "\t" << dim3 << "\t\t\t";
  out << set;
  out << ((dim1 * dim2) + (dim1 * dim3) + (dim2 * dim3)) * 2 << "\t"
  << dim1 * dim2 * dim3 << "\n";
}
void Cylinder::xls(ostream& out) const
{
  out << "CYLINDER" << "\t\t";
  out << reset;
  out << dim1 << "\t\t\t" << dim2 << "\t\t\t";
  out << set;
  out << PI * (dim1 * dim1) * 2 + PI * (dim1 * dim2) * 2 << "\t"
  << PI * (dim1 * dim1) * dim2 << "\n";
}