
def searchRange(arr,a):
    lw,hi = 0,len(arr)-1 
    head,end = 0,hi
    if a<arr[head] or arr[end] <a: return -1,-1

    while lw<=hi: # search for the head of the "a,a,...,a" sequence
        mid = (lw+hi)>>1
        if arr[mid] == a:
            head = mid
            hi = mid-1
        elif arr[mid] < a: lw = mid+1
        else : hi = mid-1
    
    lw,hi = 0,len(arr)-1

    while lw<=hi: # search for the end of the "a,a,...,a" sequence
        mid = (lw+hi)>>1
        if arr[mid] == a:
            end = mid
            lw = mid+1
        elif arr[mid] < a: lw = mid+1
        else : hi = mid-1

    return head,end

arr = [1,1,2,2,3,3,3,3,4,4,6,6,7,8,8]
for i in range(1,9):
    print(f"{i}-> {searchRange(arr,i)}")
