/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BEG = 258,
     END = 259,
     T_INT = 260,
     T_BOOL = 261,
     READ = 262,
     WRITE = 263,
     DECL = 264,
     ENDDECL = 265,
     VAR = 266,
     NUM = 267,
     IF = 268,
     THEN = 269,
     ELSE = 270,
     ENDIF = 271,
     LOGICAL_AND = 272,
     LOGICAL_NOT = 273,
     LOGICAL_OR = 274,
     EQUALEQUAL = 275,
     LESSTHANOREQUAL = 276,
     GREATERTHANOREQUAL = 277,
     NOTEQUAL = 278,
     WHILE = 279,
     DO = 280,
     ENDWHILE = 281,
     T = 282,
     F = 283,
     MAIN = 284,
     RETURN = 285
   };
#endif
/* Tokens.  */
#define BEG 258
#define END 259
#define T_INT 260
#define T_BOOL 261
#define READ 262
#define WRITE 263
#define DECL 264
#define ENDDECL 265
#define VAR 266
#define NUM 267
#define IF 268
#define THEN 269
#define ELSE 270
#define ENDIF 271
#define LOGICAL_AND 272
#define LOGICAL_NOT 273
#define LOGICAL_OR 274
#define EQUALEQUAL 275
#define LESSTHANOREQUAL 276
#define GREATERTHANOREQUAL 277
#define NOTEQUAL 278
#define WHILE 279
#define DO 280
#define ENDWHILE 281
#define T 282
#define F 283
#define MAIN 284
#define RETURN 285




