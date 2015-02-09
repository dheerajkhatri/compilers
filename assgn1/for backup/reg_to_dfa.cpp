#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <queue>
using namespace std;
#define DEBUG	

struct trans {
	int vertex_from;
	int vertex_to;
	char trans_symbol;
};



class NFA {
public:
	vector<int> vertex;
	vector<trans> transitions;
	int final_state;

	NFA() {

	}

	int get_vertex_count() {
		return vertex.size();
	}

	void set_vertex(int no_vertex) {
		for(int i = 0; i < no_vertex; i++) {
			vertex.push_back(i);
		}
	}

	void set_transition(int vertex_from, int vertex_to, char trans_symbol) {
		trans new_trans;
		new_trans.vertex_from = vertex_from;
		new_trans.vertex_to = vertex_to;
		new_trans.trans_symbol = trans_symbol;
		transitions.push_back(new_trans);
	}

	void set_final_state(int fs) {
		final_state = fs;
	}

	int get_final_state() {
		return final_state;
	}

	void display() {
		trans new_trans;
		cout<<"\n";
		for(int i = 0; i < transitions.size(); i++) {
			new_trans = transitions.at(i);
			cout<<"q"<<new_trans.vertex_from<<" --> q"<<new_trans.vertex_to<<" : Symbol - "<<new_trans.trans_symbol<<endl;
		}
		cout<<"\nThe final state is q"<<get_final_state()<<endl;
	}

	set<int> epsilon_closure(int index){
		set<int> myclous;		
		myclous.insert(index);

		for(vector<trans> ::iterator it = transitions.begin(); it!=transitions.end(); ++it){
			if(it->vertex_from == index && it->trans_symbol == '^'){
				myclous.insert(it->vertex_to);
				set<int>temps = this->epsilon_closure(it->vertex_to);
				for(set<int>::iterator itt = temps.begin();itt!=temps.end();++itt){
					myclous.insert(*itt);
				}
			}
		}
		return myclous;
	}
};


class DFA {
public:
	int vertex;   // number of vertex
	vector<trans> transitions;
	vector<int> final_state;
	//map<int,set<int> >index_to_set;	

	void set_vertex(int count){
		vertex = count;
	}

	int get_vertex_count(){
		return vertex;
	}

	void set_final_state(int state){
		final_state.push_back(state);
	}

	bool is_final(int state){
		for(vector<int>::iterator it = final_state.begin();it!=final_state.end();++it){
			if(state == *it){
				return true;
			}
		}
		return false;
	}

	void set_transition(int vertex_from,int vertex_to,char trans_symbol){
		trans new_trans;
		new_trans.vertex_from = vertex_from;
		new_trans.vertex_to = vertex_to;
		new_trans.trans_symbol = trans_symbol;
		transitions.push_back(new_trans);		
	}

	void display() {
		trans new_trans;
		cout<<"\n";
		for(int i = 0; i < transitions.size(); i++) {
			new_trans = transitions.at(i);
			cout<<"q"<<new_trans.vertex_from<<" --> q"<<new_trans.vertex_to<<" : Symbol - "<<new_trans.trans_symbol<<endl;
		}
		// also print here final states
		cout<<"final states of dfa are"<<endl;
		for(vector<int>::iterator ift = final_state.begin();ift!=final_state.end();ift++){
			cout<<*ift<<" ";
		}cout<<endl;
	}

};


