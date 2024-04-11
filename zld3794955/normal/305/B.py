p,q = map(int,raw_input().split(' '))
n=int(raw_input())
a=map(int,raw_input().split(' '))
for i in range(0,n):
    p=p-a[i]*q
    t=p; p=q; q=t;
if q==0:
    print "YES"
else:
    print "NO"