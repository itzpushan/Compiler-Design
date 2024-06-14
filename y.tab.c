/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "tree.h"
#include "symbol.h"
#include "reg_stack.h"
#include "gencode.h"
#include "y.tab.h"
#include "externs.h"


int yydebug = 1;

int yywrap() { return 1; }

void yyerror(const char *str) { fprintf(stderr, "\nerror at line %d: %s\n", yylineno, str); }

int main(int c, char** v) 
{ 
	
	if(c != 2)
	{
		fprintf(stderr, "Incorrect number of arguments given.\n");
		exit(0);
	}
	
	
	FILE *infile = fopen(v[1], "r");
	if(!infile)
	{
		fprintf(stderr, "Invalid file name given.\n");
		exit(0);
	}

	
	char* fout_name = (char*)malloc(strlen(v[1]));
	strcpy(fout_name, (char*)v[1]);
	fout_name[strlen(fout_name)-1] = 's';
	fout = fopen(fout_name, "w");

	
	htable = (table_t*)malloc(sizeof(table_t));
	for(int i = 0; i < TABLE_SIZE; i++)
		htable->symbol_table[i] = NULL;
	htable->prev = htable;
	htable->next = htable;
	htable->id = -1;

	
	rstack = (stack_t*)malloc(sizeof(stack_t));
	for(int i = 0; i < MAX_REGS; i++)
		rstack->reg[i] = i;
	for(int i = 0; i < MAX_TEMPS; i++)
		rstack->temp[i] = -i; 
	rstack->top_idx = MAX_REGS-1;

	
	fprintf(stderr, "Converting into Token\n____________\n\n");
	yyin = infile;
	file_header(v[1]);
	do { yyparse(); }
	while (!feof(yyin));
	file_footer();
	
	fclose(infile);
	fclose(fout);
}

