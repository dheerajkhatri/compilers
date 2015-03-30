%{
  #include <bits/stdc++.h>
	#include <cstdio>
	#include<cstdlib>
	#include <cstring>
	#define pb push_back 
  #define vns vector<node*>
	using namespace std;

	extern int yylex(void);
	int line_num = 1;
	extern char* yytext ;
	void yyerror(char *);
  void yyerror(string);

  typedef struct node{
    string node_id;
    vns children;
    node(string s){
      node_id = s;
    }
    node(string s,vns v){
      children = v;
      node_id = s;
    }
  }node;
  node* root=NULL;
  node* mknode(vns ,string);
  node* leaf(string);
  void print_graph(node*);


%}
%error-verbose
%union{
  int		int_val;
  double 	decimal_val;
  char      char_val;
  char*     id_val;
  struct node*     ptr;
}

%left 	PREC2
%left   TEMPPREC
%right 	'='
%left 	OR_OP
%left	AND_OP
%left	'|'
%left	'^'
%left	'&' 
%left 	DOUBLE_EQ_OP NOT_EQ_OP
%left 	'<' '>' LESS_EQ_OP GRE_EQ_OP 
%left	'+' '-'
%left	'*' '/' '%'
%left   INCR_OP DECR_OP '('



%token IDENTIFIER BOOL INT FLOAT DOUBLE CHAR DO WHILE IF ELIF FALSE TRUE IN OUT MAIN VOID FOR INTCONST CHAR_CONSTANT RETURN STRUCT SWITCH WHITESPACE CASE ELSE DEFAULT CONSTANT STRING INP_OP OUT_OP OR_OP  INC_OP DEC_OP AND_OP LESS_EQ_OP GRE_EQ_OP DOUBLE_EQ_OP NOT_EQ_OP DOUBLE_CONSTANT



%type <ptr> START INNER OUTER FUNCTION VARDEF MVARDEF STRUCT1 FORN WHILEN MATH RMATH RADDSUB RMULTIDIV FCALL IFN SWITCHN UNARY_EXP VARNAME SWITCHINNER ARGT COND CONST FL1 FL2 FL3 MARGT INPUT OUTPUT BRACKET ELSEC WODEFAULT TYPE FARG LOOP CONDITIONAL MARG MVAR OPERATOR INC_OP DEC_OP MIN MOUT DOWHILEN

%start START



%%


START : OUTER                                                       {vns v ; v.pb($1) ; $$ = mknode(v,"START");root = $$;print_graph(root); cout<<"------------*------------\n";}
;

OUTER  :                                                              {vns v; v.pb(leaf("  ")); $$ = mknode(v,"OUTER");}
 |  VARDEF OUTER                                                      {vns v; v.pb($1); v.pb($2); $$ = mknode(v,"OUTER");}
 |  STRUCT1 OUTER                                                     {vns v; v.pb($1); v.pb($2); $$ = mknode(v,"OUTER");}
 | FUNCTION OUTER                                                     {vns v; v.pb($1); v.pb($2); $$ = mknode(v,"OUTER");}
 | error                                                               {vns v; v.pb(leaf("~")); $$ = mknode(v,"OUTER");} 
;

TYPE  :  
   INT                                                              {vns v; v.pb(leaf("INT")); $$ = mknode(v,"TYPE");} 
   |BOOL                                                            {vns v; v.pb(leaf("BOOL")); $$ = mknode(v,"TYPE");}
   |VOID                                                            {vns v; v.pb(leaf("VOID")); $$ = mknode(v,"TYPE");}
   |FLOAT                                                           {vns v; v.pb(leaf("FLOAT")); $$ = mknode(v,"TYPE");}
   |DOUBLE                                                          {vns v; v.pb(leaf("DOUBLE")); $$ = mknode(v,"TYPE");}
   |STRUCT IDENTIFIER                                               {vns v; v.pb(leaf("STRUCT IDENTIFIER")); $$ = mknode(v,"TYPE");}
   |CHAR                                                            {vns v; v.pb(leaf("CHAR")); $$ = mknode(v,"TYPE");}
