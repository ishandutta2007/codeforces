t = int(input())
for case in range(t):
    n, m, k = list(map(int, input().split()))
    p = n // k
    if p >= m:
        print(m)
    else:
        print(p - ((m - p) + k - 2) // (k - 1))