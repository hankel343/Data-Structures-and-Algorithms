#include "Vector.h"
vector::vector()
	: m_size{ 0 }, m_capacity{ 5 }, items{ nullptr }
{
	items = new int[m_capacity] {0}; //Dynamically allocate array of default capacity
}

vector::vector(int capacity)
	: m_size{ 0 }, m_capacity{ capacity }, items{ nullptr }
{
	items = new int[capacity] {0}; //Dynamically allocating array of specified capacity 
}

int vector::size() {
	return m_size;
}

int vector::capacity() {
	return m_capacity;
}

bool vector::empty() {
	return m_size == 0;
}

int vector::at(int index) {
	if (index >= m_size) return -1;
	else return items[index];
}

int vector::pop_back() {
	if (m_size == 0) {
		throw EmptyVectorException();
	}
	else {
		int temp{ items[m_size - 1] };
		m_size--;
		return temp;
	}
}

void vector::deleteIndex(int index) {
	if (m_size == 0) throw EmptyVectorException();

	for (int i{ index }; i < m_size - 1; i++) {
		items[i] = items[i + 1];
	}
	m_size--;
}

void vector::push(int newItem) {
	if (m_size >= m_capacity) {
		resize(m_size * 2);
		items[m_size++] = newItem;
	}
	else {
		items[m_size++] = newItem;
	}
}

void vector::insert(int index, int item) {
	if (isFull()) return; //There is space for another element in the vector.

	if (index < m_size) { //index is within a valid range
		m_size++;
		for (int i{ m_size - 1 }; i > index; i--) {
			items[i] = items[i - 1];
		}
		items[index] = item;
	}
}

int& vector::operator[](int index) {
	if (index >= m_size) {
		throw OutOfBoundsIndexException();
	}
	else {
		return items[index];
	}
}

int vector::find(int item) {
	for (int i{ 0 }; i < m_size; i++) {
		if (item == items[i]) {
			return i; //returns index of the found item.
		}
	}
	return -1; //Item not found
}

/* Private Method */
void vector::resize(int newCapacity) {
	int* temp{ items }; //Temporary pointer on old array
	items = new int[newCapacity];

	//Copy elements from old array into new array
	for (int i{ 0 }; i < newCapacity; i++) {
		if (i < m_capacity) {
			items[i] = temp[i];
		}
		else {
			items[i] = 0;
		}
	}
	m_capacity = newCapacity; //Update capacity
	delete[] temp; //Release memory of old array
}

bool vector::isFull() {
	return (m_size == m_capacity);
}