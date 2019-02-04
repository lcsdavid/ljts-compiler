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
(<=)			{ yylval.Integer = less_equal; return RELATIONAL_OPERATOR; }
>				{ yylval.Integer = greater_strict; return RELATIONAL_OPERATOR; }
(>=)			{ yylval.Integer = greater_equal; return RELATIONAL_OPERATOR; }
=				{ yylval.Integer = equal; return RELATIONAL_OPERATOR; }
(<>)			{ yylval.Integer = not_equal; return RELATIONAL_OPERATOR; }
{integer}		{ yylval.Integer = std::atoi(yytext); return INTEGER; }
{string}		{ yylval.String = new std::string(yytext); return STRING; }
{identifier}	{ yylval.String = new std::string(yytext); return IDENTIFIER; }
{typename}		{ yylval.String = new std::string(yytext); return TYPENAME; }
.				return yytext[0];
%%
