#ifndef L2_OOP_VECTORINA_ITER_H
#define L2_OOP_VECTORINA_ITER_H

#include "vectorina.h"

template <typename T>
class vectorina_iter : public vector_iterbase<T>
{
public:
    vectorina_iter() = delete;
    
    vectorina_iter(T *p);
    vectorina_iter(const vectorina_iter<T> &iter);
    
    T &
    operator*();
    T *
    operator->();
};

template <typename T>
class vectorina_iter_const : public vector_iterbase<T>
{
public:
    vectorina_iter_const() = delete;
    
    vectorina_iter_const(T *p);
    vectorina_iter_const(const vectorina_iter_const<T> &iter);
    
    const T& operator*() const;
    const T* operator->() const;
};

template <typename T>
vectorina_iter_const<T>::vectorina_iter_const(T *p) : vector_iterbase<T>(p)
{}

template <typename T>
vectorina_iter_const<T>::vectorina_iter_const(const vectorina_iter_const<T> &iter) :
        vector_iterbase<T>(iter.ptr)
{}

template <typename T>
const T &vectorina_iter_const<T>::operator*() const
{
    return *this->ptr;
}

template <typename T>
const T *vectorina_iter_const<T>::operator->() const
{
    return this->ptr;
}

template <typename T>
vectorina_iter<T>::vectorina_iter(const vectorina_iter<T>& iter) : vector_iterbase<T>(iter.ptr) {}

template <typename T>
vectorina_iter<T>::vectorina_iter(T* p) : vector_iterbase<T>(p) {}

template <typename T>
T &vectorina_iter<T>::operator*()
{
    return *(this->ptr);
}

template <typename T>
T *vectorina_iter<T>::operator->()
{
    return this->ptr;
}

#endif //L2_OOP_VECTORINA_ITER_H