;

STRUCT1  :  
STRUCT IDENTIFIER'{'MVARDEF VARDEF';''}'';'                          {vns v; v.pb(leaf("STRUCT")); v.pb(leaf("IDENTIFIER")); v.pb(leaf("{")); v.pb($4); v.pb($5); v.pb(leaf(";"));v.pb(leaf("}"));v.pb(leaf(";"));$$ = mknode(v,"STRUCT1");}
;

MVARDEF  :                                                          
MVARDEF VARDEF';'                                                   {vns v; v.pb($1);v.pb($2);v.pb(leaf(";")); $$ = mknode(v,"MVARDEF");}
|                                                                   {vns v; v.pb(leaf("  ")); $$ = mknode(v,"MVARDEF");}
;


FUNCTION  :  
TYPE VARNAME'('FARG')''{'INNER'}'                                   {vns v; v.pb($1); v.pb($2); v.pb(leaf("(")); v.pb($4); v.pb(leaf(")")); v.pb(leaf("{"));v.pb($7);v.pb(leaf("}"));$$ = mknode(v,"FUNCTIONS");}
;


INNER  :  
LOOP INNER                                                          {vns v; v.pb($1);v.pb($2);$$ = mknode(v,"INNER");}
|CONDITIONAL INNER                                                  {vns v; v.pb($1);v.pb($2);$$ = mknode(v,"INNER");}
|VARDEF INNER                                                       {vns v; v.pb($1);v.pb($2);$$ = mknode(v,"INNER");}
|RETURN UNARY_EXP';'                                                {vns v; v.pb(leaf("RETURN"));v.pb($2);v.pb(leaf(";"));$$ = mknode(v,"INNER");}
|INPUT INNER                                                        {vns v; v.pb($1);v.pb($2);$$ = mknode(v,"INNER");}
|OUTPUT INNER                                                       {vns v; v.pb($1);v.pb($2);$$ = mknode(v,"INNER");}
|MATH INNER                                                         {vns v; v.pb($1);v.pb($2);$$ = mknode(v,"INNER");}
|                                                                   {vns v; v.pb(leaf("  "));$$ = mknode(v,"INNER");}
|error INNER                                                        {vns v; v.pb(leaf("ERROR"));v.pb($2);$$ = mknode(v,"INNER");}
;

VARNAME  : 
'*'VARNAME                                                          {vns v; v.pb(leaf("*"));v.pb($2);$$ = mknode(v,"VARNAME");}
|'&'VARNAME                                                         {vns v; v.pb(leaf("&"));v.pb($2);$$ = mknode(v,"VARNAME");}
|IDENTIFIER BRACKET	                                                {vns v; v.pb(leaf("IDENTIFIER"));v.pb($2);$$ = mknode(v,"VARNAME");}
;

BRACKET  :  
BRACKET'['RMATH']'                                                  {vns v; v.pb($1); v.pb(leaf("["));v.pb($3); v.pb(leaf("]")); $$ = mknode(v,"VARNAME");}
|                                                                   {vns v; v.pb(leaf("  "));$$ = mknode(v , "BRACKET");}
;

MARG  :  
MARG TYPE VARNAME','                                                {vns v; v.pb($1);v.pb($2);v.pb($3);v.pb(leaf(","));$$ = mknode(v,"MARG");}
|                                                                   {vns v; v.pb(leaf("  "));$$ = mknode(v , "MARG");} 
;

FARG  :  
MARG TYPE VARNAME                                                   {vns v; v.pb($1);v.pb($2);v.pb($3);$$ = mknode(v,"FARG");}
|                                                                   {vns v; v.pb(leaf("  "));$$ = mknode(v , "FARG");}
;

