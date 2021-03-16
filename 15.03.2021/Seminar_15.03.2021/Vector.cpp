#include "Vector.h"
using namespace std;

//Constructors and destructors
Vector::Vector()
{
	size = 1;
	arr = new(nothrow) int[size];
	if (!arr) {
		cerr << "Memory not allocated" << endl;
		return;										//???? what should I return here;
	}
}

Vector::Vector(size_t size)
{
	this->size = size;
	arr = new(nothrow) int[this->size];
	if (!arr) {
		cerr << "Memory not allocated" << endl;
		return;										//???? what should I return here;
	}
}

Vector::Vector(const Vector& obj)
{
	size = obj.getSize();
	for (size_t i = 0; i < getSize(); i++)
		this[i] = obj[i];
}

Vector& Vector::operator=(const Vector& obj)
{
	if (this != &obj) {
		size = obj.getSize();
		for (size_t i = 0; i < getSize(); i++)
			this[i] = obj[i];
	}
	return *this;
}

Vector::~Vector()
{
	delete[] arr;
}

//Operators

Vector Vector::operator+(Vector const& obj)
{
	if (getSize() != obj.getSize()) {
		cerr << "The sizes of the two vectors must be the same." << endl;
		return;										//???? what should I return here;
	}
	Vector result(*this);
	result += obj;
	return result;
}

Vector& Vector::operator+=(Vector const& obj)
{
	if (getSize() != obj.getSize()) {
		cerr << "The sizes of the two vectors must be the same." << endl;
		return;										//???? what should I return here;
	}
	for (size_t i = 0; i < getSize(); i++)
		arr[i] += obj.arr[i];
	return *this;
}

const int& Vector::operator[](size_t index) const
{
	if (index >= getSize()) {
		cerr << "Index is out of bounds." << endl;
		return;										//???? what should I return here;;
	}
	return arr[index];
}

int& Vector::operator[](size_t index)
{
	if (index >= getSize()) {
		cerr << "Index is out of bounds." << endl;
		return;										//???? what should I return here;;
	}
	return arr[index];
}

bool Vector::operator==(Vector const& obj)
{
	if (getSize() != obj.getSize())
		return false;
	for (size_t i = 0; i < getSize(); i++)
		if (arr[i] != obj[i])
			return false;
	return true;
}

//Setters and getters
size_t Vector::getSize() const
{
	return size;
}

void Vector::putValue(size_t position, int el)
{
	if (position >= getSize()) {
		cerr << "Position is out of bounds." << endl;
		return;										//???? what should I return here;;
	}
	arr[position] = el; 
}

int Vector::getValue(size_t position) const
{
	if (position >= getSize()) {
		cerr << "Position is out of bounds." << endl;
		return;										//???? what should I return here;
	}
	return arr[position];
}

void Vector::add(const Vector& obj)
{
	if (getSize() != obj.getSize()) {
		cerr << "The sizes of the two vectors must be the same." << endl;
		return;										//???? what should I return here;
	}
	for (size_t i = 0; i < getSize(); i++)
		arr[i] += obj.arr[i];
}