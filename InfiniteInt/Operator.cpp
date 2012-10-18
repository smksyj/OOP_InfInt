#include "Operator.h"
//#define DEBUG


Operator::Operator(void)
{
}


Operator::~Operator(void)
{
}

/*
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
*/

InfInt Operator::Operation(vector<string> tokens){
#ifdef DEBUG
	cout<<"Parser::Operation debug started..."<<endl;
#endif
#ifdef DEBUG
//	cout<<"Splitting..."<<endl;
#endif
//	vector<string> tokens= split(expression, ' ');
#ifdef DEBUG
	cout<<"Tokens are "<<endl;
	for(vector<string>::iterator i=tokens.begin();i!=tokens.end();++i)
		cout<<" => "<<*i<<endl;
#endif

	vector<string> post;
	vector<string> temp;

	const string Plus("+"), Minus("-"), Mult("*"), Div("/"),
		Pow("^"), Root("v"),
		Lparen("("), Rparen(")");

	for(int i=0; i<(int)tokens.size(); i++){
#ifdef DEBUG
		cout<<"tokens["<<i<<"] is debugging: "<<tokens[i]<<endl;
#endif
		if(tokens[i].compare(Pow)==0|| tokens[i].compare(Root)==0){
			temp.push_back(tokens[i]);
		}
		else if(tokens[i].compare(Mult)==0|| tokens[i].compare(Div)==0){
 			if(temp.size()!= 0 && (temp.begin()->compare(Pow)==0|| temp.begin()->compare(Root)==0|| temp.begin()->compare(Mult)==0|| temp.begin()->compare(Div)==0)){
				for(int k=temp.size(); k>0; k--){
					if(temp.back().compare(Lparen)==0)
						continue;
					post.push_back(temp.back());
					temp.pop_back();
				}
			}
			temp.push_back(tokens[i]);
		}
		else if(tokens[i].compare(Plus)==0|| tokens[i].compare(Minus)==0){
			if(temp.size()!= 0 && (temp.begin()->compare(Pow)==0|| temp.begin()->compare(Root)==0|| temp.begin()->compare(Mult)==0|| temp.begin()->compare(Div)==0)){
				for(int k=temp.size(); k>0; k--){
					if(temp.back().compare(Lparen)==0)
						continue;
					post.push_back(temp.back());
					temp.pop_back();
				}
			}
			temp.push_back(tokens[i]);
		}
		else if(tokens[i].compare(Lparen)==0){
			temp.push_back(tokens[i]);
		}
		else if(tokens[i].compare(Rparen)==0){
			while(temp.back().compare(Lparen)!=0){
				post.push_back(temp.back());
				temp.pop_back();
			}
			temp.pop_back();
		}
		else{
			post.push_back(tokens[i]);
		}
#ifdef DEBUG
		cout<<"post is"<<endl;
		for(vector<string>::iterator i=post.begin();i!=post.end();++i)
			cout<<" => "<<*i<<endl;
		cout<<"temp is"<<endl;
		for(vector<string>::iterator i=temp.begin();i!=temp.end();++i)
			cout<<" => "<<*i<<endl;
#endif
	}
	for(int k=temp.size(); k>0; k--){
		if(temp.back().compare(Lparen)!=0|| temp.back().compare(Rparen)!=0)
			post.push_back(temp.back());
		temp.pop_back();
	}
#ifdef DEBUG
	cout<<"Changed to RPL."<<endl
		<<"post is"<<endl;
	for(vector<string>::iterator i=post.begin();i!=post.end();++i)
		cout<<" => "<<*i<<endl;
	cout<<"temp is"<<endl;
	for(vector<string>::iterator i=temp.begin();i!=temp.end();++i)
		cout<<" => "<<*i<<endl;
#endif

	vector<InfInt> InfVec;

	for(int i= 0; i< (int)post.size(); i++){
#ifdef DEBUG
		cout<<"post["<<i<<"] is debugging: "<<post[i]<<endl;
#endif
		if(post[i].compare(Plus)==0|| post[i].compare(Minus)==0|| post[i].compare(Mult)==0|| post[i].compare(Div)==0|| post[i].compare(Pow)==0|| post[i].compare(Root)==0){
			InfInt A(InfVec.back());
			InfVec.pop_back();
			InfInt B(InfVec.back());
			InfVec.pop_back();
			InfInt C;
#ifdef DEBUG
			cout<<"A: "<<A<<" B: "<<B<<endl;
#endif
			if(post[i].compare(Plus)==0){
				C= B+A;
#ifdef DEBUG
				cout<<"B+A -> C: "<<C<<endl;
#endif
			}
			else if(post[i].compare(Minus)==0){
				C= B-A;
#ifdef DEBUG
				cout<<"B-A -> C: "<<C<<endl;
#endif
			}
			else if(post[i].compare(Mult)==0){
				C= B*A;
#ifdef DEBUG
				cout<<"B*A -> C: "<<C<<endl;
#endif
			}
			else if(post[i].compare(Div)==0){
				C= B/A;
#ifdef DEBUG
				cout<<"B/A -> C: "<<C<<endl;
#endif
			}
			else if(post[i].compare(Pow)==0){
				C= B.pow(A);
#ifdef DEBUG
				cout<<"B^A -> C: "<<C<<endl;
#endif
			}
			else if(post[i].compare(Root)==0){
				C= B.root(A);
#ifdef DEBUG
				cout<<"BvA -> C: "<<C<<endl;
#endif
			}
			InfVec.push_back(C);
		}

		else{
			InfInt Temp(post[i]);
			InfVec.push_back(Temp);
		}
	}

	//InfInt ret(temp[0].c_str());
	//return ret;
#ifdef DEBUG
	cout<<"Parser::Operation finished!"<<endl<<"Will return..."<<endl<<" => "<<InfVec[0]<<endl;
#endif
	return InfVec[0];
}
