import math

a, b = [int(x) for x in input().split()]

d = 7 - max(a, b)

g = math.gcd(d, 6)

print(d // g, '/', 6 // g, sep='')