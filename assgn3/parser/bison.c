/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "grammar.y" /* yacc.c:339  */

	#include <stdio.h>
	#include<stdlib.h>
	extern int yylex(void);
	extern int mylineno ;
	extern char* yytext ;
	void yyerror(char *);

#line 75 "grammar.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.h".  */
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
#line 9 "grammar.y" /* yacc.c:355  */

  int		int_val;
  double 	decimal_val;
  char      char_val;
  char*     id_val;
  struct node*     ptr;

#line 164 "grammar.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 179 "grammar.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   854

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  349

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,     2,     2,    57,    48,     2,
      42,    43,    46,    55,    51,    54,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    47,
      59,    52,    58,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,    64,    45,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    21,    21,    24,    25,    26,    27,    37,    38,    41,
      42,    45,    45,    45,    45,    45,    45,    45,    45,    48,
      51,    51,    55,    60,    61,    62,    63,    64,    65,    66,
      66,    68,    69,    70,    73,    73,    73,    76,    76,    79,
      79,    82,    85,    86,    87,    88,    89,    90,    93,    94,
      95,    96,    97,    98,    98,   102,   102,   105,   106,   107,
     108,   109,   110,   111,   112,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   127,   128,   129,   132,   133,
     134,   135,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   148,   151,   152,   153,   156,   157,   158,   159,
     163,   163,   166,   169,   170,   171,   172,   173,   174,   177,
     178,   179,   180,   181,   182,   185,   185,   185,   188,   191,
     192,   193,   194,   194,   198,   199,   199,   203,   205,   205,
     207,   211,   211,   211,   214,   214,   215,   215,   216,   217,
     218,   219,   220,   221,   222,   225,   226,   227,   228,   229,
     230,   231,   232,   235,   238,   241,   244,   244,   248,   249,
     250,   250,   254,   257,   258,   259,   262,   263,   264,   265,
     266,   267
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "BOOL", "INT", "FLOAT",
  "DOUBLE", "CHAR", "DO", "WHILE", "IF", "ELIF", "FALSE", "TRUE", "IN",
  "OUT", "MAIN", "VOID", "FOR", "INTCONST", "CHAR_CONSTANT", "RETURN",
  "STRUCT", "SWITCH", "WHITESPACE", "CASE", "ELSE", "DEFAULT", "CONSTANT",
  "STRING", "INP_OP", "OUT_OP", "OR_OP", "INC_OP", "DEC_OP", "AND_OP",
  "LESS_EQ_OP", "GRE_EQ_OP", "DOUBLE_EQ_OP", "NOT_EQ_OP",
  "\"int argc, char* argv[]\"", "'('", "')'", "'{'", "'}'", "'*'", "';'",
  "'&'", "'['", "']'", "','", "'='", "'!'", "'-'", "'+'", "'/'", "'%'",
  "'>'", "'<'", "\"&&\"", "\"||\"", "':'", "'^'", "'|'", "$accept",
  "START", "OUTER", "MAINARG", "MAINF", "TYPE", "STRUCT1", "MVARDEF",
  "FUNCTION", "INNER", "VARNAME", "BRACKET", "MARG", "FARG", "VARDEF",
  "MVAR", "MCONST", "MATH", "RMATH", "RADDSUB", "RMULTIDIV", "INTMATH",
  "ADDSUB", "MULTIDIV", "CONDITIONAL", "IFN", "RELATIONALOPERATOR", "COND",
  "ELSEC", "SWITCHN", "SWITCHINNER", "WODEFAULT", "ARGT", "MARGT", "FCALL",
  "LOOP", "FL1", "FL2", "FL3", "OPERATOR", "FORN", "WHILEN", "DOWHILEN",
  "MIN", "MOUT", "INPUT", "OUTPUT", "CONST", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    40,    41,   123,   125,    42,    59,    38,    91,
      93,    44,    61,    33,    45,    43,    47,    37,    62,    60,
     297,   298,    58,    94,   124
};
# endif

#define YYPACT_NINF -305

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-305)))

