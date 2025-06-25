#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Selection_sort(vector<int> &arr, int n)
{
    for (int i =0; i<n-1;i++)
    {
        int min = i;
        for (int j =i+1;j<n;j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    Selection_sort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}