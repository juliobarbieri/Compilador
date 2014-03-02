/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 2 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <utility>


#define MAX_VAR 1000
#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label, tipo, valor, nomeOriginal, traducao;
	int tamanho;
	bool desempilha;
};

struct variavel
{
    string nome, tipo;
    bool declarada;
    bool funcao;
};

struct funcao
{		
	string tipo, label, traducao;
	list<atributos> parametros;
};

struct vetor
{
	string tipo, label;
	int tamanho;
	int funcao;
};

struct matriz
{
	string tipo, label;
	int linhas;
	int colunas;
	int funcao;
};

struct escopo
{
	string inicio, verificacao, fim;
};

typedef list<map<string,atributos> > pilha;
typedef list<escopo> listaEscopo;
typedef map<string,funcao> listaFuncoes;

int variaveis[MAX_VAR];

string intToString(int valor);
int stringToInt(string temp);
void verificaExistencia(string label);
void verificaExistenciaEspertinho(string label);
void empilhaVariavel(string chave, string tipo, string nome, string valor, string nomeOriginal, bool desempilhar);
void adicionaFuncao(string chave, string label, string tipo);
bool compararParametros(list<atributos> fnc1, list<atributos> fnc2);
funcao buscarFuncao(string label);
funcao retornaFuncao(string label);
variavel buscarNaPilha(string label);
atributos retornaVariavel(string label);
string desempilhaTudo(map<string,atributos> mapa);
void manipulaChar(string chave, string str1, string str2, string op, string s1valor, string s3valor);
escopo criaBreakOuContinue();

void verificaPosicaoVetor(string label, int posicao);
void verificaPosicaoMatriz(string label, int linha, int coluna);

string floatToString(float valor);
float stringToFloat(string temp);

int yylex(void);
string geraLabel();
string geraLabelGlobal();
string geraEscopo();
escopo criaEscopo();
string getTipo(string var1, string op, string var2);
map<string, string> geraTabelaTipos();
void yyerror(string);

pilha pilhaVariaveis;
listaEscopo escopos;
listaFuncoes funcoes;

map<string, struct variavel> tabVariaveis;
map<string, struct vetor> tabVetores;
map<string, struct matriz> tabMatrizes;
map<string, string> tabTipos = geraTabelaTipos();

variavel variavelSwitch;
string temporariaSwitch = "";
string fimSwitch = "";

string valoresDeclaracao;

bool temBreakOuContinue = 0;

list<atributos> listaParametros;



/* Line 268 of yacc.c  */
#line 183 "y.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_NUM = 258,
     TK_ABRE_PAR = 259,
     TK_FECHA_PAR = 260,
     TK_ABRE_CHV = 261,
     TK_FECHA_CHV = 262,
     TK_PNT_VIRGULA = 263,
     TK_MAIN = 264,
     TK_ID = 265,
     TK_TIPO_INT = 266,
     TK_TIPO_FLOAT = 267,
     TK_TIPO_BOOL = 268,
     TK_TIPO_CHAR = 269,
     TK_CHAR = 270,
     TK_IF = 271,
     TK_ELSE = 272,
     TK_DO = 273,
     TK_WHILE = 274,
     TK_FOR = 275,
     TK_CASE = 276,
     TK_SWITCH = 277,
     TK_DEFAULT = 278,
     TK_SOMA = 279,
     TK_SUB = 280,
     TK_MUL = 281,
     TK_DIV = 282,
     TK_RETURN = 283,
     TK_ABRE_CLCH = 284,
     TK_FECHA_CLCH = 285,
     TK_BREAK = 286,
     TK_CONTINUE = 287,
     TK_FIM = 288,
     TK_ERROR = 289,
     TK_REAL = 290,
     TK_TIPO_STRING = 291,
     TK_STRING = 292,
     TK_BOOLEAN = 293,
     TK_IGUAL = 294,
     TK_DIFERENTE = 295,
     TK_MAIOR_QUE = 296,
     TK_MENOR_QUE = 297,
     TK_MAIOR_IGUAL = 298,
     TK_MENOR_IGUAL = 299,
     TK_E = 300,
     TK_OU = 301,
     TK_NEGACAO = 302,
     TK_MOD = 303,
     TK_READ = 304,
     TK_WRITE = 305,
     TK_INCREMENTO = 306,
     TK_DECREMENTO = 307
   };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_ABRE_PAR 259