DFA nfa_to_dfa(NFA nfa){
	DFA dfa;
	int i,stateCounter,curState;
	stateCounter = curState = 0;
	//set<int> uninvestigated;   // to check which state has not seen yet,if found then erase from set
	//vector<set<int> >todoSet;
	map<set<int>,int >found_mapping;  // map to record sets found till now
	queue<set<int> > todo;            //queue to maintain all the set yet to be proceed
	set<int> a_set;
	set<int> b_set;
	set<int> a_epsilon;
	set<int> b_epsilon;
	set<int> lol;
	int ok;
	bool isdone[20000];
	for(i=0;i<20000;i++)
		isdone[i] = false;
	/*for(i=0;i<nfa.get_vertex_count();i++){
		uninvestigated.insert(i);
	}*/
	set<int>temps = nfa.epsilon_closure(0);
	//todoSet.push_back(temps);
	found_mapping.insert(make_pair(temps,curState));
	todo.push(temps);

	while(!todo.empty()){
		
		temps.clear();
		a_set.clear();
		b_set.clear();
		a_epsilon.clear();
		b_epsilon.clear();
		lol.clear();

		temps = todo.front();
		curState = found_mapping[temps];
		todo.pop();
		
		if(isdone[curState]==true)continue;

		isdone[curState] = true;

		#ifdef DEBUG
			cout<<"cur SET number "<<found_mapping[temps]<<" is "<<endl;
			for(set<int>::iterator lol1 = temps.begin();lol1!=temps.end();++lol1){
				cout<<*lol1<<" ";
			}
			cout<<endl;
		#endif

		// finding a_set and b_set
 		for(vector<trans>::iterator its = (nfa.transitions).begin();its!=(nfa.transitions).end();++its){
			if(temps.find(its->vertex_from)!=temps.end()){
				if(its->trans_symbol == 'a'){
					a_set.insert(its->vertex_to);
				}else if(its->trans_symbol == 'b'){
					b_set.insert(its->vertex_to);
				}
			}
		} 


		//set dfa transitions
		if(a_set.empty()){
			dfa.set_transition(curState,-1,'a');
		} else{

			// find clousure of all the states in set
			for(set<int>::iterator aits = a_set.begin();aits!=a_set.end();aits++){
				lol.clear();
				lol = nfa.epsilon_closure(*aits);
				for(set<int>::iterator ilol = lol.begin(); ilol!=lol.end();++ilol){
					a_epsilon.insert(*ilol);
				}
			}

			//HERE ALSO CHECK WHETHER THE STATE IS ALREADY PRESENT OR NOT THEN INSERT IN VECTOR MAPPING
			if(found_mapping.find(a_epsilon)==found_mapping.end()){
				found_mapping.insert(make_pair(a_epsilon,++stateCounter));
			}
			todo.push(a_epsilon);
			dfa.set_transition(curState,found_mapping[a_epsilon],'a');
		}
		//INSERT EPSILON CLOSURE FOR A_sET AND B_sET 
		if(b_set.empty()){
			dfa.set_transition(curState,-1,'b');			
		} else{

			for(set<int>::iterator bits = b_set.begin();bits!=b_set.end();bits++){
				lol.clear();
				lol = nfa.epsilon_closure(*bits);
				for(set<int>::iterator ilols = lol.begin(); ilols!=lol.end();++ilols){
					b_epsilon.insert(*ilols);
				}
			}

			//HERE ALSO CHECK WHETHER THE STATE IS ALREADY PRESENT OR NOT THEN INSERT IN VECTOR MAPPING
			if(found_mapping.find(b_epsilon)==found_mapping.end()){
				found_mapping.insert(make_pair(b_epsilon,++stateCounter));
			}

			todo.push(b_epsilon);
			dfa.set_transition(curState,found_mapping[b_epsilon],'b');
		}


		#ifdef DEBUG
			cout<<"cur SET AMOVE number "<<found_mapping[a_epsilon]<<" is "<<endl;
			for(set<int>::iterator lol2 = a_epsilon.begin();lol2!=a_epsilon.end();++lol2){
				cout<<*lol2<<" ";
			}
			cout<<endl;		

			cout<<"cur SET BMOVE number "<<found_mapping[b_epsilon]<<" is "<<endl;
			for(set<int>::iterator lol3 = b_epsilon.begin();lol3!=b_epsilon.end();++lol3){
				cout<<*lol3<<" ";
			}
			cout<<endl;	
			cout<<"input to ok ?"<<endl;
			cin>>ok;
			cout<<"-------------------------------------"<<endl;
		#endif


		//check for final state  temps is current set, check whether final state of johnson algo is there ?
		if(temps.find(nfa.get_final_state())!=temps.end()){
			dfa.set_final_state(curState);
		}

	}

	


	dfa.set_vertex(found_mapping.size());
	return dfa;
}


