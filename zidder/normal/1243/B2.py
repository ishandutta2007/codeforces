from collections import defaultdict

k = int(input())
for i in range(k):
    n = int(input())
    s1 = list(input())
    s2 = list(input())
    ans = []
    def swp(i, j):
        ans.append((i+1, j+1))
        s1[i], s2[j] = s2[j], s1[i]
    c = defaultdict(int)
    for i in s1:
        c[i] += 1
    for i in s2:
        c[i] += 1

    for k, v in c.items():
        if v % 2 == 1:
            print('No')
            break
    else:
        print('Yes')
        for i in range(n):
            for j in range(i + 1, n):
                if s1[i] == s1[j]:
                    swp(j, i)
                    break
            else:
                for j in range(i + 1, n):
                    if s1[i] == s2[j]:
                        swp(i+1, j)
                        swp(i+1, i)
                        break
        if ans == []:
            ans.append([1, 1])
        assert s1 == s2
        assert len(ans) <= 2 * n
        print(len(ans))
        for i in ans:
            print(*i)