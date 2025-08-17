/*
STATIC CAST (during compilation)
int a = 42;
double b = a;
int d = static_cast<int>(b);

DYNAMIC CAST (during execution)
/!\ only for downcast with a virtual function /!\

REINTERPRET CAST
float a = 42.42
void *b = &a;
int * c = reinterpret_cast<int *>(b);
int & d = reinterpret_cast<int &>(b);

CONST CAST (not good to use)
int a = 42;
int const * b = &a;
int * c = const_cast<int *>(b);

TYPE CAST
class Foo
{
	public:
		Foo(float const v) : _v(v)

		float getV() {return this->_v;}

		operator float() {return this->_v;}
		operator int() {return static_const<int>(this->_v);}

	private:
		float _v;
};

Foo a(420.024f);
float b = a; //use operator float()
int c = a;   //use operator int()

cout << a.getV() << endl; =>420.024
cout << b << endl;		  =>420.024
cout << c << endl;		  =>420
*/
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "There should be one (and only one) argument." << std::endl;
		return 1;
	}
	std::string str = argv[1];
	ScalarConverter::convert(str);

	return 0;
}