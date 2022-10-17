def lg(n):
    t=0
    while n:
        n//=2
        t+=1
    return t
def ans(n):
    q=n*(n+1)//2
    return int(q-2**lg(n)*2+2)
t=int(input())
for i in range(t):
    n=int(input())
    print(ans(n))