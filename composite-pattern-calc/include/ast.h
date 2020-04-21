#pragma once

#include <memory>
#include <list>

#include "token.h"

class ASTNode
{
 public:
  virtual void print(std::ostream &out) const=0;
  virtual void translate(std::ostream &out)=0;
  virtual double eval() const=0;
  virtual ~ASTNode();
};

std::ostream& operator<< (std::ostream&out, const ASTNode &node);

typedef std::shared_ptr < ASTNode > ASTNodeSP;

class ASTSymbol : public ASTNode
{
 public:
  std::string name;
  ASTSymbol(const std::string &name_);
  virtual double eval() const;
  virtual void print(std::ostream &out) const;
  virtual void translate(std::ostream &out);
};

class ASTNumber : public ASTNode
{
 public:
  double value;
  ASTNumber(double value_);
  virtual double eval() const;
  virtual void print(std::ostream &out) const;
  virtual void translate(std::ostream &out);
};

class ASTSum : public ASTNode
{
 public:
  ASTNodeSP lhs;
  ASTNodeSP rhs;
  virtual double eval() const;
  virtual void print(std::ostream &out) const;
  virtual void translate(std::ostream &out);
  ASTSum(const ASTNodeSP &lhs_, const ASTNodeSP &rhs_);
};

class ASTProduct : public ASTNode
{
 public:
  ASTNodeSP lhs;
  ASTNodeSP rhs;
  virtual double eval() const;
  virtual void print(std::ostream &out) const;
  virtual void translate(std::ostream &out);
  ASTProduct(const ASTNodeSP &lhs_, const ASTNodeSP &rhs_);
};

class ASTStatements : public ASTNode
{
 public:
  typedef std::list < ASTNodeSP > Statements;
  Statements statements;
  virtual double eval() const;
  virtual void print(std::ostream &out) const;
  virtual void translate(std::ostream &out);
  ASTStatements();
};
