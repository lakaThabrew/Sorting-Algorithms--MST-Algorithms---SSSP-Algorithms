#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubble_sort(vector<int> &arr, int n)
{
    bool swapped;
    for (int i =0;i<n;i++)
    {
        swapped = false;
        for (int j=0;j<n-i-1;j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    
    bubble_sort(arr, n);

    cout << "\nSorted array: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}