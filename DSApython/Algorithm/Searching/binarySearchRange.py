
def searchRange(arr,a):
    lw,hi = 0,len(arr)-1 # first search for the head of the "a,a,...,a" sequence
    while hi-lw>5: 
        mid = (lw+hi)>>1
        (hi:=mid) if(a<=arr[mid]) else (lw:=mid)
        
    head = lw
    while head<=hi and arr[head]!=a: head+=1
    if arr[head] != a: return (-1,-1)
    
    lw,hi = 0,len(arr)-1 # then search for the end of the "a,a,...,a" sequence
    while hi-lw>5:
        mid = (lw+hi)>>1
        (lw:=mid) if(arr[mid]<=a) else (hi:=mid)

    end = hi
    while end>=lw and arr[end]!=a: end-=1
    
    return head,end

arr = [1,1,2,2,3,3,3,3,4,4,6,6,7,8,8]
for i in range(1,9):
    print(f"{i}-> {searchRange(arr,i)}")
