#include "array.h"

int main()
{
    DynamicArray<int> arr;
    arr.print();

    arr.push(10);
    std::cout << arr.get(0) << std::endl;
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

    arr.pop();
    arr.print();

    return 0;
}