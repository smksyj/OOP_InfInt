#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "Parser.h"
#include "ConsoleParser.h"
#include "Operator.h"

class Calculator
{
private:
	Parser *parser;
	Operator *oper;
public:
	//Calculator(void);
	~Calculator(void);
	Calculator(Parser *parser);

	void run();
};
#endif