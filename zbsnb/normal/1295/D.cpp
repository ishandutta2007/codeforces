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

ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}

ll phi(ll x){

    ll ret=1;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            ret*=i-1;
            x/=i;
            while(x%i==0){
                ret*=i;
                x/=i;
            }
        }
    }
    if(x!=1)ret*=x-1;
    return ret;
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        // cout<<a<<" "<<b<<" "<<gcd(a,b)<<endl;
        cout<<phi(b/gcd(a,b))<<endl;
    }
}