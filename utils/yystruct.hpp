#ifndef COMPILER_YYSTRUCT_HPP
#define COMPILER_YYSTRUCT_HPP

extern int yylineno;
extern int yycharno;
extern char *yytext;

struct yystruct {
	int yylineno, yycharno;
	char *yytext;
	
	yystruct() : lineno(yylineno), charno(yycharno), yyline(yytext) {}
}

#endif