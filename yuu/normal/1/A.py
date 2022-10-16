import math
n, m, a = list(map(int, input().split()))
n = math.ceil(n / a)
m = math.ceil(m / a)
print(n * m)