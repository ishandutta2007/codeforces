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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n;cin>>n;
    ll a=1,b=n,ans=n;
    for(ll i=1;i<=min(n-1,(ll)1000000);i++){
        if(n%i==0){
            if(max(i,n/i)<ans&&gcd(i,n/i)==1){
                a=i,b=n/i,ans=max(i,n/i);
            }
        }
    }
    cout<<a<<" "<<b<<endl;
}