VARDEF  : 
TYPE VARNAME';'                                                     {vns v; v.pb($1); v.pb($2); v.pb(leaf(";"));$$ = mknode(v , "VARDEF");}
|TYPE VARNAME '=' RMATH';'                                          {vns v; v.pb($1); v.pb($2);v.pb(leaf("="));v.pb($4); v.pb(leaf(";"));$$ = mknode(v , "VARDEF");}
|TYPE MVAR VARNAME';'                                               {vns v; v.pb($1); v.pb($2); v.pb($3); v.pb(leaf(";"));$$ = mknode(v , "VARDEF");}
|TYPE MVAR VARNAME '=' RMATH';'                                     {vns v; v.pb($1); v.pb($2); v.pb($3);v.pb(leaf("="));v.pb($5); v.pb(leaf(";"));$$ = mknode(v , "VARDEF");}
;

MVAR  :  
MVAR VARNAME','                                                     {vns v; v.pb($1); v.pb($2); v.pb(leaf(","));$$ = mknode(v , "MVAR");}
|MVAR VARNAME '=' RMATH','                                          {vns v; v.pb($1); v.pb($2);v.pb(leaf("="));v.pb($4); v.pb(leaf(","));$$ = mknode(v , "MVAR");}
|VARNAME','                                                         {vns v; v.pb($1); v.pb(leaf(",")); $$ = mknode(v , "MVAR");}
|VARNAME '=' RMATH','                                               {vns v;v.pb($1);v.pb(leaf("="));v.pb($3); v.pb(leaf(","));$$ = mknode(v , "MVAR");}
;


MATH  :  
VARNAME '=' RMATH';'                                                {vns v; v.pb($1); v.pb(leaf("=")); v.pb($3); v.pb(leaf(";"));$$ = mknode(v , "MATH");}
|';'                                                                {vns v; v.pb(leaf(";"));$$ = mknode(v , "MATH");}
|VARNAME OPERATOR '=' RMATH';'                                      {vns v; v.pb($1); v.pb($2); v.pb(leaf("=")); v.pb($4); v.pb(leaf(";"));$$ = mknode(v , "MATH");}
|UNARY_EXP';'                                                       {vns v; v.pb($1);v.pb(leaf(";"));$$ = mknode(v , "MATH");}
;

RMATH : 
'('RMATH')'                                                         {vns v; v.pb(leaf("(")); v.pb($2);v.pb(leaf(")"));$$ = mknode(v , "RMATH");}                                                   
|'!'RMATH                                                           {vns v; v.pb(leaf("!"));v.pb($2);$$ = mknode(v , "RMATH");}
|RADDSUB                                                            {vns v; v.pb($1);$$ = mknode(v , "RMATH");}
;

RADDSUB  : 
RMULTIDIV                                                           {vns v; v.pb($1);$$ = mknode(v , "RADDSUB");}
|RADDSUB '-' RADDSUB                                                {vns v; v.pb($1);v.pb(leaf("-"));v.pb($3);$$ = mknode(v , "RADDSUB");}
|RADDSUB '+' RADDSUB                                                {vns v; v.pb($1);v.pb(leaf("-"));v.pb($3);$$ = mknode(v , "RADDSUB");}
;

RMULTIDIV  :  
RMULTIDIV '*' RMULTIDIV                                             {vns v; v.pb($1);v.pb(leaf("*"));v.pb($3);$$ = mknode(v , "RMULTIDIV");}
|RMULTIDIV '/' RMULTIDIV                                            {vns v; v.pb($1);v.pb(leaf("/"));v.pb($3);$$ = mknode(v , "RMULTIDIV");}
|RMULTIDIV '%' RMULTIDIV                                            {vns v; v.pb($1);v.pb(leaf("%"));v.pb($3);$$ = mknode(v , "RMULTIDIV");}
|UNARY_EXP                                                          {vns v; v.pb($1);$$ = mknode(v , "RMULTIDIV");}
;


