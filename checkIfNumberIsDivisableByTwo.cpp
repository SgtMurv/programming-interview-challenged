#include <iostream>

using namespace std;

bool isEven(int number){
	int remainder = number % 2;
	if(remainder > 0) return false;
	else return true;
}

int main(){
	int number = 77;
	bool result = isEven(number);
	if(result == true){
		cout << number <<   "  -> is dividable by two :)" << endl;
	}
	else{
		cout << number <<   "  -> is not divisable by two >:(" << endl;
	}
	return 0;
}