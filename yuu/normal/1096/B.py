n=int(input())
s=input()
left=right=0;
cleft=cright='a';
for i in range(1, n):
    if(s[i]!=s[i-1]):
        left=i-1
        cl=s[i-1]
        break
for j in range(1, n):
    i=n-1-j
    if(s[i]!=s[i+1]):
        right=i+1
        cr=s[i+1]
        break
# print(left, right)
if(cl!=cr):
    print(left+2+n-right)
else:
    if(right<=left):
        print((n*(n+1)//2)%998244353);
    else:
        print((left+2)*(n-right+1)%998244353);