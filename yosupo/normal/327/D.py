import sys
from collections import deque

sys.setrecursionlimit(2000)

n, m = map(int, raw_input().split())
s = [raw_input() for i in range(n)]
d = [[-1 if s[i][j] == '.' else -2 for j in range(m)] for i in range(n)]

np = ((-1, 0), (1, 0), (0, -1), (0, 1))
buff = []
sbuff = []
def solve(i, j):
    global d, buff
    q = deque()
    q.append((i, j))
    d[i][j] = 0
    while len(q):
        i, j = q.popleft()
        for u in np:
            x = i+u[0]
            y = j+u[1]
            if not (0 <= x < n) or not (0 <= y < m) or d[x][y] != -1:
                continue
            buff.append((x, y))
            d[x][y] = 0
            q.append((x, y))

k = 0
for i in range(n):
    for j in range(m):
        if d[i][j] == -1:
            k += 1
            sbuff.append((i, j))
            solve(i, j)
buff.reverse()
print(len(buff)*3+k)
s0 = ['B {0} {1}'.format(i[0]+1, i[1]+1) for i in sbuff]
s1 = ['B {0} {1}'.format(i[0]+1, i[1]+1) for i in buff]
s2 = ['D {0} {1}\nR {0} {1}'.format(i[0]+1, i[1]+1) for i in buff]
print '\n'.join(s0)
print '\n'.join(s1)
print '\n'.join(s2)