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
#line 3 "calc.y" /* yacc.c:339  */

#include <bits/stdc++.h>
#include "heading.h"
void yyerror(char *s);
void yyerror(string);
int yylex(void);
int line_num = 1;


typedef struct node{
	vector<node*> child;	
	string node_name ;
	node (vector<node*> v,string attr)
	{
		child = v;
		node_name = attr;
	}
	node (string attr)
	{
		node_name = attr;
	}
}node;
node * wrap(char c);
node* mkleaf(string s);
node* mknode(vector<node*> v, string attr);
node* root = NULL;
void preorder(node* t);

#line 95 "calc.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "calc.tab.h".  */
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
#line 32 "calc.y" /* yacc.c:355  */

  int		int_val;
  double 	decimal_val;
  char      char_val;
  char*     id_val;
  struct node*     ptr;

#line 180 "calc.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CALC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 195 "calc.tab.c" /* yacc.c:358  */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   558

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  239

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,     2,     2,    55,    37,     2,
      42,    48,    40,    38,    44,    39,    56,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      53,    45,    54,     2,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,    51,    47,    57,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    93,    93,    96,    97,    98,   101,   103,   104,   105,
     106,   108,   109,   110,   112,   113,   115,   116,   118,   119,
     121,   122,   123,   124,   126,   127,   129,   130,   132,   133,
     135,   136,   138,   139,   141,   142,   144,   145,   147,   148,
     149,   151,   152,   153,   154,   155,   157,   158,   159,   161,
     162,   163,   165,   166,   167,   168,   170,   171,   173,   174,
     175,   176,   177,   178,   180,   181,   182,   183,   184,   185,
     186,   187,   189,   190,   191,   192,   193,   194,   196,   197,
     198,   199,   200,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   212,   213,   215,   216,   218,   220,   221,   223,
     224,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   241,   242,   245,   248,   249
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "STRUCT", "VOID", "LONG", "SHORT",
  "CONTINUE", "BREAK", "WHILE", "ELSE", "SIZEOF", "RETURN", "DOUBLE",
  "FLOAT", "INT", "FOR", "CHAR", "BOOL", "IDENTIFIERS", "INTEGER_CONSTANT",
  "FLOAT_CONSTANT", "CHARACTER_CONSTANT", "STRING_CONSTANT",
  "RIGHT_SHIFT_OP", "LEFT_SHIFT_OP", "INCR_OP", "DECR_OP", "PTR_OP",
  "AND_OP", "OR_OP", "LESS_THAN_EQUAL_TO_OP", "GREATER_THAN_EQUAL_TO_OP",
  "EQUAL_TO_OP", "NOT_EQUAL_TO_OP", "TEMPPREC", "'&'", "'+'", "'-'", "'*'",
  "'/'", "'('", "';'", "','", "'='", "'{'", "'}'", "')'", "'['", "']'",
  "'|'", "'^'", "'<'", "'>'", "'%'", "'.'", "'~'", "'!'", "'@'", "$accept",
  "Program", "Program_element", "Declaration", "Declarator_list",
  "Initializer", "Initializer_list", "Declarator", "Pointer",
  "Simple_declarator", "Expression_list", "Expression", "Pl1", "Pl2",
  "Pl3", "Pl4", "Pl5", "Pl6", "Pl7", "Pl8", "Pl9", "Pl10",
  "Unary_expression", "Pl11", "Pl12", "Basic_expression", "Unary_op",
  "Type", "Function", "Parameter_list", "Struct",
  "Struct_declaration_list", "SS", "Stmt", "if_Stmt", "for_Stmt",
  "while_Stmt", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,    38,    43,    45,
      42,    47,    40,    59,    44,    61,   123,   125,    41,    91,
      93,   124,    94,    60,    62,    37,    46,   126,    33,    64
};
# endif

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -113

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     247,    -6,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
      31,  -129,   247,     1,   247,  -129,   -38,  -129,  -129,  -129,
      -2,     1,    13,    39,   -10,    -5,  -129,   247,  -129,     3,
    -129,     1,    21,   329,    -5,   369,     1,   200,  -129,    54,
       0,     1,   -28,    50,  -129,  -129,  -129,  -129,  -129,   457,
     457,  -129,  -129,   218,   329,  -129,  -129,  -129,  -129,  -129,
      83,    94,    90,   123,   131,    56,    26,    87,    82,     8,
     135,  -129,    47,  -129,   457,  -129,   136,  -129,    79,  -129,
       1,   329,   130,  -129,   247,   139,   266,   481,  -129,  -129,
      18,  -129,   133,  -129,    57,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,  -129,  -129,   175,   393,   481,   176,
    -129,  -129,  -129,     1,    84,  -129,   156,   158,   159,   160,
     166,   433,   169,   130,   130,   130,   112,     1,   154,   130,
     130,   130,     1,   130,   165,   172,   481,  -129,   457,   289,
    -129,    94,  -129,    90,   123,   131,    56,    26,    26,    87,
      87,    87,    87,    82,    82,     8,     8,  -129,  -129,  -129,
    -129,  -129,  -129,    23,   167,  -129,  -129,  -129,  -129,   481,
     130,   130,   170,   130,   116,   481,  -129,   174,  -129,   130,
     181,  -129,  -129,  -129,  -129,  -129,   184,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,    24,  -129,  -129,   187,    29,
    -129,   130,   118,   130,  -129,  -129,   197,  -129,   198,  -129,
     481,  -129,   130,   130,   120,   201,   202,   481,   239,  -129,
      49,   209,   210,   130,   130,   212,   217,  -129,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,    89,    86,    90,    88,    87,    84,    83,    85,
       0,     2,     5,     0,     5,    91,     0,     1,     4,    20,
      18,     0,     0,     9,     0,    17,     3,     0,    19,     0,
       6,     0,     0,     0,    16,     0,     0,     0,    21,     7,
       0,     0,     0,     0,    72,    73,    74,    75,    76,     0,
       0,    82,    80,     0,     0,    78,    79,    81,    10,    11,
      26,    28,    30,    32,    34,    36,    38,    41,    46,    49,
      52,    57,    58,    64,     0,    22,     0,   100,     0,    96,
       0,     0,     0,    95,     0,     0,     0,     0,    59,    60,
       0,    24,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,     0,     0,     0,     0,
      63,    23,    98,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
      12,    29,    52,    31,    33,    35,    37,    39,    40,    43,
      45,    42,    44,    48,    47,    50,    51,    53,    54,    55,
      27,    71,    66,     0,     0,    68,    99,    97,   113,     0,
       0,     0,     0,     0,     0,     0,   106,     0,   111,     0,
       9,    93,   101,   103,   102,    94,     0,    61,    62,    25,
      56,    13,    14,    67,    65,     0,   107,   108,     0,     0,
     109,     0,     0,     0,   104,    92,     0,   118,     0,   110,
       0,   105,     0,     0,     0,     0,     0,     0,   115,   117,
       0,     0,     0,     0,     0,     0,     0,   114,   116
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,    10,    88,  -129,   -51,  -129,   -12,   248,   243,
     -53,   -31,  -129,   179,   173,   182,   185,   192,    65,     5,
      72,    75,   446,   -32,  -129,  -129,  -129,    33,  -129,  -129,
    -129,  -129,   215,  -128,  -129,  -129,  -129
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,   135,    22,    58,    94,    77,    24,    25,
     136,    91,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   137,    14,    42,
      15,    37,    78,   138,   139,   140,   141
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    23,    59,    93,    76,   186,   187,   188,    27,    29,
      19,   192,   193,   194,    16,   196,    84,    88,    89,    39,
      85,    19,    18,    59,    26,     1,     2,     3,     4,    83,
     125,    17,    21,    13,    90,     5,     6,     7,    20,     8,
       9,    20,   120,    21,    35,    13,    82,    13,   110,   111,
      59,    38,   206,   207,   144,   210,    30,    31,   102,   103,
      36,   214,   146,   112,   173,    41,   147,   146,   146,    40,
      80,   203,   216,   146,   114,   115,   116,   218,   184,   104,
     105,    32,   170,   219,    33,   221,    92,   174,    12,   117,
     100,   101,    86,   146,   225,   226,   118,   232,   202,    81,
      12,   149,    12,   119,   150,   235,   236,   159,   160,   161,
     162,   176,   106,   107,    95,   199,   200,   142,    59,   145,
     108,   109,   122,   123,    96,   190,   205,   177,   123,   209,
     195,   126,   212,   127,     1,     2,     3,     4,   128,   129,
     130,    97,    43,   131,     5,     6,     7,   132,     8,     9,
      44,    45,    46,    47,    48,   189,   146,    49,    50,   211,
     146,   220,   146,   227,   146,   157,   158,   224,    99,    51,
      52,   208,    53,   133,   230,    98,   134,  -112,   163,   164,
     113,   148,    43,   165,   166,   143,   121,    55,    56,    57,
      44,    45,    46,    47,    48,   171,   175,    49,    50,   178,
     179,   191,   180,   181,     1,     2,     3,     4,   182,    51,
      52,   185,    53,   197,     5,     6,     7,   204,     8,     9,
     198,   213,     1,     2,     3,     4,    33,    55,    56,    57,
      43,   215,     5,     6,     7,   217,     8,     9,    44,    45,
      46,    47,    48,   222,   223,    49,    50,    79,   228,   229,
     231,     1,     2,     3,     4,   233,   234,    51,    52,   237,
      53,     5,     6,     7,   238,     8,     9,    34,    28,   153,
       1,     2,     3,     4,   151,    55,    56,    57,    43,   154,
       5,     6,     7,   155,     8,     9,    44,    45,    46,    47,
      48,   156,     0,    49,    50,   124,     0,     0,     0,     0,
       0,    43,     0,     0,     0,    51,    52,     0,    87,    44,
      45,    46,    47,    48,     0,     0,    49,    50,     0,     0,
       0,     0,     0,    55,    56,    57,     0,     0,    51,    52,
       0,    53,     0,     0,     0,    54,   201,     0,     0,     0,
       0,    43,     0,     0,     0,     0,    55,    56,    57,    44,
      45,    46,    47,    48,     0,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    52,
       0,    53,     0,     0,     0,    54,     0,     0,     0,     0,
       0,    43,     0,     0,     0,     0,    55,    56,    57,    44,
      45,    46,    47,    48,     0,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,    43,     0,     0,    51,    52,
       0,    53,     0,    44,    45,    46,    47,    48,     0,    75,
      49,    50,     0,     0,     0,     0,    55,    56,    57,     0,
       0,     0,    51,    52,     0,    53,     0,     0,     0,     0,
       0,   172,     0,     0,     0,    43,     0,     0,     0,     0,
      55,    56,    57,    44,    45,    46,    47,    48,     0,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,    51,    52,     0,    53,   183,    44,    45,    46,
      47,    48,     0,     0,    49,    50,     0,     0,     0,     0,
      55,    56,    57,    43,     0,     0,    51,    52,     0,    87,
       0,    44,    45,    46,    47,    48,     0,     0,    49,    50,
       0,     0,     0,     0,    55,    56,    57,     0,     0,     0,
      51,    52,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    56,
      57,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   167,   168,   169
};

