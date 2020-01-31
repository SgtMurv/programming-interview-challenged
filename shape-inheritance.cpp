#include <iostream>
using namespace std;

struct Shape
{
	virtual Shape *duplicate()
	{
		cout << "SHAPE" << endl;
		return new Shape;
	}
	virtual ~Shape() {}
};

struct Box : public Shape
{
	Box *duplicate()
	{
		cout << "BOX" << endl;
		return new Box;
	}
	~Box()
	{
		cout << "Deleting a box" << endl;
	}
};

int main()
{
	Shape *s1 = new Box;
	// new box is returned from the duplicate method so 2 separate box objects now exist to be deleted.
	Shape *s2 = s1->duplicate();

	delete s1;
	delete s2;
	return 0;
}