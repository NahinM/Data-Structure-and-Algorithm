MAX = 100

def countSort(arr):
    visited = [False]*MAX
    for i in arr:
        visited[i] = True
    
    at = -1
    for i in range(MAX):
        if visited[i]: arr[(at:=(at+1))] = i
    
arr = [9,8,7,6,5,4,3,2,1]
countSort(arr)
print(arr)