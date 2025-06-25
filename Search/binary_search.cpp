#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(const vector<int>& arr,int target,int start, int end)
{
    int mid = start + (end - start) / 2;
    if (start > end) 
    {
        return false;
    }

    if (arr[mid] == target) 
    {
        return true;
    }
    if (arr[mid] < target) 
    {
        return binary_search(arr, target, mid + 1, end);
    }
    return binary_search(arr, target, start, mid - 1);
}


int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    sort(arr.begin(), arr.end());
    int target = 19;
    binary_search(arr,target,0,arr.size()-1) ? cout << "Element found" : cout << "Element not found";
    return 0;
}