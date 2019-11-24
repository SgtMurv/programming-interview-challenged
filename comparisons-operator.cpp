#include <iostream>

using namespace std;

int main(){
	string wordsToDisplay = "This text was assigned with the '=' operator";
	if(wordsToDisplay == wordsToDisplay){
		// The '==' is a comparisons operator where two values are compared
		cout << wordsToDisplay << endl;
	}
	return 0;
}