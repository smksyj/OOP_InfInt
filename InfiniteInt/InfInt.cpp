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
	if ( self.thesign == false && other.thesign == true ) { // negative, positive
		return false;
	} else if ( self.thesign == true && other.thesign == false ) { // positive, negative
		return true;
	} else if ( self.thesign == true && other.thesign == true ) { // both are positive
		if ( self.digits.size() > other.digits.size() ){
			return true;
		}
		else if( self.digits.size() < other.digits.size() ) {
			return false;
		}
		else {
			int i = self.digits.size()-1;
			for ( ; i >= 0 ; i--) {
				if ( self.digits.at(i) > other.digits.at(i) ) {
					return true;
				}
				else if( self.digits.at(i) < other.digits.at(i) ) {
					return false;
				}
			}
		}	
	} else if ( self.thesign == false && other.thesign == false ) { // both are negative
		if ( self.digits.size() < other.digits.size() ){
			return true;
		}
		else if( self.digits.size() > other.digits.size() ) {
			return false;
		}
		else {
			int i = self.digits.size()-1;
			for ( ; i >= 0 ; i--) {
				if ( self.digits.at(i) < other.digits.at(i) ) {
					return true;
				}
				else if( self.digits.at(i) > other.digits.at(i) ) {
					return false;
				}
			}
		}
	}
}

bool operator<(const InfInt& self, const InfInt& other) {
	if ( !operator>(self, other) && !operator==(self, other) ) {
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
	InfInt self2(self);
	InfInt other2(other);
	InfInt ret;

	ret.digits.clear();
	if(self.thesign==other.thesign){
		if(self.thesign==true&&self>other){
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
			
		}else{
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
		if(self.thesign==true&&self<other){
			ret.thesign=false;
		}
		if(self.thesign==false){
			ret.thesign=true;
		}
	}else{
		
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
	}

	return ret;

}

InfInt operator*(const InfInt& self, const InfInt& other) {
	InfInt ret, tempVal(self);
	if(self.digits == ret.digits ||other.digits == ret.digits){
		return ret;
	}

	if(self.thesign == other.thesign){
		ret.thesign = true;
	}else{
		ret.thesign = false;
	}
	tempVal.thesign = ret.thesign;
		
	for(int i=0; i < other.digits.length(); i++){
		InfInt temp;
		temp.thesign = ret.thesign;
		for(char j='0'; j < other.digits[i]; j++){
			temp = temp + tempVal;
		}
		for(int k = 0; k < i; k++){
			temp.digits = '0' + temp.digits;
		}
		ret = ret + temp;
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
	//exp¬•¬¨ √¶√Å¬∫??ë≈??û¬∞¬°¬? ¬øŒ©¬∫? ¬µ√à√¶√ì√∏¬ø?è√?0??∫¬ª√?
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

InfInt InfInt::root(const InfInt& num) {
#ifdef DEBUG
	cout<<"Start root in debugging mode..."<<endl;
#endif
	InfInt me(*this);
#ifdef DEBUG
	cout<<"me:"<<me<<" num:"<<num<<endl;
#endif
	InfInt ret(-1);
	InfInt one(1);
	if(this->thesign!=true||num<one)
		return ret;
	ret=ret+one;
	for(;ret.pow(num)+one<me;ret=ret+one){
#ifdef DEBUG
		cout<<"ret:"<<ret<<" ret.pow(num):"<<ret.pow(num)<<" ret.pow(num+one<me:"<<(ret.pow(num)+one<me)<<endl<<"Press any key..."<<endl;
		getchar();
#endif
	}
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
