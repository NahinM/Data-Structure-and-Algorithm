
def ternarySearch(arr,a):
    lw,hi = 0,len(arr)-1

    # divide the array into three sections
    while hi-lw>5:
        mid1 = lw+((hi-lw)//3)
        mid2 = hi-((hi-lw)//3)

        if a<arr[mid1]: hi = mid1 # first part of the three sections
        elif arr[mid2]<a: lw = mid2 # end part of the three sections
        else: # middle part of the three sections
            lw = mid1
            hi = mid2
    
    for i in range(lw,hi+1):
        if arr[i]==a: return i
    return -1

arr = [(i+1) for i in range(40)]

for a in range(10,30):
    ndx = ternarySearch(arr,a)
    print(f"seaching for {a}: index={"Not Found" if(ndx<0) else ndx}")

a = 0
ndx = ternarySearch(arr,a)
print(f"seaching for {a}: index={"Not Found" if(ndx<0) else ndx}")