#line 143 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 281 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INUM = 3,                       /* INUM  */
  YYSYMBOL_RNUM = 4,                       /* RNUM  */
  YYSYMBOL_ADDOP = 5,                      /* ADDOP  */
  YYSYMBOL_MULOP = 6,                      /* MULOP  */
  YYSYMBOL_RELOP = 7,                      /* RELOP  */
  YYSYMBOL_ASSOP = 8,                      /* ASSOP  */
  YYSYMBOL_NOT = 9,                        /* NOT  */
  YYSYMBOL_ARRAYOP = 10,                   /* ARRAYOP  */
  YYSYMBOL_PARENOP = 11,                   /* PARENOP  */
  YYSYMBOL_LISTOP = 12,                    /* LISTOP  */
  YYSYMBOL_IDENT = 13,                     /* IDENT  */
  YYSYMBOL_STRING = 14,                    /* STRING  */
  YYSYMBOL_PROGRAM = 15,                   /* PROGRAM  */
  YYSYMBOL_FUNCTION = 16,                  /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 17,                 /* PROCEDURE  */
  YYSYMBOL_VAR = 18,                       /* VAR  */
  YYSYMBOL_ARRAY = 19,                     /* ARRAY  */
  YYSYMBOL_OF = 20,                        /* OF  */
  YYSYMBOL_DOTDOT = 21,                    /* DOTDOT  */
  YYSYMBOL_INTEGER = 22,                   /* INTEGER  */
  YYSYMBOL_REAL = 23,                      /* REAL  */
  YYSYMBOL_BOOL = 24,                      /* BOOL  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_FOR = 27,                       /* FOR  */
  YYSYMBOL_REPEAT = 28,                    /* REPEAT  */
  YYSYMBOL_BEG = 29,                       /* BEG  */
  YYSYMBOL_END = 30,                       /* END  */
  YYSYMBOL_THEN = 31,                      /* THEN  */
  YYSYMBOL_THAN = 32,                      /* THAN  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_DO = 34,                        /* DO  */
  YYSYMBOL_DOWNTO = 35,                    /* DOWNTO  */
  YYSYMBOL_TO = 36,                        /* TO  */
  YYSYMBOL_UNTIL = 37,                     /* UNTIL  */
  YYSYMBOL_EMPTY = 38,                     /* EMPTY  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '.'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_45_ = 45,                       /* '['  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_start = 48,                     /* start  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_ident_list = 53,                /* ident_list  */
  YYSYMBOL_decls = 54,                     /* decls  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_std_type = 56,                  /* std_type  */
  YYSYMBOL_subprogram_decls = 57,          /* subprogram_decls  */
  YYSYMBOL_subprogram_decl = 58,           /* subprogram_decl  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_subprogram_head = 60,           /* subprogram_head  */
  YYSYMBOL_fn_header = 61,                 /* fn_header  */
  YYSYMBOL_62_5 = 62,                      /* $@5  */
  YYSYMBOL_63_6 = 63,                      /* $@6  */
  YYSYMBOL_proc_header = 64,               /* proc_header  */
  YYSYMBOL_65_7 = 65,                      /* $@7  */
  YYSYMBOL_66_8 = 66,                      /* $@8  */
  YYSYMBOL_param_list = 67,                /* param_list  */
  YYSYMBOL_param = 68,                     /* param  */
  YYSYMBOL_compound_stmt = 69,             /* compound_stmt  */
  YYSYMBOL_opt_stmts = 70,                 /* opt_stmts  */
  YYSYMBOL_stmt_list = 71,                 /* stmt_list  */
  YYSYMBOL_stmt = 72,                      /* stmt  */
  YYSYMBOL_73_9 = 73,                      /* $@9  */
  YYSYMBOL_74_10 = 74,                     /* $@10  */
  YYSYMBOL_75_11 = 75,                     /* $@11  */
  YYSYMBOL_var = 76,                       /* var  */
  YYSYMBOL_procedure_stmt = 77,            /* procedure_stmt  */
  YYSYMBOL_expr_list = 78,                 /* expr_list  */
  YYSYMBOL_expr = 79,                      /* expr  */
  YYSYMBOL_simple_expr = 80,               /* simple_expr  */
  YYSYMBOL_term = 81,                      /* term  */
  YYSYMBOL_factor = 82,                    /* factor  */
  YYSYMBOL_id = 83,                        /* id  */
  YYSYMBOL_fn = 84,                        /* fn  */
  YYSYMBOL_inum = 85,                      /* inum  */
  YYSYMBOL_rnum = 86                       /* rnum  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,    43,     2,    42,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   173,   173,   176,   176,   176,   176,   190,   197,   206,
     214,   217,   219,   227,   229,   233,   236,   239,   239,   253,
     259,   266,   266,   271,   271,   275,   275,   280,   280,   284,
     286,   290,   295,   299,   302,   305,   307,   311,   317,   322,
     324,   324,   330,   330,   330,   338,   340,   344,   345,   353,
     355,   358,   361,   368,   377,   379,   386,   390,   392,   396,
     398,   400,   405,   407,   409,   411,   415,   419,   422,   426
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INUM", "RNUM",
  "ADDOP", "MULOP", "RELOP", "ASSOP", "NOT", "ARRAYOP", "PARENOP",
  "LISTOP", "IDENT", "STRING", "PROGRAM", "FUNCTION", "PROCEDURE", "VAR",
  "ARRAY", "OF", "DOTDOT", "INTEGER", "REAL", "BOOL", "IF", "WHILE", "FOR",
  "REPEAT", "BEG", "END", "THEN", "THAN", "ELSE", "DO", "DOWNTO", "TO",
  "UNTIL", "EMPTY", "'('", "')'", "';'", "'.'", "','", "':'", "'['", "']'",
  "$accept", "start", "program", "$@1", "$@2", "$@3", "ident_list",
  "decls", "type", "std_type", "subprogram_decls", "subprogram_decl",
  "$@4", "subprogram_head", "fn_header", "$@5", "$@6", "proc_header",
  "$@7", "$@8", "param_list", "param", "compound_stmt", "opt_stmts",
  "stmt_list", "stmt", "$@9", "$@10", "$@11", "var", "procedure_stmt",
  "expr_list", "expr", "simple_expr", "term", "factor", "id", "fn", "inum",
  "rnum", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,    14,    39,   -71,   -71,   -71,   -71,   -15,    35,   -71,
      -8,   -71,    44,    21,   -71,   -71,    58,    35,    38,    17,
      14,    14,    50,    42,   -71,     3,    36,    37,    43,    45,
       5,    46,   -71,    58,    47,   -71,   -71,    49,   -71,    41,
      48,   -71,   -71,    52,   -71,   -71,     4,   -71,    55,    53,
     -71,    74,   -71,    -3,   -71,    38,    90,   -71,    56,    35,
      35,   -71,   -71,     7,     7,     4,    34,    40,    89,   -71,
     -16,   -71,   -71,   -71,     5,     4,     4,     4,    50,    75,
     -71,    24,    29,   -71,    32,    89,   -71,    59,   -71,   -71,
       7,     4,     7,     4,     4,   -71,   -71,     9,   -71,    57,
     -71,    90,     3,   -71,    35,   -71,   -71,     5,     5,    89,
      95,   -71,    13,    60,   -71,     4,   -71,    61,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,    81,    69,    41,     5,   -71,
     -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,    67,     3,     1,     0,     0,     7,
       0,     4,     0,     0,     8,    10,    16,     0,     5,     0,
       0,     0,     0,     0,    10,     0,     0,    21,     0,    25,
      34,     0,    15,    16,     0,    13,    14,     0,    11,     0,
       0,    24,    20,     0,    28,    66,     0,    39,     0,    33,
      35,     0,    38,    47,     6,    17,     0,     9,     0,     0,
       0,    68,    69,     0,     0,     0,     0,    52,    54,    57,
      59,    62,    63,    32,     0,     0,    51,     0,     0,     0,
      19,     0,     0,    29,     0,    55,    65,     0,    40,    42,
       0,     0,     0,    51,     0,    36,    37,     0,    49,     0,
      18,     0,     0,    22,     0,    26,    64,     0,     0,    56,
      53,    58,     0,     0,    48,     0,    46,     0,    31,    30,
      41,    43,    61,    60,    50,     0,     0,     0,     0,    12,
      44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -71,   -71,   -71,   -71,    11,    80,     6,   -38,
      72,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
      51,     8,   -19,   -71,   -71,   -70,   -71,   -71,   -71,   -71,
     -71,    16,   -44,    19,   -49,   -52,   -30,    54,   -50,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     7,    13,    22,    81,    16,    37,    38,
      18,    23,    78,    24,    26,    40,    41,    28,    43,    44,
      82,    83,    47,    48,    49,    50,   107,   108,   126,    51,
      52,    97,    98,    67,    68,    69,    70,     5,    71,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    58,    66,    31,    95,   -45,    79,    61,    62,    63,
      61,    62,    86,    64,    85,     1,    64,    45,    45,    10,
      45,    87,    34,    93,     8,    35,    36,     4,    19,    94,
      46,    96,    11,    99,    30,    12,    76,   120,   121,     6,
     111,   109,    77,    65,    53,    90,    65,    91,     9,   114,
     113,   117,   115,   122,    20,    21,   115,    14,   130,   100,
      12,    25,    15,    35,    36,    88,    89,    12,   102,   103,
     104,   124,   105,   104,    27,    29,    17,    53,    53,    30,
      39,   -23,    75,    32,    42,    73,   -27,    59,    54,   129,
      57,    60,    56,    61,    74,    92,   101,    80,    53,   106,
      90,   127,   128,   116,    33,    55,   123,   125,   118,   112,
     110,    84,   119
};

static const yytype_uint8 yycheck[] =
{
      30,    39,    46,    22,    74,     8,    56,     3,     4,     5,
       3,     4,    64,     9,    63,    15,     9,    13,    13,     8,
      13,    65,    19,    39,    39,    22,    23,    13,    17,    45,
      25,    75,    40,    77,    29,    43,    39,   107,   108,     0,
      92,    90,    45,    39,    74,     5,    39,     7,    13,    40,
      94,   101,    43,    40,    16,    17,    43,    13,   128,    78,
      43,    44,    41,    22,    23,    31,    32,    43,    44,    40,
      41,   115,    40,    41,    20,    21,    18,   107,   108,    29,
      44,    44,     8,    41,    41,    30,    41,    39,    42,   127,
      41,    39,    45,     3,    41,     6,    21,    41,   128,    40,
       5,    20,    33,    46,    24,    33,    46,    46,   102,    93,
      91,    60,   104
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    48,    49,    13,    84,     0,    50,    39,    13,
      53,    40,    43,    51,    13,    41,    54,    18,    57,    53,
      16,    17,    52,    58,    60,    44,    61,    84,    64,    84,
      29,    69,    41,    54,    19,    22,    23,    55,    56,    44,
      62,    63,    41,    65,    66,    13,    25,    69,    70,    71,
      72,    76,    77,    83,    42,    57,    45,    41,    56,    39,
      39,     3,     4,     5,     9,    39,    79,    80,    81,    82,
      83,    85,    86,    30,    41,     8,    39,    45,    59,    85,
      41,    53,    67,    68,    67,    81,    82,    79,    31,    32,
       5,     7,     6,    39,    45,    72,    79,    78,    79,    79,
      69,    21,    44,    40,    41,    40,    40,    73,    74,    81,
      80,    82,    78,    79,    40,    43,    46,    85,    55,    68,
      72,    72,    40,    46,    79,    46,    75,    20,    33,    56,
      72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    50,    51,    52,    49,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    59,    58,    60,
      60,    62,    61,    63,    61,    65,    64,    66,    64,    67,
      67,    68,    69,    70,    70,    71,    71,    72,    72,    72,
      73,    72,    74,    75,    72,    76,    76,    77,    77,    78,
      78,    78,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    83,    84,    85,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     0,     0,    13,     1,     3,     6,
       0,     1,     8,     1,     1,     3,     0,     0,     5,     5,
       3,     0,     5,     0,     2,     0,     5,     0,     2,     1,
       3,     3,     3,     1,     0,     1,     3,     3,     1,     1,
       0,     5,     0,     0,     8,     1,     4,     1,     4,     1,
       3,     0,     1,     3,     1,     2,     3,     1,     3,     1,
       4,     4,     1,     1,     3,     2,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
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
| yyreduce -- do a reduction.  |
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* start: program  */
#line 173 "parser.y"
                { print_tree((yyvsp[0].tval), 0); }
