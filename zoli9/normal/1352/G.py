def perm(k):
    if k == 5:
        return [1, 4, 2, 5, 3]
    if k == 6:
        return [1, 4, 2, 5, 3, 6]
    if k == 7:
        return [1, 4, 2, 6, 3, 7, 5]
    if k == 8:
        return [1, 5, 2, 6, 3, 7, 4, 8]
    return []


tests = int(input())
for test in range(tests):
    n = int(input())
    ans = []
    if n <= 3:
        print(-1)
        continue
    if n == 4:
        print(3, 1, 4, 2)
        continue
    i = 1
    while True:
        if 5 <= n-i+1 <= 8:
            extra = perm(n-i+1)
            for j in range(len(extra)):
                extra[j] += (i-1)
            ans.extend(extra)
            break
        ans.extend([i+1, i+3, i, i+2])
        i += 4
    for x in ans:
        print(x, end=" ")
    print()