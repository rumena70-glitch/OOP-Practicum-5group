#ifndef PRACT8_VECTOR_H
#define PRACT8_VECTOR_H
#include <iostream>


template <typename T> class Vector {
    size_t size = 0;
    size_t capacity = 0;
public:
    Vector();
    Vector(size_t n);
    Vector(size_t n, const T& object);
    int getSize();
    int getCapacity();
    void push_back(const T& obj);
    void push_back(T&& obj);
    void pop_back();
    void insert(size_t idx, const T& obj);
    void insert(size_t idx, T&& obj);
    void erase(size_t idx);
    T& begin();
    const T& begin() const;
    T& end();
    const T& end() const;
    T& operator[](size_t idx);
    void shrink_to_fit();
    bool empty() const;
    void clear();
};



#endif //PRACT8_VECTOR_H
