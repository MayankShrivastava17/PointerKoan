//============================================================================
// Name        : PointerKata.cpp
// Author      : Eric Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

unsigned char *setupBuffer()
{
	const int BUFFER_SIZE = 255;

	// Start with operations on an unsigned char - where a char is 1 byte
	unsigned char *p = new unsigned char[BUFFER_SIZE];
	for(int i = 0; i < BUFFER_SIZE; i++)
	{
		p[i] = i;
	}

	return p;
}

int main() {
	cout << "This is the C++ pointer kata." << endl; // prints !!!Hello World!!!
	cout << "Meant to practice pointer arithmetic" << endl;
	cout << "It simply uses assert on a known data structure, and you fill in the rest" << endl;
	unsigned char *originalPointer = setupBuffer();
	unsigned char *p = originalPointer;

	assert(p[0] == 0);
	assert(*p == 0);

	p = p + 3;
	assert(*p == 0);

	unsigned char a = *p++;
	assert(a == 0);
	assert(*p == 0);

	unsigned char b = *(p++);
	assert(b == 0);
	assert(*p == 0);

	// Would love to deal with the 'endianness' of the memory.
	// Not sure I can
	unsigned char c = *++p;
	assert(c == 0);
	assert(*p == 0);

	// Sure you can - cast and display the hex value
	// but how would you simulate the memory?
	unsigned char *np = p + 3;
	assert(*np == 0);
	assert(*p == 0);

	//Let's setup an int pointer
	unsigned int *intP = (unsigned int*) originalPointer;

	// Hint remember your processors Endianness
	// Also you should probably do these as hex
	assert(*intP == 0x00000000);

	intP = intP + 3;
	assert(*intP == 0x00000000);

	intP = (unsigned int *)((unsigned char *) (intP) + 3);
	assert(*intP == 0x00000000);

	unsigned int intX = *intP--;
	assert(intX == 0x00000000);
	assert(*intP == 0x00000000);

	unsigned int *subtractedP = intP - 1;
	assert(*subtractedP == 0x00000000);
	assert(intP - subtractedP == 0);

	// Obscure C trick
	//assert(*(4[intP]) == 0x1211100F);

	cout << "Congrats you did it!  You must know your pointers" << endl;
	return 0;
}