#line 1939 "y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 176 "parser.y"
                     { push_table((yyvsp[0].tval)->attribute.sval, FUNCTION); }
#line 1945 "y.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 176 "parser.y"
                                                                                      { add_io((yyvsp[-1].tval)); }
#line 1951 "y.tab.c"
    break;

  case 5: /* $@3: %empty  */
#line 176 "parser.y"
                                                                                                                                 { main_header(); caller = top_table(); }
#line 1957 "y.tab.c"
    break;

  case 6: /* program: PROGRAM fn $@1 '(' ident_list ')' $@2 ';' decls subprogram_decls $@3 compound_stmt '.'  */
#line 177 "parser.y"
                {
			(yyval.tval) = str_tree(PROGRAM, "head body",
					op_tree(PARENOP, "()", (yyvsp[-11].tval), (yyvsp[-8].tval)),
					str_tree(PROGRAM, "decls compound_stmt",
						str_tree(PROGRAM, "decls sub_decls", (yyvsp[-4].tval), (yyvsp[-3].tval)),
					(yyvsp[-1].tval))
				);
			main_footer();
			print_table(top_table());
			pop_table();
		}
#line 1973 "y.tab.c"
    break;

  case 7: /* ident_list: IDENT  */
#line 191 "parser.y"
                {
			(yyval.tval) = op_tree(LISTOP, ",", 
					empty_tree(),
					str_tree(IDENT, (yyvsp[0].sval), empty_tree(), empty_tree())
				);
		}
