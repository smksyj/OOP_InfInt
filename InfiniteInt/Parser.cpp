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
