n = int(input())
x = set()
y = set()
p = [list(map(int, input().split())) for i in range(n)]
for d in p:
    x.add(d[0])
    y.add(d[1])
    x.add(d[2])
    y.add(d[3])
xl = sorted(list(x))
yl = sorted(list(y))
if (xl[-1] - xl[0] != yl[-1] - yl[0]):
    print('NO')
    exit()
z = [[0 for i in range(len(xl)-1)] for j in range(len(yl)-1)]
for d in p:
    for i in range(xl.index(d[0]), xl.index(d[2])):
        for j in range(yl.index(d[1]), yl.index(d[3])):
            z[j][i] = 1
for d in z:
    if d.count(0):
        print('NO')
        exit()
print('YES')