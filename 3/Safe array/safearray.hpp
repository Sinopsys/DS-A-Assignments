////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Safearray class methods definition
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      30.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// This file contains templates of the method of the class Safearray.
/// This file is not going to be used w/o its main counterpart, safearray.h.
/// Since the file is used only through safearray.h, which has its own "include 
/// watcher", we add no addition "watcher" here.
///
////////////////////////////////////////////////////////////////////////////////

// #ifndef    // No need to have a watcher here!


#include "safearray.h"


// we have to indicate that methods of the class Safearray are also inside the namespace xi
namespace xi
{
    using std::out_of_range;

    template<typename T>
    SafeArray<T>::SafeArray(size_t cap)
    {
        _storage = new T[cap];
        _capacity = cap;
    }

    template<typename T>
    SafeArray<T>::~SafeArray()
    {
        delete[] _storage;
        _storage = nullptr;
        _capacity = 0;
    }

    template<typename T>
    T &SafeArray<T>::operator[](size_t k)
    {
        checkBounds(k);
        return _storage[k];
    }

    template<typename T>
    const T &SafeArray<T>::operator[](size_t k) const
    {
        checkBounds(k);
        return (const T &) _storage[k];
    }

    template<typename T>
    size_t SafeArray<T>::getCapacity() const
    {
        return _capacity;
    }

    template<typename T>
    void SafeArray<T>::checkBounds(size_t index) const
    {
        if ((index >= _capacity) || (index < 0))
        {
            throw out_of_range("Index out of range.");
        }
    }


    template<class T>
    SafeArray<T>::SafeArray(const SafeArray <T> &other)
    {
        _capacity = other._capacity;
        _storage = new T[_capacity];
        for (int i = 0; i < _capacity; ++i)
        {
            _storage[i] = other[i];
        }
    }

    template<class T>
    SafeArray <T> &SafeArray<T>::operator=(const SafeArray <T> &other)
    {
        size_t len = other._capacity;
        T *tmp = new SafeArray<T>(len);
        for (int i = 0; i < len; ++i)
        {
            tmp[i] = other[i];
        }
        delete[] _storage;
        _storage = nullptr;
        _storage = tmp;
        _capacity = len;
        return *this;
    }
} // namespace xi