#line 1984 "y.tab.c"
    break;

  case 8: /* ident_list: ident_list ',' IDENT  */
#line 198 "parser.y"
                {
			(yyval.tval) = op_tree(LISTOP, ",", 
					(yyvsp[-2].tval),
					str_tree(IDENT, (yyvsp[0].sval), empty_tree(), empty_tree())
				);
		}
#line 1995 "y.tab.c"
    break;

  case 9: /* decls: decls VAR ident_list ':' type ';'  */
#line 207 "parser.y"
                {
			(yyval.tval) = op_tree(LISTOP, ":",
					op_tree(VAR, (yyvsp[-4].sval), (yyvsp[-5].tval), (yyvsp[-3].tval)),
				 (yyvsp[-1].tval));
			make_vars((yyvsp[-3].tval), (yyvsp[-1].tval));
		}
#line 2006 "y.tab.c"
    break;

  case 10: /* decls: %empty  */
#line 214 "parser.y"
                { (yyval.tval) = empty_tree(); }
#line 2012 "y.tab.c"
    break;

  case 11: /* type: std_type  */
#line 218 "parser.y"
                { (yyval.tval) = (yyvsp[0].tval); }
#line 2018 "y.tab.c"
    break;

  case 12: /* type: ARRAY '[' inum DOTDOT inum ']' OF std_type  */
