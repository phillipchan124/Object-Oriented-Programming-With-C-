// Lab 2b, Encapsulating Data
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

// struct for shapes
struct Square {
  double side;
};
struct Rectangle {
  double length;
  double width;
};
struct Circle {
  double radius;
};
struct Cube {
  double side;
};
struct Prism {
  double length;
  double width;
  double height;
};
struct Cylinder {
  double radius;
  double height;
};

// output function in concole
void outputSquare(ostream&, Square*);
void outputRectangle(ostream&, Rectangle*);
void outputCircle(ostream&, Circle*);
void outputCube(ostream&, Cube*);
void outputPrism(ostream&, Prism*);
void outputCylinder(ostream&, Cylinder*);

// output function for excel spreadsheet
void xlsSquare(ostream&, Square*);
void xlsRectangle(ostream&, Rectangle*);
void xlsCircle(ostream&, Circle*);
void xlsCube(ostream&, Cube*);
void xlsPrism(ostream&, Prism*);
void xlsCylinder(ostream&, Cylinder*);

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 2b, Encapsulating Data \n";
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
        Square* s = new Square;
        s->side = nums[0];
        shape[shapeIndex] = s;
        shapeId[shapeIndex] = 1;
      }
      else if(strcmp(token[0], "RECTANGLE") == 0){
        Rectangle* r = new Rectangle;
        r->length = nums[0];
        r->width = nums[1];
        shape[shapeIndex] = r;
        shapeId[shapeIndex] = 2;
      }
      else if(strcmp(token[0],"CIRCLE") == 0){
        Circle* c = new Circle;
        c->radius = nums[0];
        shape[shapeIndex] = c;
        shapeId[shapeIndex] = 3;
      }
      else if(strcmp(token[0], "CUBE") == 0){
        Cube* c = new Cube;
        c->side = nums[0];
        shape[shapeIndex] = c;
        shapeId[shapeIndex] = 4;
      }
      else if(strcmp(token[0], "PRISM") == 0){
        Prism* p = new Prism;
        p->length = nums[0];
        p->width = nums[1];
        p->height = nums[2];
        shape[shapeIndex] = p;
        shapeId[shapeIndex] = 5;
      }
      else if(strcmp(token[0], "CYLINDER") == 0){
        Cylinder* c = new Cylinder;
        c->radius = nums[0];
        c->height = nums[1];
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
    if ( shapeId[i] == 1 ) outputSquare(cout, (Square*)shape[i]);
    else if ( shapeId[i] == 2 ) outputRectangle(cout, (Rectangle*)shape[i]);
    else if ( shapeId[i] == 3 ) outputCircle(cout, (Circle*)shape[i]);
    else if ( shapeId[i] == 4 ) outputCube(cout, (Cube*)shape[i]);
    else if ( shapeId[i] == 5 ) outputPrism(cout, (Prism*)shape[i]);
    else if ( shapeId[i] == 6 ) outputCylinder(cout, (Cylinder*)shape[i]);
  }
  
  // create a file-writing object with column names
  ofstream fout;
  fout.open("geo.xls"); // create a file to output result
  fout << "Shape \tside \tradius \tlength \twidth \theight \t"
  << "area \tperimeter \tsurface area \tvolumne \n";
  
  // outout in excel spreadsheet
  for (int i = 0; i < shapeIndex; i++ )
  {
    if ( shapeId[i] == 1)  xlsSquare(fout, (Square*)shape[i]);
    else if ( shapeId[i] == 2 ) xlsRectangle(fout, (Rectangle*)shape[i]);
    else if ( shapeId[i] == 3 ) xlsCircle(fout, (Circle*)shape[i]);
    else if ( shapeId[i] == 4 ) xlsCube(fout, (Cube*)shape[i]);
    else if ( shapeId[i] == 5 ) xlsPrism(fout, (Prism*)shape[i]);
    else if ( shapeId[i] == 6 ) xlsCylinder(fout, (Cylinder*)shape[i]);
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
// output function in concole
void outputSquare(ostream& out, Square* s)
{
  double side = s->side;
  out << "SQUARE";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << " side="<< side;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " area=" << side * side
  << " perimeter=" << side * 4 << endl;
}
void outputRectangle(ostream& out, Rectangle* r)
{
  double length = r->length, width = r->width;
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
void outputCircle(ostream& out, Circle* c)
{
  double radius = c->radius;
  out << "CIRCLE";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << " radius=" << radius << " ";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << "area=" << PI * radius * radius
  << " perimeter=" << PI * 2 * radius << endl;
}
void outputCube(ostream& out, Cube* c)
{
  double side = c->side;
  out << "CUBE";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << " side=" << side;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " surface area=" << side * side *6
  << " volume=" << side * side * side << endl;
}
void outputPrism(ostream& out, Prism* p)
{
  double length = p->length;
  double width = p->width;
  double height = p->height;
  out << "PRISM";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << " length=" << length << " width=" << width << " height=" << height;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " surface area=" << ((length * width) + (width * height) + (length * height)) * 2
  << " volume= " << length * width * height << endl;
}
void outputCylinder(ostream& out, Cylinder* c)
{
  double radius = c->radius, height = c->height;
  out << "CYLINDER";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << " radius=" << radius << " height=" << height;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " surface area=" << PI * (radius * radius) * 2 + PI * (radius * height) * 2
  << " volume=" << PI * (radius * radius) * height << endl;
}

// output function for excel spreadsheet
void xlsSquare(ostream& out, Square* s)
{
  double side = s->side;
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
void xlsRectangle(ostream& out, Rectangle* r)
{
  double length = r->length, width = r->width;
  out << "RECTANGLE "  << "\t\t\t";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << length << "\t" << width << "\t\t";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << length * width << "\t" << (length + width) * 2 << "\n";
}
void xlsCircle(ostream& out, Circle* c)
{
  double radius = c->radius;
  out << "CIRCLE" << "\t\t";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << radius << "\t\t\t\t";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << PI * radius * radius << "\t"
  << PI * 2 * radius << "\n";
}
void xlsCube(ostream& out, Cube* c)
{
  double side = c->side;
  out << "CUBE" << "\t";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << side << "\t\t\t\t\t\t\t";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << side * side * 6 << "\t"
  << side * side * side << "\n";
}
void xlsPrism(ostream& out, Prism* p)
{
  double length = p->length;
  double width = p->width;
  double height = p->height;
  out << "PRISM" << "\t\t\t";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << length << "\t" << width << "\t" << height << "\t\t\t";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << ((length * width) + (width * height) + (length * height)) * 2 << "\t"
  << length * width * height << "\n";
}
void xlsCylinder(ostream& out, Cylinder* c)
{
  double radius = c->radius, height = c->height;
  out << "CYLINDER" << "\t\t";
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << radius << "\t\t\t" << height << "\t\t\t";
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << PI * (radius * radius) * 2 + PI * (radius * height) * 2 << "\t"
  << PI * (radius * radius) * height << "\n";
}