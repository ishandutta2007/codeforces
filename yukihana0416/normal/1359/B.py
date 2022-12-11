tc = int(input())
for ca in range(tc):
    n, m, x, y = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        s = input()
        cnt = 0
        for j in range(m):
            if s[j] == '.':
                cnt += 1
            else:
                ans += min(x * cnt, cnt // 2 * y + (cnt & 1) * x)
                cnt = 0
        ans += min(x * cnt, cnt // 2 * y + (cnt & 1) * x)
    print(ans)