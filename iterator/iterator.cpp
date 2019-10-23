#include <iostream>
#include <vector>

#define MAX 100

/* abstract class */
class Iterator {
public:
	~Iterator(){}
	virtual void next()=0;
	virtual int hasNext()=0;
};

class Aggregate: public Iterator {
public:
	~Aggregate(){}
	virtual Iterator *createIterator()=0;
};

class Menu {
public:
	std::string getMenu() { return str; }
	void setMenu(std::string input) { str = input; }
private:
	std::string str;
};

/* class prototype */
class MenuIterator;

class MenuBook: public Aggregate {
public:
	MenuBook(int a):max(a){ list.resize(max); }
	int getSize() {
		return max;
	}
	void attach(Menu *obj) {
		list.push_back(obj);
	}
	MenuBook* createIterator() {
		return new MenuIterator(*this);
	}
private:
	unsigned int max;
	std::vector<Menu*> list;
};

class MenuIterator: public Iterator {
public:
	MeunIterator(MenuBook b):Book(b){}
	void next() { index++; }
	int hasNext() { return index + 1 > max ? 0 : 1; }
private:
	MenuBook Book;
	unsigned int index;
};

int main()
{

	return 0;
}
