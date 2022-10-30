n = int(input())

s = input()

min_max_len = n
for c in range(1, n):
    if s[c] != '0':
        if max(c, n-c) < min_max_len:
            min_max_len = max(c, n-c)
ans = None

for c in range(1, n):
    if s[c] != '0':
        if max(c, n-c) <= min_max_len+1:
            x = int(s[:c])+int(s[c:])
            if (ans is None) or ans > x:
                ans = x

print(ans)