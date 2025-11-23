#include <iostream>
#include <vector>
#include "MergeSort.h"

int main()
{
    // Instancja dla int
    MergeSort<int> sorterInt;
    std::vector<int> arrInt = { 5, 1, 9, 2, 3, -4, 7, 0 };

    std::cout << "Tablica int przed sortowaniem: ";
    for (auto x : arrInt) std::cout << x << " ";
    std::cout << std::endl;

    sorterInt.sort(arrInt);

    std::cout << "Tablica int po sortowaniu: ";
    for (auto x : arrInt) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
