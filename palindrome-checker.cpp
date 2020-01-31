#include <iostream>

using namespace std;
// TODO: Make the word lowercase so that it works in all situations 
bool doesContainPalindrome(char word[], int size){
	for(int i =  0; i< size; i++){
		char leftLetter = word[i];
		char rightLetter = word[(size-1)-i];
		if (leftLetter!= rightLetter){
			return false;
		}
		// palindromes are symetrical so you don't need to loop through the entire word
		if(i > size/2)break;
	}
	return true;
}

int main(){
	char word[] =  "racecar";
	bool result = doesContainPalindrome(word, sizeof(word)-1);
	if(result == true){
		cout << word <<   "  -> Is a Palindrome :)" << endl;
	}
	else{
		cout << word <<   "  -> Is NOT a Palindrome >:(" << endl;
	}
	return 0;
}