#line 220 "parser.y"
                { 
			(yyval.tval) = str_tree(ARRAY, "array-range type",
					op_tree(DOTDOT, (yyvsp[-4].sval), (yyvsp[-5].tval), (yyvsp[-3].tval)),
				 (yyvsp[0].tval));
		}
#line 2028 "y.tab.c"
    break;

  case 13: /* std_type: INTEGER  */
#line 228 "parser.y"
                { (yyval.tval) = str_tree(INTEGER, (yyvsp[0].sval), empty_tree(), empty_tree()); }
#line 2034 "y.tab.c"
    break;

  case 14: /* std_type: REAL  */
#line 230 "parser.y"
                { (yyval.tval) = str_tree(REAL, (yyvsp[0].sval), empty_tree(), empty_tree()); }
#line 2040 "y.tab.c"
    break;

  case 15: /* subprogram_decls: subprogram_decls subprogram_decl ';'  */
#line 234 "parser.y"
                { (yyval.tval) = op_tree(LISTOP, "_", (yyvsp[-2].tval), (yyvsp[-1].tval)); }
#line 2046 "y.tab.c"
    break;

  case 16: /* subprogram_decls: %empty  */
#line 236 "parser.y"
                { (yyval.tval) = empty_tree(); }
#line 2052 "y.tab.c"
    break;

  case 17: /* $@4: %empty  */
#line 239 "parser.y"
                                                         { function_header((yyvsp[-2].tval)); caller = top_table(); }
#line 2058 "y.tab.c"
    break;

  case 18: /* subprogram_decl: subprogram_head decls subprogram_decls $@4 compound_stmt  */
#line 240 "parser.y"
                {
			check_function((yyvsp[-4].tval), (yyvsp[0].tval));
			(yyval.tval) = op_tree(LISTOP, "_", (yyvsp[-4].tval), 
					op_tree(LISTOP, "_", (yyvsp[-3].tval), 
						op_tree(LISTOP, "_", (yyvsp[-2].tval), (yyvsp[0].tval))
					)
				 );
			function_footer((yyvsp[-4].tval)); 
			print_table(top_table());
			pop_table();
		}
#line 2074 "y.tab.c"
    break;

  case 19: /* subprogram_head: FUNCTION fn_header ':' std_type ';'  */
#line 254 "parser.y"
                {
			(yyval.tval) = int_tree(FUNCTION, (yyvsp[-4].ival), (yyvsp[-3].tval), (yyvsp[-1].tval));
			make_function((yyvsp[-3].tval), (yyvsp[-1].tval));
			set_fn_assembly_label((yyvsp[-4].ival));
		}
#line 2084 "y.tab.c"
    break;

  case 20: /* subprogram_head: PROCEDURE proc_header ';'  */
#line 260 "parser.y"
                {
			(yyval.tval) = int_tree(PROCEDURE, (yyvsp[-2].ival), (yyvsp[-1].tval), empty_tree());
			make_procedure((yyvsp[-1].tval));
		}
#line 2093 "y.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 266 "parser.y"
               { push_table((yyvsp[0].tval)->attribute.sval, FUNCTION); }
#line 2099 "y.tab.c"
    break;

  case 22: /* fn_header: fn $@5 '(' param_list ')'  */