UNARY_EXP : 
VARNAME INC_OP                                                   {vns v; v.pb($1); v.pb($2); $$ = mknode(v,"UNARY_EXP");}
|INC_OP VARNAME                                                   {vns v; v.pb($1); v.pb($2); $$ = mknode(v,"UNARY_EXP");}                                                   
|VARNAME DEC_OP                                                   {vns v; v.pb($1); v.pb($2); $$ = mknode(v,"UNARY_EXP");} 
|DEC_OP VARNAME                                                   {vns v; v.pb($1); v.pb($2); $$ = mknode(v,"UNARY_EXP");} 
|CONST                                                   {vns v; v.pb($1);$$ = mknode(v,"UNARY_EXP");}
|FCALL                                                   {vns v; v.pb($1); $$ = mknode(v,"UNARY_EXP");}
|VARNAME                                                    {vns v; v.pb($1); $$ = mknode(v,"UNARY_EXP");}
;



//for array indexing 
/*INTMATH  : 
'('INTMATH')'|
'!'INTMATH|
ADDSUB|
;

ADDSUB  :  MULTIDIV|
ADDSUB '-' ADDSUB|
ADDSUB '+' ADDSUB
;

MULTIDIV  :  UNARY_EXP|
MULTIDIV '*' MULTIDIV|
MULTIDIV '/' MULTIDIV|
MULTIDIV '%' MULTIDIV
;
*/



CONDITIONAL  :  
IFN                                                   {vns v; v.pb($1);$$ = mknode(v,"CONDITIONAL");}
| SWITCHN                                             {vns v; v.pb($1);$$ = mknode(v,"CONDITIONAL");}
;

IFN  :  
IF'('COND')''{'INNER'}'                               {vns v; v.pb(leaf("IF"));v.pb(leaf("("));v.pb($3);v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));$$ = mknode(v,"IFN");}      
|IF'('error')''{'INNER'}'                             {vns v; v.pb(leaf("IF"));v.pb(leaf("("));v.pb(leaf("ERROR"));v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));$$ = mknode(v,"IFN");}  
|IF'('COND')''{'INNER'}' ELSEC                        {vns v; v.pb(leaf("IF"));v.pb(leaf("("));v.pb($3);v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));v.pb($8);$$ = mknode(v,"IFN");}  
|IF'('error')''{'INNER'}' ELSEC                       {vns v; v.pb(leaf("IF"));v.pb(leaf("("));v.pb(leaf("ERROR"));v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));v.pb($8);$$ = mknode(v,"IFN");}  
;



COND  :  
COND AND_OP COND                                     {vns v; v.pb($1);v.pb(leaf("AND_OP"));v.pb($3);$$ = mknode(v , "COND");}
|COND OR_OP COND                                      {vns v; v.pb($1);v.pb(leaf("OR_OP"));v.pb($3);$$ = mknode(v , "COND");}
|RMATH                                                {vns v; v.pb($1);$$ = mknode(v , "COND");}
|COND '>' COND                                     {vns v; v.pb($1);v.pb(leaf(">"));v.pb($3);$$ = mknode(v , "COND");}
|COND '<' COND                                     {vns v; v.pb($1);v.pb(leaf("<"));v.pb($3);$$ = mknode(v , "COND");}
|COND DOUBLE_EQ_OP COND                                     {vns v; v.pb($1);v.pb(leaf("DOUBLE_EQ_OP"));v.pb($3);$$ = mknode(v , "COND");}
|COND NOT_EQ_OP COND                                     {vns v; v.pb($1);v.pb(leaf("NOT_EQ_OP"));v.pb($3);$$ = mknode(v , "COND");}
|COND LESS_EQ_OP COND                                     {vns v; v.pb($1);v.pb(leaf("LESS_EQ_OP"));v.pb($3);$$ = mknode(v , "COND");}
|COND GRE_EQ_OP COND                                      {vns v; v.pb($1);v.pb(leaf("GRE_EQ_OP"));v.pb($3);$$ = mknode(v , "COND");}
;


