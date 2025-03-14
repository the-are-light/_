#include "line.h"

Line::Line(int startCapacity)
{
	if (startCapacity <= 0)
		capacity = DEFAULT_CAPACITY;
	else
		capacity = startCapacity;
	ptr = new int[capacity];
	size = 0;
}

Line::~Line()
{
	delete[] ptr;
}

Line::Line(const Line &line)
{
	ptr = new int[line.capacity];
	size = line.size;
	capacity = line.capacity;

	for (int i = 0; i < size; i++)
		ptr[i] = line.ptr[i];
}

Line& Line::operator =(const Line& line)
{
	if (this == &line)
		return *this;
	if (capacity != line.capacity)
	{
		delete[] ptr;
		ptr = new int[line.capacity];
		capacity = line.capacity;
	}
	size = line.size;
	for (int i = 0; i < size; i++)
		ptr[i] = line.ptr[i];
	return *this;
}

int& Line::operator[] (int index)
{
	if (index >= size || index < 0)
		throw LineException();
	else
		return ptr[index];
}

void Line::insert(int elem, int index)
{
	if (index < 0 || index > size)
		throw LineException();
	if (size == capacity)
		increaseCapacity(size + 1);

	for (int j = size - 1; j >= index; j--)
		ptr[j + 1] = ptr[j];

	size++;
	ptr[index] = elem;
}

void Line::insert(int elem)
{
	insert(elem, size);
}

void Line::increaseCapacity(int newCapacity) {
	capacity = newCapacity < capacity * 2 ? capacity * 2 : newCapacity;
	int* newPtr = new int[capacity];
	for (int i = 0; i < size; i++)
		newPtr[i] = ptr[i];
	delete[] ptr;
	ptr = newPtr;
}

void Line::remove(int index)
{
	if (index < 0 || index > size)
		throw LineException();
	for (int j = index; j < size - 1; j++)
		ptr[j] = ptr[j + 1];
	
	ptr[size - 1] = 0; 
	size--;
}

int Line::getSize() const
{
	return size;
}

ostream& operator <<(ostream& out, const Line& line)
{
	out << "Total size: " << line.size << endl;
	for (int i = 0; i < line.size; i++)
	{
		out << line.ptr[i] << " ";
	}
	out << endl;
	return out;
}