/***********************************************
* Mika Peer Shalem, mpeersha
* 2023 Winter CSE101 PA6
* Arithmetic.cpp
* Contains a main function that performs operations on two BigInteger lists
***********************************************/
#include "BigInteger.h"
#include<iostream>
#include <fstream>
#include<string>
using namespace std;
int main(int argc, char * argv[]) {
	ifstream in;
	ofstream out;
	// Check that there are two command line arguments
	// argc = argument count. Stores num of args including program name
	if (argc!=3) {
		cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
		return (EXIT_FAILURE);
	}
	// Open input file
	in.open(argv[1]);
	if (!in.is_open()) {
		cerr << "Unable to open file " << argv[1] << " for reading" << endl;
		return (EXIT_FAILURE);
	}
	// Open output file
	out.open(argv[2]);
	if (!out.is_open()) {
		cerr << "Unable to open file " << argv[2] << " for reading" << endl;
		return (EXIT_FAILURE);
	}
	
	// Creates the Big Integers based on in file
	string line;
	BigInteger A; BigInteger B;
	if(getline(in, line)) {
		A = BigInteger(line);
	}
	getline(in, line);
	if(getline(in, line)) {
		B = BigInteger(line);
	}
	// BigInteger two = BigInteger("2");
	// BigInteger three = BigInteger("3");
	// BigInteger four = BigInteger("4");
	// BigInteger five = BigInteger("5");
	BigInteger nine = BigInteger("9");
	BigInteger sixteen = BigInteger("16");
	out << A.to_string() << "\n" << endl;
    out << B.to_string() << "\n" << endl;
	// Operations
	out << (A+B).to_string() << "\n" << endl;
	out << (A-B).to_string() << "\n" << endl;
	out << (A-A).to_string() << "\n" << endl;
	// out << "3A: " << (three*A).to_string() << "\n" << endl;
	// out << "2B: " << (two*B).to_string() << "\n" << endl;
	out << ((A+A+A) - (B+B)).to_string() << "\n" << endl;
	out << (A*B).to_string() << "\n" << endl;
	BigInteger ASquare = A*A;
	out << (ASquare).to_string() << "\n" << endl;
	BigInteger BSquare = B*B;
	out << (BSquare).to_string() << "\n" << endl;
	out << ((nine*ASquare*ASquare)+(sixteen*BSquare*BSquare*B)).to_string() << "\n" << endl;
	
	// Close files
	in.close();
	out.close();
	return (EXIT_SUCCESS);
}
