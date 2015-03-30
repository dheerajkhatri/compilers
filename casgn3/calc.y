/* calc.y */

%{
#include <bits/stdc++.h>
#include "heading.h"
void yyerror(char *s);
void yyerror(string);
int yylex(void);
int line_num = 1;


typedef struct node{
	vector<node*> child;	
	string node_name ;
	node (vector<node*> v,string attr)
	{
		child = v;
		node_name = attr;
	}
	node (string attr)
	{
		node_name = attr;
	}
}node;
node * wrap(char c);
node* mkleaf(string s);
node* mknode(vector<node*> v, string attr);
node* root = NULL;
void preorder(node* t);
%}
%error-verbose
%union{
  int		int_val;
  double 	decimal_val;
  char      char_val;
  char*     id_val;
  struct node*     ptr;
}

%token 	IF
%token 	STRUCT
%token 	VOID 
%token 	LONG 
%token 	SHORT 
%token 	CONTINUE
%token 	BREAK 
%token 	WHILE 
%token 	ELSE 
%token 	SIZEOF
%token 	RETURN 
%token 	DOUBLE
%token 	FLOAT 
%token 	INT 
%token 	FOR 
%token 	<id_val> CHAR
%token 	BOOL

%token 	IDENTIFIERS 
%token 	INTEGER_CONSTANT 
%token 	FLOAT_CONSTANT 
%token 	CHARACTER_CONSTANT 
%token 	STRING_CONSTANT
%token 	RIGHT_SHIFT_OP 
%token 	LEFT_SHIFT_OP 
%token 	INCR_OP 
%token 	DECR_OP 
%token 	PTR_OP 
%token 	AND_OP 
%token 	OR_OP 
%token 	LESS_THAN_EQUAL_TO_OP 
%token 	GREATER_THAN_EQUAL_TO_OP 
%token 	EQUAL_TO_OP 
%token 	NOT_EQUAL_TO_OP 




%left   TEMPPREC
%left	'&'
%left	'+' '-'
%left	'*' '/'
%left   INCR_OP DECR_OP '('

%type <ptr> Program Program_element Declaration Declarator_list Initializer Initializer_list Declarator Pointer Simple_declarator Expression_list Expression Pl1 Pl2 Pl3 Pl4 Pl5 Pl6 Pl7 Pl8 Pl9 Pl10 Pl11 Pl12 Unary_expression Basic_expression Unary_op Type Function Parameter_list Struct Struct_declaration_list SS Stmt if_Stmt for_Stmt while_Stmt

%start	Program

%%

/*--------------------------------------------------------------------------------*/


Program      			: Program_element 									{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Program");root = $$; preorder(root); cout<<"//////";}
			 			;

Program_element 		: Function Program_element 							{vector<node*> v ; v.push_back($1) ; v.push_back($2);	$$ = mknode(v,"Program_element");}
						| Declaration Program_element 						{vector<node*> v ; v.push_back($1) ; v.push_back($2);	$$ = mknode(v,"Program_element");}
						| {$$ = mkleaf("~");}
						;

Declaration 			: 	Type Declarator_list ';' 						{vector<node*> v ; v.push_back($1) ; v.push_back($2);	v.push_back(mkleaf(";"));$$ = mknode(v,"Declaration");}
						;
Declarator_list 		:   Declarator_list ',' Declarator 					{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf(",")); v.push_back($3);$$ = mknode(v,"Declarator_list");}
						|	Declarator_list ',' Declarator '=' Initializer  {vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf(",")); v.push_back($3);v.push_back(mkleaf("=")); v.push_back($5) ; $$ = mknode(v,"Declarator_list");}
						|	Declarator  									{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Declarator_list");}
						|	Declarator '=' Initializer 						{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("=")); v.push_back($3);$$ = mknode(v,"Declarator_list");}
						;
