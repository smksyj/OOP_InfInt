#ifndef INFINT_H_
#define INFINT_H_

#include <iostream>
#include <string>

using namespace std;

class InfInt
{
private :
	/*
    char* digits;
    unsigned int length;
	*/
	string digits;
    bool thesign;   // true if positive , false if negative.
    // ex) 15311111111111111 -> digits="11111111111111351", length=17, thesign=true;
    // ex) -12345555555555 -> digits="55555555554321", length=14, thesign=false
    // you may insert additional private members here.

public :
    InfInt();               // assign 0 as a default value
    InfInt(int);
    InfInt(const string);
    InfInt(const InfInt&); // copy constructor
    ~InfInt(); // destructor
	
    InfInt& operator=(const InfInt&); // assignment operator
    friend bool operator==(const InfInt& , const InfInt&);
    friend bool operator!=(const InfInt& , const InfInt&);
    friend bool operator>(const InfInt& , const InfInt&);
    friend bool operator<(const InfInt& , const InfInt&);

    friend InfInt operator+(const InfInt& , const InfInt&);
    friend InfInt operator-(const InfInt& , const InfInt&);
    friend InfInt operator*(const InfInt& , const InfInt&);
    friend InfInt operator/(const InfInt& , const InfInt&);
    InfInt pow(const InfInt&);
    InfInt root(const InfInt& num=InfInt(2));

    friend ostream& operator<<(ostream& , const InfInt&);

    // friend istream& operator>>(istream& , InfInt&);    // not required
};
#endif
