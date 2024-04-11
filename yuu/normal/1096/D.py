n=int(input())
s=input()
aa=input().split()
a=[]
for x in aa:
    a.append(int(x))
f=[0, 1e18, 1e18, 1e18]
for i in range(0, n):
    if(s[i]=='h'):
        f[1]=min(f[1], f[0])
        f[0]+=a[i]
    elif (s[i]=='a'):
        f[2]=min(f[2], f[1])
        f[1]+=a[i]
    elif (s[i]=='r'):
        f[3]=min(f[3], f[2])
        f[2]+=a[i]
    elif (s[i]=='d'):
        f[3]+=a[i]
print(min(f))