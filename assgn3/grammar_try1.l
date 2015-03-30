%{
	#include <stdio.h>
	#include "y.tab.h"
	int yywrap(void);
	int mylineno = 1;
	
%}

DIGIT			[0-9]   
LETTER			[a-zA-Z_]
NUMBER			{DIGIT}+
FLOAT			{DIGIT}*"."{DIGIT}*
IDENTIFIER		{LETTER|"_"}+{DIGIT}*
BOOL			{"true"|"false"}

%%
[ \t]			;
\n			{ mylineno++ ; }
"==" 			{ 	printf("%s is a relational operator(DOUBLE_EQ)\n", yytext); 
				return(DOUBLE_EQ);
			}
"!=" 			{ printf("%s is a relational operator(NOT_EQ)\n", yytext); 
				return(NOT_EQ);
			}
main			{printf("%s is main(MAIN)\n", yytext);
			return(MAIN);}
"<=" 			{ printf("%s is a relational operator(LESS_EQ)\n", yytext); 
				return(LESS_EQ);
			}
">=" 			{ printf("%s is a relational operator(GREATER_EQ)\n", yytext); 
				return(GREATER_EQ);
			}
"++" 			{ printf("%s is a type operator(INCR)\n", yytext); 
				return(INCR);
			}
"--" 			{ printf("%s is a type operator(DECR)\n", yytext); 
				return(DECR);
			}
"+" 			{ printf("%s is a type operator(PLUS)\n", yytext); 
				return(PLUS);
			}
"-" 			{ printf("%s is a type operator(MINUS)\n", yytext); 
				return(MINUS);
			}
"*" 			{ printf("%s is a type operator(MULT)\n", yytext); 
				return(MULT);
			}
"/" 			{ printf("%s is a type operator(DIV)\n", yytext); 
				return(DIV);
			}
"=" 			{ printf("%s is a type operator(EQUALS)\n", yytext); 
				return(EQUALS);
			}
[<] 			{ printf("%s is a relative operator(LESS)\n", yytext); 
				return(LESS);				
			}
[>] 			{ printf("%s is a relative operator(GREATER\n", yytext); 
				return(GREATER);
			}
\{ 			{ printf("%s is a block begin(LCB)\n", yytext); 
				return(LCB);
			}
\} 			{ printf("%s is a block end(RCB)\n", yytext); 
				return(RCB);
			}
[\(] 			{ printf("%s is a delimiter(LP)\n", yytext); 
				return(LP);			
			}
[/)] 			{ printf("%s is a delimiter(RP)\n", yytext); 
				return(RP);
			}
[;] 			{ printf("%s is a delimiter(SEMI)\n", yytext); 
				return(SEMI);
			}
[,] 			{ printf("%s is a delimiter(COMMA)\n", yytext); 
				return(COMMA);			
			}
"and"			{printf("%s is a bitwise operator(AND)\n", yytext);
				return(AND);
			}
"or"			{printf("%s is a bitwise operator(OR)\n", yytext);
				return(OR);
			}
"not"			{printf("%s is a bitwise operator(NOT)\n", yytext);
				return(NOT);
			}

"break" 		{ printf("%s is a keyword(BREAK)\n", yytext); 
				return(BREAK);
			}

"true"      {
				printf("%s is a keyword(TRUE)\n",yytext);
				return(TRUE);
			}
"false"      {
				printf("%s is a keyword(FALSE)\n",yytext);
				return(FALSE);
			}

float 			{ printf("%s is a type specifier(FLOAT)\n", yytext); 
				return(FLOAT);
			}
int 			{ printf("%s is a type specifier(INT)\n", yytext); 
				return(INT);
			}
bool 			{ printf("%s is a type specifier(BOOL)\n", yytext); 
				return(BOOL);
			}
for 			{ printf("%s is an iteration(FOR)\n", yytext); 
				return(FOR);
			}
while 			{ printf("%s is an iteration(FOR)\n", yytext); 
				return(WHILE);
			}
if 			{ printf("%s is a conditional(IF)\n", yytext); 
				return(IF);
			}
ifx 			{ printf("%s is a conditional(IFX)\n", yytext); 
				return(IFX);
			}
else 			{ printf("%s is a conditional(ELSE\n", yytext); 
				return(ELSE);
			}
return 			{ printf("%s is a type keyword(RETURN)\n", yytext); 
				return(RETURN);
			}

void 			{	printf("%s is a type specifier(VOID)\n", yytext); 
				return(VOID);
			}
{DIGIT}+{LETTER}+ 	{ printf("%s is not allowed(error!) ", yytext); printf("Error is at %d line", yylineno);
				
			}
{LETTER}+{DIGIT}*			{ printf("%s is an identifier(IDENTIFIER)\n", yytext); 
						return(IDENTIFIER);
					}
{DIGIT}+				{ printf("%s is a number(NUMBER)\n", yytext); 
						return(NUMBER);
					}
{DIGIT}*"."{DIGIT}*			{ printf("%s is a number(FLOAT\n", yytext); 
						return(FLOAT_NUM);
					}
.				{return;}
%%

int yywrap(void)
{
	return 1 ;
}

