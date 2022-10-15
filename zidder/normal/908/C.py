n,r = map(int,input().split())
x = list(map(int,input().split()))
res = []
for i in range(len(x)):
    y=r
    for j in range(i):
        dx=abs(x[i]-x[j])
        if dx>2*r:
            continue
        Y = res[j]+(4*r*r-dx**2)**0.5
        y = max([y,Y])
    res.append(float(y))
print(*res)