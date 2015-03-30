
%{
#include <stdio.h>

#include <string.h>

#include "goyal.h"
%}


%%
(\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/)|(\/\/.*) {yylval.id_val = yytext;}
[ \t]+ ;
"main" 			{yylval.id_val = yytext; return(MAIN);}
"if"				{yylval.id_val = yytext; return(IF);}
"elif" 			{yylval.id_val = yytext; return(ELIF);}
"else" 			{yylval.id_val = yytext; return(ELSE);}
"switch" 			{yylval.id_val = yytext; return(SWITCH);}
"case" 			{yylval.id_val = yytext; return(CASE );}
"default" 		{yylval.id_val = yytext; return(DEFAULT);}
"do" 				{yylval.id_val = yytext; return(DO);}
"return" 			{yylval.id_val = yytext; return(RETURN );}
"void"			{yylval.id_val = yytext; return(VOID );}
"struct" 			{yylval.id_val = yytext; return(STRUCT );}
"int" 			{yylval.id_val = yytext; return(INT );}
"float" 			{yylval.id_val = yytext; return(FLOAT );}
"bool" 			{yylval.id_val = yytext; return(BOOL );}
"double" 			{yylval.id_val = yytext; return(DOUBLE );}
"char"			{yylval.id_val = yytext; return(CHAR );}
"for" 			{yylval.id_val = yytext; return(FOR);}
"while" 			{yylval.id_val = yytext; return(WHILE);}
"in" 				{yylval.id_val = yytext; return(IN);}
"out"				{yylval.id_val = yytext; return(OUT);}
"+" 				{yylval.id_val = yytext; return('+');}
"++" 			{yylval.id_val = yytext; return(INC_OP);}
"--"				{yylval.id_val = yytext; return(DEC_OP);}
"-"				{yylval.id_val = yytext; return('-');}
"*" 				{yylval.id_val = yytext; return('*');}
"/" 				{yylval.id_val = yytext; return('/');}
"%" 				{yylval.id_val = yytext; return('%');}
"=" 				{yylval.id_val = yytext; return('=');}
"=="				{yylval.id_val = yytext; return(DOUBLE_EQ_OP);}
"<="			{yylval.id_val = yytext; return(LESS_EQ_OP);}
">="				{yylval.id_val = yytext; return(GRE_EQ_OP);}
"<" 				{yylval.id_val = yytext; return('<');}
">" 				{yylval.id_val = yytext; return('>');}
"!" 				{yylval.id_val = yytext; return('!');}
"&&" 			{yylval.id_val = yytext; return(AND_OP);}
"^"				{yylval.id_val = yytext; return('^');}
"||"			{yylval.id_val = yytext; return(OR_OP);}
"<<" 			{yylval.id_val = yytext; return(OUT_OP);}
">>"			{yylval.id_val = yytext; return(INP_OP);}

[0-9]+ |
[0-9]+\.[0-9]+ |
\.[0-9]+	{yylval.id_val = yytext; return(CONSTANT);}
'(\\.|[^\\'])'						{ yylval.char_val = yytext[0];return CHAR_CONSTANT ;}
\"(\\.|[^\\"])*\"	 {yylval.id_val = yytext; return(STRING);}
"(" {yylval.id_val = yytext; return('(');}
")" {yylval.id_val = yytext; return(')');}
"{" {yylval.id_val = yytext; return('{');}
"}" {yylval.id_val = yytext; return('}');}
";" {yylval.id_val = yytext; return(';');}
"," {yylval.id_val = yytext; return(',');}
":" {yylval.id_val = yytext; return(':');}
[a-zA-Z][a-zA-Z0-9]* {yylval.id_val = yytext; return(IDENTIFIER);}
[\n]		{yylval.id_val = yytext;};
%%