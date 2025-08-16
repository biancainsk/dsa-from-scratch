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
    DynamicArray();

    /**
     * @brief Destroy the Dynamic Array object
     */
    ~DynamicArray();

    /**
     * @brief Copy Constructor
     */
    DynamicArray(const DynamicArray& other);

    /**
     * @brief Move Constructor
     */
    DynamicArray(DynamicArray&& other) noexcept;

    /**
     * @brief Copy and Move Assignment Operator
     */
    DynamicArray& operator=(DynamicArray other) noexcept;


    /**
     * @brief Get element at index (read-only).
     * @param index The index of the element to retrieve.
     * @return const T& Reference to the element.
     * Access; O(1)
     */
    const T& get(size_t index) const;

    /**
     * @brief Append an element to the end of the array.
     * @param data The element to add.
     * Insert; O(1)
     */
    void pushBack(const T& data);

    /**
     * @brief Insert an element at a specific index.
     * @param data The element to insert.
     * @param index The position at which to insert the element.
     * Insert; O(n)
     */
    void insert(const T& data, size_t index);

    /**
     * @brief Remove the last element in the array.
     * Delete; O(1)
     */
    void pop();

    /**
     * @brief Delete an element at a given index.
     * @param index The index of the element to delete.
     * Delete; O(n)
     */
    void del(size_t index);

    /**
     * @brief Search for an element in the unsorted array; Linear Search.
     * @param data The element to search for.
     * @return true If found.
     * @return false If not found.
     * Search; O(n)
     */
    bool search(const T& data) const;


    /**
     * @brief Print the elements in the array.
     */
    void print() const;

    // /**
    //  * @brief Get pointer to first element (for iteration).
    //  * @return const T* Pointer to beginning.
    //  */
    // const T* begin() const;
    // /**
    //  * @brief Get pointer to one past the last element.
    //  * @return const T* Pointer to end.
    //  */
    // const T* end() const;

    /**
     * @brief Access element at index.
     * @param index Index to access.
     * @return T& Reference to element.
     */
    T& operator[](size_t index);
    /**
     * @brief Access element at index (read-only).
     * @param index Index to access.
     * @return const T& Reference to element.
     */
    const T& operator[](size_t index) const;

    /**
     * @brief ccess element at a specific index with bounds checking.
     * @param index The position of the element to access. Must be in range [0, size()).
     * @return T& Reference to the element at the specified index.
     */
    T& at(size_t index);
    /**
     * @brief Access element at a specific index with bounds checking (const version).
     * @param index The position of the element to access. Must be in range [0, size()).
     * @return const T& Reference to the element at the specified index.
     */
    const T& at(size_t index) const;

private:

    /**
     * @brief Internal array.
     */
    T* m_arr;

    /**
     * @brief Total capacity of the array.
     */
    size_t m_size;

    /**
     * @brief Number of actual elements.
     */
    size_t m_count;


    /**
     * @brief Check if a specific index is valid.
     * @param index Index to check.
     * @return true if the index is valid, false otherwise.
     */
    bool isValid(size_t index) const;

    /**
     * @brief Double the total size of the array.
     * O(n)
     */
    void resize();

    /**
     * @brief Halve the size of the array.
     * O(n)
     */
    void shrink();

    /**
     * @brief Swap the contents of the array with another.
     * Exception safety: No-throw guarantee.
     * @param other The DynamicArray to swap with.
     */
    void swap(DynamicArray& other) noexcept;
};

#endif // DYNAMIC_ARRAY_H