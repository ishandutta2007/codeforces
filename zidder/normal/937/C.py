k,d,t = map(int,input().split())
t*=2
if k>d:
    if k%d==0:
        d=k
    else:
        d=(k//d+1)*d
q=d+k
ans=t//q*d
t%=q
if t<=2*k:
    print(t/2+ans)
else:
    print(ans+t-k)