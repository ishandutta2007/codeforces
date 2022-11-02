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

int a[100010];
int maxn[100010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m,k;cin>>n>>m>>k;if(k>=m)k=m-1;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=m;i++){
            maxn[i]=max(a[i],a[n-m+i]);
        }
        // for(int i=1;i<=m;i++)cout<<maxn[i]<<" ";cout<<endl;
        multiset<int> s;
        for(int i=1;i<=m-k;i++)s.insert(maxn[i]);
        int ans=*(s.begin());
        for(int i=m-k+1;i<=m;i++){
            s.insert(maxn[i]);
            s.erase(s.find(maxn[i-(m-k)]));
            ans=max(ans,*(s.begin()));
        }
        cout<<ans<<endl;
    }
}