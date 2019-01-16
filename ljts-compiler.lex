digit        [0-9]
upperletter  [A-Z]
lowerletter  [a-z]
letter       ({lowerletter}|{upperletter})
newline      (\r\n?)|\n
commentary   \/{2}[^{newline}]*{newline}|\/\*([^\*]*|\*[^\/])*\*\/

identifier   {lowerletter}({letter}|{digit})*
typename     {upperletter}({letter}|{digit})*

char         \'[^\']+\'
integer      {digit}+
float        {double}f
double       {integer}\.{digit}*
string       \"[^\"]*\"

%{

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ljts-compiler.hpp"

%}

%%
{commentary}  { std::string ctary = yytext; yylineno += std::count(ctary.begin(), ctary.end(), '\n'); }
{newline}     yylineno++;
[ \t]
class         return CLASS;
def           return DEF;
else          return ELSE;
extends       return EXTENDS;
is            return IS;
if            return IF;
new           return NEW;
object        return OBJECT;
override      return OVERRIDE;
var           return VAR;
return        return RETURN;
then          return THEN;
:=            return ASSIGNMENT;
(<)           { yylval = Operation::less_strict; return RELATIONAL_OPERATOR; }
=<|<=         { yylval = Operation::less_equal; return RELATIONAL_OPERATOR; }
>             { yylval = Operation::greater_strict; return RELATIONAL_OPERATOR; }
=>|>=         { yylval = Operation::greater_equal; return RELATIONAL_OPERATOR; }
=             { yylval = Operation::equal; return RELATIONAL_OPERATOR; }
(<>)          { yylval = Operation::not_equal; return RELATIONAL_OPERATOR; }
{integer}     { yylval = std::atoi(yytext); return INTEGER; }
{string}      { yylval = std::string(yytext); return STRING; }
{identifier}  { yylval = std::string(yytext); return IDENTIFIER; }
{typename}    { yylval = std::string(yytext); return TYPENAME; }
.             { /* std::cerr << "Error: lexical error, unexpected '" << yytext << "' at line " << yylineno << std::endl; */ return yytext[0]; }
%%

std::ostream& operator<<(std::ostream& os, yytokentype t) {
	switch (t) {
		case ASSIGNMENT:
			os << "ASSIGNMENT";
			break;
		case CLASS:
			os << "CLASS";
			break;
		case TYPENAME:
			os << "TYPENAME: " << std::get<std::string>(yylval);
			break;
		case DEF:
			os << "DEF";
			break;
		case ELSE:
		    os << "ELSE";
			break;
		case EXTENDS:
			os << "EXTENDS";
			break;
		case IDENTIFIER:
		    os << "IDENTIFIER: " << std::get<std::string>(yylval);
			break;
		case IF:
			os << "IF";
			break;
		case INTEGER:
		    os << "INTEGER: " << std::get<int>(yylval);
			break;
		case IS:
		    os << "IS";
			break;
	    case OBJECT:
		    os << "OBJECT";
			break;
		case OVERRIDE:
            os << "OVERRIDE";
			break;
		case RELATIONAL_OPERATOR:
			os << "RELATIONAL_OPERATOR: " << yytext;
			break;
		case RETURN:
			os << "RETURN";
			break;
		case THEN:
			os << "THEN";
			break;
		case VAR:
			os << "VAR";
			break;
		default:
			if (yytext[0] == ' ')
				return os;
			os << "'" << yytext << "'";
	}
	return os << ", lineno " << yylineno << std::endl;
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#ifdef LEX_MAIN

int main(int argc, char **argv) {
	int fi;
	if ((fi = open(argv[1], O_RDONLY)) == -1) {
		std::cerr << "Erreur: fichier inaccessible " << argv[1] << std::endl;
		exit(1);
	}
	std::cout << "Fichier " << argv[1] << " chargé: " << std::endl;
	close(0); dup(fi); close(fi);
	Token t;
	while ((t = yylex()) != 0)
		std::cout << (Token)t;
	return 0;
}

#endif