#define TK_FECHA_PAR 260
#define TK_ABRE_CHV 261
#define TK_FECHA_CHV 262
#define TK_PNT_VIRGULA 263
#define TK_MAIN 264
#define TK_ID 265
#define TK_TIPO_INT 266
#define TK_TIPO_FLOAT 267
#define TK_TIPO_BOOL 268
#define TK_TIPO_CHAR 269
#define TK_CHAR 270
#define TK_IF 271
#define TK_ELSE 272
#define TK_DO 273
#define TK_WHILE 274
#define TK_FOR 275
#define TK_CASE 276
#define TK_SWITCH 277
#define TK_DEFAULT 278
#define TK_SOMA 279
#define TK_SUB 280
#define TK_MUL 281
#define TK_DIV 282
#define TK_RETURN 283
#define TK_ABRE_CLCH 284
#define TK_FECHA_CLCH 285
#define TK_BREAK 286
#define TK_CONTINUE 287
#define TK_FIM 288
#define TK_ERROR 289
#define TK_REAL 290
#define TK_TIPO_STRING 291
#define TK_STRING 292
#define TK_BOOLEAN 293
#define TK_IGUAL 294
#define TK_DIFERENTE 295
#define TK_MAIOR_QUE 296
#define TK_MENOR_QUE 297
#define TK_MAIOR_IGUAL 298
#define TK_MENOR_IGUAL 299
#define TK_E 300
#define TK_OU 301
#define TK_NEGACAO 302
#define TK_MOD 303
#define TK_READ 304
#define TK_WRITE 305
#define TK_INCREMENTO 306
#define TK_DECREMENTO 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 329 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   681

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  203

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,     2,
       2,    54,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    15,    18,    21,    24,
      26,    29,    30,    36,    42,    44,    47,    52,    59,    64,
      71,    80,    81,    87,    91,    93,    95,    98,    99,   101,
     103,   105,   107,   109,   111,   113,   115,   117,   119,   121,
     123,   127,   130,   133,   136,   139,   145,   154,   156,   158,
     160,   162,   164,   166,   168,   170,   172,   174,   179,   183,
     187,   191,   195,   199,   203,   207,   210,   213,   215,   217,
     221,   228,   238,   240,   245,   253,   258,   260,   264,   265,
     271,   277,   287,   293,   301,   307,   315,   323,   331,   334,
     336,   341,   345,   346,   349,   352,   356,   358,   360,   362,
     364,   366,   368,   370
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    -1,    59,    58,    -1,    66,    60,
      -1,    74,    10,     8,    -1,    63,    64,    -1,    63,     8,
      -1,    60,    61,    -1,    61,    -1,    62,    64,    -1,    -1,
      74,    10,     4,    65,     5,    -1,    74,    10,     4,    65,
       5,    -1,    67,    -1,    74,    10,    -1,    74,    10,    29,
      30,    -1,    74,    10,    29,    30,    29,    30,    -1,    74,
      10,    53,    65,    -1,    74,    10,    29,    30,    53,    65,
      -1,    74,    10,    29,    30,    29,    30,    53,    65,    -1,
      -1,    11,     9,     4,     5,    67,    -1,    68,    70,    69,
      -1,     6,    -1,     7,    -1,    71,    70,    -1,    -1,    72,
      -1,    83,    -1,    84,    -1,    86,    -1,    82,    -1,    85,
      -1,    81,    -1,    80,    -1,    90,    -1,    91,    -1,    92,
      -1,    78,    -1,    68,    70,    69,    -1,    73,     8,    -1,
      77,     8,    -1,    76,     8,    -1,    74,    10,    -1,    74,
      10,    29,    77,    30,    -1,    74,    10,    29,    77,    30,
      29,    77,    30,    -1,    11,    -1,    12,    -1,    36,    -1,
      13,    -1,    14,    -1,     3,    -1,    35,    -1,    37,    -1,
      38,    -1,    15,    -1,    74,    10,    54,    77,    -1,    77,
      24,    77,    -1,    77,    25,    77,    -1,    77,    26,    77,
      -1,    77,    27,    77,    -1,    77,    48,    77,    -1,    77,
      93,    77,    -1,     4,    77,     5,    -1,    77,    51,    -1,
      77,    52,    -1,    78,    -1,    75,    -1,    10,    54,    77,
      -1,    10,    29,    77,    30,    54,    77,    -1,    10,    29,
      77,    30,    29,    77,    30,    54,    77,    -1,    10,    -1,
      10,    29,    77,    30,    -1,    10,    29,    77,    30,    29,
      77,    30,    -1,    10,     4,    79,     5,    -1,    77,    -1,
      77,    53,    79,    -1,    -1,    50,     4,    77,     5,     8,
      -1,    49,     4,    10,     5,     8,    -1,    20,     4,    76,
       8,    77,     8,    77,     5,    67,    -1,    19,     4,    77,
       5,    67,    -1,    18,    67,    19,     4,    77,     5,     8,
      -1,    16,     4,    77,     5,    67,    -1,    16,     4,    77,
       5,    67,    17,    85,    -1,    16,     4,    77,     5,    67,
      17,    67,    -1,    22,     4,    10,     5,     6,    87,     7,
      -1,    88,    87,    -1,    89,    -1,    21,    77,    55,    67,
      -1,    23,    55,    67,    -1,    -1,    31,     8,    -1,    32,
       8,    -1,    28,    77,     8,    -1,    39,    -1,    40,    -1,
      45,    -1,    46,    -1,    41,    -1,    42,    -1,    43,    -1,
      44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   135,   139,   145,   162,   167,   174,   178,
     184,   190,   195,   207,   215,   221,   246,   270,   293,   312,
     336,   360,   365,   371,   377,   385,   392,   397,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   414,   418,   419,
     420,   426,   430,   431,   434,   454,   476,   499,   499,   499,
     499,   499,   501,   501,   501,   501,   501,   503,   545,   630,
     679,   725,   771,   804,   811,   817,   821,   825,   831,   861,
     866,   873,   880,   886,   893,   902,   916,   921,   927,   932,
     938,   944,   955,   965,   975,   982,   990,   999,  1005,  1009,
    1014,  1030,  1039,  1047,  1053,  1059,  1064,  1068,  1072,  1076,
    1080,  1084,  1088,  1092
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_ABRE_PAR", "TK_FECHA_PAR",
  "TK_ABRE_CHV", "TK_FECHA_CHV", "TK_PNT_VIRGULA", "TK_MAIN", "TK_ID",
  "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_BOOL", "TK_TIPO_CHAR",
  "TK_CHAR", "TK_IF", "TK_ELSE", "TK_DO", "TK_WHILE", "TK_FOR", "TK_CASE",
  "TK_SWITCH", "TK_DEFAULT", "TK_SOMA", "TK_SUB", "TK_MUL", "TK_DIV",
  "TK_RETURN", "TK_ABRE_CLCH", "TK_FECHA_CLCH", "TK_BREAK", "TK_CONTINUE",
  "TK_FIM", "TK_ERROR", "TK_REAL", "TK_TIPO_STRING", "TK_STRING",
  "TK_BOOLEAN", "TK_IGUAL", "TK_DIFERENTE", "TK_MAIOR_QUE", "TK_MENOR_QUE",
  "TK_MAIOR_IGUAL", "TK_MENOR_IGUAL", "TK_E", "TK_OU", "TK_NEGACAO",
  "TK_MOD", "TK_READ", "TK_WRITE", "TK_INCREMENTO", "TK_DECREMENTO", "','",
  "'='", "':'", "$accept", "S", "GLOBAL", "DEC_GLOBAL", "FNCS_ABAIXO",
  "FNC_ABAIXO", "DEC_FNC_ABX", "DEC_FUNCAO", "ESCOPO_FNC", "VARIAVEIS",
  "MAIN", "ESCOPO", "ABRE_CHAVE", "FECHA_CHAVE", "COMANDOS", "COMANDO",
  "DECLARACOES", "DECLARACAO", "TIPO", "VALOR", "ATT", "E", "CHAMADA_FNC",
  "VAR_FNC", "WRITE", "READ", "FOR", "WHILE", "DO_WHILE", "IF", "SWITCH",
  "CASES", "CASE", "DEFAULT", "BREAK", "CONTINUE", "RETURN", "OP_LOGICA", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    44,    61,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    60,    60,
      61,    61,    62,    63,    64,    65,    65,    65,    65,    65,
      65,    65,    66,    67,    68,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    73,    73,    73,    74,    74,    74,
      74,    74,    75,    75,    75,    75,    75,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    79,    79,    79,    80,
      81,    82,    83,    84,    85,    85,    85,    86,    87,    87,
      88,    89,    89,    90,    91,    92,    93,    93,    93,    93,
      93,    93,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     3,     2,     2,     2,     1,
       2,     0,     5,     5,     1,     2,     4,     6,     4,     6,
       8,     0,     5,     3,     1,     1,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     2,     2,     5,     8,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     3,
       6,     9,     1,     4,     7,     4,     1,     3,     0,     5,
       5,     9,     5,     7,     5,     7,     7,     7,     2,     1,
       4,     3,     0,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    47,    48,    50,    51,    49,     0,     2,     0,     0,
      11,     0,     0,     1,     3,    24,     7,     6,    14,    27,
      47,     4,     9,     0,     0,     0,     0,    52,     0,    72,
      56,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,     0,     0,    27,     0,    27,    28,     0,     0,
      68,     0,     0,    39,    35,    34,    32,    29,    30,    33,
      31,    36,    37,    38,     8,    10,     0,    21,     5,     0,
       0,    67,    78,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,     0,     0,     0,    25,    23,    26,    41,
      44,    43,    42,     0,     0,     0,     0,    96,    97,   100,
     101,   102,   103,    98,    99,     0,    65,    66,     0,    21,
       0,     0,    22,    64,    76,     0,     0,    69,     0,     0,
       0,     0,     0,     0,    95,     0,     0,    40,     0,     0,
      58,    59,    60,    61,    62,    63,     0,    13,    15,    78,
      75,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,    12,     0,    21,    77,     0,     0,    84,     0,
      82,     0,    92,    80,    79,    45,    16,    18,     0,    70,
       0,     0,     0,     0,     0,     0,    92,    89,     0,     0,
      21,    74,    86,    85,    83,     0,     0,     0,    87,    88,
       0,    17,    19,     0,     0,     0,    91,    46,    21,    71,
      81,    90,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    21,    22,    23,     9,    17,   110,
      10,    18,    19,    87,    45,    46,    47,    48,   111,    50,
      51,    52,    71,   115,    54,    55,    56,    57,    58,    59,
      60,   175,   176,   177,    61,    62,    63,   108
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -105
static const yytype_int16 yypact[] =
{
      46,     5,  -105,  -105,  -105,  -105,     4,  -105,    46,    -5,
      91,    14,    21,  -105,  -105,  -105,  -105,  -105,  -105,   165,
    -105,    91,  -105,    33,    22,    12,    49,  -105,    26,    -2,
    -105,    36,    33,    58,    65,    66,    26,    67,    70,  -105,
    -105,  -105,    79,    80,   165,    89,   165,  -105,    98,    87,
    -105,    99,    47,   327,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,   104,    91,  -105,    33,
     112,  -105,    26,    26,    26,    26,    90,    26,    91,   100,
     356,  -105,  -105,   102,    26,    89,  -105,  -105,  -105,  -105,
     -20,  -105,  -105,    26,    26,    26,    26,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,    26,  -105,  -105,    26,    91,
     108,   106,  -105,  -105,   446,   109,   476,   592,   181,   115,
     211,   110,   114,   119,  -105,   120,   240,  -105,    26,    26,
     615,   615,   629,   629,   592,   592,   121,  -105,   -11,    26,
    -105,   -16,    33,    26,    33,    76,    26,   125,   124,   126,
     505,   592,  -105,   103,    91,  -105,    26,    26,   118,   269,
    -105,   385,     0,  -105,  -105,   111,   -10,  -105,   534,   592,
       6,   133,    26,    26,    88,   135,     0,  -105,    26,   116,
      91,    93,  -105,  -105,  -105,   298,   414,    33,  -105,  -105,
     563,    95,  -105,    26,    33,    33,  -105,  -105,    91,   592,
    -105,  -105,  -105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,   151,  -105,  -105,   140,  -105,  -105,   139,  -104,
    -105,   -21,   -13,    82,    35,  -105,  -105,  -105,     7,  -105,
      92,   -28,    -9,    43,  -105,  -105,  -105,  -105,  -105,     2,
    -105,    13,  -105,  -105,  -105,  -105,  -105,  -105
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -68
static const yytype_int16 yytable[] =
{
      70,    15,    72,    16,    13,   136,    44,    11,    80,   128,
      53,    76,    15,   156,    12,    11,    67,    24,   153,   179,
      68,   173,    31,   174,    25,    26,    49,    73,    24,    27,
      28,    44,    66,    44,   129,    53,    29,    53,   157,    15,
      75,    30,   154,   180,   114,   116,   117,   118,   112,   120,
     167,    49,    74,    49,    69,    92,   126,     1,     2,     3,
       4,    39,    77,    40,    41,   130,   131,   132,   133,    78,
      79,    93,    94,    95,    96,    81,   192,   134,    82,    85,
     135,    88,     5,    83,    84,   121,    97,    98,    99,   100,
     101,   102,   103,   104,   202,   105,    86,    90,   106,   107,
     150,   151,    20,     2,     3,     4,    89,    91,   109,   119,
     123,   114,   125,   137,   140,   159,   138,   113,   161,   143,
     145,   158,   146,   160,   147,   148,   152,     5,   168,   169,
     129,   162,   163,   166,   164,   170,    93,    94,    95,    96,
     178,   184,   188,   187,   185,   186,   191,   193,   198,   182,
     190,    97,    98,    99,   100,   101,   102,   103,   104,    14,
     105,    64,    65,   106,   107,   199,   196,   127,    27,    28,
     122,    15,   183,   200,   201,    29,    20,     2,     3,     4,
      30,    31,   155,    32,    33,    34,   142,    35,     0,   189,
       0,     0,     0,    36,     0,     0,    37,    38,     0,     0,
      39,     5,    40,    41,     0,    93,    94,    95,    96,     0,
       0,     0,     0,     0,    42,    43,   144,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,     0,   106,   107,     0,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,     0,   106,   107,    93,    94,    95,    96,     0,     0,
       0,     0,     0,     0,   171,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,     0,   105,     0,
       0,   106,   107,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,   194,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,     0,
     106,   107,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -67,     0,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,     0,     0,   106,
     107,   -67,   -67,   -67,   -67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,     0,   -67,     0,     0,   -67,   -67,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   172,     0,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,     0,   106,   107,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,     0,     0,   106,   107,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,     0,     0,   106,   107,     0,     0,   195,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,     0,   106,   107,   139,
      93,    94,    95,    96,     0,     0,   141,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,     0,   106,   107,    93,
      94,    95,    96,     0,     0,   165,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,     0,     0,   106,   107,    93,    94,
      95,    96,     0,     0,   181,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,     0,     0,   106,   107,    93,    94,    95,
      96,     0,     0,   197,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
       0,   105,     0,     0,   106,   107,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,     0,
     105,    95,    96,   106,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,     0,     0,   106,   107,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,     0,
     106,   107
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-105))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      28,     6,     4,     8,     0,   109,    19,     0,    36,    29,
      19,    32,     6,    29,     9,     8,     4,    10,    29,    29,
       8,    21,    16,    23,    10,     4,    19,    29,    21,     3,
       4,    44,    10,    46,    54,    44,    10,    46,    54,     6,
       4,    15,    53,    53,    72,    73,    74,    75,    69,    77,
     154,    44,    54,    46,     5,     8,    84,    11,    12,    13,
      14,    35,     4,    37,    38,    93,    94,    95,    96,     4,
       4,    24,    25,    26,    27,     8,   180,   105,     8,    44,
     108,    46,    36,     4,     4,    78,    39,    40,    41,    42,
      43,    44,    45,    46,   198,    48,     7,    10,    51,    52,
     128,   129,    11,    12,    13,    14,     8,     8,     4,    19,
      10,   139,    10,     5,     5,   143,    10,     5,   146,     4,
      10,   142,     8,   144,     5,     5,     5,    36,   156,   157,
      54,     6,     8,    30,     8,    17,    24,    25,    26,    27,
      29,     8,     7,    55,   172,   173,    30,    54,    53,   170,
     178,    39,    40,    41,    42,    43,    44,    45,    46,     8,
      48,    21,    23,    51,    52,   193,   187,    85,     3,     4,
      78,     6,   170,   194,   195,    10,    11,    12,    13,    14,
      15,    16,   139,    18,    19,    20,     5,    22,    -1,   176,
      -1,    -1,    -1,    28,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    37,    38,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    49,    50,     5,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      -1,    -1,    51,    52,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      -1,    -1,    51,    52,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    -1,
      -1,    51,    52,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    -1,    -1,
      51,    52,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    -1,    -1,    51,
      52,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    -1,    -1,    51,    52,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    -1,    -1,    51,    52,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    -1,    -1,    51,    52,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    55,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    -1,    -1,    51,    52,    53,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    -1,    -1,    51,    52,    24,
      25,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    -1,    -1,    51,    52,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    -1,    -1,    51,    52,    24,    25,    26,
      27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    -1,    -1,    51,    52,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    26,    27,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    -1,    -1,    51,    52,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    -1,    -1,
      51,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    13,    14,    36,    57,    58,    59,    63,
      66,    74,     9,     0,    58,     6,     8,    64,    67,    68,
      11,    60,    61,    62,    74,    10,     4,     3,     4,    10,
      15,    16,    18,    19,    20,    22,    28,    31,    32,    35,
      37,    38,    49,    50,    68,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    80,    81,    82,    83,    84,    85,
      86,    90,    91,    92,    61,    64,    10,     4,     8,     5,
      77,    78,     4,    29,    54,     4,    67,     4,     4,     4,
      77,     8,     8,     4,     4,    70,     7,    69,    70,     8,
      10,     8,     8,    24,    25,    26,    27,    39,    40,    41,
      42,    43,    44,    45,    46,    48,    51,    52,    93,     4,
      65,    74,    67,     5,    77,    79,    77,    77,    77,    19,
      77,    74,    76,    10,     8,    10,    77,    69,    29,    54,
      77,    77,    77,    77,    77,    77,    65,     5,    10,    53,
       5,    30,     5,     4,     5,    10,     8,     5,     5,     5,
      77,    77,     5,    29,    53,    79,    29,    54,    67,    77,
      67,    77,     6,     8,     8,    30,    30,    65,    77,    77,
      17,     5,     8,    21,    23,    87,    88,    89,    29,    29,
      53,    30,    67,    85,     8,    77,    77,    55,     7,    87,
      77,    30,    65,    54,     5,    55,    67,    30,    53,    77,
      67,    67,    65
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
        case 2:

/* Line 1806 of yacc.c  */
#line 130 "sintatica.y"
    {
				cout << "/*Compilador BX*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\n" << (yyvsp[(1) - (1)]).traducao + "\n" << endl;
			}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 136 "sintatica.y"
    {
				(yyval).traducao = "\n" + (yyvsp[(1) - (2)]).traducao + "\n" + (yyvsp[(2) - (2)]).traducao;
			}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 140 "sintatica.y"
    {
				(yyval).traducao = "\n" + (yyvsp[(1) - (2)]).traducao + "\n" + (yyvsp[(2) - (2)]).traducao + "\n";
			}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 146 "sintatica.y"
    {
                struct variavel var = {geraLabelGlobal(), (yyvsp[(1) - (3)]).traducao, true, false};
            	verificaExistencia((yyvsp[(2) - (3)]).label);
            	tabVariaveis[(yyvsp[(2) - (3)]).label] = var;
            	string str1(var.tipo);
                if(str1.compare("string") == 0)
                {
                	(yyval).traducao = "char " + tabVariaveis[(yyvsp[(2) - (3)]).label].nome + "[255];\n";
                }
            	else {
            		if ((yyvsp[(1) - (3)]).traducao == "boolean") {
						(yyvsp[(1) - (3)]).traducao = "bool";
					}
	              	(yyval).traducao = (yyvsp[(1) - (3)]).traducao + " " + tabVariaveis[(yyvsp[(2) - (3)]).label].nome + ";\n";            	
            	}
			}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 163 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
				
			}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 168 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + ";\n\n";
				
			}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 175 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + "\n" + (yyvsp[(2) - (2)]).traducao;
			}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 179 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 185 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
				
			}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 190 "sintatica.y"
    {
				(yyval).traducao = "";
			}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 196 "sintatica.y"
    {
				funcao fnc = retornaFuncao((yyvsp[(2) - (5)]).label);
				if(compararParametros(fnc.parametros, listaParametros)) {
					(yyval).traducao = (yyvsp[(1) - (5)]).traducao + " " + fnc.label + "(" + (yyvsp[(4) - (5)]).traducao + ") ";	
				}
				else {
					yyerror("Função não declarada!");
				}
			}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 208 "sintatica.y"
    {
				string label = geraEscopo() + "funcao";
				adicionaFuncao((yyvsp[(2) - (5)]).label, label, (yyvsp[(1) - (5)]).traducao);
				(yyval).traducao = (yyvsp[(1) - (5)]).traducao + " " + label + "(" + (yyvsp[(4) - (5)]).traducao + ") ";
			}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 216 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao + "\n\n";
			}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 222 "sintatica.y"
    {
				map<string,atributos> tabelaTemp;
				tabelaTemp.clear();			
				pilhaVariaveis.push_front(tabelaTemp);	
				
				string label = geraLabel();	
				empilhaVariavel(label, (yyvsp[(1) - (2)]).traducao, label, "", (yyvsp[(2) - (2)]).label, true);
				
				listaParametros.clear();
				
				atributos atr;
				atr.label = label;
				atr.tipo = (yyvsp[(1) - (2)]).traducao;
				atr.nomeOriginal = (yyvsp[(2) - (2)]).label;
				listaParametros.push_back(atr);
					
				struct variavel var = {label, (yyvsp[(1) - (2)]).traducao, true, true};
            	tabVariaveis[(yyvsp[(2) - (2)]).label] = var;
            	var.tipo = (yyvsp[(1) - (2)]).tipo;
				
				(yyval).label = label;
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + " " + label;			
				(yyval).tipo = (yyvsp[(1) - (2)]).tipo;	
			}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 247 "sintatica.y"
    {
				string label = geraLabel();	
				empilhaVariavel(label, (yyvsp[(1) - (4)]).traducao, label, "", (yyvsp[(2) - (4)]).label, true);

				atributos atr;
				atr.label = label;
				atr.tipo = (yyvsp[(1) - (4)]).traducao;
				atr.nomeOriginal = (yyvsp[(2) - (4)]).label;
				listaParametros.push_back(atr);
				
				struct variavel var = {label, (yyvsp[(1) - (4)]).traducao, true, true};
				struct vetor vet = {var.nome, (yyvsp[(1) - (4)]).traducao, 0, true};
            	tabVariaveis[(yyvsp[(2) - (4)]).label] = var;
            	tabVetores[(yyvsp[(2) - (4)]).label] = vet;
				
            	vet.tipo = (yyvsp[(1) - (4)]).tipo;
            	var.tipo = (yyvsp[(1) - (4)]).tipo;
				
				(yyval).label = label;
				(yyval).traducao = (yyvsp[(1) - (4)]).traducao + " *" + label;			
				(yyval).tipo = (yyvsp[(1) - (4)]).tipo;	
			}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 271 "sintatica.y"
    {
				string label = geraLabel();	
            	empilhaVariavel(label, (yyvsp[(1) - (6)]).traducao, label, "", (yyvsp[(2) - (6)]).label, true);
            	
				atributos atr;
				atr.label = label;
				atr.tipo = (yyvsp[(1) - (6)]).traducao;
				atr.nomeOriginal = (yyvsp[(2) - (6)]).label;
				listaParametros.push_back(atr);
				
				struct variavel var = {label, (yyvsp[(1) - (6)]).traducao, true, true};
				struct matriz vet = {var.nome, (yyvsp[(1) - (6)]).traducao, 0, 0, true};
            	tabVariaveis[(yyvsp[(2) - (6)]).label] = var;
            	tabMatrizes[(yyvsp[(2) - (6)]).label] = vet;
            	
            	vet.tipo = (yyvsp[(1) - (6)]).tipo;
            	var.tipo = (yyvsp[(1) - (6)]).tipo;
				
				(yyval).label = label;
				(yyval).traducao = (yyvsp[(1) - (6)]).traducao + " **" + label;			
				(yyval).tipo = (yyvsp[(1) - (6)]).tipo;	
			}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 294 "sintatica.y"
    {
				string label = geraLabel();	
				empilhaVariavel(label, (yyvsp[(1) - (4)]).traducao, label, "", (yyvsp[(2) - (4)]).label, true);
				
				atributos atr;
				atr.label = label;
				atr.tipo = (yyvsp[(1) - (4)]).traducao;
				atr.nomeOriginal = (yyvsp[(2) - (4)]).label;
				listaParametros.push_back(atr);
					
				struct variavel var = {label, (yyvsp[(1) - (4)]).traducao, true, true};
            	tabVariaveis[(yyvsp[(2) - (4)]).label] = var;
            	var.tipo = (yyvsp[(1) - (4)]).tipo;
				
				(yyval).label = label;
				(yyval).traducao = (yyvsp[(1) - (4)]).traducao + " " + label + ", " + (yyvsp[(4) - (4)]).traducao;			
				(yyval).tipo = (yyvsp[(1) - (4)]).tipo;	
			}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 313 "sintatica.y"
    {
				string label = geraLabel();	
				empilhaVariavel(label, (yyvsp[(1) - (6)]).traducao, label, "", (yyvsp[(2) - (6)]).label, true);
				
				atributos atr;
				atr.label = label;
				atr.tipo = (yyvsp[(1) - (6)]).traducao;
				atr.nomeOriginal = (yyvsp[(2) - (6)]).label;
				listaParametros.push_back(atr);
				
				struct variavel var = {label, (yyvsp[(1) - (6)]).traducao, true, true};
				struct vetor vet = {var.nome, (yyvsp[(1) - (6)]).traducao, 0, true};
            	tabVariaveis[(yyvsp[(2) - (6)]).label] = var;
            	tabVetores[(yyvsp[(2) - (6)]).label] = vet;
				
            	vet.tipo = (yyvsp[(1) - (6)]).tipo;
            	var.tipo = (yyvsp[(1) - (6)]).tipo;
				
				(yyval).label = label;
				(yyval).traducao = (yyvsp[(1) - (6)]).traducao + " *" + label + ", " + (yyvsp[(6) - (6)]).traducao;			
				(yyval).tipo = (yyvsp[(1) - (6)]).tipo;	
			}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 337 "sintatica.y"
    {
				string label = geraLabel();	
				empilhaVariavel(label, (yyvsp[(1) - (8)]).traducao, label, "", (yyvsp[(2) - (8)]).label, true);
				
				atributos atr;
				atr.label = label;
				atr.tipo = (yyvsp[(1) - (8)]).traducao;
				atr.nomeOriginal = (yyvsp[(2) - (8)]).label;
				listaParametros.push_back(atr);
				
				struct variavel var = {label, (yyvsp[(1) - (8)]).traducao, true, true};
				struct matriz vet = {var.nome, (yyvsp[(1) - (8)]).traducao, 0, 0, true};
            	tabVariaveis[(yyvsp[(2) - (8)]).label] = var;
            	tabMatrizes[(yyvsp[(2) - (8)]).label] = vet;
				
            	vet.tipo = (yyvsp[(1) - (8)]).tipo;
            	var.tipo = (yyvsp[(1) - (8)]).tipo;
				
				(yyval).label = label;
				(yyval).traducao = (yyvsp[(1) - (8)]).traducao + " **" + label + ", " + (yyvsp[(8) - (8)]).traducao;			
				(yyval).tipo = (yyvsp[(1) - (8)]).tipo;	
			}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 360 "sintatica.y"
    {
				(yyval).traducao = "";
			}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 366 "sintatica.y"
    {
				(yyval).traducao = "int main(void)\n" + (yyvsp[(5) - (5)]).traducao + "\n\n"; 
			}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 372 "sintatica.y"
    {
				(yyval).traducao = "{\n\n" + (yyvsp[(3) - (3)]).traducao +"\n" + (yyvsp[(2) - (3)]).traducao + "\n}";
			}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 378 "sintatica.y"
    {
				map<string,atributos> tabelaVariaveis;
				tabelaVariaveis.clear();
				pilhaVariaveis.push_front(tabelaVariaveis);
			}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 386 "sintatica.y"
    {
				(yyval).traducao = desempilhaTudo(pilhaVariaveis.front());			
				pilhaVariaveis.pop_front();		
			}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 393 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + "\n" + (yyvsp[(2) - (2)]).traducao;
			}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 397 "sintatica.y"
    {
				(yyval).traducao = "";
			}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 411 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 415 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 421 "sintatica.y"
    {
				(yyval).traducao = "{\n" + (yyvsp[(3) - (3)]).traducao +"\n" + (yyvsp[(2) - (3)]).traducao + "\n}";				
			}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 427 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao;
			}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 435 "sintatica.y"
    {
                struct variavel var = {geraLabel(), (yyvsp[(1) - (2)]).traducao, true, false};
                verificaExistenciaEspertinho((yyvsp[(2) - (2)]).label);
                empilhaVariavel(var.nome, (yyvsp[(1) - (2)]).traducao, var.nome, "", (yyvsp[(2) - (2)]).label, false);
            	tabVariaveis[(yyvsp[(2) - (2)]).label] = var;
            	
            	string str1(var.tipo);
                if(str1.compare("string") == 0)
                {
                	(yyval).traducao = "\tchar " + retornaVariavel((yyvsp[(2) - (2)]).label).label + "[255];\n";
                }
            	else {
            		if ((yyvsp[(1) - (2)]).traducao == "boolean") {
						(yyvsp[(1) - (2)]).traducao = "bool";
					}
	              	(yyval).traducao = "\t" + (yyvsp[(1) - (2)]).traducao + " " + retornaVariavel((yyvsp[(2) - (2)]).label).label + ";\n";            	
            	}
            }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 455 "sintatica.y"
    {
				struct variavel var = {geraLabel(), (yyvsp[(1) - (5)]).traducao, true, false};
				struct vetor vet = {var.nome, (yyvsp[(1) - (5)]).traducao, stringToInt((yyvsp[(4) - (5)]).valor), false};
                verificaExistenciaEspertinho((yyvsp[(2) - (5)]).label);
                empilhaVariavel(var.nome, (yyvsp[(1) - (5)]).traducao, var.nome, "", (yyvsp[(2) - (5)]).label, false);
            	tabVariaveis[(yyvsp[(2) - (5)]).label] = var;
            	tabVetores[(yyvsp[(2) - (5)]).label] = vet;
            	
            	string str1(var.tipo);
                if(str1.compare("string") == 0)
                {
                	yyerror("Não implementado!");
                }
            	else {
            		if ((yyvsp[(1) - (5)]).traducao == "boolean") {
						(yyvsp[(1) - (5)]).traducao = "bool";
					}
	              	(yyval).traducao = (yyvsp[(4) - (5)]).traducao + "\t" + (yyvsp[(1) - (5)]).traducao + " " + retornaVariavel((yyvsp[(2) - (5)]).label).label + "[" + (yyvsp[(4) - (5)]).label + "];\n";            	
            	}
			}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 477 "sintatica.y"
    {
				struct variavel var = {geraLabel(), (yyvsp[(1) - (8)]).traducao, true, false};
				struct matriz mtz = {var.nome, (yyvsp[(1) - (8)]).traducao, stringToInt((yyvsp[(4) - (8)]).valor), stringToInt((yyvsp[(7) - (8)]).valor), false};
                verificaExistenciaEspertinho((yyvsp[(2) - (8)]).label);
                empilhaVariavel(var.nome, (yyvsp[(1) - (8)]).traducao, var.nome, "", (yyvsp[(2) - (8)]).label, false);
            	tabVariaveis[(yyvsp[(2) - (8)]).label] = var;
            	tabMatrizes[(yyvsp[(2) - (8)]).label] = mtz;
            	
            	string str1(var.tipo);
                if(str1.compare("string") == 0)
                {
                	yyerror("Não implementado!");
                }
            	else {
            		if ((yyvsp[(1) - (8)]).traducao == "boolean") {
						(yyvsp[(1) - (8)]).traducao = "bool";
					}
	              	(yyval).traducao = (yyvsp[(4) - (8)]).traducao + (yyvsp[(7) - (8)]).traducao + "\t" + (yyvsp[(1) - (8)]).traducao + " " + retornaVariavel((yyvsp[(2) - (8)]).label).label + "[" + (yyvsp[(4) - (8)]).label + " * " + (yyvsp[(7) - (8)]).label + " + " + (yyvsp[(7) - (8)]).label + "];\n";            	
            	}
			}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 504 "sintatica.y"
    {
				struct variavel var = {geraLabel(), (yyvsp[(1) - (4)]).traducao, true, false};
				verificaExistenciaEspertinho((yyvsp[(2) - (4)]).label);
                tabVariaveis[(yyvsp[(2) - (4)]).label] = var;
				(yyvsp[(2) - (4)]).tipo = (yyvsp[(1) - (4)]).traducao;
				(yyvsp[(2) - (4)]).valor = (yyvsp[(4) - (4)]).valor;
                string str1(var.tipo);
                empilhaVariavel(var.nome, (yyvsp[(1) - (4)]).traducao, var.nome, (yyvsp[(4) - (4)]).valor, (yyvsp[(2) - (4)]).label, true);

                if(str1.compare("string") == 0)
                {
                	if ((yyvsp[(2) - (4)]).tipo == (yyvsp[(4) - (4)]).tipo) {
                		(yyval).traducao = (yyvsp[(4) - (4)]).traducao + "\t" + "strcpy(" + retornaVariavel((yyvsp[(2) - (4)]).label).label + ", " + (yyvsp[(4) - (4)]).label + ");\n";
                	}
                	else {
                		yyerror("Tipos " + (yyvsp[(2) - (4)]).tipo + " e " + (yyvsp[(4) - (4)]).tipo + " incompatíveis!");
                	}
                
                }
                else {
                    if ((yyvsp[(1) - (4)]).traducao == "boolean") {
						(yyvsp[(1) - (4)]).traducao = "bool";
					}
					
					// Se tipos float = int, ou são iguais, é possível a atribuição
					if ((retornaVariavel((yyvsp[(2) - (4)]).label).tipo == (yyvsp[(4) - (4)]).tipo) || ((yyvsp[(4) - (4)]).tipo == "int" || retornaVariavel((yyvsp[(2) - (4)]).label).tipo == "float")) {
		            	(yyval).traducao = (yyvsp[(4) - (4)]).traducao + "\t" + retornaVariavel((yyvsp[(2) - (4)]).label).label + " = " + (yyvsp[(4) - (4)]).label + ";\n";
                	}
                	// Soma entre chars
                	else if(((yyvsp[(2) - (4)]).valor[(yyvsp[(2) - (4)]).valor.length()-1] == '\'') &&  ((yyvsp[(2) - (4)]).valor[0] == '\'') || ((yyvsp[(4) - (4)]).valor[(yyvsp[(4) - (4)]).valor.length()-1] == '\'') &&  ((yyvsp[(4) - (4)]).valor[0] == '\'')) {
                		(yyval).traducao = (yyvsp[(4) - (4)]).traducao + "\t" + retornaVariavel((yyvsp[(2) - (4)]).label).label + " = " + (yyvsp[(4) - (4)]).label + ";\n";
                	}
                	else
                	{
                		yyerror("Tipos incompatíveis!");
                	}
                	
                }
			}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 546 "sintatica.y"
    {
				// Variável que verifica se deve empilhar ou não ao fim (Caso seja char, já teria empilhado)
				bool character = 0;
			
				string chave = geraLabel();
				(yyval).label = chave;
				
				string tipo = getTipo((yyvsp[(1) - (3)]).tipo, (yyvsp[(2) - (3)]).traducao, (yyvsp[(3) - (3)]).tipo);
				
				string str1((yyvsp[(1) - (3)]).tipo);
				string str2((yyvsp[(3) - (3)]).tipo);
				
				// Verifica se é char (char, não string)
				if(((yyvsp[(1) - (3)]).valor[(yyvsp[(1) - (3)]).valor.length()-1] == '\'') &&  ((yyvsp[(1) - (3)]).valor[0] == '\'') || ((yyvsp[(3) - (3)]).valor[(yyvsp[(3) - (3)]).valor.length()-1] == '\'') &&  ((yyvsp[(3) - (3)]).valor[0] == '\'')) {
					character = 1;
					manipulaChar(chave, str1, str2, "+", (yyvsp[(1) - (3)]).valor, (yyvsp[(3) - (3)]).valor);
 				}
				// Se não, procedimento normal
				else if((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo)
				{
					string temp_cast = geraLabel();
					
					if((yyvsp[(1) - (3)]).tipo != tipo)
					{
						(yyvsp[(1) - (3)]).traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + (yyvsp[(1) - (3)]).label + ";\n";
						(yyvsp[(1) - (3)]).label = temp_cast;
						(yyvsp[(1) - (3)]).tipo = tipo;
					}
					if(((yyvsp[(1) - (3)]).tipo == tipo) && tipo == "string") {
						(yyvsp[(3) - (3)]).traducao += "\tchar " + temp_cast + "[255];" + "\n\tsnprintf(" + temp_cast + ", 255, \"%d\", " + (yyvsp[(3) - (3)]).label + ");\n";
						(yyvsp[(3) - (3)]).label = temp_cast;
					}
				}
				
				
				if ((str1.compare("string") == 0)  || (str2.compare("string") == 0)) {
					(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\tstrcpy("+ (yyval).label + ", " + (yyvsp[(1) - (3)]).label + ");\n" + "\tstrcat("+ (yyval).label + ", " + (yyvsp[(3) - (3)]).label + ");\n";
				}
				else if (tipo.compare("int") == 0) {
					(yyval).valor = intToString(stringToInt((yyvsp[(1) - (3)]).valor) + stringToInt((yyvsp[(3) - (3)]).valor));
					(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + (yyval).label + " = "+ (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traducao + " " + (yyvsp[(3) - (3)]).label + ";\n";
				}
				else {
					(yyval).tipo = tipo;
					(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + (yyval).label + " = "+ (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traducao + " " + (yyvsp[(3) - (3)]).label + ";\n";			}
					
				// Se não é char empilha, caso seja char, já empilhou antes
				if (((yyvsp[(1) - (3)]).tipo == "int" && (yyvsp[(3) - (3)]).tipo == "int") || ((yyvsp[(1) - (3)]).tipo == "float" && (yyvsp[(3) - (3)]).tipo == "float") || ((yyvsp[(1) - (3)]).tipo == "int" && (yyvsp[(3) - (3)]).tipo == "float") || ((yyvsp[(1) - (3)]).tipo == "float" && (yyvsp[(3) - (3)]).tipo == "int")) {
				
					empilhaVariavel(chave, tipo, chave, (yyvsp[(1) - (3)]).valor + (yyvsp[(3) - (3)]).valor, "", true);
					(yyval).valor = intToString(stringToInt((yyvsp[(1) - (3)]).valor) + stringToInt((yyvsp[(3) - (3)]).valor));
				}
				// Caso aconteça concatenação...
				else if(character == 0) {
					
					string str1;
					string str2;
					
					if (((yyvsp[(1) - (3)]).tipo == "string" || (yyvsp[(1) - (3)]).tipo == "char") && (yyvsp[(1) - (3)]).valor.length() != 0) {
						str1 = (yyvsp[(1) - (3)]).valor.substr(1, (yyvsp[(1) - (3)]).valor.size()-2);
					}
					
					if (((yyvsp[(3) - (3)]).tipo == "string" || (yyvsp[(3) - (3)]).tipo == "char") && (yyvsp[(3) - (3)]).valor.length() != 0) {
						str2 = (yyvsp[(3) - (3)]).valor.substr(1, (yyvsp[(3) - (3)]).valor.size()-2);
					}
					
					if ((yyvsp[(1) - (3)]).tipo == "int") {
						str1 = (yyvsp[(1) - (3)]).valor;
					}
					
					if ((yyvsp[(3) - (3)]).tipo == "int") {
						str2 = (yyvsp[(3) - (3)]).valor;
					}
				
					(yyval).valor = '\"' + str1 + str2 + '\"';
					
					if ((yyvsp[(1) - (3)]).valor.length() != 0 && (yyvsp[(3) - (3)]).valor.length() != 0) {
						empilhaVariavel(chave, tipo, chave, '\"' + str1 + str2 + '\"', "", true);
					}
					else {
						empilhaVariavel(chave, tipo, chave, "", "", true);
					}
				}
			}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 631 "sintatica.y"
    {
				bool character = 0;
				
				string chave = geraLabel();
				(yyval).label = chave;
				
				string tipo = getTipo((yyvsp[(1) - (3)]).tipo, (yyvsp[(2) - (3)]).traducao, (yyvsp[(3) - (3)]).tipo);
				
				string str1((yyvsp[(1) - (3)]).tipo);
				string str2((yyvsp[(3) - (3)]).tipo);
				
				// Verifica se é char (char, não string)
				if(((yyvsp[(1) - (3)]).valor[(yyvsp[(1) - (3)]).valor.length()-1] == '\'') &&  ((yyvsp[(1) - (3)]).valor[0] == '\'') || ((yyvsp[(3) - (3)]).valor[(yyvsp[(3) - (3)]).valor.length()-1] == '\'') &&  ((yyvsp[(3) - (3)]).valor[0] == '\'')) {
					character = 1;
					manipulaChar(chave, str1, str2, "-", (yyvsp[(1) - (3)]).valor, (yyvsp[(3) - (3)]).valor);
 				}
				// Se não, procedimento normal
				else if((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo)
				{
					string temp_cast = geraLabel();
					
					if((yyvsp[(1) - (3)]).tipo != tipo)
					{
						(yyvsp[(1) - (3)]).traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + (yyvsp[(1) - (3)]).label + ";\n";
						(yyvsp[(1) - (3)]).label = temp_cast;
						(yyvsp[(1) - (3)]).tipo = tipo;
					}
					else
					{
						(yyvsp[(3) - (3)]).traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + (yyvsp[(3) - (3)]).label + ";\n";
						(yyvsp[(3) - (3)]).label = temp_cast;
						(yyvsp[(3) - (3)]).tipo = tipo;
					}
					
					if (tipo.compare("int") == 0) {
						(yyval).valor = intToString(stringToInt((yyvsp[(1) - (3)]).valor) - stringToInt((yyvsp[(3) - (3)]).valor));
					}
					
					
				}
				
				(yyval).tipo = tipo;
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + (yyval).label + " = "+ (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traducao + " " + (yyvsp[(3) - (3)]).label + ";\n";
				
				if(character == 0) {
					empilhaVariavel(chave, tipo, chave, (yyval).valor, "", true);
				}
			}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 680 "sintatica.y"
    {
				bool character = 0;
			
				string chave = geraLabel();
				(yyval).label = chave;
				
				string tipo = getTipo((yyvsp[(1) - (3)]).tipo, (yyvsp[(2) - (3)]).traducao, (yyvsp[(3) - (3)]).tipo);
				
				string str1((yyvsp[(1) - (3)]).tipo);
				string str2((yyvsp[(3) - (3)]).tipo);
				
				// Verifica se é char (char, não string)
				if(((yyvsp[(1) - (3)]).valor[(yyvsp[(1) - (3)]).valor.length()-1] == '\'') &&  ((yyvsp[(1) - (3)]).valor[0] == '\'') || ((yyvsp[(3) - (3)]).valor[(yyvsp[(3) - (3)]).valor.length()-1] == '\'') &&  ((yyvsp[(3) - (3)]).valor[0] == '\'')) {
					character = 1;
					manipulaChar(chave, str1, str2, "*", (yyvsp[(1) - (3)]).valor, (yyvsp[(3) - (3)]).valor);
 				}
				else if((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo)
				{
					string temp_cast = geraLabel();
					
					if((yyvsp[(1) - (3)]).tipo != tipo)
					{
						(yyvsp[(1) - (3)]).traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + (yyvsp[(1) - (3)]).label + ";\n";
						(yyvsp[(1) - (3)]).label = temp_cast;
						(yyvsp[(1) - (3)]).tipo = tipo;
					}
					else
					{
						(yyvsp[(3) - (3)]).traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + (yyvsp[(3) - (3)]).label + ";\n";
						(yyvsp[(3) - (3)]).label = temp_cast;
						(yyvsp[(3) - (3)]).tipo = tipo;
					}
					
					if (tipo.compare("int") == 0) {
						(yyval).valor = intToString(stringToInt((yyvsp[(1) - (3)]).valor) * stringToInt((yyvsp[(3) - (3)]).valor));
					}
				}
				
				(yyval).tipo = tipo;
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + (yyval).label + " = "+ (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traducao + " " + (yyvsp[(3) - (3)]).label + ";\n";
				
				if(character == 0) {
					empilhaVariavel(chave, tipo, chave, (yyval).valor, "", true);
				}
			}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 726 "sintatica.y"
    {
				bool character = 0;
			
				string chave = geraLabel();
				(yyval).label = chave;
				
				string tipo = getTipo((yyvsp[(1) - (3)]).tipo, (yyvsp[(2) - (3)]).traducao, (yyvsp[(3) - (3)]).tipo);
				
				string str1((yyvsp[(1) - (3)]).tipo);
				string str2((yyvsp[(3) - (3)]).tipo);
				
				// Verifica se é char (char, não string)
				if(((yyvsp[(1) - (3)]).valor[(yyvsp[(1) - (3)]).valor.length()-1] == '\'') &&  ((yyvsp[(1) - (3)]).valor[0] == '\'') || ((yyvsp[(3) - (3)]).valor[(yyvsp[(3) - (3)]).valor.length()-1] == '\'') &&  ((yyvsp[(3) - (3)]).valor[0] == '\'')) {
					character = 1;
					manipulaChar(chave, str1, str2, "/", (yyvsp[(1) - (3)]).valor, (yyvsp[(3) - (3)]).valor);
 				}
				else if((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo)
				{
					string temp_cast = geraLabel();
					
					if((yyvsp[(1) - (3)]).tipo != tipo)
					{
						(yyvsp[(1) - (3)]).traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + (yyvsp[(1) - (3)]).label + ";\n";
						(yyvsp[(1) - (3)]).label = temp_cast;
						(yyvsp[(1) - (3)]).tipo = tipo;
					}
					else
					{
						(yyvsp[(3) - (3)]).traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + (yyvsp[(3) - (3)]).label + ";\n";
						(yyvsp[(3) - (3)]).label = temp_cast;
						(yyvsp[(3) - (3)]).tipo = tipo;
					}
					
					if (tipo.compare("int") == 0) {
						(yyval).valor = intToString(stringToInt((yyvsp[(1) - (3)]).valor) / stringToInt((yyvsp[(3) - (3)]).valor));
					}
				}
				
				(yyval).tipo = tipo;
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + (yyval).label + " = "+ (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traducao + " " + (yyvsp[(3) - (3)]).label + ";\n";
				
				if(character == 0) {
					empilhaVariavel(chave, tipo, chave, (yyval).valor, "", true);
				}
			}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 772 "sintatica.y"
    {
				string chave = geraLabel();
				(yyval).label = chave;
				
				string tipo = getTipo((yyvsp[(1) - (3)]).tipo, (yyvsp[(2) - (3)]).traducao, (yyvsp[(3) - (3)]).tipo);
				
				if((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo)
				{
					string temp_cast = geraLabel();
					
					if((yyvsp[(1) - (3)]).tipo != tipo)
					{
						(yyvsp[(1) - (3)]).traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + (yyvsp[(1) - (3)]).label + ";\n";
						(yyvsp[(1) - (3)]).label = temp_cast;
						(yyvsp[(1) - (3)]).tipo = tipo;
					}
					else
					{
						(yyvsp[(3) - (3)]).traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + (yyvsp[(3) - (3)]).label + ";\n";
						(yyvsp[(3) - (3)]).label = temp_cast;
						(yyvsp[(3) - (3)]).tipo = tipo;
					}
					
					if (tipo.compare("int") == 0) {
						(yyval).valor = intToString(stringToInt((yyvsp[(1) - (3)]).valor) % stringToInt((yyvsp[(3) - (3)]).valor));
					}
				}
				
				(yyval).tipo = tipo;
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + (yyval).label + " = "+ (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traducao + " " + (yyvsp[(3) - (3)]).label + ";\n";
				empilhaVariavel(chave, tipo, chave, (yyval).valor, "", true);
			}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 805 "sintatica.y"
    {
				string nome = geraLabel();
				(yyval).label = nome;	
				empilhaVariavel(nome,"bool", nome, "", "", true);		
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\n\t" + (yyval).label + " = " + (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traducao + " " + (yyvsp[(3) - (3)]).label  + ";\n";	
			}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 812 "sintatica.y"
    {
				(yyval).tipo = (yyvsp[(2) - (3)]).tipo;
				(yyval).traducao = (yyvsp[(2) - (3)]).traducao;
				(yyval).label = (yyvsp[(2) - (3)]).label;
			}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 818 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + "\t" + (yyvsp[(1) - (2)]).label + "++;\n";
			}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 822 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + "\t" + (yyvsp[(1) - (2)]).label + "--;\n";
			}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 826 "sintatica.y"
    {
				string label = geraLabel();
				(yyval).traducao = "\t" + valoresDeclaracao + "\n\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traducao + ";\n";
				valoresDeclaracao = "";
			}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 832 "sintatica.y"
    {
				string nome = geraLabel();
				(yyval).label = nome;
				
				string str1((yyvsp[(1) - (1)]).tipo);
				if (str1.compare("string") == 0) {
					
					string str((yyvsp[(1) - (1)]).traducao);
					if (str[str.length()-1] == ' ') {
						str = str.substr(0, str.size()-1);
					}
				
					(yyval).tipo = "string";
					empilhaVariavel(nome,"char", nome, str, "", true);
					(yyval).traducao = "\tstrcpy(" + (yyval).label + ", " + (yyvsp[(1) - (1)]).traducao + ");\n";
					(yyval).tamanho = (yyvsp[(1) - (1)]).traducao.length() - 2;
					(yyvsp[(1) - (1)]).tamanho = (yyvsp[(1) - (1)]).traducao.length() - 2;
					(yyval).valor = str;
				}
				else {
					if ((yyvsp[(1) - (1)]).tipo == "") (yyvsp[(1) - (1)]).tipo = "bool";
					
					(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
					empilhaVariavel(nome, (yyvsp[(1) - (1)]).tipo, nome, (yyvsp[(1) - (1)]).traducao, "", true);
					(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traducao + ";\n";
					(yyval).valor = (yyvsp[(1) - (1)]).traducao;
					(yyvsp[(1) - (1)]).valor = (yyvsp[(1) - (1)]).traducao;
				}
			}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 862 "sintatica.y"
    {
				(yyval).tipo = (yyvsp[(3) - (3)]).tipo;
				(yyval).traducao = (yyvsp[(3) - (3)]).traducao + "\t" + retornaVariavel((yyvsp[(1) - (3)]).label).label + " = " + (yyvsp[(3) - (3)]).label + ";\n";
			}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 867 "sintatica.y"
    {
				(yyval).tipo = (yyvsp[(3) - (6)]).tipo;
				
				(yyval).traducao = (yyvsp[(3) - (6)]).traducao + (yyvsp[(6) - (6)]).traducao + "\t" + retornaVariavel((yyvsp[(1) - (6)]).label).label + "[" + (yyvsp[(3) - (6)]).label + "] = " + (yyvsp[(6) - (6)]).label + ";\n";
				verificaPosicaoVetor((yyvsp[(1) - (6)]).label, stringToInt((yyvsp[(3) - (6)]).valor));
			}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 874 "sintatica.y"
    {
				(yyval).tipo = (yyvsp[(3) - (9)]).tipo;
				
				(yyval).traducao = (yyvsp[(3) - (9)]).traducao + (yyvsp[(6) - (9)]).traducao + (yyvsp[(9) - (9)]).traducao + "\t" + retornaVariavel((yyvsp[(1) - (9)]).label).label + "[" + (yyvsp[(3) - (9)]).label + " * " + intToString(tabMatrizes[(yyvsp[(1) - (9)]).label].colunas) + " + " + (yyvsp[(6) - (9)]).label + "] = " + (yyvsp[(9) - (9)]).label + ";\n";
				verificaPosicaoMatriz((yyvsp[(1) - (9)]).label, stringToInt((yyvsp[(3) - (9)]).valor), stringToInt((yyvsp[(6) - (9)]).valor));
			}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 881 "sintatica.y"
    {
				(yyval).tipo = retornaVariavel((yyvsp[(1) - (1)]).label).tipo;
				(yyval).traducao = "";
				(yyval).label = retornaVariavel((yyvsp[(1) - (1)]).label).label;
			}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 887 "sintatica.y"
    {
				(yyval).tipo = retornaVariavel((yyvsp[(1) - (4)]).label).tipo;
				(yyval).traducao = (yyvsp[(3) - (4)]).traducao + "\n";
				(yyval).label = retornaVariavel((yyvsp[(1) - (4)]).label).label + "[" + (yyvsp[(3) - (4)]).label + "]";
				verificaPosicaoVetor((yyvsp[(1) - (4)]).label, stringToInt((yyvsp[(3) - (4)]).valor));
			}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 894 "sintatica.y"
    {
				(yyval).tipo = retornaVariavel((yyvsp[(1) - (7)]).label).tipo;
				(yyval).traducao = (yyvsp[(3) - (7)]).traducao + "\n";
				(yyval).label = retornaVariavel((yyvsp[(1) - (7)]).label).label + "[" + (yyvsp[(3) - (7)]).label + " * " + intToString(tabMatrizes[(yyvsp[(1) - (7)]).label].colunas) + " + " + (yyvsp[(6) - (7)]).label + "]";
				verificaPosicaoMatriz((yyvsp[(1) - (7)]).label, stringToInt((yyvsp[(3) - (7)]).valor), stringToInt((yyvsp[(6) - (7)]).valor));
			}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 903 "sintatica.y"
    {
				// Recuperar label da funcao
				string labelOriginal((yyvsp[(1) - (4)]).label);
				funcao fnc = buscarFuncao(labelOriginal);

				(yyvsp[(1) - (4)]).tipo = fnc.tipo;
				(yyval).tipo = (yyvsp[(1) - (4)]).tipo;
				(yyval).label = geraLabel();
				empilhaVariavel((yyval).label, (yyvsp[(1) - (4)]).tipo, (yyval).label, "", "", true);	
				(yyval).traducao = fnc.label + "(" + (yyvsp[(3) - (4)]).traducao + ")"; 
			}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 917 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).label;
				valoresDeclaracao += "\n" + (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 922 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (3)]).label + ", " + (yyvsp[(3) - (3)]).label;
				valoresDeclaracao += (yyvsp[(1) - (3)]).traducao;
			}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 927 "sintatica.y"
    {
				(yyval).traducao = "";
			}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 933 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(3) - (5)]).traducao +  "\tstd::cout << " + (yyvsp[(3) - (5)]).label + " << std::endl;";
			}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 939 "sintatica.y"
    {
				(yyval).traducao = "\tstd::cin >> " + retornaVariavel((yyvsp[(3) - (5)]).label).label + ";";
 			}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 945 "sintatica.y"
    {
				escopo e = criaEscopo();
				string escopoInicio = e.inicio;
				string escopoVerificacao = e.verificacao;
				string escopoFim = e.fim;
				
				(yyval).traducao = (yyvsp[(3) - (9)]).traducao +"\n" + (yyvsp[(5) - (9)]).traducao + "\n\tif(" + (yyvsp[(5) - (9)]).label + ") goto " + escopoInicio + "; \n\telse goto " + escopoFim + ";\n\t" + escopoInicio + ":" + (yyvsp[(9) - (9)]).traducao + "\n\t" + escopoVerificacao + ":;\n" +  (yyvsp[(7) - (9)]).traducao + " \n " + (yyvsp[(5) - (9)]).traducao + "\n\tif(" + (yyvsp[(5) - (9)]).label + ") goto " + escopoInicio + "; \n\telse goto " + escopoFim + ";\n\t" + escopoFim + ":;\n";
			}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 956 "sintatica.y"
    {
				escopo e = criaEscopo();
				string escopoInicio = e.inicio;
				string escopoVerificacao = e.verificacao;
				string escopoFim = e.fim;

				(yyval).traducao = (yyvsp[(3) - (5)]).traducao + "\n\tif("+ (yyvsp[(3) - (5)]).label +") goto " + escopoInicio + "; \n\telse goto " + escopoFim + ";\n\t" + escopoInicio + ":" + (yyvsp[(5) - (5)]).traducao + "\n\t" + (yyvsp[(3) - (5)]).traducao + "\n\t" + escopoVerificacao + ":;\n\tif(" + (yyvsp[(3) - (5)]).label +") goto " + escopoInicio + "; \n\telse goto " + escopoFim +";\n\t" + escopoFim + ":;\n";
			}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 966 "sintatica.y"
    {
				escopo e = criaEscopo();
				string escopoInicio = e.inicio;
				string escopoVerificacao = e.verificacao;
				string escopoFim = e.fim;

				(yyval).traducao =  "\t" + escopoInicio + ":\n" + (yyvsp[(5) - (7)]).traducao + "\n\t" + (yyvsp[(2) - (7)]).traducao + "\n\t" + escopoVerificacao + ":\n\tif("+ (yyvsp[(5) - (7)]).label +") goto " + escopoInicio + "; \n\telse goto " + escopoFim + ";\n\t" + escopoFim + ":;\n\t";
			}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 976 "sintatica.y"
    {
				string nomeEscopo = geraEscopo();
				string escopoInicio = nomeEscopo + "inicio";
				string escopoFim = nomeEscopo + "fim";
				(yyval).traducao = (yyvsp[(3) - (5)]).traducao + "\n\tif(" + (yyvsp[(3) - (5)]).label + ") goto " + escopoInicio + "; \n\telse  goto " + escopoFim + "; \n\t" + escopoInicio + ":" + (yyvsp[(5) - (5)]).traducao + escopoFim + ":;\n";
			}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 983 "sintatica.y"
    {
				string nomeEscopo = geraEscopo();
				string escopoInicio = nomeEscopo + "inicio";
				string escopoVerificacao = nomeEscopo + "verificacao";
				string escopoFim = nomeEscopo + "fim";
				(yyval).traducao = (yyvsp[(3) - (7)]).traducao + "\n\tif(" + (yyvsp[(3) - (7)]).label + ") goto " + escopoInicio + "; \n\telse  goto " + escopoVerificacao + "; \n\t" + escopoInicio + ":" + (yyvsp[(5) - (7)]).traducao + "\n\tgoto " + escopoFim + ";\n\t" + escopoVerificacao + ":; \n\t" + (yyvsp[(7) - (7)]).traducao + escopoFim + ":;\n";
			}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 991 "sintatica.y"
    {
				string nomeEscopo = geraEscopo();
				string escopoInicio = nomeEscopo + "inicio";
				string escopoElse = nomeEscopo + "else";
				string escopoFim = nomeEscopo + "fim";
				(yyval).traducao = (yyvsp[(3) - (7)]).traducao + "\n\tif(" + (yyvsp[(3) - (7)]).label +")  goto " + escopoInicio + "; \n\telse  goto " + escopoElse + "; \n\t" + escopoInicio + ":" + (yyvsp[(5) - (7)]).traducao  + "\n\t goto "+ escopoFim  + ";\n\t"+ escopoElse + ":" + (yyvsp[(7) - (7)]).traducao + escopoFim + ":;\n";
			}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1000 "sintatica.y"
    {
				variavelSwitch = buscarNaPilha((yyvsp[(3) - (7)]).label);
				(yyval).traducao = "\n" + variavelSwitch.tipo + " " + temporariaSwitch + " = " + variavelSwitch.nome + ";\n{\n" + (yyvsp[(6) - (7)]).traducao + "\n}\n" + fimSwitch + ":;\n";
			}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1006 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + "\n" + (yyvsp[(2) - (2)]).traducao;
			}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1010 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1015 "sintatica.y"
    {
				if(temporariaSwitch == "")
				{
					temporariaSwitch = geraLabel();
				}
				string nomeEscopo = geraEscopo();
				string inicioEscopo = nomeEscopo + "inicio";
				string fimEscopo = nomeEscopo + "fim";
				if(fimSwitch == "")
				{
					fimSwitch = geraEscopo() + "fimSwitch";
				}
				(yyval).traducao = "\n" + (yyvsp[(2) - (4)]).traducao + "\nif(" + temporariaSwitch + " == " + (yyvsp[(2) - (4)]).label + ") goto " + inicioEscopo + "; else goto " + fimEscopo + ";\n" + inicioEscopo + ":;\n" + (yyvsp[(4) - (4)]).traducao + "\n goto " + fimSwitch + ";\n\n" + fimEscopo + ":;";
			}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1031 "sintatica.y"
    {
				if(fimSwitch == "")
				{
					fimSwitch = geraEscopo() + "fimSwitch";
				}
				(yyval).traducao = "\n" + (yyvsp[(3) - (3)]).traducao + "\n" + "goto " + fimSwitch + ";";
			}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1039 "sintatica.y"
    {
				if(fimSwitch == "")
				{
					fimSwitch = geraEscopo() + "fimSwitch";
				}
				(yyval).traducao = "goto " + fimSwitch + ";";
			}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1048 "sintatica.y"
    {
				escopo nomeEscopo = criaBreakOuContinue();
				(yyval).traducao = "goto " + nomeEscopo.fim + ";";
			}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1054 "sintatica.y"
    {
				escopo nomeEscopo = criaBreakOuContinue();
				(yyval).traducao = "goto " + nomeEscopo.verificacao + ";";
			}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1060 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(2) - (3)]).traducao + "\n\treturn " + (yyvsp[(2) - (3)]).label + ";";
			}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1065 "sintatica.y"
    {
				(yyval).traducao = "==";
			}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1069 "sintatica.y"
    {
				(yyval).traducao = "!=";
			}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1073 "sintatica.y"
    {
				(yyval).traducao = "&&";
			}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1077 "sintatica.y"
    {
				(yyval).traducao = "||";
			}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1081 "sintatica.y"
    {
				(yyval).traducao = ">";
			}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 1085 "sintatica.y"
    {
				(yyval).traducao = "<";
			}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 1089 "sintatica.y"
    {
				(yyval).traducao = ">=";
			}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 1093 "sintatica.y"
    {
				(yyval).traducao = "<=";
			}
    break;



/* Line 1806 of yacc.c  */
#line 3130 "y.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 2067 of yacc.c  */
#line 1098 "sintatica.y"


#include "lex.yy.c"

int yyparse();

string getTipo(string var1, string op, string var2)
{
    string tipo_retorno = "";

    tipo_retorno = tabTipos[var1+op+var2];
    if(tipo_retorno != "")    
		return tipo_retorno;
		
	tipo_retorno = tabTipos[var2+op+var1];
	if(tipo_retorno != "")
		return tipo_retorno;
	
	perror("ERRO: Tipos incompativeis");
	exit(EXIT_FAILURE);
}





string geraTraducaoExp(struct atributos ss, struct atributos s1, struct atributos s3, string operador)
{
	return s1.traducao + s3.traducao + "\t" + ss.label + " = " + s1.label + " + " + s3.label + ";\n";
}




map<string, string> geraTabelaTipos()
{
    map<string, string> tabela_tipos;

    const string INT = "int";
    const string FLOAT = "float";
    const string STRING = "string";
    const string CHAR = "char";

    const string INT_MAIS_INT = "int+int";
    const string INT_MAIS_FLOAT = "int+float";
    const string INT_MAIS_STR = "int+string";
    const string INT_MAIS_CHAR = "int+char";
    const string FLOAT_MAIS_FLOAT = "float+float";
    const string FLOAT_MAIS_STRING = "float+string";
    const string CHAR_MAIS_STRING = "char+string";
    const string STRING_MAIS_STRING = "string+string";
    const string CHAR_MAIS_CHAR = "char+char";
    
    const string CHAR_MENOS_CHAR = "char-char";
    const string CHAR_VEZES_CHAR = "char*char";
    const string CHAR_DIV_CHAR = "char/char";

    const string INT_MENOS_INT = "int-int";
    const string INT_MENOS_FLOAT = "int-float";
    const string INT_MENOS_CHAR = "int-char";
    const string FLOAT_MENOS_FLOAT = "float-float";
    
    const string INT_VEZES_CHAR = "int*char";
    const string INT_DIV_CHAR = "int/char";
    
    const string INT_VEZES_INT = "int*int";
    const string INT_VEZES_FLOAT = "int*float";
    const string FLOAT_VEZES_FLOAT = "float*float";

    const string INT_DIV_INT = "int/int";
    const string INT_DIV_FLOAT = "int/float";
    const string FLOAT_DIV_FLOAT = "float/float";
    
    const string FLOAT_MOD_FLOAT = "float%float";
    const string INT_MOD_INT = "int%int";
    const string INT_MOD_FLOAT = "int%float";


    tabela_tipos[INT_MAIS_INT] = INT;
    tabela_tipos[INT_MAIS_FLOAT] = FLOAT;
    tabela_tipos[INT_MAIS_STR] = STRING;
    tabela_tipos[INT_MAIS_CHAR] = CHAR;
    tabela_tipos[FLOAT_MAIS_FLOAT] = FLOAT;
    tabela_tipos[FLOAT_MAIS_STRING] = STRING;
    tabela_tipos[CHAR_MAIS_CHAR] = STRING;
    
    tabela_tipos[CHAR_MENOS_CHAR] = CHAR;
    tabela_tipos[CHAR_VEZES_CHAR] = CHAR;
    tabela_tipos[CHAR_DIV_CHAR] = CHAR;
    tabela_tipos[INT_VEZES_CHAR] = CHAR;
    tabela_tipos[INT_DIV_CHAR] = CHAR;
    
    tabela_tipos[CHAR_MAIS_STRING] = STRING;
    tabela_tipos[STRING_MAIS_STRING] = STRING;
    
    tabela_tipos[INT_MENOS_INT] = INT;
    tabela_tipos[INT_MENOS_FLOAT] = FLOAT;
    tabela_tipos[INT_MENOS_CHAR] = CHAR;
    tabela_tipos[FLOAT_MENOS_FLOAT] = FLOAT;
    
    tabela_tipos[INT_VEZES_INT] = INT;
    tabela_tipos[INT_VEZES_FLOAT] = FLOAT;
    tabela_tipos[FLOAT_VEZES_FLOAT] = FLOAT;
    
    tabela_tipos[INT_DIV_INT] = INT;
    tabela_tipos[INT_DIV_FLOAT] = FLOAT;
    tabela_tipos[FLOAT_DIV_FLOAT] = FLOAT;
    
    tabela_tipos[INT_MOD_INT] = INT;
    tabela_tipos[FLOAT_MOD_FLOAT] = FLOAT;
    tabela_tipos[INT_MOD_FLOAT] = FLOAT;
    
    return tabela_tipos;   
}

string intToString(int valor)
{
	stringstream out;
	out << valor;
	return out.str();
}
int stringToInt(string temp)
{
	return atoi(temp.c_str());
}

string floatToString(float valor)
{
	stringstream out;
	out << valor;
	return out.str();
}
float stringToFloat(string temp)
{
	return atoi(temp.c_str());
}

string geraLabel()
{
	static int i = 0;
	stringstream label;
	label << "temp_" << i++;
	
	return label.str();
	
}

string geraLabelGlobal()
{
	static int i = 0;
	stringstream label;
	label << "gtemp_" << i++;
	
	return label.str();
	
}

string geraEscopo()
{
	static int i = 0;
	stringstream label;
	label << "escopo_" << i++ << "_";
	
	return label.str();
	
}

escopo criaEscopo()
{
	escopo nomeEscopo;
	if(escopos.empty())
	{
		string labelEscopo = geraEscopo();
		nomeEscopo.inicio = labelEscopo + "inicio";
		nomeEscopo.verificacao = labelEscopo + "verificacao";
		nomeEscopo.fim = labelEscopo + "fim";
	}
	else
	{
		nomeEscopo = escopos.front();
		escopos.pop_front();
	}
	return nomeEscopo;
}

void verificaExistencia(string label)
{
	map<string,variavel>::const_iterator
	iterator(tabVariaveis.begin()),
    	mend(tabVariaveis.end());
    	
    for(; iterator != mend; ++iterator)
	{
		if ((iterator->first == label) && (iterator->second.declarada == true)) {
			if (!(iterator->second.funcao == true))
				yyerror("Variável '" + label + "' já declarada!");
		}
	}
}

void verificaExistenciaEspertinho(string label)
{
	map<string,atributos> mapa = pilhaVariaveis.front();
	map<string,atributos>::const_iterator
	iterator(mapa.begin()),
    	mend(mapa.end());
    
    	for(;iterator!=mend;++iterator)
		{
			if ((iterator->second.nomeOriginal == label) && (iterator->second.nomeOriginal != "")) 
					yyerror("Variável '" + label + "' já declarada!");
    	}
 }	
 
atributos retornaVariavel(string label)
{
	map<string,atributos> mapa = pilhaVariaveis.front();
	map<string,atributos>::const_iterator
	iterator(mapa.begin()),
    	mend(mapa.end());
    
    	for(;iterator!=mend;++iterator)
		{
			if ((iterator->second.nomeOriginal == label))
				return iterator->second;
    	}
    	
		variavel var = buscarNaPilha(label);
		atributos atr;
		atr.tipo = var.tipo;
		atr.label = var.nome;
		atr.nomeOriginal = label;
		return atr;
		yyerror("Variável '" + label + "' não declarada neste escopo!");
 }	

void empilhaVariavel(string chave, string tipo, string label, string valor, string nomeOriginal, bool desempilhar)
{
	verificaExistenciaEspertinho(nomeOriginal);
	
	map<string, atributos> mapa = pilhaVariaveis.front();
	mapa.erase(chave);	
	atributos atr;
	atr.valor = valor;	
	atr.tipo = tipo;
	atr.label = label;
	atr.nomeOriginal = nomeOriginal;
	atr.desempilha = desempilhar;
	
	mapa.insert(pair<string, atributos>(chave,atr));
	pilhaVariaveis.pop_front();
	pilhaVariaveis.push_front(mapa);
}

void adicionaFuncao(string chave, string label, string tipo)
{	
	funcao fnc;	
	fnc.tipo = tipo;
	fnc.label = label;
	
	if (!listaParametros.empty()) {		
		copy( listaParametros.begin(), listaParametros.end(), back_inserter(fnc.parametros) );	
		atributos atr = fnc.parametros.front();
		atributos atl = fnc.parametros.back();
	}
	
	funcoes.insert(pair<string, funcao>(chave, fnc));
}

bool compararParametros(list<atributos> fnc1, list<atributos> fnc2)
{
	if (fnc1.size() != fnc2.size()) {
		return false;
	}
	
	if (fnc1.size() == 0 && fnc2.size()) {
		return true;
	}
	
    for (list<atributos>::const_iterator iterator = fnc1.begin(), end = fnc1.end(); iterator != end; ++iterator) {
  		atributos atr = fnc2.front();
		fnc2.pop_front();
		if (iterator->nomeOriginal != atr.nomeOriginal) {
			return false;
		}  	
	}
    	
	
	return true;
}

funcao buscarFuncao(string label)
{
	map<string, funcao>::const_iterator
	iterator(funcoes.begin()),
    	mend(funcoes.end());
    	
    for(; iterator != mend; ++iterator)
	{
		if (iterator->first == label) {
			return iterator->second;
		}
	}
	yyerror("Função '" + label + "' não declarada!");
}


variavel buscarNaPilha(string label)
{
	map<string, variavel>::const_iterator
	iterator(tabVariaveis.begin()),
    	mend(tabVariaveis.end());
    	
    for(; iterator != mend; ++iterator)
	{
		if (iterator->first == label) {
			return iterator->second;
		}
	}
	yyerror("Variável '" + label + "' não declarada!");
}

funcao retornaFuncao(string label)
{
	listaFuncoes::const_iterator
	iterator(funcoes.begin()),
    	mend(funcoes.end());
    	
    for(; iterator != mend; ++iterator)
	{
		if (iterator->first == label) {
			return iterator->second;
		}
	}
	yyerror("Função '" + label + "' não declarada!");
}

string desempilhaTudo(map<string,atributos> mapa)
{
	map<string,atributos>::const_iterator
	iterator(mapa.begin()),
    	mend(mapa.end());
    
   	 string s;
    
    	for(;iterator!=mend;++iterator)
		{
			// Poe as variaveis no início do ESCOPO.
			if(iterator->second.tipo == "string" && iterator->second.desempilha == true)
			{
				string tipo = "char";
				int tam = iterator->second.valor.length() - 2;
				if (tam < 0) tam = 255;
				s += "\t" + tipo + " " + iterator->second.label + "[" + intToString(tam) + "];\n";
			}
			else if (iterator->second.tipo == "char" && iterator->second.desempilha == true)
			{
				string str = iterator->second.valor;
				
				// Significa que é char
				if ((str[str.length()-1] == '\'') &&  (str[0] == '\'')) {
					s += "\t" + iterator->second.tipo + " " + iterator->second.label + ";\n";
 				}
 				// É String
 				else {
 					int tam = str.length() - 2;
 					if (tam < 0) tam = 255;
					s += "\t" + iterator->second.tipo + " " + iterator->second.label + "[" + intToString(tam) + "];\n";
 				}
			}
			else if (iterator->second.desempilha == true)
			{
				if (iterator->second.tipo == "boolean") {
					s += "\tbool " + iterator->second.label +";\n";
				}
				else
					s += "\t" + iterator->second.tipo + " " + iterator->second.label +";\n";
			}
    	}
	
	return s;	
}

escopo criaBreakOuContinue()
{
	if(temBreakOuContinue)
	{
		return escopos.front();
	}
	else
	{
		temBreakOuContinue = 1;
		escopo nomeEscopo;
		
		string labelEscopo = geraEscopo();
		
		nomeEscopo.inicio = labelEscopo + "inicio";
		nomeEscopo.verificacao = labelEscopo + "verificacao";
		nomeEscopo.fim = labelEscopo + "fim";
		escopos.push_front(nomeEscopo);
		return nomeEscopo;
	}
	
}

void verificaPosicaoVetor(string label, int posicao)
{
	if (tabVetores[label].tamanho <= posicao || (0 > posicao)) {
		if (tabVetores[label].funcao == false) {
			yyerror("Posição '" + intToString(posicao) + "' não presente no vetor!");
		}
	}
}

void verificaPosicaoMatriz(string label, int linhas, int colunas)
{
	if (((tabMatrizes[label].linhas <= linhas) && (tabMatrizes[label].colunas <= colunas)) || ((0 > linhas) && (0 > colunas))) {
		if (tabMatrizes[label].funcao == false) {
			yyerror("Posição linha '" + intToString(linhas) + "' e posicao coluna '" + intToString(colunas) + "' não presente no vetor!");
		}
	}
}

void manipulaChar(string chave, string str1, string str2, string op, string s1valor, string s3valor) {
	char resultado;
					
	// Se a operação é entre char e string, não faz cast
	if ((str1 == "int" && str2 == "char")) {
		// Don't cast!
		int valor1 = stringToInt(s1valor);
		char valor2 = s3valor[1];
		
		if (op == "+") resultado = valor1 + valor2;
		if (op == "-") resultado = valor1 - valor2;
		if (op == "*") resultado = valor1 * valor2;
		if (op == "/") resultado = valor1 / valor2;
	}
	if (str1 == "char" && str2 == "int") {
		// Don't cast!
		int valor2 = stringToInt(s1valor);
		char valor1 = s3valor[1];	
		
		if (op == "+") resultado = valor1 + valor2;
		if (op == "-") resultado = valor1 - valor2;
		if (op == "*") resultado = valor1 * valor2;
		if (op == "/") resultado = valor1 / valor2;			
	}
					
	if (str1 == "char" && str2 == "char") {
		char valor2 = s1valor[1];
		char valor1 = s3valor[1];
		
		if (op == "+") resultado = valor1 + valor2;
		if (op == "-") resultado = valor1 - valor2;
		if (op == "*") resultado = valor1 * valor2;
		if (op == "/") resultado = valor1 / valor2;						
	}
											
	stringstream ss;
	string s;
	ss << resultado;
	ss >> s;	
						
	empilhaVariavel(chave, "char", chave, "\'" + s + "\'", "", true);
}


int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				

