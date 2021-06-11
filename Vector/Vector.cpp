#include "Vector.h"

/* Private Methods */
void Vector::resize(int newCapacity) {
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

bool Vector::isFull() {
	return (m_size == m_capacity);
}

/* Public Methods */
Vector::Vector()
	: m_size{ 0 }, m_capacity{ 5 }, items{ nullptr }
{
	items = new int[m_capacity] {0}; //Dynamically allocate array of default capacity
}

Vector::Vector(int capacity)
	: m_size{ 0 }, m_capacity{ capacity }, items{ nullptr }
{
	items = new int[capacity] {0}; //Dynamically allocating array of specified capacity 
}

int Vector::size() {
	return m_size;
}

int Vector::capacity() {
	return m_capacity;
}

bool Vector::empty() {
	return m_size == 0;
}

int Vector::at(int index) {
	if (index >= m_size) return -1;
	else return items[index];
}

int Vector::pop_back() {
	if (m_size == 0) {
		throw EmptyVectorException();
	}
	else {
		int temp{ items[m_size - 1] };
		m_size--;

		//Check for resize if current size is atleast 1/4 of capacity
		if (m_size * 4 <= m_capacity) {
			resize(m_capacity / 2);
		}

		return temp;
	}
}

void Vector::deleteIndex(int index) {
	if (m_size == 0) throw EmptyVectorException();

	for (int i{ index }; i < m_size - 1; i++) {
		items[i] = items[i + 1];
	}
	m_size--;

	//Check for resize if current size is atleast 1/4 of capacity
	if (m_size * 4 <= m_capacity) {
		resize(m_capacity / 2);
	}
}

void Vector::remove(int item) {
	if (m_size == 0) return;

	bool found{ false };
	for (int i{ 0 }; i < m_size && !found; i++) {
		if (items[i] == item) {
			found = true;
			deleteIndex(i);
		}
	}
}

void Vector::push(int newItem) {
	if (m_size >= m_capacity) {
		resize(m_size * 2);
		items[m_size++] = newItem;
	}
	else {
		items[m_size++] = newItem;
	}
}

void Vector::insert(int index, int item) {
	if (isFull()) return; //There is space for another element in the Vector.

	if (index < m_size) { //index is within a valid range
		m_size++;
		for (int i{ m_size - 1 }; i > index; i--) {
			items[i] = items[i - 1];
		}
		items[index] = item;
	}
}

void Vector::prepend(int item) {
	if (isFull()) {
		resize(m_size * 2);
	}

	m_size++;
	for (int i{ m_size - 1 }; i > 0; i--) {
		items[i] = items[i - 1];
	}
	items[0] = item;
}

int& Vector::operator[](int index) {
	if (index >= m_size) {
		throw OutOfBoundsIndexException();
	}
	else {
		return items[index];
	}
}

int Vector::find(int item) {
	for (int i{ 0 }; i < m_size; i++) {
		if (item == items[i]) {
			return i; //returns index of the found item.
		}
	}
	return -1; //Item not found
}

//Destructor:
Vector::~Vector() {
	delete[] items;
}