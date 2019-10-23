#include <iostream>

class IG {
public:
	void VoltageOn() { std::cout << "Voltage On" << std::endl; }
	void SupplyOil() { std::cout << "Supply Oil" << std::endl; }
	void Ignittion() { std::cout << "Ignition on" << std::endl; }
};

class Display {
public:
	void DisplayOn() { std::cout << "IVI-Display On" << std::endl; }
	void IVISystemStart() { std::cout << "IVI system start" << std::endl; }
};


class Facade {
public:
	void StartVehicle() {
		ig.Ignittion();
		ig.VoltageOn();
		ig.SupplyOil();
		disp.DisplayOn();
		disp.IVISystemStart();
	}

private:
	IG ig;
	Display disp;
};

int main()
{
	Facade facade;
	facade.StartVehicle();

	return 0;
}
