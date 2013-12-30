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
     TK_IF = 268,
     TK_ELSE = 269,
     TK_DO = 270,
     TK_WHILE = 271,
     TK_FOR = 272,
     TK_SOMA = 273,
     TK_SUB = 274,
     TK_MUL = 275,
     TK_DIV = 276,
     TK_FIM = 277,
     TK_ERROR = 278,
     TK_REAL = 279
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
#define TK_IF 268
#define TK_ELSE 269
#define TK_DO 270
#define TK_WHILE 271
#define TK_FOR 272
#define TK_SOMA 273
#define TK_SUB 274
#define TK_MUL 275
#define TK_DIV 276
#define TK_FIM 277
#define TK_ERROR 278
#define TK_REAL 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


