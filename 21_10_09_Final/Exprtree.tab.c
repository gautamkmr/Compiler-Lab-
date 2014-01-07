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
	int yylex();
	void yyerror( char* );
	
	char msg[MSGLEN];
	Argstruct *tmp1, *tmp2;
	Argstruct* original_list;
	NODPTR expr_head;
	GSymbolTable* tmp;

	int errflag;		/* To mark the occurance of any compilation error. 		*/
	int type_flag;		/* To store type of variables and arrays 			*/
	int arg_flag;		/* To store argument types of arguments in function definition.	*/
	int func_type_flag ;	/* To store the return type of functions in function definition */
	
	void SemError(char*);
	char* print_name(int);


	/* 
		Match arguments of the two passed argument list and reports error
	 * Arguments:
	 *	ARG1, ARG2 : Specifies the argument lists to be matched.
	 *    
	 * Precondition	:	---
	 *			
	 * Postcondition:	Arguments are checked for name and type equivalence.
	 *			Any errors will be reported as semantic errors.
	 * Comments	:	---
	 */
        void match_arguments(Argstruct*, Argstruct*);


	/*
		Match parameters of the two passed parameter list and reports error 
	 * Arguments:
	 *	ARG1, ARG2 : Specifies the parameter lists to be matched.
	 *    
	 * Precondition	:	---
	 *			
	 * Postcondition:	Any errors will be reported as semantic errors.
	 *
	 * Comments	:	Parameters are checked only for type equivalence.
	 */
        void match_parameters(Argstruct*, Argstruct*);
	
	/*
		Initiates the program by initialising global variables
	 * Precondition	:	---
	 *			
	 * Postcondition:	---
	 *
	 * Comments	:	---
	 */	
        void initiate();

	/*
		Dealloactes all dynamically allocated memory and closes all open files.
	 * Precondition	:	---
	 *			
	 * Postcondition:	---
	 *
	 * Comments	:	---
	 */	
        void terminate();


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
#line 241 "Exprtree.tab.c"

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
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

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
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      42,    43,    35,    33,    39,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      31,    46,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      25,    27,    31,    35,    37,    42,    47,    48,    50,    54,
      56,    59,    61,    63,    65,    69,    70,    73,    86,    88,
      90,    92,    94,    98,   110,   112,   116,   117,   120,   124,
     126,   128,   130,   134,   136,   137,   140,   143,   145,   147,
     149,   151,   157,   163,   168,   175,   184,   191,   196,   197,
     199,   201,   205,   207,   209,   212,   214,   216,   218,   222,
     226,   230,   234,   238,   242,   246,   250,   254,   258,   262,
     266,   269,   273,   277,   279,   281
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    61,    67,    -1,     9,    50,    10,
      -1,    -1,    51,    50,    -1,    52,    53,    38,    -1,     5,
      -1,     6,    -1,    54,    -1,    55,    -1,    54,    39,    53,
      -1,    55,    39,    53,    -1,    11,    -1,    11,    40,    12,
      41,    -1,    11,    42,    56,    43,    -1,    -1,    57,    -1,
      57,    38,    58,    -1,    58,    -1,    59,    60,    -1,     5,
      -1,     6,    -1,    11,    -1,    11,    39,    60,    -1,    -1,
      61,    62,    -1,    63,    64,    42,    65,    43,    44,    69,
       3,    75,    66,     4,    45,    -1,     5,    -1,     6,    -1,
      11,    -1,    56,    -1,    30,    85,    38,    -1,    63,    68,
      42,    43,    44,    69,     3,    75,    66,     4,    45,    -1,
      29,    -1,     9,    70,    10,    -1,    -1,    71,    70,    -1,
      72,    73,    38,    -1,     5,    -1,     6,    -1,    74,    -1,
      74,    39,    73,    -1,    11,    -1,    -1,    76,    75,    -1,
       1,    38,    -1,    79,    -1,    77,    -1,    78,    -1,    80,
      -1,     7,    42,    86,    43,    38,    -1,     8,    42,    85,
      43,    38,    -1,    86,    46,    85,    38,    -1,    13,    85,
      14,    75,    16,    38,    -1,    13,    85,    14,    75,    15,
      75,    16,    38,    -1,    24,    85,    25,    75,    26,    38,
      -1,    11,    42,    82,    43,    -1,    -1,    83,    -1,    84,
      -1,    84,    39,    83,    -1,    85,    -1,    12,    -1,    34,
      12,    -1,    86,    -1,    27,    -1,    28,    -1,    42,    85,
      43,    -1,    85,    33,    85,    -1,    85,    34,    85,    -1,
      85,    35,    85,    -1,    85,    36,    85,    -1,    85,    31,
      85,    -1,    85,    32,    85,    -1,    85,    37,    85,    -1,
      85,    22,    85,    -1,    85,    21,    85,    -1,    85,    23,
      85,    -1,    85,    20,    85,    -1,    18,    85,    -1,    85,
      17,    85,    -1,    85,    19,    85,    -1,    81,    -1,    11,
      -1,    11,    40,    85,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   100,   103,   104,   107,   110,   111,   114,
     115,   116,   117,   120,   139,   168,   192,   193,   196,   197,
     200,   203,   204,   207,   208,   211,   212,   215,   228,   229,
     232,   266,   285,   293,   317,   327,   330,   331,   334,   337,
     338,   341,   342,   345,   356,   357,   363,   366,   367,   368,
     369,   372,   379,   382,   390,   396,   403,   411,   440,   441,
     444,   445,   448,   470,   471,   475,   476,   477,   478,   480,
     489,   498,   507,   516,   524,   532,   541,   550,   559,   566,
     572,   578,   586,   594,   598,   624
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
  "'*'", "'/'", "'%'", "';'", "','", "'['", "']'", "'('", "')'", "'{'",
  "'}'", "'='", "$accept", "Prog", "Gdecl_sec", "Gdecl_list", "Gdecl",
  "ret_type", "Glist", "Gid", "func", "arg_list", "arg_list1", "arg",
  "arg_type", "var_list", "Fdef_sec", "Fdef", "func_ret_type", "func_name",
  "FargList", "ret_stmt", "MainBlock", "main", "Ldecl_sec", "Ldecl_list",
  "Ldecl", "type", "Lid_list", "Lid", "stmt_list", "statement",
  "read_stmt", "write_stmt", "assign_stmt", "cond_stmt", "func_call",
  "param_list", "param_list1", "para", "expr", "var_expr", 0
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
     285,    60,    62,    43,    45,    42,    47,    37,    59,    44,
      91,    93,    40,    41,   123,   125,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    50,    51,    52,    52,    53,
      53,    53,    53,    54,    54,    55,    56,    56,    57,    57,
      58,    59,    59,    60,    60,    61,    61,    62,    63,    63,
      64,    65,    66,    67,    68,    69,    70,    70,    71,    72,
      72,    73,    73,    74,    75,    75,    75,    76,    76,    76,
      76,    77,    78,    79,    80,    80,    80,    81,    82,    82,
      83,    83,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     0,     2,     3,     1,     1,     1,
       1,     3,     3,     1,     4,     4,     0,     1,     3,     1,
       2,     1,     1,     1,     3,     0,     2,    12,     1,     1,
       1,     1,     3,    11,     1,     3,     0,     2,     3,     1,
       1,     1,     3,     1,     0,     2,     2,     1,     1,     1,
       1,     5,     5,     4,     6,     8,     6,     4,     0,     1,
       1,     3,     1,     1,     2,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,    25,     7,     8,     0,     4,     0,     1,
       0,     3,     5,    13,     0,     9,    10,    28,    29,    26,
       0,     2,     0,    16,     6,     0,     0,    30,    34,     0,
       0,     0,    21,    22,     0,    17,    19,     0,    11,    12,
      16,     0,    14,    15,     0,    23,    20,    31,     0,     0,
      18,     0,     0,     0,    24,     0,    36,     0,     0,    39,
      40,     0,    36,     0,     0,     0,    35,    37,    43,     0,
      41,     0,     0,     0,    84,     0,     0,     0,     0,    48,
      49,    47,    50,     0,     0,    38,     0,    46,     0,     0,
       0,    84,    63,     0,    66,    67,     0,     0,    83,     0,
      65,     0,     0,     0,    45,     0,     0,    42,     0,     0,
       0,    58,    80,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,    59,    60,
      62,    68,     0,    81,    82,    79,    77,    76,    78,    73,
      74,    69,    70,    71,    72,    75,     0,    32,    33,    53,
      27,    51,    52,    57,     0,     0,     0,     0,    61,     0,
      54,    56,     0,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     7,     8,    14,    15,    16,    34,
      35,    36,    37,    46,    10,    19,    20,    29,    48,   103,
      21,    30,    57,    61,    62,    63,    69,    70,    77,    78,
      79,    80,    81,    82,    98,   137,   138,   139,   140,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -65