#define YYTABLE_NINF -79

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,  -305,  -305,  -305,  -305,  -305,  -305,    22,    39,    13,
       9,    -2,    -2,    -2,    -8,  -305,    30,    51,    -2,  -305,
      25,    25,    11,    25,  -305,  -305,  -305,  -305,    54,    67,
    -305,    29,    25,  -305,  -305,  -305,    47,   388,    40,    40,
      80,   388,    88,  -305,  -305,   337,    87,    92,    94,  -305,
     105,   106,  -305,    25,    25,    80,    80,    42,   107,     8,
       2,  -305,     9,   114,  -305,  -305,  -305,  -305,  -305,  -305,
      25,    25,   410,  -305,   410,   148,   302,    50,    57,    36,
      76,    78,  -305,  -305,   120,   124,   125,  -305,  -305,   129,
    -305,  -305,  -305,  -305,  -305,    80,    80,    80,    80,    80,
     146,   617,  -305,  -305,    82,   133,  -305,  -305,   292,  -305,
    -305,  -305,  -305,  -305,  -305,   147,  -305,  -305,   410,   410,
     410,   410,   410,  -305,  -305,  -305,  -305,  -305,   617,   617,
    -305,   136,   410,  -305,     2,     2,  -305,  -305,  -305,  -305,
     127,   139,   159,  -305,  -305,   161,   617,   651,   162,    25,
      25,   -19,     9,   160,   670,   617,   617,   617,  -305,  -305,
     617,   617,  -305,  -305,  -305,   617,   617,  -305,   -31,  -305,
    -305,    36,    36,  -305,  -305,  -305,   170,   173,  -305,   155,
     617,   458,   458,   193,   195,   673,  -305,    26,  -305,   458,
     181,   182,   190,  -305,   197,   205,  -305,  -305,   410,  -305,
    -305,  -305,  -305,  -305,  -305,   201,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,   207,  -305,  -305,  -305,   210,   458,   458,
    -305,   740,   747,    25,   171,  -305,     9,   694,  -305,   458,
     754,  -305,  -305,   410,  -305,  -305,   215,   410,  -305,   253,
     133,   779,  -305,   149,  -305,  -305,  -305,  -305,   220,  -305,
    -305,   458,   458,   458,   221,   222,   223,   224,   228,   149,
     231,   238,   178,  -305,   236,   242,  -305,   617,   149,   149,
     149,   617,  -305,  -305,  -305,  -305,   233,   -11,  -305,   458,
     243,   244,    25,    25,     9,   718,   250,   292,   232,   252,
     786,  -305,     7,  -305,  -305,   248,  -305,  -305,   410,   265,
     260,   256,   479,  -305,   272,   278,   277,  -305,   410,  -305,
     410,   617,   525,   617,   298,  -305,   458,   617,  -305,  -305,
     280,   617,   -11,   284,   292,  -305,   793,   286,  -305,   288,
    -305,   298,   273,   290,  -305,   -11,  -305,   571,   617,  -305,
     617,   298,   293,   294,  -305,     7,   298,  -305,  -305
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    11,    14,    15,    18,    13,     0,     0,     0,
       0,     3,     3,     3,    16,     1,     0,     0,     3,    38,
       0,     0,     0,     0,     5,     6,     4,    21,     0,     0,
       2,    36,     0,    34,    35,    40,     0,     0,     7,     7,
      92,     0,     0,    42,    48,    56,     0,    54,     0,     8,
       0,     0,    86,     0,     0,    92,    92,    82,    96,    87,
      93,    83,     0,     0,   169,   170,   167,   166,   168,   171,
       0,     0,     0,    56,     0,    65,     0,    78,    74,    75,
      66,    73,    16,    17,    20,     0,     0,    90,    91,    96,
      85,    88,    89,   129,    37,    92,    92,    92,    92,    92,
      41,    30,    69,    70,    65,    78,    66,    73,     0,    72,
      67,    68,    46,    52,    53,     0,    45,    51,     0,     0,
       0,     0,     0,    44,    50,    43,    49,    19,    30,    30,
      84,     0,     0,    96,    93,    93,    96,    96,    96,    39,
       0,     0,     0,   157,   161,     0,    30,    30,     0,     0,
       0,    58,     0,     0,     0,    30,    30,    30,   100,   101,
      30,    30,   131,   132,   133,    30,    30,    71,     0,    55,
      78,    75,    75,    78,    78,    78,     0,     0,   130,    78,
      30,     0,     0,     0,     0,   135,    28,    38,    26,     0,
       0,     0,     0,    22,     0,     0,   147,   149,     0,   146,
     145,   148,   152,   150,   151,     0,    25,    33,    24,    27,
      23,    31,    32,     0,    10,     9,   128,     0,     0,     0,
      78,     0,     0,     0,     0,    58,     0,     0,   134,   137,
       0,    63,    64,     0,    61,    62,    78,     0,    47,     0,
      78,     0,    72,   112,   107,   108,   105,   106,     0,   103,
     104,     0,     0,     0,     0,   156,   160,   158,   159,   136,
       0,     0,    59,    57,    78,     0,   109,    30,   110,   111,
     114,    30,   162,   165,   163,   164,     0,   123,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   117,   143,   144,     0,   141,   142,     0,     0,
       0,     0,    30,   118,     0,     0,     0,   102,     0,    78,
       0,    30,    30,    30,   126,   155,     0,    30,    78,    78,
       0,    30,   123,     0,     0,   122,     0,     0,   153,     0,
     120,   126,     0,     0,   116,   123,   121,    30,    30,   119,
      30,   126,     0,     0,   125,   117,   126,   115,   124
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -305,  -305,   141,   303,  -305,    38,  -305,  -305,  -305,   130,
     -10,  -305,  -305,  -305,    95,  -305,   264,   156,   128,  -305,
      16,   -32,  -305,    48,  -305,  -305,  -305,  -149,     0,  -305,
    -281,  -304,  -305,  -305,    65,  -305,  -305,  -305,  -305,    63,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,   -44
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    50,    18,   152,    11,    37,    12,   153,
     104,    31,    41,    42,   155,    23,    76,   156,   220,    78,
      79,   133,    59,    60,   157,   158,   253,   221,   307,   159,
     289,   325,   131,   132,   106,   161,   229,   260,   286,   205,
     162,   163,   164,   183,   184,   165,   166,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    81,     1,     2,     3,     4,     5,   -29,    58,   -29,
      33,    34,    19,    36,   213,   287,     6,   288,    16,   305,
     169,     7,    33,    89,    90,    14,   -29,   336,    19,   -16,
      57,    17,   115,   222,   306,    75,    27,   344,    10,    15,
     230,   330,   348,    87,    88,    57,    57,    28,    97,    10,
      10,    10,   100,    35,   339,    20,    10,    21,    98,    99,
     102,   103,    95,    96,   168,   136,   137,   138,    29,   241,
     243,    32,   -16,    21,   -16,    47,    91,    92,    40,    62,
     259,    49,   120,    19,    93,    57,    57,    57,    57,    57,
      82,   154,   121,   122,    43,    13,    38,   116,    44,    45,
      52,   117,   268,   269,   270,    61,    13,    13,    13,    39,
      80,   118,   119,    13,    53,    54,   110,   111,   154,   154,
      61,    61,    55,   123,    93,   125,    32,   124,    21,   126,
     290,    63,    48,    56,   171,   172,   154,   154,    83,   190,
     191,    84,   192,   134,   135,   154,   154,   154,    85,    86,
     154,   154,    24,    25,    26,   154,   154,    94,   101,    30,
      61,    61,    61,    61,    61,   127,   160,   326,   128,   129,
     154,   180,   130,    77,    19,   227,   167,    64,    65,   178,
     258,   181,   110,   111,    66,    67,   244,   245,   246,   247,
      93,    68,    69,   160,   160,   112,   256,   139,   169,   113,
     105,   182,   109,   185,   189,   193,   216,   249,   250,   251,
     252,   160,   160,   255,   257,   214,   192,    32,   215,    21,
     160,   160,   160,   226,   223,   160,   160,   224,   231,   232,
     160,   160,   -78,   -78,   -78,   -78,    19,     1,     2,     3,
       4,     5,   233,   301,   234,   160,   170,   170,   173,   174,
     175,     6,   235,   237,   238,   239,    46,   154,   176,   177,
     179,   154,   263,   265,   267,   271,   285,   282,   283,   272,
     273,   274,   293,   294,   295,   275,   186,   188,   276,    32,
     332,    21,   277,   278,   279,   206,   207,   208,   291,   292,
     209,   210,   154,   300,   302,   211,   212,   303,    64,    65,
     308,   154,   154,   154,   311,    66,    67,   154,    64,    65,
     217,   154,    68,    69,   284,    66,    67,   310,   312,   315,
     316,   317,    68,    69,   324,   328,   236,   154,   154,   331,
     154,   334,   160,   335,   338,   337,   160,   108,   345,   346,
      19,   228,    51,    64,    65,   347,   240,   242,   299,     0,
      66,    67,     0,   114,     0,     0,     0,    68,    69,     0,
       0,   262,     0,     0,     0,   264,     0,   160,     0,     0,
       0,    70,    71,     0,     0,     0,   160,   160,   160,    72,
       0,    73,   160,    32,     0,    21,   160,     0,     0,     0,
      74,     0,     1,     2,     3,     4,     5,   280,     0,     0,
       0,   281,   160,   160,     0,   160,     6,     0,     0,     0,
       0,    46,     0,    19,     0,     0,    64,    65,     0,     0,
       0,     0,     0,    66,    67,     0,   309,     0,     0,     0,
      68,    69,   314,     0,     0,     0,   318,     0,   319,     0,
       0,   320,   322,   323,    70,    71,     0,   327,     0,     0,
       0,   329,    72,     0,     0,     0,    32,     0,    21,     0,
       0,    19,     0,    74,    64,    65,     0,   341,   342,     0,
     343,    66,    67,     0,     0,     0,     0,     0,    68,    69,
       0,     0,    19,     1,     2,     3,     4,     5,   140,   141,
     142,     0,    70,    71,   143,   144,     0,     6,   145,     0,
     218,   146,   147,   148,    32,     0,    21,     0,     0,     0,
       0,   219,     0,   149,   150,     0,     0,     0,     0,     0,
       0,     0,     0,   313,     0,    32,   151,    21,    19,     1,
       2,     3,     4,     5,   140,   141,   142,     0,     0,     0,
     143,   144,     0,     6,   145,     0,     0,   146,   147,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   149,
     150,     0,     0,     0,     0,     0,     0,     0,     0,   321,
       0,    32,   151,    21,    19,     1,     2,     3,     4,     5,
     140,   141,   142,     0,     0,     0,   143,   144,     0,     6,
     145,     0,     0,   146,   147,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,   150,     0,     0,     0,
       0,     0,     0,     0,     0,   340,     0,    32,   151,    21,
      19,     1,     2,     3,     4,     5,   140,   141,   142,     0,
       0,     0,   143,   144,     0,     6,   145,     0,     0,   146,
     147,   148,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   149,   150,     0,   187,     1,     2,     3,     4,     5,
     140,   141,   142,    32,   151,    21,   143,   144,     0,     6,
     145,     0,     0,   146,   147,   148,    19,     1,     2,     3,
       4,     5,     0,     0,     0,   149,   150,     0,     0,     0,
       0,     6,     0,     0,     0,     0,    46,    32,   151,    21,
       0,     0,     0,     0,   194,   195,     0,   149,   150,     0,
       0,     0,    93,     0,     0,     0,   196,     0,   197,    32,
     225,    21,   198,     0,   199,   200,   201,   202,   194,   195,
       0,     0,     0,   203,   204,     0,     0,     0,     0,     0,
     196,     0,   197,     0,     0,     0,   198,     0,   199,   200,
     201,   202,   296,   297,     0,     0,     0,   203,   204,     0,
       0,     0,     0,     0,   196,     0,   197,     0,     0,     0,
     298,     0,   199,   200,   201,   202,     0,   244,   245,   246,
     247,   203,   204,   248,   244,   245,   246,   247,     0,     0,
     254,   244,   245,   246,   247,     0,     0,   261,   249,   250,
     251,   252,     0,     0,     0,   249,   250,   251,   252,     0,
       0,     0,   249,   250,   251,   252,   244,   245,   246,   247,
       0,     0,   266,   244,   245,   246,   247,     0,     0,   304,
     244,   245,   246,   247,     0,     0,   333,   249,   250,   251,
     252,     0,     0,     0,   249,   250,   251,   252,     0,     0,
       0,   249,   250,   251,   252
};

