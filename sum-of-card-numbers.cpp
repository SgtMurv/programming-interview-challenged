#include <iostream>
#include <vector>
#include <map>
using namespace std;

void initCardValuesMap(map<string, int> &cardValues)
{
	cardValues["1"] = 1;
	cardValues["2"] = 2;
	cardValues["3"] = 3;
	cardValues["4"] = 4;
	cardValues["5"] = 5;
	cardValues["6"] = 6;
	cardValues["7"] = 7;
	cardValues["8"] = 8;
	cardValues["9"] = 9;
	cardValues["10"] = 10;
	cardValues["J"] = 10;
	cardValues["Q"] = 10;
	cardValues["K"] = 10;
	cardValues["A"] = 11;
}

bool isOver21(vector<string> myHand)
{
	bool result = false;
	int totalValue = 0;
	map<string, int> cardValues;
	initCardValuesMap(cardValues);

	// add up all the values in the hand
	for (string card : myHand)
	{
		totalValue += cardValues[card];
	}
	// check if the total value is greater than or equal to 21
	if (totalValue >= 21)
	{
		result = true;
	}
	return result;
}

void printResult(bool result)
{
	if (result)
	{
		cout << "Yay! You got over 21!" << endl;
	}
	else
	{
		cout << "Nay! You got a value lower than 21!" << endl;
	}
}

int main()
{
	vector<string> myHand;
	myHand.push_back("10");
	myHand.push_back("2");
	myHand.push_back("10");
	printResult(isOver21(myHand));
	return 0;
}