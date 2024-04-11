n,k = map(int, input().split())
a=list(map(int, input().split()))

last=''
m = 0
s=0
for i in a:
    if i==last:
        s=1
    else:
        s+=1
    last=i
    if s>m:
        m=s
print(m)