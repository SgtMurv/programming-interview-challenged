#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

class Denomination{
public:
	float value;
	int count;
	Denomination(float value) : value(value), count(0){};
};


class DenominationSplitter{
private:
	vector<Denomination> denominations;
public:
	void addDenomination(Denomination d);
	void printDenominations();
	void printLeastDenominations(float amount);
	void checkResult(float amount);
};

void DenominationSplitter::addDenomination(Denomination d){
	this->denominations.push_back(d);
}

void DenominationSplitter::printDenominations(){
	for(int i =0; i < denominations.size();i++){
		cout << denominations[i].value << endl;
	}
}

void DenominationSplitter::printLeastDenominations(float amount){
	cout << "The value for counting is £" << amount << endl;
	cout << "----------------------------------" << endl;
	for(int i =0; i < denominations.size(); i++){
		float amountCopy = amount;
		// Figure out the number of times the denomination is present in the amount.
		while(amountCopy >= 0){
			amountCopy -= denominations[i].value;
			denominations[i].count++;
			// Todo: round to 2 dp here so that the wierd float error does not occur
			printf("Pre Round: %f | ",amountCopy);
			amountCopy = ((int)(amountCopy * 100 + .5) / 100.0);
			printf("Post Round: %f\n",amountCopy);
		}
		// we are always going to go at least one over with the minus values so we decrement the count here
		denominations[i].count--;
		amount -= denominations[i].count * denominations[i].value;
		printf("Number of £%.2f's -> %i \n\n",denominations[i].value, denominations[i].count);
		// cout << "Number of £"<< to_string(denominations[i].value) << "'s -> " << denominations[i].count << endl;
	}
}

void DenominationSplitter::checkResult(float amount){
	float total = 0.0;
	// calculate the total from the denominations vector
	for(vector<Denomination>::iterator it = begin(denominations); it != end(denominations); ++it){
		total += it->value * it->count;
	}
	printf("The total is -> %.2f",total);
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
	ds.addDenomination(Denomination(0.02));
	ds.addDenomination(Denomination(0.01));

	// ds.printDenominations();

	ds.printLeastDenominations(11.42);
	ds.checkResult(1.42);

	
	return 0;
}