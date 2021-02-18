import numpy as np

import time

arr = np.random.randint(0,1000, size=(10000000,1))

now = time.time()
sum = 0
for i in arr:
sum+=i
print("Serial:",time.time()-now)
print(sum)

import multiprocessing
import os
import time
import numpy

def arrsum(arr):
sum = 0
for i in arr:
sum+=i
return sum
pool = multiprocessing.Pool(processes=32)

cpuc = multiprocessing.cpu_count()

l1 = arr[:arr.shape[0]//4]
l2 = arr[arr.shape[0]//4:arr.shape[0]//2]
l3 = arr[arr.shape[0]//2:arr.shape[0]*3//4]
l4 = arr[arr.shape[0]*3//4:]

now = time.time()

result = pool.map(arrsum, [l1,l2,l3,l4])
print(result[0]+result[1]+result[2]+result[3])

print("Parallel:",time.time()-now )

now = time.time()

print(np.sum(arr))

print("Builtin:",time.time()-now )