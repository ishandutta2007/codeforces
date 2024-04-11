n=int(input())
a=[0]+[1]*n
p = list(map(int,input().split()))
nei=[[] for i in range(n+1)]
nei[0]=[1]
for i,e in enumerate(p):
    nei[e]+=[i+2]
d=[-1]*(n+1)

vert=[0]
index=0
while index<=n:
    v=vert[index]
    for nnn in nei[v]:
        d[nnn]=d[v]+1
        vert.append(nnn)
    index+=1
from collections import Counter
cc=Counter(d)
s=0
for i,e in cc.items():
    s+=e%2
print(s-1)