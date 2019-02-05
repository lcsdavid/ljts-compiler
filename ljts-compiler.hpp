#ifndef LTJS_COMPILER_HPP
#define LTJS_COMPILER_HPP

#include "YYSTYPE.hpp"
#include "yytokentype.hpp"
#include "optype.hpp"

extern "C" int yylex();
extern "C" YYSTYPE yylval;
extern int yylineno;
void yyerror(char const *s);
extern bool do_print;

#endif