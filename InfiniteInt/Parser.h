#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Parser
{
private:
	vector<char> operators;
	bool sameToDelemeter(char c);
public:
	Parser(void);
	~Parser(void);
	vector<string> Parser::split(string value, char delemeter);
};
