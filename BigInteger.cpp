//-----------------------------------------------------------------------------
// Mika Peer Shalem, mpeersha
// 2023 Winter CSE101, PA6
// BigIntegers.cpp
// Implements a BigInteger ADT that includes access and manipulation functions. 
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include"BigInteger.h"
using namespace std;

// Global vars
long const base = 1000000000;
int const power = 9;
// Class Constructors & Destructors ----------------------------------------

// BigInteger()
// Constructor that creates a new BigInteger in the zero state: 
// signum=0, digits=().
BigInteger::BigInteger() {
    signum = 0;
    digits.clear();
}

// BigInteger()
// Constructor that creates a new BigInteger from the string s.
// Pre: s is a non-empty string consisting of (at least one) base 10 digit
// {0,1,2,3,4,5,6,7,8,9}, and an optional sign {+,-} prefix.
BigInteger::BigInteger(std::string s) {
    // Precondition
    if (s.find_first_not_of("+-0123456789") != std::string::npos) {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    }
    if (s.length() <= 0) {
        throw std::invalid_argument("BigInteger: Constructor: empty string");
    }
    if (s.length() == 1 && (s.find('-', 0) != std::string::npos || s.find('+', 0) != std::string::npos)) {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    }
    if (s.substr(1).find('+', 0) != std::string::npos) {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    }
    if (s.substr(1).find('-', 0) != std::string::npos) {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    }
    // Sign of number
    if (s.find('+', 0) != std::string::npos) {
        signum = 1;
        s.erase(0, 1); // erase sign
    } else if (s.find('-', 0) != std::string::npos) {
        signum = -1;
        s.erase(0, 1); // erase sign
    } else {
        signum = 1;
    }
    // Magnitude
    int pos = 0;
    ulong chars_in_element;
    // If is int
    if ((s.length() % power) == 0) {
        chars_in_element = s.length() / power;
    } else {
        chars_in_element = s.length() / power + 1;
    }
    // Delete leading 0s
    long find = 1;
    long count = 0;
    long length = s.length();
    while (s.length() > 1) {
        std::string num = s.substr(0,1);
        find = stol(num);
        if (find == 0) {
            s.erase(0,1);
        } else {
            break;
        }
        count += 1;
    }
    if (count == length) {
        signum = 0;
        return;
    }
    while (s.length() > power) {
        std::string num = s.substr(s.length()-power, s.length());
        ulong i = stol(num);
        digits.insertAfter(i);
        s.erase(s.length()-power, s.length());
    }   
    if (s.length() > 0) {        
        ulong i = stol(s);
        digits.insertAfter(i);
        s.erase(pos, pos+chars_in_element+1);
    }
    // cout << "\nDigits = " << digits.to_string();
}

// BigInteger()
// Constructor that creates a copy of N.
BigInteger::BigInteger(const BigInteger& N) {
    signum = N.signum;
    digits = N.digits;
}

// Optional Destuctor
// ~BigInteger()
// ~BigInteger();

// Access functions --------------------------------------------------------

// sign()
// Returns -1, 1 or 0 according to whether this BigInteger is negative, 
// positive or 0, respectively.
int BigInteger::sign() const {
    return signum;
}

// compare()
// Returns -1, 1 or 0 according to whether this BigInteger is less than N,
// greater than N or equal to N, respectively.
int BigInteger::compare(const BigInteger& N) const {
    // cout << "n sign: " << N.signum << "this sign: " << this->signum << endl;
    if (N.signum > this->signum) {
        return -1;
    } else if (N.signum < this->signum) {
        return 1;
    } else {
        List copyN = N.digits;
        List copyThis = digits;
        
        if (N.signum == 1) { 
            if (copyN.length() > copyThis.length()) { return -1; }
        } else if (N.signum == -1) { 
            if (copyN.length() < copyThis.length()) { return -1; }
        }
        else if (copyN.length() < copyThis.length()) { return 1; }
        // Same length
        copyN.moveFront(); copyThis.moveFront();
        while (copyN.position() < copyN.length()) {
            long nValue = copyN.peekNext(); long thisValue = copyThis.peekNext();
            if (N.signum == -1) { 
                nValue *= -1;
            } if (signum == -1) {
                thisValue *= -1;
            }
            // cout << "n value: " << nValue << "this value: " << thisValue << endl;
            if (nValue > thisValue) { return -1; }
            else if (nValue < thisValue) { return 1; }
            else { 
                copyN.moveNext();
                copyThis.moveNext();
            }
        }
        return 0;
    }
}



