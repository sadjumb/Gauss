#pragma once
#include <iostream>
template<class T>
class Vector
{
public:
    Vector()
    {
        size = 0;
        arr = nullptr;
    }
    Vector(const int& _size)
    {
        size = _size;
        arr = new T[size];
    }
    Vector(const Vector& copy)
    {
        size = copy.size;
        arr = new T[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = copy[i];
        }
    }
    ~Vector()
    {
        delete[] arr;
    }

    T& operator[](const int& index) const
    {
        return arr[index];
    }
    T& operator[](const int& index)
    {
        return arr[index];
    }

    Vector& operator=(const Vector& obj)
    {
        if (this != &obj)
        {
            delete[] arr;
            size = obj.size;
            arr = new T[size];
            for (int i = 0; i < size; ++i)
            {
                arr[i] = obj.arr[i];
            }
        }
        return *this;
    }
    Vector operator*(const T& obj)
    {
        Vector<T> tmp(size);
        for (int i = 0; i < size; ++i)
        {
            tmp.arr[i] = arr[i] * obj;
        }
        return tmp;
    }

    Vector& operator/=(const T& obj)
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] /= obj;
        }
        return *this;
    }

    Vector& operator-=(const Vector& obj)
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] -= obj.arr[i];
        }
        return *this;
    }
    int _size() const
    {
        return size;
    }

    void set_vector()
    {
        T tmp;
        for (int i = 0; i < size; ++i)
        {
            std::cin >> tmp;
            arr[i] = tmp;
        }
    }
	
    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i] << " ";
        }
    }
	
    void swap(const int& left, const int& right)
    {
        const T tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }

private:
    int size;
    T* arr;
};

