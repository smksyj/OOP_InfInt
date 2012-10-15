#ifndef CONSOLEPARSER_H_
#define CONSOLEPARSER_H_

#include <iostream>
#include <vector>
#include "InfInt.h"
#include "Parser.h"

using namespace std;

class ConsoleParser : public Parser
{
private:
	vector<char> operators;
public:
	ConsoleParser(void);
	~ConsoleParser(void);
	vector<string> split(string value, char delemeter);
	string getExpression();
};
#endif