#line 267 "parser.y"
                { 
			add_params((yyvsp[-1].tval));
			(yyval.tval) = op_tree(PARENOP, "()", (yyvsp[-4].tval), (yyvsp[-1].tval));
		}
#line 2108 "y.tab.c"
    break;

  case 23: /* $@6: %empty  */
#line 271 "parser.y"
             { push_table((yyvsp[0].tval)->attribute.sval, FUNCTION); }
#line 2114 "y.tab.c"
    break;

  case 24: /* fn_header: fn $@6  */
#line 272 "parser.y"
                { (yyval.tval) = (yyvsp[-1].tval); }
#line 2120 "y.tab.c"
    break;

  case 25: /* $@7: %empty  */
#line 275 "parser.y"
                 { push_table((yyvsp[0].tval)->attribute.sval, PROCEDURE); }
#line 2126 "y.tab.c"
    break;

  case 26: /* proc_header: fn $@7 '(' param_list ')'  */
#line 276 "parser.y"
                { 
			add_params((yyvsp[-1].tval));
			(yyval.tval) = op_tree(PARENOP, "()", (yyvsp[-4].tval), (yyvsp[-1].tval));
		}
#line 2135 "y.tab.c"
    break;

  case 27: /* $@8: %empty  */
#line 280 "parser.y"
             { push_table((yyvsp[0].tval)->attribute.sval, PROCEDURE); }
#line 2141 "y.tab.c"
    break;

  case 28: /* proc_header: fn $@8  */
#line 281 "parser.y"
                { (yyval.tval) = (yyvsp[-1].tval); }
#line 2147 "y.tab.c"
    break;

  case 29: /* param_list: param  */
#line 285 "parser.y"
                { (yyval.tval) = op_tree(LISTOP, ";", empty_tree(), (yyvsp[0].tval)); }
#line 2153 "y.tab.c"
    break;

  case 30: /* param_list: param_list ';' param  */
#line 287 "parser.y"
                { (yyval.tval) = op_tree(LISTOP, ";", (yyvsp[-2].tval), (yyvsp[0].tval)); }
#line 2159 "y.tab.c"
    break;

  case 31: /* param: ident_list ':' type  */
#line 291 "parser.y"
                { (yyval.tval) = op_tree(LISTOP, ":", (yyvsp[-2].tval), (yyvsp[0].tval)); }
#line 2165 "y.tab.c"
    break;

  case 32: /* compound_stmt: BEG opt_stmts END  */
#line 296 "parser.y"
                { (yyval.tval) = str_tree(BEG, "begin-end", (yyvsp[-1].tval), empty_tree()); }
#line 2171 "y.tab.c"
    break;

  case 33: /* opt_stmts: stmt_list  */
#line 300 "parser.y"
                { (yyval.tval) = (yyvsp[0].tval); }
#line 2177 "y.tab.c"
    break;

  case 34: /* opt_stmts: %empty  */
#line 302 "parser.y"
                { (yyval.tval) = empty_tree(); }
#line 2183 "y.tab.c"
    break;

  case 35: /* stmt_list: stmt  */
#line 306 "parser.y"
                { (yyval.tval) = (yyvsp[0].tval); }
#line 2189 "y.tab.c"
    break;

  case 36: /* stmt_list: stmt_list ';' stmt  */
#line 308 "parser.y"
                { (yyval.tval) = op_tree(LISTOP, ";", (yyvsp[-2].tval), (yyvsp[0].tval)); }
#line 2195 "y.tab.c"
    break;

  case 37: /* stmt: var ASSOP expr  */
#line 312 "parser.y"
                { 
			check_types((yyvsp[-2].tval), (yyvsp[0].tval));
			(yyval.tval) = op_tree(ASSOP, (yyvsp[-1].opval), (yyvsp[-2].tval), (yyvsp[0].tval));
			assignment_gencode((yyval.tval));
		}
#line 2205 "y.tab.c"
    break;

  case 38: /* stmt: procedure_stmt  */
#line 318 "parser.y"
                { 
			(yyval.tval) = (yyvsp[0].tval);
			call_procedure((yyval.tval));
		}
