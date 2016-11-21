//
//  Vector.hpp
//  Learning
//
//  Created by Elena Ispas on 15/11/16.
//  Copyright © 2016 ElenaI. All rights reserved.
//

#ifndef Vector_h
#define Vector_h

#include<iostream>
#include<cstring>

template <typename T>
class Vector
{
    private:
            T* m_array;
            std::size_t m_size;
            std::size_t m_capacity;
    
            void    IncreaseCapacity();
            T*      MoveArray(std::size_t newCapacity);
            void    DeleteArrayElements(T* array, std::size_t size);
    
    public:
            Vector():m_capacity(0), m_size(0), m_array(nullptr){}
            Vector(std::size_t newSize);
            ~Vector();
    
            void    PushBack(const T& element);
};

template<typename T>
Vector<T>::Vector(std::size_t capacity)
{
    m_capacity = capacity;
    m_size = 0;
    m_array = (T*)malloc(m_capacity * sizeof(T));
}

template<typename T>
Vector<T>::~Vector()
{    
    DeleteArrayElements(m_array, m_size);
    
    free(m_array);
}

template<typename T>
void Vector<T>::PushBack(const T& element)
{
    if(m_size == m_capacity)
    {
        IncreaseCapacity();
    }
    
    new(&m_array[m_size]) T(element);
        
    ++m_size;
}

template<typename T>
void Vector<T>::IncreaseCapacity()
{
    assert(m_size <= m_capacity && "vector's size is greater than it's capacity");
    auto newCapacity = m_size / 2 + 1;
    T* newVector = Vector<T>::MoveArray(newCapacity);
    
    DeleteArrayElements(m_array, m_size);
    
    m_capacity = newCapacity;
    
    m_array = newVector;
}

template<typename T>
T* Vector<T>::MoveArray(std::size_t newCapacity)
{
    assert(m_size <= newCapacity);
    
    T* newArray = (T*)std::malloc(newCapacity);
    int index = 0;
    try
    {
        for(; index < m_size; ++index)
        {
            new (&newArray[index]) T(m_array[index]);
        }
    } catch (...)
    {
        DeleteArrayElements(newArray, index);
        throw;
    }
    
    return  newArray;
}

template<typename T>
void Vector<T>::DeleteArrayElements(T* array, std::size_t size)
{
    for(auto p = array; p < array + m_size; ++p)
    {
        (*p).~T();
    }
}

#endif /* Vector_h */
