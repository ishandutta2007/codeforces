t=int(input())
for i in range(t):
    n, k = map(int, input().strip().split())
    a = n // k
    b = n % k
    if b > k // 2:
        b = k // 2
    print(a * k + b)