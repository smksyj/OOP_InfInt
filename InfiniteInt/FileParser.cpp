#include "FileParser.h"

/*
FileParser::FileParser(void)
{
}
*/
FileParser::FileParser(string filePath) {
	this->file = new ifstream(filePath, ios_base::in);
}


FileParser::~FileParser(void)
{
}

vector<string> FileParser::split(string value, char delemeter) {
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

	for ( int i = 0; i < (int)ret.size(); i++ ) {
		cout << ret.at(i) << " ";
	}

	return ret;
}

string FileParser::getExpression() {
	string line;

	if ( !this->file->eof() ) {
		getline(*this->file, line);

		return line;
	}

	return "0";
}
