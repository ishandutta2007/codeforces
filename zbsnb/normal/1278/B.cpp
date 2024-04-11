#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vc vector
#define pb push_back
#define pii pair<int,int>
#define pll pait<ll,ll>
#define ft first
#define sd second
// #define int long long

ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}

signed main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        int k=max(a,b)-min(a,b);
        int i=0;
        int sum=0;
        while(1){
            if(sum>=k&&(sum-k)%2==0)break;
            sum+=++i;
        }
        cout<<i<<endl;
    }
}