ELSEC  :  
ELIF '('COND')' '{'INNER'}' ELSEC                         {vns v; v.pb(leaf("ELIF"));v.pb(leaf("("));v.pb($3);v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));v.pb($8);$$ = mknode(v,"ELSEC");} 
| ELSE '{'INNER'}'                         {vns v; v.pb(leaf("ELSE"));v.pb(leaf("{"));v.pb($3);v.pb(leaf("}"));$$ = mknode(v,"ELSEC");} 
| ELIF '('COND')' '{'INNER'}'                         {vns v; v.pb(leaf("ELIF"));v.pb(leaf("("));v.pb($3);v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));$$ = mknode(v,"ELSEC");} 
| ELIF '('error')' '{'INNER'}'                         {vns v; v.pb(leaf("ELIF"));v.pb(leaf("("));v.pb(leaf("ERROR"));v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));$$ = mknode(v,"ELSEC");} 
| ELIF '('error')' '{'INNER'}' ELSEC                        {vns v; v.pb(leaf("ELIF"));v.pb(leaf("("));v.pb(leaf("ERROR"));v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));v.pb($8);$$ = mknode(v,"ELSEC");} 
;

SWITCHN  : 
SWITCH'('COND')''{'SWITCHINNER'}'                         {vns v; v.pb(leaf("SWITCH"));v.pb(leaf("("));v.pb($3);v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));$$ = mknode(v,"SWITCHN");} 
|SWITCH'('error')''{'SWITCHINNER'}'                        {vns v; v.pb(leaf("SWITCH"));v.pb(leaf("("));v.pb(leaf("ERROR"));v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));$$ = mknode(v,"SWITCHN");} 
;

SWITCHINNER  :  
CASE CONST':''{'INNER'}' SWITCHINNER                     {vns v;v.pb(leaf("CASE"));v.pb($2);v.pb(leaf(":"));v.pb(leaf("{"));v.pb($5);v.pb(leaf("}"));v.pb($7); $$=mknode(v,"SWITCHINNER");}
|CASE CONST':' INNER SWITCHINNER                     {vns v;v.pb(leaf("CASE"));v.pb($2);v.pb(leaf(":"));v.pb($4);v.pb($5); $$=mknode(v,"SWITCHINNER");}
|DEFAULT':''{'INNER'}' WODEFAULT                     {vns v;v.pb(leaf("DEFAULT"));v.pb(leaf(":"));v.pb(leaf("{"));v.pb($4);v.pb(leaf("}"));v.pb($6); $$=mknode(v,"SWITCHINNER");}
|DEFAULT':' INNER WODEFAULT                     {vns v;v.pb(leaf("DEFAULT"));v.pb(leaf(":"));v.pb($3);v.pb($4); $$=mknode(v,"SWITCHINNER");}
|                                                    {vns v;v.pb(leaf("  "));$$=mknode(v,"SWITCHINNER");}
;

WODEFAULT  :  
CASE CONST':''{'INNER'}' WODEFAULT              {vns v; v.pb(leaf("CASE")); v.pb(leaf("CONST")); v.pb(leaf(":")); v.pb(leaf("{")); v.pb($5); v.pb(leaf("}")); v.pb($7); $$ = mknode(v,"WODEFAULT");}                 
|CASE CONST':' INNER WODEFAULT                  {vns v; v.pb(leaf("CASE")); v.pb(leaf("CONST")); v.pb(leaf(":")); v.pb($4); v.pb($5); $$ = mknode(v,"WODEFAULT");}          
|                                               {vns v;v.pb(leaf("  "));$$=mknode(v,"WODEFAULT");}
; 

ARGT  :  
MARGT RMATH                                     {vns v;v.pb($1);v.pb($2); $$ = mknode(v,"ARGT");}
;

MARGT  :  
MARGT RMATH','                                  {vns v;v.pb($1);v.pb($2);v.pb(leaf(",")); $$ = mknode(v,"MARGT");}
|                                               {vns v;v.pb(leaf("  "));$$=mknode(v,"MARGT");}
;

