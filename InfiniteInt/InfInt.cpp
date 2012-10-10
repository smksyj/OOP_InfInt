#include "InfInt.h"

const int ASCII_POSITION = 48;

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
	int len = strlen(value) - 1;

	if ( value[0] == '-' ) {
		this->thesign = false;
		this->digits = "";
		for ( int i = len; i > 0; i-- ) {
			if ( isdigit(value[i]) != 0 ) {
				this->digits += value[i];
			}
		}
	} else {
		this->thesign = true;
		for ( int i = len; i > -1; i-- ) {
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

/*
InfInt::InfInt(InfInt *const target) {
	this->digits = string(target->digits);
}
*/

InfInt::~InfInt() {
}

InfInt& InfInt::operator=(const InfInt& value) { // assignment operator
	this->digits = string(value.digits);

	return *this;
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

	int carry = 0;
	InfInt ret;
	ret.digits.clear();

	if(self.thesign==other.thesign){
		for ( int i = 0; i < self.digits.size() || i < other.digits.size() || carry == 1; i++ ) {
			int result = 0;
			if ( i < other.digits.size() ) {
				result += (other.digits.at(i) - ASCII_POSITION);
			}
			if ( i < self.digits.size() ) {
				result += (self.digits.at(i) - ASCII_POSITION);
			}
			result += carry;

			if ( result >= 10 ) {
				ret.digits += result % 10 + ASCII_POSITION;
				carry = 1;
			} else {
				ret.digits += result + ASCII_POSITION;
				carry = 0;
			}
		}
		ret.thesign = self.thesign;
	}else{
		
	}

	return ret;
}

InfInt operator-(const InfInt& self, const InfInt& other) {

	
	int carry = 0;
	InfInt ret;
	
	ret.digits.clear();
	if(self>other){
		// It operates only first number is larger than second num.
		if(self.thesign==other.thesign){
			for ( int i = 0; i < self.digits.size() || i < other.digits.size() || carry == 1; i++ ) {
				int result = 0;
				if ( i < self.digits.size() ) {
					result += (self.digits.at(i) - ASCII_POSITION);
				}
				if ( i < other.digits.size() ) {
					result -= (other.digits.at(i) - ASCII_POSITION);
				}
				
				result += carry;
				carry = result<0?-1:0;
				
				if(result<0){
					result+=10;
				}
				
				ret.digits += (unsigned)result + ASCII_POSITION;
			}
		}
	}else{
		if(self.thesign==other.thesign){
			for ( int i = 0; i < self.digits.size() || i < other.digits.size() || carry == 1; i++ ) {
				int result = 0;
				if ( i < other.digits.size() ) {
					result += (other.digits.at(i) - ASCII_POSITION);
				}
				if ( i < self.digits.size() ) {
					result -= (self.digits.at(i) - ASCII_POSITION);
				}
				
				result += carry;
				carry = result<0?-1:0;
				
				if(result<0){
					result+=10;
				}
				
				ret.digits += (unsigned)result + ASCII_POSITION;
			}
		}
	}
	
	return ret;

}

InfInt operator*(const InfInt& self, const InfInt& other) {
	InfInt temp, ret;
	InfInt one("1");

	if(self.thesign == other.thesign){
		ret.thesign = true;
	}else{
		ret.thesign = false;
	}
	temp.thesign = other.thesign;
	while(temp != other){
		ret = ret+self;
		temp = temp + one;
	}

	return ret;
}

InfInt operator/(const InfInt& self, const InfInt& other) {
	bool sign_result= true;
	if(self.thesign!= other.thesign){
		sign_result= false;
	}

	InfInt Int1(self);
	InfInt Int2(other);

	Int1.thesign= Int2.thesign= true;

	InfInt quo;

	InfInt dummy('1');

	while(Int1.thesign== true){
		Int1= Int1- Int2;
		if(Int1.thesign== true){
			quo= quo+ dummy;
		}
	}

	return quo;
}

// friend InfInt InfInt::operator/(const InfInt& self, const InfInt& other); // not required

InfInt InfInt::pow(const InfInt& exp) {
	//exp¥¬ æÁº??��??�°¡�? ¿Ωº? µÈæÓø¿?��?0??�»�?
	InfInt temp(*this);

	if( exp.digits.compare("0") < 0 ) {
		return InfInt();
	}
	InfInt result("1");
	result.thesign = true;

	for ( int i = 0 ; i < exp ; i++ ) {
		result = temp * result;
	}

	if ( temp.thesign == false && (((exp.digits.at(0) - '0') % 2)==1)) {
		result.thesign = false;
	}

	return result;
}

InfInt InfInt::root() {
	InfInt me(*this);
	InfInt ret(-1);
	InfInt i(1);
	InfInt one(1);
	if(this->thesign!=true)
		return ret;
	ret=ret+one;
	for(;i*i+one<me;i=i+one)
		;
	return ret;
}

ostream& operator<<(ostream& out, const InfInt& self) {
	if ( self.thesign == false ) {
		out.put('-');
		for ( int i = self.digits.size() - 1; i > -1; i-- ) {
			out.put(self.digits.at(i));
		}
	} else {
		for ( int i = self.digits.size() - 1; i > -1; i-- ) {
			out.put(self.digits.at(i));
		}
	}
	return out;
}
// friend istream& InfInt::operator>>(istream& , InfInt&);    // not required
