#include <iostream>

class BridgeImpl {
public:
	virtual void print()=0;
};

class B3Impl: public BridgeImpl {
public:
	void print() { std::cout << "B3 implementation" << std::endl; }
};

class F15Impl: public BridgeImpl {
public:
	void print() { std::cout << "F15 implementation" << std::endl; }
};

class Plane {
public:
	Plane(BridgeImpl *b):impl(b){}
	void Type() { std::cout << "Type:"; impl->print(); }
private:
	BridgeImpl *impl;
};

int main()
{
	BridgeImpl *impl = new B3Impl;
	BridgeImpl *impl_F15 = new F15Impl;
	Plane p(impl);
	Plane p2(impl_F15);

	p.Type();
	p2.Type();

	return 0;
}
