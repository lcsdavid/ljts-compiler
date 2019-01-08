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
class         return (int)token::CLASS;
def           return (int)token::DEF;
else          return (int)token::ELSE;
extends       return (int)token::EXTENDS;
is            return (int)token::IS;
if            return (int)token::IF;
object        return (int)token::OBJECT;
override      return (int)token::OVERRIDE;
var           return (int)token::VAR;
return        return (int)token::RETURN;
then          return (int)token::THEN;
:=            return (int)token::ASSIGNMENT;
{integer}     { yylval = std::atoi(yytext); return (int)token::INTEGER; }
{identifier}  { yylval = std::string(yytext); return (int)token::IDENTIFIER; }
.
%%

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

std::ostream& operator<<(std::ostream& os, token const& t) {
	switch (t) {
		case token::ASSIGNMENT:
			os << "ASSIGNMENT";
			break;
		case token::CLASS:
			os << "CLASS";
			break;
		case token::DEF:
			os << "DEF";
			break;
		case token::ELSE:
		    os << "ELSE";
			break;
		case token::EXTENDS:
			os << "EXTENDS";
			break;
		case token::IDENTIFIER:
		    os << "IDENTIFIER: " << std::get<std::string>(yylval);
			break;
		case token::IF:
			os << "IF";
			break;
		case token::INTEGER:
		    os << "INTEGER: " << std::get<int>(yylval);
			break;
		case token::IS:
		    os << "IS";
			break;
	    case token::OBJECT:
		    os << "OBJECT";
			break;
		case token::OVERRIDE:
            os << "OVERRIDE";
			break;
		case token::RELATIONAL_OPERATOR:
			os << "RELATIONAL_OPERATOR: " << yytext;
			break;
		case token::RETURN:
			os << "RETURN";
			break;
		case token::THEN:
			os << "THEN";
			break;
		case token::VAR:
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
	std::cout << "Fichier " << argv[1] << " chargé: " << std::endl;
	close(0); dup(fi); close(fi);
	token t;
	while ((t = (token)yylex()) != token::END_OF_FILE)
		std::cout << t << std::endl;
	return 0;
}