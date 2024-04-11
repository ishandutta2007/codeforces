n=int(input())
v = [[] for i in range(n)]
b = [False]*n
for i in range(1,n):
    x=int(input())-1
    v[x]+=[i]
for i in range(n):
    c=0
    for q in v[i]:
        if not v[q]:
            c+=1
    if c>2:
        b[i]=True
ans="Yes"
for i in range(n):
    if not b[i] and v[i]:
        ans="No"
print(ans)