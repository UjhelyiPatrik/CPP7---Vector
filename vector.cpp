/**
 * @file vector.cpp
 * @brief vector class implementation.
 * @author
 * @date
 */

#include "vector.hpp"
#include <algorithm>

Vector::Vector(): pData(nullptr), elementNum(0) {}

Vector::Vector(const Vector& other) {

	*this = other;
}

Vector::~Vector() {
	delete[]pData;
}

Vector& Vector::operator= (const Vector& other) {

	if (this != &other) {
		elementNum = other.elementNum;
		pData = new int[elementNum];

		for (int i = 0; i < elementNum; i++) {
			this->pData[i] = other.pData[i];
		}
	}

	return *this;
}

int& Vector::operator[](unsigned int position) {
	try
	{
		if (position < elementNum) {
			return pData[position];
		}
		else {
			throw position;
		}
	}
	catch (int triedPosition)
	{
		std::cout << "The max position in the vector is " << elementNum << "! (You tried to reach element " << triedPosition << ")";
	}
}

const int& Vector::operator[](unsigned int position) const {
	try
	{
		if (position < elementNum) {
			return pData[position];
		}
		else {
			throw position;
		}
	}
	catch (int triedPosition)
	{
		std::cout << "The max position in the vector is " << elementNum << "! (You tried to reach element " << triedPosition << ")";
	}
}

int Vector::size() const {
	return elementNum;
}

void Vector::clear() {
	delete[]pData;
	elementNum = 0;
}

bool Vector::insert(unsigned int position, int element) {
	if (position < elementNum) {
		int* tmp = new int[elementNum + 1];

		int j = 0;
		for (int i = 0; i < elementNum; i++) {
			if (j == position) {
				tmp[j] = element;
				i--;
			}
			else {
				tmp[j] = pData[i];
			}

			j++;
		}

		delete[]pData;

		elementNum++;

		pData = tmp;
	}
	else {
		int *tmp = new int[position+1];

		for (int i = 0; i < elementNum; i++) {
			tmp[i] = pData[i];
		}

		delete[]pData;

		for (int i = elementNum; i < position; i++) {
			tmp[i] = 0;
		}

		tmp[position] = element;

		elementNum = position+1;

		pData = tmp;
	}

	return true;
}

int& Vector::at(unsigned int position) {

	try {

		if (position >= elementNum) {
			throw std::exception("Out of range!");
		}
		else {
			return pData[position];
		}

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << " Returned position 0 intead\n";
		return pData[0];
	}
}

const int& Vector::at(unsigned int position) const {
	
	try {

		if (position >= elementNum) {
			throw std::exception("Out of range!");
		}
		else {
			return pData[position];
		}

	}
	catch (const std::exception& ex)
	{
			std::cout << ex.what() << " Returned position 0 intead\n";
			return pData[0];
	}
}

bool Vector::erase(unsigned int position) {

	try {

		if (position >= elementNum) {
			throw std::exception("Out of range!");
		}
		else {

			int* tmp = new int[elementNum - 1];

			int j = 0;
			for (int i = 0; i < elementNum; i++) {
				if(i==position){
					i++;
					
				}
				tmp[j] = pData[i];
				j++;
			}

			delete[]pData;

			elementNum--;

			pData = tmp;
			return true;
		}

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << " Returned position 0 intead\n";
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, const Vector& value) {
	for (int i = 0; i < value.elementNum; i++) {
		os << value[i] << " ";
	}

	return os;
}

void sort(Vector& value) {
	std::sort(value.pData, value.pData+value.elementNum, [](int a, int b) {return a < b; });
}