FCALL  :  
VARNAME'('ARGT')'                               {vns v;v.pb($1);v.pb(leaf("("));v.pb($3);v.pb(leaf(")")); $$ = mknode(v,"FCALL");}
;


LOOP  : 
FORN                                          {vns v;v.pb($1); $$ = mknode(v,"LOOP");}
|WHILEN                                    {vns v;v.pb($1); $$ = mknode(v,"LOOP");}
|DOWHILEN                                    {vns v;v.pb($1); $$ = mknode(v,"LOOP");}
;

FL1 : 
MATH                                          {vns v;v.pb($1);$$=mknode(v,"FL1");}
 ;


FL2 :  
COND                                          {vns v;v.pb($1);$$=mknode(v,"FL2");}
|                                             {vns v;v.pb(leaf("  "));$$=mknode(v,"FL2");}
;


FL3  : 
VARNAME '=' RMATH                            {vns v;v.pb($1);v.pb(leaf("="));v.pb($3);$$=mknode(v,"FL3");}
|TYPE VARNAME '=' RMATH                       {vns v;v.pb($1);v.pb($2);v.pb(leaf("="));v.pb($4);$$=mknode(v,"FL3");}
|VARNAME OPERATOR'=' RMATH                    {vns v;v.pb($1);v.pb($2);v.pb(leaf("="));v.pb($4);$$=mknode(v,"FL3");}
|UNARY_EXP                                    {vns v;v.pb($1);$$=mknode(v,"FL3");}
|                                            {vns v;v.pb(leaf("  "));$$=mknode(v,"FL3");}
;

OPERATOR  :  
'+'                                        {vns v; v.pb(leaf("+")); $$ = mknode(v,"OPERATOR");}
|'-'                                        {vns v; v.pb(leaf("-")); $$ = mknode(v,"OPERATOR");}
|'*'                                        {vns v; v.pb(leaf("*")); $$ = mknode(v,"OPERATOR");}
|'/'                                        {vns v; v.pb(leaf("/")); $$ = mknode(v,"OPERATOR");}
|'&'                                        {vns v; v.pb(leaf("&")); $$ = mknode(v,"OPERATOR");}
|'^'                                        {vns v; v.pb(leaf("^")); $$ = mknode(v,"OPERATOR");}
|'|'                                        {vns v; v.pb(leaf("|")); $$ = mknode(v,"OPERATOR");}
|'%'                                        {vns v; v.pb(leaf("%")); $$ = mknode(v,"OPERATOR");}
;

FORN  :  
FOR'('FL1 FL2';' FL3')''{'INNER'}'          {vns v;v.pb(leaf("FOR"));v.pb(leaf("("));v.pb($3);v.pb($4);v.pb(leaf(";"));v.pb($6);v.pb(leaf(")"));v.pb(leaf("{"));v.pb($9);v.pb(leaf("}"));$$=mknode(v,"FORN");}
|FOR'('error')''{'INNER'}'                  {vns v;v.pb(leaf("FOR"));v.pb(leaf("("));v.pb(leaf("ERROR"));v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));$$=mknode(v,"FORN");}
;

WHILEN : 
WHILE'('COND')''{'INNER'}'                  {vns v;v.pb(leaf("WHILE"));v.pb(leaf("("));v.pb($3);v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));$$=mknode(v,"WHILEN");}
|WHILE'('error')''{'INNER'}'                {vns v;v.pb(leaf("WHILE"));v.pb(leaf("("));v.pb(leaf("ERROR"));v.pb(leaf(")"));v.pb(leaf("{"));v.pb($6);v.pb(leaf("}"));$$=mknode(v,"WHILEN");}
;

