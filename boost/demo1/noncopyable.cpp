#include <boost/utility.hpp>
#include <iostream>

using namespace std;

class MyClass : public boost::noncopyable {
	public:
		MyClass();
		MyClass(int i) {}
};

int main()
{
	MyClass c1();
	MyClass c2();

	//MyClass c3(c1);
	//MyClass c3 = c1;


	return 0;
}
