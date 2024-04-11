n, m= map(int, input().split())
s=set()
for i in range(m):
    x,y=map(int, input().split())
    s.add((x,y))

if m*2 == n*(n-1)  or n<2 or n==2 and m==1:
    print('NO')
    exit()

x, y = 0,0
for i in range(1,n+1):
    for j in range(i+1,n+1):
        if (i, j) not in s and (j, i) not in s:
            x=i
            y=j
            break
x-=1
y-=1
print('YES')
l = list(range(1,n+1))
if x == 1:
    y,x=x,y
if y == 0:
    x, y=y,x
l[x], l[0] = 1, l[x]
l[y], l[1] = 2, l[y]
print(*l)
l[y]=1
print(*l)