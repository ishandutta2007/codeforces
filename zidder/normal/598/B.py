def ckl(s,l,r,k):
    l-=1
    r-=1
    k%=r-l+1
    return s[:l]+s[r-k+1:r+1]+s[l:r-k+1]+s[r+1:]
s=input()
t=int(input())
for i in range(t):
    a,b,c=map(int,input().split())
    s=ckl(s,a,b,c)
print(s)