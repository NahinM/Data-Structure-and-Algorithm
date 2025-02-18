
def countSort1(arr):
    MAX = MIN = arr[0]
    for i in arr:
        if i>MAX: MAX=i
        if i<MIN: MIN=i

    count = [0]*(MAX-MIN+1)
    for i in arr: count[i-MIN]+=1
    
    at,i = 0,0
    ln = len(arr)
    while at<ln:
        if count[i]==0: i += 1
        else:
            arr[at]=i+MIN
            count[i]-=1
            at+=1


def countSort2(arr):
    MAX=MIN=arr[0]
    for i in arr:
        if i<MIN: MIN = i
        if i>MAX: MAX = i
    
    count = [0]*(MAX-MIN+1)
    for i in arr: count[i-MIN]+=1
    
    ln = len(arr)
    for i in range(1,MAX-MIN+1): count[i]+=count[i-1]
    
    arr2 = [0]*ln
    for i in range(ln-1,-1,-1):
        x = arr[i]-MIN
        count[x]-=1
        arr2[count[x]] = x+MIN
    
    return arr2
    
arr = [10,16,19,13,17,12,11]
print(countSort2(arr))
countSort1(arr)
print(arr)
