// Lab 12, UI-independent Classes
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#include <iostream>
using std::ios;
using std::ostream;

#include <iomanip>
using std::setprecision;

#include "GeometryHomework.h"

const double PI = 3.14159;

ostream& operator<<(ostream& out, const Shape* s)
{
  s->output(out);
  return out;
}

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
// output in console
void Square::output(ostream& out) const
{
  out << "SQUARE";
  out << reset;
  out << " side="<< dim1;
  out << set;
  out << " area=" << dim1 * dim1
  << " perimeter=" << dim1 * 4 << "\n";
}
void Rectangle::output(ostream& out) const
{
  out << "RECTANGLE";
  out << reset;
  out << " length="<< dim1 << " ";
  out << "width="<< dim2 << " ";
  out << set;
  out << "area=" << dim1 * dim2
  << " perimeter=" << (dim1 + dim2) * 2 << "\n";
}
void Circle::output(ostream& out) const
{
  out << "CIRCLE";
  out << reset;
  out << " radius=" << dim1 << " ";
  out << set;
  out << "area=" << PI * dim1 * dim1
  << " perimeter=" << PI * 2 * dim1 << "\n";
}
void Cube::output(ostream& out) const
{
  out << "CUBE";
  out << reset;
  out << " side=" << dim1;
  out << set;
  out << " surface area=" << dim1 * dim1 *6
  << " volume=" << dim1 * dim1 * dim1 << "\n";
}
void Prism::output(ostream& out) const
{
  out << "PRISM";
  out << reset;
  out << " length=" << dim1 << " width=" << dim2 << " height=" << dim3;
  out << set;
  out << " surface area=" << ((dim1 * dim2) + (dim1 * dim3) + (dim2 * dim3)) * 2
  << " volume= " << dim1 * dim2 * dim3 << "\n";
}
void Cylinder::output(ostream& out) const
{
  out << "CYLINDER";
  out << reset;
  out << " radius=" << dim1 << " height=" << dim2;
  out << set;
  out << " surface area=" << PI * (dim1 * dim1) * 2 + PI * (dim1 * dim2) * 2
  << " volume=" << PI * (dim1 * dim1) * dim2 << "\n";
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