static const yytype_int16 yycheck[] =
{
      53,    13,    33,    54,    35,   133,   134,   135,    46,    21,
      20,   139,   140,   141,    20,   143,    44,    49,    50,    31,
      48,    20,    12,    54,    14,     4,     5,     6,     7,    41,
      81,     0,    42,     0,    87,    14,    15,    16,    40,    18,
      19,    40,    74,    42,    49,    12,    46,    14,    40,    41,
      81,    48,   180,   181,    86,   183,    43,    44,    32,    33,
      27,   189,    44,    55,   117,    32,    48,    44,    44,    48,
      37,    48,    48,    44,    27,    28,    29,    48,   131,    53,
      54,    42,   113,   211,    45,   213,    53,   118,     0,    42,
      34,    35,    42,    44,   222,   223,    49,    48,   149,    45,
      12,    44,    14,    56,    47,   233,   234,   102,   103,   104,
     105,   123,    25,    26,    31,   146,   148,    84,   149,    86,
      38,    39,    43,    44,    30,   137,   179,    43,    44,   182,
     142,     1,   185,     3,     4,     5,     6,     7,     8,     9,
      10,    51,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    43,    44,    27,    28,    43,
      44,    43,    44,    43,    44,   100,   101,   220,    37,    39,
      40,     1,    42,    43,   227,    52,    46,    47,   106,   107,
      45,    48,    12,   108,   109,    46,    50,    57,    58,    59,
      20,    21,    22,    23,    24,    20,    20,    27,    28,    43,
      42,    47,    43,    43,     4,     5,     6,     7,    42,    39,
      40,    42,    42,    48,    14,    15,    16,    50,    18,    19,
      48,    47,     4,     5,     6,     7,    45,    57,    58,    59,
      12,    47,    14,    15,    16,    48,    18,    19,    20,    21,
      22,    23,    24,    46,    46,    27,    28,    47,    47,    47,
      11,     4,     5,     6,     7,    46,    46,    39,    40,    47,
      42,    14,    15,    16,    47,    18,    19,    24,    20,    96,
       4,     5,     6,     7,    95,    57,    58,    59,    12,    97,
      14,    15,    16,    98,    18,    19,    20,    21,    22,    23,
      24,    99,    -1,    27,    28,    80,    -1,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    39,    40,    -1,    42,    20,
      21,    22,    23,    24,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    -1,    -1,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    57,    58,    59,    20,
      21,    22,    23,    24,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    57,    58,    59,    20,
      21,    22,    23,    24,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    39,    40,
      -1,    42,    -1,    20,    21,    22,    23,    24,    -1,    50,
      27,    28,    -1,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    -1,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      57,    58,    59,    20,    21,    22,    23,    24,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    39,    40,    -1,    42,    43,    20,    21,    22,
      23,    24,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
      57,    58,    59,    12,    -1,    -1,    39,    40,    -1,    42,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    27,    28,
      -1,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    -1,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,    14,    15,    16,    18,    19,
      61,    62,    63,    87,    88,    90,    20,     0,    62,    20,
      40,    42,    64,    67,    68,    69,    62,    46,    68,    67,
      43,    44,    42,    45,    69,    49,    87,    91,    48,    67,
      48,    87,    89,    12,    20,    21,    22,    23,    24,    27,
      28,    39,    40,    42,    46,    57,    58,    59,    65,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    50,    71,    67,    92,    47,
      87,    45,    46,    67,    44,    48,    42,    42,    83,    83,
      70,    71,    87,    65,    66,    31,    30,    51,    52,    37,
      34,    35,    32,    33,    53,    54,    25,    26,    38,    39,
      40,    41,    55,    45,    27,    28,    29,    42,    49,    56,
      83,    50,    43,    44,    92,    65,     1,     3,     8,     9,
      10,    13,    17,    43,    46,    63,    70,    87,    93,    94,
      95,    96,    87,    46,    83,    87,    44,    48,    48,    44,
      47,    73,    82,    74,    75,    76,    77,    78,    78,    79,
      79,    79,    79,    80,    80,    81,    81,    82,    82,    82,
      71,    20,    48,    70,    71,    20,    67,    43,    43,    42,
      43,    43,    42,    43,    70,    42,    93,    93,    93,    43,
      67,    47,    93,    93,    93,    67,    93,    48,    48,    71,
      83,    47,    65,    48,    50,    70,    93,    93,     1,    70,
      93,    43,    70,    47,    93,    47,    48,    48,    48,    93,
      43,    93,    46,    46,    70,    93,    93,    43,    47,    47,
      70,    11,    48,    46,    46,    93,    93,    47,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    62,    63,    64,    64,    64,
      64,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    78,    78,    78,    78,    78,    79,    79,    79,    80,
      80,    80,    81,    81,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    85,    85,    85,    85,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    88,    89,    89,    90,    91,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    94,    94,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     3,     3,     5,     1,
       3,     1,     3,     4,     3,     1,     2,     1,     1,     2,
       1,     3,     3,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     4,     1,     1,     2,
       2,     4,     4,     2,     1,     4,     3,     4,     3,     2,
       2,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     8,     7,     4,     2,     5,     4,     3,     3,
       1,     2,     2,     2,     3,     4,     2,     3,     3,     3,
       4,     2,     0,     2,    11,     7,    11,     7,     4
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
        case 2:
#line 93 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Program");root = (yyval.ptr); preorder(root); cout<<"//////";}
#line 1502 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 96 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-1].ptr)) ; v.push_back((yyvsp[0].ptr));	(yyval.ptr) = mknode(v,"Program_element");}
#line 1508 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 97 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-1].ptr)) ; v.push_back((yyvsp[0].ptr));	(yyval.ptr) = mknode(v,"Program_element");}
#line 1514 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 98 "calc.y" /* yacc.c:1646  */
    {(yyval.ptr) = mkleaf("~");}
#line 1520 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 101 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back((yyvsp[-1].ptr));	v.push_back(mkleaf(";"));(yyval.ptr) = mknode(v,"Declaration");}
#line 1526 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 103 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf(",")); v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Declarator_list");}
#line 1532 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 104 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-4].ptr)) ; v.push_back(mkleaf(",")); v.push_back((yyvsp[-2].ptr));v.push_back(mkleaf("=")); v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Declarator_list");}
#line 1538 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Declarator_list");}
#line 1544 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 106 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("=")); v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Declarator_list");}
#line 1550 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 108 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Initializer");}
#line 1556 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 109 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("{")) ; v.push_back((yyvsp[-1].ptr)); v.push_back(mkleaf("}")) ; (yyval.ptr) = mknode(v,"Initializer");}
#line 1562 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 110 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("{")) ; v.push_back((yyvsp[-2].ptr)); v.push_back(mkleaf(",")) ; v.push_back(mkleaf("}")) ; (yyval.ptr) = mknode(v,"Initializer");}
#line 1568 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 112 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf(",")); v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Initializer_list");}
#line 1574 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 113 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Initializer_list");}
#line 1580 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 115 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-1].ptr)) ; v.push_back((yyvsp[0].ptr));	(yyval.ptr) = mknode(v,"Declarator");}
#line 1586 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 116 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Declarator");}
#line 1592 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 118 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Pointer");}
#line 1598 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 119 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("*")) ; v.push_back((yyvsp[0].ptr)); v.push_back(mkleaf("}")) ; (yyval.ptr) = mknode(v,"Pointer");}
#line 1604 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 121 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Simple_declarator");}
#line 1610 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 122 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("(")) ; v.push_back((yyvsp[-1].ptr)); v.push_back(mkleaf(")")) ; (yyval.ptr) = mknode(v,"Simple_declarator");}
#line 1616 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 123 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("[")) ; v.push_back(mkleaf("]")) ; (yyval.ptr) = mknode(v,"Simple_declarator");}
#line 1622 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 124 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-3].ptr)) ; v.push_back(mkleaf("[")) ; v.push_back((yyvsp[-1].ptr)); v.push_back(mkleaf("]")) ; (yyval.ptr) = mknode(v,"Simple_declarator");}
#line 1628 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 126 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Expression_list");}
#line 1634 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 127 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf(",")); v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Expression_list");}
#line 1640 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 129 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Expression");}
#line 1646 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 130 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("=")); v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Expression");}
#line 1652 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 132 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl1");}
#line 1658 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 133 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("||")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl1");}
#line 1664 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 135 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl2");}
#line 1670 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 136 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("&&")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl2");}
#line 1676 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 138 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl3");}
#line 1682 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 139 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("|")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl3");}
#line 1688 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 141 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl4");}
#line 1694 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 142 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("^")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl4");}
#line 1700 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 144 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl5");}
#line 1706 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 145 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("&")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl5");}
#line 1712 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 147 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl6");}
#line 1718 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 148 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("==")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl6");}
#line 1724 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 149 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("!=")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl6");}
#line 1730 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 151 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl7");}
#line 1736 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 152 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("<")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl7");}
#line 1742 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 153 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("<=")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl7");}
#line 1748 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 154 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf(">")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl7");}
#line 1754 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 155 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf(">=")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl7");}
#line 1760 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 157 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl8");}
#line 1766 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 158 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("<<")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl8");}
#line 1772 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 159 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf(">>")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl8");}
#line 1778 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 161 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl9");}
#line 1784 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 162 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("+")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl9");}
#line 1790 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 163 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("-")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl9");}
#line 1796 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 165 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl10");}
#line 1802 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 166 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("*")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl10");}
#line 1808 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 167 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("/")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl10");}
#line 1814 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 168 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("%")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Pl10");}
#line 1820 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 170 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("(")) ; v.push_back((yyvsp[-2].ptr)); v.push_back(mkleaf(")")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Unary_expression");}
#line 1826 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 171 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Unary_expression");}
#line 1832 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 173 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl11");}
#line 1838 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 174 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("++")) ;  v.push_back((yyvsp[0].ptr));  (yyval.ptr) = mknode(v,"Pl11");}
#line 1844 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 175 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("--")) ;  v.push_back((yyvsp[0].ptr));  (yyval.ptr) = mknode(v,"Pl11");}
#line 1850 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 176 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("sizeof")) ; v.push_back(mkleaf("(")) ;v.push_back((yyvsp[-1].ptr)); v.push_back(mkleaf(")")) ; (yyval.ptr) = mknode(v,"Pl11"); }
#line 1856 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 177 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("sizeof")) ; v.push_back(mkleaf("(")) ;v.push_back((yyvsp[-1].ptr)); v.push_back(mkleaf(")")) ; (yyval.ptr) = mknode(v,"Pl11"); }
#line 1862 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 178 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-1].ptr)) ; v.push_back((yyvsp[0].ptr));	(yyval.ptr) = mknode(v,"Pl11");}
#line 1868 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 180 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Pl12");}
#line 1874 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 181 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-3].ptr)) ; v.push_back(mkleaf("[")) ; v.push_back((yyvsp[-1].ptr)); v.push_back(mkleaf("]")) ; (yyval.ptr) = mknode(v,"Pl12");}
#line 1880 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 182 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("[")) ; v.push_back(mkleaf("]")) ; (yyval.ptr) = mknode(v,"Pl12");}
#line 1886 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 183 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-3].ptr)) ; v.push_back(mkleaf("(")) ; v.push_back((yyvsp[-1].ptr)); v.push_back(mkleaf(")")) ; (yyval.ptr) = mknode(v,"Pl12");}
#line 1892 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 184 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf(".")) ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Pl12");}
#line 1898 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 185 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-1].ptr)) ; v.push_back(mkleaf("++")) ; (yyval.ptr) = mknode(v,"Pl12");}
#line 1904 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 186 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-1].ptr)) ; v.push_back(mkleaf("--")) ; (yyval.ptr) = mknode(v,"Pl12");}
#line 1910 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 187 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf("*")) ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Pl12");}
#line 1916 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 189 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Basic_expression"); }
#line 1922 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 190 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Basic_expression");}
#line 1928 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 191 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Basic_expression");}
#line 1934 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 192 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(wrap(yylval.char_val)); (yyval.ptr) = mknode(v,"Basic_expression");}
#line 1940 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 193 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Basic_expression");}
#line 1946 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 194 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("(")) ; v.push_back((yyvsp[-1].ptr)); v.push_back(mkleaf(")")) ; (yyval.ptr) = mknode(v,"Basic_expression");}
#line 1952 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 196 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Unary_op");}
#line 1958 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 197 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Unary_op");}
#line 1964 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 198 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Unary_op");}
#line 1970 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 199 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Unary_op");}
#line 1976 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 200 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Unary_op");}
#line 1982 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 202 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Type");}
#line 1988 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 203 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Type");}
#line 1994 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 204 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Type");}
#line 2000 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 205 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Type");}
#line 2006 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 206 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Type");}
#line 2012 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 207 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Type");}
#line 2018 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 208 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Type");}
#line 2024 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 209 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); (yyval.ptr) = mknode(v,"Type");}
#line 2030 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 210 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"Type");}
#line 2036 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 212 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-7].ptr)) ; v.push_back((yyvsp[-6].ptr));v.push_back(mkleaf("(")); v.push_back((yyvsp[-4].ptr)); v.push_back(mkleaf(")")); v.push_back(mkleaf("{")); v.push_back((yyvsp[-1].ptr));v.push_back(mkleaf("}"));	(yyval.ptr) = mknode(v,"Function");}
#line 2042 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 213 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-6].ptr)) ; v.push_back((yyvsp[-5].ptr));v.push_back(mkleaf("("));v.push_back(mkleaf(")")); v.push_back(mkleaf("{"));v.push_back((yyvsp[-1].ptr));v.push_back(mkleaf("}"));	(yyval.ptr) = mknode(v,"Function");}
#line 2048 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 215 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-3].ptr)) ; v.push_back(mkleaf(",")); v.push_back((yyvsp[-1].ptr)); v.push_back((yyvsp[0].ptr));	(yyval.ptr) = mknode(v,"Parameter_list");}
#line 2054 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 216 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-1].ptr)) ; v.push_back((yyvsp[0].ptr));	(yyval.ptr) = mknode(v,"Parameter_list");}
#line 2060 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 218 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("struct")); v.push_back(mkleaf("IDENTIFIERS"));v.push_back(mkleaf("{")) ;v.push_back((yyvsp[-1].ptr)) ;v.push_back(mkleaf("}")) ; (yyval.ptr) = mknode(v,"Struct");}
#line 2066 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 220 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-3].ptr)) ; v.push_back((yyvsp[-2].ptr));	v.push_back((yyvsp[-1].ptr)); v.push_back(mkleaf(";")); (yyval.ptr) = mknode(v,"Struct_declaration_list");}
#line 2072 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 221 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back((yyvsp[-1].ptr));	v.push_back(mkleaf(";")); (yyval.ptr) = mknode(v,"Struct_declaration_list");}
#line 2078 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 223 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf(",")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"SS");}
#line 2084 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 224 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[0].ptr)) ; (yyval.ptr) = mknode(v,"SS");}
#line 2090 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 226 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-1].ptr)) ; v.push_back((yyvsp[0].ptr));	(yyval.ptr) = mknode(v,"Stmt");}
#line 2096 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 227 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-1].ptr)) ; v.push_back((yyvsp[0].ptr));	(yyval.ptr) = mknode(v,"Stmt");}
#line 2102 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 228 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-1].ptr)) ; v.push_back((yyvsp[0].ptr));	(yyval.ptr) = mknode(v,"Stmt");}
#line 2108 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 229 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-2].ptr)) ; v.push_back(mkleaf(";")) ; v.push_back((yyvsp[0].ptr));	(yyval.ptr) = mknode(v,"Stmt");}
#line 2114 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 230 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("{")) ; v.push_back((yyvsp[-2].ptr)); v.push_back(mkleaf("}")) ;  v.push_back((yyvsp[0].ptr));(yyval.ptr) = mknode(v,"Stmt");}
#line 2120 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 231 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf(";")) ; v.push_back((yyvsp[0].ptr)); (yyval.ptr) = mknode(v,"Stmt");}
#line 2126 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 232 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("CONTINUE")); v.push_back(mkleaf(";")) ; v.push_back((yyvsp[0].ptr)); (yyval.ptr) = mknode(v,"Stmt");}
#line 2132 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 233 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("BREAK")); v.push_back(mkleaf(";")) ; v.push_back((yyvsp[0].ptr)); (yyval.ptr) = mknode(v,"Stmt");}
#line 2138 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 234 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("RETURN")); v.push_back(mkleaf(";")) ; v.push_back((yyvsp[0].ptr)); (yyval.ptr) = mknode(v,"Stmt");}
#line 2144 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 235 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("RETURN")); v.push_back((yyvsp[-2].ptr)); v.push_back(mkleaf(";")) ; v.push_back((yyvsp[0].ptr)); (yyval.ptr) = mknode(v,"Stmt");}
#line 2150 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 236 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back((yyvsp[-1].ptr)) ; v.push_back((yyvsp[0].ptr));	(yyval.ptr) = mknode(v,"Stmt");}
#line 2156 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 237 "calc.y" /* yacc.c:1646  */
    {(yyval.ptr) = mkleaf("~");}
#line 2162 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 238 "calc.y" /* yacc.c:1646  */
    {cout<<"1>>>>"; vector<node*> v ; v.push_back(mkleaf("ERROR\n")); (yyval.ptr) = mknode(v,"Stmt");  yyclearin;}
#line 2168 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 241 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("if")); v.push_back(mkleaf("(")) ; v.push_back((yyvsp[-8].ptr)); v.push_back(mkleaf(")")) ;v.push_back(mkleaf("{")) ;v.push_back((yyvsp[-5].ptr)) ;v.push_back(mkleaf("}")) ;v.push_back(mkleaf("else")) ;v.push_back(mkleaf("{")) ;v.push_back((yyvsp[-1].ptr)); v.push_back(mkleaf("}")) ; (yyval.ptr) = mknode(v,"if_Stmt");}
#line 2174 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 242 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("if")); v.push_back(mkleaf("(")) ; v.push_back((yyvsp[-4].ptr)); v.push_back(mkleaf(")")) ;v.push_back(mkleaf("{")) ;v.push_back((yyvsp[-1].ptr)) ;v.push_back(mkleaf("}")) ; (yyval.ptr) = mknode(v,"if_Stmt");}
#line 2180 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 245 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("for")); v.push_back(mkleaf("(")) ; v.push_back((yyvsp[-8].ptr)); v.push_back(mkleaf(";")) ; v.push_back((yyvsp[-6].ptr)); v.push_back(mkleaf(";")) ; v.push_back((yyvsp[-4].ptr)); v.push_back(mkleaf(")")) ;v.push_back(mkleaf("{")) ;v.push_back((yyvsp[-1].ptr)) ;v.push_back(mkleaf("}")) ; (yyval.ptr) = mknode(v,"for_Stmt");}
#line 2186 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 248 "calc.y" /* yacc.c:1646  */
    {vector<node*> v ; v.push_back(mkleaf("while")); v.push_back(mkleaf("(")) ; v.push_back((yyvsp[-4].ptr)); v.push_back(mkleaf(")")) ;v.push_back(mkleaf("{")) ;v.push_back((yyvsp[-1].ptr)) ;v.push_back(mkleaf("}")) ; (yyval.ptr) = mknode(v,"while_Stmt");}
#line 2192 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 249 "calc.y" /* yacc.c:1646  */
    {cout<<"3>>>>"; vector<node*> v ; v.push_back(mkleaf("ERROR\n")); (yyval.ptr) = mknode(v,"while_Stmt"); ; yyclearin;}
#line 2198 "calc.tab.c" /* yacc.c:1646  */
    break;


#line 2202 "calc.tab.c" /* yacc.c:1646  */
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
#line 252 "calc.y" /* yacc.c:1906  */

/*--------------------------------------------------------------------------------*/


void yyerror(string s)
{
  //extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cout << "ERROR: " << s << " at symbol \"" << yytext;
  cout << "\" on line " << line_num << endl;
}


void yyerror(char *s)
{
   yyerror(string(s));
}


node* mknode(vector<node*> v, string attr)	/*may be used and */
{
	node *n = new node(v,attr );
	return n; 
}

node* mkleaf(string s)
{
	node  *n = new node(s);
	return n;
}
node * wrap(char c)
{
	char ch[2];
	ch[0] = c;
	ch[1] = '\0';
	vector<node*> v; // local variable !!! 
	string str(ch);
	node *n = new node(v,str);
	return n;
}

void preorder(node* t)
{
	cout<<(t->node_name)<<", ";
	for(vector<node*>::iterator it = t->child.begin(); it!=t->child.end() ; it++)
	{
		preorder(*it);
	}
}
