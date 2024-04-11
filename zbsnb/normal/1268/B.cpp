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

int a[200010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    ll cnt1=0,cnt2=0;
    for(int i=1;i<=t;i++){
        int n;cin>>n;
        if(i%2){
            cnt1+=n/2;
            cnt2+=n-n/2;
        }
        else{
            cnt2+=n/2;
            cnt1+=n-n/2;
        }
    }
    cout<<min(cnt1,cnt2)<<endl;
}