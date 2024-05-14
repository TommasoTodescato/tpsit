import time
from numpy import random

arr = random.randint(1000000000, size=1000)
arr2 = arr.copy()
def bubbleSort(arr):
    n = len(arr)
    for i in range(n-1):
        swapped = False
        for j in range(0, n-i-1):
            if arr[j] > arr[j + 1]:
                swapped = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

        if not swapped:
            return


start = time.time()
bubbleSort(arr)
end = time.time()
t1 = end-start
print(t1)


start = time.time()
arr2.sort()
end = time.time()
t2 = end-start
print(t2)