DOWHILEN  :  
DO'{'INNER'}'WHILE'('COND')'';'             {vns v;v.pb(leaf("DO"));v.pb(leaf("{"));v.pb($3);v.pb(leaf("}"));v.pb(leaf("WHILE"));v.pb(leaf("("));v.pb($7);v.pb(leaf(")"));v.pb(leaf(";"));$$=mknode(v,"DOWHILEN");}
|DO'{'INNER'}'WHILE'('error')'';'             {vns v;v.pb(leaf("DO"));v.pb(leaf("{"));v.pb($3);v.pb(leaf("}"));v.pb(leaf("WHILE"));v.pb(leaf("("));v.pb(leaf("ERROR"));v.pb(leaf(")"));v.pb(leaf(";"));$$=mknode(v,"DOWHILEN");}
;

MIN  :  
MIN INP_OP VARNAME                                    {vns v;v.pb($1);v.pb(leaf("IN_OP")); v.pb($3); $$ = mknode(v,"MIN");}
|                                                     {vns v;v.pb(leaf("  "));$$=mknode(v,"MIN");}
;


MOUT  : 
MOUT OUT_OP VARNAME                                   {vns v;v.pb($1);v.pb(leaf("OUT_OP")); v.pb($3); $$ = mknode(v,"MOUT");}
|MOUT OUT_OP CONST                                    {vns v;v.pb($1);v.pb(leaf("OUT_OP")); v.pb($3); $$ = mknode(v,"MOUT");}
|                                                           {vns v;v.pb(leaf("  "));$$=mknode(v,"MOUT");}
;

INPUT  :
IN MIN INP_OP VARNAME';'                            {vns v;v.pb(leaf("IN"));v.pb($2);v.pb(leaf("INP_OP")); v.pb($4); $$ = mknode(v,"INPUT");}
;

OUTPUT  :  
OUT MOUT OUT_OP VARNAME';'                            {vns v;v.pb(leaf("OUT"));v.pb($2);v.pb(leaf("OUT_OP")); v.pb($4); $$ = mknode(v,"OUTPUT");}
|OUT MOUT OUT_OP CONST ';'                            {vns v;v.pb(leaf("OUT"));v.pb($2);v.pb(leaf("OUT_OP")); v.pb($4); $$ = mknode(v,"OUTPUT");}
;

CONST :  
TRUE                                                        {vns v; v.pb(leaf("TRUE")); $$ = mknode(v,"CONST");}
|FALSE                                                      {vns v; v.pb(leaf("FALSE")); $$ = mknode(v,"CONST");}
|INTCONST                                                   {vns v; v.pb(leaf("INTCONST")); $$ = mknode(v,"CONST");}  
|DOUBLE_CONSTANT                                            {vns v; v.pb(leaf("DOUBLE_CONSTANT")); $$ = mknode(v,"CONST");}
|CHAR_CONSTANT                                              {vns v; v.pb(leaf("CHAR_CONSTANT")); $$ = mknode(v,"CONST");}
;

%%
/*--------------------------------------------------------------------------------*/


void yyerror(string s){
  //extern int line_num;  // defined and maintained in lex.c
  extern char *yytext;  // defined and maintained in lex.c
  
  cout << "ERROR: " << s << " at symbol \"" << yytext;
  cout << "\" on line " << line_num << endl;
}


void yyerror(char *s){
    extern char *yytext;
    printf("ERROR: %s at symbol %s on line %d",s,yytext,line_num);
  //  yyerror(string(s));
}

void print_graph(node* t){
if(t->node_id == "  " || t->children.size()==0) return;
  cout<<(t->node_id)<<"->";
  for(vector<node*>::iterator it = t->children.begin(); it!=t->children.end() ; it++)
  {
    cout << (*it)->node_id << " ";
  }
  cout << "\n";
  for(vector<node*>::iterator it = t->children.begin(); it!=t->children.end() ; it++)
  {
    print_graph(*it);
  }
}

node* mknode(vns v,string s){
  node* temp = new node(s,v);
  return temp;
}
node* leaf(string s){
  vns v;
  v.clear();
  node* temp = new node(s,v);
  return temp;
}