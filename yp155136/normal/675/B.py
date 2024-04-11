n,a,b,c,d = map(int,(input().split()))

ans=0

for i in range(1,n+1) :
    j = i+b-c
    k = a+j-d
    l = c+k-b
    if 1<=j and j<=n and 1<=k and k<=n and 1<=l and l<=n :
        ans = ans+1
        
print(ans*n)