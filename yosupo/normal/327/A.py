n = int(input())
a = list(map(int, input().split()))

res = 0
for i in range(n):
    for j in range(i, n):
        b = a[:]
        for u in range(i, j+1):
            if b[u]:
                b[u] = 0
            else:
                b[u] = 1
        res = max(res, b.count(1))
print(res)