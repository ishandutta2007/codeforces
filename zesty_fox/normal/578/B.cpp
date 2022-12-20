#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=200010;
int n,k,x;
ll a[N],pre[N],suf[N],ans;
ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) res*=x;
        x*=x;
        y>>=1;
    }
    return res;
}

int main(){
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        pre[i]=pre[i-1]|a[i];
    }
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]|a[i];
    for(int i=1;i<=n;i++){
        ans=max(ans,pre[i-1]|suf[i+1]|(qpow(x,k)*a[i]));
    }
    cout<<ans<<endl;
    return 0;
}