#line 2214 "y.tab.c"
    break;

  case 39: /* stmt: compound_stmt  */
#line 323 "parser.y"
                { (yyval.tval) = (yyvsp[0].tval); }
#line 2220 "y.tab.c"
    break;

  case 40: /* $@9: %empty  */
#line 324 "parser.y"
                       { start_if_gencode((yyvsp[-1].tval), (yyvsp[-2].ival)); }
#line 2226 "y.tab.c"
    break;

  case 41: /* stmt: IF expr THEN $@9 stmt  */
#line 325 "parser.y"
                {
			(yyval.tval) = str_tree(IF, "if then", (yyvsp[-3].tval), (yyvsp[0].tval));
			enforce_type((yyvsp[-3].tval), BOOL);
			end_if_gencode((yyvsp[-4].ival));
		}
#line 2236 "y.tab.c"
    break;

  case 42: /* $@10: %empty  */
#line 330 "parser.y"
                       { start_if_else_gencode((yyvsp[-1].tval), (yyvsp[-2].ival)); }
#line 2242 "y.tab.c"
    break;

  case 43: /* $@11: %empty  */
#line 330 "parser.y"
                                                               { mid_if_else_gencode((yyvsp[-4].ival)); }
#line 2248 "y.tab.c"
    break;

  case 44: /* stmt: IF expr THAN $@10 stmt $@11 ELSE stmt  */
#line 331 "parser.y"
                {
			(yyval.tval) = str_tree(IF, "if then-else", (yyvsp[-6].tval), str_tree(IF, "then else", (yyvsp[-3].tval), (yyvsp[0].tval)));
			enforce_type((yyvsp[-6].tval), BOOL);
			end_if_gencode(((yyvsp[-7].ival)+1));
		}
#line 2258 "y.tab.c"
    break;

  case 45: /* var: id  */
#line 339 "parser.y"
                { (yyval.tval) = (yyvsp[0].tval); }
#line 2264 "y.tab.c"
    break;

  case 46: /* var: id '[' expr ']'  */
#line 341 "parser.y"
                { (yyval.tval) = op_tree(ARRAYOP, "[]", (yyvsp[-3].tval), (yyvsp[-1].tval)); }
#line 2270 "y.tab.c"
    break;

  case 47: /* procedure_stmt: id  */
#line 344 "parser.y"
                    { (yyval.tval) = (yyvsp[0].tval); }
#line 2276 "y.tab.c"
    break;

  case 48: /* procedure_stmt: id '(' expr_list ')'  */
#line 346 "parser.y"
                { 
			(yyval.tval) = op_tree(PARENOP, "()", (yyvsp[-3].tval), (yyvsp[-1].tval));
			entry_t* fn_entry = find_entry(top_table(), (yyvsp[-3].tval)->attribute.sval);
			check_args(fn_entry, (yyvsp[-1].tval));
		}
#line 2286 "y.tab.c"
    break;

  case 49: /* expr_list: expr  */
#line 354 "parser.y"
                { (yyval.tval) = op_tree(LISTOP, ",", empty_tree(), (yyvsp[0].tval)); }
#line 2292 "y.tab.c"
    break;

  case 50: /* expr_list: expr_list ',' expr  */
#line 356 "parser.y"
                { (yyval.tval) = op_tree(LISTOP, ",", (yyvsp[-2].tval), (yyvsp[0].tval)); }
#line 2298 "y.tab.c"
    break;

  case 51: /* expr_list: %empty  */
#line 358 "parser.y"
                { (yyval.tval) = op_tree(LISTOP, ",", empty_tree(), empty_tree()); }
#line 2304 "y.tab.c"
    break;

  case 52: /* expr: simple_expr  */
#line 362 "parser.y"
                { 
			tree_t* t = (yyvsp[0].tval);
			number_tree(t);
			type(t);
			(yyval.tval) = t;
		}
#line 2315 "y.tab.c"
    break;

  case 53: /* expr: simple_expr RELOP simple_expr  */
