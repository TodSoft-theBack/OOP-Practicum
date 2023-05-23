#include <iostream>
#include "Vector.hpp"

int main()
{
    Vector<int> collection;
    for (int i = 0; i < 5; i++)
        collection.PushBack(i + 1);
    std::cout << collection;
    collection.InsertAt(2u, 5);
    std::cout << collection;
    collection.RemoveAt(0);
    std::cout << collection;
    collection.RemoveBack();
    std::cout << collection;
    collection.Clear();
    std::cout << collection;
    return EXIT_SUCCESS;
}