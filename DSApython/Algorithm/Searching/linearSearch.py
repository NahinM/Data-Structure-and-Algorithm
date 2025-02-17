def linearSearch(arr,x):
    for i in arr:
        if i==x: return True
    return False

arr = [1,2,3,4,5,6,7,8,9]
print("YES") if linearSearch(arr,6) else print("NO")