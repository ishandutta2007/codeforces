n,a,b=map(int,input().split())
def ll(x):
    if x==1:
        return 0
    return 1+ll(x//2)
def main(n,a,b):
    if n==1:
        return 0
    q=n//2
    if a<=q and b>q or a>q and b<=q:
        return ll(n)
    return main(q,(a-1)%q+1,(b-1)%q+1)
r=main(n,a,b)
if 2**r==n:
    print('Final!')
else:
    print(r)