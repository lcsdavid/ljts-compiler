digit		[0-9]
upperletter	[A-Z]
lowerletter	[a-z]
letter		({lowerletter}|{upperletter})
newline		(\r\n?)|\n
commentary	\/{2}[^{newline}]*{newline}|\/\*([^\*]*|\*[^\/])*\*\/

identifier	{lowerletter}({letter}|{digit})*
typename	{upperletter}({letter}|{digit})*

char		\'[^\']+\'
integer		{digit}+
float		{double}f
double		{integer}\.{digit}*
string		\"[^\"]*\"

%{

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ljts-compiler.hpp"

%}

%%
{commentary}	{ std::string ctary = yytext; }
{newline}
[ \t]
class			return CLASS;
def				return DEF;
else			return ELSE;
extends			return EXTENDS;
is				return IS;
if				return IF;
new				return NEW;
object			return OBJECT;
override		return OVERRIDE;
var				return VAR;
return			return RETURN;
then			return THEN;
this			return THIS;
:=				return ASSIGNMENT;
(<)				{ yylval.Integer = less_strict; return RELATIONAL_OPERATOR; }
=<|<=			{ yylval.Integer = less_equal; return RELATIONAL_OPERATOR; }
>				{ yylval.Integer = greater_strict; return RELATIONAL_OPERATOR; }
=>|>=			{ yylval.Integer = greater_equal; return RELATIONAL_OPERATOR; }
=				{ yylval.Integer = equal; return RELATIONAL_OPERATOR; }
(<>)			{ yylval.Integer = not_equal; return RELATIONAL_OPERATOR; }
{integer}		{ yylval.Integer = std::atoi(yytext); return INTEGER; }
{string}		{ yylval.String = yytext; return STRING; }
{identifier}	{ yylval.String = yytext; return IDENTIFIER; }
{typename}		{ yylval.String = yytext; return TYPENAME; }
.				return yytext[0];
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
			os << "TYPENAME: " << yylval.Integer;
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
			os << "IDENTIFIER: " << yylval.Integer;
			break;
		case IF:
			os << "IF";
			break;
		case INTEGER:
			os << "INTEGER: " << yylval.Integer;
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