NFA concat(NFA a, NFA b) {
	NFA result;
	result.set_vertex(a.get_vertex_count() + b.get_vertex_count());
	int i;
	trans new_trans;

	for(i = 0; i < a.transitions.size(); i++) {
		new_trans = a.transitions.at(i);
		result.set_transition(new_trans.vertex_from, new_trans.vertex_to, new_trans.trans_symbol);
	}

	result.set_transition(a.get_final_state(), a.get_vertex_count(), '^');

	for(i = 0; i < b.transitions.size(); i++) {
		new_trans = b.transitions.at(i);
		result.set_transition(new_trans.vertex_from + a.get_vertex_count(), new_trans.vertex_to + a.get_vertex_count(), new_trans.trans_symbol);
	}

	result.set_final_state(a.get_vertex_count() + b.get_vertex_count() - 1);

	return result;
}


NFA kleene(NFA a) {
	NFA result;
	int i;
	trans new_trans;
	
	result.set_vertex(a.get_vertex_count() + 2);

	result.set_transition(0, 1, '^');

	for(i = 0; i < a.transitions.size(); i++) {
		new_trans = a.transitions.at(i);
		result.set_transition(new_trans.vertex_from + 1, new_trans.vertex_to + 1, new_trans.trans_symbol);
	}

	result.set_transition(a.get_vertex_count(), a.get_vertex_count() + 1, '^');
	result.set_transition(a.get_vertex_count(), 1, '^');
	result.set_transition(0, a.get_vertex_count() + 1, '^');

	result.set_final_state(a.get_vertex_count() + 1);

	return result;
}


NFA or_selection(vector<NFA> selections, int no_of_selections) {
	NFA result;
	int vertex_count = 2;
	int i, j;
	NFA med;
	trans new_trans;

	for(i = 0; i < no_of_selections; i++) {
		vertex_count += selections.at(i).get_vertex_count();
	}

	result.set_vertex(vertex_count);
	
	int adder_track = 1;

	for(i = 0; i < no_of_selections; i++) {
		result.set_transition(0, adder_track, '^');
		med = selections.at(i);
		for(j = 0; j < med.transitions.size(); j++) {
			new_trans = med.transitions.at(j);
			result.set_transition(new_trans.vertex_from + adder_track, new_trans.vertex_to + adder_track, new_trans.trans_symbol);
		}
		adder_track += med.get_vertex_count();

		result.set_transition(adder_track - 1, vertex_count - 1, '^');
	}

	result.set_final_state(vertex_count - 1);

	return result;
}


NFA re_to_nfa(string re) {
	stack<char> operators;
	stack<NFA> operands;
	char op_sym;
	int op_count;
	char cur_sym;
	NFA *new_sym;
	
	for(string::iterator it = re.begin(); it != re.end(); ++it) {
		cur_sym = *it;
		if(cur_sym != '(' && cur_sym != ')' && cur_sym != '*' && cur_sym != '|' && cur_sym != '.') {
			new_sym = new NFA();
			new_sym->set_vertex(2);
			new_sym->set_transition(0, 1, cur_sym);
			new_sym->set_final_state(1);
			operands.push(*new_sym);
			delete new_sym;
		} else {
			if(cur_sym == '*') {
				NFA star_sym = operands.top();
				operands.pop();
				operands.push(kleene(star_sym));
			} else if(cur_sym == '.') {
				operators.push(cur_sym);
			} else if(cur_sym == '|') {
				operators.push(cur_sym);
			} else if(cur_sym == '(') {
				operators.push(cur_sym);
			} else {
				op_count = 0;
				char c;
				op_sym = operators.top();
				if(op_sym == '(') continue;
				do {
					operators.pop();
					op_count++;
				} while(operators.top() != '(');
				operators.pop();
				NFA op1;
				NFA op2;
				vector<NFA> selections;
				if(op_sym == '.') {
					for(int i = 0; i < op_count; i++) {
						op2 = operands.top();
						operands.pop();
						op1 = operands.top();
						operands.pop();
						operands.push(concat(op1, op2));
					}
				} else if(op_sym == '|'){
					selections.assign(op_count + 1, NFA());
					int tracker = op_count;
					for(int i = 0; i < op_count + 1; i++) {
						selections.at(tracker) = operands.top();
						tracker--;
						operands.pop();
					}
					operands.push(or_selection(selections, op_count+1));
				} else {
					
				}
			}
		}
	}

	return operands.top();
}


