Everything Working fine!
-Here everything are made for only aphabet set = {a,b}
-No nead to explicitly mention concatenation by '.' or any other symbol


There are two classes
	1.NFA 
	2.DFA

Main functions are 
	1. DFA nfa_to_dfa(NFA nfa);	
	2.NFA OPERATIONS:	
		NFA concatenation(NFA a, NFA b);
		NFA kleene_star(NFA a);
		NFA or_function(NFA n1, NFA n2);
	3.string infix_to_postfix(string re);
	4.NFA re_to_nfa(string re);
	5.DFA dfa_minimize(DFA dfa);
	6.bool simulate(DFA dfa, string s);

Working :- 
	First infix -> Postfix 
	RE->NFA   (Thompson construction)
	NFA->DFA (Subset construction)
	DFA->minimized_dfa (Myhill Nerode Theorem)
	Simulation on minimized dfa		

INPUT-
first input is regular expression
then give all the string with enter that you want to simulate on minimized dfa made on regular expression

OUTPUT-
for all input strings that you want to simulate on given regular expression "accepted" or "rejected" will be printed!

More scope of improvement-
1.Can extend alphabet set and more general DFA could be possible!
2.Your input format should be valid ie: there should not be epsilon in between string that you want to simulate
3.For minimization Myhill Nerode Theorem is used, Hofcroft algorithm can also be implemented of less comlexity(not very sure!)


