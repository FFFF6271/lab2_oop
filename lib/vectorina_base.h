#ifndef L2_OOP_VECTORINA_BASE_H
#define L2_OOP_VECTORINA_BASE_H

#include "vectorina.h"

class vectorina_main
{
public:
    vectorina_main(size_t size) : size(size)
    {};
    
    inline size_t get_size();

protected:
    size_t size;
};

template <typename T>
class vectorina_base : public vectorina_main
{
public:
    vectorina_base() = delete;
    
    explicit vectorina_base(size_t n);
    vectorina_base(size_t n, const T *array);;
    vectorina_base(std::initializer_list<T>);
    
    explicit vectorina_base(const vectorina_base<T> &obj);
    vectorina_base(vectorina_base<T> &&obj);
    
    virtual ~vectorina_base();
    
    vectorina_base<T> &operator=(const vectorina_base<T> &obj);
    vectorina_base<T> &operator=(vectorina_base<T> &&obj);
    
    T &get(uint32_t index);
    const T &get(uint32_t index) const;
    
    void set(uint32_t index, T value);
    
    vectorina_iter<T> begin();
    vectorina_iter_const<T> begin() const;
    
    vectorina_iter<T> end();
    vectorina_iter_const<T> end() const;
    
    T operator[](uint32_t index) const;
    T &operator[](uint32_t index);
        
    T get_vector_length() const;
    
    vectorina_base &operator+=(const vectorina_base<T> &obj);
    vectorina_base &operator-=(const vectorina_base<T> &obj);
    
    vectorina_base<T> operator+(const vectorina_base<T> &obj) const;
    vectorina_base<T> operator-(const vectorina_base<T> &obj) const;
    vectorina_base<T> operator*(const T element) const;
    
    vectorina_base<T> operator+() const;
    vectorina_base<T> operator-() const;
    
    vectorina_base<T> add(const vectorina_base<T> &obj) const;
    vectorina_base<T> minus(const vectorina_base<T> &obj) const;
    vectorina_base<T> multi(const T element) const;
    
    T scalar_multi(vectorina_base<T> &obj);
    void normalize();
    
    template <typename U>
    friend bool operator<(const vectorina_base<T> &one, const vectorina_base<T> &two);
    
    template <typename U>
    friend bool operator>(const vectorina_base<T> &one, const vectorina_base<T> &two);
    
    template <typename U>
    friend bool operator<=(const vectorina_base<T> &one, const vectorina_base<T> &two);
    template <typename U>
    
    friend bool operator>=(const vectorina_base<T> &one, const vectorina_base<T> &two);
    
    template <typename U>
    friend std::ostream &operator<<(std::ostream&, const vectorina_base<U>&);
private:
    void destroy_object();
    
    T *math_vector;
};

size_t vectorina_main::get_size()
{
    return this->size;
}

template <typename T>
vectorina_base<T>::vectorina_base(size_t n) : vectorina_main(n)
{
    math_vector = new T[n];
}

template <typename T>
vectorina_base<T>::vectorina_base(vectorina_base<T> &&obj) :
    math_vector(obj.math_vector),
    vectorina_main(obj.size)
{
    obj.math_vector = nullptr;
    obj.size = 0;
}

template <typename T>
vectorina_base<T>::vectorina_base(std::initializer_list<T> list) :
    vectorina_main(list.size())
{
    math_vector = new T[list.size()];
    
    int current = 0;
    for (auto i = list.begin(); i < list.end(); i++)
    {
        math_vector[current] = *i;
        current++;
    }
}

template <typename T>
vectorina_base<T> &vectorina_base<T>::operator=(vectorina_base<T> &&obj)
{
    this->destroy_object();
    math_vector = obj.math_vector;
    size = obj.size;
    
    obj.math_vector = nullptr;
    obj.size = 0;
    return *this;
}

template <typename T>
vectorina_base<T>::vectorina_base(size_t n, const T *array) :
    vectorina_main(n)
{
    math_vector = new T[n];
    std::copy(array, array + n, math_vector);
}

template <typename T>
vectorina_base<T>::~vectorina_base()
{
    this->destroy_object();
}

template <typename T>
void vectorina_base<T>::destroy_object()
{
    if (math_vector)
        delete[] math_vector;
}

template <typename T>
vectorina_base<T>::vectorina_base(const vectorina_base<T> &obj) :
    vectorina_main(obj.size)
{
    if(size != obj.size)
        throw vectorina_wrong_dimension("size is not equals!", __LINE__);
    
    math_vector = new T[obj.size];
    std::copy(obj.math_vector, obj.math_vector + obj.size, math_vector);
}

template <typename T>
vectorina_base<T> &vectorina_base<T>::operator+=(const vectorina_base<T> &obj)
{
    if(size != obj.size)
        throw vectorina_wrong_dimension("size is not equals!", __LINE__);
    
    for(int32_t i = 0; i < obj.size; i++) {
        math_vector[i] += obj.math_vector[i];
    }
    
    return *this;
}

template <typename T>
vectorina_base<T> &vectorina_base<T>::operator-=(const vectorina_base<T> &obj)
{
    if(size != obj.size)
        throw vectorina_wrong_dimension("size is not equals!", __LINE__);
    
    for(int32_t i = 0; i < obj.size; i++) {
        math_vector[i] -= obj.math_vector[i];
    }
    
    return *this;
}

template <typename T>
T &vectorina_base<T>::get(uint32_t index)
{
    return math_vector[index];
}

template <typename T>
const T &vectorina_base<T>::get(uint32_t index) const
{
    return math_vector[index];
}

template <typename T>
vectorina_iter<T> vectorina_base<T>::begin()
{
    vectorina_iter<T> iter(math_vector);
    return iter;
}

