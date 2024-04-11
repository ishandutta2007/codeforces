import math
tests = int(input())
for test in range(tests):
    n, k = map(int, (input().split()))
    p = n-1
    c = math.floor(k/p)
    num = n*c
    if k % p == 0:
        print(num-1)
    else:
        print(num + k % p)