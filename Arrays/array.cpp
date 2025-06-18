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
DynamicArray<T>::DynamicArray(const DynamicArray& other) : arr(new T[other.size]), size(other.size), count(other.count)
{
    for(int i = 0; i < count; i++)
    {
        arr[i] = other.arr[i];
    }
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
    if(this != &other)
    {
        size = other.size;
        count = other.count;

        if(arr)
        {
            delete[] arr;
        }
        arr = new T[size];
        for (int i = 0; i < count; ++i)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray&& other) noexcept : arr(other.arr), size(other.size), count(other.count)
{
    other.arr = nullptr;
    other.size = 0;
    other.count = 0;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray&& other) noexcept
{
    if(this != &other)
    {      
        size = other.size;
        count = other.count;

        if(arr)
        {
            delete[] arr;
        }
        arr = other.arr;

        other.size = 0;
        other.count = 0;
        other.arr = nullptr;
    }
    return *this;
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
    std::cout << "Resizing to " << newSize << std::endl;

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
    std::cout << "Shrinking to " << newSize << std::endl;

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
    if(!isValid(index))
    {
        throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");
    }

    return arr[index];
}

template <typename T>
void DynamicArray<T>::push(const T& data)
{
    std::cout << "Pushing " << data << std::endl;
    if(count == size)
    {
        resize();
    }
    arr[count++] = data;
}

template <typename T>
void DynamicArray<T>::insert(const T& data, int index)
{
    std::cout << "Inserting " << data << " at index " << index << std::endl;
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
    std::cout << "Poping " << arr[count - 1] << std::endl;
    if(count == 0)
    {
        throw std::out_of_range("Array is empty, cannot pop.");
    }

    count--;

    if(count > 0 && count <= (size / 4))
    {
        shrink();
    }
}

template <typename T>
void DynamicArray<T>::del(int index)
{
    std::cout << "Deleting element at index " << index << std::endl;
    if(!isValid(index))
    {
        throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");
    }

    count--;
    for(int i = index; i < count; i++)
    {
        arr[i] = arr[i + 1];
    }
        
    if(count > 0 && count <= (size / 4))
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
    std::cout << "The array is: ";
    for(int i = 0; i < count; i++)
    {
        if constexpr(std::is_pointer<T>::value)
        {
            if(arr[i])
            {
                std::cout << *arr[i] << " ";
            }
            else
            {
                std::cout << "nullptr ";
            }
        }
        else
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

template <typename T>
const T* DynamicArray<T>::begin() const
{
    return arr;
}

template <typename T>
const T* DynamicArray<T>::end() const
{
    return arr + count;
}

template <typename T>
const T& DynamicArray<T>::operator[](int index) const
{
    if(!isValid(index))
    {
        throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");
    }

    return arr[index];
}

template class DynamicArray<int>;
template class DynamicArray<int*>;