template <typename T>
vectorina_iter<T> vectorina_base<T>::end()
{
    vectorina_iter<T> iter(math_vector + this->size);
    return iter;
}

template <typename T>
void vectorina_base<T>::normalize()
{
    T length = this->get_vector_length();
    for (int32_t i = 0; i < size; i++)
        math_vector[i] = math_vector[i] / length;
}

template <typename T>
vectorina_iter_const<T> vectorina_base<T>::begin() const
{
    vectorina_iter_const<T> iter(math_vector);
    return iter;
}

template <typename T>
vectorina_iter_const<T> vectorina_base<T>::end() const
{
    vectorina_iter_const<T> iter(math_vector + this->size);
    return iter;
}

template <typename T>
vectorina_base<T> &vectorina_base<T>::operator=(const vectorina_base<T> &obj)
{
    if(size != obj.size)
        throw vectorina_wrong_dimension("size is not equals!", __LINE__);
    
    for(int32_t i = 0; i < size; i++)
    {
        math_vector[i] = obj.math_vector[i];
    }
    return *this;
}

template <typename T>
void vectorina_base<T>::set(uint32_t index, T value)
{
    if(index < 0 || index >= size)
        throw vectorina_out_of_range("index out of range", __LINE__);
    
    math_vector[index] = value;
}

template <typename T>
T vectorina_base<T>::operator[](uint32_t index) const
{
    if(index < 0 || index >= size)
        throw vectorina_out_of_range("index out of range", __LINE__);
    
    return math_vector[index];
}

template <typename T>
T &vectorina_base<T>::operator[](uint32_t index)
{
    if(index < 0 || index >= size)
        throw vectorina_out_of_range("index out of range", __LINE__);
    
    return math_vector[index];
}

template <typename T>
T vectorina_base<T>::get_vector_length() const
{
    T res;
    for(int32_t i = 0; i < size; i++)
        res += math_vector[i] * math_vector[i];
    return res;
}

template <typename T>
vectorina_base<T> vectorina_base<T>::operator+(const vectorina_base<T> &obj) const
{
    return this->add(obj);
}

template <typename T>
vectorina_base<T> vectorina_base<T>::operator-(const vectorina_base<T> &obj) const
{
    return this->minus(obj);
}

template <typename T>
vectorina_base<T> vectorina_base<T>::operator*(T element) const
{
    return this->multi(element);
}

template <typename T>
vectorina_base<T> vectorina_base<T>::operator+() const
{
    return *this;
}

template <typename T>
vectorina_base<T> vectorina_base<T>::operator-() const
{
    vectorina_base<T> res(size);
    for(int32_t i = 0; i < size; i++)
        res.math_vector[i] = -math_vector[i];
    
    return res;
}

template <typename T>
vectorina_base<T> vectorina_base<T>::add(const vectorina_base<T> &obj) const
{
    if(size != obj.size)
        throw vectorina_wrong_dimension("size is not equals!", __LINE__);
    vectorina_base<T> res(size);
    for(int32_t i = 0; i < size; i++)
    {
        res.math_vector[i] = this->math_vector[i] + obj.math_vector[i];
    }
    return res;
}

template <typename T>
vectorina_base<T> vectorina_base<T>::minus(const vectorina_base<T> &obj) const
{
    if(size != obj.size)
        throw vectorina_wrong_dimension("size is not equals!", __LINE__);

    vectorina_base<T> res(size);
    for(int32_t i = 0; i < size; i++)
    {
        res.math_vector[i] = this->math_vector[i] - obj.math_vector[i];
    }
    return res;
}

template <typename T>
vectorina_base<T> vectorina_base<T>::multi(const T element) const
{
    vectorina_base<T> res(size);
    for(int32_t i = 0; i < size; i++)
    {
        res.math_vector[i] = math_vector[i] * element;
    }
    return res;
}

template <typename U>
bool operator<(const vectorina_base<U> &one, const vectorina_base<U> &two)
{
    if(one.size != two.size)
        throw vectorina_wrong_dimension("size is not equals!", __LINE__);
    return one.get_vector_length() < two.get_vector_length();
}

template <typename U>
bool operator>(const vectorina_base<U> &one, const vectorina_base<U> &two)
{
    if(one.size != two.size)
        throw vectorina_wrong_dimension("size is not equals!", __LINE__);
    return one.get_vector_length() > two.get_vector_length();
}

template <typename U>
bool operator<=(const vectorina_base<U> &one, const vectorina_base<U> &two)
{
    if(one.size != two.size)
        throw vectorina_wrong_dimension("size is not equals!", __LINE__);
    return one.get_vector_length() <= two.get_vector_length();
}

template <typename U>
bool operator>=(const vectorina_base<U> &one, const vectorina_base<U> &two)
{
    if(one.size != two.size)
        throw vectorina_wrong_dimension("size is not equals!", __LINE__);
    return one.get_vector_length() >= two.get_vector_length();
}

template <typename T>
T vectorina_base<T>::scalar_multi(vectorina_base<T> &obj)
{
    if(size != obj.size)
        throw vectorina_wrong_dimension("size is not equals!", __LINE__);
    
    T res;
    for (int32_t i = 0; i < size; i++)
    {
        res += obj.math_vector[i] + math_vector[i];
    }
    return res;
}

template <typename U>
std::ostream &operator<<(std::ostream &os, const vectorina_base<U> &obj)
{
    os << "{ ";
    for(int i = 0; i < obj.size; i++) {
        os << obj.math_vector[i] << " ";
    }
    os << "}" << std::endl;
    return os;
}

#endif //L2_OOP_VECTORINA_BASE_H
