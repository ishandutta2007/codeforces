#include<bits/stdc++.h>
using namespace std;


int n, a[202000];

#define ll long long
const int mod=1e9+7;
ll K(ll x,ll y=mod-2){
    ll t=1;
    for (;y;y>>=1,x=x*x%mod)
        if (y&1){
            t=t*x%mod;
        }
    return t;
}

ll jc[404000], inv[404000];

ll C(int x,int y){
    return jc[x]*inv[y]%mod*inv[x-y]%mod;
}

int main(){
    n=4e5+3;
    jc[0]=inv[0]=1;
    for (int i=1;i<=n;++i){
        jc[i]=jc[i-1]*i%mod; inv[i]=K(jc[i]);
    }
    cin>>n;
    ll ans=0;
    for (int i=0;i<=n;++i){
        int x; cin>>x;
        if (i+x>=i+1) ans = (ans+C(i+x,i+1))%mod;
    }
    cout<<ans<<endl;
}