// Manipulation procedures -------------------------------------------------

// makeZero()
// Re-sets this BigInteger to the zero state.
void BigInteger::makeZero() {
    signum = 0;
    digits.clear();
}

// negate()
// If this BigInteger is zero, does nothing, otherwise reverses the sign of 
// this BigInteger positive <--> negative. 
void BigInteger::negate() {
    if (signum != 0) { 
        signum *= -1;
    }
}


// BigInteger Arithmetic operations ----------------------------------------

// normalize()
// Normalizes each node of the list, O(n)
int normalize(List& L) {
    L.moveBack();
    int sign = 0;
    int carry = 0;
    while (L.position() > 0) {
        long val = L.peekPrev();
        if (carry >= 1) { val += carry; carry=0; }
        if (val>=base) {
            carry = val/base;
            val = val%base;
        }
        if (val > 0) { sign = 1; } 
        else if (val < 0) { sign = -1; }
        L.setBefore(val);
        L.movePrev();
    }
    if (carry != 0) { L.insertAfter(carry); }
    // cout << "L: " << L.to_string() << endl;
    return sign;
}


// add()
// Returns a BigInteger representing the sum of this and N. O(n^2)
BigInteger BigInteger::add(const BigInteger& N) const {
    BigInteger sum;
    List L = digits;
    List copyN = N.digits;
    // std::cout << "N IS: " << copyN.to_string() << "A is " << L.to_string() << endl;
    // std::cout << "N IS: " << N.signum << "A is " << signum << endl;
    if (N.signum != -1 && signum == -1) {
        BigInteger copyThis; copyThis.signum = -1*signum; copyThis.digits = digits;
        return N.sub(copyThis);
    }
    if (N.signum == -1 && signum != -1) {
        BigInteger copy; copy.signum = -1*N.signum; copy.digits = N.digits;
        return sub(copy);
    }
    if (N.signum == -1 && signum == -1) {
        BigInteger negateThis; negateThis.digits = digits; negateThis.signum = 1;
        BigInteger negateN; negateN.digits = N.digits; negateN.signum = 1;
        sum = negateThis.add(negateN);
        sum.signum = -1;
        return sum;
    }
    L.moveBack(); copyN.moveBack();
    while (L.position() > 0 || copyN.position() > 0) {
        long lValue = 0; long nValue = 0;
        if (L.position() > 0) { lValue = L.movePrev();}
        if (copyN.position() > 0) { nValue = copyN.movePrev();}
        long current = lValue + nValue;
        sum.digits.insertAfter(current);
    }
    // std::cout << "sum digits: " << sum.digits << endl;
        // ERASE LEADING 0S
    if (sum.digits.length() == 1) { 
        if (sum.digits.front() == 0) { 
            sum.digits.clear(); 
            return sum;
        }
    }
    sum.digits.moveFront();
    
    while (sum.digits.length() > 1 && sum.digits.position() < sum.digits.length()) {
        if (sum.digits.peekNext() == 0) {
            sum.digits.eraseAfter();
        } else { break; }
    }
    if (sum.digits.length() > 1) {
        long v = sum.digits.peekNext();
        if (v == 0) { sum.digits.eraseAfter(); }
        else {
            std::string vs = std::to_string(v);
            if (vs.find_first_not_of("0123456789") == std::string::npos) { 
                sum.digits.setAfter(stol(vs));
            }
        }
    }
    int sign = normalize(sum.digits);
    sum.signum = sign;
    return sum;
}

