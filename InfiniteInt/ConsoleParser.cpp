#include "ConsoleParser.h"


ConsoleParser::ConsoleParser(void)
{
	this->operators.push_back('+');
	this->operators.push_back('-');
	this->operators.push_back('*');
	this->operators.push_back('/');
	this->operators.push_back('^');
	this->operators.push_back('v');
}


ConsoleParser::~ConsoleParser(void)
{
}


vector<string> ConsoleParser::split(string value, char delemeter) {
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

string ConsoleParser::getExpression() {
	string line;
	getline(cin, line);

	return line;
}