DIGIT			[0-9]
ALPHABETS		[a-zA-Z_]

%{
#include <stdio.h>
#include "heading.h"
#include "tok.h"
extern int line_num;
void incr_linenum();
void incr_text();
%}

%%
"//".*"\n"		{incr_linenum(); }
"/*".*"*/"		{ incr_text();}

"if"			{ yylval.id_val = yytext; return IF ; }
"struct"		{ yylval.id_val = yytext; return STRUCT ; }
"void"			{ yylval.id_val = yytext; return VOID ; }
"long"			{ yylval.id_val = yytext; return LONG ; }
"short"			{ yylval.id_val = yytext; return SHORT ; }
"continue"		{ yylval.id_val = yytext; return CONTINUE ; }
"break"			{ yylval.id_val = yytext; return BREAK ; }
"while"			{ yylval.id_val = yytext; return WHILE ; }
"else"			{ yylval.id_val = yytext; return ELSE ; }
"sizeof"		{ yylval.id_val = yytext; return SIZEOF ; }
"return"		{ yylval.id_val = yytext; return RETURN ; }
"double"		{ yylval.id_val = yytext; return DOUBLE ; }
"float"			{ yylval.id_val = yytext; return FLOAT ; }
"int"			{ yylval.id_val = yytext; return INT ; }
"for"			{ yylval.id_val = yytext; return FOR ; }
"char"			{ yylval.id_val = yytext; return CHAR ; }
"bool"			{ yylval.id_val = yytext; return BOOL ; }
{ALPHABETS}({ALPHABETS}|{DIGIT})*	{ yylval.id_val = yytext;return IDENTIFIERS ;}
{DIGIT}+							{ yylval.id_val = yytext;return INTEGER_CONSTANT ;}
{DIGIT}+"."{DIGIT}+					{ yylval.id_val = yytext;return FLOAT_CONSTANT ;}
'(\\.|[^\\'])'						{ yylval.char_val = yytext[0];return CHARACTER_CONSTANT ;}
\"(\\.|[^\\"])*\"					{ yylval.id_val = (yytext);return STRING_CONSTANT ;}


">>"			{ yylval.id_val = yytext; return RIGHT_SHIFT_OP ; }
"<<"			{ yylval.id_val = yytext; return LEFT_SHIFT_OP ; }
"++"			{ yylval.id_val = yytext; return INCR_OP ; }
"--"			{ yylval.id_val = yytext; return DECR_OP ; }
"->"			{ yylval.id_val = yytext; return PTR_OP ; }
"&&"			{ yylval.id_val = yytext; return AND_OP ; }
"||"			{ yylval.id_val = yytext; return OR_OP ; }
"<="			{ yylval.id_val = yytext; return LESS_THAN_EQUAL_TO_OP ; }
">="			{ yylval.id_val = yytext; return GREATER_THAN_EQUAL_TO_OP ; }
"=="			{ yylval.id_val = yytext; return EQUAL_TO_OP ; }
"!="			{ yylval.id_val = yytext; return NOT_EQUAL_TO_OP ; }
";"				{ yylval.id_val = yytext; return ';' ; }
"{"				{ yylval.id_val = yytext; return '{' ; }
"}"				{ yylval.id_val = yytext; return '}' ; }
","				{ yylval.id_val = yytext; return ',' ; }
":"				{ yylval.id_val = yytext; return ':' ; }
"="				{ yylval.id_val = yytext; return '=' ; }
"("				{ yylval.id_val = yytext; return '(' ; }
")"				{ yylval.id_val = yytext; return ')' ; }
"["				{ yylval.id_val = yytext; return '[' ; }
"]"				{ yylval.id_val = yytext; return ']' ; }
"*"				{ yylval.id_val = yytext; return '*' ; }
"."				{ yylval.id_val = yytext; return '.' ; }
"/"				{ yylval.id_val = yytext; return '/' ; }
"+"				{ yylval.id_val = yytext; return '+' ; }
"!"				{ yylval.id_val = yytext; return '!' ; }
"&"				{ yylval.id_val = yytext; return '&' ; }
"@"				{ yylval.id_val = yytext; return '@' ; }
"~"				{ yylval.id_val = yytext; return '~' ; }
"-"				{ yylval.id_val = yytext; return '-' ; }
"%"				{ yylval.id_val = yytext; return '%' ; }
"<"				{ yylval.id_val = yytext; return '<' ; }
">"				{ yylval.id_val = yytext; return '>' ; }
"^"				{ yylval.id_val = yytext; return '^' ; }
"|"				{ yylval.id_val = yytext; return '|' ; }

[ \n]		{ incr_linenum();}
[ \t]        {;}
.				{ ECHO;}
%%

void incr_linenum()
{
	line_num++;
}

void incr_text()
{
	for (int i = 0; yytext[i] != '\0'; i++)
	{
		if (yytext[i] == '\n')
		{
			line_num++;
		}
	}
}
