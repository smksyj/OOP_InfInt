#ifndef PARSER_H_
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
	vector<string> split(string value, char delemeter);
};
#endif
