#include "Parser.h"


Parser::Parser(void)
{
	this->RPL=false;
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

vector<string> Parser::parsing(vector<string> parsed) {
	vector<string> ret;
	return ret;
}

InfInt Parser::calc() {
	InfInt ret;
	return ret;
}
