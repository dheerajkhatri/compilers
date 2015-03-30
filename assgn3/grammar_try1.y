%{
	#include <stdio.h>
	#include<stdlib.h>
	extern int yylex(void);
	extern int mylineno ;
	extern char* yytext ;
	void yyerror(char *);
%}
%token IDENTIFIER SEMI INT FLOAT BOOL LP RP COMMA  LCB RCB WHILE FOR IF IFX ELSE EQUALS PLUS MINUS DOUBLE_EQ GREATER GREATER_EQ LESS LESS_EQ NOT_EQ MULT DIV NUMBER BREAK RETURN INCR DECR AND OR NOT MAIN TRUE FALSE FLOAT_NUM VOID
%start START_CODE 
%%

START_CODE			: 		declaration_list MAIN LP parameters_list RP Compound_statements
  				;
  					
declaration_list		:		declaration_list declaration		
				|		declaration							
				;
						
declaration			:		variable_declaration				
				|		function_declaration					
				;

variable_declaration		:		type_specifier IDENTIFIER SEMI
				;

type_specifier			:		INT
				|		FLOAT
				|		BOOL
				|		VOID
				;
									
function_declaration		: 		type_specifier IDENTIFIER LP parameters_list RP Compound_statements		
				;


parameters_list			:               parameters_list COMMA parameters
				|		parameters
				|
				;
							
parameters			:		type_specifier	IDENTIFIER
				;

Statement_list			:		Statement_list	Statements					
				| 													
				;	

Statements			:		Function_call_statements	
				|		Compound_statements
				|		Loop_statements
				|		Condition_statements
				|		Expression_statements 
				|		Break_statement
				|		Return_statement
				;

Function_call_statements	:		IDENTIFIER EQUALS IDENTIFIER LP Identifier_list RP SEMI
				|		IDENTIFIER LP Identifier_list RP SEMI
				;
				
Identifier_list			:		Identifier_list COMMA IDENTIFIER
				|		IDENTIFIER
				|
				;

Compound_statements		:		LCB local_declaration Statement_list RCB
				;
						
local_declaration		:		local_declaration variable_declaration							
				| 													
				;
				
											



Loop_statements			:		WHILE LP expression RP Statements			
				|		FOR LP Expression_statements expression SEMI Expression_statements RP Statements		
				;



Condition_statements		:		IF LP expression RP Statements 		
				|		IFX LP expression RP Statements ELSE Statements
				;


Expression_statements		:		IDENTIFIER EQUALS expression SEMI
				|		IDENTIFIER INCR	SEMI
				|		IDENTIFIER DECR	SEMI
				|		INCR IDENTIFIER SEMI
				|		DECR IDENTIFIER	SEMI
				|		expression	SEMI
				;		


expression			:		expression   operators_bitwise   expression_relation
				|		expression_relation
				;

expression_relation		:		expression_relation operators_relation expression_addsub
				|		expression_addsub
				;

						
expression_addsub		: 		expression_addsub  operators_addsub expression_multdiv						
				|		expression_multdiv
				;

						
expression_multdiv		:		expression_multdiv operators_multdiv expression_simple
				|		expression_simple
				;

						
expression_simple		:		LP expression RP
				|		NOT expression_simple
				|		operators_addsub expression_simple
				|		NUMBER
				|		TRUE
				|		FALSE
				|		FLOAT_NUM
				|		IDENTIFIER
				;

																									


Break_statement			:		BREAK SEMI
				;



Return_statement		:		RETURN expression SEMI
				|		RETURN SEMI
				;													
			


operators_bitwise		:		AND
				|		OR
				;

operators_relation		:		DOUBLE_EQ
				|		GREATER_EQ
				|		GREATER
				|		LESS_EQ
				|		LESS
				|		NOT_EQ
				;
						
operators_addsub		:		PLUS
				|		MINUS
						;

operators_multdiv		:		MULT
				|		DIV
				;
 	
%%

int main()
{
	yyparse();
}
void yyerror (char *s) { printf("Error in line: %d, text: %s \n", mylineno, yytext);}



 					
