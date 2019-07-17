def number(arr):
    if arr==[]:
        return 0
    else:
        return 1+number(arr[1:])

print (number([1,2,3,4]))