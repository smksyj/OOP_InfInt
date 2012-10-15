#ifndef PARSER_H_
#include <iostream>
#include <vector>
#include "InfInt.h"

using namespace std;

class Parser
{
private:
	vector<char> operators;
	vector<char> numbers;
	bool RPL;
public:
	Parser(void);
	~Parser(void);
	vector<string> split(string value, char delemeter);
	InfInt Operation(string expression);
};

#endif
