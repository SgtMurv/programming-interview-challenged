
#include <iostream>
#include <cstdlib>
#include <map>
#include <time.h>
using namespace std;

int randomNumber(int maxValue)
{
	return rand() % maxValue + 1;
}

int main()
{
	srand(time(NULL));

	int randNumber = randomNumber(60);
	cout << randNumber << endl;
	return 0;
}
