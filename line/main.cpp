
#include <iostream>
#include "locale.h"
#include "line.h"
#include <ctime>

using namespace std;

// задача Иосифа Флавия
int survivor(int n, int k);

int main()
{
	setlocale(LC_ALL, "russian");

	// for complete task
	Line n_num(7);
	int k = 2;
	n_num.insert(1000);
	cout << n_num;
	for (int i = 1; i < 7; i++)
	{
		if (i % 2 != 0)
			n_num.insert(n_num[i - 1] * 5);
		else
			n_num.insert(n_num[i - 1] * 10 / 5);
	}

	for (int i = 0; i < n_num.getSize(); i++)
	{
		clock_t start = clock();
		cout << "Вход: (" << n_num[i] << ", " << k << "), Выход: " << survivor(n_num[i], k) << " Time: ";
		clock_t end = clock();
		cout << double(end - start) / CLOCKS_PER_SEC;
		cout << endl;
	}

	// test my array
	Line line(4);
	for (int i = 0; i < 4; i++)
		line.insert(i + 1);
	cout << line << endl;
	for (int i = 0; i < 8; i += 2)
		line.insert(10 + i, i);
	cout << line << endl;
	for (int i = 1; i < 8; i += 2)
		line[i] = 20 + i;
	cout << line << endl;
	for (int i = 6; i >= 0; i -= 3)
		line.remove(i);
	cout << line << endl;

	return 0;
}

int survivor(int n, int k)
{
	Line line;

	for (int i = 1; i <= n; i++)
		line.insert(i);

	int index = 0;

	while (line.getSize() > 1)
	{
		index = (index + k - 1) % line.getSize();
		line.remove(index);
	}

	return line[0];

}
