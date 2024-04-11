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
int a[1000010];
int b[1000010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    ll ans=0;
    int now=t;
    for(int i=1;i<=t;i++){
        int n;cin>>n;
        int maxn=0,minn=1e9;
        int flg=0;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            if(tmp>minn){
                flg=1;
            }
            maxn=max(maxn,tmp);
            minn=min(minn,tmp);
        }
        if(flg){
            ans+=2*now-1;
            now--;
            a[i]=-1;
        }
        else{
            a[i]=minn;
            b[maxn]++;
        }
    }
    for(int i=1000000;i>=0;i--){
        b[i]+=b[i+1];
    }
    for(int i=1;i<=t;i++){
        if(a[i]==-1)continue;
        ans+=b[a[i]+1];
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}