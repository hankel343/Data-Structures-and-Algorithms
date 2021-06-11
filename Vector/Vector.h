#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using std::cout; using std::endl;
class EmptyVectorException {};
class OutOfBoundsIndexException {};

class Vector {
private:
	int m_size;
	int m_capacity;
	int* items;

	/* Private Methods */
	void resize(int newCapacity);
	//When capacity is reached, double the size of the array.
	//If an item is popped and size is 1/4 of capacity, then resize to half.

	bool isFull();

public:
	//constructor
	Vector(); //done
	Vector(int capacity); //done
	int size(); //done
	int capacity(); //done
	bool empty(); //done
	int at(int index); //done
	void push(int newItem); //done
	void insert(int index, int item); //TO DO
	void prepend(int item); //TO DO
	int pop_back(); //remove from end, return value //done
	void deleteIndex(int index); //delete item at given index, shift all elements to left //TODO
	void remove(int item); //looks for value and removes index holding it //TODO
	int find(int item); //looks for value and returns first index with that value //TODO

	//[] operator overload
	int& operator[](int index);

	//Destructor:
	~Vector();
};

#endif
