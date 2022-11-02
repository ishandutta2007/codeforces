n=input()
ans=set()

def dfs(p,l):
    if p>n or l>10:
        return
    if p>0:
        ans.add(p)
    dfs(p*10+a,l+1)
    dfs(p*10+b,l+1)

for a in range(0,10):
    for b in range(0,a):
        dfs(0,0)
print "%d" % len(ans)