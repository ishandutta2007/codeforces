tests = int(input())
for test in range(tests):
    n = list(map(int, input().split()))
    ans = []
    if n[1] == 0:
        if n[0] > 0:
            ans.extend([0] * (n[0] + 1))
        else:
            ans.extend([1] * (n[2] + 1))
        for x in ans:
            print(x, end="")
        print()
        continue
    ans.extend([0] * (n[0] + 1))
    x = n[1]
    if x % 2 == 0:
        x -= 1
    for i in range(x):
        ans.append(1 - i % 2)
    ans.extend([1] * (n[2]))
    if x != n[1]:
        ans.append(0)
    for x in ans:
        print(x, end="")
    print()