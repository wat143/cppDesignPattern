#include <iostream>
#include <vector>

class Base {
public:
	virtual int cost()=0;
};

/* drink class */
class Coffee : public Base
{
public:
	Coffee():val(400) {}
	int cost() { return val; }
private:
	int val;
};

class Late : public Base
{
public:
	Late():val(450) {}
	int cost() { return val; }
private:
	int val;
};

/* base class of toppings */
class Topping : public Base
{
public:
	Topping(Base *b):base(b) {}
	Base *base;
};

class Soy : public Topping {
public:
	Soy(Base *b):Topping(b), val(50) {}
	int cost() { return base->cost() + val; }
private:
	int val;
};

class Whip : public Topping {
public:
	Whip(Base *b):Topping(b), val(70) {}
	int cost() { return base->cost() + val; }
private:
	int val;
};

int main()
{
	Late *late = new Late;
	Whip *whip = new Whip(late);
	Soy *soy = new Soy(whip);

	std::cout << soy->cost() << std::endl;


	return 0;
}
