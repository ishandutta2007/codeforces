n=int(input())
a=list(map(int,input().split()))
mm=max(a)
mmm=min(a)
if mmm!=mm-2:
    print(n)
    print(*a)
else:
    q,w,e=0,0,0
    for i in a:
        if i==mm:
            e+=1
        elif i==mmm:
            q+=1
        else:
            w+=1
    y=w%2+q+e
    p=max(q,e)-min(q,e)
    u=p+w
    if y<u:
        print(y)
        print(*([mm]*(e+w//2)+[mmm]*(q+w//2)+[mm-1]*(w%2)))
    else:
        print(u)
        if q>e:
            print(*([mmm]*p+(n-p)*[mmm+1]))
        else:
            print(*([mm]*p+(n-p)*[mm-1]))