Initializer 			: 	Expression 										{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Initializer");}
						|	'{' Initializer_list '}'						{vector<node*> v ; v.push_back(mkleaf("{")) ; v.push_back($2); v.push_back(mkleaf("}")) ; $$ = mknode(v,"Initializer");}
						|	'{' Initializer_list ',' '}' 					{vector<node*> v ; v.push_back(mkleaf("{")) ; v.push_back($2); v.push_back(mkleaf(",")) ; v.push_back(mkleaf("}")) ; $$ = mknode(v,"Initializer");}
						;
Initializer_list 		:   Initializer_list ',' Initializer 				{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf(",")); v.push_back($3);$$ = mknode(v,"Initializer_list");}
						|	Initializer 									{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Initializer_list");}
						;
Declarator  			:   Pointer Simple_declarator 						{vector<node*> v ; v.push_back($1) ; v.push_back($2);	$$ = mknode(v,"Declarator");}
						|	Simple_declarator 								{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Declarator");}
						;
Pointer 				:	'*' 											{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Pointer");}
						|	'*' Pointer  									{vector<node*> v ; v.push_back(mkleaf("*")) ; v.push_back($2); v.push_back(mkleaf("}")) ; $$ = mknode(v,"Pointer");}
						;
Simple_declarator 		:   IDENTIFIERS 									{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Simple_declarator");}
						|	'(' Declarator ')' 								{vector<node*> v ; v.push_back(mkleaf("(")) ; v.push_back($2); v.push_back(mkleaf(")")) ; $$ = mknode(v,"Simple_declarator");}
						|	Simple_declarator '[' ']' 						{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("[")) ; v.push_back(mkleaf("]")) ; $$ = mknode(v,"Simple_declarator");}
						|	Simple_declarator '[' Expression ']'            {vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("[")) ; v.push_back($3); v.push_back(mkleaf("]")) ; $$ = mknode(v,"Simple_declarator");}
						;
Expression_list 		:   Expression 										{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Expression_list");}
						|   Expression_list ',' Expression 					{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf(",")); v.push_back($3);$$ = mknode(v,"Expression_list");}
						;
Expression 				:	Pl1 											{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Expression");}
						|	Unary_expression '=' Expression 				{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("=")); v.push_back($3);$$ = mknode(v,"Expression");}
						;
Pl1						: 	Pl2 											{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl1");}
						|	Pl1 OR_OP Pl2  									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("||")) ;  v.push_back($3);$$ = mknode(v,"Pl1");}
						;
Pl2						: 	Pl3 											{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl2");}
						|	Pl2 AND_OP Pl3 									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("&&")) ;  v.push_back($3);$$ = mknode(v,"Pl2");}
						;
Pl3						: 	Pl4											 	{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl3");}	
						|	Pl3 '|' Pl4 									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("|")) ;  v.push_back($3);$$ = mknode(v,"Pl3");}
						;
Pl4						: 	Pl5												{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl4");}
						|	Pl4 '^' Pl5 									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("^")) ;  v.push_back($3);$$ = mknode(v,"Pl4");}
						;
Pl5						: 	Pl6 											{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl5");}
						|	Pl5 '&' Pl6 									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("&")) ;  v.push_back($3);$$ = mknode(v,"Pl5");}
						;
Pl6						: 	Pl7 											{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl6");}
						|	Pl6 EQUAL_TO_OP Pl7 							{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("==")) ;  v.push_back($3);$$ = mknode(v,"Pl6");}
						|	Pl6 NOT_EQUAL_TO_OP Pl7 						{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("!=")) ;  v.push_back($3);$$ = mknode(v,"Pl6");}
						;
Pl7						: 	Pl8 											{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl7");}
						|	Pl7 '<' Pl8 									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("<")) ;  v.push_back($3);$$ = mknode(v,"Pl7");}
						|	Pl7 LESS_THAN_EQUAL_TO_OP Pl8 					{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("<=")) ;  v.push_back($3);$$ = mknode(v,"Pl7");}
						|	Pl7 '>' Pl8 									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf(">")) ;  v.push_back($3);$$ = mknode(v,"Pl7");}
						|	Pl7 GREATER_THAN_EQUAL_TO_OP Pl8 				{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf(">=")) ;  v.push_back($3);$$ = mknode(v,"Pl7");}
						;
Pl8						: 	Pl9 %prec TEMPPREC 								{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl8");}
						|	Pl8 LEFT_SHIFT_OP Pl9 %prec TEMPPREC 			{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("<<")) ;  v.push_back($3);$$ = mknode(v,"Pl8");}
						|	Pl8 RIGHT_SHIFT_OP Pl9 %prec TEMPPREC 			{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf(">>")) ;  v.push_back($3);$$ = mknode(v,"Pl8");}
						;
