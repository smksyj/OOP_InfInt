#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#include <fstream>
#include <string>
#include <vector>

#include "parser.h"

using namespace std;

class FileParser :
	public Parser
{
private:
	ifstream *file;
public:
	//FileParser(void);
	FileParser(string filePath);
	~FileParser(void);

	vector<string> split(string value, char delemeter);
	string getExpression();
};
#endif