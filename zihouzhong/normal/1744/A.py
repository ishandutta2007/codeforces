tc = int(input())
for _ in range(tc):
    n = int(input())
    a = list(map(int, input().split()))
    s = input()

    flag = True
    for i in range(n):
        for j in range(n):
            if a[i] == a[j] and s[i] != s[j]:
                flag = False

    print("YES" if flag else "NO")