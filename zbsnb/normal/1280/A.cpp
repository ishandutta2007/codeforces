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
const int mod=1e9+7;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int x;cin>>x;
        string s;cin>>s;
        ll ans=s.size();
        for(int i=0;i<x;i++){
            int tmp=s.size();
            int len=ans-i-1;
            int cnt=s[i]-'1';
            if(tmp<=x){
                for(int j=1;j<=cnt;j++){
                    s+=s.substr(i+1,len);
                }
            }
            ans+=cnt*len;
            ans%=mod;
            // cout<<i<<" "<<ans<<" "<<s<<endl;
        }
        cout<<(ans%mod+mod)%mod<<endl;
    }
}