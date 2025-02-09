def selectionSort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(i+1,n):
            if arr[i] > arr[j]: arr[i],arr[j] = arr[j],arr[i]

arr = [9,8,7,6,5,4,3,2,1]
selectionSort(arr)
print(arr)
