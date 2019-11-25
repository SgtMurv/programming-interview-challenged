#include <iostream>
using namespace std;

void fizzBuzz(){
	string toPrint = "";
	for(int i =1; i< 100; i++){
		int fiveRemainder = i % 5;
		int threeRemainder = i %3;
		if(threeRemainder == 0){
			toPrint = "Baddabing !";
		}
		if(fiveRemainder == 0){
			toPrint = "Baddaboom!";
		}
		if(threeRemainder == 0 && fiveRemainder == 0){
			toPrint = "Dip ..";
		}
		if(toPrint == ""){
			cout << i << endl;
		}
		else{
			cout << toPrint << endl;
		}
		toPrint = "";
	}
}

int main(){
	fizzBuzz();
	return 0;
}