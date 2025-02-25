
def binarySearch(arr,a):
    lw,hi = 0,len(arr)-1

    while lw<=hi:
        mid = (hi+lw)>>1
        if arr[mid] == a: return True
        elif arr[mid] < a: lw = mid+1
        else : hi = mid-1
    return False

arr = [(i+1)*2 for i in range(20)]

for i in range(1,40+1):
    print(f"{i}\t: {"Yes" if binarySearch(arr,i) else "NO"}")
