/**
 * @file vector.hpp
 * @brief Definition of class vector.
 * @author
 * @date
 * @note There is a standard version of the following vector class in C++ alerady implemented, named std::vector.
 *   The interface of std::vector is similar to the one below.
 *   For more information, see https://en.cppreference.com/w/cpp/container/vector
 */

#pragma once
#ifndef VECTOR_HPP
#define VECTOR_HPP

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

 /** A Vector class designed to store integers. */
class Vector
{
public:
    /** Default constructor for class vector.
     *  The original size of the vector is zero, no elements are stored in it.
     */
    Vector();

    /** Destructor for class vector. */
    ~Vector();

    /** Copy constructor.
     *
     * @param[in] other The vector whose data will be copied.
    */
    Vector(const Vector& other);

    /** Assignment operator.
     *
     * @param[in] other The vector whose data will be copied.
     * @return A reference to *this.
     */
    Vector& operator= (const Vector& other);

    /** Returns the number of stored elements in the vector. */
    int size() const;

    /** Deletes every element in the array and sets the number of stored elements to zero. */
    void clear();

    /** Inserts a new element in the vector on a specified position.
     *  If the size of the vector is smaller than the given position,
     *    the vector will be filled with zeros and the element will be inserted after the zeros.
     *
     * @param[in] position The position where the new element will be inserted.
     * @param[in] element The value of the new element to be inserted.
     * @return true, if the element was successfully inserted, false otherwise.
     */
    bool insert(unsigned int position, int element);

    /** Gets a reference to a given element in the vector.
     *  It is not needed to check if the positions is correct.
     *    Additional task (not neccessary): solve the error handling with try-catch and throw statements.
     *
     * @param[in] position The index of the element which will be returned.
     * @return A non-const reference to an element.
     */
    int& at(unsigned int position);

    /** Gets a reference to a given element in the vector.
     *  It is not needed to check if the positions is correct.
     *    Additional task (not neccessary): solve the error handling with try-catch and throw statements.
     *
     * @param[in] position The index of the element which will be returned.
     * @return A const reference to an element.
     */
    const int& at(unsigned int position) const;

    /** Gets a reference to a given element in the vector.
     *  It is not needed to check if the positions is correct.
     *    Additional task (not neccessary): solve the error handling with try-catch and throw statements.
     *
     * @param[in] position The index of the element which will be returned.
     * @return A non-const reference to an element.
     */
    int& operator[](unsigned int position);

    /** Gets a reference to a given element in the vector.
     *  It is not needed to check if the positions is correct.
     *    Additional task (not neccessary): solve the error handling with try-catch and throw statements.
     *
     * @param[in] position The index of the element which will be returned.
     * @return A const reference to an element.
     */
    const int& operator[](unsigned int position) const;

    /** Deletes a given element in the vector.
     *
     * @param[in] position The index of the element which will be deleted from the vector.
     * @return True, if the element was successfully deleted, false otherwise
     */
    bool erase(unsigned int position);

private:
    /** Stores the current number of elements in the vector. */
    unsigned int elementNum;

    /** The actual elements in the vector. */
    int* pData;
};

/** Prints the elements of the vector to 'os'
 *
 * @note The official vector implementation in std::vector does not contain a printing function,
 *   it is only neccessary for this task.
 *   Do not make this function a friend-function, use the member functions of class Vector.
 *
 * @param[in] os The stream to which to output will be written.
 * @param[in] value The vector which will be printed to 'os'.
 */
std::ostream& operator<<(std::ostream& os, const Vector& value);

/** Sorts the values in the vector in ascending values.
 *
 * @note This function is similar to the one defined in the algorithm std header.
 *   It is forbidden to make this function a friend function, use only the public member functions of the vector.
 *   For more information, see https://en.cppreference.com/w/cpp/algorithm/sort
 */
void sort(Vector& value);

#endif VECTOR_HPP