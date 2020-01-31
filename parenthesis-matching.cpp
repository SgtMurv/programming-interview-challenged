#include <iostream>
#include <vector>
using namespace std;

void findOpeningParenthesis(vector<int>& openingParenthesis,string sentence){
	// loop through the string and record the indexes where a parenthesis pair has been opened.
	for(int i = 0; i < sentence.size(); i++){
		if(sentence[i] == '('){
			openingParenthesis.push_back(i);
			cout << i << ", ";
		}
	}
	cout << endl;
}

int findMatchingParenthesis(std::string sentence, int index,int numberOfClosingParenthesisToIgnore){
	int rightIndex = 0;
	// need to look through each character in the string and then look for a ')'
	for(rightIndex = index+1; rightIndex < sentence.size(); rightIndex++){
		// cout << sentence[rightIndex] << " ";
		if(sentence[rightIndex] == ')'){
			// now we need to check if we need to ignore any of the closing parenthesis
			if(numberOfClosingParenthesisToIgnore > 0){
				// if we need to ignore a closing parenthesis then we need to decrement the number to ignore so we dont ignore too many closing ones
				numberOfClosingParenthesisToIgnore--;
			}
			else {
				// if we don't need to ignore any parenthesis then we need to break out the loop
				return rightIndex;
			}
		}
	}
	return -1;
}

int main(){
	string string1 = "When opening a door (for some reason (it could be any (real or imaginary) reason)) holdtight.";
	string string2 = "((())";
	vector<int> openingParenthesis;
	findOpeningParenthesis(openingParenthesis, string2);
	for(int i =0; i < openingParenthesis.size();i++){
		int endIndex = findMatchingParenthesis(string2, openingParenthesis[i], openingParenthesis.size()-(i+1));
		cout << endIndex << ", ";
	}
	return 0;
}