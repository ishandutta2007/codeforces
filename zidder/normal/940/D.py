n=int(input())
a=list(map(int,input().split()))
s=input()
l=-1000000000
r=1000000000
for i in range(4,n):
    if s[i-4:i]=='0000':
        if s[i]=='1':
            l=max(max(a[i-4:i+1])+1,l)
    if s[i-4:i]=='1111':
        if s[i]=='0':
            r=min(min(a[i-4:i+1])-1,r)
print(l, r)