static const yytype_int16 yycheck[] =
{
      10,    45,     4,     5,     6,     7,     8,    26,    40,    28,
      20,    21,     3,    23,    45,    26,    18,    28,     5,    12,
      51,    23,    32,    55,    56,     3,    45,   331,     3,     3,
      40,    18,    76,   182,    27,    45,    44,   341,     0,     0,
     189,   322,   346,    53,    54,    55,    56,    17,    46,    11,
      12,    13,    62,    42,   335,    46,    18,    48,    56,    57,
      70,    71,    54,    55,   108,    97,    98,    99,    17,   218,
     219,    46,    46,    48,    48,    37,    34,    35,    49,    41,
     229,    41,    46,     3,    42,    95,    96,    97,    98,    99,
       3,   101,    56,    57,    47,     0,    42,    47,    51,    52,
      20,    51,   251,   252,   253,    40,    11,    12,    13,    42,
      45,    54,    55,    18,    34,    35,    34,    35,   128,   129,
      55,    56,    42,    47,    42,    47,    46,    51,    48,    51,
     279,    43,    37,    53,   118,   119,   146,   147,    46,   149,
     150,    47,   152,    95,    96,   155,   156,   157,    43,    43,
     160,   161,    11,    12,    13,   165,   166,    50,    44,    18,
      95,    96,    97,    98,    99,    45,   101,   316,    44,    44,
     180,    44,    43,    45,     3,   185,    43,     6,     7,    43,
     224,    42,    34,    35,    13,    14,    37,    38,    39,    40,
      42,    20,    21,   128,   129,    47,    25,    51,    51,    51,
      72,    42,    74,    42,    42,    45,    51,    58,    59,    60,
      61,   146,   147,   223,   224,    45,   226,    46,    45,    48,
     155,   156,   157,   185,    31,   160,   161,    32,    47,    47,
     165,   166,    54,    55,    56,    57,     3,     4,     5,     6,
       7,     8,    52,   287,    47,   180,   118,   119,   120,   121,
     122,    18,    47,    52,    47,    45,    23,   267,   128,   129,
     132,   271,    47,    10,    44,    44,   276,    34,    35,    47,
      47,    47,   282,   283,   284,    47,   146,   147,    47,    46,
     324,    48,    44,    47,    42,   155,   156,   157,    45,    45,
     160,   161,   302,    43,    62,   165,   166,    45,     6,     7,
      52,   311,   312,   313,    44,    13,    14,   317,     6,     7,
     180,   321,    20,    21,   276,    13,    14,    52,    62,    47,
      42,    44,    20,    21,    26,    45,   198,   337,   338,    45,
     340,    45,   267,    45,    44,    62,   271,    73,    45,    45,
       3,   185,    39,     6,     7,   345,   218,   219,   285,    -1,
      13,    14,    -1,    51,    -1,    -1,    -1,    20,    21,    -1,
      -1,   233,    -1,    -1,    -1,   237,    -1,   302,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,   311,   312,   313,    42,
      -1,    44,   317,    46,    -1,    48,   321,    -1,    -1,    -1,
      53,    -1,     4,     5,     6,     7,     8,   267,    -1,    -1,
      -1,   271,   337,   338,    -1,   340,    18,    -1,    -1,    -1,
      -1,    23,    -1,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,   298,    -1,    -1,    -1,
      20,    21,   302,    -1,    -1,    -1,   308,    -1,   310,    -1,
      -1,   311,   312,   313,    34,    35,    -1,   317,    -1,    -1,
      -1,   321,    42,    -1,    -1,    -1,    46,    -1,    48,    -1,
      -1,     3,    -1,    53,     6,     7,    -1,   337,   338,    -1,
     340,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,    21,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    34,    35,    15,    16,    -1,    18,    19,    -1,
      42,    22,    23,    24,    46,    -1,    48,    -1,    -1,    -1,
      -1,    53,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    46,    47,    48,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    -1,    18,    19,    -1,    -1,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    46,    47,    48,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    46,    47,    48,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    46,    47,    48,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    24,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    23,    46,    47,    48,
      -1,    -1,    -1,    -1,    34,    35,    -1,    34,    35,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,    46,
      47,    48,    52,    -1,    54,    55,    56,    57,    34,    35,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    48,    -1,    -1,    -1,    52,    -1,    54,    55,
      56,    57,    34,    35,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    -1,    37,    38,    39,
      40,    63,    64,    43,    37,    38,    39,    40,    -1,    -1,
      43,    37,    38,    39,    40,    -1,    -1,    43,    58,    59,
      60,    61,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    58,    59,    60,    61,    37,    38,    39,    40,
      -1,    -1,    43,    37,    38,    39,    40,    -1,    -1,    43,
      37,    38,    39,    40,    -1,    -1,    43,    58,    59,    60,
      61,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    58,    59,    60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,    18,    23,    66,    67,
      70,    71,    73,    79,     3,     0,     5,    18,    69,     3,
      46,    48,    75,    80,    67,    67,    67,    44,    17,    17,
      67,    76,    46,    75,    75,    42,    75,    72,    42,    42,
      49,    77,    78,    47,    51,    52,    23,    70,    79,    41,
      68,    68,    20,    34,    35,    42,    53,    75,    86,    87,
      88,    99,    70,    43,     6,     7,    13,    14,    20,    21,
      34,    35,    42,    44,    53,    75,    81,    83,    84,    85,
      99,   112,     3,    46,    47,    43,    43,    75,    75,    86,
      86,    34,    35,    42,    50,    54,    55,    46,    56,    57,
      75,    44,    75,    75,    75,    83,    99,   112,    81,    83,
      34,    35,    47,    51,    51,   112,    47,    51,    54,    55,
      46,    56,    57,    47,    51,    47,    51,    45,    44,    44,
      43,    97,    98,    86,    88,    88,    86,    86,    86,    51,
       9,    10,    11,    15,    16,    19,    22,    23,    24,    34,
      35,    47,    70,    74,    75,    79,    82,    89,    90,    94,
      99,   100,   105,   106,   107,   110,   111,    43,   112,    51,
      83,    85,    85,    83,    83,    83,    74,    74,    43,    83,
      44,    42,    42,   108,   109,    42,    74,     3,    74,    42,
      75,    75,    75,    45,    34,    35,    46,    48,    52,    54,
      55,    56,    57,    63,    64,   104,    74,    74,    74,    74,
      74,    74,    74,    45,    45,    45,    51,    74,    42,    53,
      83,    92,    92,    31,    32,    47,    70,    75,    82,   101,
      92,    47,    47,    52,    47,    47,    83,    52,    47,    45,
      83,    92,    83,    92,    37,    38,    39,    40,    43,    58,
      59,    60,    61,    91,    43,    75,    25,    75,   112,    92,
     102,    43,    83,    47,    83,    10,    43,    44,    92,    92,
      92,    44,    47,    47,    47,    47,    47,    44,    47,    42,
      74,    74,    34,    35,    70,    75,   103,    26,    28,    95,
      92,    45,    45,    75,    75,    75,    34,    35,    52,   104,
      43,   112,    62,    45,    43,    12,    27,    93,    52,    83,
      52,    44,    62,    44,    74,    47,    42,    44,    83,    83,
      74,    44,    74,    74,    26,    96,    92,    74,    45,    74,
      95,    45,   112,    43,    45,    45,    96,    62,    44,    95,
      44,    74,    74,    74,    96,    45,    45,    93,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      72,    72,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    77,
      77,    78,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    84,    84,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    88,    88,    88,    88,
      89,    89,    90,    91,    91,    91,    91,    91,    91,    92,
      92,    92,    92,    92,    92,    93,    93,    93,    94,    95,
      95,    95,    95,    95,    96,    96,    96,    97,    98,    98,
      99,   100,   100,   100,   101,   101,   102,   102,   103,   103,
     103,   103,   103,   103,   103,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   106,   107,   108,   108,   109,   109,
     109,   109,   110,   111,   111,   111,   112,   112,   112,   112,
     112,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     2,     2,     0,     1,     8,
       8,     1,     1,     1,     1,     1,     2,     2,     1,     7,
       3,     0,     8,     2,     2,     2,     2,     2,     2,     1,
       0,     2,     2,     2,     2,     2,     2,     4,     0,     4,
       0,     3,     4,     6,     6,     6,     6,     9,     3,     5,
       5,     5,     5,     5,     0,     3,     0,     4,     1,     4,
       5,     3,     3,     3,     3,     1,     1,     2,     2,     2,
       2,     3,     2,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     1,     1,     3,     2,     1,     1,     2,     2,
       2,     2,     0,     1,     3,     3,     1,     3,     3,     3,
       1,     1,     8,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     2,     1,     3,     8,     4,     0,     7,     7,
       5,     6,     4,     0,     7,     5,     0,     2,     3,     0,
       4,     1,     1,     1,     1,     0,     1,     0,     3,     4,
       4,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,    10,     7,     9,     3,     0,     3,     3,
       3,     0,     5,     5,     5,     5,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
#line 1597 "grammar.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}