#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i =low -1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Quicksort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        Quicksort(arr, low, pivot - 1);
        Quicksort(arr, pivot + 1, high);
    }
}

int main()
{
    vector<int> arr = {5, 12, 119, 1, 52, 16};
    int n= arr.size();

    Quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}