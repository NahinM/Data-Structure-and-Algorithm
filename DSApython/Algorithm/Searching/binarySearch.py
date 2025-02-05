
def binarySearch(arr,x):
    lw,hi = 0,len(arr)-1
    mid = (hi-lw)>>1

    while hi-lw<=5:
        if arr[mid] == x: return True
        (lw := mid) if arr[mid]<x else (hi := mid)

    for i in range(lw,hi+1):
        if arr[i] == x: return True
    
    return False



arr = [(i+1)*2 for i in range(20)]

for i in range(1,20+1):
    print(f"{i} : {"Yes" if binarySearch(arr,i) else "NO"}")