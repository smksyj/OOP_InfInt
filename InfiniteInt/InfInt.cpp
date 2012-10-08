#include "InfInt.h"

InfInt::InfInt() { // assign 0 as a default value
	this->digits = string("0");
	this->thesign = true;
}

InfInt::InfInt(int value) {
	this->digits = "";
	this->thesign = value > 0 ? true : false;

	while ( value != 0 ) {
		if ( value % 10 == 0 ) {
			this->digits += "0";
		} else {
			this->digits += value % 10 + 48;
		}
		value /= 10;
	}
}

InfInt::InfInt(const char* value) {
	if ( value[0] == '-' ) {
		this->thesign = false;
		this->digits = "";
		for ( int i = 1; value[i] != NULL; i++ ) {
			if ( isdigit(value[i]) != 0 ) {
				this->digits += value[i];
			}
		}
	} else {
		this->thesign = true;
		//this->digits = string(value);
		for ( int i = 0; value[i] != NULL; i++ ) {
			if ( isdigit(value[i]) != 0 ) {
				this->digits += value[i];
			}
		}
	}
}

InfInt::InfInt(const InfInt& value) { // copy constructor
	this->digits = "";
	this->thesign = value.thesign;

	for ( int i = 0; i < (unsigned int)value.digits.size(); i++ ) {
		this->digits += value.digits.at(i);
	}
}

InfInt::~InfInt() {
}

InfInt& InfInt::operator=(const InfInt& value) { // assignment operator
	return InfInt(value.digits.c_str());
}

bool operator==(const InfInt& self, const InfInt& other) {
	if ( self.thesign == other.thesign && self.digits.compare(other.digits) == 0 ) {
		return true;
	}

	return false;
}

bool operator!=(const InfInt& self, const InfInt& other) {
	return !operator==(self, other);
}

bool operator>(const InfInt& self, const InfInt& other) {
	if ( self.thesign == false && other.thesign == true ) {
		return false;
	} else if ( self.thesign == true && other.thesign == false ) {
		return true;
	} else if ( self.thesign == true && other.thesign == true ) {
		return self.digits.compare(other.digits) < 0 ? false : true;
	} else {
		return self.digits.compare(other.digits) < 0 ? true : false;
	}
}

bool operator<(const InfInt& self, const InfInt& other) {
	if ( !operator>(self, other) && !operator>(self, other) ) {
		return true;
	}

	return false;
}

InfInt operator+(const InfInt& self, const InfInt& other) {
	self.digits;

	return InfInt();
}

InfInt operator-(const InfInt& self, const InfInt& other) {

	return InfInt();
}

InfInt operator*(const InfInt& self, const InfInt& other) {
	return InfInt();
}

// friend InfInt InfInt::operator/(const InfInt& self, const InfInt& other); // not required

ostream& operator<<(ostream& out, const InfInt& self) {
	if ( self.thesign == false ) {
		out.put('-');
	}

	for ( int i = 0; i < (unsigned int)self.digits.size(); i++ ) {
		out.put(self.digits.at(i));
	}

	return out;
}
// friend istream& InfInt::operator>>(istream& , InfInt&);    // not required