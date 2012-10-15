#include "Parser.h"


Parser::Parser(void)
{
}


Parser::~Parser(void)
{
}


vector<string> Parser::split(string value, char delimiter=' ') {
	vector<string> ret;

	for ( int i = 0, j = 0; i < (int)value.size(); i++ ) {
		if ( value.at(i) == delimiter ) {
			ret.push_back(value.substr(j, i - j));
			j = i;
			j++;
		} else if ( i == (int)value.size() - 1 ) {
			ret.push_back(value.substr(j, i - j + 1));
		}
	}

	return ret;
}

InfInt Parser::Operation(string expression){
#ifdef DEBUG
	cout<<"Parser::Operation debug started..."<<endl
		<<"The expression is "<<endl
		<<"  => "<<expression<<endl;
#endif
#ifdef DEBUG
	cout<<"Splitting..."<<endl;
#endif
	vector<string> tokens= split(expression, ' ');
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
		cout<<"token["<<i<<"] is debugging: "<<tokens[i]<<endl;
#endif
		if(tokens[i].compare(Mult)|| tokens[i].compare(Div)){
			temp.push_back(tokens[i]);
		}
		else if(tokens[i].compare(Plus)|| tokens[i].compare(Minus)){
			if(temp.size()!= 0 && (temp.begin()->at(0)== '*'|| temp.begin()->at(0)== '/')){
				for(int k=temp.size(); k>0; k--){
					post.push_back(temp.back());
					temp.pop_back();
				}
			}
			temp.push_back(tokens[i]);
		}
		else if(tokens[i].compare(Lparen)){
			temp.push_back(tokens[i]);
		}
		else if(tokens[i].compare(Rparen)){
			while(temp.back().compare(Lparen)){
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
		if(temp.back().compare(Lparen)|| temp.back().compare(Rparen))
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
		if(post[i].compare(Plus)|| post[i].compare(Minus)|| post[i].compare(Mult)|| post[i].compare(Div)){
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
