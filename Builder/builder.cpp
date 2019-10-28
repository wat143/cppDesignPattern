#include <iostream>

class Builder {
public:
	~Builder(){}
	virtual void fry()=0;
	virtual void stew()=0;
};

class ChickenCurry: public Builder {
public:
	void fry() {
		std::cout << "Fry Chicken" << std::endl;
	}
	void stew() {
		std::cout << "Stew Chicken and Vegetables with Curry Spice" << std::endl;
	}
};

class MisoSoupe: public Builder {
public:
	void fry() {
		std::cout << "Fry is not necessar" << std::endl;
	}
	void stew() {
		std::cout << "Stew Vegetables with Miso" << std::endl;
	}
};

class Director {
public:
	void execute(){
		builder->fry();
		builder->stew();
	};
	void setBuilder(Builder *b) {
		builder = b;
	}
	void unsetBuilder() {
		builder = NULL;
	}
private:
	Builder *builder;
};

int main()
{
	Builder *builder = new ChickenCurry;
	Director director;

	/* Chicken Curry Builder */
	director.setBuilder(builder);
	director.execute();
	director.unsetBuilder();
	delete builder;

	/* Miso Soupe Builder */
	builder = new MisoSoupe;
	director.setBuilder(builder);
	director.execute();
	director.unsetBuilder();
	delete builder;

	return 0;
}
