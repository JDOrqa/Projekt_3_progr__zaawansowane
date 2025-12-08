#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template <typename T>
class MergeSort
{
public:
    void sort(std::vector<T>& arr);

private:
    void mergeSort(std::vector<T>& arr, int left, int right);
    void merge(std::vector<T>& arr, int left, int mid, int right);
};

// dolaczanie szablonu
#include "MergeSort_szab.h"

#endif
