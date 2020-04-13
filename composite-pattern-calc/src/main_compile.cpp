#include "calc.h"
#include "parser.h"
#include "stringsequence.h"
#include "istreamsequence.h"
#include "tokens.h"
#include "translator.h"
#include <fstream>

void compile(const std::string &file)
{
  std::ifstream ifs(file.c_str());
  SequenceSP sequence(new IStreamSequence(ifs));
  TokensSP tokens(new Tokens(sequence));
  ParserSP parser = ParserSP(CreateRecursiveDescentParser());
  ASTNodeSP program = parser->parse(tokens);
  TranslatorSP translator = CreateJasminTranslator();
  std::string jfile = file.substr(0,file.length()-5);
  jfile += ".j";
  translator->translate(jfile,program);
}


int main(int argc, char *argv[])
{
  for (int argi=1; argi < argc; ++argi) {
    compile(argv[argi]);
  }
}
