#include <bits/stdc++.h>

using namespace std;
#define DEBUG
string reg;
int reg_l;
int* brackets;


/*structure for state of a NFA */
typedef struct nfanode{
	int index;
	vector<pair<char,struct nfanode> > edges;
} nfa_node;


/*structure for NFA */
typedef struct nfa_struct{
	nfa_node start,final;
}nfa;
nfa total;
vector<nfa_node> total2(100000);


/*structure for state of a DFA */
typedef struct dfanode{
	char ch;
	vector<pair<char,int> > edges;
} dfa_node;


/*structure for DFA */
typedef struct dfa_struct{
	dfa_node start,final;
}dfa;
dfa final_dfa;


/*converts infix regular expression to postfix regular expression */
void infix_to_postfix(){
	stack<char> operators;
	stack<string> variables;
	for(int i=0;i<reg_l;i++){
		string tem="";
		tem+=reg[i];
		if(reg[i]=='('){
			operators.push(reg[i]);
			variables.push(tem);
		}
		else if(reg[i]==')'){
			string temp = variables.top();
			variables.pop();
			operators.pop();
			if(variables.top()!="(") temp+='&';
			while(variables.top()!="("){
				string temp2 = variables.top();
				variables.pop();
				if(variables.top()!="(") temp=temp2+'&'+temp;
				else temp=temp2+temp;
			}
			variables.pop();
			variables.push(temp);
		}
		else if(reg[i]=='*'){
			string temp = variables.top();
			variables.pop();
			temp+='*';
			variables.push(temp);
		}
		else if(reg[i]=='|') operators.push(reg[i]);
		else{
			if(!operators.empty() && operators.top()!='(' && !variables.empty()){
				string temp = variables.top();
				variables.pop();
				temp+=reg[i];
				temp+=operators.top();
				operators.pop();
				variables.push(temp);
			}
			else variables.push(tem);
		}
	}
	reg=variables.top();
	variables.pop();
	if(!variables.empty()) reg+='&';
	while(!variables.empty()){
		string temp2=variables.top();
		variables.pop();
		if(!variables.empty()) reg = temp2+'&'+reg;
		else reg = temp2 + reg;
	}
	reg_l = reg.length();
}


/*constructs NFA of the postfix regular expression using stack */
void construct_nfa_from_postfix(){
	stack<nfa> nfa_stack;
	for(int i=0;i<reg_l;i++){
		if(reg[i]=='a' || reg[i]=='b'){
			nfa temp;
			temp.start.index = 0;
			temp.final.index = 0;
			temp.start.edges.push_back(make_pair(reg[i],temp.final));
			nfa_stack.push(temp);
		}
		else if(reg[i]=='&'){
			nfa temp,top1,top2;
			temp.start.index = 0;
			temp.final.index = 0;
			top1 = nfa_stack.top();
			nfa_stack.pop();
			top2 = nfa_stack.top();
			nfa_stack.pop();
			temp  = top2;
			temp.final = top1.start;
			nfa_stack.push(temp);
		}
		else if(reg[i]=='|'){
			nfa temp,top1,top2;
			temp.start.index = 0;
			temp.final.index = 0;
			top1 = nfa_stack.top();
			nfa_stack.pop();
			top2 = nfa_stack.top();
			nfa_stack.pop();
			temp.start.edges.push_back(make_pair('e',top1.start));
			temp.start.edges.push_back(make_pair('e',top2.start));
			top1.final.edges.push_back(make_pair('e',temp.final));
			top2.final.edges.push_back(make_pair('e',temp.final));
			nfa_stack.push(temp);
		}
		else if(reg[i]=='*'){
			nfa temp,top1;
			temp.start.index = 0;
			temp.final.index = 0;
			top1 = nfa_stack.top();
			nfa_stack.pop();
			temp.start.edges.push_back(make_pair('e',top1.start));
			temp.start.edges.push_back(make_pair('e',temp.final));
			top1.final.edges.push_back(make_pair('e',temp.final));
			top1.final.edges.push_back(make_pair('e',top1.start));
			nfa_stack.push(temp);
		}
	}
	total = nfa_stack.top();
	queue<nfa_node> q;
	q.push(total.start);
	int curr=1;
	while(!q.empty()){
		nfa_node current_node = q.front();
		q.pop();
		current_node.index = curr++;
		total2[curr]=current_node;
		for(vector<pair<char,nfa_node> >::iterator it = current_node.edges.begin();it!=current_node.edges.end();it++){
			if(it->second.index !=0 ) q.push(it->second);
		}
	}
	nfa_stack.pop();
}


