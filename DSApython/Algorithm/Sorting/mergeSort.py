def merge(arr1,arr2,into):
    i1,i2,a = 0,0,0
    while a<len(into):
        while i1 < len(arr1) and (i2>=len(arr2) or arr1[i1]<arr2[i2]):
            into[a] = arr1[i1]
            a+=1
            i1+=1
        while i2 < len(arr2) and (i1>=len(arr1) or arr2[i2]<arr1[i1]):
            into[a] = arr2[i2]
            a+=1
            i2+=1

def mergeSort(arr):
    left = 0
    right = len(arr)-1
    if left>=right:
        return
    
    mid = (right-left)>>1

    arr1 = [arr[i] for i in range(left,mid+1)]
    mergeSort(arr1)

    arr2 = [arr[i] for i in range(mid+1,right+1)]
    mergeSort(arr2)

    merge(arr1,arr2,arr)

arr = [10,9,8,7,6,5,4,3,2,1]
mergeSort(arr)
print(arr)