#include <iostream>

class Singleton {
public:
	static Singleton* createInstance() {
		static Singleton singleton;
		return &singleton;
	}
	void setVal(int a) {
		val = a;
	}
	int getVal() {
		return val;
	}

private:
	Singleton() {}
	int val;
};

int main()
{
	Singleton *obj1 = Singleton::createInstance();
	Singleton *obj2 = Singleton::createInstance();

	obj2->setVal(100);
	std::cout << "obj1: " << obj1->getVal() << std::endl;
	std::cout << "obj2: " << obj2->getVal() << std::endl;

	obj1->setVal(-5);
	std::cout << "obj1: " << obj1->getVal() << std::endl;
	std::cout << "obj2: " << obj2->getVal() << std::endl;

	return 0;
}
