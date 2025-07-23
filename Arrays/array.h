#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <iostream>

/**
 * @brief A dynamic array class that supports generic types with automatic resizing.
 * @tparam T Type of the elements in the array.
 */
template <typename T>
class DynamicArray
{
public:
    /**
     * @brief Construct a new Dynamic Array object
     */
    explicit DynamicArray();

    /**
     * @brief Destroy the Dynamic Array object
     */
    ~DynamicArray();

    /**
     * @brief Copy Constructor
     */
    DynamicArray(const DynamicArray& other);

    /**
     * @brief Copy Assignment Operator
     */
    DynamicArray& operator=(const DynamicArray& other);

    /**
     * @brief Move Constructor
     */
    DynamicArray(DynamicArray&& other) noexcept;

    /**
     * @brief Move Assignment Operator
     */
    DynamicArray& operator=(DynamicArray&& other) noexcept;

    /**
     * @brief Get element at index (read-only)
     * @param index The index of the element to retrieve
     * @return const T& Reference to the element
     * Access; O(1)
     */
    const T& get(int index) const;

    /**
     * @brief Append an element to the end of the array
     * @param data The element to add
     * Insert; O(1)/O(n)
     */
    void push(const T& data);

    /**
     * @brief Insert an element at a specific index
     * @param data The element to insert
     * @param index The position at which to insert the element
     * Insert; O(n)
     */
    void insert(const T& data, int index);

    /**
     * @brief Remove the last element in the array
     * Delete; O(n)
     */
    void pop();

    /**
     * @brief Delete an element at a given index
     * @param index The index of the element to delete
     * Delete; O(n)
     */
    void del(int index);

    /**
     * @brief Search for an element in the array
     * @param data The element to search for
     * @return true If found
     * @return false If not found
     * Search; O(n)
     */
    bool search(const T& data) const;

    /**
     * @brief Print the elements in the array
     */
    void print() const;

    /**
     * @brief Get pointer to first element (for iteration)
     * @return const T* Pointer to beginning
     */
    const T* begin() const;

    /**
     * @brief Get pointer to one past the last element
     * @return const T* Pointer to end
     */
    const T* end() const;

    /**
     * @brief Access element at index (read-only)
     * @param index Index to access
     * @return const T& Reference to element
     */
    const T& operator[](int index) const;

private:

    /**
     * @brief Internal array
     */
    T* m_arr;

    /**
     * @brief Total capacity of the array
     */
    int m_size;

    /**
     * @brief Number of actual elements
     */
    int m_count;

    /**
     * @brief Check if a specific index is valid
     * @param index Index to check
     * @return true if the index is valid, false otherwise 
     */
    bool isValid(int index) const;

    /**
     * @brief Double the total size of the array
     */
    void resize();

    /**
     * @brief Halve the size of the array
     */
    void shrink();
};

#endif // DYNAMIC_ARRAY_H