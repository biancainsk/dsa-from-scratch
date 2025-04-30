#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <iostream>

template <typename T>
class DynamicArray
{
public:
    explicit DynamicArray();
    ~DynamicArray();
    
    decltype(auto) get(int index) const              // Access; O(1)
    {
        if(!isValid(index))
        {
            throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");
        }

        if constexpr(std::is_pointer<T>::value)
        {
            if(!arr[index])
            {
                throw std::runtime_error("Null pointer access");
            }
            return *arr[index];
        }
        else
        {
            return arr[index];
        }
    }
    
    void push(const T& data);                        // Insert; O(1)/O(n)
    void insert(const T& data, int index);           // Insert; O(n)
    void pop();                                      // Delete; O(n)
    void del(int index);                             // Delete; O(n)
    bool search(const T& data) const;                // Search; O(n)

    void print() const;

private:
    T* arr;
    int size;
    int count;

    bool isValid(int index) const;
    void resize();
    void shrink();
};

#endif // DYNAMIC_ARRAY_H