// normalizeDiff()
// Normalizes each node of the list, O(n)
int normalizeDiff(List &L) {
    int sign = 0;
    int carry = 0;
    L.moveFront();
    // Sign is based on first element
    if (L.peekNext() > 0) { sign = 1; } 
    else if (L.peekNext() < 0) { sign = -1; }
    L.moveBack();
    long val;
    while (L.peekPrev() != L.front()) {
        if (sign == -1) { val = (-1*L.peekPrev()); }
        else { val = L.peekPrev(); }
        // std::cout << "val before  " << val << endl;
        if (carry >= 1) { val -= carry; carry = 0; }
        if (val < 0) {
            long neg_sign = ((-1*val)/base)+1;
            val += neg_sign*base;
            carry += neg_sign;
        }
        L.setBefore(val);
        L.movePrev();
    }
    if (sign == -1) {
        // std::cout << "carry after  " << carry << endl;
        // std::cout << "val after  " << val << endl;
        val = -1*(L.peekPrev());
        if (carry > 0) { val -= 1; }
        // std::cout << "val after  " << val << endl;
        
        L.setBefore(val);
    } else {
        if (carry > 0) {
            val = L.peekPrev() - 1;
            L.setBefore(val);
        }
    }
    return sign;
}


// sub()
// Returns a BigInteger representing the difference of this and N.
BigInteger BigInteger::sub(const BigInteger& N) const {
    BigInteger diff;
    List L = digits;
    List copyN = N.digits;
    if ((&N)==this) {
        diff.signum = 0;
        return diff;
    }
    if (N.signum == -1) {
        BigInteger copyN; copyN.digits = N.digits; copyN.signum = 1;
        return add(copyN);
    }
    if (signum == -1 && N.signum == 1) {
        BigInteger copyThis; copyThis.digits = digits; copyThis.signum = 1;
        diff = copyThis.add(N);
        diff.signum = -1;
        return diff;
    }
    // Does the substraction
    L.moveBack(); copyN.moveBack();
    while (L.position() > 0 || copyN.position() > 0) {
        long lValue = 0; long nValue = 0;
        if (L.position() > 0) { lValue = L.movePrev();}
        if (copyN.position() > 0) { nValue = copyN.movePrev();}
        long current = lValue - nValue;
        diff.digits.insertAfter(current);
    }
    // std::cout << "After sub Digits diff: " << diff.digits.to_string() << endl;
    // ERASE LEADING 0S
    if (diff.digits.length() == 1) { 
        if (diff.digits.front() == 0) { 
            diff.digits.clear(); 
            return diff;
        }
    }
    diff.digits.moveFront();
    while (diff.digits.length() > 1 && diff.digits.position() < diff.digits.length()) {
        // printf("here %d\n", diff.digits.position());
        if (diff.digits.peekNext() == 0) {
            diff.digits.eraseAfter();
        } else { break; }
    }
    if (diff.digits.length() > 1) {
        long v = diff.digits.peekNext();
        if (v == 0) { diff.digits.eraseAfter(); } 
        else {
            std::string vs = std::to_string(v);
            if (vs.find_first_not_of("0123456789") == std::string::npos) { 
                diff.digits.setAfter(stol(vs));
            }
        }
    }

    // std::cout << "After sub Digits diff: " << diff.digits.to_string() << endl;
    // Normalizes
    int sign = normalizeDiff(diff.digits);
    diff.signum = sign;
    return diff;
}

// scalarMult()
// Returns a list after scalar multiplying
List scalarMult(List &L, long i, int shift) {
    List mult = L;
    // std::cout << "Scalar mult: " << mult.to_string() << " i: " << i << endl;
    mult.moveBack();
    for (int i=0; i<shift; i += 1) {
        mult.insertAfter(0);
    }
    while (mult.position() > 0) {
        mult.setBefore(mult.peekPrev() * i);
        mult.movePrev();
    }
    // std::cout << "Scalar mult: " << mult.to_string() << endl;
    return mult;
}

