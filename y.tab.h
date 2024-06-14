/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INUM = 258,                    /* INUM  */
    RNUM = 259,                    /* RNUM  */
    ADDOP = 260,                   /* ADDOP  */
    MULOP = 261,                   /* MULOP  */
    RELOP = 262,                   /* RELOP  */
    ASSOP = 263,                   /* ASSOP  */
    NOT = 264,                     /* NOT  */
    ARRAYOP = 265,                 /* ARRAYOP  */
    PARENOP = 266,                 /* PARENOP  */
    LISTOP = 267,                  /* LISTOP  */
    IDENT = 268,                   /* IDENT  */
    STRING = 269,                  /* STRING  */
    PROGRAM = 270,                 /* PROGRAM  */
    FUNCTION = 271,                /* FUNCTION  */
    PROCEDURE = 272,               /* PROCEDURE  */
    VAR = 273,                     /* VAR  */
    ARRAY = 274,                   /* ARRAY  */
    OF = 275,                      /* OF  */
    DOTDOT = 276,                  /* DOTDOT  */
    INTEGER = 277,                 /* INTEGER  */
    REAL = 278,                    /* REAL  */
    BOOL = 279,                    /* BOOL  */
    IF = 280,                      /* IF  */
    WHILE = 281,                   /* WHILE  */
    FOR = 282,                     /* FOR  */
    REPEAT = 283,                  /* REPEAT  */
    BEG = 284,                     /* BEG  */
    END = 285,                     /* END  */
    THEN = 286,                    /* THEN  */
    THAN = 287,                    /* THAN  */
    ELSE = 288,                    /* ELSE  */
    DO = 289,                      /* DO  */
    DOWNTO = 290,                  /* DOWNTO  */
    TO = 291,                      /* TO  */
    UNTIL = 292,                   /* UNTIL  */
    EMPTY = 293                    /* EMPTY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INUM 258
#define RNUM 259
#define ADDOP 260
#define MULOP 261
#define RELOP 262
#define ASSOP 263
#define NOT 264
#define ARRAYOP 265
#define PARENOP 266
#define LISTOP 267
#define IDENT 268
#define STRING 269
#define PROGRAM 270
#define FUNCTION 271
#define PROCEDURE 272
#define VAR 273
#define ARRAY 274
#define OF 275
#define DOTDOT 276
#define INTEGER 277
#define REAL 278
#define BOOL 279
#define IF 280
#define WHILE 281
#define FOR 282
#define REPEAT 283
#define BEG 284
#define END 285
#define THEN 286
#define THAN 287
#define ELSE 288
#define DO 289
#define DOWNTO 290
#define TO 291
#define UNTIL 292
#define EMPTY 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 77 "parser.y"

	int ival;
	float fval;
	char *opval;
	char *sval;

	tree_t *tval;

#line 152 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
