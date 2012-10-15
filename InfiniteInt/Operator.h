#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <vector>
#include <string>

#include "InfInt.h"

using namespace std;

class Operator
{
public:
	Operator(void);
	~Operator(void);

	InfInt Operation(vector<string> tokens);
};
#endif