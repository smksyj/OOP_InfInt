#include "Parser.h"


Parser::Parser(void)
{
	this->operators.push_back('+');
	this->operators.push_back('-');
	this->operators.push_back('*');
	this->operators.push_back('/');
	this->operators.push_back('^');
	this->operators.push_back('v');
}


Parser::~Parser(void)
{
}


vector<string> Parser::split(string value, char delemeter) {
	vector<string> ret;

	for ( int i = 0, j = 0; i < (int)value.size(); i++ ) {
		if ( value.at(i) == delemeter ) {
			ret.push_back(value.substr(j, i - j));
			j = i;
			j++;
		} else if ( i == (int)value.size() - 1 ) {
			ret.push_back(value.substr(j, i - j + 1));
		}
	}

	return ret;
}

bool Parser::sameToDelemeter(char c) {
	for ( int i = 0; i < operators.size(); i++ ) {
		if ( operators.at(i) == c ) {
			return true;
		}
	}

	return false;
}