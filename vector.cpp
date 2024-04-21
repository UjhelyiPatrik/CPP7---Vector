/**
 * @file vector.cpp
 * @brief vector class implementation.
 * @author
 * @date
 */

#include "vector.hpp"

Vector::Vector(): pData(nullptr), elementNum(0) {}

Vector::Vector(const Vector& other) {

	elementNum = other.elementNum;
	pData = new int[elementNum];

	for (int i = 0; i < elementNum; i++){
		this->pData[i] = other.pData[i];
	}
}

Vector::~Vector() {
	delete[]pData;
}