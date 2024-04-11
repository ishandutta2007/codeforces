# kitten
n, m, t = map(int, input().split())
c = [0] * m
r = 0
for i in range(n):
    s = input()
    for j in range(m):
        if s[j] == 'Y':
            c[j] += 1
            if c[j] == t:
                r += 1
print(r)