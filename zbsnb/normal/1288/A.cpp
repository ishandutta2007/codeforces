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
    int t;cin>>t;
    while(t--){
        int n,d;cin>>n>>d;
        if(d<=n){
            cout<<"YES"<<endl;
            continue;
        }
        int flg=1;
        for(int i=1;i<=100000;i++){
            int tmp;
            if(d%(i+1)==0)tmp=d/(i+1);
            else tmp=d/(i+1)+1;
            if(i+tmp<=n){
                flg=0;
                cout<<"YES"<<endl;
                break;
            }
        }
        if(flg)cout<<"NO"<<endl;
    }
}