n,m=map(int,input().split())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
i,j=0,0
s=0
s1=0
s2=0
while i<n and j<m:
    if x[i]+s1==y[j]+s2:
        s+=1
        i+=1
        j+=1
        s1=0
        s2=0
    elif x[i]+s1>y[j]+s2:
        s2+=y[j]
        j+=1
    else:
        s1+=x[i]
        i+=1
print(s)