%{
#include <stdio.h>
%}



%%
[ \t]+ ;
main 			{printf("MAIN ");}
if 				{printf("IF");}
elif 			{printf("ELIF");}
else 			{printf("ELSE");}
switch 			{printf("SWITCH");}
case 			{printf("CASE ");}
default 		{printf("DEFAULT");}
do 				{printf("DO");}
return 			{printf("RETURN ");}
void			{printf("VOID ");}
struct 			{printf("STRUCT ");}
int 			{printf("INT ");}
float 			{printf("FLOAT ");}
bool 			{printf("BOOL ");}
double 			{printf("DOUBLE ");}
char			{printf("CHAR ");}
for 			{printf("FOR");}
while 			{printf("WHILE");}
in 				{printf("IN");}
out				{printf("OUT");}
\+ 				{printf("+");}
\++ 			{printf("++");}
\--				{printf("--");}
\- 				{printf("-");}
\* 				{printf("*");}
\/ 				{printf("/");}
\% 				{printf("%%");}
\= 				{printf("=");}
\==				{printf("==");}
\<=				{printf("<=");}
\>=				{printf(">=");}
\< 				{printf("<");}
\> 				{printf(">");}
\! 				{printf("!");}
\&& 			{printf("&&");}
\^ 				{printf("^");}
\|\|			{printf("||");}
\<\< 			{printf("<<");}
\>\>			{printf(">>");}

[0-9]+ |
[0-9]+\.[0-9]+ |
\.[0-9]+	{printf("CONSTANT");}
\"(\\.|[^\\"])*\" {printf("STRING");}
\( {printf("(");}
\) {printf(")");}
\{ {printf("{");}
\} {printf("}");}
\; {printf(";");}
\, {printf(",");}
\: {printf(":");}
[a-zA-Z][a-zA-Z0-9]* {printf("IDENTIFIER");}
[\n]		;
(\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/)|(\/\/.*) {printf("COMMENT ");}
%%



int yywrap(void){
	return 1;
}

int main(){
	yylex();
	return 0;
}