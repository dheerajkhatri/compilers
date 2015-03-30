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

#ifndef YY_YY_CALC_TAB_H_INCLUDED
# define YY_YY_CALC_TAB_H_INCLUDED
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
    IF = 258,
    STRUCT = 259,
    VOID = 260,
    LONG = 261,
    SHORT = 262,
    CONTINUE = 263,
    BREAK = 264,
    WHILE = 265,
    ELSE = 266,
    SIZEOF = 267,
    RETURN = 268,
    DOUBLE = 269,
    FLOAT = 270,
    INT = 271,
    FOR = 272,
    CHAR = 273,
    BOOL = 274,
    IDENTIFIERS = 275,
    INTEGER_CONSTANT = 276,
    FLOAT_CONSTANT = 277,
    CHARACTER_CONSTANT = 278,
    STRING_CONSTANT = 279,
    RIGHT_SHIFT_OP = 280,
    LEFT_SHIFT_OP = 281,
    INCR_OP = 282,
    DECR_OP = 283,
    PTR_OP = 284,
    AND_OP = 285,
    OR_OP = 286,
    LESS_THAN_EQUAL_TO_OP = 287,
    GREATER_THAN_EQUAL_TO_OP = 288,
    EQUAL_TO_OP = 289,
    NOT_EQUAL_TO_OP = 290,
    TEMPPREC = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 32 "calc.y" /* yacc.c:1909  */

  int		int_val;
  double 	decimal_val;
  char      char_val;
  char*     id_val;
  struct node*     ptr;

#line 99 "calc.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CALC_TAB_H_INCLUDED  */
