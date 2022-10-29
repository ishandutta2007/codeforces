n, k =input().split();
n=int(n)
k=int(k)

a=list(map(int,input().split()))
b=list(map(int,input().split()))

L = 0;
R = 10**10;

def check(idd) :
    summ=0;
    for i in range(0,n) :
        if (a[i]*idd>b[i]) :
            summ-=b[i]-a[i]*idd;
    if summ<=k :
        return True;
    else :
        return False;

while R-L !=1 :
    mid = (L+R)/2;
    mid=int(mid);
    #print(mid)
    if check(mid)==True :
        L=mid;
    else :
        R=mid;
print(L)