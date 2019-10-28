#include <iostream>

class SortParts {
public:
	template<typename T>
	void swap(T &a, T &b) {
		T tmp = a;
		a = b;
		b = tmp;
	}
};

class Sort {
public:
	void bubbleSort(int *arry, int num) {
		for (int i = 0; i < num; i++)
		{
			for (int j = num - 1; j >= i; j--)
			{
				if (arry[i] > arry[j])
					s.swap(arry[i], arry[j]);
			}
		}
	}
private:
	SortParts s;
};

int main()
{
	int arry[5] = {5, 4, 3, 2, 1};
	Sort s;

	for (int i = 0; i < 5; i++)
		std::cout << arry[i] << " ";
	std::cout << std::endl;

	s.bubbleSort(arry, 5);

	for (int i = 0; i < 5; i++)
		std::cout << arry[i] << " ";
	std::cout << std::endl;

	return 0;
}
