#include<cstdio>
#include<iostream>
using namespace std;
const int Mo=(int)1e9+7;
int inv2=(Mo+1)/2;
int main(){
    long long n,m;scanf("%I64d%I64d",&n,&m);
    long long ans=0;
    if(m>n){ans+=1ll*((m-n)%Mo)*(n%Mo)%Mo;m=n;}
    for(long long i=1;i<=n;){
        long long r=min(n/i,m);
        long long l=(n/(i+1))+1;
        if(l<=r) (ans+=1ll*(n%l+n%r)%Mo*((r-l+1)%Mo)%Mo*inv2%Mo)%=Mo;
        if(i==n)break;
        i=n/(n/(i+1));
    }
    printf("%I64d\n",ans);
    return 0;
}