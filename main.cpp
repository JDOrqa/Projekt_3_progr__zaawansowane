#include <iostream>
#include <vector>
#include "MergeSort.h"

int main()
{
    MergeSort<int> sorterInt;
    std::vector<int> arrInt = { 5, 1, 9, 2, 3, -4, 7, 0 };

    std::cout << "Tablica int przed sortowaniem: ";
    for (auto x : arrInt) std::cout << x << " ";
    std::cout << std::endl;

    sorterInt.sort(arrInt);

    std::cout << "Tablica int po sortowaniu: ";
    for (auto x : arrInt) std::cout << x << " ";
    std::cout << std::endl;

    MergeSort<double> sorterDouble;
    std::vector<double> arrDouble = { 5.5, 1.1, -3.3, 9.9, 0.5, -2.7 };

    std::cout << "\nTablica double przed sortowaniem: ";
    for (auto x : arrDouble) std::cout << x << " ";
    std::cout << std::endl;

    sorterDouble.sort(arrDouble);

    std::cout << "Tablica double po sortowaniu: ";
    for (auto x : arrDouble) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
