k = int(input())
for i in range(k):
    side = 0
    n = int(input())
    s = sorted(list(map(int, input().split())))
    for i in range(n):
        side = max(min(n - i, s[i]), side)
    print(side)