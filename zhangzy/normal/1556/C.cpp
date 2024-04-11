#include<bits/stdc++.h>
using namespace std;

int n, a[1111];
long long ans=0;

void fuck(int *a,int n){
    long long mn=0, now=0;
    long long res=0;
    for (int i=2;i<=n;i+=2){
        long long l = a[1]+min(mn,-1ll)+1;
        long long r = a[i]-max(now-mn,1ll)+1;
        // printf("  %d %lld %lld\n",i,l,r);
        res+=max(0ll,min(l,r));
        mn=min(mn,now-a[i]);
        now=now-a[i]+a[i+1];
    }
    // for (int i=1;i<=n;++i) printf(" %d",a[i]);
    // printf(" : %d %lld\n",n,res);
    ans+=res;
}

int main(){
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;i+=2)
        fuck(a+i-1,n-i+1);
    cout<<ans<<endl;
}