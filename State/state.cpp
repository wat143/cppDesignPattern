#include <iostream>

class Context;


/**
 * @def Abbstraction class of state
 */
class State {
public:
	~State() {}
	virtual void printState(Context *c)=0;
};

/**
 * @def Third state class
 */
class ThirdState: public State {
public:
	void printState(Context *c) {
		std::cout << "Thirs State" << std::endl;
	}
};
/**
 * @def Second state class
 */
class SecondState: public State {
public:
	void printState(Context *c) {
		std::cout << "Second State" << std::endl;
		c->next(new ThirdState);
	}
};

/**
 * @def First state class
 */
class FirstState: public State {
public:
	void printState(Context *c) {
		std::cout << "First State" << std::endl;
		c->next(new SecondState);
	}
};

/**
 * @def Context class of state
 */
class Context {
public:
	Context() {
		s = new FirstState();
	}
	void printState() {
		s->printState(this);
	}
	void next(State *next) {
		delete s;
		s = next;
	}
private:
	State *s;
};

int main()
{
	Context c;
	c.printState();

	return 0;
}
