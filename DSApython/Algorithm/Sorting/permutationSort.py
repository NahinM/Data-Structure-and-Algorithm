def isSorted(arr):
    for i in range(len(arr)-1):
        if arr[i] > arr[i+1]: return False
    return True

flag = False
def findpmSort(arr,visited,container,i=0):
    global flag
    if i >= len(arr):
        if isSorted(container):
            for k in range(len(arr)):
                arr[k] = container[k]
            flag = True
        return

    for j in range(len(arr)):
        if not visited[j]:
            visited[j] = True
            container[i] = arr[j]
            if not flag: findpmSort(arr,visited,container,i+1)
            visited[j] = False

def permutationSort(arr):
    visited = [False]*len(arr)
    container = [0]*len(arr)
    findpmSort(arr,visited,container)
        


arr = [10,5,3,7,2,9,22,24,12]
# arr = [1,4,3]
permutationSort(arr)
print(arr)