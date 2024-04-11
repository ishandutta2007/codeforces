from collections import defaultdict

n=int(input())
d=defaultdict(dict)
for i in range(n):
    x=input()
    x=x.split()
    if i==0:
        P = x
    q=int(input())
    Con=[]
    for j in range(q):
        Con.append(input().split())
    if i!=n-1:
        input()
    d[x[0]][x[1]]=Con
ver=[P]
ans={}
while ver:
    next_ans = {}
    for v in ver:
        C=d[v[0]][v[1]]
        for n_v in C:
            if n_v[0] not in ans and n_v[0]!=P[0]:
                if n_v[0] in next_ans:
                    if int(n_v[1])>int(next_ans[n_v[0]]):
                        next_ans[n_v[0]]=n_v[1]
                else:
                    next_ans[n_v[0]]=n_v[1]
    ans.update(next_ans)
    ver=list(next_ans.items())
l=list(ans.items())
print(len(l))
l.sort()
for k,v in l:
    print(k,v)