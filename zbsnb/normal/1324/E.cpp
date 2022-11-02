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
int dp[2010][2010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,h,l,r;cin>>n>>h>>l>>r;
    int ans=0;
    for(int i=1;i<h;i++)dp[0][i]=-1e9;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        for(int j=0;j<h;j++){
            dp[i][j]=(j>=l&&j<=r)+max(dp[i-1][((j-x)%h+h)%h],dp[i-1][((j-(x-1))%h+h)%h]);
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
}