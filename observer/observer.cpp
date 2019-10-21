#include <iostream>
#include <vector>

class Subscriber;

class Observer {
public:
	~Observer() {}
	virtual void update(Subscriber*)=0;
};

class Subscriber {
public:
	~Subscriber(){}
	void attach(Observer *obj) {
		list.push_back(obj);
	}
	void notify() {
		int numObj = list.size();
		for (int i = 0; i < numObj; i++)
			list[i]->update(this);
	}
	//void detach() {}
	virtual int getVal(int a)=0;

private:
	std::vector<Observer*> list;
};

class DegitalClock : public Observer {
public:
	DegitalClock():h(0), m(0), s(0) {}
	~DegitalClock() {};
	void update(Subscriber *sub) {
		h = sub->getVal(0);
		m = sub->getVal(1);
		s = sub->getVal(2);
	}
	void show() {
		std::cout << "Degital Clock "<< h << ":" << m << ":" << s << std::endl;
	}

private:
	int h;
	int m;
	int s;
};

class Clock : public Observer {
public:
	Clock():h(8), m(10), s(49) {}
	~Clock() {};
	void update(Subscriber *sub) {
		h = sub->getVal(0);
		m = sub->getVal(1);
		s = sub->getVal(2);
	}
	void show() {
		std::cout << "Clock " << h << ":" << m << ":" << s << std::endl;
	}

private:
	int h;
	int m;
	int s;
};

class ClockTimer : public Subscriber {
public:
	~ClockTimer() {};
	int getVal(int a) {
		switch (a) {
		case 0:
			return hour;
		case 1:
			return min;
		case 2:
			return sec;
		}
	}
	void setTime(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
		notify();
	}

private:
	int hour;
	int min;
	int sec;
};

int main()
{
	ClockTimer timer;
	Clock clock;
	DegitalClock d_clock;

	clock.show();
	d_clock.show();

	timer.attach(&d_clock);
	timer.attach(&clock);

	timer.setTime(15, 14, 10);
	clock.show();
	d_clock.show();

	return 0;
}
