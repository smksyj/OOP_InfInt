#include "Operator.h"


Operator::Operator(void)
{
}


Operator::~Operator(void)
{
}

InfInt Operator::Operation(vector<string> tokens) {
	vector<string> post;
	vector<string> temp;

	//string Plus("+"), Minus("-");
	//string Mult("*"), Div("/");
	//string Open("("), Clo(")");

	for(int i=0; i<tokens.size(); i++){
		if(tokens[i].at(0)== '*'|| tokens[i].at(0)== '/'){
			temp.push_back(tokens[i]);
		}
		else if(tokens[i].at(0)== '+'|| tokens[i].at(0)== '-'){
			if(temp.size()!= 0 && (temp.begin()->at(0)== '*'|| temp.begin()->at(0)== '/')){
				for(int k=temp.size(); k>0; k--){
					post.push_back(temp.back());
					temp.pop_back();
				}
			}
			temp.push_back(tokens[i]);
		}
		else if(tokens[i].at(0)== '('){
			temp.push_back(tokens[i]);
		}
		else if(tokens[i].at(0)== ')'){
			while(temp.back().at(0)!= '('){
				post.push_back(temp.back());
				temp.pop_back();
			}
			temp.pop_back();
		}
		else{
			post.push_back(tokens[i]);
		}
	}
	for(int k=temp.size(); k>0; k--){
		if(temp.back().at(0)!= '('|| temp.back().at(0)!= ')')
			post.push_back(temp.back());
		temp.pop_back();
	}

	vector<InfInt> InfVec;

	for(int i= 0; i< post.size(); i++){
		if(post[i].at(0)== '+'|| post[i].at(0)== '-'|| post[i].at(0)== '*'|| post[i].at(0)== '/'){
			InfInt A(InfVec.back());
			InfVec.pop_back();
			InfInt B(InfVec.back());
			InfVec.pop_back();
			InfInt C;
			if(post[i].at(0)== '+'){
				C= B+A;
			}
			else if(post[i].at(0)== '-'){
				C= B-A;
			}
			else if(post[i].at(0)== '*'){
				C= B*A;
			}
			else if(post[i].at(0)== '/'){
				C= B/A;
			}
			InfVec.push_back(C);
		}

		else{
			InfInt Temp(post[i].c_str());
			InfVec.push_back(Temp);
		}
	}

	//InfInt ret(temp[0].c_str());
	//return ret;
	return InfVec[0];
}