int main() {
	cout<<"\n\nThe Thompson's Construction Algorithm takes a regular expression as an input "
		<<"and returns its corresponding Non-Deterministic Finite Automaton \n\n";
	cout<<"\n\nThe basic building blocks for constructing the NFA are : \n";

	NFA a, b;
	int ok;
	cout<<"\nFor the regular expression segment : (a)";
	a.set_vertex(2);
	a.set_transition(0, 1, 'a');
	a.set_final_state(1);
	a.display();
//	getch();

	cout<<"\nFor the regular expression segment : (b)";
	b.set_vertex(2);
	b.set_transition(0, 1, 'b');
	b.set_final_state(1);
	b.display();
//	getch();

	cout<<"\nFor the regular expression segment [Concatenation] : (a.b)";
	NFA ab = concat(a, b);
	ab.display();
//	getch();

	cout<<"\nFor the regular expression segment [Kleene Closure] : (a*)";
	NFA a_star = kleene(a);
	a_star.display();
//	getch();

	cout<<"\nFor the regular expression segment [Or] : (a|b)";
	int no_of_selections;
	no_of_selections = 2;
	vector<NFA> selections(no_of_selections, NFA());
	selections.at(0) = a;
	selections.at(1) = b;
	NFA a_or_b = or_selection(selections, no_of_selections);
	a_or_b.display();	
//	getch();


	string re;
	set<char> symbols;

	cout<<"\n*****\t*****\t*****\n";
	cout<<"\nFORMAT : \n"
		<<"> Explicitly mention concatenation with a '.' operator \n"
		<<"> Enclose every concatenation and or section by parantheses \n"
		<<"> Enclose the entire regular expression with parantheses \n\n";

	cout<<"For example : \nFor the regular expression (a.(b|c))  -- \n";
	NFA example_nfa = re_to_nfa("(a.(b|c))");
	example_nfa.display();
	
	cout<<"\n\nEnter the regular expression in the above mentioned format - \n\n";
	cin>>re;

/*	char cur_sym;
	int counter = 0;
	for(string::iterator it = re.begin(); it != re.end(); ++it) {
		cur_sym = (*it);
		if(cur_sym != '(' && cur_sym != ')' && cur_sym != '*' && cur_sym != '|' && cur_sym != '.') {
			cout<<cur_sym<<" "<<counter++<<endl;
			symbols.insert(cur_sym);
		}
	}
*/

	cout<<"\n\nThe required NFA has the transitions : \n\n";
	
	NFA required_nfa;
	required_nfa = re_to_nfa(re);
	required_nfa.display();	
	
	#ifdef DEBUG
		set<int> temp = required_nfa.epsilon_closure(0);
		cout<<"epsilon_closure of state 0 is "<<endl;
		for(set<int> ::iterator it = temp.begin();it!=temp.end();it++){
			cout<<*it<<" ";			
		}cout<<endl;
		cout<<"input to ok ?"<<endl;
		cin>>ok;
	#endif

	cout<<"--------------------------------------"<<endl;
	cout<<"now nfa->dfa will be shown"<<endl;
	DFA required_dfa = nfa_to_dfa(required_nfa);
	required_dfa.display();

	return 0;
}