/* Copy the first part of user declarations.  */
#line 1 "Exprtree.y"
	
	#include <stdio.h>
	#include "AbsSynTree.h"
	#include "globals.h"
	#include "SymbTab.h"
	#include "codegen.h"
	FILE* yyin;
	#define YYSTYPE NODPTR
	char msg[60];
	int yylex();
	void yyerror( char* );
	int flag = 0;
	int errflag = 0;
	void SemError(char*);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 182 "Exprtree.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   299

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,    35,    33,    38,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      31,    45,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    12,    15,    19,    21,    23,
      27,    31,    36,    37,    39,    43,    45,    48,    50,    54,
      55,    58,    68,    70,    72,    81,    85,    86,    89,    93,
      95,    97,    99,   103,   105,   110,   114,   115,   118,   121,
     123,   125,   127,   129,   131,   137,   143,   147,   152,   159,
     168,   175,   177,   180,   182,   184,   186,   190,   194,   198,
     202,   206,   210,   214,   218,   222,   226,   230,   233,   237,
     241,   243,   248,   253,   254,   256,   258,   260,   264
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    57,    61,    -1,     9,    49,    10,
      -1,    -1,    50,    49,    -1,    65,    51,    37,    -1,    67,
      -1,    52,    -1,    67,    38,    51,    -1,    52,    38,    51,
      -1,    11,    39,    53,    40,    -1,    -1,    54,    -1,    54,
      37,    55,    -1,    55,    -1,    65,    56,    -1,    11,    -1,
      11,    38,    56,    -1,    -1,    57,    58,    -1,    60,    11,
      39,    53,    40,    41,    59,    68,    42,    -1,    62,    -1,
      65,    -1,     5,    29,    39,    40,    41,    59,    68,    42,
      -1,     9,    63,    10,    -1,    -1,    64,    63,    -1,    65,
      66,    37,    -1,     5,    -1,     6,    -1,    67,    -1,    67,
      38,    66,    -1,    11,    -1,    11,    43,    12,    44,    -1,
       3,    69,     4,    -1,    -1,    70,    69,    -1,     1,    37,
      -1,    74,    -1,    71,    -1,    72,    -1,    75,    -1,    73,
      -1,     7,    39,    77,    40,    37,    -1,     8,    39,    76,
      40,    37,    -1,    30,    76,    37,    -1,    77,    45,    76,
      37,    -1,    13,    76,    14,    69,    16,    37,    -1,    13,
      76,    14,    69,    15,    69,    16,    37,    -1,    24,    76,
      25,    69,    26,    37,    -1,    12,    -1,    34,    12,    -1,
      77,    -1,    27,    -1,    28,    -1,    39,    76,    40,    -1,
      76,    33,    76,    -1,    76,    34,    76,    -1,    76,    35,
      76,    -1,    76,    36,    76,    -1,    76,    31,    76,    -1,
      76,    32,    76,    -1,    76,    22,    76,    -1,    76,    21,
      76,    -1,    76,    23,    76,    -1,    76,    20,    76,    -1,
      18,    76,    -1,    76,    17,    76,    -1,    76,    19,    76,
      -1,    11,    -1,    11,    43,    76,    44,    -1,    11,    39,
      78,    40,    -1,    -1,    79,    -1,    11,    -1,    12,    -1,
      78,    38,    11,    -1,    78,    38,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    37,    37,    39,    41,    42,    44,    46,    47,    48,
      49,    51,    53,    54,    56,    56,    58,    60,    61,    63,
      64,    66,    68,    70,    72,    78,    81,    82,    85,    88,
      89,    92,    93,    96,   112,   141,   144,   145,   151,   154,
     155,   156,   157,   158,   161,   168,   170,   172,   180,   186,
     193,   201,   202,   206,   207,   208,   209,   211,   220,   229,
     238,   247,   255,   263,   272,   281,   288,   294,   300,   308,
     319,   339,   359,   361,   362,   363,   364,   365,   366
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEG", "END", "T_INT", "T_BOOL", "READ",
  "WRITE", "DECL", "ENDDECL", "VAR", "NUM", "IF", "THEN", "ELSE", "ENDIF",
  "LOGICAL_AND", "LOGICAL_NOT", "LOGICAL_OR", "EQUALEQUAL",
  "LESSTHANOREQUAL", "GREATERTHANOREQUAL", "NOTEQUAL", "WHILE", "DO",
  "ENDWHILE", "T", "F", "MAIN", "RETURN", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "';'", "','", "'('", "')'", "'{'", "'}'", "'['", "']'",
  "'='", "$accept", "Prog", "GDeclSec", "GDeclList", "GDecl", "GList",
  "func", "ArgList", "ArgList1", "Arg", "Varlist", "FDefSec", "FDef",
  "LDeclSec", "RetType", "MainBlock", "decl_sec", "decl_list", "decl",
  "type", "idlist", "id", "stmt_sec", "stmt_list", "statement",
  "read_stmt", "write_stmt", "ret_stmt", "assign_stmt", "cond_stmt",
  "expr", "var_expr", "ParamList", "ParamList1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    60,    62,    43,    45,    42,    47,    59,    44,    40,
      41,   123,   125,    91,    93,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    49,    49,    50,    51,    51,    51,
      51,    52,    53,    53,    54,    54,    55,    56,    56,    57,
      57,    58,    59,    60,    61,    62,    63,    63,    64,    65,
      65,    66,    66,    67,    67,    68,    69,    69,    69,    70,
      70,    70,    70,    70,    71,    72,    73,    74,    75,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    78,    78,    79,    79,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     0,     2,     3,     1,     1,     3,
       3,     4,     0,     1,     3,     1,     2,     1,     3,     0,
       2,     9,     1,     1,     8,     3,     0,     2,     3,     1,
       1,     1,     3,     1,     4,     3,     0,     2,     2,     1,
       1,     1,     1,     1,     5,     5,     3,     4,     6,     8,
       6,     1,     2,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       1,     4,     4,     0,     1,     1,     1,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,    19,    29,    30,     0,     4,     0,     1,
       0,     3,     5,    33,     0,     8,     7,    29,    20,     0,
       2,    23,    12,     0,     6,     0,     0,     0,     0,     0,
      13,    15,     0,     0,    10,     9,     0,    12,    11,     0,
      17,    16,    34,     0,     0,    14,     0,     0,     0,    18,
      26,     0,    22,     0,     0,    26,     0,     0,     0,     0,
      25,    27,    33,     0,    31,     0,     0,     0,    70,     0,
       0,     0,     0,     0,    40,    41,    43,    39,    42,     0,
      24,     0,    28,     0,    38,     0,     0,    73,     0,    51,
       0,    54,    55,     0,     0,     0,    53,     0,     0,    35,
      37,     0,    21,    32,     0,     0,    75,    76,     0,    74,
       0,    67,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,    72,    71,    56,     0,    68,    69,    66,
      64,    63,    65,    61,    62,    57,    58,    59,    60,     0,
      47,    44,    45,    77,    78,     0,     0,     0,     0,    48,
      50,     0,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,     7,    14,    15,    29,    30,    31,
      41,    10,    18,    51,    19,    20,    52,    54,    55,    32,
      63,    16,    58,    72,    73,    74,    75,    76,    77,    78,
      95,    96,   108,   109
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int16 yypact[] =
{
      -5,     7,    22,   -73,   -73,   -73,    23,     7,    28,   -73,
      12,   -73,   -73,   -36,    10,    15,    38,    48,   -73,    67,
     -73,   -73,     7,    72,   -73,    28,    28,    60,    61,    62,
      64,   -73,    94,    66,   -73,   -73,    68,     7,   -73,     7,
      75,   -73,   -73,    65,    74,   -73,    94,   107,    76,   -73,
       7,   116,   -73,   107,   118,     7,   113,   114,    89,   116,
     -73,   -73,    91,    95,    98,   100,   101,   102,   -33,    -3,
      -3,    -3,   135,    19,   -73,   -73,   -73,   -73,   -73,    97,
     -73,   109,   -73,   113,   -73,   143,    -3,    40,    -3,   -73,
      -3,   -73,   -73,   144,    -3,   214,   -73,   263,   221,   -73,
     -73,    -3,   -73,   -73,   117,   168,   -73,   -73,     6,   -73,
     148,   -73,   -73,   190,    96,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,   122,   -73,   242,
     123,   136,    50,   -73,   -73,   -73,    57,   -73,   -73,   128,
     128,   128,   128,    46,    46,     2,     2,    31,    31,   133,
     -73,   -73,   -73,   -73,   -73,   142,   137,   138,   160,   -73,
     -73,   140,   -73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   171,   -73,    49,   -73,   149,   -73,   154,
     150,   -73,   -73,   141,   -73,   -73,   -73,   151,   -73,     4,
     112,   -54,   139,   -72,   -73,   -73,   -73,   -73,   -73,   -73,
     -30,   -57,   -73,   -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -37
static const yytype_int16 yytable[] =
{
      79,   100,    64,    22,     1,     8,    87,    23,    68,    89,
      88,     8,     4,     5,    21,    90,    79,    17,     5,   115,
      65,   116,     9,   -36,    91,    92,    66,    67,   104,    64,
      68,    93,    69,    11,   -36,   -36,    94,   125,   126,    13,
      97,    98,   136,    70,   132,   -36,   133,    24,   115,    71,
     116,   106,   107,    25,    56,   149,   105,    79,   110,    56,
     111,   153,   154,   115,   113,   116,   117,   118,   119,   120,
      79,   129,   155,   156,    34,    35,    26,    27,    28,   123,
     124,   125,   126,   158,    33,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    65,    79,    36,
      37,    39,    38,    66,    67,    40,    47,    68,    43,    69,
      42,   -36,   -36,    46,    48,    65,    50,    53,   -36,    57,
      70,    66,    67,    65,    62,    68,    71,    69,    60,    66,
      67,    80,    82,    68,    23,    69,    83,    84,    70,    99,
      85,    86,   101,    65,    71,   115,    70,   116,   -36,    66,
      67,   102,    71,    68,    68,    69,   112,   130,   -36,   157,
     151,   123,   124,   125,   126,   115,    70,   116,   117,   118,
     119,   120,    71,   152,   159,   160,   161,   162,    12,   121,
     122,   123,   124,   125,   126,   115,    44,   116,   117,   118,
     119,   120,   134,    45,    59,   103,    49,     0,    81,   121,
     122,   123,   124,   125,   126,     0,    61,   115,   131,   116,
     117,   118,   119,   120,     0,     0,     0,     0,     0,     0,
       0,   121,   122,   123,   124,   125,   126,     0,   114,     0,
     135,   115,     0,   116,   117,   118,   119,   120,   115,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     0,   121,   122,   123,   124,   125,   126,   128,   115,
       0,   116,   117,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,   121,   122,   123,   124,   125,   126,   150,
     115,     0,   116,   117,   118,   119,   120,     0,   127,     0,
       0,     0,     0,     0,   121,   122,   123,   124,   125,   126
};

static const yytype_int16 yycheck[] =
{
      57,    73,    56,    39,     9,     1,    39,    43,    11,    12,
      43,     7,     5,     6,    10,    18,    73,     5,     6,    17,
       1,    19,     0,     4,    27,    28,     7,     8,    85,    83,
      11,    34,    13,    10,    15,    16,    39,    35,    36,    11,
      70,    71,   114,    24,    38,    26,    40,    37,    17,    30,
      19,    11,    12,    38,    50,   127,    86,   114,    88,    55,
      90,    11,    12,    17,    94,    19,    20,    21,    22,    23,
     127,   101,    15,    16,    25,    26,    38,    29,    11,    33,
      34,    35,    36,   155,    12,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     1,   155,    39,
      39,    37,    40,     7,     8,    11,    41,    11,    40,    13,
      44,    15,    16,    38,    40,     1,     9,    41,     4,     3,
      24,     7,     8,     1,    11,    11,    30,    13,    10,     7,
       8,    42,    37,    11,    43,    13,    38,    37,    24,     4,
      39,    39,    45,     1,    30,    17,    24,    19,    26,     7,
       8,    42,    30,    11,    11,    13,    12,    40,    16,    26,
      37,    33,    34,    35,    36,    17,    24,    19,    20,    21,
      22,    23,    30,    37,    37,    37,    16,    37,     7,    31,
      32,    33,    34,    35,    36,    17,    37,    19,    20,    21,
      22,    23,    44,    39,    53,    83,    46,    -1,    59,    31,
      32,    33,    34,    35,    36,    -1,    55,    17,    40,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    14,    -1,
      40,    17,    -1,    19,    20,    21,    22,    23,    17,    -1,
      19,    20,    21,    22,    23,    31,    32,    33,    34,    35,
      36,    -1,    31,    32,    33,    34,    35,    36,    37,    17,
      -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      17,    -1,    19,    20,    21,    22,    23,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    47,    48,     5,     6,    49,    50,    65,     0,
      57,    10,    49,    11,    51,    52,    67,     5,    58,    60,
      61,    65,    39,    43,    37,    38,    38,    29,    11,    53,
      54,    55,    65,    12,    51,    51,    39,    39,    40,    37,
      11,    56,    44,    40,    53,    55,    38,    41,    40,    56,
       9,    59,    62,    41,    63,    64,    65,     3,    68,    59,
      10,    63,    11,    66,    67,     1,     7,     8,    11,    13,
      24,    30,    69,    70,    71,    72,    73,    74,    75,    77,
      42,    68,    37,    38,    37,    39,    39,    39,    43,    12,
      18,    27,    28,    34,    39,    76,    77,    76,    76,     4,
      69,    45,    42,    66,    77,    76,    11,    12,    78,    79,
      76,    76,    12,    76,    14,    17,    19,    20,    21,    22,
      23,    31,    32,    33,    34,    35,    36,    25,    37,    76,
      40,    40,    38,    40,    44,    40,    69,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    69,
      37,    37,    37,    11,    12,    15,    16,    26,    69,    37,
      37,    16,    37
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 29:
#line 88 "Exprtree.y"
    { flag = 1; ;}
    break;

  case 30:
#line 89 "Exprtree.y"
    { flag = 0; ;}
    break;

  case 33:
#line 96 "Exprtree.y"
    { 
				  if(lookup((yyvsp[(1) - (1)])->name))
				  {
				 	sprintf(msg,"Variable '%s' redeclared",(yyvsp[(1) - (1)])->name);
					 SemError(msg);
				  } 
			
				  insert((yyvsp[(1) - (1)])->name,-1);
				  (yyvsp[(1) - (1)])->stptr=lookup((yyvsp[(1) - (1)])->name);
				  (yyvsp[(1) - (1)])->RetType = (yyvsp[(1) - (1)])->stptr->type;
				  if( flag )
					(yyvsp[(1) - (1)])->stptr->type = INT;
				  else
					(yyvsp[(1) - (1)])->stptr->type = BOOL;
						
				;}
    break;

  case 34:
#line 113 "Exprtree.y"
    {
				  if(lookup((yyvsp[(1) - (4)])->name))
				  {
				 	 sprintf(msg,"var redclare %s",(yyvsp[(1) - (4)])->name);
					 SemError(msg);
				  } 
					
				  insert((yyvsp[(1) - (4)])->name,-1);
				  (yyvsp[(1) - (4)])->stptr=lookup((yyvsp[(1) - (4)])->name);
				  (yyvsp[(1) - (4)])->RetType = (yyvsp[(1) - (4)])->stptr->type;
				
				  if((yyvsp[(3) - (4)])->value == 0)
				  {
					sprintf(msg, "Array index of variable '%s' set to zero", 
									(yyvsp[(1) - (4)])->name);
					SemError(msg);
				  }
				  (yyvsp[(1) - (4)])->stptr->size = (yyvsp[(3) - (4)])->value;
				  Count += ((yyvsp[(3) - (4)])->value - 1);
				  if( flag ) 
					(yyvsp[(1) - (4)])->stptr->type = INT;
				  else
				  	(yyvsp[(1) - (4)])->stptr->type = BOOL;
				;}
    break;

  case 35:
#line 141 "Exprtree.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 37:
#line 145 "Exprtree.y"
    { 
						  if((yyvsp[(2) - (2)])->NodeType == SEQ)
							(yyval) = ConnectNodes(MakeLeaf(SEQ, NULL), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
						  else
							(yyval) = ConnectNodes(MakeLeaf(SEQ, NULL), (yyvsp[(1) - (2)]), NULL);
						;}
    break;

  case 38:
#line 151 "Exprtree.y"
    { errflag = 1; yyerrok ; ;}
    break;

  case 39:
#line 154 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 40:
#line 155 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 41:
#line 156 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 42:
#line 157 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 43:
#line 158 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 44:
#line 161 "Exprtree.y"
    {
	 					  if((yyvsp[(3) - (5)])->RetType == BOOL)
	 					  	SemError("Cannot read to a boolean variable");
						  (yyval) = ConnectNodes(MakeLeaf(RD, NULL), (yyvsp[(3) - (5)]), NULL); 
						 ;}
    break;

  case 45:
#line 168 "Exprtree.y"
    { (yyval) = ConnectNodes(MakeLeaf(WE, NULL), (yyvsp[(3) - (5)]), NULL); ;}
    break;

  case 46:
#line 170 "Exprtree.y"
    {;}
    break;

  case 47:
#line 172 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (4)])->RetType != (yyvsp[(3) - (4)])->RetType)
							SemError("Assigning unmatched types");
				 
						  (yyval) = ConnectNodes(MakeLeaf(EQUAL, NULL), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
						;}
    break;

  case 48:
#line 181 "Exprtree.y"
    { 
						  if((yyvsp[(2) - (6)])->RetType != BOOL)
						  	SemError("Condition not a boolean type");
						  (yyval) = ConnectNodes(MakeLeaf(IF_THEN, NULL), (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)]));	
						;}
    break;

  case 49:
#line 187 "Exprtree.y"
    {
						  if((yyvsp[(2) - (8)])->RetType != BOOL)
						  	SemError("Condition not a boolean type");
						  (yyval) = ConnectNodes(MakeLeaf(IF_THEN_ELSE, NULL), (yyvsp[(2) - (8)]), (yyvsp[(6) - (8)]));
						  (yyval)->Mptr = (yyvsp[(4) - (8)]);
						;}
    break;

  case 50:
#line 194 "Exprtree.y"
    {
						  if((yyvsp[(2) - (6)])->RetType != BOOL)
						  	SemError("Condition not a boolean type");
						  (yyval) = ConnectNodes(MakeLeaf(DO_WHILE, NULL), (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)]));
						;}
    break;

  case 51:
#line 201 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]);			;}
    break;

  case 52:
#line 202 "Exprtree.y"
    { 
						  (yyvsp[(2) - (2)])->value = -1 * (yyvsp[(2) - (2)])->value;	
						  (yyval) = (yyvsp[(2) - (2)]);
						;}
    break;

  case 53:
#line 206 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]);			;}
    break;

  case 54:
#line 207 "Exprtree.y"
    { (yyval) = MakeLeaf(TRUE, NULL);	;}
    break;

  case 55:
#line 208 "Exprtree.y"
    { (yyval) = MakeLeaf(FALSE, NULL);	;}
    break;

  case 56:
#line 209 "Exprtree.y"
    { (yyval) = (yyvsp[(2) - (3)]); 			;}
    break;

  case 57:
#line 211 "Exprtree.y"
    {
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Adding unmatched types");
					  	  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Adding not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(PLUS, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
						  (yyval)->RetType = (yyvsp[(1) - (3)])->RetType; 	
						;}
    break;

  case 58:
#line 220 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Warning: Subtracting unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Subtraction not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(MINUS, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
						  (yyval)->RetType = (yyvsp[(1) - (3)])->RetType; 	
						;}
    break;

  case 59:
#line 229 "Exprtree.y"
    { 			
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Multiplying unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Multipliation not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(MUL, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
						  (yyval)->RetType = (yyvsp[(1) - (3)])->RetType; 	
						;}
    break;

  case 60:
#line 238 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Dividing unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Division not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(DIV, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
						  (yyval)->RetType = (yyvsp[(1) - (3)])->RetType; 	
						;}
    break;

  case 61:
#line 247 "Exprtree.y"
    {
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(LT, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 62:
#line 255 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(GT, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 63:
#line 264 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(GTE, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 64:
#line 273 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(LTE, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 65:
#line 282 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");

						  (yyval) = ConnectNodes(MakeLeaf(NE, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 66:
#line 288 "Exprtree.y"
    {
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");

						  (yyval) = ConnectNodes(MakeLeaf(ISEQUAL, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 67:
#line 294 "Exprtree.y"
    {
						   if((yyvsp[(2) - (2)])->RetType != BOOL)
							SemError("Expression not of boolean type");

						  (yyval) = ConnectNodes(MakeLeaf(NOT, NULL) , (yyvsp[(2) - (2)]), NULL); 	
						;}
    break;

  case 68:
#line 300 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType != BOOL)
							SemError("AND not defined on integer type");

						  (yyval) = ConnectNodes(MakeLeaf(AND, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));	
						;}
    break;

  case 69:
#line 308 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType != BOOL)
							SemError("OR not defined on integer type");

						  (yyval) = ConnectNodes(MakeLeaf(OR, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 	
						;}
    break;

  case 70:
#line 319 "Exprtree.y"
    { 
				  (yyvsp[(1) - (1)])->stptr = lookup((yyvsp[(1) - (1)])->name);
				  if((yyvsp[(1) - (1)])->stptr == NULL)
				  {
					sprintf(msg, "Variable '%s' undeclared", (yyvsp[(1) - (1)])->name);
					yyerror(msg);
				  }
				  else
				  {
				   (yyvsp[(1) - (1)])->RetType = (yyvsp[(1) - (1)])->stptr->type;
				  
				   if((yyvsp[(1) - (1)])->stptr->size != -1) //That is, the variable is an array
				   {
					sprintf(msg, "Array variable '%s' accessed without index", 
					(yyvsp[(1) - (1)])->stptr->name);
					yyerror(msg);
				   }
				  }
				   (yyval) = (yyvsp[(1) - (1)]);
				;}
    break;

  case 71:
#line 340 "Exprtree.y"
    {
				  (yyvsp[(1) - (4)])->stptr = lookup((yyvsp[(1) - (4)])->name);
				  if((yyvsp[(1) - (4)])->stptr == NULL)
				  {
					sprintf(msg, "Variable '%s' undeclared", (yyvsp[(1) - (4)])->name);
					SemError(msg);
				  }
				  (yyvsp[(1) - (4)])->RetType = (yyvsp[(1) - (4)])->stptr->type;
				  
				  if((yyvsp[(3) - (4)])->RetType == BOOL)
				  	SemError("Array index cannot be boolean");
				  else if((yyvsp[(1) - (4)])->stptr->size == -1) //That is, the variable is not an array
				  {
					sprintf(msg, "Variable '%s' not an array", (yyvsp[(1) - (4)])->stptr->name);
					SemError(msg);
				  }
				  (yyval) = ConnectNodes(MakeLeaf(ARRAY, (yyvsp[(1) - (4)])->name), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				  (yyval)->RetType = (yyvsp[(1) - (4)])->RetType;
				;}
    break;


/* Line 1267 of yacc.c.  */
#line 1938 "Exprtree.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 367 "Exprtree.y"


void yyerror(char* err)
{
	printf("%s at line number: %d\n", err, Lineno);
}

void SemError(char* err)
{
	yyerror(err);
	exit(0);
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("Usage Eval <Input filename> <Output filename>\n");
		return 0;
	}

	yyin = fopen(argv[1], "r");
	if(!yyin)
	{
		printf("\nFile %s not found\n", argv[1]);
		return 0;
	}

	Fp = fopen(argv[2], "w");
	if(!Fp){
		printf("File cannot be created\n");
		exit(0);
	}

	Lineno	= 1;	// Line no: starts from 1.
	Count   = 0;	// For binding field in Symbol table.
	ArrFlag = 1;	// So that array contents will be loaded instead of just the binding.
	Label	= 0;	// Label count starts from 0
	fprintf(Fp, "START\n");
	yyparse();
	fprintf(Fp, "HALT");
	fclose(Fp);
	fclose(yyin);
	return 0;
		/*input:	
		|	BEG decl_sec stmt_sec END { if(!errflag) {Print($3,0); CodeGen($3);} }
		;*/
}

