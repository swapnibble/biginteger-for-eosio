#include "BigIntegerUtils.hpp"
#include "BigUnsignedInABase.hpp"

eosio::string bigUnsignedToString( const BigUnsigned &x) {
	return eosio::string(BigUnsignedInABase(x, BigUnsignedInABase::Base(10) ) );
}

eosio::string bigIntegerToString( const  BigInteger &x) {
	return (x.getSign() == BigInteger::negative)
		? (eosio::string("-") + bigUnsignedToString(x.getMagnitude()))
		: (bigUnsignedToString(x.getMagnitude()));
}

BigUnsigned stringToBigUnsigned(const eosio::string &s) {
	return BigUnsigned(BigUnsignedInABase(s, BigUnsignedInABase::Base(10) ) );
}


class ext_string : public eosio::string {
public:
	ext_string( const eosio::string &cstr): eosio::string(cstr){}

	const eosio::string substr(size_t offset, size_t substr_size, bool copy) {
		return (const eosio::string) ( eosio::string::substr( offset, substr_size, copy) ) ;
    }
};

BigInteger stringToBigInteger( const eosio::string &s) {
	// Recognize a sign followed by a BigUnsigned.
	const char signChar = s.get_data()[0];
	ext_string childStr( s );
	
	return (signChar == '-') ? BigInteger(stringToBigUnsigned(childStr.substr(1, s.get_size() - 2, false)), BigInteger::negative)
		: (signChar == '+') ? BigInteger(stringToBigUnsigned(childStr.substr(1, s.get_size() - 2, false)))
		: BigInteger(stringToBigUnsigned(s));
}

// commented by swapnibble
/*
eosio::ostream &operator <<(eosio::ostream &os, const BigUnsigned &x) {
	BigUnsignedInABase::Base base;
	long osFlags = os.flags();
	if (osFlags & os.dec)
		base = 10;
	else if (osFlags & os.hex) {
		base = 16;
		if (osFlags & os.showbase)
			os << "0x";
	} else if (osFlags & os.oct) {
		base = 8;
		if (osFlags & os.showbase)
			os << '0';
	} else {
		throw "eosio::ostream << BigUnsigned: Could not determine the desired base from output-stream flags";
	}
	eosio::string s = eosio::string(BigUnsignedInABase(x, base));
	os << s;
	return os;
}

eosio::ostream &operator <<(eosio::ostream &os, const BigInteger &x) {
	if (x.getSign() == BigInteger::negative)
		os << '-';
	os << x.getMagnitude();
	return os;
}
*/