n = int(input())
d = []
for i in range(n):
    d.append(input())

for i in range(n):
    if d[i].count('E') == n:
        break
else:
    for i in range(n):
        print(i+1, d[i].index('.')+1)
    exit()

for i in range(n):
    res = 0
    for j in range(n):
        if d[j][i] == 'E':
            res += 1
    if res == n:
        break
else:
    for i in range(n):
        for j in range(n):
            if d[j][i] == '.':
                print(j+1, i+1)
                break
    exit()
print(-1)