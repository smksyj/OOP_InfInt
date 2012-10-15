#ifndef PARSER_H_
#define PARSER_H_

#include <vector>
#include <string>

#include "InfInt.h"

using namespace std;

class Parser // working as Interface
{
public:
	virtual vector<string> split(string value, char delemeter) = 0;
	virtual string getExpression() = 0;
};
#endif