Pl9						: 	Pl10 %prec TEMPPREC 							{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl9");}
						|	Pl9 '+' Pl10  						 			{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("+")) ;  v.push_back($3);$$ = mknode(v,"Pl9");}
						|	Pl9 '-' Pl10  									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("-")) ;  v.push_back($3);$$ = mknode(v,"Pl9");}
						;
Pl10					: 	Unary_expression	  							{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl10");}
						|	Pl10 '*' Unary_expression  						{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("*")) ;  v.push_back($3);$$ = mknode(v,"Pl10");}
						|	Pl10 '/' Unary_expression	 					{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("/")) ;  v.push_back($3);$$ = mknode(v,"Pl10");}
						|	Pl10 '%' Unary_expression 						{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("%")) ;  v.push_back($3);$$ = mknode(v,"Pl10");}
						;	
Unary_expression		: '(' Type ')' Pl11 								{vector<node*> v ; v.push_back(mkleaf("(")) ; v.push_back($2); v.push_back(mkleaf(")")) ;  v.push_back($4);$$ = mknode(v,"Unary_expression");}
						|	Pl11 										 	{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Unary_expression");}
						;
Pl11					: 	Pl12 %prec TEMPPREC 							{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl11");}
						|	INCR_OP Pl11  									{vector<node*> v ; v.push_back(mkleaf("++")) ;  v.push_back($2);  $$ = mknode(v,"Pl11");}
						|	DECR_OP Pl11                                	{vector<node*> v ; v.push_back(mkleaf("--")) ;  v.push_back($2);  $$ = mknode(v,"Pl11");}
						|	SIZEOF'(' Pl11 ')' 								{vector<node*> v ; v.push_back(mkleaf("sizeof")) ; v.push_back(mkleaf("(")) ;v.push_back($3); v.push_back(mkleaf(")")) ; $$ = mknode(v,"Pl11"); }
						|	SIZEOF'(' Type ')' 								{vector<node*> v ; v.push_back(mkleaf("sizeof")) ; v.push_back(mkleaf("(")) ;v.push_back($3); v.push_back(mkleaf(")")) ; $$ = mknode(v,"Pl11"); }
						|	Unary_op Pl11 									{vector<node*> v ; v.push_back($1) ; v.push_back($2);	$$ = mknode(v,"Pl11");}
						;
Pl12					:   Basic_expression  								{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Pl12");}
						|	Pl12 '[' Expression ']' 						{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("[")) ; v.push_back($3); v.push_back(mkleaf("]")) ; $$ = mknode(v,"Pl12");}			
						|	Pl12 '(' ')'									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("[")) ; v.push_back(mkleaf("]")) ; $$ = mknode(v,"Pl12");}
						|	Pl12 '(' Expression_list')' 					{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("(")) ; v.push_back($3); v.push_back(mkleaf(")")) ; $$ = mknode(v,"Pl12");}
						|	Pl12 '.' IDENTIFIERS							{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf(".")) ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Pl12");}
						|	Pl12 INCR_OP 									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("++")) ; $$ = mknode(v,"Pl12");}
						|	Pl12 DECR_OP 									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("--")) ; $$ = mknode(v,"Pl12");}
						|	Pl12 PTR_OP IDENTIFIERS							{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf("*")) ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Pl12");}
						;
