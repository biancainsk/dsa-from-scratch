#include "array.h"

int main()
{
    // --- ARRAY OF INTS ---
    std::cout << "--- ARRAY OF INTS ---" << std::endl;
    DynamicArray<int> arr;

    arr.pushBack(10);
    arr.print();

    arr.pushBack(20);
    arr.print();

    arr.pushBack(30);
    arr.print();

    arr.insert(40, 2);
    arr.print();

    std::cout << "At index 3 value is " << arr[3] << std::endl;

    // .begin() and .end() allows us to use range-based for-loops like this:
    // for(auto val : arr)
    // {
    //     std::cout << val << " ";
    //     // val++;
    // }
    // std::cout << std::endl;

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

    std::cout << std::endl;

    // --- ARRAY OF POINTERS ---
    std::cout << "--- ARRAY OF POINTERS ---" << std::endl;
    DynamicArray<int*> arrPtr;

    for(int i = 0; i < 10; i++)
    {
        int* ptrVal = new int(i * 10);
        arrPtr.pushBack(ptrVal);
    }

    arrPtr.print();

    arrPtr.del(1);
    arrPtr.print();

    std::cout << arrPtr.get(5) << std::endl;
    std::cout << "At index 5 value is " << arrPtr[3] << std::endl;

    arrPtr.pop();
    arrPtr.print();

    arrPtr.del(2);
    arrPtr.print();

    return 0;
}