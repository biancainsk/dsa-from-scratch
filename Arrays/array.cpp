#include "array.h"

template <typename T>
DynamicArray<T>::DynamicArray()
{
    m_arr = new T[1];
    m_size = 1;
    m_count = 0;
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] m_arr;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) : m_arr(new T[other.m_size]), m_size(other.m_size), m_count(other.m_count)
{
    for(int i = 0; i < m_count; i++)
    {
        m_arr[i] = other.m_arr[i];
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray&& other) noexcept : m_arr(other.m_arr), m_size(other.m_size), m_count(other.m_count)
{
    other.m_arr = nullptr;
    other.m_size = 0;
    other.m_count = 0;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray other) noexcept
{
    swap(other);
    return *this;
}

template <typename T>
bool DynamicArray<T>::isValid(size_t index) const
{
    return (index < m_count);
}

template <typename T>
void DynamicArray<T>::resize()
{
    int newSize = m_size * 2;
    std::cout << "Resizing to " << newSize << std::endl;

    T* temp = new T[newSize];
    for(int i = 0; i < m_count; i++)
    {
        temp[i] = m_arr[i];
    }

    delete[] m_arr;
    m_arr = temp;
    m_size = newSize;
}

template <typename T>
void DynamicArray<T>::shrink()
{
    int newSize = m_size / 2;
    if(newSize < 1)
    {
        return;
    }
    std::cout << "Shrinking to " << newSize << std::endl;

    T* temp = new T[newSize];
    for(int i = 0; i < m_count; i++)
    {
        temp[i] = m_arr[i];
    }

    delete[] m_arr;
    m_arr = temp;
    m_size = newSize;
}

template <typename T>
void DynamicArray<T>::swap(DynamicArray& other) noexcept
{
    std::swap(m_arr, other.m_arr);
    std::swap(m_size, other.m_size);
    std::swap(m_count, other.m_count);
}


template <typename T>
const T& DynamicArray<T>::get(size_t index) const
{
    if(!isValid(index))
    {
        throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");
    }

    return m_arr[index];
}

template <typename T>
void DynamicArray<T>::pushBack(const T& data)
{
    std::cout << "Pushing " << data << std::endl;
    if(m_count == m_size)
    {
        resize();
    }
    m_arr[m_count++] = data;
}

template <typename T>
void DynamicArray<T>::insert(const T& data, size_t index)
{
    std::cout << "Inserting " << data << " at index " << index << std::endl;
    if(!isValid(index) && (index != m_count))
    {
        throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");
    }

    if(m_count == m_size)
    {
        resize();
    }

    for(int i = m_count; i > index; i--)
    {
        m_arr[i] = m_arr[i - 1];
    }

    m_arr[index] = data;
    m_count++;
}

template <typename T>
void DynamicArray<T>::pop()
{
    std::cout << "Poping " << m_arr[m_count - 1] << std::endl;
    if(m_count == 0)
    {
        throw std::out_of_range("Array is empty, cannot pop.");
    }

    m_count--;
    if((m_count > 0) && (m_count <= (m_size / 4)))
    {
        shrink();
    }
}

template <typename T>
void DynamicArray<T>::del(size_t index)
{
    std::cout << "Deleting element at index " << index << std::endl;
    if(!isValid(index))
    {
        throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");
    }

    m_count--;
    for(int i = index; i < m_count; i++)
    {
        m_arr[i] = m_arr[i + 1];
    }
        
    if((m_count > 0) && (m_count <= (m_size / 4)))
    {
        shrink();
    }
}

template <typename T>
bool DynamicArray<T>::search(const T& data) const
{
    for(int i = 0; i < m_count; i++)
    {
        if(data == m_arr[i])
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
    for(int i = 0; i < m_count; i++)
    {
        if constexpr(std::is_pointer<T>::value)
        {
            if(m_arr[i])
            {
                std::cout << *m_arr[i] << " ";
            }
            else
            {
                std::cout << "nullptr ";
            }
        }
        else
        {
            std::cout << m_arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

// template <typename T>
// const T* DynamicArray<T>::begin() const
// {
//     return m_arr;
// }

// template <typename T>
// const T* DynamicArray<T>::end() const
// {
//     return m_arr + m_count;
// }

template <typename T>
T& DynamicArray<T>::operator[](size_t index)
{
    return m_arr[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const
{
    return m_arr[index];
}

template <typename T>
T& DynamicArray<T>::at(size_t index)
{
    if(!isValid(index))
    {
        throw std::out_of_range("Index out of range");
    }
    return m_arr[index];
}

template <typename T>
const T& DynamicArray<T>::at(size_t index) const
{
    if(!isValid(index))
    {
        throw std::out_of_range("Index out of range");
    }
    return m_arr[index];
}

template class DynamicArray<int>;
template class DynamicArray<int*>;