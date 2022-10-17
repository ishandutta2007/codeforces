def main():
    n,pos,l,r=map(int,input().split())
    if l==1 and r==n:
        return 0
    if l!=1 and r!=n:
        q=r-l+2
    else:
        if l==1:
            return abs(pos-r)+1
        return abs(pos-l)+1
    w=min(abs(pos-l),abs(pos-r))
    return q+w
print(main())