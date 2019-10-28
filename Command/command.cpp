#include <iostream>
#include <vector>
#include <string>

class Command {
public:
	Command(std::string s, int a):num(a), cmd(s) {}
	int num;
	std::string cmd;
};

class CalcModule {
public:
	CalcModule() : result(0) {}
	void initResult() { result = 0; }
	void calc(Command a) {
		if (a.cmd == "+")
			result += a.num;
		else if (a.cmd == "-")
			result -= a.num;
		else if (a.cmd == "/")
			result /= a.num;
		else if (a.cmd == "*")
			result *= a.num;
		else if (a.cmd == "%")
			result %= a.num;
		else if (a.cmd == "&")
			result &= a.num;
		else if (a.cmd == "|")
			result |= a.num;
		else
			;
	}
	void undo() {
		int size = cmdList.size();
		/* initialize reuslt */
		initResult();
		/* calculate all commands except for undone one */
		for (int i = 0; i < size - 1; i++)
			calc(cmdList[i]);

		/* pop last command */
		cmdList.pop_back();
	}
	void pushCmd(Command a) {
		cmdList.push_back(a);
		calc(a);
	}
	int getResult() { return result; }
private:
	int result;
	std::vector<Command> cmdList;
};

class Calculator : public CalcModule {
public:
	int getResult() { return CalcModule::getResult(); }
};

int main()
{
	Command a("+", 10);
	Command b("%", 3);
	Calculator cal;

	cal.pushCmd(a);
	cal.pushCmd(b);
	std::cout << cal.getResult() << std::endl;

	cal.undo();
	std::cout << cal.getResult() << std::endl;

	return 0;
}
