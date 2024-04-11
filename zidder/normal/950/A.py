l,r,a=map(int,input().split())
s=0
for i in range(a+1):
    s=max(s,2*min(l+i,r+a-i))
print(s)