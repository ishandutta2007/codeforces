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

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    string s1[n];
    string s2[m];
    for(int i=0;i<n;i++){
        cin>>s1[i];
    }
    for(int i=0;i<m;i++){
        cin>>s2[i];
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int tmp;cin>>tmp;
        tmp--;
        int a=tmp%n;
        int b=tmp%m;
        // cout<<a<<" "<<b<<endl;
        cout<<s1[a]<<s2[b]<<endl;
    }
}