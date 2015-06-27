//============================================================================
// Name        : MoT.cpp
// Author      : Steve Cirelli
// Version     :
// Copyright   : 
// Description : Mode of Transportaion
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class CTest{
public:
	CTest(){
		this->i = 0;
		this->isIt = false;
	}
	CTest( int in, bool b ){
		this->i = in;
		this->isIt = b;
	}
	CTest( CTest &t ){
		this->i = t.i;
		this->isIt = t.isIt;
		cout << "Copy constructor called." << endl;
	}

	const CTest& operator = (const CTest &t ){
		this->i = t.i;
		this->isIt = t.isIt;
		return *this;
	}

	string toString(){
		string rtn;
		stringstream sstm;
		sstm << "i= " << this->i << "\tisIt= " << this->isIt;
		rtn = sstm.str();
		return rtn;
	}

	int i;
	bool isIt;
};

CTest& passing( CTest t ){
	t.i=10;
	t.isIt = false;
	return t;
}

int main(void) {
	CTest f(5,false), k;

	cout << "\n\nBefore: " << endl;
	cout << "f: " << f.toString() << endl;
	cout << "k: " << k.toString() << endl;
	k = passing(f);
	cout << "\n\nAfter: " << endl;
	cout << "f: " << f.toString() << endl;
	cout << "k: " << k.toString() << endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}
