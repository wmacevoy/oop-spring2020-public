#include "ast.h"

#include <iostream>
#include <iomanip>

using namespace std;

ASTNode::~ASTNode() {}

std::ostream& operator<< (std::ostream&out, const ASTNode &node)
{
  node.print(out);
  return out;
}

ASTSymbol::ASTSymbol(const std::string &name_)
  : name(name_)
{
}

double ASTSymbol::eval() const
{
  // WARNING --- BAD IDEA
  return 1.0/double(name[0]);
}


void ASTSymbol::print(std::ostream &out) const
{
  out << name;
}

void ASTSymbol::translate(std::ostream &out)
{
  out << "fload " << name[0]-'a'+1 << endl;
}

ASTNumber::ASTNumber(double value_) 
  : value(value_) 
{ 
}

double ASTNumber::eval() const 
{ 
  return value; 
}

void ASTNumber::translate(std::ostream &out)
{
  out << "ldc " << fixed << setprecision(15) << value << endl;
}

void ASTNumber::print(std::ostream &out) const 
{ 
  out << value;
}

double ASTSum::eval() const 
{ 
  return (lhs->eval() + rhs->eval()); 
}

ASTSum::ASTSum(const ASTNodeSP &lhs_, const ASTNodeSP &rhs_)
  : lhs(lhs_), rhs(rhs_)
{
}


void ASTSum::print(std::ostream &out) const
{
  out << "(" << *lhs << "+" << *rhs << ")";
}

void ASTSum::translate(std::ostream &out)
{
  lhs->translate(out);
  rhs->translate(out);
  out << "fadd" << endl;
}


ASTProduct::ASTProduct(const ASTNodeSP &lhs_, const ASTNodeSP &rhs_)
  : lhs(lhs_), rhs(rhs_)
{
}

double ASTProduct::eval() const 
{ 
  return (lhs->eval() * rhs->eval()); 
}

void ASTProduct::print(std::ostream &out) const
{
  out << "(" << *lhs << "*" << *rhs << ")";
}

void ASTProduct::translate(std::ostream &out)
{
  lhs->translate(out);
  rhs->translate(out);
  out << "fmul" << endl;
}


ASTStatements::ASTStatements()
{
}

double ASTStatements::eval() const
{
  double value = 0.0;
  for (Statements::const_iterator i = statements.begin();
       i != statements.end();
       ++i) {
    value=(*i)->eval();
  }
  return value;
}

void ASTStatements::print(std::ostream &out) const
{
  for (Statements::const_iterator i = statements.begin();
       i != statements.end();
       ++i) {
    (*i)->print(out); out << std::endl;
  }
}

void ASTStatements::translate(std::ostream &out)
{
  for (Statements::const_iterator i = statements.begin();
       i != statements.end();
       ++i) {

    out << "   ; push java.lang.System.out (type PrintStream)" << endl;
    out << "   getstatic java/lang/System/out Ljava/io/PrintStream;" << endl;
    out << "   " << endl;
    (*i)->translate(out);
    out << "   " << endl;
    out << "   ; invoke println" << endl;
    out << "   invokevirtual java/io/PrintStream/println(F)V" << endl;
    out << "   " << endl;
  }
}



