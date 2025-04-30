#include "array.h"

int main()
{
    // --- ARRAY OF INTS ---
    std::cout << "--- ARRAY OF INTS ---" << std::endl;
    DynamicArray<int> arr;
    arr.print();

    arr.push(10);
    int& x = arr.get(0);
    std::cout << x << std::endl;
    arr.print();

    arr.push(20);
    arr.print();

    arr.push(30);
    arr.print();

    arr.insert(40, 2);
    arr.print();

    arr.pop();
    arr.print();

    arr.search(10);
    arr.search(20);
    arr.search(30);

    arr.del(1);
    arr.print();

    arr.pop();
    arr.print();

    arr.pop();
    arr.print();

    // --- ARRAY OF POINTERS ---
    std::cout << "--- ARRAY OF POINTERS ---" << std::endl;
    DynamicArray<int*> arrPtr;

    for(int i = 0; i < 10; i++)
    {
        int* ptrVal = new int(i * 10);
        arrPtr.push(ptrVal);
    }

    arrPtr.print();

    arrPtr.del(1);
    arrPtr.print();

    std::cout << arrPtr.get(5) << std::endl;
    auto& y = arrPtr.get(5);
    y = 12;
    arrPtr.print();

    return 0;
}