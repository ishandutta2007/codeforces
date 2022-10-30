tests = int(input())
for test in range(tests):
    n = int(input())
    a = list(map(int, input().split()))
    b = [0]
    for x in a:
        b.append(x+b[-1])
    was = [0]*(n+1)
    for i in range(n):
        for j in range(i+1, n):
            if b[j+1]-b[i] <= n:
                was[b[j+1]-b[i]] = 1
    ans = 0
    for x in a:
        ans += was[x]
    print(ans)