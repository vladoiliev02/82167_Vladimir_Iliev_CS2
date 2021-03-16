#pragma once
#include <iostream>

class Vector {
private:
	size_t size;
	int* arr;

public: //Constructors and destructor
	Vector();
	Vector(size_t size);
	Vector(const Vector& obj);
	~Vector();

public: //Operators
	Vector& operator=(const Vector& obj);
	Vector operator+(Vector const& obj);
	Vector operator*(int mult); //To be implemented
	Vector& operator+=(Vector const& obj);
	Vector operator*=(int mult); //To be implemented
	bool operator==(Vector const& obj);
	const int& operator[](size_t index) const;
	int& operator[](size_t index);

public: //Getters
	size_t getSize() const;

public: //Methods
	void putValue(size_t position, int el);
	int getValue(size_t position) const;
	void add(const Vector& obj);
};