k,n=map(int,input().split())
s=map(int,input().split())
q=1
for i in s:
    if n%i==0:
        q=max(q,i)
print(n//q)