/*finds the epsilon closure of a node*/
vector<nfa_node> epsilon_closure(nfa_node a){
	vector<nfa_node> eps_clo;
	queue<nfa_node> q;
	map<int,int> visited;
	q.push(a);
	while(!q.empty()){
		nfa_node curr = q.front();
		q.pop();
		eps_clo.push_back(curr);
		for(vector<pair<char,nfa_node> >::iterator it = curr.edges.begin();it!=curr.edges.end();it++){
			if(it->first == 'e' && visited[it->second.index]==0){
				q.push(it->second);
				visited[it->second.index]=1;
			}
		}
	}
	return eps_clo;
}


/* mapping of which nfa states is a dfa state mapped to */
map<vector<int>,int > mapping; 		
map<int,vector<nfa_node> > mapping2;				



/*non-minimal DFA */
vector<dfa_node> nmdfa(1000000);
/*number of nodes in the non-minimal DFA */
int num_nodes;


/*Constructs DFA from NFA*/
void construct_dfa_from_nfa(){
	set<int> to_be_processed;								//set of uinvestigated dfa states
	vector<nfa_node> zeps = epsilon_closure(total.start);
	vector<int> izeps;
	for(vector<nfa_node>::iterator it = zeps.begin();it!=zeps.end();it++) izeps.push_back(it->index);
	int curr = 1;
	to_be_processed.insert(curr);
	mapping2[curr]=zeps; 	
	mapping[izeps]=curr++;
	while(!to_be_processed.empty()){
		int k = *to_be_processed.begin();
		vector<nfa_node> temp = mapping2[k];
		vector<int> a_trans,b_trans;					//vectors to store the transitions on 'a' and 'b'
		for(vector<nfa_node>::iterator it = temp.begin();it!=temp.end();it++){
			nfa_node current_node = *it;
			for(vector<pair<char,nfa_node> >::iterator jt = current_node.edges.begin();jt!=current_node.edges.end();jt++){
				vector<nfa_node> zzz;
				if(jt->first!='e') zzz = epsilon_closure(jt->second);
				vector<int> ttt;
				for(vector<nfa_node>::iterator qt = zzz.begin();qt!=zzz.end();qt++) ttt.push_back(qt->index);
				if(jt->first == 'a') a_trans.insert(a_trans.end(),ttt.begin(),ttt.end());
				if(jt->first == 'b') b_trans.insert(b_trans.end(),ttt.begin(),ttt.end());
			}
		}
		sort(a_trans.begin(),a_trans.end());
		sort(b_trans.begin(),b_trans.end());
		a_trans.erase( unique( a_trans.begin(), a_trans.end() ), a_trans.end() );
		b_trans.erase( unique( b_trans.begin(), b_trans.end() ), b_trans.end() );
		if(mapping[a_trans]==0){
			mapping[a_trans]=curr;
			vector<nfa_node> a_temp;
			for(vector<int>::iterator it = a_trans.begin();it!=a_trans.end();it++) a_temp.push_back(total2[*it]);
			mapping2[curr]=a_temp;
		}
		nmdfa[k].edges.push_back(make_pair('a',curr++));
		if(mapping[b_trans]==0){
			mapping[b_trans]=curr;
			vector<nfa_node> b_temp;
			for(vector<int>::iterator it = b_trans.begin();it!=b_trans.end();it++) b_temp.push_back(total2[*it]);
			mapping2[curr]=b_temp;
		}
		nmdfa[k].edges.push_back(make_pair('b',curr++));
	}
	num_nodes = curr;
}


/*main driver function */
int main(int argc, char* argv[]){
	string temp;
	reg="";
	cin >> temp;
	for(unsigned int i=0;i<temp.length();i++){
		if(temp[i]=='.'){
			reg+='&';
		}
		else if(temp[i]=='+') reg+='|';
		else reg+=temp[i];
	}

	#ifdef DEBUG
		cout<<"now reg is "<<reg<<endl;
	#endif

	reg_l = reg.length();
	brackets = new int[reg_l];
	stack<int> s;
	for(int i=0;i<reg_l;i++){
		brackets[i]=0;
		if(reg[i]=='(') s.push(i);
		if(reg[i]==')'){
			brackets[s.top()]=i;
			brackets[i]=s.top();
			s.pop();
		}
	}

	#ifdef DEBUG
		for(int k=0;k<reg_l;k++){
			cout<<k<<"->"<<brackets[k]<<endl;
		}
		cin>>temp;
	#endif

	infix_to_postfix();

	#ifdef DEBUG
		cout<<"after infix to postfix "<<reg<<endl;
	#endif

	construct_nfa_from_postfix();
	//cout << reg << "\n";
	return 0;
}
