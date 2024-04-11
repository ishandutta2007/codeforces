n=int(input())
a=list(map(int,input().split()))
ans='YES'
for i in range(n-1):
    m=max(a)
    for j in range(n-i-1):
        if abs(a[j+1]-a[j])>1:
            ans='NO'
    a.remove(m)
print(ans)