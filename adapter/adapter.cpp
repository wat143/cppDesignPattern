#include <iostream>

class Echo {
public:
	void echo(int a) { std::cout << a << std::endl; }
};

class Print {
public:
	void print(int a, int b) {
		for (int i = 0; i < b; i++)
			std::cout << a << " " << std::endl;
	}
};

class PrintAbstract : public Echo {
public:
	void echo(int a) {
		int b = 5;
		p.print(a, b);
	}
private:
	Print p;
};

int main()
{
	Print p;
	PrintAbstract pa;

	int a = 3, b = 5;

	std::cout << "===Class Print===" << std::endl;
	p.print(a, b);
	std::cout << "===Class PrintAbstract===" << std::endl;
	pa.echo(a);

	return 0;
}
