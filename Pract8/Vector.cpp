#include "Vector.h"

template<typename T>
Vector<T>::Vector() {
}

template<typename T>
Vector<T>::Vector(size_t n) {
}

template<typename T>
Vector<T>::Vector(size_t n, const T &object) {
}

template<typename T>
int Vector<T>::getSize() {
}

template<typename T>
int Vector<T>::getCapacity() {
}

template<typename T>
void Vector<T>::push_back(const T &obj) {
}

template<typename T>
void Vector<T>::push_back(T &&obj) {
}

template<typename T>
void Vector<T>::pop_back() {
}

template<typename T>
void Vector<T>::insert(size_t idx, const T &obj) {
}

template<typename T>
void Vector<T>::insert(size_t idx, T &&obj) {
}

template<typename T>
void Vector<T>::erase(size_t idx) {
}

template<typename T>
T & Vector<T>::begin() {
}

template<typename T>
const T & Vector<T>::begin() const {
}

template<typename T>
T & Vector<T>::end() {
}

template<typename T>
const T & Vector<T>::end() const {
}

template<typename T>
T & Vector<T>::operator[](size_t idx) {
}

template<typename T>
void Vector<T>::shrink_to_fit() {
}

template<typename T>
bool Vector<T>::empty() const {
}

template<typename T>
void Vector<T>::clear() {
}
