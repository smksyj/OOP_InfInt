#include "InfInt.h"

//#define DEBUG

const int ASCII_POSITION = 48;

InfInt::InfInt() { // assign 0 as a default value
	this->digits = string("0");
	this->thesign = true;
}

InfInt::InfInt(int value) {
	this->digits = "";
	this->thesign = value > 0 ? true : false;

	if ( value == 0 ) {
		this->digits += "0";
	} else {
		while ( value != 0 ) {
			if ( value % 10 == 0 ) {
				this->digits += "0";
			} else {
				this->digits += value % 10 + 48;
			}
			value /= 10;
		}
	}
	/*
	if ( value == 0 ) {
		this->digits += "0";
	}
	*/
}

InfInt::InfInt(const string value) {
	int len = value.size() - 1;

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

	for ( int i = 0; i < (int)value.digits.size(); i++ ) {
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
	this->thesign = value.thesign;
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
	int maxLength = self.digits.size() > other.digits.size() ? self.digits.size() : other.digits.size();

	if ( self.thesign == other.thesign ) {
		if ( self.thesign == true ) { // +, +
			for ( int i = 0; i < maxLength || carry == 1; i++ ) {
				int result = 0;

				if ( (int)self.digits.size() > i ) {
					result += (self.digits.at(i) - ASCII_POSITION);
				}
				if ( (int)other.digits.size() > i ) {
					result +=  + (other.digits.at(i) - ASCII_POSITION);
				}
				result += carry;

				if ( result >= 10 ) {
					result -= 10;
					carry = 1;
				} else {
					carry = 0;
				}

				ret.digits += result + 48;
			}

		} else { // -, -
			for ( int i = 0; i < maxLength || carry == 1; i++ ) {
				int result = 0;

				if ( (int)self.digits.size() > i ) {
					result += (self.digits.at(i) - ASCII_POSITION);
				}
				if ( (int)other.digits.size() > i ) {
					result +=  + (other.digits.at(i) - ASCII_POSITION);
				}
				result += carry;

				if ( result >= 10 ) {
					result -= 10;
					carry = 1;
				} else {
					carry = 0;
				}

				ret.digits += result + ASCII_POSITION;
			}

			ret.thesign = false;

		}
	} else { // self.thesign != other.thesign
//		if ( self.thesign == true ) { // +, -

			if ( self.digits.size() > other.digits.size() ) { // 길이가 self가 더 클 경우 -> self에서 빼기
			selfIsBigger:
				for ( int i = 0; i < maxLength; i++ ) {
					int result = 0;

					if ( (int)self.digits.size() > i ) {
						result += (self.digits.at(i) - ASCII_POSITION) - carry;
					}
					if ( (int)other.digits.size() > i ) {
						result -= (other.digits.at(i) - ASCII_POSITION);
					}

					if ( result < 0 ) {
						result = 10 + result;
						carry = 1;
					} else {
						carry = 0;
					}

					ret.digits += result + ASCII_POSITION;
				}

				for ( int i = ret.digits.size() - 1; i >= 0; i-- ) {
					if ( ret.digits.at(i) == '0' ) {
						ret.digits.erase(ret.digits.size()-1);
						//ret.digits.pop_back();
					} else {
						break;
					}
				}
				ret.thesign = self.thesign;
				if ( ret.digits.compare("0") == 0 ) {
					ret.thesign = true;
				}

			} else if ( self.digits.size() < other.digits.size() ) { // 길이가 self가 더 작을 경우 -> other에서 빼기
			selfIsSmaller:
				for ( int i = 0; i < maxLength; i++ ) {
					int result = 0;

					if ( (int)other.digits.size() > i ) {
						result += (other.digits.at(i) - ASCII_POSITION) - carry;
					}
					if ( (int)self.digits.size() > i ) {
						result -= (self.digits.at(i) - ASCII_POSITION);
					}

					if ( result < 0 ) {
						result = 10 + result;
						carry = 1;
					} else {
						carry = 0;
					}

					ret.digits += result + ASCII_POSITION;
				}
				
				for ( int i = ret.digits.size() - 1; i >= 0; i-- ) {
					if ( ret.digits.at(i) == '0' ) {
						ret.digits.erase(ret.digits.size()-1);
						//ret.digits.pop_back();
					} else {
						break;
					}
				}
				ret.thesign = other.thesign;
				if ( ret.digits.compare("0") == 0 ) {
					ret.thesign = true;
				}


			} else { // 길이가 같을 경우
				for ( int i = self.digits.size() - 1; i >= 0; i-- ) {
					if ( self.digits.at(i) - other.digits.at(i) > 0 ) {
						goto selfIsBigger;
					} else if ( self.digits.at(i) - other.digits.at(i) < 0 ) {
						goto selfIsSmaller;
					}
					/*
					else {
						return InfInt("0");
					}
					*/
				}

				return InfInt("0");
			}

			/*
		} else { // -, +
			
		}
		*/
	}


	return ret;
}

InfInt operator-(const InfInt& self, const InfInt& other) {
	InfInt minus(other);
	if ( other.digits.compare("0") != 0 ) {
		minus.thesign = false;
	}
	if ( other.thesign == false ) {
		minus.thesign = true;
	}
	return self + minus;
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
		
	for(int i=0; i < (int)other.digits.length(); i++){
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

	InfInt dummy("1");
	InfInt dummy2("-1");

	while(Int1.thesign== true){
 		Int1= Int1- Int2;
		if(Int1.thesign== true){
			quo= quo+ dummy;
		}
	}

	if(sign_result== false){
		quo= quo* dummy2;
	}

	return quo;
}

// friend InfInt InfInt::operator/(const InfInt& self, const InfInt& other); // not required

InfInt InfInt::pow(const InfInt& exp) {
	//exp is positive number
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
	if(me.thesign!=true||num<one){
#ifdef DEBUG
		cout<<"Can't calculate root. Will return "<<ret<<endl;
#endif
		return ret;
	}
	for(ret=one;ret.pow(num)<me+one;ret=ret+one){
#ifdef DEBUG
		cout<<"ret:"<<ret<<" ret.pow(num):"<<ret.pow(num)<<" ret.pow(num)<me:"<<(ret.pow(num)<me)<<endl<<"Press any key..."<<endl;
		getchar();
#endif
	}
	ret=ret-one;
#ifdef DEBUG
	cout<<"root() debugging finished. Will return "<<ret<<endl;
#endif
	return ret;
}

ostream& operator<<(ostream& out, const InfInt& self) {
	if ( self.digits.compare("0") == 0 ) {
		out.put('0');
		return out;
	}

	if ( self.thesign == false ) {
		out.put('-');
		for ( int i = self.digits.size() - 1; i > -1; i-- ) {
			/*
			if ( self.digits.at(i) != '0' ) {
				print = true;
			}

			if ( print ) {
				out.put(self.digits.at(i));
			}
			*/
			out.put(self.digits.at(i));
		}
	} else {
		for ( int i = self.digits.size() - 1; i > -1; i-- ) {
			/*
			if ( self.digits.at(i) != '0' ) {
				print = true;
			}

			if ( print ) {
				out.put(self.digits.at(i));
			}
			*/
			out.put(self.digits.at(i));
		}
	}
	return out;
}
// friend istream& InfInt::operator>>(istream& , InfInt&);    // not required
