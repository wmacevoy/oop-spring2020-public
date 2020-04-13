#include "translator.h"

#include <iostream>
#include <fstream>

using namespace std;

Translator::~Translator() 
{
}

class JasminTranslator : public Translator
{
  std::string name;
  std::ostream *out;
  ASTNodeSP program;

  void header()
  {
    (*out) << ".class public " << name << endl;
    (*out) << ".super java/lang/Object" << endl;
    (*out) << "" << endl;
    (*out) << "; default constructor" << endl;
    (*out) << ".method public <init>()V" << endl;
    (*out) << "   aload_0 ; push this" << endl;
    (*out) << "   invokespecial java/lang/Object/<init>()V ; call super" << endl;
    (*out) << "   return" << endl;
    (*out) << ".end method" << endl;
    (*out) << "" << endl;
    (*out) << ".method public static main([Ljava/lang/String;)V" << endl;
    (*out) << "begin:" << endl;
  }

  void footer()
  {
    (*out) << "   ; terminate main" << endl;
    (*out) << "   return" << endl;
    (*out) << "end:" << endl;
    (*out) << ".end method" << endl;
  }

  void symbols()
  {
    (*out) << "   .limit stack 100" << endl;
    (*out) << "   .limit locals 100" << endl;
    (*out) << "   .var 0 is ans F from begin to end" << endl;
    for (int i='a'; i<='z'; ++i) {
      (*out) << "   .var " << (i-'a'+1) << " is " << char(i) << " F from begin to end" << endl;
    }
  }

  void body()
  {
    for (int i='a'; i<='z'; ++i) {
      (*out) << "   ldc 1.0" << endl;
      (*out) << "   ldc " << i << ".0" << endl;
      (*out) << "   fdiv" << endl;
      (*out) << "   fstore " << (i-'a'+1) << endl;
    }
    program->translate(*out);
  }
  
  void generate()
  {
    header();
    symbols();
    body();
    footer();
  }

  void translate(const std::string &file, ASTNodeSP program_)
  {
    name = file.substr(0,file.length()-2);
    out = new ofstream(file.c_str());
    program=program_;
    generate();
    delete out;
  }

};

TranslatorSP CreateJasminTranslator()
{
  return TranslatorSP(new JasminTranslator());
}
