n=int(input())
a=int(input())
b=int(input())
c=int(input())

mx = max(max(a,b),c)
mn = min(min(a,b),c)

if n==1 :
    print(0)
else :
    print(min(a,b) + (n-2)*mn)