%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "y.tab.h"

int assemblyLabelNum = 1;

%}

identifier     [a-zA-Z][a-zA-Z0-9]*
integerLiteral [0-9]+
realLiteral    [0-9]*"."[0-9]+
relationalOp   "<"|">"|"="|">="|"<="|"<>"
addOperator    "+"|"-"|"or"
multiplyOperator "*"|"/"|"and"
dotdot         ".."
whitespace     [ \t]+
endline        [\r\n]
string         "'"[a-zA-Z0-9 ]*"'"

%x     COMMENT1
%x     COMMENT2
%x     COMMENT3

%option yyLineNo

%%

"{"                   { BEGIN COMMENT1; }
<COMMENT1>[^}]        { ; }
<COMMENT1>"}"         { fprintf(stderr, " {COMMENT}"); BEGIN INITIAL; }

"(*"                  { BEGIN COMMENT2; }
<COMMENT2>.           |
<COMMENT2>\n          { ; }
<COMMENT2>"*)"        { fprintf(stderr, " (*COMMENT*)"); BEGIN INITIAL; }

"//"                  { BEGIN COMMENT3; }
<COMMENT3>.           { ; }
<COMMENT3>\n          { fprintf(stderr, " //COMMENT"); BEGIN INITIAL; }

{realLiteral}         { fprintf(stderr, " [RNUM:%f]", yylval.fval = atof(yytext)); return REAL_LITERAL; }
{integerLiteral}      { fprintf(stderr, " [INUM:%d]", yylval.ival = atoi(yytext)); return INTEGER_LITERAL; }

{relationalOp}        { fprintf(stderr, " [RELOP:%s]", yylval.opval = strdup(yytext)); return RELATIONAL_OPERATOR; } 
{addOperator}         { fprintf(stderr, " [ADDOP:%s]", yylval.opval = strdup(yytext)); return ADD_OPERATOR; }
{multiplyOperator}    { fprintf(stderr, " [MULOP:%s]", yylval.opval = strdup(yytext)); return MULTIPLY_OPERATOR; }
:=                    { fprintf(stderr, " [ASSOP]"); yylval.opval = strdup(yytext); return ASSIGNMENT_OPERATOR; }
not                   { fprintf(stderr, " [LOGICAL_NOT]"); yylval.opval = strdup(yytext); return LOGICAL_NOT; }

program               { fprintf(stderr, " [PROGRAM]"); yylval.sval = strdup(yytext); return PROGRAM; }
function              { fprintf(stderr, " [FUNCTION]"); yylval.ival = assemblyLabelNum; assemblyLabelNum++; return FUNCTION; }
procedure             { fprintf(stderr, " [PROCEDURE]"); yylval.ival = assemblyLabelNum; assemblyLabelNum++; return PROCEDURE; }

var                   { fprintf(stderr, " [VAR]"); yylval.sval = strdup(yytext); return VAR; }
array                 { fprintf(stderr, " [ARRAY]"); yylval.sval = strdup(yytext); return ARRAY; }
of                    { fprintf(stderr, " [OF]"); yylval.sval = strdup(yytext); return OF; }
{dotdot}              { fprintf(stderr, " [DOTDOT]"); yylval.sval = strdup(yytext); return DOTDOT; }
integer               { fprintf(stderr, " [INTEGER]"); yylval.sval = strdup(yytext); return INTEGER; }
real                  { fprintf(stderr, " [REAL]"); yylval.sval = strdup(yytext); return REAL; }

if                    { fprintf(stderr, " [IF]"); yylval.ival = assemblyLabelNum; assemblyLabelNum += 2; return IF; }
then                  { fprintf(stderr, " [THEN]"); yylval.sval = strdup(yytext); return THEN; }
than                  { fprintf(stderr, " [THAN]"); yylval.sval = strdup(yytext); return THAN; }
else                  { fprintf(stderr, " [ELSE]"); yylval.sval = strdup(yytext); return ELSE; }
do                    { fprintf(stderr, " [DO]"); yylval.sval = strdup(yytext); return DO; }
while                 { fprintf(stderr, " [WHILE]"); yylval.ival = assemblyLabelNum; assemblyLabelNum += 2; return WHILE; }
for                   { fprintf(stderr, " [FOR]"); yylval.ival = assemblyLabelNum; assemblyLabelNum += 2; return FOR; }
to                    { fprintf(stderr, " [TO]"); yylval.sval = strdup(yytext); return TO; }
downto                { fprintf(stderr, " [DOWNTO]"); yylval.sval = strdup(yytext); return DOWNTO; }
repeat                { fprintf(stderr, " [REPEAT]"); yylval.ival = assemblyLabelNum; assemblyLabelNum++; return REPEAT; }
until                 { fprintf(stderr, " [UNTIL]"); yylval.sval = strdup(yytext); return UNTIL; }
begin                 { fprintf(stderr, " [BEGIN]"); yylval.sval = strdup(yytext); return BEG; }
end                   { fprintf(stderr, " [END]"); yylval.sval = strdup(yytext); return END; }

{identifier}          { fprintf(stderr, " [IDENT:%s]", yylval.sval = strdup(yytext)); return IDENT; }
{string}              { fprintf(stderr, " [STRING:%s]", yylval.sval = strdup(yytext)); return STRING; }

{whitespace}          { ; }
{endline}             { fprintf(stderr, "\n%d ", yyLineNo); }
.                     { fprintf(stderr, " {%c}", yytext[0]); return yytext[0]; }

%%
