def recursion(arr, target, left, right):
    mid = (left + right) // 2
    if arr[mid] == target:
        return True
    elif arr[mid] < target:
        return recursion(arr, target, mid + 1, right)
    else:
        return recursion(arr, target, left, mid - 1)      
    return False

target = 12
arr = [2, 3, 4, 5, 6, 7, 8, 9, 10]
if recursion(arr, target, 0, len(arr) - 1):
    print("Found")
else:
    print("Not Found")

