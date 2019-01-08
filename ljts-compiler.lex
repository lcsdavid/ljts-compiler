digit        [0-9]
letter       [A-Za-z0-9_]
newline      (\r\n?)|\n
commentary   \/{2}[^{newline}]*{newline}|\/\*([^\*]*|\*[^\/])*\*\/

identifier   {letter}({letter}|{digit})*

char         '[^']+'
integer      {digit}+
float        {double}f
double       {integer}\.{digit}*
string       "[^"]*"

%{
	
#include <cstdlib>
#include <iostream>
#include <string>

#include "ljts-compiler.hpp"

extern "C" {
	int yylex(void);
	YYSTYPE yylval;
};

%}

%%
{commentary}
{newline}     yylineno++;
class         return CLASS;
def           return DEF;
else          return ELSE;
extends       return EXTENDS;
is            return IS;
if            return IF;
object        return OBJECT;
override      return OVERRIDE;
var           return VAR;
return        return RETURN;
then          return THEN;
:=            return ASSIGNMENT;
{integer}     { yylval = std::atoi(yytext); return INTEGER; }
{identifier}  { yylval = std::string(yytext); return IDENTIFIER; }
.
%%

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

std::ostream& operator<<(std::ostream& os, token const& t) {
	switch (t) {
		case ASSIGNMENT:
			os << "ASSIGNMENT";
			break;
		case CLASS:
			os << "CLASS";
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
			os << yytext;
	}
	return os << ", lineno " << yylineno;
}

int main(int argc, char **argv) {
	int fi;
	if ((fi = open(argv[1], O_RDONLY)) == -1) {
		std::cerr << "Erreur: fichier inaccessible " << argv[1] << std::endl;
		exit(1);
	}
	std::cout << "Fichier " << argv[1] << "chargé:" << std::endl;
	close(0); dup(fi); close(fi);
	token t;
	while ((t = (token)yylex()) != 0)
		std::cout << t << std::endl;
	return 0;
}