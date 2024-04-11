a = list(map(int,input().split()));
ans = a[0]*a[1];
ans=int(ans);
if ans%2==0 :
    print(int(ans/2));
else :
    print(int((ans-1)/2));