#line 369 "parser.y"
                { 
			tree_t* t = op_tree(RELOP, (yyvsp[-1].opval), (yyvsp[-2].tval), (yyvsp[0].tval));
			number_tree(t);
			type(t);
			(yyval.tval) = t;
		}
#line 2326 "y.tab.c"
    break;

  case 54: /* simple_expr: term  */
#line 378 "parser.y"
                { (yyval.tval) = (yyvsp[0].tval); }
#line 2332 "y.tab.c"
    break;

  case 55: /* simple_expr: ADDOP term  */
#line 380 "parser.y"
                { 	
			(yyval.tval) = op_tree(ADDOP, (yyvsp[-1].opval), 
					int_tree(INUM, 0, empty_tree(), empty_tree()), 
					(yyvsp[0].tval)
				);
		}
#line 2343 "y.tab.c"
    break;

  case 56: /* simple_expr: simple_expr ADDOP term  */
#line 387 "parser.y"
                { (yyval.tval) = op_tree(ADDOP, (yyvsp[-1].opval), (yyvsp[-2].tval), (yyvsp[0].tval)); }
#line 2349 "y.tab.c"
    break;

  case 57: /* term: factor  */
#line 391 "parser.y"
                { (yyval.tval) = (yyvsp[0].tval); }
#line 2355 "y.tab.c"
    break;

  case 58: /* term: term MULOP factor  */
#line 393 "parser.y"
                { (yyval.tval) = op_tree(MULOP, (yyvsp[-1].opval), (yyvsp[-2].tval), (yyvsp[0].tval)); }
#line 2361 "y.tab.c"
    break;

  case 59: /* factor: id  */
#line 397 "parser.y"
                { (yyval.tval) = (yyvsp[0].tval); }
#line 2367 "y.tab.c"
    break;

  case 60: /* factor: id '[' expr ']'  */
#line 399 "parser.y"
                { (yyval.tval) = op_tree(ARRAYOP, "[]", (yyvsp[-3].tval), (yyvsp[-1].tval)); }
#line 2373 "y.tab.c"
    break;

  case 61: /* factor: id '(' expr_list ')'  */
#line 401 "parser.y"
                {
			(yyval.tval) = op_tree(PARENOP, "()", (yyvsp[-3].tval), (yyvsp[-1].tval));
			call_function((yyval.tval));
		}
#line 2382 "y.tab.c"
    break;

  case 62: /* factor: inum  */
#line 406 "parser.y"
                { (yyval.tval) = (yyvsp[0].tval); }
#line 2388 "y.tab.c"
    break;

  case 63: /* factor: rnum  */
#line 408 "parser.y"
                { (yyval.tval) = (yyvsp[0].tval); }
#line 2394 "y.tab.c"
    break;

  case 64: /* factor: '(' expr ')'  */
#line 410 "parser.y"
                { (yyval.tval) = (yyvsp[-1].tval); }
#line 2400 "y.tab.c"
    break;

  case 65: /* factor: NOT factor  */
#line 412 "parser.y"
                { (yyval.tval) = op_tree(NOT, (yyvsp[-1].opval), (yyvsp[0].tval), empty_tree()); }
#line 2406 "y.tab.c"
    break;

  case 66: /* id: IDENT  */
#line 416 "parser.y"
                { (yyval.tval) = str_tree(IDENT, (yyvsp[0].sval), empty_tree(), empty_tree()); }
#line 2412 "y.tab.c"
    break;

  case 67: /* fn: IDENT  */
#line 420 "parser.y"
                { (yyval.tval) = str_tree(IDENT, (yyvsp[0].sval), empty_tree(), empty_tree()); }
#line 2418 "y.tab.c"
    break;

  case 68: /* inum: INUM  */
#line 423 "parser.y"
                { (yyval.tval) = int_tree(INUM, (yyvsp[0].ival), empty_tree(), empty_tree()); }
#line 2424 "y.tab.c"
    break;

  case 69: /* rnum: RNUM  */
#line 427 "parser.y"
                { (yyval.tval) = float_tree(RNUM, (yyvsp[0].fval), empty_tree(), empty_tree()); }
#line 2430 "y.tab.c"
    break;


#line 2434 "y.tab.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 430 "parser.y"

