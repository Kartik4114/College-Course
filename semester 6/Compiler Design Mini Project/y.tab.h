
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING = 259,
     NUMBER = 260,
     LET = 261,
     ASSIGN = 262,
     FILTER = 263,
     PROJECT = 264,
     MAP = 265,
     GROUP = 266,
     JOIN = 267,
     AS = 268,
     UNION = 269,
     UNIONALL = 270,
     INTERSECT = 271,
     EXCEPT = 272,
     DISTINCT = 273,
     ON = 274,
     BY = 275,
     TYPE = 276,
     AGGS = 277,
     SETS = 278,
     DEFUN = 279,
     ARROW = 280,
     COMMA = 281,
     LPAREN = 282,
     RPAREN = 283,
     LBRACE = 284,
     RBRACE = 285,
     EQ = 286,
     NEQ = 287,
     GE = 288,
     LE = 289,
     GT = 290,
     LT = 291,
     PLUS = 292,
     MINUS = 293,
     MUL = 294,
     DIV = 295,
     AND = 296,
     OR = 297,
     DOT = 298,
     INNER = 299
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define LET 261
#define ASSIGN 262
#define FILTER 263
#define PROJECT 264
#define MAP 265
#define GROUP 266
#define JOIN 267
#define AS 268
#define UNION 269
#define UNIONALL 270
#define INTERSECT 271
#define EXCEPT 272
#define DISTINCT 273
#define ON 274
#define BY 275
#define TYPE 276
#define AGGS 277
#define SETS 278
#define DEFUN 279
#define ARROW 280
#define COMMA 281
#define LPAREN 282
#define RPAREN 283
#define LBRACE 284
#define RBRACE 285
#define EQ 286
#define NEQ 287
#define GE 288
#define LE 289
#define GT 290
#define LT 291
#define PLUS 292
#define MINUS 293
#define MUL 294
#define DIV 295
#define AND 296
#define OR 297
#define DOT 298
#define INNER 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 10 "saneql.y"

    int num;
    char* str;



/* Line 1676 of yacc.c  */
#line 147 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


