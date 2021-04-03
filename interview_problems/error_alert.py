def check(arr, size, x): 
    count = 0
    left = 0 
    for i in range(size):
        if arr[i] > x:
            count += 1
    if count == size:
        return True 
    for i in range(size, len(arr)):
        count -= 1 if arr[left] > x else 0 
        left += 1
        count += 1 if arr[i] > x else 0
        if count == size:
            return True
    return False 

def error_alert(arr, threshold):
    for i in range(1, threshold):
        if check(arr, i, threshold / i):
            return True
    return False

array = [1, 3, 4, 3, 1]
threshold = 6
print(error_alert(array, threshold))

array = [4, 3, 1, 3, 1]
threshold = 6
print(error_alert(array, threshold))






111
101
111

111111
100001
10011
101
111 

111111
100001
100001
100001
111111