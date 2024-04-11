n,L=map(int,input().split())
c=list(map(int,input().split()))
c+=[float('inf')]*(35-len(c))
for i in range(len(c)-1):
    if c[i]*2<c[i+1]:
        c[i+1]=2*c[i]
def main():
    l=bin(L)[2:][::-1]
    ans=0
    for i in range(len(c)):
        if ans>c[i]:
            ans=c[i]
        if i<len(l) and l[i]=='1':
            ans+=c[i]
    return ans
print(main())