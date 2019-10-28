#include <iostream>
#include <vector>

/**
 *@brief  Menu class
 */
class Menu {
public:
	void setName(std::string s) { str = s; }
	std::string getName() { return str; }
private:
	std::string str;
};

/**
 *@brief  abstract class of Iterator 
 */
class Iterator {
public:
	~Iterator(){}
	virtual Menu next()=0;
	virtual int hasNext()=0;
};

/**
 *@brief  abstract class of Aggregate
 */
class Aggregate {
public:
	~Aggregate(){}
	virtual Iterator* createIterator()=0;
};

/**
 *@brief  MenuBook class
 */
class MenuBook: public Aggregate {
public:
	MenuBook(int max): num(0) { list.resize(max); }
	int getNumMenu() { return num; }
	void attach(Menu m) { list[num++] = m; }
	Menu getMenuByIndex(int index){ return list[index]; }
	Iterator* createIterator();
private:
	std::vector<Menu> list;
	int num;
};

/**
 *@brief  MenuIterator class
 */
class MenuBookIterator :public Iterator {
public:
	MenuBookIterator(MenuBook m): book(m), index(0) {}
	Menu next() { return book.getMenuByIndex(index++); }
	int hasNext() { return index < book.getNumMenu(); }
private:
	MenuBook book;
	int index;
};

Iterator* MenuBook::createIterator() { return new MenuBookIterator(*this); }

int main()
{
	Menu a, b, c, d;
	MenuBook book(5);

	a.setName("Curry");
	b.setName("Ramen");
	c.setName("Sushi");
	d.setName("Pizza");
	book.attach(a);
	book.attach(b);
	book.attach(c);
	book.attach(d);

	Iterator *itr = book.createIterator();

	while(itr->hasNext())
	{
		Menu tmp = itr->next();
		std::cout << tmp.getName() << std::endl;
	}

	return 0;
}
