#include <iostream>

using namespace std;

int main (){
	int firstvalue, secondvalue;
	int * mypointer;
	// the '&' operator returns the memory address of the variable it is applied on
	// Therefore the pointer is set to the memory address of the firstvalue
	mypointer = &firstvalue;
	// mypointer is pointing to the memory address of the first value so we are setting the value stored at this memory address to be 10
	*mypointer = 10;
	// mypointer is now assigned to the secondvalue's memory address
	mypointer = &secondvalue;
	// the secondvalue's memory address is set the value of 20
	*mypointer = 20;
	cout << "firstvalue is " << firstvalue << '\n';
	cout << "secondvalue is " << secondvalue << '\n';
	return 0;
}