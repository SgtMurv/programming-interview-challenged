#include <iostream>
using namespace std;

int fib(int n){
	if (n <2){
		return n;
	}
	return fib(n-2) + fib(n-1);
}

int main(){
	cout << fib(6);
	return 0;
}