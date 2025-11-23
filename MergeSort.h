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
   void mergeSort(std::vector<T>& arr, int left, int right)
    {
        if (left >= right) return;

        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
#endif
