#ifndef L2_OOP_VECTORINA_ITERATOR_H
#define L2_OOP_VECTORINA_ITERATOR_H

#include "vectorina.h"

template <typename T>
class vector_iterbase
{
public:
    explicit vector_iterbase(T *ptr);
    vector_iterbase(const vector_iterbase<T>& iter);
    
    virtual ~vector_iterbase();
    
    vector_iterbase<T>& operator=(const vector_iterbase<T>& iter);
    
    vector_iterbase<T>& operator++();
    vector_iterbase<T> operator++(int);
    
    vector_iterbase<T>& operator--();
    vector_iterbase<T> operator--(int);
    
    bool operator ==(const vector_iterbase& iter);
    bool operator !=(const vector_iterbase& iter);

protected:
    T* ptr = nullptr;
    
};

template <typename T>
vector_iterbase<T>::vector_iterbase(T *ptr) : ptr(ptr)
{}

template <typename T>
vector_iterbase<T>::vector_iterbase(const vector_iterbase<T>& iter)
{
    ptr = iter.ptr;
}

template <typename T>
vector_iterbase<T>::~vector_iterbase()
{
    ptr = nullptr;
}

template <typename T>
vector_iterbase<T>& vector_iterbase<T>::operator=(const vector_iterbase<T>& iter)
{
    if(this != &iter)
        ptr = iter.ptr;
    return *this;
}

template <typename T>
vector_iterbase<T>& vector_iterbase<T>::operator++()
{
    ++ptr;
    return *this;
}

template <typename T>
vector_iterbase<T> vector_iterbase<T>::operator++(int)
{
    vector_iterbase<T> tmp(*this);
    this->operator++();
    return tmp;
}

template <typename T>
vector_iterbase<T>& vector_iterbase<T>::operator--()
{
    --ptr;
    return *this;
}

template <typename T>
vector_iterbase<T> vector_iterbase<T>::operator--(int)
{
    vector_iterbase<T> tmp(*this);
    this->operator--();
    return tmp;
}

template <typename T>
bool vector_iterbase<T>::operator==(const vector_iterbase& iter)
{
    return ptr == iter.ptr;
}

template <typename T>
bool vector_iterbase<T>::operator!=(const vector_iterbase& iter)
{
    return ptr != iter.ptr;
}

#endif //L2_OOP_VECTORINA_ITERATOR_H
