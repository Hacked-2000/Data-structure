#include<iostream>
using namespace std;

class A
{
	public:
		A()
		{
			cout << "A is Constructed" << endl;
		}
};
class B
{
	static A a;
    public:
	  B()
	{
		cout << "B is Constructed" << endl;
	}	
};

int main()
{
	B b;
	return 0;
}