Basic_expression  		: IDENTIFIERS										{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Basic_expression"); }
						| INTEGER_CONSTANT 									{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Basic_expression");}
						| FLOAT_CONSTANT									{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Basic_expression");}	
						| CHARACTER_CONSTANT								{vector<node*> v ; v.push_back(wrap(yylval.char_val)); $$ = mknode(v,"Basic_expression");}	
						| STRING_CONSTANT									{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Basic_expression");}
						|	'(' Expression_list ')'							{vector<node*> v ; v.push_back(mkleaf("(")) ; v.push_back($2); v.push_back(mkleaf(")")) ; $$ = mknode(v,"Basic_expression");}
						;
Unary_op 				: '~' 												{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Unary_op");}
						| '!'												{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Unary_op");}
						| '*'												{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Unary_op");}
						| '@'												{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Unary_op");}
						| '-' 												{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Unary_op");}
						;	
Type 					: CHAR 												{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Type");}
						| INT 												{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Type");}
						| BOOL												{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Type");}
						| LONG 												{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Type");}
						| FLOAT 											{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Type");}
						| DOUBLE										    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Type");}
						| VOID 												{vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Type");}
						| SHORT											    {vector<node*> v ; string var(yylval.id_val) ; v.push_back(mkleaf(var)); $$ = mknode(v,"Type");}
						| Struct 											{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"Type");}
						;
Function 				:	Type Declarator '(' Parameter_list ')' '{' Stmt '}' {vector<node*> v ; v.push_back($1) ; v.push_back($2);v.push_back(mkleaf("(")); v.push_back($4); v.push_back(mkleaf(")")); v.push_back(mkleaf("{")); v.push_back($7);v.push_back(mkleaf("}"));	$$ = mknode(v,"Function");}
						|	Type Declarator '(' ')'  '{' Stmt '}' 				{vector<node*> v ; v.push_back($1) ; v.push_back($2);v.push_back(mkleaf("("));v.push_back(mkleaf(")")); v.push_back(mkleaf("{"));v.push_back($6);v.push_back(mkleaf("}"));	$$ = mknode(v,"Function");}
						;
Parameter_list 			:  Parameter_list  ',' Type Declarator 					{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf(",")); v.push_back($3); v.push_back($4);	$$ = mknode(v,"Parameter_list");}
						|	Type Declarator 									{vector<node*> v ; v.push_back($1) ; v.push_back($2);	$$ = mknode(v,"Parameter_list");}
						;
Struct 					:  STRUCT IDENTIFIERS '{' Struct_declaration_list'}'	{vector<node*> v ; v.push_back(mkleaf("struct")); v.push_back(mkleaf("IDENTIFIERS"));v.push_back(mkleaf("{")) ;v.push_back($4) ;v.push_back(mkleaf("}")) ; $$ = mknode(v,"Struct");}
						;
Struct_declaration_list :  Struct_declaration_list Type SS ';' 					{vector<node*> v ; v.push_back($1) ; v.push_back($2);	v.push_back($3); v.push_back(mkleaf(";")); $$ = mknode(v,"Struct_declaration_list");}
						|	Type SS ';' 										{vector<node*> v ; v.push_back($1) ; v.push_back($2);	v.push_back(mkleaf(";")); $$ = mknode(v,"Struct_declaration_list");}
						;
SS 						:  SS ',' Declarator 									{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf(",")) ;  v.push_back($3);$$ = mknode(v,"SS");}
						|	Declarator 											{vector<node*> v ; v.push_back($1) ; $$ = mknode(v,"SS");}
						;
Stmt 					: 	if_Stmt Stmt 										{vector<node*> v ; v.push_back($1) ; v.push_back($2);	$$ = mknode(v,"Stmt");}
						|	while_Stmt Stmt 									{vector<node*> v ; v.push_back($1) ; v.push_back($2);	$$ = mknode(v,"Stmt");}
						|	for_Stmt Stmt 										{vector<node*> v ; v.push_back($1) ; v.push_back($2);	$$ = mknode(v,"Stmt");}
						|	Expression_list ';' Stmt 							{vector<node*> v ; v.push_back($1) ; v.push_back(mkleaf(";")) ; v.push_back($3);	$$ = mknode(v,"Stmt");}
						|	'{' Stmt '}' Stmt 									{vector<node*> v ; v.push_back(mkleaf("{")) ; v.push_back($2); v.push_back(mkleaf("}")) ;  v.push_back($4);$$ = mknode(v,"Stmt");}						
						|	';' Stmt 											{vector<node*> v ; v.push_back(mkleaf(";")) ; v.push_back($2); $$ = mknode(v,"Stmt");}						
						|	CONTINUE ';' Stmt                                   {vector<node*> v ; v.push_back(mkleaf("CONTINUE")); v.push_back(mkleaf(";")) ; v.push_back($3); $$ = mknode(v,"Stmt");}						
						|	BREAK';' Stmt 										{vector<node*> v ; v.push_back(mkleaf("BREAK")); v.push_back(mkleaf(";")) ; v.push_back($3); $$ = mknode(v,"Stmt");}						
						|	RETURN ';' Stmt 									{vector<node*> v ; v.push_back(mkleaf("RETURN")); v.push_back(mkleaf(";")) ; v.push_back($3); $$ = mknode(v,"Stmt");}						
						|	RETURN Expression_list ';' Stmt 					{vector<node*> v ; v.push_back(mkleaf("RETURN")); v.push_back($2); v.push_back(mkleaf(";")) ; v.push_back($4); $$ = mknode(v,"Stmt");}						
						|   Declaration  Stmt 									{vector<node*> v ; v.push_back($1) ; v.push_back($2);	$$ = mknode(v,"Stmt");}
						|														{$$ = mkleaf("~");}
						| 	error ';'{cout<<"1>>>>"; vector<node*> v ; v.push_back(mkleaf("ERROR\n")); $$ = mknode(v,"Stmt");  yyclearin;}
						;

if_Stmt					: IF '(' Expression_list ')'  '{'Stmt'}'  ELSE '{'Stmt'}' {vector<node*> v ; v.push_back(mkleaf("if")); v.push_back(mkleaf("(")) ; v.push_back($3); v.push_back(mkleaf(")")) ;v.push_back(mkleaf("{")) ;v.push_back($6) ;v.push_back(mkleaf("}")) ;v.push_back(mkleaf("else")) ;v.push_back(mkleaf("{")) ;v.push_back($10); v.push_back(mkleaf("}")) ; $$ = mknode(v,"if_Stmt");}
						| IF '(' Expression_list ')' '{' Stmt '}'                 {vector<node*> v ; v.push_back(mkleaf("if")); v.push_back(mkleaf("(")) ; v.push_back($3); v.push_back(mkleaf(")")) ;v.push_back(mkleaf("{")) ;v.push_back($6) ;v.push_back(mkleaf("}")) ; $$ = mknode(v,"if_Stmt");}
						;
						
for_Stmt 				: FOR'(' Expression_list ';' Expression_list ';' Expression_list ')' '{' Stmt '}' {vector<node*> v ; v.push_back(mkleaf("for")); v.push_back(mkleaf("(")) ; v.push_back($3); v.push_back(mkleaf(";")) ; v.push_back($5); v.push_back(mkleaf(";")) ; v.push_back($7); v.push_back(mkleaf(")")) ;v.push_back(mkleaf("{")) ;v.push_back($10) ;v.push_back(mkleaf("}")) ; $$ = mknode(v,"for_Stmt");}
						
						;
while_Stmt 				: WHILE '(' Expression_list ')' '{' Stmt '}' 	 		  {vector<node*> v ; v.push_back(mkleaf("while")); v.push_back(mkleaf("(")) ; v.push_back($3); v.push_back(mkleaf(")")) ;v.push_back(mkleaf("{")) ;v.push_back($6) ;v.push_back(mkleaf("}")) ; $$ = mknode(v,"while_Stmt");}
						| WHILE '('error')' {cout<<"3>>>>"; vector<node*> v ; v.push_back(mkleaf("ERROR\n")); $$ = mknode(v,"while_Stmt"); ; yyclearin;}
						;

%%
/*--------------------------------------------------------------------------------*/


void yyerror(string s)
{
  //extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cout << "ERROR: " << s << " at symbol \"" << yytext;
  cout << "\" on line " << line_num << endl;
}


void yyerror(char *s)
{
   yyerror(string(s));
}


node* mknode(vector<node*> v, string attr)	/*may be used and */
{
	node *n = new node(v,attr );
	return n; 
}

node* mkleaf(string s)
{
	node  *n = new node(s);
	return n;
}
node * wrap(char c)
{
	char ch[2];
	ch[0] = c;
	ch[1] = '\0';
	vector<node*> v; // local variable !!! 
	string str(ch);
	node *n = new node(v,str);
	return n;
}

void preorder(node* t)
{
	cout<<(t->node_name)<<", ";
	for(vector<node*>::iterator it = t->child.begin(); it!=t->child.end() ; it++)
	{
		preorder(*it);
	}
}
