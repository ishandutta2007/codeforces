import math
tests = int(input())
for test in range(tests):
    n = int(input())
    ans = []
    ans2 = []
    zeros = 0
    while n > 0:
        if n % 10 > 0:
            ans.append(n % 10)
            ans2.append(zeros)
        n = math.floor(n / 10)
        zeros += 1
    print(len(ans))
    for i in range(len(ans)):
        print(ans[i], end='')
        for j in range(ans2[i]):
            print(0, end='')
        print("")