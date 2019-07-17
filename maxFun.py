def Amax(arr):
    if arr==[]:
        return 0
    else :
        if arr[0]>Amax(arr[1:]):
            return arr[0]
        else :
            return Amax(arr[1:])

print (Amax([3,-1,-4,-2,5,0]))