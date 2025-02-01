def bubbleSort(arr):
    n = len(arr)
    for i in range(n-1):
        sorted = True
        for j in range(n-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1] = arr[j+1],arr[j]
                sorted = False
        if sorted:
            break

arr = [1,2,3,4,10,9,8,7,6,5]
bubbleSort(arr)
print(arr)