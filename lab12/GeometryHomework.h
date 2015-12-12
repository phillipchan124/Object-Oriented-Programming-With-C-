// Lab 12, UI-independent Classes
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#ifndef GeometryHomework_H
#define GeometryHomework_H

#include <iostream>
using std::ostream;

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

ostream& operator<<(ostream&, const Shape*);

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
ostream& reset(ostream&);
ostream& set(ostream&);

#endif