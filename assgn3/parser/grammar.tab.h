/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    BOOL = 259,
    INT = 260,
    FLOAT = 261,
    DOUBLE = 262,
    CHAR = 263,
    DO = 264,
    WHILE = 265,
    IF = 266,
    ELIF = 267,
    FALSE = 268,
    TRUE = 269,
    IN = 270,
    OUT = 271,
    MAIN = 272,
    VOID = 273,
    FOR = 274,
    INTCONST = 275,
    CHAR_CONSTANT = 276,
    RETURN = 277,
    STRUCT = 278,
    SWITCH = 279,
    WHITESPACE = 280,
    CASE = 281,
    ELSE = 282,
    DEFAULT = 283,
    CONSTANT = 284,
    STRING = 285,
    INP_OP = 286,
    OUT_OP = 287,
    OR_OP = 288,
    INC_OP = 289,
    DEC_OP = 290,
    AND_OP = 291,
    LESS_EQ_OP = 292,
    GRE_EQ_OP = 293,
    DOUBLE_EQ_OP = 294,
    NOT_EQ_OP = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 9 "grammar.y" /* yacc.c:1909  */

  int		int_val;
  double 	decimal_val;
  char      char_val;
  char*     id_val;
  struct node*     ptr;

#line 103 "grammar.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
