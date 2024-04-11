t = int(input())
for i in range(t):
    x, y, n = map(int, input().split())
    ans = (n // x) * x + y
    if ans > n:
        ans -= x
    print(ans)