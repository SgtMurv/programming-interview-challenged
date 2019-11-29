#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

class Denomination{
public:
	double value;
	int count;
	Denomination(double value) : value(value), count(0){};
};


class DenominationSplitter{
private:
	vector<Denomination> denominations;
public:
	void addDenomination(Denomination d);
	void printDenominations();
	void printLeastDenominations(double amount);
	double round(double number);
	void checkResult(double amount);
};

void DenominationSplitter::addDenomination(Denomination d){
	this->denominations.push_back(d);
}

void DenominationSplitter::printDenominations(){
	for(int i =0; i < denominations.size();i++){
		cout << denominations[i].value << endl;
	}
}

void DenominationSplitter::printLeastDenominations(double amount){
	cout << "The value for counting is £" << amount << endl;

	for(int i =0; i < denominations.size(); i++){
		double amountCopy = amount;
		// Figure out the number of times the denomination is present in the amount.
		while(amountCopy >= 0){
			amountCopy = round(amountCopy);
			amountCopy -= denominations[i].value;
			denominations[i].count++;
		}
		// we are always going to go at least one over with the minus values so we decrement the count here
		if(denominations[i].count != 0)denominations[i].count--;
		amount -= denominations[i].count * denominations[i].value;
		printf("Number of £%.2f's -> %i \n",denominations[i].value, denominations[i].count);
	}
}

double DenominationSplitter::round(double number){
	double value = (int)(number * 100 + .5);
	return (double)value / 100;
}

void DenominationSplitter::checkResult(double amount){
	double total = 0.0;
	// calculate the total from the denominations vector
	for(vector<Denomination>::iterator it = begin(denominations); it != end(denominations); ++it){
		total += it->value * it->count;
	}
	if(total == amount){
		cout << "CORRECT! The denomination counts add up! => " << total << endl;
	}
	else{
		cout << "WRONG! The counts don't add up! => " << total << endl;
	}
}

int main(){
	DenominationSplitter ds;
	ds.addDenomination(Denomination(50));
	ds.addDenomination(Denomination(20));
	ds.addDenomination(Denomination(10));
	ds.addDenomination(Denomination(5));
	ds.addDenomination(Denomination(2));
	ds.addDenomination(Denomination(1));
	ds.addDenomination(Denomination(0.5));
	ds.addDenomination(Denomination(0.2));
	ds.addDenomination(Denomination(0.1));
	ds.addDenomination(Denomination(0.05));
	ds.addDenomination(Denomination(0.02));
	ds.addDenomination(Denomination(0.01));

	// ds.printDenominations();

	ds.printLeastDenominations(68.02);
	ds.checkResult(68.02);
	return 0;
}