%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);
%}

%union {
    int num;
    char* str;
}

%token <str> IDENTIFIER STRING
%token <num> NUMBER

%token LET ASSIGN
%token FILTER PROJECT MAP GROUP JOIN AS
%token UNION UNIONALL INTERSECT EXCEPT DISTINCT
%token ON BY TYPE AGGS SETS
%token DEFUN ARROW
%token COMMA LPAREN RPAREN LBRACE RBRACE
%token EQ NEQ GE LE GT LT
%token PLUS MINUS MUL DIV
%token AND OR
%token DOT
%token INNER

%start query
%%

query:
      function_definition
    | let_statement
    | expression_chain
;

let_statement:
    LET IDENTIFIER ASSIGN expression_chain
    {
        printf("Valid let assignment: %s\n", $2);
    }
;

function_definition:
    DEFUN IDENTIFIER LPAREN param_list_opt RPAREN return_type_opt LBRACE function_body RBRACE
    {
        printf("Valid function definition: %s\n", $2);
    }
;

param_list_opt:
      /* empty */
    | param_list
;

param_list:
      IDENTIFIER
    | param_list COMMA IDENTIFIER
;

return_type_opt:
      /* empty */
    | ARROW IDENTIFIER
;

function_body:
    expression_chain
;

expression_chain:
      IDENTIFIER chain { printf("Valid SaneQL query.\n"); }
;

chain:
      chain operation
    | operation
;

operation:
      DOT FILTER LPAREN condition RPAREN
    | DOT PROJECT LPAREN expr_list RPAREN
    | DOT MAP LPAREN expression RPAREN
    | DOT GROUP LPAREN group_params RPAREN
    | DOT JOIN LPAREN join_type COMMA expression COMMA join_condition RPAREN
    | DOT AS LPAREN rename_list RPAREN
    | DOT UNION LPAREN expression COMMA expression RPAREN
    | DOT UNIONALL LPAREN expression COMMA expression RPAREN
    | DOT INTERSECT LPAREN expression COMMA expression RPAREN
    | DOT EXCEPT LPAREN expression COMMA expression RPAREN
    | DOT DISTINCT LPAREN RPAREN
;

join_type:
      INNER
;

join_condition:
      expression EQ expression
;

group_params:
    expr_list COMMA AGGS COMMA TYPE COMMA SETS
;

condition:
      expression comp_op expression
    | condition AND condition
    | condition OR condition
;

expr_list:
      expression
    | expr_list COMMA expression
;

rename_list:
      IDENTIFIER STRING
    | rename_list COMMA IDENTIFIER STRING
;

expression:
      IDENTIFIER
    | IDENTIFIER DOT IDENTIFIER       // ✅ Allow table.column access
    | NUMBER
    | STRING
    | expression PLUS expression
    | expression MINUS expression
    | expression MUL expression
    | expression DIV expression
    | LPAREN expression RPAREN
    | function_call                   // ✅ Allow nested function calls in expressions
;

function_call:
    IDENTIFIER LPAREN argument_list_opt RPAREN
;

argument_list_opt:
      /* empty */
    | argument_list
;

argument_list:
      expression
    | argument_list COMMA expression
;

comp_op:
    EQ | NEQ | GE | LE | GT | LT
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}

int main() {
    printf("Enter a SaneQL query:\n");
    return yyparse();
}