static const yytype_int16 yypact[] =
{
       4,    -2,    17,   -65,   -65,   -65,    24,    -2,    28,   -65,
      14,   -65,   -65,   -32,     9,     3,    25,   -65,   -65,   -65,
      -4,   -65,    69,    44,   -65,    28,    28,   -65,   -65,    40,
      41,    43,   -65,   -65,    42,    50,   -65,    78,   -65,   -65,
      44,    53,   -65,   -65,    44,    58,   -65,   -65,    55,    60,
     -65,    78,    72,    90,   -65,    90,    49,   110,   114,   -65,
     -65,   109,    49,   119,    99,    99,   -65,   -65,   -65,    83,
      93,    96,   101,   102,    95,    -6,    -6,   115,    79,   -65,
     -65,   -65,   -65,   100,   115,   -65,   119,   -65,   143,    -6,
      -6,   -31,   -65,    -6,   -65,   -65,   144,    -6,   -65,   180,
     -65,   259,    -6,   151,   -65,    -6,   153,   -65,   116,   105,
     155,    -6,   -65,   -65,   130,    22,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,   107,
     215,   113,   237,   123,   122,   131,   -65,   127,   -65,   132,
     266,   -65,    16,   -65,   -65,    26,    26,    26,    26,   287,
     287,   226,   226,    74,    74,    -1,   154,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,    -6,   217,   141,   145,   -65,   165,
     -65,   -65,   146,   -65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   -65,   175,   -65,   -65,    32,   -65,   -65,   158,
     -65,   149,   -65,   134,   -65,   -65,   -65,   -65,   -65,   111,
     -65,   -65,   150,   142,   -65,   -65,   120,   -65,   -63,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,    45,   -65,   -49,   -64
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -45
static const yytype_int16 yytable[] =
{
      83,    83,    84,     4,     5,    91,    92,    27,    22,    90,
      23,   111,    93,     1,    83,   104,   116,     9,   117,    17,
      18,    94,    95,    71,   108,    28,    99,   101,    96,    72,
      73,   165,   166,    74,    11,    75,    97,   -44,   -44,    13,
     109,   110,    25,   116,   112,   117,    76,    24,   114,    32,
      33,    83,   142,   130,    59,    60,   132,    38,    39,   124,
     125,   126,   127,   128,    26,    83,   156,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      71,    31,    40,    41,    42,    43,    72,    73,    44,    45,
      74,   116,    75,   117,   -44,   -44,    49,    51,    52,    56,
      71,    83,   169,    76,    53,   -44,    72,    73,    71,   -44,
      74,   128,    75,    64,    72,    73,    55,    65,    74,    66,
      75,    85,   116,    76,   117,   118,   119,   120,   121,   -44,
      68,    76,    86,   -44,    87,    90,   122,   123,   124,   125,
     126,   127,   128,    88,    89,   102,   105,   116,   135,   117,
     118,   119,   120,   121,    74,   131,   113,   133,   158,   134,
     161,   122,   123,   124,   125,   126,   127,   128,   160,   162,
     163,   164,   116,   141,   117,   118,   119,   120,   121,   170,
     167,   172,    12,   171,   173,    54,   122,   123,   124,   125,
     126,   127,   128,    50,   115,   106,   136,   116,    47,   117,
     118,   119,   120,   121,    67,    58,   107,     0,     0,   168,
       0,   122,   123,   124,   125,   126,   127,   128,    71,     0,
       0,     0,     0,     0,    72,    73,     0,     0,    74,     0,
      75,     0,   116,   -44,   117,   118,   119,   120,   121,     0,
       0,    76,     0,   116,     0,   117,   122,   123,   124,   125,
     126,   127,   128,   157,   116,     0,   117,   118,   119,   120,
     121,   126,   127,   128,     0,     0,     0,     0,   122,   123,
     124,   125,   126,   127,   128,   159,   116,     0,   117,   118,
     119,   120,   121,   116,   129,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   122,   123,   124,
     125,   126,   127,   128,   116,     0,   117,   118,   119,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   128
};

static const yytype_int16 yycheck[] =
{
      64,    65,    65,     5,     6,    11,    12,    11,    40,    40,
      42,    42,    18,     9,    78,    78,    17,     0,    19,     5,
       6,    27,    28,     1,    88,    29,    75,    76,    34,     7,
       8,    15,    16,    11,    10,    13,    42,    15,    16,    11,
      89,    90,    39,    17,    93,    19,    24,    38,    97,     5,
       6,   115,   115,   102,     5,     6,   105,    25,    26,    33,
      34,    35,    36,    37,    39,   129,   129,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
       1,    12,    42,    42,    41,    43,     7,     8,    38,    11,
      11,    17,    13,    19,    15,    16,    43,    39,    43,     9,
       1,   165,   165,    24,    44,    26,     7,     8,     1,    30,
      11,    37,    13,     3,     7,     8,    44,     3,    11,    10,
      13,    38,    17,    24,    19,    20,    21,    22,    23,    30,
      11,    24,    39,    26,    38,    40,    31,    32,    33,    34,
      35,    36,    37,    42,    42,    30,    46,    17,    43,    19,
      20,    21,    22,    23,    11,     4,    12,     4,    45,    43,
      38,    31,    32,    33,    34,    35,    36,    37,    45,    38,
      43,    39,    17,    43,    19,    20,    21,    22,    23,    38,
      26,    16,     7,    38,    38,    51,    31,    32,    33,    34,
      35,    36,    37,    44,    14,    84,    41,    17,    40,    19,
      20,    21,    22,    23,    62,    55,    86,    -1,    -1,   164,
      -1,    31,    32,    33,    34,    35,    36,    37,     1,    -1,
      -1,    -1,    -1,    -1,     7,     8,    -1,    -1,    11,    -1,
      13,    -1,    17,    16,    19,    20,    21,    22,    23,    -1,
      -1,    24,    -1,    17,    -1,    19,    31,    32,    33,    34,
      35,    36,    37,    38,    17,    -1,    19,    20,    21,    22,
      23,    35,    36,    37,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    17,    -1,    19,    20,
      21,    22,    23,    17,    25,    19,    20,    21,    22,    23,
      31,    32,    33,    34,    35,    36,    37,    31,    32,    33,
      34,    35,    36,    37,    17,    -1,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    48,    49,     5,     6,    50,    51,    52,     0,
      61,    10,    50,    11,    53,    54,    55,     5,     6,    62,
      63,    67,    40,    42,    38,    39,    39,    11,    29,    64,
      68,    12,     5,     6,    56,    57,    58,    59,    53,    53,
      42,    42,    41,    43,    38,    11,    60,    56,    65,    43,
      58,    39,    43,    44,    60,    44,     9,    69,    69,     5,
       6,    70,    71,    72,     3,     3,    10,    70,    11,    73,
      74,     1,     7,     8,    11,    13,    24,    75,    76,    77,
      78,    79,    80,    86,    75,    38,    39,    38,    42,    42,
      40,    11,    12,    18,    27,    28,    34,    42,    81,    85,
      86,    85,    30,    66,    75,    46,    66,    73,    86,    85,
      85,    42,    85,    12,    85,    14,    17,    19,    20,    21,
      22,    23,    31,    32,    33,    34,    35,    36,    37,    25,
      85,     4,    85,     4,    43,    43,    41,    82,    83,    84,
      85,    43,    75,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    75,    38,    45,    38,
      45,    38,    38,    43,    39,    15,    16,    26,    83,    75,
      38,    38,    16,    38
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
        case 7:
#line 110 "Exprtree.y"
    { type_flag = INT;  ;}
    break;

  case 8:
#line 111 "Exprtree.y"
    { type_flag = BOOL; ;}
    break;

  case 13:
#line 120 "Exprtree.y"
    {
					   tmp = Glookup((yyvsp[(1) - (1)])->name);
					   if(tmp)
					   {
					     if(tmp->type == FUNC)
					     {
					     	sprintf(msg, "A function with the name '%s' already exists",
					     		  tmp->name);
					     	SemError(msg);
					     }
					     else
					     {
					        sprintf(msg, "Variable '%s' redeclared",(yyvsp[(1) - (1)])->name);
  					        SemError(msg);
  					     }
					   }
					   else
					     Ginsert((yyvsp[(1) - (1)])->name, type_flag, -1, -1, NULL); 
					;}
    break;

  case 14:
#line 139 "Exprtree.y"
    {   
					    tmp = Glookup((yyvsp[(1) - (4)])->name);
					    if(tmp)
					    {
					      if(tmp->type == FUNC)
					      {
					     	sprintf(msg, "A function with the name '%s' already exists",
					     		  tmp->name);
					     	SemError(msg);
					      }
					      else
					      {
  					        sprintf(msg,"Array '%s' redeclared",(yyvsp[(1) - (4)])->name);
					        SemError(msg);
					      }
					    }
					    else if((yyvsp[(3) - (4)])->value <= 0)
					    {
					      sprintf(msg, "Array '%s' declared with non-positive index", (yyvsp[(1) - (4)])->name);
					      SemError(msg);
					    }	
		                    	    else
		                      	    {
		                      	      Ginsert((yyvsp[(1) - (4)])->name, type_flag, -1, (yyvsp[(3) - (4)])->value, NULL);
		                      	      GCount += ((yyvsp[(3) - (4)])->value - 1);
		                      	    }
					;}
    break;

  case 15:
#line 169 "Exprtree.y"
    {
					    tmp = Glookup((yyvsp[(1) - (4)])->name);
					    if(tmp)
					    {
					      if(tmp->type == FUNC)
					      {
					        sprintf(msg,"Function '%s' redeclared",(yyvsp[(1) - (4)])->name);
					        SemError(msg);
					      }
					      else
					      {
					        sprintf(msg,"A variable with name '%s' already exists",(yyvsp[(1) - (4)])->name);
					        SemError(msg);
					      }
					    }
					    else
					    {
					      Ginsert((yyvsp[(1) - (4)])->name, FUNC, type_flag, -1, list_head);
					      list_head = NULL;
					    }
					;}
    break;

  case 21:
#line 203 "Exprtree.y"
    { arg_flag = INT;  ;}
    break;

  case 22:
#line 204 "Exprtree.y"
    { arg_flag = BOOL; ;}
    break;

  case 23:
#line 207 "Exprtree.y"
    { createList((yyvsp[(1) - (1)])->name, arg_flag);	;}
    break;

  case 24:
#line 208 "Exprtree.y"
    { createList((yyvsp[(1) - (3)])->name, arg_flag);	;}
    break;

  case 27:
#line 216 "Exprtree.y"
    {	
					  (yyval) = ConnectNodes(MakeLeaf(FUNC_DEF, (yyvsp[(2) - (12)])->name), (yyvsp[(9) - (12)]), (yyvsp[(10) - (12)]));
					  Print((yyval), 0);
					  
					  if(!errflag)					  
					  	CodeGen((yyval));
					  
					  free(Lhead);
					  Lhead = NULL;
					;}
    break;

  case 28:
#line 228 "Exprtree.y"
    { func_type_flag = INT;  ;}
    break;

  case 29:
#line 229 "Exprtree.y"
    { func_type_flag = BOOL;  ;}
    break;

  case 30:
#line 232 "Exprtree.y"
    {
					  (yyval)->Gstptr = Glookup((yyvsp[(1) - (1)])->name);
					  if(!(yyval)->Gstptr)
					  {
					     sprintf(msg,"Function '%s' is not declared", (yyvsp[(1) - (1)])->name);
					     SemError(msg);
					  }
					  else if((yyval)->Gstptr->type != FUNC)
					  {
					     sprintf(msg,"'%s' is declared but not a function",(yyvsp[(1) - (1)])->name);
					     SemError(msg);
					  }
					  else if((yyval)->Gstptr->isFuncDefined)
					  {
					     sprintf(msg,"Function '%s' is re-defined", (yyvsp[(1) - (1)])->name);
					     SemError(msg);
					  }	
					  else if((yyval)->Gstptr->FuncRetType != func_type_flag)
					  {
					     sprintf(msg,"Return type of function '%s' is not matching",(yyvsp[(1) - (1)])->name);
					     SemError(msg);
					  }
					  else
					  {
					     (yyval)->Gstptr->isFuncDefined = 1; // To mark that the function is defined.
					     original_list = (yyval)->Gstptr->arglist;
					     strcpy(function_name, (yyvsp[(1) - (1)])->name);
					  }
					  (yyval) = (yyvsp[(1) - (1)]);
					  LCount = 1;
				  	  L_arg_count = -1;
					;}
    break;

  case 31:
#line 266 "Exprtree.y"
    { 
					  match_arguments(original_list, list_head);
					  while(original_list)
					  {
				  	    if(Llookup(original_list->name))
					    {
					      sprintf(msg,"Argument '%s' is redeclared", original_list->name);
				    	      SemError(msg);
				  	    }
					    else
					      Linsert(original_list->name, original_list->type, PARAM);
				  	    original_list = original_list->next;
					  }
					  // Thus 'original_list' will be NULL.
					  // Cannot de-allocate list_head here.
					  list_head = NULL;
					;}
    break;

  case 32:
#line 285 "Exprtree.y"
    { 
					  if((yyvsp[(2) - (3)])->RetType != func_type_flag)
					  	SemError("Return type mismatch");
					  else
						(yyval) = ConnectNodes(MakeLeaf(RET, NULL), (yyvsp[(2) - (3)]), NULL);
					;}
    break;

  case 33:
#line 294 "Exprtree.y"
    {
				  	  tmp = Ghead;
				  	  while(tmp)
				  	  {
				  	  	if(tmp->type == FUNC && !tmp->isFuncDefined)
				  	  	{
				  	  		printf("Function '%s' is declared but not defined\n", tmp->name);
				  	  		errflag = 1;
				  	  	}
				  	  	tmp = tmp->next;
				  	  }
					  
					  (yyval) = ConnectNodes(MakeLeaf(MAIN_CALL, "main"), (yyvsp[(8) - (11)]), (yyvsp[(9) - (11)]));
				  	  Print((yyval), 0);
				  	  
				  	  if(!errflag)
				  	  	CodeGen((yyval));
				  	 
				  	  free(Lhead);		// Free the local symbol table.
				  	  Lhead = NULL;
					;}
    break;

  case 34:
#line 317 "Exprtree.y"
    { 
					  if(func_type_flag != INT)
					  	SemError("Main should have return type as integer");
					  /* LCount should start from 1. Since the location pointed by SP will global data.*/
					  LCount = 1;		
				  	  L_arg_count = -1;
					  strcpy(function_name, "main");
					;}
    break;

  case 39:
#line 337 "Exprtree.y"
    { type_flag = INT; ;}
    break;

  case 40:
#line 338 "Exprtree.y"
    { type_flag = BOOL; ;}
    break;

  case 43:
#line 345 "Exprtree.y"
    {
						  if(Llookup((yyvsp[(1) - (1)])->name))
						  {
						 	sprintf(msg,"Variable '%s' redeclared",(yyvsp[(1) - (1)])->name);
							SemError(msg);
						  } 
						  else
						  	Linsert((yyvsp[(1) - (1)])->name,type_flag, L_VAR);
						;}
    break;

  case 44:
#line 356 "Exprtree.y"
    { (yyval) = ConnectNodes(MakeLeaf(SEQ, NULL), NULL, NULL); ;}
    break;

  case 45:
#line 357 "Exprtree.y"
    { 
						  if((yyvsp[(2) - (2)])->NodeType == SEQ)
							(yyval) = ConnectNodes(MakeLeaf(SEQ, NULL), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
						  else
							(yyval) = ConnectNodes(MakeLeaf(SEQ, NULL), (yyvsp[(1) - (2)]), NULL);
						;}
    break;

  case 46:
#line 363 "Exprtree.y"
    { errflag = 1; yyerrok ; ;}
    break;

  case 47:
#line 366 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 48:
#line 367 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 49:
#line 368 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 50:
#line 369 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 51:
#line 372 "Exprtree.y"
    {
	 					  if((yyvsp[(3) - (5)])->RetType == BOOL)
	 					  	SemError("Cannot read to a boolean variable");
						  (yyval) = ConnectNodes(MakeLeaf(RD, NULL), (yyvsp[(3) - (5)]), NULL); 
						 ;}
    break;

  case 52:
#line 379 "Exprtree.y"
    { (yyval) = ConnectNodes(MakeLeaf(WE, NULL), (yyvsp[(3) - (5)]), NULL); ;}
    break;

  case 53:
#line 382 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (4)])->RetType != (yyvsp[(3) - (4)])->RetType)
							SemError("Assigning unmatched types");
				 
						  (yyval) = ConnectNodes(MakeLeaf(EQUAL, NULL), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
						;}
    break;

  case 54:
#line 391 "Exprtree.y"
    { 
						  if((yyvsp[(2) - (6)])->RetType != BOOL)
						  	SemError("Condition not a boolean type");
						  (yyval) = ConnectNodes(MakeLeaf(IF_THEN, NULL), (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)]));	
						;}
    break;

  case 55:
#line 397 "Exprtree.y"
    {
						  if((yyvsp[(2) - (8)])->RetType != BOOL)
						  	SemError("Condition not a boolean type");
						  (yyval) = ConnectNodes(MakeLeaf(IF_THEN_ELSE, NULL), (yyvsp[(2) - (8)]), (yyvsp[(6) - (8)]));
						  (yyval)->Mptr = (yyvsp[(4) - (8)]);
						;}
    break;

  case 56:
#line 404 "Exprtree.y"
    {
						  if((yyvsp[(2) - (6)])->RetType != BOOL)
						  	SemError("Condition not a boolean type");
						  (yyval) = ConnectNodes(MakeLeaf(DO_WHILE, NULL), (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)]));
						;}
    break;

  case 57:
#line 412 "Exprtree.y"
    {
						   (yyvsp[(1) - (4)])->Gstptr = Glookup((yyvsp[(1) - (4)])->name);
						   
						   if(!(yyvsp[(1) - (4)])->Gstptr)
						   {
						     sprintf(msg,"Function '%s' is not declared", (yyvsp[(1) - (4)])->name);
						     SemError(msg);
						   }
						   else if((yyvsp[(1) - (4)])->Gstptr->type != FUNC)
						   {
						     sprintf(msg,"'%s' is declared but not a function",(yyvsp[(1) - (4)])->name);
						     SemError(msg);
						   }
						   else
						   {
						     match_parameters((yyvsp[(1) - (4)])->Gstptr->arglist, list_head);
						     
						     (yyvsp[(1) - (4)])->list = expr_head;
						     
						     (yyval) = ConnectNodes(MakeLeaf(FUNC, (yyvsp[(1) - (4)])->name), (yyvsp[(1) - (4)]), NULL);
						     (yyval)->list = expr_head;
						     (yyval)->RetType = (yyvsp[(1) - (4)])->Gstptr->FuncRetType;
						   }
						   expr_head = NULL;
						   list_head = NULL;
						;}
    break;

  case 62:
#line 448 "Exprtree.y"
    { 
						  /* We need to pass the return types of each parameter
						     for checking type equivalence.			
						  */ 
						  createList("\0", (yyvsp[(1) - (1)])->RetType);	
						  
						  /* This is to obtain the ASTs corresponding to the induvidual
						     parameters.We need them for code generation.
						  */
						  if(expr_head == NULL)
						  {
						  	expr_head = (yyvsp[(1) - (1)]);
						  	expr_head->next = NULL;
						  }
						  else
						  {
						  	(yyvsp[(1) - (1)])->next = expr_head;
						  	expr_head = (yyvsp[(1) - (1)]);
						  }
						;}
    break;

  case 63:
#line 470 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]);			;}
    break;

  case 64:
#line 471 "Exprtree.y"
    { 
						  (yyvsp[(2) - (2)])->value = -1 * (yyvsp[(2) - (2)])->value;	
						  (yyval) = (yyvsp[(2) - (2)]);
						;}
    break;

  case 65:
#line 475 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]);			;}
    break;

  case 66:
#line 476 "Exprtree.y"
    { (yyval) = MakeLeaf(TRUE, NULL);	;}
    break;

  case 67:
#line 477 "Exprtree.y"
    { (yyval) = MakeLeaf(FALSE, NULL);	;}
    break;

  case 68:
#line 478 "Exprtree.y"
    { (yyval) = (yyvsp[(2) - (3)]); 			;}
    break;

  case 69:
#line 480 "Exprtree.y"
    {
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Adding unmatched types");
					  	  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Adding not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(PLUS, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
						  (yyval)->RetType = (yyvsp[(1) - (3)])->RetType; 	
						;}
    break;

  case 70:
#line 489 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Warning: Subtracting unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Subtraction not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(MINUS, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
						  (yyval)->RetType = (yyvsp[(1) - (3)])->RetType; 	
						;}
    break;

  case 71:
#line 498 "Exprtree.y"
    { 			
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Multiplying unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Multipliation not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(MUL, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
						  (yyval)->RetType = (yyvsp[(1) - (3)])->RetType; 	
						;}
    break;

  case 72:
#line 507 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Dividing unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Division not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(DIV, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
						  (yyval)->RetType = (yyvsp[(1) - (3)])->RetType; 	
						;}
    break;

  case 73:
#line 516 "Exprtree.y"
    {
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(LT, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 74:
#line 524 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(GT, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 75:
#line 532 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Moding unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Modulus not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(MOD, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
						  (yyval)->RetType = (yyvsp[(1) - (3)])->RetType;
						;}
    break;

  case 76:
#line 542 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(GTE, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 77:
#line 551 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  (yyval) = ConnectNodes(MakeLeaf(LTE, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 78:
#line 560 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");

						  (yyval) = ConnectNodes(MakeLeaf(NE, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 79:
#line 566 "Exprtree.y"
    {
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");

						  (yyval) = ConnectNodes(MakeLeaf(ISEQUAL, NULL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
						;}
    break;

  case 80:
#line 572 "Exprtree.y"
    {
						   if((yyvsp[(2) - (2)])->RetType != BOOL)
							SemError("Expression not of boolean type");

						  (yyval) = ConnectNodes(MakeLeaf(NOT, NULL) , (yyvsp[(2) - (2)]), NULL); 	
						;}
    break;

  case 81:
#line 578 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType != BOOL)
							SemError("AND not defined on integer type");

						  (yyval) = ConnectNodes(MakeLeaf(AND, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));	
						;}
    break;

  case 82:
#line 586 "Exprtree.y"
    { 
						  if((yyvsp[(1) - (3)])->RetType != (yyvsp[(3) - (3)])->RetType)
							SemError("Comparison between unmatched types");
						  if((yyvsp[(1) - (3)])->RetType != BOOL)
							SemError("OR not defined on integer type");

						  (yyval) = ConnectNodes(MakeLeaf(OR, NULL) , (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 	
						;}
    break;

  case 83:
#line 594 "Exprtree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 84:
#line 598 "Exprtree.y"
    { 
				  (yyvsp[(1) - (1)])->Lstptr = Llookup((yyvsp[(1) - (1)])->name);
				  if((yyvsp[(1) - (1)])->Lstptr == NULL)
				  {
					(yyvsp[(1) - (1)])->Gstptr = Glookup((yyvsp[(1) - (1)])->name);
					if((yyvsp[(1) - (1)])->Gstptr == NULL)
					{
					   sprintf(msg, "Variable '%s' undeclared", (yyvsp[(1) - (1)])->name);
					   SemError(msg);
				        }
				        else if((yyvsp[(1) - (1)])->Gstptr->type == FUNC)
				        {
			        	   sprintf(msg, "Cannot use function name '%s'", (yyvsp[(1) - (1)])->name);
					   SemError(msg);
					}
					else if((yyvsp[(1) - (1)])->Gstptr->size != -1)	// That is the variable is actually an array.
				 	{
				  	   sprintf(msg, "Array '%s' accessed without index", (yyvsp[(1) - (1)])->name);
					   SemError(msg);
					}
					(yyvsp[(1) - (1)])->RetType = (yyvsp[(1) - (1)])->Gstptr->type;
				  }
				  else
					(yyvsp[(1) - (1)])->RetType = (yyvsp[(1) - (1)])->Lstptr->type;
				  (yyval) = (yyvsp[(1) - (1)]);
				;}
    break;

  case 85:
#line 625 "Exprtree.y"
    {
				  (yyvsp[(1) - (4)])->Gstptr = Glookup((yyvsp[(1) - (4)])->name);
				  if((yyvsp[(1) - (4)])->Gstptr == NULL)
				  {
					sprintf(msg, "Array '%s' undeclared", (yyvsp[(1) - (4)])->name);
					SemError(msg);
				  }
				  else if((yyvsp[(1) - (4)])->Gstptr->type == FUNC)
			          {
				       	sprintf(msg, "Cannot use function name '%s'", (yyvsp[(1) - (4)])->name);
					SemError(msg);
				  }
				  else if((yyvsp[(1) - (4)])->Gstptr->size == -1) //That is, the variable is not an array
				  {
					sprintf(msg, "'%s' is not an array", (yyvsp[(1) - (4)])->Lstptr->name);
					SemError(msg);
				  }
				  else if((yyvsp[(3) - (4)])->RetType == BOOL)
				  	SemError("Array index cannot be boolean");
				  
				  (yyvsp[(1) - (4)])->RetType = (yyvsp[(1) - (4)])->Gstptr->type;
				  
				  (yyval) = ConnectNodes(MakeLeaf(ARRAY, (yyvsp[(1) - (4)])->name), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
				  (yyval)->RetType = (yyvsp[(1) - (4)])->RetType;
				;}
    break;


/* Line 1267 of yacc.c.  */
#line 2289 "Exprtree.tab.c"
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


#line 651 "Exprtree.y"

/*
  NOTE:
  	Parameters => the variables that are passed on a function call.
  	Arguments  => the variables in a function definition.
  	
  	Function declartion => The part written inside decl ... enddecl block.
*/
  	
void match_parameters(Argstruct* orig_list, Argstruct* passed_list)
{
	tmp1 = orig_list;
	tmp2 = passed_list; 
	
	/* Checking the argument count */
	while(tmp1 && tmp2)
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	
	if(tmp2 == NULL && tmp1 != NULL)
		SemError("Too few parameters passed");
	else if(tmp2 != NULL && tmp1 == NULL)
		SemError("Too many parameters passed");

	/* Checking the type equivalence */
	while(orig_list && passed_list)
	{
		if(passed_list->type != orig_list->type)		// Checking for type equivalence
		{
			sprintf(msg, "Type mismatch. Expecting type '%s' ", print_name(orig_list->type));
			SemError(msg);
		}
		orig_list = orig_list->next;
		passed_list = passed_list->next;
	}
}

void match_arguments(Argstruct* orig_list, Argstruct *passed_list)
{
	tmp1 = passed_list; tmp2 = orig_list;
	
	/* Checking the argument count */
	while(tmp1 && tmp2)
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	
	if(tmp2 == NULL && tmp1 != NULL)
		SemError("Too few arguments in function definition");
	else if(tmp2 != NULL && tmp1 == NULL)
		SemError("Too many arguments in function definition");
		
	/* Checking the name and type equivalence */
	while(passed_list && orig_list)
	{
		if(passed_list->type != orig_list->type)		// Checking for type equivalence
		{
			sprintf(msg, "Type mismatch for argument '%s' ", passed_list->name);
			SemError(msg);
		}
		else if(strcmp(passed_list->name ,orig_list->name) != 0)	// Checking for name equivalence
		{
			sprintf(msg, "Name '%s' is expected for '%s'", orig_list->name, passed_list->name);
			SemError(msg);
		}
		passed_list = passed_list->next;
		orig_list = orig_list->next;
	}
}           

char* print_name(int type)
{
	if(type == INT)
		return "Integer";
	else if(type == BOOL)
		return "Boolean";
}

void yyerror(char* err)
{
	printf("At line number %d :- %s.\n", Lineno, err);
}

void SemError(char* err)
{
	yyerror(err);
	exit(0);
}

void initiate()
{
	expr_head = NULL;
	list_head = NULL;
	L_arg_count = -1;
	Branching_Label = 0;
	Function_Label  = 0;
	ArrFlag         = 1;	// So that array contents will be loaded instead of just the binding.
	errflag         = 0;
	Lineno	        = 1;	// Line no: starts from 1.
	GCount          = 0;	// For binding field in global Symbol table.
	LCount          = 1;	// For binding field in local Symbol table.
	
	
}

void terminate()
{
	if(Lhead)
		free(Lhead);
	if(Ghead)
		free(Ghead);
	
	fclose(Fp);
	fclose(yyin);
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
		printf("File %s not found\n", argv[1]);
		return 0;
	}

	Fp = fopen(argv[2], "w");
	if(!Fp){
		printf("Output file cannot be created\n");
		exit(0);
	}
	
	initiate();
	yyparse();
	terminate();

	return 0;
}

