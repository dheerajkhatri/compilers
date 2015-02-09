#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
//#define DEBUG	

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
			//cin>>ok;
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


//minimization using myhill nerode theorem 

DFA dfa_minimize(DFA dfa){
	int states,i,j,iatrans,ibtrans,jatrans,jbtrans,lols;  // iatrans = $(i,a) ; ibtrans = $(i,b)
	states = dfa.get_vertex_count();
	//vector<int>finals = dfa.final_state;
	//vector<trans>curtrans = dfa.transitions;
	bool change = false; // to check whether is there any change in table if not then stop there
	bool isfalse;  // to check whether table entry already checked or not
	DFA m_dfa;  // final minimized dfa
	bool table[states][states];  
	
	for(i=0;i<states;i++){
		for(j=0;j<states;j++){
			table[i][j] = true;
		}
	}

	//first loop for ticking

	for(i=0;i<states;i++){
		for(j=0;j<states;j++){
			if(i<=j){
				continue;   // only lower half table needed to be filled
			} else{  		// chceck whether one of i and j found in final state
				if( ( (find(dfa.final_state.begin(),dfa.final_state.end(),i)!=dfa.final_state.end()) && (find(dfa.final_state.begin(),dfa.final_state.end(),j)==dfa.final_state.end())) || 
					( (find(dfa.final_state.begin(),dfa.final_state.end(),j)!=dfa.final_state.end()) && (find(dfa.final_state.begin(),dfa.final_state.end(),i)==dfa.final_state.end()))
				){
					table[i][j] = false;
				}
			}
		}
	}

	#ifdef DEBUG
		cout<<"INITIAL TABLE IS -----------------------"<<endl;
		for(i=0;i<states;i++){
			for(j=0;j<states;j++){
				if(i<=j)cout<<"- ";
				else cout<<table[i][j]<<" ";
			}
			cout<<endl;		
		}
		cin>>lols;
	#endif

	// loop until there is no change in table
	do{
		change = false;
		for(i=0;i<states;i++){
			for(j=0;j<states;j++){
				if(i<=j || table[i][j]==false){					
					continue;
				}else{										
					//iterate over all transitions and find i and j's transitions
					//if pair goes to such state on a or b which is having false in table 
					for(vector<trans>::iterator its = (dfa.transitions).begin();its!=dfa.transitions.end();its++){
						if(its->vertex_from == i){
							if(its->trans_symbol == 'a')
								iatrans = its->vertex_to;
							else if(its->trans_symbol == 'b')
								ibtrans = its->vertex_to;
						}else if(its->vertex_from == j){
							if(its->trans_symbol == 'a')
								jatrans = its->vertex_to;
							else if(its->trans_symbol == 'b')
								jbtrans = its->vertex_to;
						}
					}   // for pair i j found the a and b transitions
					#ifdef DEBUG
						cout<<"FOR PAIR  "<<i<<"  "<<j<<"----------"<<endl;
						cout<<"for state "<<i<<endl;
						cout<<i<<" ->a "<<iatrans<<"   "<<" ->b "<<ibtrans<<endl;

						cout<<"for state "<<j<<endl;
						cout<<j<<" ->a "<<jatrans<<"   "<<" ->b "<<jbtrans<<endl;

						cout<<"-----------------------"<<endl;
					#endif

					// FOR SOME STATE I IF THERE IS NO TRANSITION THEN WE ARE SETTING THAT TRANSITION IN -1 STATE
					// 	check whether any trans lead to FALSE entry in table
					if((iatrans!=-1 && jatrans!=-1) && iatrans!=jatrans){
						isfalse = iatrans > jatrans ? table[iatrans][jatrans]:table[jatrans][iatrans];
						if(!isfalse) {
							change = true;
							table[i][j] = false;
							#ifdef DEBUG
								cout<<"change for pair "<<i<<" & "<<j<<endl;
							#endif
						}
						// if any one (i or j)is -1 and other is final state then set table enrty FALSE
					}else if((iatrans==-1 && jatrans!=-1 && (find(dfa.final_state.begin(),dfa.final_state.end(),jatrans)!=dfa.final_state.end()))||
						(jatrans==-1 && iatrans!=-1 && (find(dfa.final_state.begin(),dfa.final_state.end(),iatrans)!=dfa.final_state.end()))){
							change = true;
						table[i][j] = false;						
						//cout<<"in else if a change for pair "<<i<<" & "<<j<<endl;
						//cin>>lols;
					}

					if((ibtrans!=-1 && jbtrans!=-1) && ibtrans!=jbtrans){
						isfalse = ibtrans > jbtrans ? table[ibtrans][jbtrans]:table[jbtrans][ibtrans];
						if(!isfalse) {
							change = true;
							table[i][j] = false;
						//	cout<<"change for pair "<<i<<" & "<<j<<endl;
						}
					
					}else if((ibtrans==-1 && jbtrans!=-1 && (find(dfa.final_state.begin(),dfa.final_state.end(),jbtrans)!=dfa.final_state.end()))||
						(jbtrans==-1 && ibtrans!=-1 && (find(dfa.final_state.begin(),dfa.final_state.end(),ibtrans)!=dfa.final_state.end()))){
							change = true;
						table[i][j] = false;
						//cout<<"in if else b change for pair "<<i<<" & "<<j<<endl;
						//cin>>lols;
					}

					


				} // end of i>j else			
			} // end of j loop
		}  // end of i loop

	}while(change);
	cout<<"FINAL MINIMIZED TABLE IS "<<endl;
	for(i=0;i<states;i++){
		for(j=0;j<states;j++){
			if(i<=j)cout<<"- ";
			else cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}

	//make sets and maps them to new states
	bool checked[states],mila_kya=false;
	map<set<int>,int>final_mapping;  // merged set will be mapped to new given states
	int curCount=0; // counter for new merged set to map a new state
	set<int>aisehi,temps;	
	map<set<int>,int>::iterator to_erase;
	set<int>::iterator sit;
	for(i=0;i<states;i++) checked[i] = false;  // to check all states are checked or not

	for(i=0;i<states;i++){

		//cout<<"i is "<<i<<"-------------------"<<endl;
		if(checked[i]==false){
		//	cout<<"in new set"<<endl;
			aisehi.clear();
			aisehi.insert(i);			
		}

		for(j=i+1;j<states;j++){
		//	cout<<"pairs are "<<i<<" "<<j<<endl;
			if(table[j][i]==1 && checked[i]==false){
		//		cout<<"for pair "<<i<<" "<<j<<" inserted in set"<<endl;
				aisehi.insert(j);
				checked[j] = true;
			}
			else if(table[j][i]==1 && checked[i]==true){
		//		cout<<"pair is "<<i<<" "<<j<<" in checked[i]==true"<<endl;
				// find in which set j lies and update the set  here i and j are minimizing and i is already merged with some state
				for(map<set<int>,int>::iterator itt = final_mapping.begin();itt!=final_mapping.end();itt++){
					if( (itt->first).find(i) == (itt->first).end() ){
						continue;
					} else {
						temps.clear();
						sit = (itt->first).find(i);
						temps = itt->first;
						temps.insert(j);  // add new state j in old set that contain i 
						checked[j] = true;
		//				cout<<j<<" IS MARKED TRUE ALSO"<<endl;
						final_mapping[temps] = itt->second;
						to_erase = final_mapping.find(itt->first);
						final_mapping.erase(to_erase);
						break;
					}
				}
			}
		}
		if(checked[i]==false)final_mapping[aisehi] = curCount++;
		checked[i] = true;
	}
	#ifdef DEBUG
		cout<<"total states in minimized dfa are "	<<curCount<<endl;
		cout<<"printing final set  mapping"	<<endl;
		for(map<set<int>,int >::iterator crawl = final_mapping.begin();crawl!=final_mapping.end();++crawl){
			cout<<"set is ";
			for(set<int>::iterator scrawl = crawl->first.begin();scrawl!=crawl->first.end();scrawl++){
				cout<<*scrawl<<" ";
			}
			cout<<" and maps to "<<crawl->second<<endl;	
		}
	#endif

	m_dfa.set_vertex(curCount);
	set<int>::iterator ist;
	int atra,btra;

	for(map<set<int>,int>::iterator ift = final_mapping.begin(); ift!=final_mapping.end(); ift++){	

		// set final states	
		for(ist = ift->first.begin(); ist!=ift->first.end();ist++){
			if(find(dfa.final_state.begin(),dfa.final_state.end(),*ist)!=dfa.final_state.end()){
				m_dfa.set_final_state(ift->second);
				break;  //necessary otherwise multiple copy in final state vector
			}			
		}

		// now set transitions
		
		ist = (ift->first).begin();
		
		//iterate over dfa.transitions and find the a and b transition state
		for(vector<trans>::iterator itr = dfa.transitions.begin(); itr!=dfa.transitions.end(); itr++){
			if(itr->vertex_from == *ist && itr->trans_symbol == 'a'){
				atra = itr->vertex_to;
			}
			if(itr->vertex_from == *ist && itr->trans_symbol == 'b'){
				btra = itr->vertex_to;
			}
		}

		if(atra==-1){
			m_dfa.set_transition(ift->second,-1,'a');
		}
		if(btra==-1){
			m_dfa.set_transition(ift->second,-1,'b');
		}
		// now check in which set atra and btra are and accordingly set the transition of final dfa
		
		for(map<set<int>,int>::iterator ifft = final_mapping.begin();ifft!=final_mapping.end();ifft++){			
			for(set<int>::iterator isst = ifft->first.begin();isst!=ifft->first.end();isst++){
				if(atra!=-1 && *isst == atra ){
					m_dfa.set_transition(ift->second,ifft->second,'a');					
				}
				if(btra!=-1 && *isst == btra){
					m_dfa.set_transition(ift->second,ifft->second,'b');		
				}
			}
		}


	}

	m_dfa.display();
	return dfa;
}




bool simulate(DFA dfa, string s){
	int i,curstate=0;
	for(i=0;i<s.length();i++){
		//cout<<"current s[i] is "<<s[i]<<endl;
		for(vector<trans>::iterator its = dfa.transitions.begin();its!=dfa.transitions.end();its++){
			if(its->vertex_from == curstate && its->trans_symbol == s[i] && its->vertex_to == -1)return false;
			else if(its->vertex_from == curstate && its->trans_symbol == s[i]){
				curstate = its->vertex_to;
				//cout<<"now curstate is and curent alphabet is "<<curstate<<" "<<s[i]<<endl;
				break;
			}
		}
	}

	// now check cur state if final or not

	for(vector<int>::iterator it = dfa.final_state.begin(); it!=dfa.final_state.end();it++){
		if(*it == curstate)return true;
	}
	return false;
}


int main() {
	/*cout<<"\n\nThe Thompson's Construction Algorithm takes a regular expression as an input "
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


	
	set<char> symbols;

	cout<<"\n*****\t*****\t*****\n";
	cout<<"\nFORMAT : \n"
		<<"> Explicitly mention concatenation with a '.' operator \n"
		<<"> Enclose every concatenation and or section by parantheses \n"
		<<"> Enclose the entire regular expression with parantheses \n\n";

	cout<<"For example : \nFor the regular expression (a.(b|c))  -- \n";
	NFA example_nfa = re_to_nfa("(a.(b|c))");
	example_nfa.display();*/
	string re;
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

	cout<<"------The required NFA has the transitions : -----"<<endl;
	
	NFA required_nfa;
	required_nfa = re_to_nfa(re);
	required_nfa.display();	
	
	/*#ifdef DEBUG
		set<int> temp = required_nfa.epsilon_closure(0);
		cout<<"epsilon_closure of state 0 is "<<endl;
		for(set<int> ::iterator it = temp.begin();it!=temp.end();it++){
			cout<<*it<<" ";			
		}cout<<endl;
		cout<<"input to ok ?"<<endl;
		cin>>ok;
	#endif*/
	string to_simulate;
	cout<<"--------------------------------------"<<endl;
	cout<<"now nfa->dfa will be shown"<<endl;
	DFA required_dfa = nfa_to_dfa(required_nfa);
	required_dfa.display();
	cout<<"---------------------------------------"<<endl;
	cout<<"here goes minimization table for required dfa"<<endl;
	DFA tempdfa = dfa_minimize(required_dfa);
	cout<<"enter the strings to simulate and press q to quit"<<endl;
	
	cin>>to_simulate;
	while(to_simulate[0]!='q'){
		simulate(tempdfa,to_simulate) == true ? cout<<"accepted"<<endl : cout<<"rejected"<<endl;
		cin>>to_simulate;
	}

	cout<<"-----------------------------------BYE BYE-------------------------------"<<endl;
	return 0;
}