// mult()
// Returns a BigInteger representing the product of this and N. 
BigInteger BigInteger::mult(const BigInteger& N) const {
    BigInteger prod;
    List L = digits;
    List copyN = N.digits;
    List save;
    int shift = 0;
    copyN.moveBack();
    while (copyN.position() > 0) {
        long nValue = 0;
        if (copyN.position() > 0) { nValue = copyN.peekPrev(); copyN.movePrev();}
        // scalar mult
        List scale = scalarMult(L, nValue, shift);
        normalize(scale);
        BigInteger prev; prev.digits = scale;
        // std::cout << "after scale: " << scale.to_string() << " after norm: " << norm.to_string() << endl;
        // std::cout << "before add prod: " << prod.digits.to_string() << endl;
        prod = prev.add(prod);       
        // std::cout << "prod: " << prod.digits.to_string() << endl;
        shift += 1;
    }
    if (prod.signum == 0) {
        return prod;
    }
    if ((signum == -1 && N.signum == 1) || (signum == 1 && N.signum == -1)) {
        prod.signum = -1;
    } else {
        prod.signum = 1;
    }
    return prod;
}


// Other Functions ---------------------------------------------------------

// to_string()
// Returns a string representation of this BigInteger consisting of its
// base 10 digits. If this BigInteger is negative, the returned string 
// will begin with a negative sign '-'. If this BigInteger is zero, the
// returned string will consist of the character '0' only.
std::string BigInteger::to_string() {
    // cout << "s is " << signum << endl;
    // std::cout << "DIGITS IS " << digits.to_string() << endl;
    std::string s = "";
    // Sign
    if (signum == -1) {
        s += "-";
    } else if (signum == 0) {
        s += "0";
        return s;
    }
    digits.moveFront();
    s += std::to_string(digits.peekNext());
    digits.moveNext();
    while (digits.position() < digits.length()) {
        long i = digits.peekNext();
        std::string val = std::to_string(i);
        // std::cout << "s: " << val << endl;
        long count = val.length();
        while (count < power) {
            s += '0';
            count += 1;
        }
        s += val;
        // std::cout << "s: " << s << endl;
        digits.moveNext();
    }
    // s += digits.to_string();
    // cout << "s is " << digits.to_string() << endl;
    return s;
}


// Overriden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of N into stream.
std::ostream& operator<<( std::ostream& stream, BigInteger N ) {
    return stream << N.BigInteger::to_string();
}

// operator==()
// Returns true if and only if A equals B. 
bool operator==( const BigInteger& A, const BigInteger& B ) {
    if (A.compare(B) == 0) { return true; }
    return false;
}

// operator<()
// Returns true if and only if A is less than B. 
bool operator<( const BigInteger& A, const BigInteger& B ) {
    if (A.compare(B) == -1) { return true; }
    return false;
}

// operator<=()
// Returns true if and only if A is less than or equal to B. 
bool operator<=( const BigInteger& A, const BigInteger& B ) {
    if ((A.compare(B) == 0) || (A.compare(B) == -1)) { return true; }
    return false;
}

// operator>()
// Returns true if and only if A is greater than B. 
bool operator>( const BigInteger& A, const BigInteger& B ) {
    if (A.compare(B) == 1) { return true; }
    return false;
}

// operator>=()
// Returns true if and only if A is greater than or equal to B. 
bool operator>=( const BigInteger& A, const BigInteger& B ) {
    if ((A.compare(B) == 0) || (A.compare(B) == 1)) { return true; }
    return false;
}

// operator+()
// Returns the sum A+B. 
BigInteger operator+( const BigInteger& A, const BigInteger& B ) {
    return A.add(B);
}

// operator+=()
// Overwrites A with the sum A+B. 
BigInteger operator+=( BigInteger& A, const BigInteger& B ) {
    A = A.add(B);
    return A;
}

// operator-()
// Returns the difference A-B. 
BigInteger operator-( const BigInteger& A, const BigInteger& B ) {
    return A.sub(B);
}

// operator-=()
// Overwrites A with the difference A-B. 
BigInteger operator-=( BigInteger& A, const BigInteger& B ) {
    A = A.sub(B);
    return A;
}

// operator*()
// Returns the product A*B. 
BigInteger operator*( const BigInteger& A, const BigInteger& B ) {
    return A.mult(B);
}

// operator*=()
// Overwrites A with the product A*B. 
BigInteger operator*=( BigInteger& A, const BigInteger& B ) {
    A = A.mult(B);
    return A;
}

