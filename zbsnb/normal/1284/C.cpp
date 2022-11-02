#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vc vector
#define pb push_back
#define pii pair<int,int>
#define pll pait<ll,ll>
#define ft first
#define sd second
#define up(it,vec) for(auto it=vec.begin();it!=vec.end();it++)
#define dn(it,vec) for(auto it=vec.rbegin();it!=vec.rend();it++)
// #define int long long
ll mod;int n;
ll mypow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}


ll fac[250010],inv[250100];
void init(){
    fac[0]=1;
    for(int i=1;i<=250000;i++)fac[i]=fac[i-1]*i%mod;
    inv[250000]=mypow(fac[250000],mod-2);
    for(int i=250000;i>=1;i--)inv[i-1]=inv[i]*i%mod;
    
    // for(int i=1;i<=10;i++){
    //     cout<<i<<" "<<fac[i]<<" "<<inv[i]<<endl;
    // }

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>mod;
    init();
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(n-i)*fac[n-1-i]%mod*(n-i)%mod*fac[i+1]%mod;

    }
    cout<<ans%mod<<endl;
}