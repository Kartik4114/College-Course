%{
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%option noyywrap

%%

"let"           { return LET; }
"filter"        { return FILTER; }
"project"       { return PROJECT; }
"map"           { return MAP; }
"group"         { return GROUP; }
"join"          { return JOIN; }
"as"            { return AS; }
"union"         { return UNION; }
"unionall"      { return UNIONALL; }
"intersect"     { return INTERSECT; }
"except"        { return EXCEPT; }
"distinct"      { return DISTINCT; }
"on"            { return ON; }
"by"            { return BY; }
"type"          { return TYPE; }
"aggs"          { return AGGS; }
"sets"          { return SETS; }
"inner"         { return INNER; }

"=="            { return EQ; }
"!="            { return NEQ; }
">="            { return GE; }
"<="            { return LE; }
">"             { return GT; }
"<"             { return LT; }
"="             { return ASSIGN; }

"DEFUN"         { return DEFUN; }
"->"            { return ARROW; }

"&&"            { return AND; }
"||"            { return OR; }

[0-9]+          { yylval.num = atoi(yytext); return NUMBER; }
\"[^\"]*\"      { yylval.str = strdup(yytext); return STRING; }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }

","             { return COMMA; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"."             { return DOT; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }

[ \t\r\n]+      ; // skip whitespace

.               { return yytext[0]; }

%%
