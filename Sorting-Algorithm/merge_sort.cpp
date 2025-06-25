#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }
    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }
}

void merge_sort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return; // Base case: if the array has one or no elements, it's already sorted

    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);    
    merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size(); 

    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}