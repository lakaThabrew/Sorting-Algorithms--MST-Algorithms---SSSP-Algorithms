#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int> &arr, int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void make_heap(vector<int> &arr, int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(arr, i, n);
    }
}

void sort_heap(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n - 1; i > 0; --i) {
        heapify(arr, i, n);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main()
{
    vector<int> arr = {12, 11, 3, 2, 5, 10, 14, 16};

    make_heap(arr, arr.size());
    
    cout << "Max heap is: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    sort_heap(arr);

    cout << "Sorted array is: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}