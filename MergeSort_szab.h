#ifndef MERGESORT_TPP
#define MERGESORT_TPP



template <typename T>
void MergeSort<T>::sort(std::vector<T>& arr)
{
    if (arr.size() <= 1) return;
    mergeSort(arr, 0, arr.size() - 1);
}

template <typename T>
void MergeSort<T>::mergeSort(std::vector<T>& arr, int left, int right)
{
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

template <typename T>
void MergeSort<T>::merge(std::vector<T>& arr, int left, int mid, int right)
{
    std::vector<T> temp;
    temp.reserve(right - left + 1);
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j]) 
            temp.push_back(arr[i++]);
        else 
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}

#endif
