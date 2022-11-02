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

int a[200010];

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=2*n;i++)cin>>a[i];
        map<int,int> mp1,mp2;
        int now=0;
        mp1[0]=0;
        for(int i=1;i<=n;i++){
            now-=a[i]==1?1:-1;
            mp1[now]=i;
        }

        now=0;
        mp2[0]=2*n+1;
        for(int i=2*n;i>=n+1;i--){
            now-=a[i]==1?1:-1;
            mp2[-now]=i;
        }
        int ans=2e9;
        for(int i=-n;i<=n;i++){
            if(mp1.find(i)==mp1.end())continue;
            if(mp2.find(i)==mp2.end())continue;
            // cout<<i<<" "<<mp1[i]<<" "<<mp2[i]<<endl;
            ans=min(ans,mp2[i]-mp1[i]-1);
        }
        cout<<ans<<endl;
    }
}