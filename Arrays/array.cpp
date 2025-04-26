#include "array.h"

template <typename T>
DynamicArray<T>::DynamicArray()
{
    arr = new T[1];
    size = 1;
    count = 0;
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] arr;
}

template <typename T>
bool DynamicArray<T>::isValid(int index) const
{
    return ((index > -1) && (index < count));
}

template <typename T>
void DynamicArray<T>::resize()
{
    int newSize = size * 2;
    T* temp = new T[newSize];

    for (int i = 0; i < count; i++)
    {
        temp[i] = arr[i];
    }

    delete[] arr;
    arr = temp;
    size = newSize;
}

template <typename T>
void DynamicArray<T>::shrink()
{
    int newSize = size / 2;
    if(newSize < 1)
    {
        return; // minimum capacity is 1
    }

    T* temp = new T[newSize];

    for(int i = 0; i < count; i++)
    {
        temp[i] = arr[i];
    }

    delete[] arr;
    arr = temp;
    size = newSize;
}

template <typename T>
const T& DynamicArray<T>::get(int index) const
{
    if(isValid(index))
    {
        return arr[index];
    }
    throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");
}

template <typename T>
void DynamicArray<T>::push(const T& data)
{
    if(count == size)
    {
        resize();
    }
    arr[count++] = data;
}

template <typename T>
void DynamicArray<T>::insert(const T& data, int index)
{
    if(!isValid(index) && (index != count))
    {
        throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");
    }

    if(count == size)
    {
        resize();
    }

    for(int i = count; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = data;
    count++;
}

template <typename T>
void DynamicArray<T>::pop()
{
    if(count == 0)
    {
        throw std::out_of_range("Array is empty, cannot pop.");
    }

    count--;

    if(count > 0 && count <= size / 4)
    {
        shrink();
    }
}

template <typename T>
void DynamicArray<T>::del(int index)
{
    if(!isValid(index))
    {
        throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");
    }

    count--;
    for(int i = index; i < count; i++)
    {
        arr[i] = arr[i + 1];
    }
        
    if(count > 0 && count <= size / 4)
    {
        shrink();
    }
}

template <typename T>
bool DynamicArray<T>::search(const T& data) const
{
    for(int i = 0; i < count; i++)
    {
        if(data == arr[i])
        {
            std::cout << "Element " << data << " is present in the array at idx " << i << std::endl;
            return true;
        }
    }
    std::cout << "Element " << data << " is not present in the array" << std::endl;
    return false;
}

template <typename T>
void DynamicArray<T>::print() const
{
    for(int i = 0; i < count; i++)
    {
        std::cout << arr[i] << " ";  // Output: 1 2 3 4
    }
    std::cout << std::endl;
}

template class DynamicArray<int>;
template class DynamicArray<int*>;