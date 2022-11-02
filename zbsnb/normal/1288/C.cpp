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
const ll mod=1e9+7;
ll dp[1010][30];

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    ll ans=0;
    for(int i=1;i<=2*m;i++){
        for(int j=1;j<=n;j++){
            if(i==1)dp[j][i]=1;
            else{
                for(int k=1;k<=j;k++){
                    dp[j][i]+=dp[k][i-1];
                }
            }
            dp[j][i]%=mod;
            if(i==2*m)ans+=dp[j][i];
        }
    }
    // for(int i=1;i<=2*m;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[j][i]<<" ";
    //     }

    //     cout<<endl;
    // }
    cout<<ans%mod<<endl;
}