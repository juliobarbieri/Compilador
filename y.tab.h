/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


