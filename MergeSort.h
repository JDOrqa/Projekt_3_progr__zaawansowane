#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template <typename T>
class MergeSort
{
public:
   /// Sortuje wektor rosnąco
    void sort(std::vector<T>& arr)
    {
        if (arr.size() <= 1) return;
        mergeSort(arr, 0, arr.size() - 1);
    }
private:
  
#endif
