#include <iostream>

class Vehicle {
public:
	Vehicle(std::string s):name(s) {}
	std::string getName() { return name; }
	virtual void show() { std::cout << name << std::endl; }
private:
	std::string name;
};

class Sedan : public Vehicle {
public:
	Sedan(std::string s):Vehicle(s){}
	void show() {
		std::cout << "Sedan:";
		Vehicle::show();
	}
};

class SUV : public Vehicle {
public:
	SUV(std::string s):Vehicle(s) {}
	void show() {
		std::cout << "SUV:";
		Vehicle::show();
	}
};

class Factory {
public:
	Vehicle* create(int a, std::string str) {
		Vehicle *ret = createInstance(a, str);
		return ret;
	}
private:
	virtual Vehicle* createInstance(int a, std::string str)=0;
};

class VehicleFactory : public Factory {
public:
	Vehicle *createInstance(int a, std::string str) {
		switch (a) {
		case 0:
			return new Sedan(str);
		case 1:
			return new SUV(str);
		}
	}
};

int main()
{
	VehicleFactory factory;
	Vehicle *sedan = factory.create(0, "C-Class");
	Vehicle *SUV = factory.create(1, "CX-5");

	sedan->show();
	SUV->show();

	return 0;
}
