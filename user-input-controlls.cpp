#include <iostream>
using namespace std;

class TextInput
{
public:
	TextInput() {}
};

class NumericInput : TextInput
{
public:
	NumericInput() {}
};

int main()
{
	TextInput *input = new NumericInput();
	input->add('1');
	input->add('a');
	input->add('0');
	std::cout << input->getValue();
	return 0;
}