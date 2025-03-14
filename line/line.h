#ifndef _LINE_H_
#define _LINE_H_
#include <iostream>
using namespace std;

const int DEFAULT_CAPACITY = 10;

class LineException {};

class Line
{
	int* ptr;
	int size, capacity;
	void increaseCapacity(int newCapacity);
public:
	int& operator[] (int index);
	void insert(int elem, int index);
	void insert(int elem);
	void remove(int index);

	explicit Line(int startCapacity= DEFAULT_CAPACITY);
	~Line();
	Line(const Line& line);
	Line& operator =(const Line& line);

	int getSize() const;
	friend ostream& operator <<(ostream& out, const Line& line);
};

#endif